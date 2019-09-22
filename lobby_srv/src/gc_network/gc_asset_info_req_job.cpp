#include "gc_lobby_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../player/repository.h"
#include "../player/player_dbo.h"

namespace protocol {

	bool asset_info_req_job::process()
	{
		asset_info_req req;
		if (!req.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[asset_info_req_job::process()] asset_info_req deserialize failed.");
			return false;
		}

		asset_info_ans ans;
		ans.set_result(error::common::success);

		auto player_no = link_->get_ref_id();
		auto player_obj = player::repository::instance().find(player_no);
		if (nullptr == player_obj)
		{
			return true;
		}

		*ans.get_mutable_info() = player_obj->get_asset_agent()->get_asset_info();
		link_->send(ans);

		write_fmt(Log::Process, "[asset_info_req_job::process()] (player_no:%lld)", player_no);
		return true;
	}
}