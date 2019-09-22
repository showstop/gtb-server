#ifndef __GTB_GC_GRANDPRIX_HANDLER__
#define __GTB_GC_GRANDPRIX_HANDLER__

#include <ServerBase/message_executor.h>
#include <protocol/grandprix.dc.h>

namespace protocol
{
	class grandprix_info_req_job : public message_handler_itf
	{
	public:
		grandprix_info_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~grandprix_info_req_job() {}

		virtual bool process();
	};

	class grandprix_rank_info_req_job : public message_handler_itf
	{
	public:
		grandprix_rank_info_req_job(const network::link_ptr_t& link, StreamPtr& msg)
			: message_handler_itf(link, msg) {}
		virtual ~grandprix_rank_info_req_job() {}

		virtual bool process();
	};

}

#endif