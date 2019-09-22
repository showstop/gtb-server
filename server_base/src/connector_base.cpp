#include <ServerBase/connector_base.h>
#include <SpringCat/Network/DefaultLinkFactory.h>
#include <ServerBase/message_cut_filter.h>
#include <ServerBase/crypto_aes_filter.h>
#include <ServerBase/io_handler.h>

#define LINK_BASE_RAW_PTR "LINK_BASE_RAW_PTR"

namespace network {

	struct connector_base::impl
	{
		filters::MsgCutFilter msg_cut_filter_;
		filters::AESFilter aes_filter_;
		SpringCat::Network::FilterChain filters_;
		SpringCat::System::Threading::ThreadPool* thread_pool_;
		BaseCat::Network::Connector::Handle connector_handle_;
		link_ptr_t link_;
		BaseCat::System::Threading::AutoResetEvent conn_wait_event_;

		int pending_buffer_size_;
		int pending_count_;

		connector_base_io_handler_itf* handler_;

	public:
		impl(SpringCat::System::Threading::ThreadPool* thread_pool, bool use_cipher)
			: thread_pool_(thread_pool), handler_(NULL), pending_buffer_size_(4096), pending_count_(2)
		{
			assert(thread_pool_ != NULL);

			filters_.Add(filters::Detail::MsgCutFilter::FILTER_NAME, &msg_cut_filter_);
			if(use_cipher)
				filters_.Add(filters::Detail::AESFilter::FILTER_NAME, &aes_filter_);
			
			connector_handle_ = BaseCat::Network::Connector::CreateHandle(thread_pool_->GetHandle(), filters_.GetHandle());
			if(NULL == connector_handle_)
			{
				assert(!"[connector::impl] BaseCat Connector Create failed");
				throw;
			}

			BaseCat::Network::Connector::SetOnConnected(connector_handle_, on_connected, this);
			BaseCat::Network::Connector::SetOnReceived(connector_handle_, on_received, this);
			BaseCat::Network::Connector::SetOnDisconnected(connector_handle_, on_disconnected, this);
		}

		~impl()
		{
			BaseCat::Network::Connector::DestroyHandle(connector_handle_);
			connector_handle_ = NULL;

			filters_.Remove(filters::Detail::MsgCutFilter::FILTER_NAME);
			filters_.Remove(filters::Detail::AESFilter::FILTER_NAME);
		}

		bool connect(const std::string& ip, unsigned short port, unsigned short timeout)
		{
			if(false == BaseCat::Network::Connector::Connect(connector_handle_, ip.c_str(), port, timeout))
				return false;
			return conn_wait_event_.TimedWait(timeout);
		}

		void disconnect()
		{
			if(link_.get())
				link_->close();
		}

		bool send(const SpringCat::Wave::object_base& msg)
		{
			if(link_.get())
				return link_->send(msg);
			return false;
		}

	private:
		static void __stdcall on_connected(BaseCat::Network::Connector::Handle base_conn,
			BaseCat::Network::Link::Handle link, void* context)
		{
			connector_base::impl* conn = static_cast<connector_base::impl*>(context);

			link_ptr_t link_ptr(new network::link_base(link));
			conn->link_.swap(link_ptr);
			conn->link_->set_connect_flag(true);
			conn->conn_wait_event_.Set();
		}

		static void __stdcall on_received(BaseCat::Network::Connector::Handle base_conn,
			BaseCat::Network::Link::Handle link, void* context)
		{
			connector_base::impl* conn = static_cast<connector_base::impl*>(context);

			link_ptr_t link_ptr(conn->link_);

			autostream link_stream(link);

			protocol::packet_header header;
			memset(&header, 0x00, sizeof(protocol::packet_header));
			SpringCat::System::StreamPtr payload(new SpringCat::System::Stream());
			SpringCat::System::StreamPtr source_packet(new SpringCat::System::Stream(link_stream.stream_));

			if(false == protocol::extract_message(link_stream.stream_, header, *payload))
			{
				// invalid packet.
				link_ptr->close();
				return;
			}
			assert(conn->handler_ != NULL);
			conn->handler_->on_received(source_packet, header, payload);
		}

		static void __stdcall on_disconnected(BaseCat::Network::Connector::Handle base_conn,
			BaseCat::Network::Link::Handle link, void* context)
		{
			connector_base::impl* conn = static_cast<connector_base::impl*>(context);
			
			assert(conn->handler_ != NULL);

			conn->link_->set_connect_flag(false);
			conn->handler_->on_closed();

			link_ptr_t tmp;
			conn->link_.swap(tmp);
		}
	};

	connector_base::connector_base(SpringCat::System::Threading::ThreadPool* thread_pool, bool use_cipher)
		: pimpl_(new connector_base::impl(thread_pool, use_cipher))
	{

	}

	connector_base::~connector_base()
	{
		delete pimpl_;
		pimpl_ = NULL;
	}

	bool connector_base::connect(const char* ip, unsigned short port, unsigned short timeout)
	{
		return pimpl_->connect(ip, port, timeout);
	}

	void connector_base::disconnect()
	{
		pimpl_->disconnect();
	}

	void connector_base::set_pending_buff_size(int size)
	{
		pimpl_->pending_buffer_size_ = size;
	}

	void connector_base::set_pending_count(int count)
	{
		pimpl_->pending_count_ = count;
	}

	void connector_base::set_handler(connector_base_io_handler_itf* handler)
	{
		pimpl_->handler_ = handler;
	}

	bool connector_base::send(const SpringCat::Wave::object_base& msg)
	{
		return pimpl_->send(msg);
	}

	void connector_base::get_link_ptr(network::link_ptr_t& link_ptr) const
	{
		link_ptr = pimpl_->link_;
	}

}