#include "xNet_monitor_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../player/repository.h"
#include "../logic/lobby_server.h"

namespace protocol {

	bool monitor_data_req_job::process()
	{
		monitor_data_req req;
		if (!req.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[monitor_data_req_job::process()] monitor_data_req deserialize failed.");
			return false;
		}

		monitor_data_ans ans;
		ans.set_result(error::common::success);

		lobby::server::instance().get_game_resource_data(*ans.get_mutable_data());
		
		sock_->send(src_, ans);

		write_fmt(Log::Process, "[monitor_data_req_job::process()] monitor_data_ans (SERVER:%s)",
			ans.get_data()->get_machine_name().c_str());
		return true;
	}
}