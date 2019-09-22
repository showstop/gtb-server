#include "player_dbo.h"
#include <util/db_odbc.h>
#include <ServerBase/logger.h>
#include <util/string_util.h>

namespace dbo {

	bool player::load_player_profile_info(player_no_t player_no, protocol::player_profile_info& info)
	{
		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call load_player_profile_info(?);");
		if (false == cp.prepare(query, pstmt))
		{
			write_fmt(Log::Error, "[dbo::player::load_player_profile_info] query prepare failed.");
			return false;
		}

		pstmt->set_int64(1, player_no);
		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[dbo::player::load_player_profile_info] query execute failed..(Error:%s)", pstmt->get_error_str());
			return false;
		}

		if (false == pstmt->fetch())
		{
			write_fmt(Log::Error, "[dbo::player::load_player_profile_info] no data..(player_no:%lld)", player_no);
			return false;
		}
		volatile int idx = 0;

		info.set_player_no(player_no);
		info.set_game_nick(pstmt->get_wstring(++idx));
		info.set_nation_code(pstmt->get_int(++idx));
		info.set_player_level(pstmt->get_int(++idx));
		info.set_exp(pstmt->get_int(++idx));
		info.set_trophy(pstmt->get_int(++idx));

		return true;
	}

	bool player::save_player_profile_info(const protocol::player_profile_info& info)
	{
		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call save_player_profile_info(?, ?, ?, ?, ?, ?);");
		if (false == cp.prepare(query, pstmt))
		{
			write_fmt(Log::Error, "[dbo::player::save_player_profile_info] query prepare failed.");
			return false;
		}

		volatile int idx = 0;
		pstmt->set_int64(++idx, info.get_player_no());
		pstmt->set_wstring(++idx, util::mbs_to_wcs(info.get_game_nick()));
		pstmt->set_int(++idx, info.get_nation_code());
		pstmt->set_int(++idx, info.get_player_level());
		pstmt->set_int(++idx, info.get_exp());
		pstmt->set_int(++idx, info.get_trophy());

		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[dbo::player::save_player_profile_info] query execute failed..(Error:%s)", pstmt->get_error_str());
			return false;
		}

		return true;
	}

	bool player::save_tutorial_update_progress(player_no_t player_no, const protocol::TutorialProgress progress)
	{
		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call save_player_tutorial_progress(?, ?);");
		if (false == cp.prepare(query, pstmt))
		{
			write_fmt(Log::Error, "[dbo::player::save_player_tutorial_complete] query prepare failed.");
			return false;
		}

		volatile int idx = 0;
		pstmt->set_int64(++idx, player_no);
		pstmt->set_int(++idx, static_cast<int32>(progress));
		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[dbo::player::save_player_tutorial_complete] query execute failed..(Error:%s)", pstmt->get_error_str());
			return false;
		}

		return true;
	}

	bool player::save_first_vehicle(player_no_t player_no, int32 selected_vehicle_no)
	{
		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("update player_register_info set tutorial_reward=? where player_no=?;");
		if (false == cp.prepare(query, pstmt))
		{
			write_fmt(Log::Error, "[dbo::player::save_first_vehicle] query prepare failed.");
			return false;
		}

		volatile int idx = 0;
		pstmt->set_int(++idx, selected_vehicle_no);
		pstmt->set_int64(++idx, player_no);

		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[dbo::player::save_player_tutorial_complete] query execute failed..(Error:%s)", pstmt->get_error_str());
			return false;
		}

		return true;
	}

}