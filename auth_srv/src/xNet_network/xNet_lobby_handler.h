#ifndef __GTB_XNET_LOBBY_HANDLER__
#define __GTB_XNET_LOBBY_HANDLER__

#include "xNet_message_handler_itf.h"
#include <protocol/internal_as_ls.dc.h>

namespace protocol
{

	class internal_login_ans_job : public xNet_message_handler_itf
	{
	public:
		internal_login_ans_job(xNet::socket* sock, const xNet::address& src, StreamPtr& msg)
			: xNet_message_handler_itf(sock, src, msg) {}
		virtual ~internal_login_ans_job() {}

		virtual bool process();
	};



}

#endif