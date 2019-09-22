#include "ps_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../player/repository.h"
#include "../logic/lobby_server.h"
#include "../playserver/ps_manager.h"

namespace protocol {

	bool internal_end_game_req_job::process()
	{
		internal_end_game_req req;
		if (!req.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[internal_end_game_req_job::process()] internal_end_game_req deserialize failed.");
			return false;
		}

		internal_end_game_ans ans;
		ans.set_result(error::common::success);

		play::server_agent_ptr_t ps_obj;
		if (false == play::server_manager::instance().find(req.get_ps_no(), ps_obj))
		{
			write_fmt(Log::Error, "[internal_end_game_req_job::process()] cannot find play-server obj(ps_no:%d)", req.get_ps_no());
			return false;
		}

		ps_obj->set_state(play::COMPLETE);

		link_->send(ans);
		write_fmt(Log::Process, "[internal_end_game_req_job::process()] internal_end_game_req");
		return true;
	}
}