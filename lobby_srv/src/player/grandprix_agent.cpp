#include "grandprix_agent.h"
#include "player_dbo.h"
#include <common/exception.h>

namespace grandprix {
	
	agent::agent(const player_no_t player_no)
		: player_no_(player_no)
	{

	}

	agent::~agent()
	{

	}

	bool agent::load()
	{
		return dbo::grandprix::load_grandprix_info(player_no_, info_);
	}

	void agent::get_grandprix_info(protocol::grandprix_info& info)
	{
		info_ = info;
	}

}