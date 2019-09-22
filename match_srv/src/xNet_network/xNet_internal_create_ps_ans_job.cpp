#include "xNet_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../match/quick_match_pool.h"
#include <xNetConnector.h>

namespace protocol {

	bool internal_create_ps_ans_job::process()
	{
		internal_create_ps_ans ans;
		if (!ans.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[internal_create_ps_ans_job::process()] internal_create_ps_ans deserialize failed.");
			return false;
		}

		switch (ans.get_mode())
		{
		case protocol::GameMode_QUICK:
		{
			match::quick_pool::instance().match_complete_notify_to_players(ans.get_room_no(), *ans.get_ps_addr());
			break;
		}
		case protocol::GameMode_GRANDPRIX:
		{
			break;
		}
		default:
			write_fmt(Log::Error, "[internal_create_ps_ans_job::process()] invalid game mode..(mode:%d, room_no:%d, ps_addr:%s:%d)",
				ans.get_mode(), ans.get_room_no(), ans.get_ps_addr()->get_domain().c_str(), ans.get_ps_addr()->get_port());
			break;
		}

		write_fmt(Log::Process, "[internal_create_ps_ans_job::process()] create ps ans..(mode:%d, room_no:%d, ps_addr:%s:%d)",
			ans.get_mode(), ans.get_room_no(), ans.get_ps_addr()->get_domain().c_str(), ans.get_ps_addr()->get_port());

		return true;
	}
}