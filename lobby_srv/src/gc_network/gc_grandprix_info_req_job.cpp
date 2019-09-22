#include "gc_grandprix_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../player/repository.h"

namespace protocol {

	bool grandprix_info_req_job::process()
	{
		grandprix_info_req req;
		if (!req.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[grandprix_info_req_job::process()] grandprix_info_req_ deserialize failed.");
			return false;
		}

		grandprix_info_ans ans;
		ans.set_result(error::common::success);

		auto player_no = link_->get_ref_id();
		auto player_obj = player::repository::instance().find(player_no);
		if (nullptr == player_obj)
		{
			return true;
		}

		player_obj->get_grandprix_agent()->get_grandprix_info(*ans.get_mutable_info());
		link_->send(ans);

		write_fmt(Log::Process, "[grandprix_info_req_job::process()]  grandprix_info_ans success.(player_no:%lld)",
			link_->get_ref_id());
		return true;
	}
}