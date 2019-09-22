#include "xNet_lobby_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include <protocol/auth.dc.h>
#include "../gc_network/gc_link_table.h"
#include <util/db_odbc.h>

namespace protocol {

	namespace dbo {

		bool check_if_tutorial_complete(player_no_t player_no, protocol::TutorialProgress& progress)
		{
			db::connection_pool cp;
			db::prepared_statement_ptr pstmt;

			const std::string query("call load_player_tutorial_progress(?);");
			if (false == cp.prepare(query, pstmt))
			{
				write_fmt(Log::Error, "[internal_login_ans_job::check_if_tutorial_complete] prepare failed.");
				return false;
			}

			volatile int idx = 0;
			pstmt->set_int64(++idx, player_no);

			if (false == cp.execute(pstmt))
			{
				write_fmt(Log::Error, "[internal_login_ans_job::check_if_tutorial_complete] execute failed...(%s), (player_no:%lld)",
					pstmt->get_error_str(), player_no);
				return false;
			}

			if (false == pstmt->fetch())
				return false;

			progress = static_cast<protocol::TutorialProgress>(pstmt->get_int(1));
			return true;
		}

	}

	bool internal_login_ans_job::process()
	{
		internal_login_ans ans;
		if (!ans.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[internal_login_ans_job::process()] internal_login_ans deserialize failed.");
			return false;
		}

		login_ans ans_to_gc;
		ans_to_gc.set_result(ans.get_result());
		ans_to_gc.set_session_id(ans.get_session_id());
		ans_to_gc.set_server_timestamp(::time(0));
		*ans_to_gc.get_mutable_assigned_ls_addr() = *ans.get_mutable_ls_addr();

		auto player_no = ans.get_player_no();
		protocol::TutorialProgress tutorial_progress;
		dbo::check_if_tutorial_complete(player_no, tutorial_progress);
		ans_to_gc.set_progress(tutorial_progress);

		if (ans.get_result() != error::common::success)
		{
			write_fmt(Log::Process, "[internal_login_ans_job::process()] lobby server send to error(%d) (player_no:%lld)", 
				ans.get_result(), player_no);

			//todo retry another lobby server.
			return true;
		}

		network::link_ptr_t gc_link;
		if (false == gc::link_table::instance().find(player_no, gc_link))
		{
			write_fmt(Log::Process, "[internal_login_ans_job::process()] cannot find gc-link. (player_no:%lld)", player_no);
			return true;
		}

		gc_link->send(ans_to_gc);
		write_fmt(Log::Process, "[internal_login_ans_job::process()] result=%d", ans.get_result());

		return true;
	}
}