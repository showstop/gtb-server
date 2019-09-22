#include "ps_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../player/repository.h"
#include "../logic/lobby_server.h"
#include "../playserver/ps_manager.h"
#include <protocol/internal_ls_mms.dc.h>
#include "../xNet_network/xNet_gateway.h"

namespace protocol {

	bool internal_start_game_ans_job::process()
	{
		internal_start_game_ans ans;
		if (!ans.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[internal_start_game_ans_job::process()] internal_start_game_ans deserialize failed.");
			return false;
		}

		auto ps_no = link_->get_link_id();

		play::server_agent_ptr_t ps_obj;
		if (false == play::server_manager::instance().find(ps_no, ps_obj))
		{
			ans.set_result(error::play::not_exist_ps_info);
			write_fmt(Log::Error, "[internal_start_game_ans_job::process() cannot find ps-obj.(ps_no:%d)", ps_no);
			link_->send(ans);
		}

		internal_create_ps_ans ans_to_ms;
		ans_to_ms.set_result(ans.get_result());
		ans_to_ms.set_mode(ps_obj->get_game_play_info().mode_);
		ans_to_ms.set_room_no(ps_obj->get_match_server_room_no());
		ans_to_ms.get_mutable_ps_addr()->set_domain(lobby::server::instance().get_server_addr().first);
		ans_to_ms.get_mutable_ps_addr()->set_port(ps_obj->get_server_no());
		
		xNet::gateway::instance().send(ps_obj->get_match_server_xNet_addr().to_address(), ans_to_ms);

		write_fmt(Log::Process, "[internal_start_game_ans_job::process() send internal_create_ps_ans to MatchServer");

		return true;
	}
}