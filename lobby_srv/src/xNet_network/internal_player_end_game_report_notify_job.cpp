#include "xNet_lobby_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/db_odbc.h>
#include "../player/repository.h"
#include "../logic/lobby_server.h"

namespace protocol {

	namespace dbo {

		bool save_quick_match_give_up(player_no_t player_no, int32 vehicle_no)
		{
			db::connection_pool cp;
			db::prepared_statement_ptr pstmt;

			std::string query("call save_quick_play_acc_giveup(?, ?);");
			if (false == cp.prepare(query, pstmt))
			{
				write_fmt(Log::Error, "[save_quick_match_give_up] query prepare failed.");
				return false;
			}

			pstmt->set_int64(1, player_no);
			pstmt->set_int(2, vehicle_no);

			if (false == cp.execute(pstmt))
			{
				write_fmt(Log::Error, "[save_quick_match_give_up] query execute failed..(error:%s)", pstmt->get_error_str());
				return false;
			}

			return true;
		}

		bool save_quick_match_report_data(player_no_t player_no, int32 vehicle_no, int32 final_rank, std::map<protocol::record_data_key, int32>& play_data)
		{
			db::connection_pool cp;
			db::prepared_statement_ptr pstmt;

			std::string query("call save_quick_play_acc(");
			const int PARAM_COUNT = 12;
			for (int i = 0; i < PARAM_COUNT; i++)
			{
				if ((i + 1) == PARAM_COUNT)
					query.append("?);");
				else
					query.append("?,");
			}
			if (false == cp.prepare(query, pstmt))
			{
				write_fmt(Log::Error, "[save_quick_match_report_data] query prepare failed.");
				return false;
			}

			volatile int idx = 0;

			pstmt->set_int64(++idx, player_no);
			pstmt->set_int(++idx, vehicle_no);
			pstmt->set_int(++idx, final_rank);

			pstmt->set_int(++idx, play_data[protocol::record_data_key_KILL]);
			pstmt->set_int(++idx, play_data[protocol::record_data_key_DEATH]);
			pstmt->set_int(++idx, play_data[protocol::record_data_key_ACQ_INGAME_ITEM]);
			pstmt->set_int(++idx, play_data[protocol::record_data_key_USE_INGAME_ITEM]);
			pstmt->set_int(++idx, play_data[protocol::record_data_key_QUICK_MATCH_PLAY_SEC]);
			pstmt->set_int(++idx, play_data[protocol::record_data_key_BUMP_ATTACK]);
			pstmt->set_int(++idx, play_data[protocol::record_data_key_ACQ_GAME_MONEY]);
			pstmt->set_int(++idx, play_data[protocol::record_data_key_DEAL_DAMAGE]);
			pstmt->set_int(++idx, play_data[protocol::record_data_key_TAKE_DAMAGE]);

			if (false == cp.execute(pstmt))
			{
				write_fmt(Log::Error, "[save_quick_match_report_data] query execute failed..(error:%s)", pstmt->get_error_str());
				return false;
			}

			return true;
		}

	}

	bool internal_player_end_game_report_notify_job::process()
	{
		internal_player_end_game_report_notify noti;
		if (!noti.deserialize(*msg_))
		{
			write_fmt(Log::Error, "[internal_player_end_game_report_notify_job::process()] internal_player_end_game_report_notify deserialize failed.");
			return false;
		}

		auto player_no = noti.get_player_no();
		auto vehicle_no = noti.get_vehicle_no();
		if (noti.get_is_giveup())
		{
			dbo::save_quick_match_give_up(player_no, vehicle_no);

			write_fmt(Log::Process, "[internal_player_end_game_report_notify_job::process()] give up match.(player_no:%lld, mode:%d, vehicle_no:%d)",
				player_no, noti.get_mode(), noti.get_vehicle_no());
		}
		else
		{
			dbo::save_quick_match_report_data(player_no, vehicle_no, noti.get_final_rank(), *noti.get_mutable_play_data());

			auto player_obj = player::repository::instance().find(player_no);
			if (nullptr == player_obj)
			{
				write_fmt(Log::Error, "[internal_player_end_game_report_notify_job::process()] cannot find player-obj(player_no:%lld)",
					player_no);
				return false;
			}

			player_obj->get_vehicle_agent()->acquire_stuff(noti.get_first_reward_stuff_id(), 1);
			player_obj->get_vehicle_agent()->acquire_stuff(noti.get_second_reward_stuff_id(), 1);

			player_obj->get_asset_agent()->inc_gold_immediately(noti.get_inc_game_money());
			player_obj->get_asset_agent()->save();

			player_obj->inc_exp(noti.get_inc_exp());

			write_fmt(Log::Process, "[internal_player_end_game_report_notify_job::process()] complete match."
				"(player_no:%lld, mode:%d, vehicle_no:%d, rank:%d)",
				player_no, noti.get_mode(), noti.get_vehicle_no(), noti.get_final_rank());
		}

		return true;
	}


}

