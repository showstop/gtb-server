#include "attendance_registry.h"
#include <util/db_odbc.h>
#include <ServerBase/logger.h>
#include <json/json.h>
#include <common/exception.h>

namespace attendance {

	registry::registry()
	{
		if (false == load_attendance_registry())
			throw new exception_x(error::common::internal_db_error, "cannot load attendance list from db.");
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

	bool registry::find(int32 dayseq, protocol::attendance_info& info)
	{
		auto it = std::find_if(infos_.get_mutable_infos()->begin(),
			infos_.get_mutable_infos()->end(),
			[dayseq](const protocol::attendance_info* info) -> bool
		{
			return dayseq == info->get_day_seq();
		});

		if (it == infos_.get_mutable_infos()->end())
			return false;

		info = *(*it);
		return true;
	}

	bool registry::load_attendance_registry()
	{
		infos_.clear();

		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call load_attendance_registry;");
		if (false == cp.prepare(query, pstmt))
		{
			write_fmt(Log::Error, "[registry::load_attendance_registry()] query prepare failed.");
			return false;
		}

		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[registry::load_attendance_registry()] query execute failed.(%s)", pstmt->get_error_str());
			return false;
		}

		while (pstmt->fetch())
		{
			volatile int idx = 0;

			auto& info = *infos_.add_infos();

			info.set_day_seq(pstmt->get_int(++idx));
			info.get_mutable_reward()->set_type(static_cast<protocol::RewardType>(pstmt->get_int(++idx)));
			info.get_mutable_reward()->set_specific_id(pstmt->get_int(++idx));
			info.get_mutable_reward()->set_quantity(pstmt->get_int(++idx));
		}

		write_fmt(Log::Process, "[registry::load_attendance_registry()] load attendance(count:%d) success.", (int)infos_.get_infos().size());
		return true;
	}

}
