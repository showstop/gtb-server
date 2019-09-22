#ifndef __GTB_LOBBYSERVER_GC_ACCEPTOR__
#define __GTB_LOBBYSERVER_GC_ACCEPTOR__

#include <ServerBase/sb_define.h>
#include <ServerBase/acceptor_base.h>
#include <ServerBase/dispatcher.h>
#include <ServerBase/io_handler.h>
#include <boost/scoped_ptr.hpp>
#include <boost/function.hpp>
#include <ServerBase/message_executor.h>


namespace gc {

	class acceptor : public network::acceptor_base_io_handler_itf,
		private SpringCat::System::TL::NonCopyable
	{
		typedef boost::function<void(const network::link_ptr_t&, StreamPtr&, void* context)> dispatcher_callback_t;
		typedef protocol::dispatcher<unsigned int, dispatcher_callback_t> dispatcher_t;
	public:
		acceptor(const std::string& ip, uint16 port);
		virtual ~acceptor();

		bool start();
		bool stop();

	private:
		void on_opened(const network::link_ptr_t& link);
		void on_closed(const network::link_ptr_t& link);
		void on_received(const network::link_ptr_t& link, StreamPtr source_packet,
			const protocol::packet_header& header, StreamPtr payload);

		template <typename THandler>
		static void message_dispatch(const network::link_ptr_t&, StreamPtr&, void*);

		void register_handler();

	private:
		boost::scoped_ptr<ThreadPool> thread_pool_;
		boost::scoped_ptr<network::acceptor_base> acceptor_;
		boost::scoped_ptr<dispatcher_t> dispatcher_;

		// message handler queue
		boost::scoped_ptr<protocol::message_queue> msgQ_;
	};

}

#endif