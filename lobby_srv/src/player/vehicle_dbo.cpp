#include "player_dbo.h"
#include "../registry/vehicle_registry.h"
#include <util/db_odbc.h>
#include <ServerBase/logger.h>
#include <json/json.h>
#include <boost/lexical_cast.hpp>

namespace dbo {

	bool json_to_vehicle_skills(const std::string& json_skills, std::vector<protocol::vehicle_skill*>& infos)
	{
		Json::Value root;
		Json::Reader reader;
		if (false == reader.parse(json_skills, root))
			return false;

		int32 count = static_cast<int>(infos.size());
		for (int i = 0; i < count; i++)
		{
			std::ostringstream os;
			os << "slot_" << i + 1;
			std::string name = os.str();

			Json::Value val = root[name];
			infos[i]->set_skill_lv(val["level"].asInt());
		}
		return true;
	}

	bool vehicle_skills_to_json(const std::vector<protocol::vehicle_skill*>& infos, std::string& json_skills)
	{
		Json::Value root;

		int count = static_cast<int>(infos.size());
		for (int i = 0; i < count; i++)
		{
			std::ostringstream os;
			os << "slot_" << i + 1;
			std::string name = os.str();

			Json::Value& val = root[name];
			val["id"] = infos[i]->get_skill_id();
			val["level"] = infos[i]->get_skill_lv();
		}

		Json::FastWriter writer;
		json_skills = writer.write(root);

		return true;
	}

	const char* PARTS_NAME[] = { "battery", "body_kit", "motor", "suspension" };
	bool json_to_vehicle_parts(const std::string& json_parts, protocol::vehicle& vehicle_info)
	{
		Json::Value root;
		Json::Reader reader;
		if (false == reader.parse(json_parts, root))
			return false;

		for (int i = 0; i < sizeof(PARTS_NAME)/sizeof(PARTS_NAME[0]); i++)
		{
			Json::Value val = root[PARTS_NAME[i]];

			auto& parts = *vehicle_info.add_parts();
			parts.set_level(val["level"].asInt());
			parts.set_exp(val["exp"].asInt());
		}
		return true;
	}

	bool vehicle_parts_to_json(const std::vector<protocol::vehicle_parts*>& infos, std::string& json_parts)
	{
		Json::Value root;

		int count = static_cast<int>(infos.size());
		for (int i = 0; i < count; i++)
		{
			Json::Value& val = root[PARTS_NAME[i]];
			val["level"] = infos[i]->get_level();
			val["exp"] = infos[i]->get_exp();
		}

		Json::FastWriter writer;
		json_parts = writer.write(root);

		return true;
	}

	bool vehicle::load_vehicle_list(player_no_t player_no, protocol::vehicle_list& infos)
	{
		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call load_vehicle_list(?);");
		if (false == cp.prepare(query, pstmt))
		{
			write_fmt(Log::Error, "[dbo::vehicle::load_vehicle_list] query prepare failed.");
			return false;
		}

		pstmt->set_int64(1, player_no);
		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[dbo::vehicle::load_vehicle_list] query execute error. (%s)", pstmt->get_error_str());
			return false;
		}

		while (pstmt->fetch())
		{
			volatile int idx = 0;

			auto& vi = *infos.add_infos();
			auto vehicle_no = pstmt->get_int(++idx);
			if (false == ::vehicle::registry::instance().find(vehicle_no, vi))
			{
				write_fmt(Log::Error, "[dbo::vehicle::load_vehicle_list] NOT exist vehicle_no.. (vehicle_no:%d, player_no:%lld)",
					vehicle_no, player_no);
				continue;
			}

			vi.set_level(static_cast<protocol::vehicle_level>(pstmt->get_int(++idx)));
			vi.set_hold_card(pstmt->get_int(++idx));

			auto json_skills = pstmt->get_string(++idx);
			//char buff[1024] = { 0, };
			//pstmt->get_blob(++idx, buff, 1024);
			//std::string json_skills(buff);
			if (false == json_to_vehicle_skills(json_skills, *vi.get_mutable_skills()))
			{
				write_fmt(Log::Error, "[dbo::vehicle::load_vehicle_list] invalid json-format.. (col:skills, vehicle_no:%d, player_no:%lld)",
					vehicle_no, player_no);
				continue;
			}

			auto json_parts = pstmt->get_string(++idx);
			//pstmt->get_blob(++idx, buff, 1024);
			//std::string json_parts(buff);
			if(false == json_to_vehicle_parts(json_parts, vi))
			{
				write_fmt(Log::Error, "[dbo::vehicle::load_vehicle_list] invalid json-format.. (col:parts, vehicle_no:%d, player_no:%lld)",
					vehicle_no, player_no);
				continue;
			}
		}

