#include "unit_test.h"
#include "../xNet_network/xNet_lobby_handler.h"
#include <ServerBase/logger.h>
#include <util/db_odbc.h>
#include "../env/config.h"
#include "../player/player.h"
#include "../playserver/ps_manager.h"

test_unit::test_unit()
{

}

test_unit::~test_unit()
{

}

void test_unit::all()
{
	//internal_player_end_game_report_notify();
	//player_level_test();
}

void test_unit::internal_player_end_game_report_notify()
{
	//play::server_manager::instance().test();

	xNet::address test_addr;
	StreamPtr msg(new Stream());
	protocol::internal_player_end_game_report_notify noti;
	noti.set_final_rank(1);
	noti.set_first_reward_stuff_id(1111);
	noti.set_second_reward_stuff_id(2222);
	noti.set_inc_exp(100);
	noti.set_inc_game_money(150);
	noti.set_is_giveup(true);
	noti.set_mode(protocol::GameMode_QUICK);
	noti.set_player_no(1);
	noti.set_vehicle_no(300111);
	noti.set_play_data(protocol::record_data_key_ACQ_GAME_MONEY, 150);
	noti.serialize(*msg);
	protocol::internal_player_end_game_report_notify_job job(nullptr, test_addr, msg);

	job.process();
}

void test_unit::player_level_test()
{
	player::object obj(8);

	obj.inc_exp(200);

}
