#include "gc_lobby_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../player/repository.h"
#include "../player/player_dbo.h"

namespace protocol {

	bool tutorial_progress_update_req_job::process()
	{
		tutorial_progress_update_req req;
		if (!req.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[tutorial_progress_update_req_job::process()] tutorial_progress_req deserialize failed.");
			return false;
		}

		tutorial_progress_update_ans ans;
		ans.set_result(error::common::success);
		ans.set_progress(req.get_progress());

		auto player_no = link_->get_ref_id();
		auto player_obj = player::repository::instance().find(player_no);
		if (nullptr == player_obj)
		{
			return true;
		}

		dbo::player::save_tutorial_update_progress(player_no, req.get_progress());

		link_->send(ans);

		write_fmt(Log::Process, "[tutorial_progress_req_job::process()] (player_no:%lld, progress:%d)", player_no, req.get_progress());
		return true;
	}
}