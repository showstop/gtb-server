#ifndef __GTB_ASSET_AGENT__
#define __GTB_ASSET_AGENT__

#include <SpringCat/System/System.h>
#include <common/server_consts.h>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <ServerBase/link_base.h>
#include <protocol/player.dc.h>

namespace asset {

	class agent 
	{
	public:
		agent(const player_no_t player_no);
		virtual~agent();

		const protocol::asset_info& get_asset_info();

		bool begin_transaction();
		bool commit();
		void rollback();

		int32 inc_gold(int16 delta);
		int32 inc_diamond(int16 delta);

		int16 inc_quick_ticket(int16 delta);
		int16 inc_grandprix_ticket(int16 delta);

		void inc_gold_immediately(int16 delta);
		void inc_diamond_immediately(int16 delta);
		void inc_quick_ticket_immediately(int16 delta);
		void inc_grandprix_immediately(int16 delta);

		bool load();
		bool save();

	private:
		CriticalSection cs_;

		const player_no_t player_no_;
		protocol::asset_info info_;

		bool is_transaction_;
		protocol::asset_info volatile_info_;
	};
	typedef boost::shared_ptr<agent> agent_ptr_t;

}
#endif