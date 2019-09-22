#include "player_dbo.h"
#include <util/db_odbc.h>
#include <util/string_util.h>
#include <ServerBase/logger.h>

namespace dbo {

	bool ability::load_ability_list(player_no_t player_no, protocol::ability_list& infos)
	{
		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call load_ability_list(?);");
		if (false == cp.prepare(query, pstmt))
		{
			write_fmt(Log::Error, "[dbo::ability::load_ability_list] query prepare failed.");
			return false;
		}

		pstmt->set_int64(1, player_no);
		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[dbo::ability::load_ability_list] query execute error. (%s)", pstmt->get_error_str());
			return false;
		}

		while (pstmt->fetch())
		{
			auto& info = *infos.add_infos();

			info.set_ability_id(pstmt->get_int(1));
			info.set_level(pstmt->get_int(2));
		}

		write_fmt(Log::Process, "[dbo::ability::load_ability_list] load ability list. (player_no:%lld)", player_no);
		return true;
	}

	bool ability::load_ability_slot_info(player_no_t player_no, protocol::ability_slot& info)
	{
		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call load_ability_slot_info(?);");
		if (false == cp.prepare(query, pstmt))
		{
			write_fmt(Log::Error, "[dbo::ability::load_ability_slot_info] query prepare failed.");
			return false;
		}

		pstmt->set_int64(1, player_no);
		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[dbo::ability::load_ability_slot_info] query execute error. (%s)", pstmt->get_error_str());
			return false;
		}

		if (pstmt->fetch())
		{
			volatile int idx = 0;
			info.insert_slots(protocol::ability_slot_no_SLOT_1, pstmt->get_int(++idx));
			info.insert_slots(protocol::ability_slot_no_SLOT_2, pstmt->get_int(++idx));
			info.insert_slots(protocol::ability_slot_no_SLOT_3, pstmt->get_int(++idx));
		}

		write_fmt(Log::Process, "[dbo::ability::load_ability_slot_info] load ability slot. (player_no:%lld)", player_no);
		return true;
	}


	bool ability::save_ability_info(player_no_t player_no, const protocol::ability& info)
	{
		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call save_ability_info(?, ?, ?);");
		if (false == cp.prepare(query, pstmt))
		{
			write_fmt(Log::Error, "[dbo::ability::save_ability_info] query prepare failed.");
			return false;
		}

		volatile int idx = 0;
		pstmt->set_int64(++idx, player_no);
		pstmt->set_int(++idx, info.get_ability_id());
		pstmt->set_int(++idx, info.get_level());

		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[dbo::ability::save_ability_info] query execute failed..(Error:%s)", pstmt->get_error_str());
			return false;
		}
		return true;
	}

	bool ability::save_ability_slot_info(player_no_t player_no, const protocol::ability_slot& info)
	{
		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call save_ability_slot_info(?, ?, ?, ?);");
		if (false == cp.prepare(query, pstmt))
		{
			write_fmt(Log::Error, "[dbo::ability::save_ability_slot_info] query prepare failed.");
			return false;
		}

		auto& slots = *const_cast<protocol::ability_slot*>(&info)->get_mutable_slots();

		volatile int idx = 0;
		pstmt->set_int64(++idx, player_no);
		pstmt->set_int(++idx, slots[protocol::ability_slot_no_SLOT_1]);
		pstmt->set_int(++idx, slots[protocol::ability_slot_no_SLOT_2]);
		pstmt->set_int(++idx, slots[protocol::ability_slot_no_SLOT_3]);

		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[dbo::ability::save_ability_slot_info] query execute failed..(Error:%s)", pstmt->get_error_str());
			return false;
		}
		return true;
	}

}