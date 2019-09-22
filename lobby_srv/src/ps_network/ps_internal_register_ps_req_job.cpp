#include "ps_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../player/repository.h"
#include "../logic/lobby_server.h"
#include "../playserver/ps_manager.h"

namespace protocol {

	bool internal_register_ps_req_job::process()
	{
		internal_register_ps_req req;
		if (!req.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[internal_register_ps_req_job::process()] internal_register_ps_req deserialize failed.");
			return false;
		}

		internal_register_ps_ans ans;
		ans.set_result(error::common::success);

		auto ps_no = req.get_ps_no();

		play::server_agent_ptr_t ps_obj;
		if (false == play::server_manager::instance().find(ps_no, ps_obj))
		{
			ans.set_result(error::play::not_exist_ps_info);
			write_fmt(Log::Error, "[internal_register_ps_req_job::process() cannot find ps-obj.(ps_no:%d)", ps_no);
			return link_->send(ans);
		}

		link_->set_link_id(ps_no);
		ps_obj->set_link(link_);
		ps_obj->send_game_play_info();

		write_fmt(Log::Process, "[internal_register_ps_req_job::process()] register ps success(ps_no:%d)", req.get_ps_no());

		return true;
	}
}