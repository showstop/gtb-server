#include "gc_player_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../player/repository.h"
#include "../player/player_dbo.h"

namespace protocol {

	bool update_player_profile_info_req_job::process()
	{
		update_player_profile_info_req req;
		if (!req.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[update_player_profile_info_req_job::process()] update_player_profile_info_req deserialize failed.");
			return false;
		}

		update_player_profile_info_ans ans;
		ans.set_result(error::common::success);

		auto player_no = link_->get_ref_id();

		auto player_obj = player::repository::instance().find(player_no);
		if (nullptr == player_obj)
		{
			write_fmt(Log::Error, "[update_player_profile_info_req_job::process()] cannot find player-obj(player_no:%lld)", player_no);
			return false;
		}

		player_obj->set_profile_info(
			req.get_game_nick(),
			req.get_nation_code());

		player_obj->get_profile_info(*ans.get_mutable_info());
		link_->send(ans);

		write_fmt(Log::Process, "[update_player_profile_info_req_job::process()] (player_no:%lld)", player_no);
		return true;
	}
}