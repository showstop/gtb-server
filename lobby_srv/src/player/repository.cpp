#include "repository.h"
#include "../logic/lobby_server.h"
#include "../env/config.h"
#include <time.h>
#include <util/timer_queue.h>
#include <util/helper_util.h>
#include <ServerBase/logger.h>
#include "../xNet_network/xNet_gateway.h"
#include "player_dbo.h"

namespace player {

	unsigned int g_session_id = 0;

	repository::repository()
	{
		detect_expired_session_timer_id_ = util::timer_queue::instance().add_timer<void(unsigned int, void*)>(
			configurator::instance().get_gc_info().expired_session_check_term,
			true, &detect_expired_session, this);

		make_seed();
	}

	repository::~repository()
	{
		util::timer_queue::instance().remove_timer(detect_expired_session_timer_id_);
	}

	repository& repository::instance()
	{
		static repository r;
		return r;
	}

	network::session_id_t repository::generate_session_id() const
	{
		network::session_id_t&& ret = SpringCat::System::Threading::Interlocked::Increment(&g_session_id);
		if (ret == 0)
		{
			SpringCat::System::Threading::Interlocked::CompareExchange(&g_session_id, 0, 1);
			++ret;
		}
		return ret;
	}

	void repository::make_seed()
	{
		auto ls_no = lobby::server::instance().get_server_no();
		ls_no <<= 24;

		::srand(::time(0) & 0xffff);
		g_session_id = (rand() % 0x00afffff) + 1;

		g_session_id = g_session_id | ls_no;
	}

	network::session_id_t repository::reserve_session(player_no_t player_no, byte* key, byte* iv)
	{
		auto session_id = generate_session_id();

		ScopedLock lock(cs_);
		reserved_session_list_[session_id] = reserved_session_info(player_no, key, iv);

		return session_id;
	}

	bool repository::internal_check_if_valid(network::session_id_t session_id, network::link_ptr_t link)
	{
		auto it = reserved_session_list_.find(session_id);
		if(it == reserved_session_list_.end())
			return false;

		link->set_ref_id(it->second.player_no_);
		//link->set_session_key(it->second.key_, it->second.iv_);

		return true;
	}

	bool repository::add(network::session_id_t session_id, network::link_ptr_t link)
	{
		ScopedLock lock(cs_);
		
		if (false == internal_check_if_valid(session_id, link))
			return false;

		auto player_no = link->get_ref_id();
		auto xNet_sock = xNet::gateway::instance().create_socket(static_cast<uint64>(player_no));

		player_ptr_t obj(new player::object(link, xNet_sock));
		repos_[player_no] = obj;

		return true;
	}

	void repository::confirm_reserved_session(network::session_id_t session_id, network::link_ptr_t link)
	{
		ScopedLock lock(cs_);

		auto it = reserved_session_list_.find(session_id);
		if (it == reserved_session_list_.end())
			return;

		link->set_session_key(it->second.key_, it->second.iv_);
		internal_remove_session(session_id);
	}

	player_ptr_t repository::find(player_no_t player_no)
	{
		ScopedLock lock(cs_);
		return internal_find(player_no);
	}

	player_ptr_t repository::internal_find(player_no_t player_no)
	{
		auto it = repos_.find(player_no);
		if (it != repos_.end())
			return it->second;

		return nullptr;
	}

	void repository::remove(player_no_t player_no)
	{
		ScopedLock lock(cs_);
		repos_.erase(player_no);
	}

	void repository::internal_remove_session(network::session_id_t session_id)
	{
		reserved_session_list_.erase(session_id);
	}

	// static 
	void repository::detect_expired_session(unsigned int timer_id, void* context)
	{
		auto ctx = static_cast<repository*>(context);

		ScopedLock(ctx->cs_);
		auto now = ::time(0);
		for (auto rsi : ctx->reserved_session_list_)
		{
			auto def_secs = static_cast<int>(difftime(now, rsi.second.registered_timestamp_));

			if (def_secs > configurator::instance().get_gc_info().reserved_session_expired_time)
				ctx->reserved_session_list_.erase(rsi.first);
		}
	}

	bool repository::load_player_profile_info(player_no_t player_no, protocol::player_profile_info& info)
	{
		ScopedLock lock(cs_);

		auto obj = internal_find(player_no);
		if (nullptr == obj)
		{
			return dbo::player::load_player_profile_info(player_no, info);
		}
		obj->get_profile_info(info);
		return true;
	}

	bool repository::load_selected_vehicle_info(player_no_t player_no, protocol::vehicle& info)
	{
		ScopedLock lock(cs_);

		auto obj = internal_find(player_no);
		if (nullptr == obj)
		{
			return dbo::vehicle::load_selected_vehicle(player_no, info);
		}
		auto selected_no = obj->get_vehicle_agent()->get_selected();
		obj->get_vehicle_agent()->get_vehicle(selected_no, info);

		return true;
	}

	bool repository::load_ability_slot_info(player_no_t player_no, protocol::ability_slot& info)
	{
		ScopedLock lock(cs_);
		auto obj = internal_find(player_no);
		if (nullptr == obj)
		{
			return dbo::ability::load_ability_slot_info(player_no, info);
		}

		obj->get_ability_agent()->get_ability_slot(info);
		return true;
	}

	bool repository::load_ability_list(player_no_t player_no, protocol::ability_list& infos)
	{
		ScopedLock lock(cs_);
		auto obj = internal_find(player_no);
		if (nullptr == obj)
		{
			return dbo::ability::load_ability_list(player_no, infos);
		}

		obj->get_ability_agent()->get_ability_list(infos);
		return true;
	}


}