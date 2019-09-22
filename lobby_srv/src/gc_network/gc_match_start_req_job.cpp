#include "gc_lobby_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../player/repository.h"
#include "../xNet_network/xNet_gateway.h"
#include <protocol/internal_ls_mms.dc.h>
#include "../logic/lobby_server.h"

namespace protocol {

	bool match_start_req_job::process()
	{
		match_start_req req;
		if (!req.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[match_start_req_job::process()] match_start_req deserialize failed.");
			return false;
		}

		match_start_ans ans;
		ans.set_result(error::common::success);

		auto player_no = link_->get_ref_id();
		auto player_obj = player::repository::instance().find(player_no);
		if (nullptr == player_obj)
		{
			return true;
		}
		// TODO check if ticket count and so on...

		internal_register_player_req req_to_ms;
		req_to_ms.set_mode(req.get_mode());
		player_obj->get_profile_info(*req_to_ms.get_mutable_info());
		*req_to_ms.get_mutable_using_match_items() = *req.get_mutable_using_match_items();

		xNet::address_ext dest;
		dest.set_type(xNet::MULTICAST);
		dest.set_group_name(XNET_MATCH_NAME, static_cast<int>(strlen(XNET_MATCH_NAME)));
		xNet::gateway::instance().send(dest.to_address(), req_to_ms);

		write_fmt(Log::Process, "[match_start_req_job::process()] request to match server.(player_no:%lld, mode:%d)",
			player_no, req.get_mode());
		return true;
	}
}