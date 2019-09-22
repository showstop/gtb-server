#include <ServerBase/logger.h>
#include <assert.h>
#include <stdarg.h>
#include <iostream>
#include <BaseCat/Log.h>
#include <iomanip>
#include <sstream>
#include <ServerBase/sb_define.h>
#include <SpringCat/SpringCat.h>

	/// Log::Impl interface
	struct Log::impl
	{
		virtual ~impl()	{};
		virtual void write(const char*)=0;
		virtual void write(const std::string&)=0;
		virtual void write(int)=0;
		virtual void write(unsigned int)=0;
		virtual void write(uint64) =0;
		virtual void write(float)=0;
		virtual void flush()=0;
	};

	Log::impl* Log::getLogImpl(Log::Level level)
	{
		class LogNone : public Log::impl
		{
		public:
			void write(const char*)			{}
			void write(const std::string&)	{}
			void write(int)					{}
			void write(float)				{}
			void write(unsigned int)		{}
			void write(uint64)			{}
			void flush()					{}
		};

		class LogImpl : public Log::impl
		{
		private:
			const Log::Level level_;
			std::string buf_;
		public:
			LogImpl(Log::Level level) : level_(level)	{}
			virtual ~LogImpl()							{ flush(); }
			void write(const std::string& rhs)	{ buf_.append(rhs); }
			void write(const char* rhs)			{ buf_.append(rhs); }
			void write(int rhs)					{ std::ostringstream os; os << rhs; buf_.append(os.str());}
			void write(unsigned int rhs)		{ std::ostringstream os; os << rhs; buf_.append(os.str());}
			void write(uint64 rhs)			{ std::ostringstream os; os << rhs; buf_.append(os.str());}
			void write(float rhs)				{ std::ostringstream os; os << std::showpoint << std::setprecision(6);buf_.append(os.str());}
			void flush()						
			{	if(!buf_.length())	return;

			// exception safe
			std::string temp((size_t)0, (char)0);
			temp.swap(buf_);
			Log::Logger::instance().write(level_, temp);
			}
		};
		return new LogImpl(level);
	}

	//// class Log implementation

	Log::Log(int level)
		: pimpl(getLogImpl(static_cast<Level>(level)))
	{	}

	Log::~Log()
	{
		pimpl->flush();
		delete pimpl;
	}

	Log& Log::operator << (const char* rhs)
	{
		pimpl->write(rhs);
		return *this;
	}
	Log& Log::operator << (const std::string& rhs)
	{
		pimpl->write(rhs);
		return *this;
	}
	Log& Log::operator << (int rhs)
	{
		pimpl->write(rhs);
		return *this;
	}
	Log& Log::operator << (unsigned int rhs)
	{
		pimpl->write(rhs);
		return *this;
	}

	Log& Log::operator << (uint64 rhs )
	{
		pimpl->write(rhs);
		return *this;
	}

	Log& Log::operator << (float rhs)
	{
		pimpl->write(rhs);
		return *this;
	}
	Log& Log::operator << (const end)
	{
		pimpl->flush();
		return *this;
	}

#define MAX_LOGGER_COUNT 4

	enum LOGGER_INDEX
	{
		LI_ERROR = 0,
		LI_PROCESS,
		LI_DEBUG,
		LI_SERVICE,
	};
const int GAME_LOGGER_INDEX = 0;

	BaseCat::Log::Handle logcat_[MAX_LOGGER_COUNT];

	std::string log_namespace_;
	std::string log_config_;

	bool Log::initialize(const std::string& log_namespace, 
		const std::string& log_config)
	{
		log_namespace_ = log_namespace;
		log_config_ = log_config;

		if(false == BaseCat::Log::Initialize(log_namespace.c_str(), log_config.c_str()))
			return false;

		memset(logcat_ , 0, sizeof(logcat_));

		logcat_[LI_ERROR]		= BaseCat::Log::GetLogger(log_namespace_.c_str(), "Error");
		logcat_[LI_PROCESS]		= BaseCat::Log::GetLogger(log_namespace_.c_str(), "Process");
		logcat_[LI_DEBUG]		= BaseCat::Log::GetLogger(log_namespace_.c_str(), "Debug");
		logcat_[LI_SERVICE]		= BaseCat::Log::GetLogger(log_namespace_.c_str(), "Service");
		return true;
	}

	void Log::uninitialize()
	{
		memset(logcat_ , 0, sizeof(logcat_));
		BaseCat::Log::Uninitialize(log_namespace_.c_str());
	}

	//// class Log::Logger implementation
	Log::Logger& Log::Logger::instance()
	{
		class LoggerImpl : public Log::Logger
		{
		public:
			LoggerImpl(){}
			virtual ~LoggerImpl(){}
			void write(Level level, const std::string& log)
			{
				if(level & Log::Error)	BaseCat::Log::Fatal(logcat_[LI_ERROR], log.c_str());
				if(level & Log::Process) BaseCat::Log::Fatal(logcat_[LI_PROCESS], log.c_str());
				if(level & Log::Debug) BaseCat::Log::Fatal(logcat_[LI_DEBUG], log.c_str());
				if(level & Log::Service) BaseCat::Log::Fatal(logcat_[LI_SERVICE], log.c_str());
			}
		};

		static LoggerImpl instance;
		return instance;
	}

	SB_EXPORT_API void write_fmt(int log_level, const char* format, ...)
	{
		char buffer[8192] = {0, };
		va_list args;

		va_start(args, format);
		FUNC_VSPRINTF_SAFE(buffer, sizeof(buffer) / sizeof(buffer[0]), format, args);
		va_end(args);

		Log(static_cast<Log::Level>(log_level)) << buffer;
	}