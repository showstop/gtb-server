#include "platform_manager.h"

#include "platform_facebook.h"
#include <util/web_client.h>

#include "../env/config.h"

namespace platform {

	manager::manager()
	{
		web::client::global_init();

		platforms_[protocol::LoginType_FACEBOOK] = new facebook();
	}

	manager::~manager()
	{
		web::client::global_cleanup();
	}

	manager& manager::instance()
	{
		static manager m;
		return m;
	}

	error::code_t manager::get_player_login_info(protocol::LoginType login_type, const std::string& access_token, login_info& extracted_info) const
	{
		auto it = platforms_.find(login_type);
		if (it == platforms_.end())
			return error::auth::invalid_access_token;

		return it->second->get_player_login_info(access_token, extracted_info);
	}

	void manager::get_player_friend_list(protocol::LoginType login_type, const std::string& access_token, std::vector<player_no_t>& friends_uuid_list) const
	{
		auto it = platforms_.find(login_type);
		if (it != platforms_.end())
			it->second->get_player_friend_list(access_token, friends_uuid_list);
	}

	void manager::send_payment_info(const player_no_t& player_no, market_platform_type market_type, const std::string& price, int bill_seq_no)
	{
		//platform_->send_payment_info(player_uuid, market_type, price, bill_seq_no);
	}


}