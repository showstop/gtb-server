#include "lobby_server.h"
#include "../env/config.h"
#include "../gc_network/gc_acceptor.h"
#include <ServerBase/logger.h>
#include <util/db_odbc.h>
#include <json/json.h>
#include "../xNet_network/xNet_gateway.h"
#include <util/log_sender.h>
#include "../playserver/ps_manager.h"
#include "../sysutil/system_info_util.h"
#include "../registry/vehicle_registry.h"
#include "../registry/vehicle_parts_registry.h"
#include "../registry/achievement_registry.h"
#include "../registry/config_registry.h"
#include "../registry/daily_mission_registry.h"
#include "../registry/attendance_registry.h"
#include "../registry/ability_registry.h"
#include "../test/unit_test.h"

namespace lobby {

	struct server::impl
	{
		impl()
			: gca_(nullptr), gc_listen_port_(0),
			server_no_(0), server_name_(configurator::instance().get_sys_info().name)
		{

		}

		void init()
		{
			gca_ = new gc::acceptor(public_ip_, gc_listen_port_);
		}

		bool start()
		{
			if (!gca_->start())	return false;

			return true;
		}

		void stop()
		{
			gca_->stop();
		}

		void uninit()
		{
			delete gca_;
			gca_ = nullptr;
		}

	public:
		gc::acceptor* gca_;

		int32 server_no_;
		std::string server_name_;
		std::string domain_;
		std::string public_ip_;
		std::string private_ip_;
		uint16 gc_listen_port_;

		std::pair<stop_event, void*> stop_callback_;

		test_unit tester_;
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
			write_fmt(Log::Error, "load LobbyServer info failed.. check server registry db.");
			return false;
		}

		pimpl_->init();

		if (false == pimpl_->start())
		{
			write_fmt(Log::Error, "gc-acceptor start failed. check listen port..");
			return false;
		}

		ability::registry::instance();
		attendance::registry::instance();
		achievement::registry::instance();
		config::registry::instance();
		daily_mission::registry::instance();
		vehicle::parts::registry::instance();
		vehicle::registry::instance();

		play::server_manager::instance().start(configurator::instance().get_ps_info().ps_listen_port);

		if (false == xNet::gateway::instance().start())
		{
			write_fmt(Log::Error, "Cannot connect to xNet.");
			xNet::gateway::instance().stop();
			return false;
		}

		log_sender::instance().initialize(configurator::instance().get_sys_info().log_server_ip,
			configurator::instance().get_sys_info().log_server_port, pimpl_->server_no_);

		write_fmt(Log::Process, "gc-acceptor started...");
		write_fmt(Log::All, "LobbyServer START successfully...");

		pimpl_->tester_.all();

		return true;
	}

	void server::stop()
	{
		xNet::gateway::instance().stop();

		play::server_manager::instance().stop();

		pimpl_->stop();

		pimpl_->uninit();
		(pimpl_->stop_callback_.first)(pimpl_->stop_callback_.second);

		db::connection_pool::uninit_pool();

		write_fmt(Log::All, "LobbyServer STOP successfully...");
	}

	int32 server::get_server_no() const
	{
		return pimpl_->server_no_;
	}

	const std::string& server::get_server_name() const
	{
		return pimpl_->server_name_;
	}

	void server::get_game_resource_data(protocol::game_monitor_data& data)
	{
		data.set_machine_name(pimpl_->server_name_);

		auto& machine_resource = *data.get_mutable_machine_resource_info();
		auto& game_resource = *data.get_mutable_game_resource_info();

		//TODO

		machine_resource[protocol::HardwareResourceKey_CPU_USAGE] = sysutils::resource_checker::instance().get_cpu_usage();
		machine_resource[protocol::HardwareResourceKey_MEM_USAGE] = sysutils::resource_checker::instance().get_ram_usage();
		machine_resource[protocol::HardwareResourceKey_DISK_USAGE] = sysutils::resource_checker::instance().get_disk_usage();

		game_resource[protocol::GameResourceKey_USER_COUNT] = rand() % 2;
		game_resource[protocol::GameResourceKey_ROOM_COUNT] = rand() % 2;
	}

	std::pair<std::string, uint16> server::get_server_addr() const
	{
		return std::make_pair(pimpl_->domain_, pimpl_->gc_listen_port_);
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

		pstmt->set_string(1, "LOBBY");
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

		pimpl_->domain_ = root["domain"].asString();
		pimpl_->public_ip_ = root["public_ip"].asString();
		pimpl_->private_ip_ = root["private_ip"].asString();
		pimpl_->gc_listen_port_ = static_cast<uint16>(root["gc_listen_port"].asUInt());

		write_fmt(Log::Process, "[server::load_server_info] load server-info success");
		return true;
	}
}