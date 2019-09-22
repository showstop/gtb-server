#include <util/crash_handler.h>
#include <util/nt_service_process.h>

#define CRASH_DUMP_PREFIX "GTB.LobbyServer" 
#define NT_SERVICE_NAME "GTB.LobbyServer"
#define NT_DESCRIPTION "GTB.LobbyServer"


DWORD current_nt_service_state = SERVICE_START_PENDING;
SERVICE_STATUS_HANDLE service_handle = NULL;

DWORD __stdcall service_handler(DWORD control, DWORD eventType, void *eventData, void *data);
BOOL __stdcall ctrl_handler(DWORD type);
int argument_interpret(int argc, char** argv, bool& is_nt_service);
void __stdcall service_main(int argc, char **argv);

bool run_main(bool is_nt_service)
{
	Log(Log::Process) << NT_SERVICE_NAME << " started...";
	if (is_nt_service == true)
	{
		Log(Log::Process) << NT_SERVICE_NAME << " Initializing... in NT Service Mode...";
	}
	else
	{
		Log(Log::Process) << NT_SERVICE_NAME << " Initializing... in Console Mode...";
	}

	if (false == lobby_server.start())
	{
		Log(Log::Error) << NT_SERVICE_NAME << " Initialize failed.";
		return false;
	}
	lobby_server.wait();
	return true;
}

int main(int argc, char** argv)
{
	// install crash handler
	crash_handler::init(CRASH_DUMP_PREFIX);

	// check process arguments
	bool is_nt_service = false;
	int ret = argument_interpret(argc, argv, is_nt_service);
	if (ret != 0)	return ret;

	try
	{
		scoped_logger::instance();
	}
	catch (const char* e)
	{
		std::cerr << e << std::endl;
		return -10;
	}
	Log(Log::All) << "logger initialized successfully...";

	if (is_nt_service)
	{
		if (false == nt_service::run(NT_SERVICE_NAME, &service_main))
		{
			Log(Log::Error) << "nt_service::run() failed";
			Log::uninitialize();
			return -1;
		}
	}
	else	//console
	{
		if (SetConsoleCtrlHandler(&ctrl_handler, TRUE) == FALSE)
		{
			Log(Log::Error) << "SetConsoleCtrlHandler() failed";
			Log::uninitialize();
			return -1;
		}
		run_main(false);
	}
	return 0;
}

BOOL __stdcall ctrl_handler(DWORD type)
{
	switch (type)
	{
	case CTRL_C_EVENT:
	case CTRL_BREAK_EVENT:
	case CTRL_CLOSE_EVENT:
	case CTRL_LOGOFF_EVENT:
	case CTRL_SHUTDOWN_EVENT:
		lobby_server.stop();
		return TRUE;
	}

	return FALSE;
}

void __stdcall service_main(int, char **)
{
	service_handle = nt_service::register_service(NT_SERVICE_NAME, &service_handler, NULL);
	if (service_handle == NULL)
	{
		Log(Log::Error) << "ServiceProcess::RegisterService() failed";
		return;
	}

	if (nt_service::set_service_state(service_handle, SERVICE_START_PENDING) == true)
	{
		current_nt_service_state = SERVICE_START_PENDING;
	}
	if (nt_service::set_service_state(service_handle, SERVICE_RUNNING) == true)
	{
		current_nt_service_state = SERVICE_RUNNING;
	}
	if (false == run_main(true))
	{
		nt_service::set_service_state(service_handle, SERVICE_STOPPED);
		current_nt_service_state = SERVICE_STOPPED;
	}
}

DWORD __stdcall service_handler(DWORD control, DWORD eventType, void *eventData, void *data)
{
	(void)eventType;
	(void)eventData;
	(void)data;

	DWORD result = ERROR_CALL_NOT_IMPLEMENTED;

	switch (control)
	{
	case SERVICE_CONTROL_STOP:
	{
		nt_service::set_service_state(service_handle, SERVICE_STOP_PENDING);
		current_nt_service_state = SERVICE_STOP_PENDING;
		lobby_server.stop();
		nt_service::set_service_state(service_handle, SERVICE_STOPPED);
		current_nt_service_state = SERVICE_STOPPED;
		result = NO_ERROR;
	}
	break;
	case SERVICE_CONTROL_INTERROGATE:
	{
		nt_service::set_service_state(service_handle, current_nt_service_state);
		result = NO_ERROR;
	}
	break;
	case SERVICE_CONTROL_PAUSE:
	case SERVICE_CONTROL_CONTINUE:
		break;
	}

	return result;
}

bool get_service_name(std::string &service_name)
{
	char server_name[64] = { 0, };
	GetPrivateProfileStringA("System", "Name", "", server_name, sizeof(server_name), helper::GetAbsPathName(CONFIG_FILE).c_str());
	if (strlen(server_name) == 0)
	{
		return false;
	}
	service_name.append(NT_SERVICE_NAME);
	service_name.append(".");
	service_name.append(server_name);
	return true;
}

int argument_interpret(int argc, char** argv, bool& is_nt_service)
{
	is_nt_service = true;
	bool invalid_args = false;
	if (argc == 2)
	{
		if (strcmp(argv[1], "-i") == 0)
		{
			char image_name[512 + 1] = { 0, };
			GetModuleFileNameA(NULL, image_name, sizeof(image_name));
			std::cout << "Install ..." << std::endl;

			std::string service_name;
			if (false == get_service_name(service_name))
				return -1;

			if (nt_service::install(service_name.c_str(), service_name.c_str(), NT_DESCRIPTION, image_name) == false)
			{
				std::cerr << "Failed to install service." << std::endl;
				return -1;
			}
			std::cout << "Install " << service_name << " has successfully completed." << std::endl;
			return 1;
		}
		else if (strcmp(argv[1], "-u") == 0)
		{
			std::cout << "Uninstall..." << std::endl;

			std::string service_name;
			if (false == get_service_name(service_name))
				return -1;

			if (nt_service::uninstall(service_name.c_str()) == false)
			{
				std::cerr << "Failed to uninstall service." << std::endl;
				return -1;
			}
			std::cout << "Uninstall " << service_name << " has successfully completed." << std::endl;
			return 1;
		}
		else if (strcmp(argv[1], "-c") == 0)
		{
			is_nt_service = false;
		}
		else
			invalid_args = true;
	}
	if (argc > 2 || invalid_args)
	{
		std::cout << "invalid program argument" << std::endl;
		std::cout << "usage example" << std::endl;
		std::cout << "c:>" << NT_SERVICE_NAME << ".exe -i  : install " << NT_SERVICE_NAME " with NTService" << std::endl;
		std::cout << "c:>" << NT_SERVICE_NAME << ".exe -u  : uninstall " << NT_SERVICE_NAME " with NTService" << std::endl;
		std::cout << "c:>" << NT_SERVICE_NAME << ".exe -c  : running in console mode" << std::endl;
		return -1;
	}
	return 0;
}
