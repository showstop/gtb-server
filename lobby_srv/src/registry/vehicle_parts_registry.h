
#ifndef __GTB_VEHICLE_PARTS_REGISTRY__
#define __GTB_VEHICLE_PARTS_REGISTRY__

#include <serverbase/sb_define.h>
#include <protocol/vehicle.dc.h>

namespace vehicle {

	namespace parts {

		class registry : private SpringCat::System::TL::NonCopyable
		{
		private:
			registry();

		public:
			~registry();

			static registry& instance();

			bool get_need_stuff_list(protocol::vehicle_parts_id parts_id, int16 parts_level, std::map<int32, int32>& need_stuff);

		private:
			bool load_vehicle_parts_tuning_info();

		private:
			typedef std::pair<protocol::vehicle_parts_id, int16> parts_key_t;		// parts_id, parts_lv
			typedef std::map<int32, int32> stuff_quantity_map_t;					// stuff_id, need_quantity

			std::map<parts_key_t, stuff_quantity_map_t> infos_;

		};

	}

}


#endif
