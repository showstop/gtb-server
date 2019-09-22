#ifndef __PLAY_SERVER_AGENT__
#define __PLAY_SERVER_AGENT__

#include <ServerBase/sb_define.h>
#include <common/server_consts.h>
#include <ServerBase/link_base.h>
#include <boost/shared_ptr.hpp>
#include "../player/player.h"
#include <xNetConnector.h>

namespace play {

	typedef std::vector<player_no_t> player_list_t;

	enum server_state
	{
		IDLE = 1,
		IN_GAME,
		PREPARE_ENDING,
		COMPLETE,
	};

	struct game_play_info
	{
		game_play_info()
			: mode_(protocol::GameMode_QUICK), room_no_(0), track_no_(0) {}

		protocol::GameMode mode_;
		int32 room_no_;
		int32 track_no_;
		struct player_info
		{
			player_no_t player_no_;
			bool is_ai_;
			xNet::address xNet_addr_;
		};
		std::vector<player_info> players_;
	};

	class server_agent
	{
	public:
		server_agent(uint16 server_no, uint32 pid);
		~server_agent();

		uint16 get_server_no() const { return server_no_; }
		uint32 get_pid() const { return pid_; }

		bool get_player_xNet_addr(player_no_t player_no, xNet::address& addr);

		void set_match_server_room_no(uint32 ms_room_no) { ms_room_no_ = ms_room_no; }
		uint32 get_match_server_room_no() { return ms_room_no_; }

		void set_match_server_xNet_addr(const xNet::address_ext& addr) { ms_addr_ = addr; }
		xNet::address_ext get_match_server_xNet_addr() { return ms_addr_; }

		void set_game_play_info(const game_play_info& gpi);
		void set_link(const network::link_ptr_t& link) { link_ = link; }

		void get_game_play_info(game_play_info& gpi);
		const game_play_info& get_game_play_info() const { return gpi_; }

		bool send_game_play_info();

		bool send(const SpringCat::Wave::object_base& msg) { return link_->send(msg); }
		int32 get_timestamp() const { return timestamp_; }

		server_state get_state() const { return state_; }
		void set_state(server_state state) { state_ = state; }
	private:
		server_state state_;
		int32 timestamp_;				// launch ps time.
		uint32 pid_;
		uint16 server_no_;				// playserver port
		network::link_ptr_t link_;		// ps_link

		uint32 ms_room_no_;				// match server room no
		xNet::address_ext ms_addr_;			// match server xNet addr

		game_play_info gpi_;
	};
	typedef boost::shared_ptr<server_agent> server_agent_ptr_t;

}


#endif