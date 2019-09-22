#ifndef __GTB_VEHICLE_AGENT__
#define __GTB_VEHICLE_AGENT__

#include <SpringCat/System/System.h>
#include <common/server_consts.h>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <ServerBase/link_base.h>
#include <protocol/vehicle.dc.h>
#include <common/error_code.h>

namespace vehicle {

	class agent
	{
	public:
		agent(const player_no_t player_no);
		virtual~agent();

		bool load();
		bool save(const protocol::vehicle& info);

		int16 get_possess_count() const;

		error::code_t acquire_card(int32 vehicle_no, int32 quantity);
		error::code_t select(int32 vehicle_no);
		error::code_t upgrade(int32 vehicle_no);
		
		error::code_t parts_tuning(int32 vehicle_no, protocol::vehicle_parts_id parts_id);
		error::code_t acquire_stuff(int32 stuff_id, int32 quantity);

		void get_stuffs(protocol::vehicle_stuff& info);
		void get_vehicle(int32 vehicle_no, protocol::vehicle& info);
		void get_vehicles(protocol::vehicle_list& infos);
		int32 get_selected() const { return selected_vehicle_no_; }

	private:
		std::vector<protocol::vehicle*>::iterator internal_find(int32 vehicle_no);

	private:
		mutable CriticalSection cs_;

		const player_no_t player_no_;
		protocol::vehicle_list vehicles_;
		protocol::vehicle_stuff stuffs_;
		int32 selected_vehicle_no_;
	};
	typedef boost::shared_ptr<agent> agent_ptr_t;

}

#endif