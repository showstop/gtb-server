#ifndef __GTB_GC_LOBBY_HANDLER__
#define __GTB_GC_LOBBY_HANDLER__

#include <ServerBase/message_executor.h>
#include <protocol/lobby.dc.h>

namespace protocol
{
	class connect_lobby_req_job : public message_handler_itf
	{
	public:
		connect_lobby_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~connect_lobby_req_job() {}

		virtual bool process();
	};

	class tutorial_progress_update_req_job : public message_handler_itf
	{
	public:
		tutorial_progress_update_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~tutorial_progress_update_req_job() {}

		virtual bool process();
	};

	class first_vehicle_select_req_job : public message_handler_itf
	{
	public:
		first_vehicle_select_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~first_vehicle_select_req_job() {}

		virtual bool process();
	};

	class asset_info_req_job : public message_handler_itf
	{
	public:
		asset_info_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~asset_info_req_job() {}

		virtual bool process();
	};

	class match_item_buy_req_job : public message_handler_itf
	{
	public:
		match_item_buy_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~match_item_buy_req_job() {}

		virtual bool process();
	};

	class match_info_req_job : public message_handler_itf
	{
	public:
		match_info_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~match_info_req_job() {}

		virtual bool process();
	};

	class match_start_req_job : public message_handler_itf
	{
	public:
		match_start_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~match_start_req_job() {}

		virtual bool process();
	};

	class match_stop_req_job : public message_handler_itf
	{
	public:
		match_stop_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~match_stop_req_job() {}

		virtual bool process();
	};

}

#endif