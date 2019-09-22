#ifndef __GTB_LOBBY_PLAYER__
#define __GTB_LOBBY_PLAYER__

#include <SpringCat/System/System.h>
#include <common/server_consts.h>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <ServerBase/link_base.h>
#include "asset_agent.h"
#include "vehicle_agent.h"
#include "ability_agent.h"
#include "attendance_agent.h"
#include "achievement_agent.h"
#include "daily_mission_agent.h"
#include "grandprix_agent.h"

namespace xNet {
	class socket;
}

namespace player {

	class object : public SpringCat::System::TL::SmallObject<object>
	{
		friend class repository;
	public:
		object(player_no_t player_no);
		object(const network::link_ptr_t& link, const xNet::socket* sock);
		virtual~object();

		player_no_t get_player_no() const;
		void get_profile_info(protocol::player_profile_info& info) const;
		void set_profile_info(const std::string& game_nick, int16 nation_code);

		void inc_exp(int32 delta);

		const xNet::socket* get_xNet_socket();
		network::link_ptr_t get_client_link();

		ability::agent_ptr_t get_ability_agent();
		asset::agent_ptr_t get_asset_agent();
		vehicle::agent_ptr_t get_vehicle_agent();
		attendance::agent_ptr_t get_attendance_agent();
		achievement::agent_ptr_t get_achievement_agent();
		daily_mission::agent_ptr_t get_daily_mission_agent();
		grandprix::agent_ptr_t get_grandprix_agent();

	private:
		int16 calc_exp_gauge();

	private:
		struct impl;
		boost::scoped_ptr<impl> pimpl_;
	};

	typedef boost::shared_ptr<object> player_ptr_t;

}


#endif