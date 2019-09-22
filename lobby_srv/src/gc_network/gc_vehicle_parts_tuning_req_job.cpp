#include "gc_vehicle_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../player/repository.h"

namespace protocol {

	bool vehicle_parts_tuning_req_job::process()
	{
		vehicle_parts_tuning_req req;
		if (!req.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[vehicle_parts_tuning_req_job::process()] vehicle_parts_tuning_req deserialize failed.");
			return false;
		}

		vehicle_parts_tuning_ans ans;
		ans.set_result(error::common::success);

		auto player_no = link_->get_ref_id();

		auto player_obj = player::repository::instance().find(player_no);
		if (nullptr == player_obj)
		{
			return true;
		}

		auto res = player_obj->get_vehicle_agent()->parts_tuning(req.get_vehicle_no(), req.get_parts_id());
		if (res != error::common::success)
		{
			write_fmt(Log::Process, "[vehicle_parts_tuning_req_job::process()] (player_no:%lld, req_selected_no:%d, req_parts_id:%d, result:%d)",
				player_no, req.get_vehicle_no(), req.get_parts_id(), res);

			ans.set_result(res);
			return link_->send(ans);
		}
		link_->send(ans);

		write_fmt(Log::Process, "[vehicle_parts_tuning_req_job::process()] (player_no:%lld)", player_no);
		return true;
	}
}