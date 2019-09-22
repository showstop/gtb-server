#include "player.h"
#include "player_dbo.h"
#include <common/exception.h>
#include "../xNet_network/xNet_gateway.h"


namespace player {

	struct object::impl
	{
		impl::impl(player_no_t player_no)
			: player_no_(player_no)
		{

		}

		impl::impl(const network::link_ptr_t& link, const xNet::socket* sock)
			: link_(link), player_no_(link->get_ref_id()), xNet_sock_(sock)
		{
			asset_agent_.reset(new asset::agent(player_no_));
			vehicle_agent_.reset(new vehicle::agent(player_no_));
			ability_agent_.reset(new ability::agent(player_no_));
			attendance_agent_.reset(new attendance::agent(player_no_));
			achievement_agent_.reset(new achievement::agent(player_no_));
			daily_mission_agent_.reset(new daily_mission::agent(player_no_));
			grandprix_agent_.reset(new grandprix::agent(player_no_));
		}

		CriticalSection cs_;
		player_no_t player_no_;

		const xNet::socket* xNet_sock_;
		network::link_ptr_t link_;
		protocol::player_profile_info profile_info_;

		ability::agent_ptr_t ability_agent_;
		asset::agent_ptr_t asset_agent_;
		vehicle::agent_ptr_t vehicle_agent_;
		attendance::agent_ptr_t attendance_agent_;
		achievement::agent_ptr_t achievement_agent_;
		daily_mission::agent_ptr_t daily_mission_agent_;
		grandprix::agent_ptr_t grandprix_agent_;
	};

	object::object(player_no_t player_no)
		: pimpl_(new object::impl(player_no))
	{
		if (false == dbo::player::load_player_profile_info(player_no, pimpl_->profile_info_))
			throw new exception_x(error::common::internal_db_error, "cannot load profile info(%lld)", player_no);

		calc_exp_gauge();
	}

	object::object(const network::link_ptr_t& link, const xNet::socket* sock)
		: pimpl_(new object::impl(link, sock))
	{
		if (false == dbo::player::load_player_profile_info(link->get_ref_id(), pimpl_->profile_info_))
			throw new exception_x(error::common::internal_db_error, "cannot load profile info(%lld)", link->get_ref_id());

		calc_exp_gauge();

		/*if(false == pimpl_->asset_agent_->load())
			throw new exception_x(error::common::internal_db_error, "cannot load asset info(%lld)", link->get_ref_id());

		if(false == pimpl_->vehicle_agent_->load())
			throw new exception_x(error::common::internal_db_error, "cannot load vehicle info(%lld)", link->get_ref_id());*/

		pimpl_->asset_agent_->load();
		pimpl_->vehicle_agent_->load();
		pimpl_->ability_agent_->load();
		pimpl_->attendance_agent_->load();
		pimpl_->achievement_agent_->load();
		pimpl_->daily_mission_agent_->load();
		pimpl_->grandprix_agent_->load();
	}

	object::~object()
	{
		if (pimpl_->xNet_sock_)
		{
			xNet::gateway::instance().destroy_socket(const_cast<xNet::socket*>(pimpl_->xNet_sock_));
			pimpl_->xNet_sock_ = nullptr;
		}
	}

	player_no_t object::get_player_no() const
	{
		return pimpl_->player_no_;
	}

	void object::get_profile_info(protocol::player_profile_info& info) const
	{
		ScopedLock lock(pimpl_->cs_);
		info = pimpl_->profile_info_;
	}

	void object::set_profile_info(const std::string& game_nick, int16 nation_code)
	{
		ScopedLock lock(pimpl_->cs_);
		pimpl_->profile_info_.set_game_nick(game_nick);
		pimpl_->profile_info_.set_nation_code(nation_code);

		dbo::player::save_player_profile_info(pimpl_->profile_info_);
	}

	inline int32 calc_need_exp_by_level(int16 level)
	{
		return level * (level - 1) * 97;
	}

	int16 object::calc_exp_gauge()
	{
		auto current_lv = pimpl_->profile_info_.get_player_level();
		auto next_lv = current_lv + 1;

		auto current_lv_exp = calc_need_exp_by_level(current_lv);
		auto current_exp = pimpl_->profile_info_.get_exp();
		auto next_lv_exp = calc_need_exp_by_level(next_lv);

		return static_cast<int16>(((float)(current_exp - current_lv_exp) / (float)(next_lv_exp - current_lv_exp)) * 100);
	}

	void object::inc_exp(int32 delta)
	{
		ScopedLock lock(pimpl_->cs_);

		auto current_lv = pimpl_->profile_info_.get_player_level();
		auto next_lv = current_lv + 1;
		auto current_lv_exp = calc_need_exp_by_level(current_lv);
		auto next_lv_exp = calc_need_exp_by_level(next_lv);

		pimpl_->profile_info_.set_exp(pimpl_->profile_info_.get_exp() + delta);

		if (pimpl_->profile_info_.get_exp() >= next_lv_exp)
		{
			pimpl_->profile_info_.set_player_level(next_lv);
			current_lv += 1;
			next_lv += 1;
		}
		pimpl_->profile_info_.set_exp_gauge(calc_exp_gauge());
		dbo::player::save_player_profile_info(pimpl_->profile_info_);
	}

	const xNet::socket* object::get_xNet_socket()
	{
		return pimpl_->xNet_sock_;
	}

	network::link_ptr_t object::get_client_link()
	{
		return pimpl_->link_;
	}

	ability::agent_ptr_t object::get_ability_agent()
	{
		return pimpl_->ability_agent_;
	}

	boost::shared_ptr<asset::agent> object::get_asset_agent()
	{
		return pimpl_->asset_agent_;
	}

	boost::shared_ptr<vehicle::agent> object::get_vehicle_agent()
	{
		return pimpl_->vehicle_agent_;
	}

	attendance::agent_ptr_t object::get_attendance_agent()
	{
		return pimpl_->attendance_agent_;
	}

	achievement::agent_ptr_t object::get_achievement_agent()
	{
		return pimpl_->achievement_agent_;
	}

	daily_mission::agent_ptr_t object::get_daily_mission_agent()
	{
		return pimpl_->daily_mission_agent_;
	}

	grandprix::agent_ptr_t object::get_grandprix_agent()
	{
		return pimpl_->grandprix_agent_;
	}

}