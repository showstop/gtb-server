#include "gc_lobby_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../player/repository.h"

namespace protocol {

	bool match_item_buy_req_job::process()
	{
		match_item_buy_req req;
		if (!req.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[match_item_buy_req_job::process()] match_item_buy_req deserialize failed.");
			return false;
		}

		match_item_buy_ans ans;
		ans.set_result(error::common::success);

		auto player_no = link_->get_ref_id();
		auto player_obj = player::repository::instance().find(player_no);
		if (nullptr == player_obj)
		{
			return true;
		}
		// TODO

		link_->send(ans);

		write_fmt(Log::Process, "[match_item_buy_req_job::process()] match_item_buy_ans.(player_no:%lld)",
			link_->get_ref_id());
		return true;
	}
}