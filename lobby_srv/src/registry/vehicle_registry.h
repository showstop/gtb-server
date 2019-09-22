#ifndef __GTB_VEHICLE_REGISTRY__
#define __GTB_VEHICLE_REGISTRY__

#include <serverbase/sb_define.h>
#include <protocol/vehicle.dc.h>

namespace dbo {
	struct vehicle;
}
namespace vehicle {

	class registry : private SpringCat::System::TL::NonCopyable
	{
		friend class agent;
		friend struct dbo::vehicle;
	private:
		registry();

	public:
		~registry();

		static registry& instance();
		bool find(int32 vehicle_no, protocol::vehicle& info);

	private:
		bool load_vehicle_info();

	private:
		protocol::vehicle_list vehicles_;
	};

}


#endif