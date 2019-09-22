#include "gc_auth_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>

#include "../env/config.h"
#include "../logic/auth_processor.h"

namespace protocol {

	bool login_req_job::process()
	{
		login_req req;
		if (!req.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[login_req_job::process()] login_req deserialize failed.");
			return false;
		}

		write_fmt(Log::Debug, "[login_req_job::process()] login process  (access_token:%s, client_address:%s)",
			req.get_acc_token().c_str(), ::helper::get_remote_address(link_).c_str());

		if (false == link_->is_set_session_key())
		{
			// something wrong....
			write_fmt(Log::Error, "[login_req_job::process()] invalid request - session key is not SET!! (%s)", ::helper::get_remote_address(link_).c_str());
			link_->close();
			return true;
		}

		if (link_->get_link_id() != 0)
		{
			// something wrong....
			write_fmt(Log::Error, "[login_req_job::process()] invalid request...link info(%s)", ::helper::get_remote_address(link_).c_str());

			link_->close();
			return true;
		}

		if (req.get_acc_token().empty())
		{
			write_fmt(Log::Error, "[login_req_job::process()] the access-token is empty! (client_ip:%s)", ::helper::get_remote_address(link_).c_str());

			link_->close();
			return true;
		}

		login_ans ans;
		ans.set_result(error::common::success);

		const int16 TR_VERSION = configurator::instance().get_sys_info().server_version;
		if (req.get_version() != TR_VERSION)
		{
			write_fmt(Log::Error, "[login_req_job::process()] INVALID CLIENT-VERSION (access_token:%s, client_ip:%s)",
				req.get_acc_token().c_str(),
				::helper::get_remote_address(link_).c_str());

			ans.set_result(error::common::mismatch_version);
			return link_->send(ans);
		}

		return auth::processor::instance().add_request(req, link_);
	}

}