		write_fmt(Log::Process, "[dbo::vehicle::load_vehicle_list] load vehicle list. (player_no:%lld)", player_no);
		return true;
	}

	bool vehicle::save_vehicle_info(player_no_t player_no, const protocol::vehicle& info)
	{
		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call save_vehicle_info(?, ?, ?, ?, ?, ?);");
		if (false == cp.prepare(query, pstmt))
		{
			write_fmt(Log::Error, "[dbo::vehicle::save_vehicle_info] query prepare failed.");
			return false;
		}

		volatile int idx = 0;
		pstmt->set_int64(++idx, player_no);
		pstmt->set_int(++idx, info.get_vehicle_no());
		pstmt->set_int(++idx, info.get_level());
		pstmt->set_int(++idx, info.get_hold_card());

		std::string json_skills, json_parts;
		vehicle_skills_to_json(info.get_skills(), json_skills);
		vehicle_parts_to_json(info.get_parts(), json_parts);
		pstmt->set_string(++idx, json_skills);
		pstmt->set_string(++idx, json_parts);

		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[dbo::vehicle::save_vehicle_info] query execute error. (%s)", pstmt->get_error_str());
			return false;
		}

		return true;
	}

	// static 
	bool vehicle::load_selected_vehicle(player_no_t player_no, int32& vehicle_no)
	{
		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call load_selected_vehicle_no(?);");
		if (false == cp.prepare(query, pstmt))
		{
			write_fmt(Log::Error, "[dbo::vehicle::load_selected_vehicle] query prepare failed.");
			return false;
		}

		pstmt->set_int64(1, player_no);
		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[dbo::vehicle::load_selected_vehicle] query execute error. (%s)", pstmt->get_error_str());
			return false;
		}

		if (pstmt->fetch())
			vehicle_no = pstmt->get_int(1);

		return true;
	}

	bool vehicle::load_selected_vehicle(player_no_t player_no, protocol::vehicle& info)
	{
		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call load_selected_vehicle_info(?);");
		if (false == cp.prepare(query, pstmt))
		{
			write_fmt(Log::Error, "[dbo::vehicle::load_selected_vehicle] query prepare failed.");
			return false;
		}

		pstmt->set_int64(1, player_no);
		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[dbo::vehicle::load_selected_vehicle] query execute error. (%s)", pstmt->get_error_str());
			return false;
		}

		if (pstmt->fetch())
		{
			volatile int idx = 0;

			auto vehicle_no = pstmt->get_int(++idx);
			if (false == ::vehicle::registry::instance().find(vehicle_no, info))
			{
				write_fmt(Log::Error, "[dbo::vehicle::load_selected_vehicle] NOT exist vehicle_no.. (vehicle_no:%d, player_no:%lld)",
					vehicle_no, player_no);
				return false;
			}

			info.set_level(static_cast<protocol::vehicle_level>(pstmt->get_int(++idx)));
			info.set_hold_card(pstmt->get_int(++idx));

			auto json_skills = pstmt->get_string(++idx);
			if (false == json_to_vehicle_skills(json_skills, *info.get_mutable_skills()))
			{
				write_fmt(Log::Error, "[dbo::vehicle::load_selected_vehicle] invalid json-format.. (col:skills, vehicle_no:%d, player_no:%lld)",
					info.get_vehicle_no(), player_no);
				return false;
			}

			auto json_parts = pstmt->get_string(++idx);
			if (false == json_to_vehicle_parts(json_parts, info))
			{
				write_fmt(Log::Error, "[dbo::vehicle::load_selected_vehicle] invalid json-format.. (col:parts, vehicle_no:%d, player_no:%lld)",
					info.get_vehicle_no(), player_no);
				return false;
			}
		}

		return true;
	}

	bool vehicle::save_selected_vehicle(player_no_t player_no, int32 vehicle_no)
	{
		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call save_selected_vehicle_no(?, ?);");
		if (false == cp.prepare(query, pstmt))
		{
			write_fmt(Log::Error, "[dbo::vehicle::save_selected_vehicle] query prepare failed.");
			return false;
		}

		pstmt->set_int64(1, player_no);
		pstmt->set_int(2, vehicle_no);

		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[dbo::vehicle::save_selected_vehicle] query execute error. (%s)", pstmt->get_error_str());
			return false;
		}

		return true;
	}

	bool vehicle::load_vehicle_stuff_info(player_no_t player_no, protocol::vehicle_stuff& info)
	{
		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call load_vehicle_stuff_info(?);");
		if (false == cp.prepare(query, pstmt))
		{
			write_fmt(Log::Error, "[dbo::vehicle::load_vehicle_stuff_info] query prepare failed.");
			return false;
		}

		pstmt->set_int64(1, player_no);
		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[dbo::vehicle::load_vehicle_stuff_info] query execute error. (%s)", pstmt->get_error_str());
			return false;
		}

		auto& stuff_map = *info.get_mutable_stuff_info();
		while (pstmt->fetch())
		{
			auto stuff_id = pstmt->get_int(1);
			auto quantity = pstmt->get_int(2);

			stuff_map[stuff_id] = quantity;
		}

		return true;
	}

	bool vehicle::save_vehicle_stuff_info(player_no_t player_no, int32 stuff_id, int32 quantity)
	{
		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call save_vehicle_stuff_info(?, ?, ?);");
		if (false == cp.prepare(query, pstmt))
		{
			write_fmt(Log::Error, "[dbo::vehicle::save_vehicle_stuff_info] query prepare failed.");
			return false;
		}

		volatile int idx = 0;
		pstmt->set_int64(++idx, player_no);
		pstmt->set_int(++idx, stuff_id);
		pstmt->set_int(++idx, quantity);

		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[dbo::vehicle::save_vehicle_stuff_info] query execute error. (%s)", pstmt->get_error_str());
			return false;
		}

		return true;
	}

}