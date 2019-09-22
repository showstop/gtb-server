#include "gc_player_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../player/repository.h"
#include "../player/player_dbo.h"

namespace protocol {

	bool player_profile_info_req_job::process()
	{
		player_profile_info_req req;
		if (!req.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[player_profile_info_req_job::process()] player_profile_info_req deserialize failed.");
			return false;
		}

		player_profile_info_ans ans;
		ans.set_result(error::common::success);

		auto player_no = link_->get_ref_id();
		if (false == dbo::player::load_player_profile_info(player_no, *ans.get_mutable_info()))
		{
			write_fmt(Log::Process, "[player_profile_info_req_job::process()] not exist player-no(%lld)", player_no);
			
			ans.set_result(error::lobby::not_exist_player);
			return link_->send(ans);
		}
		
		link_->send(ans);

		write_fmt(Log::Process, "[player_profile_info_req_job::process()] (player_no:%lld)", player_no);
		return true;
	}
}