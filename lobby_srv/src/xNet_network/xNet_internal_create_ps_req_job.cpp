#include "xNet_match_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../player/repository.h"
#include "../logic/lobby_server.h"
#include "../playserver/ps_manager.h"

namespace protocol {

	bool internal_create_ps_req_job::process()
	{
		internal_create_ps_req req;
		if (!req.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[internal_create_ps_req_job::process()] internal_create_ps_req deserialize failed.");
			return false;
		}

		internal_create_ps_ans ans;
		ans.set_result(error::common::success);
		ans.set_room_no(req.get_room_no());

		auto track_no = req.get_map_no();
		auto ps_obj = play::server_manager::instance().execute_play_server(req.get_mode(), track_no);
		if (nullptr == ps_obj.get())
		{
			ans.set_result(error::lobby::execute_ps_failed);
			sock_->send(src_, ans);
			return true;
		}

		ps_obj->set_match_server_room_no(req.get_room_no());
		ps_obj->set_match_server_xNet_addr(src_);

		play::game_play_info gpi;
		gpi.mode_ = req.get_mode();
		gpi.room_no_ = req.get_map_no();
		gpi.track_no_ = track_no;
		
		for (auto p : req.get_match_players())
		{
			play::game_play_info::player_info user;

			user.player_no_ = p.first;
			user.is_ai_ = p.second->get_is_ai();
			
			if (false == user.is_ai_)
			{
				auto& xNet_addr_bin = *p.second->get_mutable_binded_xnet_addr();
				memcpy(&user.xNet_addr_, &xNet_addr_bin[0], sizeof(xNet::address));
			}
			gpi.players_.push_back(user);
		}
		ps_obj->set_game_play_info(gpi);

		write_fmt(Log::Process, "[internal_create_ps_req_job::process()] execute play server success..(ms_addr:%s, room_no:%d)",
			xNet::address_ext(src_).to_string(), req.get_room_no());

		return true;
	}
}