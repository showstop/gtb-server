#ifndef __GTB_GC_ABILITIY_HANDLER__
#define __GTB_GC_ABILITIY_HANDLER__

#include <ServerBase/message_executor.h>
#include <protocol/ability.dc.h>

namespace protocol
{
	class ability_list_req_job : public message_handler_itf
	{
	public:
		ability_list_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~ability_list_req_job() {}

		virtual bool process();
	};

	class ability_slot_open_req_job : public message_handler_itf
	{
	public:
		ability_slot_open_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~ability_slot_open_req_job() {}

		virtual bool process();
	};

	class ability_equip_req_job : public message_handler_itf
	{
	public:
		ability_equip_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~ability_equip_req_job() {}

		virtual bool process();
	};

	class ability_acquire_req_job : public message_handler_itf
	{
	public:
		ability_acquire_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~ability_acquire_req_job() {}

		virtual bool process();
	};

}

#endif