#include "gc_grandprix_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../player/repository.h"

namespace protocol {

	bool grandprix_rank_info_req_job::process()
	{
		grandprix_rank_info_req req;
		if (!req.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[grandprix_rank_info_req_job::process()] grandprix_rank_info_req deserialize failed.");
			return false;
		}

		grandprix_rank_info_ans ans;
		ans.set_result(error::common::success);
		ans.set_rank_type(req.get_rank_type());

		// TODO
		link_->send(ans);

		write_fmt(Log::Process, "[grandprix_rank_info_req_job::process()]  grandprix_rank_info_ans success.(player_no:%lld)",
			link_->get_ref_id());
		return true;
	}
}