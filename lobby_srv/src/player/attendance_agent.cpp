#include "attendance_agent.h"
#include "player_dbo.h"
#include <common/exception.h>

namespace attendance {

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
		return dbo::attendance::load_attendance_list(player_no_, infos_);
	}

	void agent::get_attendance_list(protocol::attendance_list& infos)
	{
		ScopedLock lock(cs_);
		infos = infos_;
	}

	void agent::set_complete(int32 day_seq, bool is_complete)
	{
		ScopedLock lock(cs_);
		auto it = internal_find_attend_info(day_seq);
		if (it != infos_.get_mutable_infos()->end())
		{
			(*it)->set_complete(is_complete);
		}
	}

	void agent::set_received(int32 day_seq, bool is_receive)
	{
		ScopedLock lock(cs_);
		auto it = internal_find_attend_info(day_seq);
		if (it != infos_.get_mutable_infos()->end())
		{
			(*it)->set_receive_reward(is_receive);
		}
	}

	void agent::save_attendance(int32 day_seq)
	{
		ScopedLock lock(cs_);
		auto it = internal_find_attend_info(day_seq);
		if (it != infos_.get_mutable_infos()->end())
		{
			dbo::attendance::save_attendance_info(player_no_, *(*it));
		}
	}

	std::vector<protocol::attendance_info*>::iterator agent::internal_find_attend_info(int32 day_seq)
	{
		return std::find_if(infos_.get_mutable_infos()->begin(), infos_.get_mutable_infos()->end(),
			[day_seq](const protocol::attendance_info* ai) -> bool
		{
			return day_seq == ai->get_day_seq();
		});
	}


}