#ifndef __GTB_XNET_GATEWAY__
#define __GTB_XNET_GATEWAY__

#include <boost/scoped_ptr.hpp>
#include <boost/function.hpp>
#include <xNetConnector.h>
#include <ServerBase/dispatcher.h>


namespace xNet {

	class gateway
	{
		typedef boost::function<void(xNet::socket*, const xNet::address&, StreamPtr&, void* context)> dispatcher_callback_t;
		typedef protocol::dispatcher<unsigned int, dispatcher_callback_t> dispatcher_t;
	private:
		gateway();

	public:
		virtual ~gateway();

		static gateway& instance();
		
		bool start();
		void stop();
		bool send(const xNet::address& dest, const SpringCat::Wave::object_base& msg);

	private:
		void register_handler();

		static void on_received_from_xNet(const xNet::address& src, const xNet::address& dest, SpringCat::System::StreamPtr data, void* context);

		template <typename THandler>
		static void message_dispatch(xNet::socket* sock, const xNet::address& src, StreamPtr& msg, void* context);


	private:
		xNet::socket* xNet_socket_;
		std::string xNet_grp_addr_;

		boost::scoped_ptr<dispatcher_t> xNet_dispatcher_;

	};

}


#endif