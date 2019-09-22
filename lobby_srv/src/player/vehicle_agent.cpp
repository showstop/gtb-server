#include "vehicle_agent.h"
#include "player_dbo.h"
#include <common/exception.h>
#include "../registry/vehicle_registry.h"
#include "../registry/config_registry.h"

namespace vehicle {

	agent::agent(player_no_t player_no)
		: player_no_(player_no), selected_vehicle_no_(0)
	{
		vehicles_ = vehicle::registry::instance().vehicles_;
	}

	agent::~agent()
	{

	}

	bool agent::load()
	{
		ScopedLock lock(cs_);

		protocol::vehicle_list possession_list;
		if (false == dbo::vehicle::load_vehicle_list(player_no_, possession_list))
			return false;

		if (false == dbo::vehicle::load_selected_vehicle(player_no_, selected_vehicle_no_))
			return false;

		for (auto& v : *vehicles_.get_mutable_infos())
		{
			auto vehicle_no = v->get_vehicle_no();
			auto it = std::find_if(possession_list.get_infos().begin(),
				possession_list.get_infos().end(),
				[vehicle_no](const protocol::vehicle* info) -> bool
			{
				return vehicle_no == info->get_vehicle_no();
			});

			if (it != possession_list.get_infos().end())
				*v = *(*it);
		}

		return true;
	}

	bool agent::save(const protocol::vehicle& info)
	{
		ScopedLock lock(cs_);
		return dbo::vehicle::save_vehicle_info(player_no_, info);
	}

	int16 agent::get_possess_count() const
	{
		ScopedLock lock(cs_);
		auto count = std::count_if(vehicles_.get_infos().begin(), vehicles_.get_infos().end(),
			[](const protocol::vehicle* v) -> bool
		{
			return v->get_level() != protocol::vehicle_level_LOCKED;
		});

		return static_cast<int16>(count);
	}

	error::code_t agent::acquire_card(int32 vehicle_no, int32 quantity)
	{
		ScopedLock lock(cs_);

		auto it = internal_find(vehicle_no);
		if (it == vehicles_.get_mutable_infos()->end())
			return error::vehicle::has_no_vehicle;

		auto current_quantity = (*it)->get_hold_card();
		(*it)->set_hold_card(current_quantity + quantity);

		save(*(*it));
		return error::common::success;
	}

	error::code_t agent::select(int32 vehicle_no)
	{
		ScopedLock lock(cs_);

		auto it = internal_find(vehicle_no);
		if (it == vehicles_.get_mutable_infos()->end())
			return error::vehicle::has_no_vehicle;

		selected_vehicle_no_ = vehicle_no;
		dbo::vehicle::save_selected_vehicle(player_no_, selected_vehicle_no_);

		return error::common::success;
	}

	error::code_t agent::upgrade(int32 vehicle_no)
	{
		ScopedLock lock(cs_);

		auto it = internal_find(vehicle_no);
		if (it == vehicles_.get_mutable_infos()->end())
			return error::vehicle::not_exist_vehicle;

		auto current_level = (*it)->get_level();
		if (current_level == protocol::vehicle_level_S_CLASS)
			return error::vehicle::already_max_vehicle_level;

		protocol::vehicle_level new_level = (protocol::vehicle_level)((int32)current_level + 1);
		(*it)->set_level(new_level);

		auto& skills = *(*it)->get_mutable_skills();
		for (auto& s : skills)
			s->set_skill_lv((int)new_level);

		save(*(*it));
		return error::common::success;
	}

	error::code_t agent::parts_tuning(int32 vehicle_no, protocol::vehicle_parts_id parts_id)
	{
		ScopedLock lock(cs_);
		auto it = internal_find(vehicle_no);
		if (it == vehicles_.get_mutable_infos()->end())
			return error::vehicle::has_no_vehicle;

		auto parts_it = std::find_if((*it)->get_mutable_parts()->begin(), (*it)->get_mutable_parts()->end(),
			[parts_id](protocol::vehicle_parts* p) -> bool
		{
			return p->get_parts_id() == parts_id;
		}
		);

		if (parts_it != (*it)->get_mutable_parts()->end())
		{
			auto current_level = (*parts_it)->get_level();

			(*parts_it)->set_level(current_level + 1);
		}
		save(*(*it));
		return error::common::success;
	}

	error::code_t agent::acquire_stuff(int32 stuff_id, int32 quantity)
	{
		if (false == config::registry::instance().is_valid_stuff_id(stuff_id))
			return error::lobby::invalid_stuff_id;

		ScopedLock lock(cs_);
		auto& stuff_map = *stuffs_.get_mutable_stuff_info();

		stuff_map[stuff_id] += quantity;

		dbo::vehicle::save_vehicle_stuff_info(player_no_, stuff_id, quantity);
		return error::common::success;
	}


	std::vector<protocol::vehicle*>::iterator agent::internal_find(int32 vehicle_no)
	{
		return std::find_if(vehicles_.get_mutable_infos()->begin(), vehicles_.get_mutable_infos()->end(),
			[vehicle_no](const protocol::vehicle* v) -> bool
		{
			return vehicle_no == v->get_vehicle_no();
		}
		);
	}

	void agent::get_stuffs(protocol::vehicle_stuff& info)
	{
		ScopedLock lock(cs_);
		info = stuffs_;
	}

	void agent::get_vehicle(int32 vehicle_no, protocol::vehicle& info)
	{
		ScopedLock lock(cs_);
		auto it = internal_find(vehicle_no);

		info = *(*it);
	}

	void agent::get_vehicles(protocol::vehicle_list& infos)
	{
		ScopedLock lock(cs_);
		infos = vehicles_;
	}
}