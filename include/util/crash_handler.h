#include <time.h>
#include <tchar.h>
#include <windows.h>
#include <dbghelp.h>
#include "file_path_finder.h"
#pragma comment(lib, "dbghelp.lib")

class crash_handler
{
public:
	static void init(const std::string& prefix)
	{
		prefix_ = prefix;
		::SetUnhandledExceptionFilter(onSEH);
	}

	static LONG WINAPI onSEH(struct _EXCEPTION_POINTERS * pEP)
	{
		char create_filename[256] = {0, };
		char buff_time[128] = {0, };

		time_t file_time = time(0);
		struct tm t;
		localtime_s(&t, &file_time);
		strftime(buff_time, sizeof(buff_time), "%y-%m-%d.%H.%M.%S", &t);
		_snprintf_s(create_filename, sizeof(create_filename), "%s(%s).dmp", prefix_.c_str(), buff_time);

		HANDLE hFile = ::CreateFileA(create_filename, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, 0, NULL);
		if (hFile == INVALID_HANDLE_VALUE) 
		{
			OutputDebugString(L"create dump file failed\n");
			return EXCEPTION_EXECUTE_HANDLER;
		}

		MINIDUMP_EXCEPTION_INFORMATION mdeinfo;
		BOOL ret;

		mdeinfo.ClientPointers = TRUE;
		mdeinfo.ExceptionPointers = pEP;
		mdeinfo.ThreadId = GetCurrentThreadId();

		ret = MiniDumpWriteDump(GetCurrentProcess(),
			GetCurrentProcessId(),
			hFile,
			MiniDumpNormal,
			&mdeinfo,
			NULL,
			NULL  );

		if ( !ret ) 
			OutputDebugString(L"MiniDumpWriteDump failed\n");

		::CloseHandle(hFile);
		return EXCEPTION_EXECUTE_HANDLER;
	}

private:
	static std::string prefix_;
};

std::string crash_handler::prefix_;


