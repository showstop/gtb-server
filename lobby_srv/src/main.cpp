#include <ServerBase/sb_define.h>
#include <ServerBase/logger.h>
#include "env/config.h"
#include "logic/lobby_server.h"

#define CONFIG_FILE "GTB.LobbyServer.cfg"
#define LOGCAT_NAMESPACE "LobbyServer"
#define LOGCAT_CONFIG_FILE "GTB.LobbyServerLogCat.xml"

class server
{
public:
	server()
	{

	}
	~server()
	{

	}

	bool start()
	{
		if (false == configurator::instance().load_ini(CONFIG_FILE))
		{
			Log(Log::Error) << CONFIG_FILE << " load fail...";
			return false;
		}
		Log(Log::Process) << CONFIG_FILE << " load success...";

		lobby::server::instance().set_on_stop_event(on_server_stop, this);
		return lobby::server::instance().start();
	}

	void wait()
	{
		quit_.Wait();
	}

	void stop()
	{
		lobby::server::instance().stop();
		quit_.Set();
	}

private:
	static void on_server_stop(void* context)
	{
		server* serv = static_cast<server*>(context);
		serv->quit_.Set();
	}
private:
	SpringCat::System::Threading::AutoResetEvent quit_;
};

class scoped_logger
{
public:
	scoped_logger()
	{
		if (false == Log::initialize(LOGCAT_NAMESPACE, LOGCAT_CONFIG_FILE))
		{
			throw "LogCat Initialize failed! check your file(.xml .dll)";
		}
	}
	~scoped_logger()
	{
		Log::uninitialize();
	}

	static scoped_logger& instance()
	{
		static scoped_logger sl;
		return sl;
	}
};

server lobby_server;

#if defined(WIN32) || defined(_WIN64)
#include "main_win_impl.inl"
#else 
#include "main_linux_impl.inl"
#endif
