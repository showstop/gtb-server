#ifndef __GTB_MATCH_SERVER__
#define __GTB_MATCH_SERVER__

#include <boost/scoped_ptr.hpp>
#include <util/db_connection.h>
#include <ServerBase/sb_define.h>
#include <xNetConnector.h>
#include <protocol/internal_ls_mms.dc.h>

namespace match {

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
		int32 get_track_no(protocol::GameMode mode);

	private:
		bool load_server_info();
		bool load_track_info(const std::string& key, std::vector<int32>& tracks);
	private:
		struct impl;
		boost::scoped_ptr<impl> pimpl_;
	};
}

#endif
