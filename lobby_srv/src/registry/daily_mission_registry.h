#ifndef __GTB_DAILY_MISSION_REGISTRY__
#define __GTB_DAILY_MISSION_REGISTRY__

#include <serverbase/sb_define.h>
#include <protocol/daily_mission.dc.h>

namespace dbo {
	struct daily_mission;
}
namespace daily_mission {

	class registry : private SpringCat::System::TL::NonCopyable
	{
		friend class agent;
		friend struct dbo::daily_mission;
	private:
		registry();

	public:
		~registry();

		static registry& instance();
		bool find(int32 mission_id, protocol::daily_mission_info& info);

	private:
		bool load_daily_mission_registry();

	private:
		protocol::daily_mission_list infos_;
	};

}


#endif