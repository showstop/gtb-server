#ifndef __GTB_GC_DAILY_MISSION_HANDLER__
#define __GTB_GC_DAILY_MISSION_HANDLER__

#include <ServerBase/message_executor.h>
#include <protocol/daily_mission.dc.h>

namespace protocol
{
	class daily_mission_list_req_job : public message_handler_itf
	{
	public:
		daily_mission_list_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~daily_mission_list_req_job() {}

		virtual bool process();
	};

	class daily_mission_receive_reward_req_job : public message_handler_itf
	{
	public:
		daily_mission_receive_reward_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~daily_mission_receive_reward_req_job() {}

		virtual bool process();
	};

}

#endif