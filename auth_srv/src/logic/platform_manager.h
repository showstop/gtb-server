#ifndef __TR_PLATFORM_MANAGER__
#define __TR_PLATFORM_MANAGER__

#include <ServerBase/sb_define.h>
#include <common/server_consts.h>
#include <common/error_code.h>
#include <protocol/common_def.dc.h>

namespace platform {

	enum market_platform_type
	{
		ANDROID = 1,
		IOS = 2,
	};

	struct login_info
	{
		protocol::LoginType login_type_;
		player_uuid_t uuid_;
		int16 nation_code_;
		std::string push_token_;
		int16 os_type_;
	};

	class manager_interface
	{
	public:
		virtual error::code_t get_player_login_info(const std::string& access_token, login_info& extracted_info) const = 0;
		virtual void get_player_friend_list(const std::string& access_token, std::vector<player_no_t>& friends_list) const = 0;

		virtual void send_payment_info(const player_no_t& player_no, market_platform_type market_type, const std::string& price, int bill_seq_no) { };
	};

	class manager
	{
	private:
		manager();

	public:
		virtual ~manager();

		static manager& instance();

		error::code_t get_player_login_info(protocol::LoginType login_type, const std::string& access_token, login_info& extracted_info) const;
		void get_player_friend_list(protocol::LoginType login_type, const std::string& access_token, std::vector<player_no_t>& friends_list) const;

		void send_payment_info(const player_no_t& player_no, market_platform_type market_type, const std::string& price, int bill_seq_no);

	private:
		std::map<protocol::LoginType, manager_interface*> platforms_;
	};



}

#endif