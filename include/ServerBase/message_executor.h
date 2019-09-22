#ifndef __K_SB_MESSAGE_EXECUTOR__
#define __K_SB_MESSAGE_EXECUTOR__

#include <ServerBase/sb_define.h>
#include <ServerBase/link_base.h>
#include <boost/scoped_ptr.hpp>

namespace protocol {

	class message_handler_itf
	{
	public:
		message_handler_itf(const network::link_ptr_t& link, StreamPtr& msg)
			: link_(link), msg_(msg) {}

		virtual ~message_handler_itf(){}

		virtual bool process() = 0;
		virtual bool is_NOT_activated_link()
		{
			if(false == link_->is_activated())
			{
				link_->close();
				return true;
			}
			return false;
		}
	protected:
		const network::link_ptr_t link_;
		StreamPtr msg_;
	};

	class message_queue : SpringCat::System::TL::NonCopyable
	{
	public:
		message_queue(size_t thread_count)
			: shared_(false) 
		{
			thread_pool_ = BaseCat::System::Threading::ThreadPool::CreateHandle(thread_count);
			if(NULL == thread_pool_)
				throw "[message_queue::message_queue] thread_pool create failed";
		}

		message_queue(BaseCat::System::Threading::ThreadPool::Handle thread_pool)
			: shared_(true) 
		{
			thread_pool_ = thread_pool;
		}

		virtual ~message_queue() 
		{
			if(false == shared_)
			{
				BaseCat::System::Threading::ThreadPool::DestroyHandle(thread_pool_);
				thread_pool_ = NULL;
			}
		}

		void add(message_handler_itf* handler)
		{
			if(false == BaseCat::System::Threading::ThreadPool::QueueWorkItem(thread_pool_,
				reinterpret_cast<ThreadPool::ThreadEvent>(&message_queue::execute), handler))
				printf("add_failed!!!\r\n");
		}

	private:
		static unsigned int __stdcall execute(message_handler_itf* handler)
		{
			handler->process();
			delete handler;
			handler = NULL;
			return 0;
		}
	private:
		BaseCat::System::Threading::ThreadPool::Handle thread_pool_;
		bool shared_;
	};

}

#endif