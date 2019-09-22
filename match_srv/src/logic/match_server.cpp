#include "match_server.h"
#include "../env/config.h"
#include <ServerBase/logger.h>
#include <util/db_odbc.h>
#include <json/json.h>
#include "../xNet_network/xNet_gateway.h"
#include <util/log_sender.h>
#include <util/random_util.h>

namespace match {

	struct server::impl
	{
		impl()
			: server_no_(0), server_name_(configurator::instance().get_sys_info().name)
		{

		}

	public:
		int32 server_no_;
		std::string server_name_;

		std::pair<stop_event, void*> stop_callback_;

		std::vector<int32> quick_match_track_;
		std::vector<int32> grandprix_track_;
	};

	server::server()
		: pimpl_(new server::impl)
	{

	}

	server::~server()
	{

	}

	// static 
	server& server::instance()
	{
		static server s;
		return s;
	}

	void server::set_on_stop_event(const stop_event& event, void* context)
	{
		pimpl_->stop_callback_ = std::make_pair(event, context);
	}

	bool server::start()
	{
		if (pimpl_->server_name_.empty())
		{
			write_fmt(Log::Error, "[server::start] server name is empty!");
			return false;
		}

		// db connection initialize
		char err_msg[512] = { 0, };
		const env::config::db_info& db_config = configurator::instance().get_db_info();
		if (false == db::connection_pool::init_pool(
			1,
			db_config.game_conn_str.c_str(),
			reinterpret_cast<char*>(err_msg)
		))
		{
			Log(Log::Error) << "db connection failed. check your db connection info...  ";
			Log(Log::Error) << err_msg;
			return false;
		}
		Log(Log::Process) << "db-connection initialized...";

		if (false == load_server_info())
		{
			write_fmt(Log::Error, "load MatchServer info failed.. check server registry db.");
			return false;
		}

		load_track_info("quick_match_track_list", pimpl_->quick_match_track_);
		load_track_info("grandprix_track_list", pimpl_->grandprix_track_);

		if (false == xNet::gateway::instance().start())
		{
			write_fmt(Log::Error, "Cannot connect to xNet.");
			xNet::gateway::instance().stop();
			return false;
		}

		log_sender::instance().initialize(configurator::instance().get_sys_info().log_server_ip,
			configurator::instance().get_sys_info().log_server_port, pimpl_->server_no_);

		write_fmt(Log::Process, "gc-acceptor started...");
		write_fmt(Log::All, "MatchServer START successfully...");

		return true;
	}

	void server::stop()
	{
		xNet::gateway::instance().stop();

		(pimpl_->stop_callback_.first)(pimpl_->stop_callback_.second);

		db::connection_pool::uninit_pool();

		write_fmt(Log::All, "MatchServer STOP successfully...");
	}

	int32 server::get_server_no() const
	{
		return pimpl_->server_no_;
	}

	int32 server::get_track_no(protocol::GameMode mode)
	{
		if (mode == protocol::GameMode_QUICK)
		{
			auto len = pimpl_->quick_match_track_.size();
			auto pick = rand_helper::gen_probability_number(0, len - 1);
			return pimpl_->quick_match_track_[pick];
		}
		else
		{
			auto len = pimpl_->grandprix_track_.size();
			auto pick = rand_helper::gen_probability_number(0, len - 1);
			return pimpl_->grandprix_track_[pick];
		}
		return -1;
	}

	bool server::load_server_info()
	{
		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("select server_opt from z_server_registry where server_type=? and server_name=?;");
		if (false == cp.prepare(query, pstmt))
		{
			Log(Log::Error) << "[server::load_server_info] query prepare failed.";
			return false;
		}

		pstmt->set_string(1, "MATCH");
		pstmt->set_string(2, pimpl_->server_name_);

		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[server::load_server_info] query execute failed...(%s)", pstmt->get_error_str());
			return false;
		}

		if (false == pstmt->fetch())
		{
			write_fmt(Log::Error, "cannot find server-info (%s)", pimpl_->server_name_.c_str());
			return false;
		}

		std::string server_opt = pstmt->get_string(1);

		Json::Value root;
		Json::Reader reader;
		if (false == reader.parse(server_opt, root, false))
		{
			write_fmt(Log::Error, "[server::load_server_info] json-cfg parsing error.");
			return false;
		}

		write_fmt(Log::Process, "[server::load_server_info] load server-info success");
		return true;
	}

	bool server::load_track_info(const std::string& key, std::vector<int32>& track)
	{
		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call load_game_config(?);");
		if (false == cp.prepare(query, pstmt))
		{
			Log(Log::Error) << "[server::load_track_info] query prepare failed.";
			return false;
		}

		pstmt->set_string(1, key);

		if (false == cp.execute(pstmt))
		{
			write_fmt(Log::Error, "[server::load_track_info] query execute failed...(%s)", pstmt->get_error_str());
			return false;
		}

		if (false == pstmt->fetch())
		{
			write_fmt(Log::Error, "[server::load_track_info] cannot find key(%s).", key.c_str());
			return false;
		}

		Json::Value root;
		Json::Reader reader;
		std::string json_result = pstmt->get_string(1);
		if (false == reader.parse(json_result, root))
		{
			write_fmt(Log::Error, "[server::load_track_info] invalid json.");
			return false;
		}

		for (auto it = root.begin(); it != root.end(); ++it)
		{
			track.push_back((*it).asInt());
		}
		return true;
	}

}