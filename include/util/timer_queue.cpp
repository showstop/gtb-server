#include "timer_queue.h"
#include <time.h>
#include <xNet/sb_define.h>
#include <boost/bind.hpp>
#include <boost/function.hpp>

namespace util {

timer_queue::timer_queue()
	: event_(new auto_reset_event_t), 
	thread_pool_(new thread_pool_t(SpringCat::System::Environment::GetProcessorCount())),
	thread_(), lock_(), terminated_(false),
	current_timer_id_(0), ordered_timer_contexts_(), posted_timers_()
{
	boost::function<void()> f(boost::bind(&timer_queue::execute, this));
	thread_.reset(new thread_t(f));
}

timer_queue::~timer_queue()
{
	terminated_ = true;
	event_->Set();
	thread_->Wait();
	thread_.reset();
	thread_pool_.reset();

	for (timer_contexts_t::iterator it = ordered_timer_contexts_.begin(); it != ordered_timer_contexts_.end(); ++it)
	{
		delete *it;
	}
	ordered_timer_contexts_.clear();
	for (std::set<detail::timer_context*>::iterator it = posted_timers_.begin(); it != posted_timers_.end(); ++it)
	{
		delete *it;
	}
	posted_timers_.clear();
}

timer_queue& timer_queue::instance()
{
	return timer_queue_t::Instance();
}

bool timer_queue::remove_timer(unsigned int timer_id)
{
	bool result = false;
	SpringCat::System::Threading::ScopedLock<> lock(lock_);

	for (timer_contexts_t::iterator it = ordered_timer_contexts_.begin(); it != ordered_timer_contexts_.end(); ++it)
	{
		detail::timer_context* context = *it;
		if (context->id_ == timer_id)
		{
			ordered_timer_contexts_.erase(it);
			delete context;
			result = true;
			break;
		}
	}

	return result;
}

void timer_queue::execute()
{
	unsigned int to_wait = INFINITE;

	while (true)
	{
		event_->TimedWait(to_wait);
		if (terminated_ == true)
		{
			break;
		}

		unsigned int current_time = GET_TICK();

		SpringCat::System::Threading::ScopedLock<> lock(lock_);

		bool exit_flag = false;
		while (exit_flag == false && ordered_timer_contexts_.empty() == false)
		{
			timer_contexts_t::iterator it = ordered_timer_contexts_.begin();
			detail::timer_context* context = *it;

			if (current_time >= context->due_time_)
			{
				ordered_timer_contexts_.erase(it);
				detail::timer_context* new_context = new detail::timer_context(*context);

				if (context->repeat_ == true)
				{
					context->due_time_ = current_time + context->period_;
					ordered_timer_contexts_.insert(context);
				}
				else
				{
					delete context;
					context = NULL;
				}

				posted_timers_.insert(new_context);
				thread_pool_->QueueWorkItem(
					[this, new_context]() -> void
					{
						SpringCat::System::Threading::ScopedLock<> lock(lock_);

						posted_timers_.erase(new_context);

						boost::scoped_ptr<detail::timer_context> context_ptr(new_context);
						context_ptr->handler_();
					}
				);
			}
			else
			{
				exit_flag = true;
			}

			if (ordered_timer_contexts_.empty() == false)
			{
				detail::timer_context* next_context = *ordered_timer_contexts_.begin();
				to_wait = next_context->due_time_ - current_time;
			}
			else
			{
				to_wait = INFINITE;
			}
		}
	}
}

}
