
#if defined(_WIN32) || defined(_WIN64)

#include <Windows.h>

BOOL APIENTRY DllMain(HANDLE, DWORD ul_reason_for_call, LPVOID)
{
	BOOL result = TRUE;

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		{
			break;
		}
	case DLL_PROCESS_DETACH:
		{
			break;
		}
	case DLL_THREAD_ATTACH:
		{
			break;
		}
	case DLL_THREAD_DETACH:
		{
			break;
		}
	default:
		break;
	}

	return result;
}

#endif