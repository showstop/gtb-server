#include "process_util.h"

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#include <stdio.h>
#include <userenv.h>
#include <aclapi.h>
#include <assert.h>
#pragma comment (lib, "userenv.lib")
#endif

#if defined(_WIN32) || defined(_WIN64)

namespace helper {
	BOOL __stdcall AdjustDacl(HANDLE handle, DWORD DesiredAccess)
	{
		// the WORLD Sid is trivial to form programmatically (S-1-1-0)
		SID world = { SID_REVISION, 1, SECURITY_WORLD_SID_AUTHORITY, 0 };

		EXPLICIT_ACCESS ea =
		{
			DesiredAccess, SET_ACCESS, NO_INHERITANCE,
			{ 0, NO_MULTIPLE_TRUSTEE, TRUSTEE_IS_SID, TRUSTEE_IS_USER, reinterpret_cast<LPTSTR>(&world) }
		};
		ACL* pdacl = 0;
		DWORD err = ::SetEntriesInAcl(1, &ea, 0, &pdacl);
		if (ERROR_SUCCESS == err)
		{
			err = ::SetSecurityInfo(handle, SE_KERNEL_OBJECT, DACL_SECURITY_INFORMATION, 0, 0, pdacl, 0);
			::LocalFree(pdacl);
			return (ERROR_SUCCESS == err);
		}

		return FALSE;
	}

	// Useful helper function for enabling a single privilege
	BOOL __stdcall EnableTokenPrivilege(HANDLE hToken, LPCTSTR szPrivilege, TOKEN_PRIVILEGES& tpOld)
	{
		TOKEN_PRIVILEGES tp;
		tp.PrivilegeCount = 1;
		tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
		if (::LookupPrivilegeValue(0, szPrivilege, &tp.Privileges[0].Luid))
		{
			// hToken must have been opened with the following permissions:
			// TOKEN_QUERY (to get the old priv setting)
			// TOKEN_ADJUST_PRIVILEGES (to adjust the priv)
			DWORD cbOld = sizeof tpOld;
			if (::AdjustTokenPrivileges(hToken, FALSE, &tp, cbOld, &tpOld, &cbOld))
			{
				// Note that AdjustTokenPrivileges may succeed, and yet
				// some privileges weren't actually adjusted.
				// You've got to check GetLastError() to be sure!
				return (ERROR_NOT_ALL_ASSIGNED != ::GetLastError());
			}
		}

		return FALSE;
	}

	// Corresponding restoration helper function
	BOOL __stdcall RestoreTokenPrivilege(HANDLE hToken, const TOKEN_PRIVILEGES& tpOld)
	{
		return ::AdjustTokenPrivileges(hToken, FALSE, const_cast<TOKEN_PRIVILEGES*>(&tpOld), 0, 0, 0);
	}

	HANDLE __stdcall open_process_with_enough_rights(DWORD dwPID, DWORD dwAccessRights)
	{
		HANDLE hProcess = ::OpenProcess(dwAccessRights, FALSE, dwPID);
		if (hProcess == NULL)
		{
			HANDLE hpWriteDAC = ::OpenProcess(WRITE_DAC, FALSE, dwPID);
			if (hpWriteDAC == NULL)
			{
				// hmm, we don't have permissions to modify the DACL...
				// time to take ownership...
				HANDLE hToken = NULL;
				if (!::OpenProcessToken(::GetCurrentProcess(), TOKEN_QUERY | TOKEN_ADJUST_PRIVILEGES, &hToken))
					goto LReturn;

				TOKEN_PRIVILEGES tpOld;
				if (EnableTokenPrivilege(hToken, SE_TAKE_OWNERSHIP_NAME, tpOld))
				{
					// SeTakeOwnershipPrivilege allows us to open objects with
					// WRITE_OWNER, but that's about it, so we'll update the owner,
					// and dup the handle so we can get WRITE_DAC permissions.
					HANDLE hpWriteOwner = ::OpenProcess(WRITE_OWNER, FALSE, dwPID);
					if (hpWriteOwner != NULL)
					{
						BYTE buf[512]; // this should always be big enough
						DWORD cb = sizeof buf;
						if (::GetTokenInformation(hToken, TokenUser, buf, cb, &cb))
						{
							DWORD err = SetSecurityInfo(hpWriteOwner, SE_KERNEL_OBJECT, OWNER_SECURITY_INFORMATION,
								reinterpret_cast<TOKEN_USER*>(buf)->User.Sid, 0, 0, 0);
							if (ERROR_SUCCESS == err)
							{
								// now that we're the owner, we've implicitly got WRITE_DAC
								// permissions, so ask the system to reevaluate our request,
								// giving us a handle with WRITE_DAC permissions
								if (
									!::DuplicateHandle(::GetCurrentProcess(), hpWriteOwner,
										::GetCurrentProcess(), &hpWriteDAC,
										WRITE_DAC, FALSE, 0)
									)
								{
									hpWriteDAC = NULL;
								}
							}
						}

						// don't forget to close handle
						::CloseHandle(hpWriteOwner);
					}

					// not truly necessary in this app,
					// but included for completeness
					RestoreTokenPrivilege(hToken, tpOld);
				}

				// don't forget to close the token handle
				::CloseHandle(hToken);
			}

			if (hpWriteDAC)
			{
				// we've now got a handle that allows us WRITE_DAC permission
				AdjustDacl(hpWriteDAC, dwAccessRights);

				// now that we've granted ourselves permission to access 
				// the process, ask the system to reevaluate our request,
				// giving us a handle with right permissions
				if (
					!DuplicateHandle(::GetCurrentProcess(), hpWriteDAC, ::GetCurrentProcess(),
						&hProcess, dwAccessRights, FALSE, 0)
					)
				{
					hProcess = NULL;
				}

				::CloseHandle(hpWriteDAC);
			}
		}

	LReturn:
		return hProcess;
	}
}

