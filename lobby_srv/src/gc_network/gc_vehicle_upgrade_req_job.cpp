#include "gc_vehicle_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../player/repository.h"

namespace protocol {

	bool vehicle_upgrade_req_job::process()
	{
		vehicle_upgrade_req req;
		if (!req.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[vehicle_upgrade_req_job::process()] vehicle_upgrade_req deserialize failed.");
			return false;
		}

		vehicle_upgrade_ans ans;
		ans.set_result(error::common::success);

		auto player_no = link_->get_ref_id();
		auto player_obj = player::repository::instance().find(player_no);
		if (nullptr == player_obj)
		{
			return true;
		}

		auto res = player_obj->get_vehicle_agent()->upgrade(req.get_vehicle_no());
		if (res != error::common::success)
		{
			write_fmt(Log::Process, "[vehicle_upgrade_req_job::process()] (player_no:%lld, vehicle_no:%d, result:%d)",
				player_no, req.get_vehicle_no(), res);

			ans.set_result(res);
			return link_->send(ans);
		}
		link_->send(ans);

		write_fmt(Log::Process, "[vehicle_upgrade_req_job::process()] (player_no:%lld)", player_no);
		return true;
	}
}