#include "asset_agent.h"
#include "player_dbo.h"
#include <common/exception.h>

namespace asset {

	agent::agent(player_no_t player_no)
		: player_no_(player_no), is_transaction_(false)
	{

	}

	agent::~agent()
	{

	}

	bool agent::load()
	{
		ScopedLock lock(cs_);
		return dbo::asset::load_asset_info(player_no_, info_);
	}

	bool agent::save()
	{
		ScopedLock lock(cs_);
		return dbo::asset::save_asset_info(player_no_, info_);
	}

	const protocol::asset_info& agent::get_asset_info()
	{
		ScopedLock lock(cs_);
		if(is_transaction_)
			return volatile_info_;
		
		return info_;
	}

	bool agent::begin_transaction()
	{
		ScopedLock lock(cs_);
		if (is_transaction_)	return false;

		volatile_info_ = info_;

		is_transaction_ = true;

		return true;
	}

	bool agent::commit()
	{
		ScopedLock lock(cs_);
		info_ = volatile_info_;

		is_transaction_ = false;
		dbo::asset::save_asset_info(player_no_, info_);
		return true;
	}

	void agent::rollback()
	{
		ScopedLock lock(cs_);

		volatile_info_.clear();
		is_transaction_ = false;
	}

	int32 agent::inc_gold(int16 delta)
	{
		volatile_info_.set_gold(volatile_info_.get_gold() + delta);
		return volatile_info_.get_gold();
	}

	int32 agent::inc_diamond(int16 delta)
	{
		volatile_info_.set_diamond(volatile_info_.get_diamond() + delta);
		return volatile_info_.get_diamond();
	}

	int16 agent::inc_quick_ticket(int16 delta)
	{
		volatile_info_.set_quick_ticket(volatile_info_.get_quick_ticket() + delta);
		return volatile_info_.get_quick_ticket();
	}

	int16 agent::inc_grandprix_ticket(int16 delta)
	{
		volatile_info_.set_grandprix_ticket(volatile_info_.get_grandprix_ticket() + delta);
		return volatile_info_.get_grandprix_ticket();
	}

	void agent::inc_gold_immediately(int16 delta)
	{
		info_.set_gold(info_.get_gold() + delta);
	}

	void agent::inc_diamond_immediately(int16 delta)
	{
		info_.set_diamond(info_.get_diamond() + delta);
	}

	void agent::inc_quick_ticket_immediately(int16 delta)
	{
		info_.set_quick_ticket(info_.get_quick_ticket() + delta);
	}

	void agent::inc_grandprix_immediately(int16 delta)
	{
		info_.set_grandprix_ticket(info_.get_grandprix_ticket() + delta);
	}
}