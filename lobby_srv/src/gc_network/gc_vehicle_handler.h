#ifndef __GTB_GC_VEHICLE_HANDLER__
#define __GTB_GC_VEHICLE_HANDLER__

#include <ServerBase/message_executor.h>
#include <protocol/vehicle.dc.h>

namespace protocol
{
	class vehicle_list_req_job : public message_handler_itf
	{
	public:
		vehicle_list_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~vehicle_list_req_job() {}

		virtual bool process();
	};

	class vehicle_select_req_job : public message_handler_itf
	{
	public:
		vehicle_select_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~vehicle_select_req_job() {}

		virtual bool process();
	};

	class vehicle_upgrade_req_job : public message_handler_itf
	{
	public:
		vehicle_upgrade_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~vehicle_upgrade_req_job() {}

		virtual bool process();
	};

	class vehicle_parts_tuning_req_job : public message_handler_itf
	{
	public:
		vehicle_parts_tuning_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~vehicle_parts_tuning_req_job() {}

		virtual bool process();
	};

}

#endif