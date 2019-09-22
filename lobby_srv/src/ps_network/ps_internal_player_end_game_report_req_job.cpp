#include "ps_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../player/repository.h"
#include "../logic/lobby_server.h"
#include "../playserver/ps_manager.h"
#include "../xNet_network/xNet_gateway.h"
#include "../registry/config_registry.h"
#include <protocol/internal_ls_ls.dc.h>

namespace protocol {
	
	bool internal_player_end_game_report_req_job::process()
	{
		internal_player_end_game_report_req req;
		if (!req.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[internal_player_end_game_report_req_job::process()] internal_player_end_game_report_req deserialize failed.");
			return false;
		}

		auto final_rank = req.get_final_rank();
		internal_player_end_game_report_ans ans;
		ans.set_player_no(req.get_player_no());
		ans.set_giveup_game(req.get_giveup_game());
		ans.set_final_rank(final_rank);

		int32 first_reward = 0, second_reward = 0;
		if(false == req.get_giveup_game())
		{
			switch (final_rank)
			{
			case 1:
			{
				first_reward = config::registry::instance().get_reward_stuff_id(config::PLATINUM);
				break;
			}
			case 2:
			{
				first_reward = config::registry::instance().get_reward_stuff_id(config::GOLD);
				break;
			}
			case 3:
			{
				first_reward = config::registry::instance().get_reward_stuff_id(config::SILVER);
				break;
			}
			second_reward = config::registry::instance().get_reward_stuff_id(config::SILVER);
			}

			ans.set_first_acquired_stuff_id(first_reward);
			ans.set_second_acquired_stuff_id(second_reward);

		}
		// send ans to ps
		link_->send(ans);

		play::server_agent_ptr_t sa_obj;
		if (false == play::server_manager::instance().find(link_->get_link_id(), sa_obj))
		{
			write_fmt(Log::Error, "[internal_player_end_game_report_req_job::process()] cannot find ps-agent obj(ps_no:%d, player_no:%lld)",
				link_->get_link_id(), req.get_player_no());

			return false;
		}

		auto game_mode = sa_obj->get_game_play_info().mode_;

		protocol::internal_player_end_game_report_notify noti_to_other;
		noti_to_other.set_mode(game_mode);
		noti_to_other.set_player_no(ans.get_player_no());
		noti_to_other.set_vehicle_no(req.get_using_vehicle_no());
		noti_to_other.set_is_giveup(req.get_giveup_game());
		noti_to_other.set_final_rank(req.get_final_rank());
		noti_to_other.set_inc_game_money(req.get_inc_game_money());
		noti_to_other.set_inc_exp(req.get_inc_player_exp());
		noti_to_other.set_first_reward_stuff_id(ans.get_first_acquired_stuff_id());
		noti_to_other.set_second_reward_stuff_id(ans.get_second_acquired_stuff_id());
		*noti_to_other.get_mutable_play_data() = *req.get_mutable_play_data();

		xNet::address dest_ls_addr;
		sa_obj->get_player_xNet_addr(ans.get_player_no(), dest_ls_addr);

		xNet::gateway::instance().send(dest_ls_addr, noti_to_other);

		write_fmt(Log::Process, "[internal_player_end_game_report_req_job::process()] player_no:%lld", req.get_player_no());
		return true;
	}
}