#include "ability_agent.h"
#include "player_dbo.h"
#include <common/exception.h>

namespace ability {

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
		return dbo::ability::load_ability_list(player_no_, abilities_);
	}

	void agent::get_ability(int32 ability_id, protocol::ability& info)
	{
		ScopedLock lock(cs_);

		auto it = internal_find_ability(ability_id);
		if (it != abilities_.get_mutable_infos()->end())
		{
			info = *(*it);
		}
	}

	void agent::get_ability_list(protocol::ability_list& infos)
	{
		ScopedLock lock(cs_);
		infos = abilities_;
	}

	void agent::get_ability_slot(protocol::ability_slot& slot)
	{
		ScopedLock lock(cs_);
		slot = slots_;
	}

	error::code_t agent::slot_open(protocol::ability_slot_no slot_no)
	{
		ScopedLock lock(cs_);

		auto& slots = *slots_.get_mutable_slots();
		slots[slot_no] = 0;

		return error::common::success;
	}

	error::code_t agent::equip(protocol::ability_slot_no slot_no, int32 ability_id)
	{
		ScopedLock lock(cs_);
		auto it = internal_find_ability(ability_id);
		if (it == abilities_.get_mutable_infos()->end())
			return error::ability::has_no_ability;

		auto& slots = *slots_.get_mutable_slots();
		slots[slot_no] = ability_id;

		return error::common::success;
	}

	error::code_t agent::acquire(int32 ability_id)
	{
		ScopedLock lock(cs_);

		auto it = internal_find_ability(ability_id);
		if (it == abilities_.get_mutable_infos()->end())
		{
			auto& new_info = *abilities_.add_infos();
			new_info.set_ability_id(ability_id);
		}
		else
		{
			auto cur_lv = (*it)->get_level();
			(*it)->set_level(cur_lv + 1);
		}

		return error::common::success;
	}

	bool agent::save_ability_info(const protocol::ability& info)
	{
		ScopedLock lock(cs_);
		return dbo::ability::save_ability_info(player_no_, info);
	}

	bool agent::save_ability_slot_info(const protocol::ability_slot& info)
	{
		ScopedLock lock(cs_);
		return dbo::ability::save_ability_slot_info(player_no_, info);
	}

	std::vector<protocol::ability*>::iterator agent::internal_find_ability(int32 ability_id)
	{
		auto& infos = *abilities_.get_mutable_infos();

		return std::find_if(infos.begin(), infos.end(),
			[ability_id](protocol::ability* a) -> bool
		{
			return ability_id == a->get_ability_id();
		});
	}


}