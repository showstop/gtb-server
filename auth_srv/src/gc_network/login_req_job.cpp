#include "gc_auth_handler.h"
#include <ServerBase/logger.h>

namespace protocol {

	bool login_req_job::process()
	{
		login_req req;
		if (!req.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[login_req_job::process()] login_req deserialize failed.");
			return false;
		}

		// todo : send to gameserver via xNet by anycast
		


		return true;
	}

}