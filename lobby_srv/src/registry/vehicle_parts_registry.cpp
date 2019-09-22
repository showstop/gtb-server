#include "vehicle_parts_registry.h"
#include <util/db_odbc.h>
#include <ServerBase/logger.h>
#include <json/json.h>
#include <common/exception.h>

namespace vehicle {
	namespace parts {

		registry::registry()
		{
			if (false == load_vehicle_parts_tuning_info())
				throw new exception_x(error::common::internal_db_error, "cannot load vehicle parts tuning info from db.");
		}

		registry::~registry()
		{

		}

		registry& registry::instance()
		{
			static registry r;
			return r;
		}

		bool registry::get_need_stuff_list(protocol::vehicle_parts_id parts_id, int16 parts_level, std::map<int32, int32>& need_stuff)
		{
			auto key = std::make_pair(parts_id, parts_level);

			auto it = infos_.find(key);
			if (it != infos_.end())
			{
				need_stuff = it->second;
				return true;
			}
			return false;
		}

		bool registry::load_vehicle_parts_tuning_info()
		{
			infos_.clear();

			db::connection_pool cp;
			db::prepared_statement_ptr pstmt;

			const std::string query("call load_vehicle_parts_tuning_registry;");
			if (false == cp.prepare(query, pstmt))
			{
				write_fmt(Log::Error, "[registry::load_vehicle_parts_tuning_info()] query prepare failed.");
				return false;
			}

			if (false == cp.execute(pstmt))
			{
				write_fmt(Log::Error, "[registry::load_vehicle_parts_tuning_info()] query execute failed.(%s)", pstmt->get_error_str());
				return false;
			}

			while (pstmt->fetch())
			{
				volatile int idx = 0;

				parts_key_t key;
				key.first = static_cast<protocol::vehicle_parts_id>(pstmt->get_int(++idx));
				key.second = pstmt->get_int(++idx);

				stuff_quantity_map_t val;
				auto stuff_id = pstmt->get_int(++idx);
				auto quantity = pstmt->get_int(++idx);

				auto it = infos_.find(key);
				if (it == infos_.end())
				{
					infos_.insert(std::make_pair(key, val));
				}
				else
				{
					it->second[stuff_id] = quantity;
				}
			}
			write_fmt(Log::Process, "[registry::load_vehicle_parts_tuning_info()] vehicle parts tuning load complete.");

			return true;
		}

	}
}