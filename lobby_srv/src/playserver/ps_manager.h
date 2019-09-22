#ifndef __PLAY_SERVER_MANAGER__
#define __PLAY_SERVER_MANAGER__

#include <ServerBase/sb_define.h>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include "ps_agent.h"
#include <protocol/internal_ls_ps.dc.h>
#include <xNetConnector.h>
#include "../ps_network/ps_acceptor.h"

namespace play {

	class server_manager
	{
	private:
		server_manager();
		~server_manager();

	public:
		static server_manager& instance();

		bool start(uint16 port);
		void stop();
		void test();

		server_agent_ptr_t execute_play_server(protocol::GameMode mode, int32 track_no);
		void kill_play_server(uint16 ps_no);

		bool find(uint16 ps_no, server_agent_ptr_t& sa_obj);
		void set_ps_link(uint16 ps_no, const network::link_ptr_t& link);

	private:
		void internal_kill_play_server(uint16 ps_no);
		uint16 internal_next_port_no();
		static void on_zombie_ps_detect(unsigned int timer_id, void* context);

	private:
		CriticalSection cs_;

		int32 zombie_ps_detector_timer_id_;

		uint16 current_port_index_;
		boost::scoped_ptr<ps::acceptor> acceptor_;
		typedef std::map<uint16, server_agent_ptr_t> sa_map_t;		// assigned port, obj
		sa_map_t sa_map_;
	};

}

#endif