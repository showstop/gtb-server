#include "achievement_agent.h"
#include "player_dbo.h"
#include <common/exception.h>
#include "../registry/achievement_registry.h"

namespace achievement {

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
		return dbo::achievement::load_achievement_list(player_no_, infos_);
	}

	void agent::get_achievement_list(protocol::achievement_list& infos)
	{
		ScopedLock lock(cs_);
		infos = infos_;
	}

	void agent::set_progress(int32 achievement_id, int32 progress)
	{
		ScopedLock lock(cs_);
		auto it = internal_find_info(achievement_id);
		if (it != infos_.get_mutable_infos()->end())
		{
			(*it)->set_progress(progress);
		}
	}

	void agent::set_received(int32 achievement_id, bool is_receive)
	{
		ScopedLock lock(cs_);
		auto it = internal_find_info(achievement_id);
		if (it != infos_.get_mutable_infos()->end())
		{
			(*it)->set_receive_reward(is_receive);
		}
	}

	void agent::save_achievement(int32 achievement_id)
	{
		ScopedLock lock(cs_);
		auto it = internal_find_info(achievement_id);
		if (it != infos_.get_mutable_infos()->end())
		{
			dbo::achievement::save_achievement_info(player_no_, *(*it));
		}
	}

	std::vector<protocol::achievement_info*>::iterator agent::internal_find_info(int32 achievement_id)
	{
		return std::find_if(infos_.get_mutable_infos()->begin(), infos_.get_mutable_infos()->end(),
			[achievement_id](const protocol::achievement_info* ai) -> bool
		{
			return achievement_id == ai->get_achievement_id();
		});
	}


}