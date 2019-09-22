#if defined(_WIN32) || defined(_WIN64)

#ifndef __GAME_SERVER_BASE__
#define __GAME_SERVER_BASE__

	#ifndef USE_SERVERBASE_DLL
		#define SB_EXPORT_API
		#ifndef STATIC_SERVERBASE_EXPORT
			#ifndef _DEBUG
				#pragma comment(lib, "ServerBase140MT.lib")
			#else
				#pragma comment(lib, "ServerBase140MTd.lib")
			#endif
		#endif
	#else
		#ifdef SERVERBASE_EXPORTS
			#define SB_EXPORT_API __declspec(dllexport)
		#else
			#define SB_EXPORT_API __declspec(dllimport)

			#ifndef _DEBUG
				#pragma comment(lib, "ServerBase.lib")
			#else
				#pragma comment(lib, "ServerBaseD.lib")
			#endif
		#endif
	#endif
#endif

#else
	#define SB_EXPORT_API
#endif