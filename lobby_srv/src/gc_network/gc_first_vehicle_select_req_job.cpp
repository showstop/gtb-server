#include "gc_lobby_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../player/repository.h"
#include "../player/player_dbo.h"

namespace protocol {

	bool first_vehicle_select_req_job::process()
	{
		first_vehicle_select_req req;
		if (!req.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[first_vehicle_select_req_job::process()] first_vehicle_select_req deserialize failed.");
			return false;
		}

		first_vehicle_select_ans ans;
		ans.set_result(error::common::success);

		auto player_no = link_->get_ref_id();
		auto player_obj = player::repository::instance().find(player_no);
		if (nullptr == player_obj)
		{
			return true;
		}

		auto possess_count = player_obj->get_vehicle_agent()->get_possess_count();
		if (possess_count > 0)
		{
			ans.set_result(error::lobby::already_received_first_car);
			return link_->send(ans);
		}

		auto selected_first_car = req.get_selected_vehicle_no();

		auto res = player_obj->get_vehicle_agent()->upgrade(selected_first_car);
		if (res != error::common::success)
		{
			write_fmt(Log::Error, "[first_vehicle_select_req_job::process()] acquire first car failed.(vehicle_no:%d, player_no:%lld)",
				selected_first_car, player_no);
			ans.set_result(res);
			return link_->send(ans);
		}
		player_obj->get_vehicle_agent()->select(selected_first_car);

		dbo::player::save_first_vehicle(player_no, req.get_selected_vehicle_no());

		link_->send(ans);

		write_fmt(Log::Process, "[first_vehicle_select_req_job::process()] (player_no:%lld, first_vehicle:%d)", player_no, req.get_selected_vehicle_no());
		return true;
	}
}