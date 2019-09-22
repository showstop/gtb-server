#include "gc_vehicle_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../player/repository.h"

namespace protocol {

	bool vehicle_list_req_job::process()
	{
		vehicle_list_req req;
		if (!req.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[vehicle_list_req_job::process()] vehicle_list_req deserialize failed.");
			return false;
		}

		vehicle_list_ans ans;
		ans.set_result(error::common::success);

		auto player_no = link_->get_ref_id();
		auto player_obj = player::repository::instance().find(player_no);
		if (nullptr == player_obj)
		{
			return true;
		}

		player_obj->get_vehicle_agent()->get_vehicles(*ans.get_mutable_infos());
		ans.set_selected_vehicle_no(player_obj->get_vehicle_agent()->get_selected());
		link_->send(ans);

		write_fmt(Log::Process, "[vehicle_list_req_job::process()] (player_no:%lld)", player_no);
		return true;
	}
}