#ifndef __GTB_PS_PROTOCOL_HANDLER__
#define __GTB_PS_PROTOCOL_HANDLER__

#include <ServerBase/message_executor.h>
#include <protocol/internal_ls_ps.dc.h>

namespace protocol {

	class internal_register_ps_req_job : public message_handler_itf
	{
	public:
		internal_register_ps_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~internal_register_ps_req_job() {}

		virtual bool process();
	};

	class internal_start_game_ans_job : public message_handler_itf
	{
	public:
		internal_start_game_ans_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~internal_start_game_ans_job() {}

		virtual bool process();
	};

	class internal_end_game_req_job : public message_handler_itf
	{
	public:
		internal_end_game_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~internal_end_game_req_job() {}

		virtual bool process();
	};

	class internal_player_end_game_report_req_job : public message_handler_itf
	{
	public:
		internal_player_end_game_report_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~internal_player_end_game_report_req_job() {}

		virtual bool process();
	};

}

#endif