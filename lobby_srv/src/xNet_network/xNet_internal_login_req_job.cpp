#include "xNet_auth_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../player/repository.h"
#include "../logic/lobby_server.h"

namespace protocol {

	bool internal_login_req_job::process()
	{
		internal_login_req req;
		if (!req.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[internal_login_req_job::process()] internal_login_req deserialize failed.");
			return false;
		}

		internal_login_ans ans;
		ans.set_result(error::common::success);

		auto player_no = req.get_player_no();
		auto key = &(*req.get_mutable_key())[0];
		auto iv = &(*req.get_mutable_iv())[0];
		
		auto new_session_id = player::repository::instance().reserve_session(
			player_no,
			key,
			iv
		);

		if (new_session_id < 0)
		{
			write_fmt(Log::Error, "[internal_login_req_job::process()] invalid session_id!!!(player_no=%lld, session_id=%d)",
				player_no, new_session_id);
			return false;
		}
		
		ans.set_session_id(new_session_id);
		ans.set_player_no(player_no);
		
		auto own_addr = lobby::server::instance().get_server_addr();
		auto& ls_addr = *ans.get_mutable_ls_addr();
		ls_addr.set_domain(own_addr.first);
		ls_addr.set_port(own_addr.second);

		// return to source address (AuthServer)
		sock_->send(src_, ans);

		write_fmt(Log::Process, "[internal_login_req_job::process()] player_no=%lld, session_id=%d",
			player_no, new_session_id);

		return true;
	}
}