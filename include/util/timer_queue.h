#ifndef __TR_LOGIC_TIMER_QUEUE__
#define __TR_LOGIC_TIMER_QUEUE__

#include <algorithm>
#include <functional>
#include <memory>
#include <set>
#include <SpringCat/SpringCat.h>
#include <boost/scoped_ptr.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <xNet/sb_define.h>

namespace util {

typedef boost::function<void()> timer_handler_t;

namespace detail {
struct timer_context
{
	unsigned int id_;
	unsigned int due_time_;
	unsigned int period_;
	bool repeat_;
	timer_handler_t handler_;
	void* context_;

	timer_context()
		: id_(0), due_time_(0), period_(0), repeat_(false), handler_()
	{}
	timer_context(const timer_context& from)
		: id_(from.id_), due_time_(from.due_time_),
		period_(from.period_), repeat_(from.repeat_), handler_(from.handler_)
	{}
	timer_context(unsigned int id, unsigned int due_time,
		unsigned int period, bool repeat, const timer_handler_t& handler)
		: id_(id), due_time_(due_time),
		period_(period), repeat_(repeat), handler_(handler)
	{}

	void swap(timer_context& other)
	{
		std::swap(id_, other.id_);
		std::swap(due_time_, other.due_time_);
		std::swap(period_, other.period_);
		std::swap(repeat_, other.repeat_);
		handler_.swap(other.handler_);
	}

	timer_context& operator=(const timer_context& rhs)
	{
		timer_context(rhs).swap(*this);

		return *this;
	}
};

struct timer_context_pred
{
	bool operator()(const timer_context* lhs, const timer_context* rhs) const
	{
		return lhs->due_time_ < rhs->due_time_;
	}
};
}

class timer_queue : private SpringCat::System::TL::NonCopyable
{
	friend struct timer_executor;
private:
	typedef SpringCat::System::Threading::Thread thread_t;
	typedef SpringCat::System::Threading::ThreadPool thread_pool_t;
	typedef SpringCat::System::Threading::AutoResetEvent auto_reset_event_t;
	typedef SpringCat::System::Threading::CriticalSection critical_section_t;
	typedef SpringCat::System::TL::Singleton<timer_queue> timer_queue_t;
	typedef std::multiset<detail::timer_context*, detail::timer_context_pred> timer_contexts_t;


private:
	boost::scoped_ptr<auto_reset_event_t> event_;
	boost::scoped_ptr<thread_pool_t> thread_pool_;
	boost::scoped_ptr<thread_t> thread_;
	critical_section_t lock_;
	bool terminated_;
	unsigned int current_timer_id_;
	timer_contexts_t ordered_timer_contexts_;
	std::set<detail::timer_context*> posted_timers_;

public:
	timer_queue();
	~timer_queue();
public:
	static timer_queue& instance();

public:
	template<typename F>
	void async_call(F func, unsigned int delay);

	template<typename F>
	unsigned int add_timer(unsigned int period, bool repeat, F func, void* context);
	bool remove_timer(unsigned int timer_id);

private:
	void execute();
};

template<typename F>
void timer_queue::async_call(F func, unsigned int delay)
{
	detail::timer_context* context = new detail::timer_context(0,
		GET_TICK() + delay, delay, false, func);

	SpringCat::System::Threading::ScopedLock<> lock(lock_);
	ordered_timer_contexts_.insert(context);
	event_->Set();
}

template<typename F>
unsigned int timer_queue::add_timer(unsigned int period, bool repeat, F func, void* ctx)
{
	if (period == 0)
	{
		return 0;
	}

	// timer id 0 is a special number for timer_queue
	// because it is reserved for the async_call() function internally.
	unsigned int timer_id = 0;
	do
	{
		timer_id = SpringCat::System::Threading::Interlocked::Increment(&current_timer_id_);
	}
	while (timer_id == 0);

	detail::timer_context* context = new detail::timer_context(timer_id,
		GET_TICK() + period, period, repeat, boost::bind(func, timer_id, ctx));

	SpringCat::System::Threading::ScopedLock<> lock(lock_);
	ordered_timer_contexts_.insert(context);
	event_->Set();

	return timer_id;
}

}

#endif
