#ifndef __GTB_ACHIEVEMENT_AGENT__
#define __GTB_ACHIEVEMENT_AGENT__

#include <SpringCat/System/System.h>
#include <common/server_consts.h>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <ServerBase/link_base.h>
#include <protocol/achievement.dc.h>

namespace achievement {

	class agent
	{
	public:
		agent(const player_no_t player_no);
		virtual~agent();

		bool load();

		void get_achievement_list(protocol::achievement_list& infos);

		void set_progress(int32 achievement_id, int32 progress);
		void set_received(int32 achievement_id, bool is_receive);

		void save_achievement(int32 achievement_id);

	private:
		std::vector<protocol::achievement_info*>::iterator internal_find_info(int32 achievement_id);

	private:
		CriticalSection cs_;

		const player_no_t player_no_;
		protocol::achievement_list infos_;
	};
	typedef boost::shared_ptr<agent> agent_ptr_t;

}

#endif