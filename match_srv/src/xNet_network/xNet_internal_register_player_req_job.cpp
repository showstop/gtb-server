#include "xNet_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../match/quick_match_pool.h"
#include <xNetConnector.h>

namespace protocol {

	bool internal_register_player_req_job::process()
	{
		internal_register_player_req req;
		if (!req.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[internal_register_player_req_job::process()] internal_register_player_req deserialize failed.");
			return false;
		}

		int32 avg_match_sec = 0;
		switch (req.get_mode())
		{
		case protocol::GameMode_QUICK:
		{
			match::quick_pool::instance().add(req.get_info()->get_player_no(), src_, *req.get_using_match_items());
			avg_match_sec = match::quick_pool::instance().get_avg_match_sec();
			break;
		}
		case protocol::GameMode_GRANDPRIX:
		{
			break;
		}
		default:
			break;
		}

		internal_register_player_ans ans;
		ans.set_result(error::common::success);
		ans.set_dest_player_no(req.get_info()->get_player_no());
		ans.set_estimated_sec(avg_match_sec);

		sock_->send(src_, ans);

		write_fmt(Log::Process, "[internal_register_player_req_job::process()] register to match-pool(mode:%d, player_no:%lld).",
			req.get_mode(), req.get_info()->get_player_no());

		return true;
	}
}