#ifndef __GTB_GC_AUTH_HANDLER__
#define __GTB_GC_AUTH_HANDLER__

#include <ServerBase/message_executor.h>
#include <protocol/auth.dc.h>

namespace protocol
{
	class session_key_req_job : public message_handler_itf
	{
	public:
		session_key_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~session_key_req_job() {}

		virtual bool process();
	};

	class login_req_job : public message_handler_itf
	{
	public:
		login_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~login_req_job() {}

		virtual bool process();
	};

	class logout_req_job : public message_handler_itf
	{
	public:
		logout_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~logout_req_job() {}

		virtual bool process();
	};

	class heartbeat_job : public message_handler_itf
	{
	public:
		heartbeat_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~heartbeat_job() {}

		virtual bool process();
	};

	class quit_req_job : public message_handler_itf
	{
	public:
		quit_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~quit_req_job() {}

		virtual bool process();
	};



}

#endif