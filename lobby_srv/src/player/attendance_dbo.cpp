#include "player_dbo.h"
#include <util/db_odbc.h>
#include <util/string_util.h>
#include <ServerBase/logger.h>

namespace dbo {

	bool attendance::load_attendance_list(player_no_t player_no, protocol::attendance_list& infos)
	{
		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call load_attendance_list(?);");
		if (false == cp.prepare(query, pstmt))
		{
			write_fmt(Log::Error, "[dbo::attendance::load_attendance_list] query prepare failed.");
			return false;
		}

		pstmt->set_int64(1, player_no);
		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[dbo::attendance::load_attendance_list] query execute error. (%s)", pstmt->get_error_str());
			return false;
		}

		if (true == pstmt->fetch())
		{
			volatile int idx = 0;

			auto& info = *infos.add_infos();
			info.set_day_seq(pstmt->get_int(++idx));
			info.set_complete(pstmt->get_int(++idx) == 1);
			info.set_receive_reward(pstmt->get_int(++idx) == 1);
		}

		write_fmt(Log::Process, "[dbo::attendance::load_attendance_list] load_attendance_list. (player_no:%lld)", player_no);
		return true;
	}

	bool attendance::save_attendance_info(player_no_t player_no, const protocol::attendance_info& info)
	{
		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call save_attendance_info(?, ?, ?, ?);");
		if (false == cp.prepare(query, pstmt))
		{
			write_fmt(Log::Error, "[dbo::attendance::save_attendance_info] query prepare failed.");
			return false;
		}

		volatile int idx = 0;
		pstmt->set_int64(++idx, player_no);
		pstmt->set_int(++idx, info.get_day_seq());
		pstmt->set_int(++idx, info.get_complete() ? 1 : 0);
		pstmt->set_int(++idx, info.get_receive_reward() ? 1 : 0);

		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[dbo::attendance::save_attendance_info] query execute failed..(Error:%s)", pstmt->get_error_str());
			return false;
		}
		return true;
	}

}