#ifndef __GTB_XNET_LOBBY_HANDLER__
#define __GTB_XNET_LOBBY_HANDLER__

#include "xNet_message_handler_itf.h"
#include <protocol/internal_ls_ls.dc.h>

namespace protocol
{

	class internal_player_end_game_report_notify_job : public xNet_message_handler_itf
	{
	public:
		internal_player_end_game_report_notify_job(xNet::socket* sock, const xNet::address& src, StreamPtr& msg)
			: xNet_message_handler_itf(sock, src, msg) {}
		virtual ~internal_player_end_game_report_notify_job() {}

		virtual bool process();
	};

}

#endif