#include "player_dbo.h"
#include <util/db_odbc.h>
#include <util/string_util.h>
#include <ServerBase/logger.h>

namespace dbo {

	bool asset::load_asset_info(player_no_t player_no, protocol::asset_info& info)
	{
		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call load_asset_info(?);");
		if (false == cp.prepare(query, pstmt))
		{
			write_fmt(Log::Error, "[dbo::vehicle::load_asset_info] query prepare failed.");
			return false;
		}

		pstmt->set_int64(1, player_no);
		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[dbo::vehicle::load_asset_info] query execute error. (%s)", pstmt->get_error_str());
			return false;
		}

		if (true == pstmt->fetch())
		{
			volatile int idx = 0;
			info.set_gold(pstmt->get_int(++idx));
			info.set_diamond(pstmt->get_int(++idx));
			info.set_quick_ticket(pstmt->get_int(++idx));
			info.set_quick_timestamp(util::convert_time_str_to_int64(pstmt->get_string(++idx)));
			info.set_grandprix_ticket(pstmt->get_int(++idx));
			info.set_grandprix_timestamp(util::convert_time_str_to_int64(pstmt->get_string(++idx)));
		}

		write_fmt(Log::Process, "[dbo::vehicle::load_asset_info] load vehicle list. (player_no:%lld)", player_no);
		return true;
	}

	bool asset::save_asset_info(player_no_t player_no, const protocol::asset_info& info)
	{
		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call save_asset_info(?, ?, ?, ?, ?, ?, ?);");
		if (false == cp.prepare(query, pstmt))
		{
			write_fmt(Log::Error, "[dbo::player::save_asset_info] query prepare failed.");
			return false;
		}

		volatile int idx = 0;
		pstmt->set_int64(++idx, player_no);
		pstmt->set_int(++idx, info.get_gold());
		pstmt->set_int(++idx, info.get_diamond());
		pstmt->set_int(++idx, info.get_quick_ticket());
		pstmt->set_string(++idx, util::convert_time_int64_to_str(info.get_quick_timestamp()));
		pstmt->set_int(++idx, info.get_grandprix_ticket());
		pstmt->set_string(++idx, util::convert_time_int64_to_str(info.get_grandprix_timestamp()));

		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[dbo::player::save_asset_info] query execute failed..(Error:%s)", pstmt->get_error_str());
			return false;
		}
		return true;
	}

}