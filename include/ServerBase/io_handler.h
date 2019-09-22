#ifndef __K_SB_IOHANDLER__
#define __K_SB_IOHANDLER__

namespace network {

	class acceptor_base_io_handler_itf
	{
	public:
		virtual ~acceptor_base_io_handler_itf(void) {}

	public:
		virtual void on_opened(const link_ptr_t& link) = 0;
		virtual void on_closed(const link_ptr_t& link) = 0;
		virtual void on_received(const link_ptr_t& link, SpringCat::System::StreamPtr source_packet,
			const protocol::packet_header& header, SpringCat::System::StreamPtr payload) = 0;
	};

	class connector_base_io_handler_itf
	{
	public:
		virtual ~connector_base_io_handler_itf(void) {}

	public:
		virtual void on_closed() = 0;
		virtual void on_received(
			SpringCat::System::StreamPtr source_packet, const protocol::packet_header& header, SpringCat::System::StreamPtr payload) = 0;
	};

}

#endif