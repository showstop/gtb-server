#ifndef __GTB_GC_PLAYER_HANDLER__
#define __GTB_GC_PLAYER_HANDLER__

#include <ServerBase/message_executor.h>
#include <protocol/player.dc.h>

namespace protocol
{
	class player_profile_info_req_job : public message_handler_itf
	{
	public:
		player_profile_info_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~player_profile_info_req_job() {}

		virtual bool process();
	};

	class update_player_profile_info_req_job : public message_handler_itf
	{
	public:
		update_player_profile_info_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~update_player_profile_info_req_job() {}

		virtual bool process();
	};

}

#endif