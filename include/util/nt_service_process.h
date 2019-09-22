#ifndef __K_SB_SERVICE_PROCESS__
#define __K_SB_SERVICE_PROCESS__

#include <windows.h>
#include <winsvc.h>

namespace nt_service
{
	typedef void (__stdcall *entry_point)(int, char**);

	bool install(const char* service_name, const char* display_name, const char* description, const char* image_name);
	bool uninstall(const char* service_name);

	bool run(const char* service_name, entry_point service_entry);
	SERVICE_STATUS_HANDLE register_service(const char* service_name, LPHANDLER_FUNCTION_EX handler, void* context);
	bool set_service_state(SERVICE_STATUS_HANDLE handle, unsigned int state);
}


#endif