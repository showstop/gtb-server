#include "auth_processor.h"
#include "../env/config.h"
#include <common/error_code.h>
#include <util/db_odbc.h>
#include <util/helper_util.h>
#include <ServerBase/logger.h>
#include <ServerBase/server_crypto.h>
#include "platform_manager.h"
#include <util/log_sender.h>
#include <protocol/internal_as_ls.dc.h>
#include "../xNet_network/xNet_gateway.h"
#include "../gc_network/gc_link_table.h"

namespace auth {

	namespace dbo {

		bool create_player(const platform::login_info& player_login_info, player_no_t& player_no)
		{
			db::connection_pool cp;
			db::prepared_statement_ptr pstmt;

			const std::string query("call create_player(?, ?, ?, ?, ?);");

			if (false == cp.prepare(query, pstmt))
			{
				write_fmt(Log::Error, "[login_req::create_player] prepare failed.");
				return false;
			}

			volatile int idx = 0;
			pstmt->set_int(++idx, static_cast<int>(player_login_info.login_type_));
			pstmt->set_string(++idx, player_login_info.uuid_);
			pstmt->set_int(++idx, player_login_info.nation_code_);
			pstmt->set_string(++idx, player_login_info.push_token_);
			pstmt->set_int(++idx, player_login_info.os_type_);

			if (false == cp.execute(pstmt))
			{
				write_fmt(Log::Error, "[login_req::create_player] execute failed...(%s), (player_uuid:%s)",
					pstmt->get_error_str(), player_login_info.uuid_.c_str());
				return false;
			}

			if (false == pstmt->fetch())
				return false;

			player_no = pstmt->get_int64(1);

			return player_no > 0;
		}

		player_no_t get_player_no_by_player_uuid(protocol::LoginType login_type, const player_uuid_t& uuid)
		{
			db::connection_pool cp;
			db::prepared_statement_ptr pstmt;

			const std::string query("call get_player_no_by_player_uuid(?, ?);");

			if (false == cp.prepare(query, pstmt))
			{
				write_fmt(Log::Error, "[login_req::get_player_no_by_player_uuid] prepare failed.");
				return false;
			}

			volatile int idx = 0;
			pstmt->set_int(++idx, static_cast<int>(login_type));
			pstmt->set_string(++idx, uuid);

			if (false == cp.execute(pstmt))
			{
				write_fmt(Log::Error, "[login_req::get_player_no_by_player_uuid] execute failed...(%s), (player_uuid:%s)",
					pstmt->get_error_str(), uuid.c_str());
				return false;
			}

			if (false == pstmt->fetch())
				return false;

			return pstmt->get_int64(1);
		}

		int32 check_player_status(player_no_t player_no, const platform::login_info& info)
		{
			db::connection_pool cp;
			db::prepared_statement_ptr pstmt;

			const std::string query("call check_player_status(?, ?, ?);");
			if (false == cp.prepare(query, pstmt))
			{
				write_fmt(Log::Error, "[login_req::check_player_status] prepare failed.");
				return false;
			}

			volatile int idx = 0;
			pstmt->set_int64(++idx, player_no);
			pstmt->set_string(++idx, info.push_token_);
			pstmt->set_int(++idx, info.os_type_);

			if (false == cp.execute(pstmt))
			{
				write_fmt(Log::Error, "[login_req::check_player_status] execute failed...(%s), (player_no:%lld)",
					pstmt->get_error_str(), player_no);
				return false;
			}

			if (false == pstmt->fetch())
				return false;

			return pstmt->get_int(1);		// player status
		}
	}

	namespace helper {

		bool send_notify_to_lobby_server(player_no_t player_no, byte* key, byte* iv)
		{
			protocol::internal_login_req req;
			req.set_player_no(player_no);
			
			req.get_mutable_key()->assign(16, 0);
			req.get_mutable_iv()->assign(16, 0);
			memcpy(&(*req.get_mutable_key())[0], key, crypto::CRYPTO_LEN);
			memcpy(&(*req.get_mutable_iv())[0], iv, crypto::CRYPTO_LEN);

			xNet::address_ext dest;
			dest.set_type(xNet::ANYCAST);
			dest.set_region_code(xNet::GLOBAL_REGION_CODE);
			dest.set_group_name(XNET_LOBBY_NAME, static_cast<int>(strlen(XNET_LOBBY_NAME)));

			return ::xNet::gateway::instance().send(dest.to_address(), req);
		}

	}

