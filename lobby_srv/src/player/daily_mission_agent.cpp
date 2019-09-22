#include "daily_mission_agent.h"
#include "player_dbo.h"
#include <common/exception.h>
#include "../registry/daily_mission_registry.h"

namespace daily_mission {

	agent::agent(player_no_t player_no)
		: player_no_(player_no)
	{

	}

	agent::~agent()
	{

	}

	bool agent::load()
	{
		ScopedLock lock(cs_);
		return dbo::daily_mission::load_daily_mission_list(player_no_, infos_);
	}

	void agent::get_mission_list(protocol::daily_mission_list& infos)
	{
		ScopedLock lock(cs_);
		infos = infos_;
	}

	void agent::set_progress(int32 mission_id, int32 progress)
	{
		ScopedLock lock(cs_);
		auto it = internal_find_info(mission_id);
		if (it != infos_.get_mutable_infos()->end())
		{
			(*it)->set_progress(progress);
		}
	}

	void agent::set_received(int32 mission_id, bool is_receive)
	{
		ScopedLock lock(cs_);
		auto it = internal_find_info(mission_id);
		if (it != infos_.get_mutable_infos()->end())
		{
			(*it)->set_receive_reward(is_receive);
		}
	}

	void agent::save_mission(int32 mission_id)
	{
		ScopedLock lock(cs_);
		auto it = internal_find_info(mission_id);
		if (it != infos_.get_mutable_infos()->end())
		{
			dbo::daily_mission::save_daily_mission_info(player_no_, *(*it));
		}
	}

	std::vector<protocol::daily_mission_info*>::iterator agent::internal_find_info(int32 mission_id)
	{
		return std::find_if(infos_.get_mutable_infos()->begin(), infos_.get_mutable_infos()->end(),
			[mission_id](const protocol::daily_mission_info* mi) -> bool
		{
			return mission_id == mi->get_mission_id();
		});
	}


}