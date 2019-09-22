#ifndef __GTB_GC_LINK_TABLE__
#define __GTB_GC_LINK_TABLE__

#include <map>
#include <ServerBase/link_base.h>
#include <common/server_consts.h>

namespace gc {

	class link_table
	{
	private:
		link_table();

	public:
		~link_table();

		static link_table& instance();

		void add(const network::link_ptr_t& link, player_no_t player_no);
		void remove(player_no_t player_no);

		bool find(player_no_t player_no, network::link_ptr_t& link);

	private:
		static void detect_expired_link(unsigned int, void*);

	private:
		uint32 expired_link_detector_timer_id_;

		mutable CriticalSection cs_;
		std::map<player_no_t, network::link_ptr_t> link_map_;
	};

}

#endif