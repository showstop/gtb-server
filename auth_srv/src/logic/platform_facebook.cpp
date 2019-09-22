#include "platform_facebook.h"
#include <util/web_client.h>
#include <json/json.h>
#include <ServerBase/logger.h>

#include <boost/lexical_cast.hpp>

namespace platform {

	const std::string BASE_URL = "https://graph.facebook.com/";

	facebook::facebook()
	{
	}

	facebook::~facebook()
	{

	}


	error::code_t facebook::get_player_login_info(const std::string& access_token, login_info& extracted_info) const
	{
		web::client wc;
		wc.set_base_url(BASE_URL);
		wc.set_script("me");
		wc.add_param("access_token", access_token);

		if (false == wc.send_request_get())
			return error::common::network_error;

		const std::string& res = wc.get_result();
		Json::Value root;
		Json::Reader reader;
		if (false == reader.parse(res, root, false))
		{
			write_fmt(Log::Error, "[facebook::get_player_uuid] json parsing error! (%s)", res.c_str());
			return error::auth::invalid_return_data;
		}

		extracted_info.uuid_ = root["id"].asString();

		// todo remove below codes.
		extracted_info.nation_code_ = 80;
		extracted_info.os_type_ = 2;
		extracted_info.push_token_ = "test";
		return error::common::success;
	}

	void facebook::get_player_friend_list(const std::string& access_token, std::vector<player_no_t>& friends_list) const
	{
		/*web::client wc;
		wc.set_base_url(BASE_URL);
		wc.set_script("me/friends");
		wc.add_param("access_token", access_token);

		if (false == wc.send_request_get())
			return;

		const std::string& res = wc.get_result();

		Json::Value root;
		Json::Reader reader;
		if (false == reader.parse(res, root, false))
			return;

		Json::Value friends = root["data"];

		for (auto it = friends.begin(); it != friends.end(); ++it)
		{
			auto friend_uuid = boost::lexical_cast<player_uuid_t>((*it)["id"].asString());
			friends_uuid_list.push_back(friend_uuid);
		}*/
	}

}