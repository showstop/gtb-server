#ifndef __GTB_XNET_MORNITOR_HANDLER__
#define __GTB_XNET_MORNITOR_HANDLER__

#include "xNet_message_handler_itf.h"
#include <protocol/internal_resource_report.dc.h>

namespace protocol
{

	class monitor_data_req_job : public xNet_message_handler_itf
	{
	public:
		monitor_data_req_job(xNet::socket* sock, const xNet::address& src, StreamPtr& msg)
			: xNet_message_handler_itf(sock, src, msg) {}
		virtual ~monitor_data_req_job() {}

		virtual bool process();
	};



}

#endif