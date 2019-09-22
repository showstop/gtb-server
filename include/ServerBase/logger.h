#ifndef __K_SB_LOGGER__
#define __K_SB_LOGGER__

#include <ServerBase/serverbase.h>
#include <ServerBase/sb_define.h>
#include <SpringCat/Config/StdIntDefs.h>
#include <iostream>

	class SB_EXPORT_API Log
	{
	public:
		typedef enum Level
		{
			Error = 0x01,
			Process = 0x02,
			Debug = 0x04,
			Service = 0x08,				// for logging server
			All = Error | Process | Debug,
		}Level;

		typedef struct end { } end;

		struct initException {};		// exception for initialization log

		Log(int level);
		~Log();

		//typedef std::vector<std::string> LoggerList;
		static bool initialize(
			const std::string& log_namespace, 
			const std::string& log_config);
		static void uninitialize();
		Log& operator << (const char*);
		Log& operator << (const std::string&);
		Log& operator << (int);
		Log& operator << (unsigned int);
		Log& operator << (uint64);
		Log& operator << (float);
		Log& operator << (const end);

	private:
		struct impl;
		impl* pimpl;
		class Logger
		{
		public:
			virtual ~Logger() {};
			static Logger& instance();
			virtual void write(Level, const std::string& log)=0;
		protected:
			Logger() {};
		};
		static impl* getLogImpl(Level);
	};

	SB_EXPORT_API void write_fmt(int log_level, const char* format, ...);

#endif