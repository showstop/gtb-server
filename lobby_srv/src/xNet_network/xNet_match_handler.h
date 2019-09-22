#ifndef __GTB_XNET_MATCH_HANDLER__
#define __GTB_XNET_MATCH_HANDLER__

#include "xNet_message_handler_itf.h"
#include <protocol/internal_ls_mms.dc.h>

namespace protocol
{

	class internal_register_player_ans_job : public xNet_message_handler_itf
	{
	public:
		internal_register_player_ans_job(xNet::socket* sock, const xNet::address& src, StreamPtr& msg)
			: xNet_message_handler_itf(sock, src, msg) {}
		virtual ~internal_register_player_ans_job() {}

		virtual bool process();
	};

	class internal_unregister_player_ans_job : public xNet_message_handler_itf
	{
	public:
		internal_unregister_player_ans_job(xNet::socket* sock, const xNet::address& src, StreamPtr& msg)
			: xNet_message_handler_itf(sock, src, msg) {}
		virtual ~internal_unregister_player_ans_job() {}

		virtual bool process();
	};

	class internal_create_ps_req_job : public xNet_message_handler_itf
	{
	public:
		internal_create_ps_req_job(xNet::socket* sock, const xNet::address& src, StreamPtr& msg)
			: xNet_message_handler_itf(sock, src, msg) {}
		virtual ~internal_create_ps_req_job() {}

		virtual bool process();
	};

	class internal_match_complete_notify_job : public xNet_message_handler_itf
	{
	public:
		internal_match_complete_notify_job(xNet::socket* sock, const xNet::address& src, StreamPtr& msg)
			: xNet_message_handler_itf(sock, src, msg) {}
		virtual ~internal_match_complete_notify_job() {}

		virtual bool process();
	};

}

#endif