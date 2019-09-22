#include "gc_achievement_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../player/repository.h"

namespace protocol {

	bool achievement_list_req_job::process()
	{
		achievement_list_req req;
		if (!req.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[achievement_list_req_job::process()] achievement_list_req deserialize failed.");
			return false;
		}

		achievement_list_ans ans;
		ans.set_result(error::common::success);

		auto player_no = link_->get_ref_id();
		auto player_obj = player::repository::instance().find(player_no);
		if (nullptr == player_obj)
		{
			write_fmt(Log::Error, "[achievement_list_req_job::process()] cannot find player-obj(player_no:%lld).", player_no);
			return true;
		}

		player_obj->get_achievement_agent()->get_achievement_list(*ans.get_mutable_infos());
		link_->send(ans);

		write_fmt(Log::Process, "[achievement_list_req_job::process()] achievement_list_ans success.(player_no:%lld)",
			link_->get_ref_id());
		return true;
	}
}