	processor::processor()
		: thread_pool_(configurator::instance().get_sys_info().auth_proc_thread_count)
	{}

	processor::~processor()
	{

	}

	processor& processor::instance()
	{
		static processor ap;
		return ap;
	}

	bool processor::add_request(const protocol::login_req& req, const network::link_ptr_t& link)
	{
		return thread_pool_.QueueWorkItem(
			[this, req, link]() -> void
		{
			if (false == process_login(req, link))
				return;
		}
		);
	}

	bool processor::process_login(const protocol::login_req& req, const network::link_ptr_t& link)
	{
		Json::Value log_obj;

		protocol::login_ans ans;
		ans.set_result(error::common::success);

		log_obj["CLIENT_ADDRESS"] = ::helper::get_remote_address(link);
		log_obj["ACCESS_TOKEN"] = req.get_acc_token();

		platform::login_info player_login_info;
		if (req.get_login_type() != protocol::LoginType_GUEST)
		{
			player_login_info.login_type_ = req.get_login_type();
			auto errcode = platform::manager::instance().get_player_login_info(req.get_login_type(), req.get_acc_token(), player_login_info);
			if (errcode != error::common::success)
			{
				write_fmt(Log::Error, "[auth_processor::process_login::process()] invalid access token (error_code:%d, access_token:%s, client_address:%s)",
					errcode, req.get_acc_token().c_str(), ::helper::get_remote_address(link).c_str());
				link->close();

				log_obj["RESULT_CODE"] = errcode;
				log_obj["RESULT_DESC"] = "Invalid Player UUID";
				log_sender::instance().write(service::LOGIN_PLAYER, link->get_ref_id(), log_obj);

				ans.set_result(errcode);
				return link->send(ans);
			}
		}
		else
		{
			player_login_info.uuid_ = "";
			log_obj["IS_GUEST"] = true;
			write_fmt(Log::Debug, "[auth_processor::process_login] GUEST LOGIN.");
		}

		// todo get player_uuid from redis server.
		auto player_no = dbo::get_player_no_by_player_uuid(player_login_info.login_type_, player_login_info.uuid_);
		write_fmt(Log::Debug, "[auth_processor::process_login] login player_no(%d).", player_no);

		log_obj["OS_TYPE"] = player_login_info.os_type_;
		bool is_new_player = false;
		if (player_no != INVALID_PLAYER_NO)
		{
			auto status = dbo::check_player_status(player_no, player_login_info);
			write_fmt(Log::Debug, "[auth_processor::process_login] check status (%d).", status);
			if (0 == status)
			{
				is_new_player = true;
			}
			else if (error::common::success != status)
			{
				ans.set_result(error::auth::blocked_player);
				link->send(ans);
				return false;
			}
		}

		if (is_new_player || player_no == INVALID_PLAYER_NO)
		{
			is_new_player = true;
			bool res = dbo::create_player(player_login_info, player_no);

			Json::Value log_obj;
			log_obj["PLAYER_NO"] = (Json::Value::UInt64)player_no;
			log_obj["RESULT_CODE"] = res;
			log_sender::instance().write(service::NEW_PLAYER, player_no, log_obj);

			if (false == res)
			{
				ans.set_result(error::common::internal_db_error);
				link->send(ans);
				return false;
			}

			write_fmt(Log::Debug, "[login_req::create_player] create new Player.");
		}

		log_obj["player_no"] = (Json::Value::UInt64)player_no;
		link->set_ref_id(player_no);

		byte k[crypto::CRYPTO_LEN], i[crypto::CRYPTO_LEN];
		link->get_session_key(k, i);

		gc::link_table::instance().add(link, player_no);
		helper::send_notify_to_lobby_server(player_no, k, i);

		log_sender::instance().write(service::LOGIN_PLAYER, player_no, log_obj);
		return true;
	}

}