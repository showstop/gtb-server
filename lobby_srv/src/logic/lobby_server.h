#ifndef __GTB_LOBBY_SERVER__
#define __GTB_LOBBY_SERVER__

#include <boost/scoped_ptr.hpp>
#include <util/db_connection.h>
#include <ServerBase/sb_define.h>
#include <xNetConnector.h>
#include <protocol/internal_resource_report.dc.h>


namespace lobby {

	class server
	{
	private:
		server();
		virtual ~server();

	public:
		static server& instance();

		typedef void(*stop_event)(void*);
		void set_on_stop_event(const stop_event& event, void* context);

		bool start();
		void stop();

		int32 get_server_no() const;
		const std::string& get_server_name() const;
		std::pair<std::string, uint16> get_server_addr() const;

		void get_game_resource_data(protocol::game_monitor_data& data);

	private:
		bool load_server_info();
	private:
		struct impl;
		boost::scoped_ptr<impl> pimpl_;
	};
}

#endif
