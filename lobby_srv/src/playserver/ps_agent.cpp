#include "ps_agent.h"
#include "process_util.h"
#include <protocol/internal_ls_ps.dc.h>
#include <protocol/internal_ls_mms.dc.h>
#include "../env/config.h"
#include "ps_manager.h"
#include "../player/repository.h"
#include <ServerBase/logger.h>

namespace play {

	server_agent::server_agent(uint16 server_no, uint32 pid)
		: server_no_(server_no), pid_(pid), timestamp_(GET_TICK()), ms_room_no_(0)
	{

	}

	server_agent::~server_agent()
	{
		kill_process(pid_);
	}

	bool server_agent::get_player_xNet_addr(player_no_t player_no, xNet::address& addr)
	{
		auto it = std::find_if(gpi_.players_.begin(), gpi_.players_.end(), 
			[player_no](const game_play_info::player_info& pi)-> bool
		{
			return player_no == pi.player_no_;
		});

		if (it == gpi_.players_.end())
		{
			return false;
		}

		addr = (*it).xNet_addr_;
		return true;
	}

	void server_agent::set_game_play_info(const game_play_info& gpi)
	{
		gpi_ = gpi;
	}

	void server_agent::get_game_play_info(game_play_info& gpi)
	{
		gpi = gpi_;
	}

	bool server_agent::send_game_play_info()
	{
		protocol::internal_start_game_req req;

		std::random_shuffle(gpi_.players_.begin(), gpi_.players_.end());

		auto it = gpi_.players_.begin();
		for (; it != gpi_.players_.end(); ++it)
		{
			auto player_no = it->player_no_;
			auto is_ai = it->is_ai_;

			auto& info = *req.insert_player_infos(player_no);
			info.set_is_ai(is_ai);

			player::repository::instance().load_player_profile_info(player_no, *info.get_mutable_profile());
			player::repository::instance().load_selected_vehicle_info(player_no, *info.get_mutable_selected_car());
			player::repository::instance().load_ability_slot_info(player_no, *info.get_mutable_equipped_ability());
			player::repository::instance().load_ability_list(player_no, *info.get_mutable_abilities());
			// todo match_item_info
		}

		send(req);
		return true;
	}

}