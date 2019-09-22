#include "player_dbo.h"
#include <util/db_odbc.h>
#include <util/string_util.h>
#include <ServerBase/logger.h>
#include "../registry/daily_mission_registry.h"

namespace dbo {

	bool daily_mission::load_daily_mission_list(player_no_t player_no, protocol::daily_mission_list& infos)
	{
		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call load_daily_mission_list(?);");
		if (false == cp.prepare(query, pstmt))
		{
			write_fmt(Log::Error, "[dbo::daily_mission::load_daily_mission_list] query prepare failed.");
			return false;
		}

		pstmt->set_int64(1, player_no);
		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[dbo::daily_mission::load_daily_mission_list] query execute error. (%s)", pstmt->get_error_str());
			return false;
		}

		while (pstmt->fetch())
		{
			volatile int idx = 0;

			auto& info = *infos.add_infos();
			info.set_mission_id(pstmt->get_int(++idx));

			if (false == ::daily_mission::registry::instance().find(info.get_mission_id(), info))
				continue;

			info.set_progress(pstmt->get_int(++idx));
			info.set_receive_reward(pstmt->get_int(++idx) == 1);
		}

		write_fmt(Log::Process, "[dbo::daily_mission::load_daily_mission_list] load_daily_mission_list. (player_no:%lld)", player_no);
		return true;
	}

	bool daily_mission::save_daily_mission_info(player_no_t player_no, const protocol::daily_mission_info& info)
	{
		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call save_daily_mission_info(?, ?, ?, ?);");
		if (false == cp.prepare(query, pstmt))
		{
			write_fmt(Log::Error, "[dbo::daily_mission::save_daily_mission_info] query prepare failed.");
			return false;
		}

		volatile int idx = 0;
		pstmt->set_int64(++idx, player_no);
		pstmt->set_int(++idx, info.get_mission_id());
		pstmt->set_int(++idx, info.get_progress());
		pstmt->set_int(++idx, info.get_receive_reward() ? 1 : 0);

		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[dbo::daily_mission::save_daily_mission_info] query execute failed..(Error:%s)", pstmt->get_error_str());
			return false;
		}

		write_fmt(Log::Process, "[dbo::daily_mission::save_daily_mission_info] save_achievement_info. (player_no:%lld)", player_no);
		return true;
	}

}