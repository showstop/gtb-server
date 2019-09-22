#ifndef __GTB_LOBBY_PLAYER_DBO__
#define __GTB_LOBBY_PLAYER_DBO__

#include <ServerBase/sb_define.h>
#include <common/server_consts.h>
#include <protocol/player.dc.h>
#include <protocol/vehicle.dc.h>
#include <protocol/ability.dc.h>
#include <protocol/attendance.dc.h>
#include <protocol/achievement.dc.h>
#include <protocol/daily_mission.dc.h>
#include <protocol/grandprix.dc.h>

namespace dbo {

	struct player
	{
		static bool load_player_profile_info(player_no_t player_no, protocol::player_profile_info& info);
		static bool save_player_profile_info(const protocol::player_profile_info& info);

		static bool save_tutorial_update_progress(player_no_t player_no, const protocol::TutorialProgress progress);

		static bool save_first_vehicle(player_no_t player_no, int32 selected_vehicle_no);
	};

	struct vehicle
	{
		static bool load_vehicle_list(player_no_t player_no, protocol::vehicle_list& infos);
		static bool save_vehicle_info(player_no_t player_no, const protocol::vehicle& info);

		static bool load_selected_vehicle(player_no_t player_no, int32& vehicle_no);
		static bool load_selected_vehicle(player_no_t player_no, protocol::vehicle& info);
		static bool save_selected_vehicle(player_no_t player_no, int32 vehicle_no);

		static bool load_vehicle_stuff_info(player_no_t player_no, protocol::vehicle_stuff& info);
		static bool save_vehicle_stuff_info(player_no_t player_no, int32 stuff_id, int32 quantity);
	};

	struct asset
	{
		static bool load_asset_info(player_no_t player_no, protocol::asset_info& info);
		static bool save_asset_info(player_no_t player_no, const protocol::asset_info& info);
	};

	struct ability
	{
		static bool load_ability_list(player_no_t player_no, protocol::ability_list& infos);
		static bool load_ability_slot_info(player_no_t player_no, protocol::ability_slot& info);
		static bool save_ability_info(player_no_t player_no, const protocol::ability& info);
		static bool save_ability_slot_info(player_no_t player_no, const protocol::ability_slot& info);
	};

	struct attendance
	{
		static bool load_attendance_list(player_no_t player_no, protocol::attendance_list& infos);
		static bool save_attendance_info(player_no_t player_no, const protocol::attendance_info& info);
	};

	struct achievement
	{
		static bool load_achievement_list(player_no_t player_no, protocol::achievement_list& infos);
		static bool save_achievement_info(player_no_t player_no, const protocol::achievement_info& info);
	};

	struct daily_mission
	{
		static bool load_daily_mission_list(player_no_t player_no, protocol::daily_mission_list& infos);
		static bool save_daily_mission_info(player_no_t player_no, const protocol::daily_mission_info& info);
	};

	struct grandprix
	{
		static bool load_grandprix_info(player_no_t player_no, protocol::grandprix_info& info);
		static bool save_grandprix_info(player_no_t player_no, const protocol::grandprix_info& info);
	};

}


#endif