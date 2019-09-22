#include <SpringCat/Network/DefaultLinkFactory.h>
#include <ServerBase/acceptor_base.h>
#include <ServerBase/message_cut_filter.h>
#include <ServerBase/io_handler.h>
#include <ServerBase/crypto_aes_filter.h>

#define LINK_BASE_RAW_PTR "LINK_BASE_RAW_PTR"

namespace network {

	struct acceptor_base::impl
	{
		filters::MsgCutFilter msg_cut_filter_;
		filters::AESFilter aes_filter_;
		SpringCat::Network::FilterChain filters_;
		SpringCat::System::Threading::ThreadPool* thread_pool_;
		BaseCat::Network::Acceptor::Handle acceptor_handle_;

		int pending_buffer_size_;
		int pending_count_;

		acceptor_base_io_handler_itf* handler_;

	public:
		impl(SpringCat::System::Threading::ThreadPool* thread_pool, const char* ip, unsigned short port, bool port_reuse = false, bool use_cipher = true)
			: thread_pool_(thread_pool), acceptor_handle_(NULL), handler_(NULL),
			pending_buffer_size_(4096), pending_count_(1)
		{
			assert(thread_pool_ != NULL);

			filters_.Add(filters::Detail::MsgCutFilter::FILTER_NAME, &msg_cut_filter_);
			if(use_cipher)
				filters_.Add(filters::Detail::AESFilter::FILTER_NAME, &aes_filter_);

			acceptor_handle_ = BaseCat::Network::Acceptor::CreateHandle(thread_pool_->GetHandle(), filters_.GetHandle());
			if(NULL == acceptor_handle_)
			{
				assert(!"[acceptor::impl] BaseCat Acceptor Create failed");
				throw;
			}

			BaseCat::Network::Acceptor::AddBinding(acceptor_handle_, ip, port, port_reuse);
			BaseCat::Network::Acceptor::SetOnAccepted(acceptor_handle_, on_accepted, this);
			BaseCat::Network::Acceptor::SetOnReceived(acceptor_handle_, on_received, this);
			BaseCat::Network::Acceptor::SetOnClosed(acceptor_handle_, on_closed, this);
		}
		
		~impl()
		{
			BaseCat::Network::Acceptor::DestroyHandle(acceptor_handle_);
			acceptor_handle_ = NULL;

			filters_.Remove(filters::Detail::MsgCutFilter::FILTER_NAME);
			filters_.Remove(filters::Detail::AESFilter::FILTER_NAME);
		}

		bool start()
		{
			return BaseCat::Network::Acceptor::Start(acceptor_handle_);
		}

		bool stop()
		{
			return BaseCat::Network::Acceptor::Stop(acceptor_handle_);
		}

		static void __stdcall on_accepted(BaseCat::Network::Acceptor::Handle base_acc, 
			BaseCat::Network::Link::Handle link, void* context)
		{
			acceptor_base::impl* acc = static_cast<acceptor_base::impl*>(context);
			assert(acc->handler_ != NULL);

			link_ptr_t *link_ptr = new link_ptr_t(new network::link_base(link));
			BaseCat::Network::Link::AddAttribute(link, LINK_BASE_RAW_PTR, link_ptr);
			(*link_ptr)->set_connect_flag(true);

			acc->handler_->on_opened(*link_ptr);
		}

		static void __stdcall on_received(BaseCat::Network::Acceptor::Handle base_acc,
			BaseCat::Network::Link::Handle link, void* context)
		{
			acceptor_base::impl* acc = static_cast<acceptor_base::impl*>(context);
			assert(acc->handler_ != NULL);

			void* link_base_ptr = NULL;
			BaseCat::Network::Link::FindAttribute(link, LINK_BASE_RAW_PTR, &link_base_ptr);

			const link_ptr_t& link_ptr = *reinterpret_cast<link_ptr_t*>(link_base_ptr);

			autostream link_stream(link);

			protocol::packet_header header;
			memset(&header, 0x00, sizeof(header));
			SpringCat::System::StreamPtr payload(new SpringCat::System::Stream());
			SpringCat::System::StreamPtr source_packet(new SpringCat::System::Stream(link_stream.stream_));

			if(false == protocol::extract_message(link_stream.stream_, header, *payload))
			{
				// invalid packet.
				link_ptr->close();
				return;
			}
			if(link_ptr->get_session_id() == 0 && header.session_id != 0)
				link_ptr->set_session_id(header.session_id);
			
			acc->handler_->on_received(link_ptr, source_packet, header, payload);
		}

		static void __stdcall on_closed(BaseCat::Network::Acceptor::Handle base_acc,
			BaseCat::Network::Link::Handle link, void* context)
		{
			acceptor_base::impl* acc = static_cast<acceptor_base::impl*>(context);

			assert(acc->handler_ != NULL);

			void* link_base_ptr = NULL;
			BaseCat::Network::Link::FindAttribute(link, LINK_BASE_RAW_PTR, &link_base_ptr);

			const link_ptr_t& link_ptr = *reinterpret_cast<link_ptr_t*>(link_base_ptr);
			link_ptr->set_connect_flag(false);

			acc->handler_->on_closed(link_ptr);
			
			delete (reinterpret_cast<link_ptr_t*>(link_base_ptr));
			BaseCat::Network::Link::RemoveAttribute(link, LINK_BASE_RAW_PTR);
		}
	};


	acceptor_base::acceptor_base(SpringCat::System::Threading::ThreadPool* thread_pool, const char* ip, unsigned short port, bool port_reuse, bool use_cipher)
		: pimpl_(new impl(thread_pool, ip, port, port_reuse, use_cipher))
	{

	}

	acceptor_base::~acceptor_base()
	{
		delete pimpl_;
		pimpl_ = NULL;
	}

	bool acceptor_base::start()
	{
		return pimpl_->start();
	}

	bool acceptor_base::stop()
	{
		return pimpl_->stop();
	}

	void acceptor_base::set_pending_buff_size(int size)
	{
		pimpl_->pending_buffer_size_ = size;
	}

	void acceptor_base::set_pending_count(int count)
	{
		pimpl_->pending_count_ = count;
	}

	void acceptor_base::set_handler(acceptor_base_io_handler_itf* handler)
	{
		assert(handler != NULL);
		pimpl_->handler_ = handler;
	}
}
