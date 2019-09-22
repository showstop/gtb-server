#ifndef __GTB_ACHIEVEMENT_REGISTRY__
#define __GTB_ACHIEVEMENT_REGISTRY__

#include <serverbase/sb_define.h>
#include <protocol/achievement.dc.h>

namespace dbo {
	struct achievement;
}
namespace achievement {

	class registry : private SpringCat::System::TL::NonCopyable
	{
		friend class agent;
		friend struct dbo::achievement;
	private:
		registry();

	public:
		~registry();

		static registry& instance();
		bool find(int32 achievement_id, protocol::achievement_info& info);

	private:
		bool load_achievement_registry();

	private:
		protocol::achievement_list infos_;
	};

}


#endif