#include "player_dbo.h"
#include <util/db_odbc.h>
#include <util/string_util.h>
#include <ServerBase/logger.h>

namespace dbo {

	bool grandprix::load_grandprix_info(player_no_t player_no, protocol::grandprix_info& info)
	{
		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call load_grandprix_info(?);");
		if (false == cp.prepare(query, pstmt))
		{
			write_fmt(Log::Error, "[dbo::grandprix::load_grandprix_info] query prepare failed.");
			return false;
		}

		pstmt->set_int64(1, player_no);
		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[dbo::grandprix::load_grandprix_info] query execute error. (%s)", pstmt->get_error_str());
			return false;
		}

		if (pstmt->fetch())
		{
			info.set_gp_point(pstmt->get_int(1));
			info.set_league(static_cast<protocol::grandprix_league>(pstmt->get_int(2)));
		}

		write_fmt(Log::Process, "[dbo::grandprix::load_grandprix_info] load grandprix info. (player_no:%lld)", player_no);
		return true;
	}

	bool grandprix::save_grandprix_info(player_no_t player_no, const protocol::grandprix_info& info)
	{
		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call save_grandprix_info(?, ?, ?);");
		if (false == cp.prepare(query, pstmt))
		{
			write_fmt(Log::Error, "[dbo::grandprix::save_grandprix_info] query prepare failed.");
			return false;
		}

		volatile int idx = 0;
		pstmt->set_int64(++idx, player_no);
		pstmt->set_int(++idx, info.get_gp_point());
		pstmt->set_int(++idx, info.get_league());
		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[dbo::grandprix::save_grandprix_info] query execute error. (%s)", pstmt->get_error_str());
			return false;
		}

		write_fmt(Log::Process, "[dbo::ability::save_grandprix_info] save grandprix_info. (player_no:%lld)", player_no);
		return true;
	}

	
}