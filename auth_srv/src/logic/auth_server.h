#ifndef __GTB_AUTH_SERVER__
#define __GTB_AUTH_SERVER__

#include <boost/scoped_ptr.hpp>
#include <util/db_connection.h>
#include <ServerBase/sb_define.h>

namespace auth {

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

	private:
		bool load_server_info();
	private:
		struct impl;
		boost::scoped_ptr<impl> pimpl_;
	};
}


#endif
