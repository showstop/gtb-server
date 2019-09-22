#include "xNet_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../match/quick_match_pool.h"
#include <xNetConnector.h>

namespace protocol {

	bool internal_unregister_player_req_job::process()
	{
		internal_unregister_player_req req;
		if (!req.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[internal_unregister_player_req_job::process()] internal_unregister_player_req deserialize failed.");
			return false;
		}

		switch (req.get_mode())
		{
		case protocol::GameMode_QUICK:
		{
			match::quick_pool::instance().remove(req.get_player_no());
			break;
		}
		case protocol::GameMode_GRANDPRIX:
		{
			break;
		}
		default:
			break;
		}

		internal_unregister_player_ans ans;
		ans.set_result(error::common::success);
		ans.set_dest_player_no(req.get_player_no());

		sock_->send(src_, ans);

		write_fmt(Log::Process, "[internal_unregister_player_req_job::process()] unregister to match-pool(mode:%d, player_no:%lld).",
			req.get_mode(), req.get_player_no());

		return true;
	}
}