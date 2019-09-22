#ifndef __XNET_MESSAGE_HANDLER_ITF__
#define __XNET_MESSAGE_HANDLER_ITF__

#include <xNetConnector.h>

namespace protocol {

	class xNet_message_handler_itf
	{
	public:
		xNet_message_handler_itf(xNet::socket* sock, const xNet::address& src, StreamPtr& msg)
			: sock_(sock), src_(src), msg_(msg) {}

		virtual ~xNet_message_handler_itf() {}

		virtual bool process() = 0;
		
	protected:
		xNet::socket* sock_;
		const xNet::address src_;
		StreamPtr msg_;
	};


}


#endif