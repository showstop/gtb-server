#ifndef __GTB_ATTENDANCE_AGENT__
#define __GTB_ATTENDANCE_AGENT__

#include <SpringCat/System/System.h>
#include <common/server_consts.h>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <ServerBase/link_base.h>
#include <protocol/attendance.dc.h>

namespace attendance {

	class agent
	{
	public:
		agent(const player_no_t player_no);
		virtual~agent();

		bool load();

		void get_attendance_list(protocol::attendance_list& infos);

		void set_complete(int32 day_seq, bool is_complete);
		void set_received(int32 day_seq, bool is_receive);

		void save_attendance(int32 day_seq);

	private:
		std::vector<protocol::attendance_info*>::iterator internal_find_attend_info(int32 day_seq);

	private:
		CriticalSection cs_;

		const player_no_t player_no_;
		protocol::attendance_list infos_;
	};
	typedef boost::shared_ptr<agent> agent_ptr_t;

}

#endif