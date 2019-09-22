#include "achievement_registry.h"
#include <util/db_odbc.h>
#include <ServerBase/logger.h>
#include <json/json.h>
#include <common/exception.h>

namespace achievement {

	registry::registry()
	{
		if (false == load_achievement_registry())
			throw new exception_x(error::common::internal_db_error, "cannot load achievement list from db.");
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

	bool registry::find(int32 achievement_id, protocol::achievement_info& info)
	{
		auto it = std::find_if(infos_.get_mutable_infos()->begin(),
			infos_.get_mutable_infos()->end(),
			[achievement_id](const protocol::achievement_info* info) -> bool
		{
			return achievement_id == info->get_achievement_id();
		});

		if (it == infos_.get_mutable_infos()->end())
			return false;

		info = *(*it);
		return true;
	}

	bool registry::load_achievement_registry()
	{
		infos_.clear();

		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call load_achievement_registry;");
		if (false == cp.prepare(query, pstmt))
		{
			write_fmt(Log::Error, "[registry::load_achievement_registry()] query prepare failed.");
			return false;
		}

		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[registry::load_achievement_registry()] query execute failed.(%s)", pstmt->get_error_str());
			return false;
		}

		while (pstmt->fetch())
		{
			volatile int idx = 0;

			auto& info = *infos_.add_infos();

			info.set_achievement_id(pstmt->get_int(++idx));
			info.set_record_key(static_cast<protocol::record_data_key>(pstmt->get_int(++idx)));
			info.set_goal(pstmt->get_int(++idx));
			info.get_mutable_reward()->set_type(static_cast<protocol::RewardType>(pstmt->get_int(++idx)));
			info.get_mutable_reward()->set_specific_id(pstmt->get_int(++idx));
			info.get_mutable_reward()->set_quantity(pstmt->get_int(++idx));
		}

		write_fmt(Log::Process, "[registry::load_achievement_registry()] load achievement(count:%d) success.", (int)infos_.get_infos().size());
		return true;
	}



}