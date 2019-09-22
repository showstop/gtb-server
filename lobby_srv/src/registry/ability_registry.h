#ifndef __GTB_ABILITY_REGISTRY__
#define __GTB_ABILITY_REGISTRY__

#include <serverbase/sb_define.h>

namespace ability {

	struct registry_info
	{
		int16 unlock_level_;
		int32 price_diamond_;
		int16 max_level_;
		std::map<int16, int32> upgrade_gold_;		// level, gold
	};

	class registry : private SpringCat::System::TL::NonCopyable
	{
		friend class agent;
	private:
		registry();

	public:
		~registry();

		static registry& instance();
		bool find(int32 ability_id, ability::registry_info& info);

	private:
		bool load_ability_registry();

	private:
		std::map<int32, registry_info> ability_infos_;		// ability_id
	};

}


#endif