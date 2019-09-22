#include "daily_mission_registry.h"
#include <util/db_odbc.h>
#include <ServerBase/logger.h>
#include <json/json.h>
#include <common/exception.h>

namespace daily_mission {

	registry::registry()
	{
		if (false == load_daily_mission_registry())
			throw new exception_x(error::common::internal_db_error, "cannot load daily mission list from db.");
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

	bool registry::find(int32 mission_id, protocol::daily_mission_info& info)
	{
		auto it = std::find_if(infos_.get_mutable_infos()->begin(),
			infos_.get_mutable_infos()->end(),
			[mission_id](const protocol::daily_mission_info* info) -> bool
		{
			return mission_id == info->get_mission_id();
		});

		if (it == infos_.get_mutable_infos()->end())
			return false;

		info = *(*it);
		return true;
	}

	bool registry::load_daily_mission_registry()
	{
		infos_.clear();

		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call load_daily_mission_registry;");
		if (false == cp.prepare(query, pstmt))
		{
			write_fmt(Log::Error, "[registry::load_daily_mission_registry()] query prepare failed.");
			return false;
		}

		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[registry::load_daily_mission_registry()] query execute failed.(%s)", pstmt->get_error_str());
			return false;
		}

		while (pstmt->fetch())
		{
			volatile int idx = 0;

			auto& info = *infos_.add_infos();

			info.set_mission_id(pstmt->get_int(++idx));
			info.set_data_key(static_cast<protocol::mission_data_key>(pstmt->get_int(++idx)));
			info.set_goal(pstmt->get_int(++idx));
			info.get_mutable_reward()->set_type(static_cast<protocol::RewardType>(pstmt->get_int(++idx)));
			info.get_mutable_reward()->set_specific_id(pstmt->get_int(++idx));
			info.get_mutable_reward()->set_quantity(pstmt->get_int(++idx));
		}

		write_fmt(Log::Process, "[registry::load_daily_mission_registry()] load daily mission(count:%d) success.", (int)infos_.get_infos().size());
		return true;
	}



}