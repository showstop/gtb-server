#ifndef __K_SB_DEFINE__
#define __K_SB_DEFINE__

#include <SpringCat/SpringCat.h>

#if defined(_WIN32) || defined(_WIN64)

		#if !defined(type_defined)
		typedef signed char    int8;
		typedef signed short int16;
		typedef signed int int32;
		typedef __int64 int64;
		typedef unsigned char uint8;
		typedef unsigned short uint16;
		typedef unsigned int uint32;
		typedef unsigned __int64 uint64;
		typedef float float32;
		typedef double float64;

		#define type_defined
		#endif

	#define GET_TICK() GetTickCount()
	#define FUNC_SPRINTF_SAFE(buf, size, fmt, ...)		sprintf_s(buf, size, fmt, __VA_ARGS__)
	#define FUNC_VSPRINTF_SAFE(buf, size, fmt, args)	vsprintf_s(buf, size, fmt, args)
#else

		#if !defined(type_defined)
			#include <stdint.h>
	
			typedef char int8;
			typedef unsigned char byte;
			typedef short int16;
			typedef int int32;
			typedef int64_t int64;
			typedef unsigned char uint8;
			typedef unsigned short uint16;
			typedef unsigned int uint32;
			typedef uint64_t uint64;
			typedef float float32;
			typedef double float64;
		#define type_defined
		#endif

		#ifdef __MACH__
	
			#include <mach/clock.h>
			#include <mach/mach.h>
				static unsigned int GetTickCount()
				{
					unsigned int tick = 0;

					clock_serv_t cclock;
					mach_timespec_t mts;
					host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
					clock_get_time(cclock, &mts);
					mach_port_deallocate(mach_task_self(), cclock);

					tick = mts.tv_sec*1000 + mts.tv_nsec/1000;

					return tick;
				}
			#else
				#include <time.h>

				static unsigned int GetTickCount()
				{
					unsigned int tick = 0;

					struct timespec tspec;
					clock_gettime(CLOCK_REALTIME, &tspec);

					tick = tspec.tv_sec*1000 + tspec.tv_nsec/1000;

					return tick;
				}
		#endif
	#define GET_TICK() GetTickCount()
	#define FUNC_SPRINTF_SAFE(buf, size, fmt, ...)		snprintf(buf, size, fmt, __VA_ARGS__)
	#define FUNC_VSPRINTF_SAFE(buf, size, fmt, args)	vsnprintf(buf, size, fmt, args)

#endif
typedef SpringCat::System::Threading::ThreadPool ThreadPool;
typedef SpringCat::System::TL::NonCopyable NonCopyable;
typedef SpringCat::System::Stream Stream;
typedef SpringCat::System::SmartHeap::Block Block;
typedef SpringCat::System::StreamPtr StreamPtr;
typedef SpringCat::System::Threading::CriticalSection CriticalSection;
typedef SpringCat::System::Threading::RWCriticalSection RWCriticalSection;
typedef SpringCat::System::Threading::ScopedReadLock<> ScopedReadLock;
typedef SpringCat::System::Threading::ScopedWriteLock<> ScopedWriteLock;
typedef SpringCat::System::Threading::ScopedLock<> ScopedLock;

namespace network {
	typedef int session_id_t;
}


#endif