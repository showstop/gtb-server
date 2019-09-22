#include "xNet_match_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../player/repository.h"
#include "../logic/lobby_server.h"
#include <protocol/lobby.dc.h>

namespace protocol {

	bool internal_unregister_player_ans_job::process()
	{
		internal_unregister_player_ans ans;
		if (!ans.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[internal_unregister_player_ans_job::process()] internal_unregister_player_ans deserialize failed.");
			return false;
		}

		match_stop_ans ans_to_gc;
		ans_to_gc.set_result(ans.get_result());

		auto player_obj = player::repository::instance().find(ans.get_dest_player_no());
		if (nullptr == player_obj)
		{
			write_fmt(Log::Error, "[internal_unregister_player_ans_job::process()] cannot find player-obj(player_no:%lld).", ans.get_dest_player_no());
			return false;
		}

		player_obj->get_client_link()->send(ans_to_gc);

		write_fmt(Log::Process, "[internal_unregister_player_ans_job::process()] player_no:%lld, result:%d",
			ans.get_dest_player_no(), ans.get_result());

		return true;
	}
}