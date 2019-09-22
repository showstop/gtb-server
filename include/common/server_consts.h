#ifndef __TR_SERVER_CONSTS__
#define __TR_SERVER_CONSTS__

#include <ServerBase/sb_define.h>

typedef int32 item_no_t;
typedef int16 item_prop_key_t;
typedef int32 item_prop_value_t;

typedef uint64 player_no_t;
typedef std::string player_uuid_t;

const player_no_t INVALID_PLAYER_NO = 0;
const player_no_t OPERATOR_PLAYER_NO = 0xFFFFFFFFFFFFFFFF;
const int32 MAX_PLAYER_COUNT = 4;

typedef std::vector<player_no_t> player_no_list_t;

static const char* XNET_AUTH_NAME = "AUTH";
static const char* XNET_LOBBY_NAME = "LOBBY";
static const char* XNET_MATCH_NAME = "MATCH";


namespace service {

	enum action_code
	{
		GS_PLAYER_COUNT = 1,
		MMS_PLAYER_COUNT = 2,

		SYSTEM_ACTION_CODE_END = 99,

		NEW_PLAYER = 100,
		LOGIN_PLAYER = 101,
		LOGOUT_PLAYER = 102,
		CONNECTION_CLOSED = 103,
		RECONNECT = 104,
		QUIT_PLAYER,

		CHARGE_DIAMOND = 201,
		CHARGE_DIAMOND_CONFIRM,
		CHARGE_GAME_MONEY,
		CHARGE_GAME_TICKET,
		BUY_INGAME_ITEM,
		BUY_PARTS,
		BUY_CHARACTERISTIC,
		PARTS_STRENGTHEN,
		CHARACTERISTIC_STRENGTHEN,
		SELL_CHARACTERISTIC,

		PARTS_PROP_CHANGE,
		LEVEL_PROP_CHANGE,

		ATTACH_PARTS,
		ATTACH_CHARACTERISTICS,

		BEGIN_MATCH = 301,
		CANCEL_MATCH = 302,
		START_GAME = 303,
		END_GAME = 304,

		SEND_GAME_INVITATION = 331,
	};

}

#endif