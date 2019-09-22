#ifndef __GTB_ABILITY_AGENT__
#define __GTB_ABILITY_AGENT__

#include <SpringCat/System/System.h>
#include <common/server_consts.h>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <ServerBase/link_base.h>
#include <protocol/ability.dc.h>
#include <common/error_code.h>

namespace ability {

	class agent
	{
	public:
		agent(const player_no_t player_no);
		virtual~agent();

		bool load();

		void get_ability(int32 ability_id, protocol::ability& info);
		void get_ability_list(protocol::ability_list& infos);
		void get_ability_slot(protocol::ability_slot& slot);

		error::code_t slot_open(protocol::ability_slot_no slot_no);
		error::code_t equip(protocol::ability_slot_no slot_no, int32 ability_id);
		error::code_t acquire(int32 ability_id);

	private:
		bool save_ability_info(const protocol::ability& info);
		bool save_ability_slot_info(const protocol::ability_slot& info);

		std::vector<protocol::ability*>::iterator internal_find_ability(int32 ability_id);

	private:
		CriticalSection cs_;

		const player_no_t player_no_;
		protocol::ability_list abilities_;
		protocol::ability_slot slots_;
	};
	typedef boost::shared_ptr<agent> agent_ptr_t;

}
#endif