#ifndef __GTB_GC_ATTENDANCE_HANDLER__
#define __GTB_GC_ATTENDANCE_HANDLER__

#include <ServerBase/message_executor.h>
#include <protocol/attendance.dc.h>

namespace protocol
{
	class attendance_list_req_job : public message_handler_itf
	{
	public:
		attendance_list_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~attendance_list_req_job() {}

		virtual bool process();
	};

	class attendance_receive_reward_req_job : public message_handler_itf
	{
	public:
		attendance_receive_reward_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~attendance_receive_reward_req_job() {}

		virtual bool process();
	};
	
}

#endif