bool _kill_process(void* handle)
{
	DWORD exit_code = 0;
	if (GetExitCodeProcess(handle, &exit_code) == FALSE)
	{
		CloseHandle(handle);
		handle = NULL;
		return false;
	}
	if (exit_code != STILL_ACTIVE)
	{
		CloseHandle(handle);
		handle = NULL;
		return false;
	}

	if (TerminateProcess(handle, 0) == FALSE)
	{
		CloseHandle(handle);
		handle = NULL;
		return false;
	}

	CloseHandle(handle);
	handle = NULL;

	return true;
}

bool kill_process(unsigned int pid)
{
	HANDLE handle = helper::open_process_with_enough_rights(pid, PROCESS_QUERY_INFORMATION | PROCESS_TERMINATE);
	if (handle == NULL)
	{
		return false;
	}

	return _kill_process(handle);
}

bool execute(const std::string &command, unsigned int *pid)
{
	STARTUPINFOA si;
	memset(&si, 0, sizeof(STARTUPINFOA));
	si.cb = sizeof(STARTUPINFOA);

	PROCESS_INFORMATION pi;
	memset(&pi, 0, sizeof(PROCESS_INFORMATION));

	if (CreateProcessA(NULL, const_cast<char *>(command.c_str()),
		NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi) == FALSE)
	{
		return false;
	}

	if (pid != NULL)
	{
		*pid = pi.dwProcessId;
	}

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	return true;
}
#else

#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <dirent.h>
#include <ServerBase/sb_define.h>
#define MAX_PATH 256

bool kill_process(unsigned int pid)
{
	if (((pid_t)pid) <= 0)
	{
		printf("[KillProcess()] pid must be positive integer \n");
		return false;
	}

	if (kill(pid, SIGKILL) == -1)
	{
		printf("[KillProcess()] kill failed. %d:%s\n", errno, strerror(errno));
		return false;
	}

	if (waitpid(pid, NULL, 0) == (pid_t)pid)
		return true;
	else
	{
		printf("[KillProcess()] waitpid failed. %d:%s\n", errno, strerror(errno));
		return false;
	}
}

bool _kill_process(void* handle)
{
	pid_t pid = (pid_t)((unsigned long int) handle);
	return kill_process(pid);
}

void close_all_open_file_descriptor(int pid)
{
	// close all open file descriptors except stdin, stdout, stderr
	char buf[MAX_PATH + 1] = { 0, };

	FUNC_SPRINTF_SAFE(buf, MAX_PATH, "/proc/%d/fd", pid);

	DIR *pDir = opendir(buf);
	if (pDir == NULL)
		exit(127);

	while (true)
	{
		struct dirent *pDirEntry = readdir(pDir);

		if (pDirEntry == NULL)
			break;

		int fd = atoi(pDirEntry->d_name);
		if (fd == 0 || fd == 1 || fd == 2)
			continue;

		close(fd);
	}

	closedir(pDir);
}

bool execute(const std::string &command, const std::string &currentPath, unsigned int *ppid)
{
	unsigned int pid = fork();
	switch (pid)
	{
	case -1:
		return false;

		// child process
	case 0:
		setsid();
		close_all_open_file_descriptor(getpid());

		// change working directory
		if (false == currentPath.empty()) {
			if (0 != chdir(currentPath.c_str())) {
				exit(127);
			}
		}

		const char *argv[4];
		argv[0] = "sh";
		argv[1] = "-c";
		argv[2] = command.c_str();
		argv[3] = NULL;
		execv("/bin/bash", (char* const*)argv);
		exit(127);
		break;

		// parent process
	default:
		if (ppid != NULL)
			*ppid = pid;

		return true;
	}
}

bool execute(const std::string &command, unsigned int *ppid)
{
	std::string full_cmd = "xvfb-run --auto-servernum --server-args='-screen 0 640x480x24:32' " + command;
	return execute(full_cmd, std::string(), ppid);
}

#endif
