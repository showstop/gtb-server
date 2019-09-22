#ifndef __K_SB_MSGCUT_FILTER__
#define __K_SB_MSGCUT_FILTER__


#include <SpringCat/System/TL/SmallObject.h>
#include <SpringCat/Common/Exceptions.h>
#include <SpringCat/Network/Filter.h>

#include <ServerBase/protocol.h>

namespace network { namespace filters {

	namespace Detail
	{
		namespace MsgCutFilter
		{
			const char * const FILTER_NAME = "Filter::MsgCutFilter";
			const char * const CONTEXT_NAME = "Filter::MsgCutFilter::Context";
		}
	}

	class MsgCutFilter : public SpringCat::Network::IFilter
	{
	private:
		struct Context : public BaseCat::System::TL::SmallObject<Context>
		{
			BaseCat::System::Stream::Handle read_;

			Context(void)
				: read_(BaseCat::System::Stream::CreateHandle())
			{}
			~Context(void)
			{
				BaseCat::System::Stream::DestroyHandle(read_);
				read_ = NULL;
			}
		};
		int pending_buffer_size_;
	public:
		MsgCutFilter()
			: IFilter(Detail::MsgCutFilter::FILTER_NAME),
			pending_buffer_size_(4096)
		{

		}

		virtual ~MsgCutFilter(void)
		{

		}

	protected:
		virtual void OnOpened(BaseCat::Network::Filter::Handle next,
			BaseCat::Network::Link::Handle link)
		{
			Context *context = new Context;
			if (BaseCat::Network::Link::AddAttribute(link,
				Detail::MsgCutFilter::CONTEXT_NAME, context) == false)
			{
				delete context;
				context = NULL;
				BaseCat::Network::Link::Close(link);
				SpringCat::throw_exception(SpringCat::LogicException(
					"[TextLineFilter::OnOpened()] Network::Link::AddAttribute() failed."));
				return;
			}

			BaseCat::Network::Link::Recv(link, pending_buffer_size_);

			BaseCat::Network::Filter::DoOnLinkOpened(next, link);
		}

		virtual void OnClosed(BaseCat::Network::Filter::Handle next,
			BaseCat::Network::Link::Handle link)
		{
			Context *context = NULL;
			if (BaseCat::Network::Link::FindAttribute(link, Detail::MsgCutFilter::CONTEXT_NAME,
				reinterpret_cast<void **>(&context)) == false)
			{
				return;
			}
			BaseCat::Network::Link::RemoveAttribute(link, Detail::MsgCutFilter::CONTEXT_NAME);
			delete context;
			context = NULL;

			BaseCat::Network::Filter::DoOnLinkClosed(next, link);
		}

		virtual void OnSend(BaseCat::Network::Filter::Handle next,
			BaseCat::Network::Link::Handle link,
			BaseCat::System::SmartHeap::Block buffer, size_t size)
		{
			BaseCat::Network::Filter::DoOnSend(next, link, buffer, size);
		}

		virtual void OnReceived(BaseCat::Network::Filter::Handle next, 
			BaseCat::Network::Link::Handle link, 
			BaseCat::System::SmartHeap::Block buffer, size_t size)
		{
			Context *context = NULL;
			if (BaseCat::Network::Link::FindAttribute(link, Detail::MsgCutFilter::CONTEXT_NAME,
				reinterpret_cast<void **>(&context)) == false)
			{
				return;
			}

			BaseCat::System::Stream::Write(context->read_, buffer, size);
			BaseCat::System::SmartHeap::Free(buffer);
			buffer = NULL;

			BaseCat::Network::Link::Recv(link, pending_buffer_size_);

			bool flag_continue = true;
			do
			{
				int len = 0;
				protocol::ParseRet ret = protocol::parse(context->read_, len);
				switch(ret)
				{
					case protocol::TOO_LARGE_PACKET:
					case protocol::MISMATCH_PROTOCOL_VERSION:
						{
							BaseCat::System::Stream::Clear(context->read_);
							BaseCat::Network::Link::Close(link);
							flag_continue = false;
							break;
						}
					case protocol::NEED_MORE_PACKET:
						{
							flag_continue = false;
							break;
						}
					case protocol::SUCCESS:
						{
							BaseCat::System::SmartHeap::Block packet = BaseCat::System::SmartHeap::Alloc(len);
							BaseCat::System::Stream::Read(context->read_, packet, len);

							BaseCat::Network::Filter::DoOnReceived(next, link, BaseCat::System::SmartHeap::Copy(packet), len);
							BaseCat::System::SmartHeap::Free(packet);
							packet = NULL;

							continue;
						}
				}
			} while ( flag_continue == true );
			
		}

	};

}}
#endif