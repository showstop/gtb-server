#include "gc_dev_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../player/repository.h"

namespace dev {

	bool put_vehicle_card_req_job::process()
	{
		put_vehicle_card_req req;
		if (!req.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[put_vehicle_card_req_job::process()] put_vehicle_card_req deserialize failed.");
			return false;
		}

		put_vehicle_card_ans ans;
		auto player_no = link_->get_ref_id();
		auto player_obj = player::repository::instance().find(player_no);
		if (nullptr == player_obj)
		{
			return true;
		}

		auto res = player_obj->get_vehicle_agent()->acquire_card(req.get_vehicle_no(), req.get_quantity());
		ans.set_result(res);
		player_obj->get_vehicle_agent()->get_vehicle(req.get_vehicle_no(), *ans.get_mutable_updated_vehicle());
		link_->send(ans);

		write_fmt(Log::Process, "[put_vehicle_card_req_job::process()]  put_vehicle_card_ans success.(result:%d, player_no:%lld, vehicle_no:%d, quantiy:%d)",
			res, player_no, req.get_vehicle_no(), req.get_quantity());
		return true;
	}
}