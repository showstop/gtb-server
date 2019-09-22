#include "gc_link_table.h"
#include <util/timer_queue.h>
#include <time.h>

namespace gc {

	link_table::link_table()
	{

	}

	link_table::~link_table()
	{

	}

	// static 
	link_table& link_table::instance()
	{
		static link_table lt;
		return lt;
	}

	void link_table::add(const network::link_ptr_t& link, player_no_t player_no)
	{
		ScopedLock lock(cs_);
		link_map_[player_no] = link;
	}

	void link_table::remove(player_no_t player_no)
	{
		ScopedLock lock(cs_);
		link_map_.erase(player_no);
	}

	bool link_table::find(player_no_t player_no, network::link_ptr_t& link)
	{
		ScopedLock lock(cs_);

		auto it = link_map_.find(player_no);
		if (it != link_map_.end())
		{
			link = it->second;
			return true;
		}
		return false;
	}

	// static 
	void link_table::detect_expired_link(unsigned int timer_id, void* context)
	{
		auto now = ::time(0);

		auto ctx = static_cast<link_table*>(context);
		ScopedLock(ctx->cs_);

		//todo
	}
}