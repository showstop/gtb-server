#ifndef __GTB_QUICK_MATCH_POOL__
#define __GTB_QUICK_MATCH_POOL__

#include <ServerBase/sb_define.h>
#include <common/server_consts.h>
#include <vector>
#include <time.h>
#include <xNet/address.h>
#include <protocol/internal_ls_mms.dc.h>

namespace match {

	struct match_player_info
	{
		match_player_info() {}
		match_player_info(player_no_t player_no)
			: player_no_(player_no), state_(protocol::MatchState_SEARCHING), is_ai_(true) {}

		match_player_info(player_no_t player_no, const xNet::address& addr, const protocol::match_item_info& match_items)
			: player_no_(player_no), addr_(addr), registered_time_(::time(nullptr)), 
			state_(protocol::MatchState_SEARCHING), using_match_items_(match_items), is_ai_(false)
		{}

		player_no_t player_no_;
		xNet::address addr_;
		time_t registered_time_;
		protocol::MatchState state_;
		protocol::match_item_info using_match_items_;
		bool is_ai_;
	};

	struct match_room_info
	{
		match_room_info(int32 map_no)
			: map_no_(map_no), created_time_(::time(nullptr))
		{}
		std::map<player_no_t, match_player_info> members_;
		int32 map_no_;
		time_t created_time_;
	};

	class quick_pool
	{
	public:
		quick_pool();
		~quick_pool();

		static quick_pool& instance();

		bool add(player_no_t player_no, const xNet::address& addr, const protocol::match_item_info& using_match_items);
		void remove(player_no_t player_no);

		int32 get_avg_match_sec() const;

		void match_complete_notify_to_players(uint32 room_no, const protocol::server_address& ps_addr, bool use_standalone=false);
	private:
		std::vector<match_player_info>::iterator internal_find_info(player_no_t player_no);
		bool internal_is_available_match();
		uint32 inc_match_room_no();

		void internal_create_ps_req(uint32 room_no, const match_room_info& info);
		void internal_player_match_complete(player_no_t player_no);

		bool internal_make_match();
		void add_ai(player_no_t player_no);

		void internal_garbage_process();

		static void on_quick_match_check(uint32 timer_id, void* context);
	private:
		CriticalSection cs_;
		std::vector<match_player_info> waiting_queue_;

		std::map<uint32, match_room_info> match_room_;

		uint32 match_check_timer_id_;
		int32 avg_match_complete_sec_;
		int32 total_match_count_;
	};

}


#endif // !__GTB_QUICK_MATCH_POOL__
