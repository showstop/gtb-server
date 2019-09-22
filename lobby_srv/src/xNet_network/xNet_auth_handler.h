#ifndef __GTB_XNET_AUTH_HANDLER__
#define __GTB_XNET_AUTH_HANDLER__

#include "xNet_message_handler_itf.h"
#include <protocol/internal_as_ls.dc.h>

namespace protocol
{

	class internal_login_req_job : public xNet_message_handler_itf
	{
	public:
		internal_login_req_job(xNet::socket* sock, const xNet::address& src, StreamPtr& msg)
			: xNet_message_handler_itf(sock, src, msg) {}
		virtual ~internal_login_req_job() {}

		virtual bool process();
	};



}

#endif