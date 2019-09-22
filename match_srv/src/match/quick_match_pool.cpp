#include "quick_match_pool.h"
#include <common/server_consts.h>
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include "../xNet_network/xNet_gateway.h"
#include <util/timer_queue.h>
#include "../logic/match_server.h"

namespace match {

	void quick_pool::on_quick_match_check(uint32 timer_id, void* context)
	{
		quick_pool* qp = (quick_pool*)context;

		ScopedLock lock(qp->cs_);
		if (qp->waiting_queue_.empty())	return;

		if (qp->waiting_queue_.size() < 4)
		{
			qp->add_ai(11);
			qp->add_ai(12);
			qp->add_ai(13);
		}
		qp->internal_make_match();

		qp->internal_garbage_process();
	}

	void quick_pool::add_ai(player_no_t player_no)
	{
		auto it = internal_find_info(player_no);
		if (it != waiting_queue_.end())
			return;

		waiting_queue_.push_back(match_player_info(player_no));
	}

	quick_pool::quick_pool()
		: match_check_timer_id_(0), avg_match_complete_sec_(30), total_match_count_(0)
	{
		match_check_timer_id_ = util::timer_queue::instance().add_timer(10 * 1000, true, &on_quick_match_check, this);
	}

	quick_pool::~quick_pool()
	{
		util::timer_queue::instance().remove_timer(match_check_timer_id_);
	}

	quick_pool& quick_pool::instance()
	{
		static quick_pool qp;
		return qp;
	}

	uint32 g_match_room_idx = 0;
	uint32 quick_pool::inc_match_room_no()
	{
		g_match_room_idx = SpringCat::System::Threading::Interlocked::Increment(&g_match_room_idx);
		if (g_match_room_idx == 0xFFFFFFFF)
		{
			g_match_room_idx = 1;
		}

		return g_match_room_idx;
	}

	bool quick_pool::add(player_no_t player_no, const xNet::address& addr, const protocol::match_item_info& using_match_items)
	{
		ScopedLock lock(cs_);
		auto it = internal_find_info(player_no);
		if (it != waiting_queue_.end())
			return false;

		waiting_queue_.push_back(match_player_info(player_no, addr, using_match_items));

		internal_make_match();

		return true;
	}

	void quick_pool::remove(player_no_t player_no)
	{
		ScopedLock lock(cs_);
		auto it = internal_find_info(player_no);
		if (it != waiting_queue_.end())
			waiting_queue_.erase(it);
	}

	int32 quick_pool::get_avg_match_sec() const
	{
		return avg_match_complete_sec_;
	}

	bool quick_pool::internal_make_match()
	{
		if (false == internal_is_available_match())
			return false;

		int32 map_no = match::server::instance().get_track_no(protocol::GameMode_QUICK);
		match_room_info new_room(map_no);

		for (int i = 0; i < waiting_queue_.size(); i++)
		{
			if (waiting_queue_[i].state_ != protocol::MatchState_SEARCHING)
				continue;

			auto player_no = waiting_queue_[i].player_no_;
			new_room.members_[player_no] = waiting_queue_[i];

			waiting_queue_[i].state_ = protocol::MatchState_PREPARE_MATCHING;
		}

		auto real_player_count = std::count_if(new_room.members_.begin(), new_room.members_.end(),
			[](const std::pair<player_no_t, match_player_info>& member) -> bool
		{
			return false == member.second.is_ai_;
		});

		auto room_no = inc_match_room_no();
		match_room_.insert(std::make_pair(room_no, new_room));

		if (real_player_count == 1)
		{
			match_complete_notify_to_players(room_no, protocol::server_address(), true);
		}
		else
		{
			internal_create_ps_req(room_no, new_room);
		}
		//internal_create_ps_req(room_no, new_room);

		return true;
	}

	// receive create_ps_ans from lobby server, then send internal_match_complete_notify to each player 
	void quick_pool::match_complete_notify_to_players(uint32 room_no, const protocol::server_address& ps_addr, bool use_standalone)
	{
		ScopedLock lock(cs_);

		auto it = match_room_.find(room_no);
		if (it == match_room_.end())
			return;

		protocol::internal_match_complete_notify noti;
		noti.set_result(error::common::success);
		noti.set_map_no(it->second.map_no_);
		noti.set_use_standalone(use_standalone);
		*noti.get_mutable_ps_addr() = ps_addr;
		for (auto p : it->second.members_)
			noti.insert_player_list(p.first, p.second.is_ai_);

		for (auto member : it->second.members_)
		{
			if (member.second.is_ai_) continue;

			noti.set_dest_player_no(member.first);
			*noti.get_mutable_using_match_items() = member.second.using_match_items_;
			xNet::gateway::instance().send(member.second.addr_, noti);

			internal_player_match_complete(member.second.player_no_);
		}
		
		internal_garbage_process();
	}

	void quick_pool::internal_garbage_process()
	{
		auto it = std::remove_if(waiting_queue_.begin(), waiting_queue_.end(),
			[](const match_player_info& mpi) -> bool
		{
			if (mpi.state_ == protocol::MatchState_COMPLETE)	return true;
		});
		waiting_queue_.erase(it, waiting_queue_.end());
	}

	void quick_pool::internal_player_match_complete(player_no_t player_no)
	{
		auto it = internal_find_info(player_no);
		if (it != waiting_queue_.end())
		{
			(*it).state_ = protocol::MatchState_COMPLETE;
			int32 delta_sec = static_cast<int32>(difftime(::time(nullptr), (*it).registered_time_));

			auto total_match_sec = avg_match_complete_sec_ * total_match_count_;
			avg_match_complete_sec_ = static_cast<int>(total_match_sec / ++total_match_count_);
		}
	}

	std::vector<match_player_info>::iterator quick_pool::internal_find_info(player_no_t player_no)
	{
		return std::find_if(waiting_queue_.begin(), waiting_queue_.end(),
			[player_no](const match_player_info& info) -> bool
		{
			return player_no == info.player_no_;
		}
		);
	}

	bool quick_pool::internal_is_available_match()
	{
		auto search_user_count = std::count_if(waiting_queue_.begin(), waiting_queue_.end(),
			[](const match_player_info& info) -> bool
		{
			return info.state_ == protocol::MatchState_SEARCHING;
		});

		return search_user_count >= MAX_PLAYER_COUNT;
	}

	void quick_pool::internal_create_ps_req(uint32 room_no, const match_room_info& info)
	{
		protocol::internal_create_ps_req req;
		req.set_room_no(room_no);
		req.set_map_no(info.map_no_);
		req.set_mode(protocol::GameMode_QUICK);

		for (auto p : info.members_)
		{
			auto player_no = p.first;
			auto& mpi = *req.insert_match_players(player_no);
			mpi.set_is_ai(p.second.is_ai_);

			if (false == p.second.is_ai_)
			{
				auto& xNet_addr_raw = *mpi.get_mutable_binded_xnet_addr();
				xNet_addr_raw.assign(sizeof(xNet::address), 0x00);
				memcpy(&xNet_addr_raw[0], &p.second.addr_, sizeof(xNet::address));
			}
		}

		xNet::address_ext lobby_addr;
		lobby_addr.set_type(xNet::ANYCAST);
		lobby_addr.set_group_name(XNET_LOBBY_NAME, static_cast<int>(strlen(XNET_LOBBY_NAME)));
		lobby_addr.set_region_code(0);	// local

		xNet::gateway::instance().send(lobby_addr.to_address(), req);

		write_fmt(Log::Process, "[quick_pool] create play server request. (room_no:%d)", room_no);
	}


}