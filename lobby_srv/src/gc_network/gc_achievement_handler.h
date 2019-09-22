#ifndef __GTB_GC_ACHIEVEMENT_HANDLER__
#define __GTB_GC_ACHIEVEMENT_HANDLER__

#include <ServerBase/message_executor.h>
#include <protocol/achievement.dc.h>

namespace protocol
{
	class achievement_list_req_job : public message_handler_itf
	{
	public:
		achievement_list_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~achievement_list_req_job() {}

		virtual bool process();
	};

	class achievement_receive_reward_req_job : public message_handler_itf
	{
	public:
		achievement_receive_reward_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~achievement_receive_reward_req_job() {}

		virtual bool process();
	};
}

#endif