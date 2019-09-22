#ifndef __TR_PLATFORM_FACEBOOK__
#define __TR_PLATFORM_FACEBOOK__

#include <ServerBase/sb_define.h>
#include "platform_manager.h"

namespace web {
	class client;
}

namespace platform {

	class facebook : public manager_interface
	{
	public:
		facebook();
		virtual ~facebook();

		virtual error::code_t get_player_login_info(const std::string& access_token, login_info& extracted_info) const;
		virtual void get_player_friend_list(const std::string& access_token, std::vector<player_no_t>& friends_list) const;

	};

}

#endif