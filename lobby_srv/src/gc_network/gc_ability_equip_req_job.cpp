#include "gc_ability_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../player/repository.h"
#include "../player/player_dbo.h"

namespace protocol {

	bool ability_equip_req_job::process()
	{
		ability_equip_req req;
		if (!req.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[ability_equip_req_job::process()] ability_equip_req deserialize failed.");
			return false;
		}

		ability_equip_ans ans;
		ans.set_result(error::common::success);

		auto player_no = link_->get_ref_id();
		auto player_obj = player::repository::instance().find(player_no);
		if (nullptr == player_obj)
		{
			write_fmt(Log::Error, "[ability_equip_req_job::process()] cannot find player-obj(player_no:%lld).", player_no);
			return true;
		}

		auto res = player_obj->get_ability_agent()->equip(req.get_slot_no(), req.get_ability_id());
		if (res != error::common::success)
		{
			ans.set_result(res);
			return link_->send(ans);
		}

		player_obj->get_ability_agent()->get_ability_slot(*ans.get_mutable_updated_slot());
		link_->send(ans);

		write_fmt(Log::Process, "[ability_equip_req_job::process()] (player_no:%lld)", player_no);
		return true;
	}
}