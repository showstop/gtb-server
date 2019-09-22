#include "ability_registry.h"
#include <util/db_odbc.h>
#include <ServerBase/logger.h>
#include <json/json.h>
#include <common/exception.h>

namespace ability {
	
	registry::registry()
	{
		if (false == load_ability_registry())
			throw new exception_x(error::common::internal_db_error, "cannot load ability list from db.");
	}

	registry::~registry()
	{
		
	}

	registry& registry::instance()
	{
		static registry r;
		return r;
	}

	bool registry::find(int32 ability_id, ability::registry_info& info)
	{
		auto it = ability_infos_.find(ability_id);
		if (it == ability_infos_.end())	return false;

		info = it->second;
		return true;
	}

	bool registry::load_ability_registry()
	{
		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call load_ability_registry;");
		if (false == cp.prepare(query, pstmt))
		{
			write_fmt(Log::Error, "[registry::load_ability_registry()] query prepare failed.");
			return false;
		}

		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[registry::load_ability_registry()] query execute failed.(%s)", pstmt->get_error_str());
			return false;
		}

		volatile int idx = 0;
		while (pstmt->fetch())
		{
			int32 ability_id = pstmt->get_int(++idx);

			registry_info ai;
			ai.unlock_level_ = pstmt->get_int(++idx);
			ai.price_diamond_ = pstmt->get_int(++idx);
			ai.price_diamond_ = pstmt->get_int(++idx);
			ai.max_level_ = pstmt->get_int(++idx);
			ai.upgrade_gold_[2] = pstmt->get_int(++idx);
			ai.upgrade_gold_[3] = pstmt->get_int(++idx);
			ai.upgrade_gold_[4] = pstmt->get_int(++idx);
			ai.upgrade_gold_[5] = pstmt->get_int(++idx);
		}

		write_fmt(Log::Process, "[registry::load_ability_registry()] load ability registry.");
		return true;
	}


}

