#include "gc_vehicle_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../player/repository.h"

namespace protocol {

	bool vehicle_select_req_job::process()
	{
		vehicle_select_req req;
		if (!req.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[vehicle_select_req_job::process()] vehicle_select_req deserialize failed.");
			return false;
		}

		vehicle_select_ans ans;
		ans.set_result(error::common::success);

		auto player_no = link_->get_ref_id();

		auto player_obj = player::repository::instance().find(player_no);
		if (nullptr == player_obj)
		{
			return true;
		}
		auto res = player_obj->get_vehicle_agent()->select(req.get_vehicle_no());
		if (res != error::common::success)
		{
			write_fmt(Log::Process, "[vehicle_select_req_job::process()] (player_no:%lld, req_selected_no:%d, result:%d)",
				player_no, req.get_vehicle_no(), res);

			ans.set_result(res);
			return link_->send(ans);
		}
		ans.set_selected_vehicle_no(player_obj->get_vehicle_agent()->get_selected());
		link_->send(ans);

		write_fmt(Log::Process, "[vehicle_select_req_job::process()] (player_no:%lld, selected_no:%d)",
			player_no, ans.get_selected_vehicle_no());
		return true;
	}
}