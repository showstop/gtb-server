#ifndef __GTB_GC_DEV_HANDLER__
#define __GTB_GC_DEV_HANDLER__

#include <ServerBase/message_executor.h>
#include <protocol/dev_test.dc.h>

namespace dev
{
	class put_vehicle_card_req_job : public protocol::message_handler_itf
	{
	public:
		put_vehicle_card_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~put_vehicle_card_req_job() {}

		virtual bool process();
	};

	class put_vehicle_stuff_req_job : public protocol::message_handler_itf
	{
	public:
		put_vehicle_stuff_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~put_vehicle_stuff_req_job() {}

		virtual bool process();
	};

}

#endif