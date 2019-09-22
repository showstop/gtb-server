#ifndef __TR_ERROR_CODE__
#define __TR_ERROR_CODE__

namespace error {

	typedef const short code_t;

	namespace common {

		code_t success = 1;
		
		code_t internal_db_error = 1001;
		code_t network_error = 1002;
		code_t expired_session = 1003;
		code_t too_many_player = 1004;
		code_t mismatch_version = 1005;
		code_t maintenance = 1006;
		code_t no_data = 1007;
	}

	namespace auth {

		code_t invalid_return_data = 2001;
		code_t invalid_access_token = 2002;
		code_t inappropriate_nick = 2003;
		code_t another_user_already_using_nick = 2004;
		code_t not_exist_player_no = 2005;
		code_t blocked_player = 2006;
	}

	namespace play {
		code_t not_exist_ps_info = 3001;
	}

	namespace lobby {

		code_t invalid_service_request = 10001;
		code_t invalid_session_id = 10002;
		code_t not_exist_player = 10003;
		code_t already_complete_tutorial = 10004;
		code_t execute_ps_failed = 10005;
		code_t already_received_first_car = 10006;
		code_t invalid_stuff_id = 10007;
	}

	namespace vehicle {
		code_t has_no_vehicle = 11001;
		code_t already_max_vehicle_level = 11002;
		code_t not_exist_vehicle = 11003;
	}

	namespace ability {
		code_t has_no_ability = 13001;
	}

	namespace item {
		code_t not_exist_item_no = 30001;
		code_t invalid_item_property = 30002;
		code_t insufficient_gold = 30003;
		code_t insufficient_diamond = 30004;
		code_t have_no_item = 30005;
		code_t invalid_parts_slot = 30006;
		code_t no_sales_item = 30007;
		code_t higher_level_required = 30008;
		code_t already_have_item = 30009;
		code_t item_is_already_max_level = 30010;
		code_t item_strengthen_is_failed = 30011;
		code_t not_on_conditions = 30012;
		code_t slot_is_already_opened = 30013;
		code_t cannot_sell_attached_item = 30014;
		code_t all_item_is_attached = 30015;
		code_t exclusive_item_attached = 30016;
		code_t cannot_resell_item = 30017;
		code_t exclusive_item_cannot_buy = 30018;
	}


}




#endif