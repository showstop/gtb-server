#include "vehicle_registry.h"
#include <util/db_odbc.h>
#include <ServerBase/logger.h>
#include <json/json.h>
#include <common/exception.h>

namespace vehicle {

	registry::registry()
	{
		if (false == load_vehicle_info())
			throw new exception_x(error::common::internal_db_error, "cannot load vehicle info from db.");
	}

	registry::~registry()
	{

	}

	// static 
	registry& registry::instance()
	{
		static registry r;
		return r;
	}

	bool registry::find(int32 vehicle_no, protocol::vehicle& info)
	{
		auto it = std::find_if(vehicles_.get_mutable_infos()->begin(), 
			vehicles_.get_mutable_infos()->end(),
			[vehicle_no](const protocol::vehicle* info) -> bool
		{
			return vehicle_no == info->get_vehicle_no();
		});

		if (it == vehicles_.get_mutable_infos()->end())
			return false;

		info = *(*it);
		return true;
	}

	bool registry::load_vehicle_info()
	{
		vehicles_.clear();

		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call load_vehicle_registry;");
		if (false == cp.prepare(query, pstmt))
		{
			write_fmt(Log::Error, "[registry::load_vehicle_info()] query prepare failed.");
			return false;
		}

		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[registry::load_vehicle_info()] query execute failed.(%s)", pstmt->get_error_str());
			return false;
		}

		while (pstmt->fetch())
		{
			volatile int idx = 0;

			protocol::vehicle info;
			info.set_vehicle_no(pstmt->get_int(++idx));
			info.set_level(protocol::vehicle_level_LOCKED);
			
			auto skill_01 = pstmt->get_int(++idx);
			auto skill_02 = pstmt->get_int(++idx);
			auto skill_03 = pstmt->get_int(++idx);

			if (skill_01)	info.add_skills()->set_skill_id(skill_01);
			if (skill_02)	info.add_skills()->set_skill_id(skill_02);
			if (skill_03)	info.add_skills()->set_skill_id(skill_03);

			auto& base_stat = *info.get_mutable_stat();
			base_stat.set_acc(pstmt->get_int(++idx));
			base_stat.set_spd(pstmt->get_int(++idx));
			base_stat.set_pow(pstmt->get_int(++idx));
			base_stat.set_hp(pstmt->get_int(++idx));

			for (auto id = protocol::vehicle_parts_id_BATTERY; 
				id != protocol::vehicle_parts_id_SUSPENSION; 
				id=(protocol::vehicle_parts_id)((int)id+1))
			{
				auto& new_parts = *info.add_parts();
				new_parts.set_parts_id(id);
				new_parts.set_level(1);
			}

			*vehicles_.add_infos() = info;
		}

		write_fmt(Log::Process, "[registry::load_vehicle_info()] load vehicles(count:%d) success.", (int)vehicles_.get_infos().size());
		return true;
	}



}