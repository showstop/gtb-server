#include "gc_lobby_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../player/repository.h"

namespace protocol {

	bool connect_lobby_req_job::process()
	{
		connect_lobby_req req;
		if (!req.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[connect_lobby_req_job::process()] connect_lobby_req deserialize failed.");
			return false;
		}

		connect_lobby_ans ans;
		ans.set_result(error::common::success);

		if (false == player::repository::instance().add(req.get_session_id(), link_))
		{
			write_fmt(Log::Error, "[connect_lobby_req_job::process()] invalid session_id..(session_id:%d)",
				req.get_session_id());

			ans.set_result(error::lobby::invalid_session_id);
			return link_->send(ans);
		}
		
		uint64 player_no = link_->get_ref_id();

		ans.set_player_no(player_no);
		link_->send(ans);

		player::repository::instance().confirm_reserved_session(req.get_session_id(), link_);
		write_fmt(Log::Process, "[connect_lobby_req_job::process()] connect to lobby success.(player_no:%lld)",
			link_->get_ref_id());
		return true;
	}
}