#ifndef __GTB_ATTENDANCE_REGISTRY__
#define __GTB_ATTENDANCE_REGISTRY__

#include <serverbase/sb_define.h>
#include <protocol/attendance.dc.h>

namespace dbo {
	struct attendance;
}
namespace attendance {

	class registry : private SpringCat::System::TL::NonCopyable
	{
		friend class agent;
		friend struct dbo::attendance;
	private:
		registry();

	public:
		~registry();

		static registry& instance();
		bool find(int32 dayseq, protocol::attendance_info& info);

	private:
		bool load_attendance_registry();

	private:
		protocol::attendance_list infos_;
	};

}


#endif