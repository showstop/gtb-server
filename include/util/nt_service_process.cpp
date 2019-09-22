#include "nt_service_process.h"


namespace nt_service 
{
	bool install(const char* service_name, const char* display_name, const char* description, const char* image_name)
	{
		SC_HANDLE scm = OpenSCManagerA(NULL, NULL, SC_MANAGER_CREATE_SERVICE);
		if (scm == NULL)
		{
			return false;
		}

		SC_HANDLE service_handle = CreateServiceA(scm, service_name, display_name,
			SERVICE_ALL_ACCESS, SERVICE_WIN32_OWN_PROCESS,
			SERVICE_AUTO_START, SERVICE_ERROR_IGNORE,
			image_name, NULL, NULL, NULL, NULL, NULL);
		if (service_handle == NULL)
		{
			CloseServiceHandle(service_handle);
			service_handle = NULL;
			CloseServiceHandle(scm);
			scm = NULL;
			return false;
		}

		SERVICE_DESCRIPTIONA service_description;
		service_description.lpDescription = const_cast<char *>(description);
		if (ChangeServiceConfig2A(service_handle, SERVICE_CONFIG_DESCRIPTION, &service_description) == FALSE)
		{
			CloseServiceHandle(service_handle);
			service_handle = NULL;
			CloseServiceHandle(scm);
			scm = NULL;
			return false;
		}

		CloseServiceHandle(service_handle);
		service_handle = NULL;

		CloseServiceHandle(scm);
		scm = NULL;

		return true;
	}

	bool uninstall(const char* service_name)
	{
		SC_HANDLE scm = OpenSCManagerA(NULL, NULL, SC_MANAGER_ALL_ACCESS);
		if (scm == NULL)
		{
			return false;
		}

		SC_HANDLE service_handle = OpenServiceA(scm, service_name, SERVICE_ALL_ACCESS);
		if (service_handle == NULL)
		{
			CloseServiceHandle(scm);
			scm = NULL;
			return false;
		}

		SERVICE_STATUS service_state;
		if (QueryServiceStatus(service_handle, &service_state) == FALSE)
		{
			CloseServiceHandle(service_handle);
			service_handle = NULL;
			CloseServiceHandle(scm);
			scm = NULL;
			return false;
		}

		if (service_state.dwCurrentState != SERVICE_STOPPED)
		{
			CloseServiceHandle(service_handle);
			service_handle = NULL;
			CloseServiceHandle(scm);
			scm = NULL;
			return false;
		}

		bool result = false;
		if (DeleteService(service_handle) == TRUE)
		{
			result = true;
		}

		CloseServiceHandle(service_handle);
		service_handle = NULL;

		CloseServiceHandle(scm);
		scm = NULL;

		return result;
	}

	bool run(const char* service_name, entry_point service_entry)
	{
		SERVICE_TABLE_ENTRYA et[] = {
			{const_cast<char *>(service_name), reinterpret_cast<LPSERVICE_MAIN_FUNCTIONA>(service_entry)},
			{NULL, NULL}
		};

		return (StartServiceCtrlDispatcherA(et) == TRUE);
	}

	SERVICE_STATUS_HANDLE register_service(const char* service_name, LPHANDLER_FUNCTION_EX handler, void* context)
	{
		return RegisterServiceCtrlHandlerExA(service_name, handler, context);
	}

	bool set_service_state(SERVICE_STATUS_HANDLE handle, unsigned int state)
	{
		SERVICE_STATUS service_state;

		service_state.dwServiceType = SERVICE_WIN32_OWN_PROCESS;
		service_state.dwCurrentState = state;
		service_state.dwControlsAccepted = SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_PAUSE_CONTINUE | SERVICE_ACCEPT_SHUTDOWN;
		service_state.dwWin32ExitCode = 0;
		service_state.dwServiceSpecificExitCode = 0;
		service_state.dwCheckPoint = 0;
		service_state.dwWaitHint = 3000;

		return (SetServiceStatus(handle, &service_state) == TRUE);
	}



}