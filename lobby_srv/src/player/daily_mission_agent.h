#ifndef __GTB_DAILY_MISSION_AGENT__
#define __GTB_DAILY_MISSION_AGENT__

#include <SpringCat/System/System.h>
#include <common/server_consts.h>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <ServerBase/link_base.h>
#include <protocol/daily_mission.dc.h>

namespace daily_mission {

	class agent
	{
	public:
		agent(const player_no_t player_no);
		virtual~agent();

		bool load();

		void get_mission_list(protocol::daily_mission_list& infos);

		void set_progress(int32 mission_id, int32 progress);
		void set_received(int32 mission_id, bool is_receive);

		void save_mission(int32 mission_id);

	private:
		std::vector<protocol::daily_mission_info*>::iterator internal_find_info(int32 mission_id);

	private:
		CriticalSection cs_;

		const player_no_t player_no_;
		protocol::daily_mission_list infos_;
	};
	typedef boost::shared_ptr<agent> agent_ptr_t;

}

#endif