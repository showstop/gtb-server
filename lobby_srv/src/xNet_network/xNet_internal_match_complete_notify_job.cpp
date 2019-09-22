#include "xNet_match_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include "../player/repository.h"
#include "../logic/lobby_server.h"
#include <protocol/lobby.dc.h>

namespace protocol {

	bool internal_match_complete_notify_job::process()
	{
		internal_match_complete_notify noti;
		if (!noti.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[internal_match_complete_notify_job::process()] internal_match_complete_notify deserialize failed.");
			return false;
		}

		auto dest_player_no = noti.get_dest_player_no();
		auto player_obj = player::repository::instance().find(dest_player_no);
		if (nullptr == player_obj)
		{
			write_fmt(Log::Error, "[internal_match_complete_notify_job::process()] cannot find player-obj(player_no:%lld).", dest_player_no);
			return false;
		}

		// todo dec gold. using match item info

		match_complete_notify noti_to_gc;
		noti_to_gc.set_result(noti.get_result());
		noti_to_gc.set_mode(noti.get_mode());
		noti_to_gc.set_use_standalone(noti.get_use_standalone());
		noti_to_gc.set_map_no(noti.get_map_no());
		*noti_to_gc.get_mutable_ps_addr() = *noti.get_ps_addr();

		for (auto p : noti.get_player_list())
		{
			auto player_no = p.first;
			player::repository::instance().load_player_profile_info(player_no, *noti_to_gc.insert_profiles(player_no));
			player::repository::instance().load_selected_vehicle_info(player_no, *noti_to_gc.insert_vehicles(player_no));
			player::repository::instance().load_ability_slot_info(player_no, *noti_to_gc.insert_equipped_ability(player_no));
			player::repository::instance().load_ability_list(player_no, *noti_to_gc.insert_abilities(player_no));
		}

		player_obj->get_client_link()->send(noti_to_gc);
		write_fmt(Log::Process, "[internal_match_complete_notify_job::process()] send match_complete_notify. (player_no:%lld)", dest_player_no);

		return true;
	}
}