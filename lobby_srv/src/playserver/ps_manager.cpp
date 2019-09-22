#include "ps_manager.h"
#include <sstream>
#include <ServerBase/logger.h>
#include <util/timer_queue.h>
#include <util/db_odbc.h>

#include "process_util.h"
#include "../logic/lobby_server.h"
#include "../env/config.h"
#include "../ps_network/ps_acceptor.h"

#include <json/json.h>

namespace play {

	server_manager::server_manager()
		: current_port_index_(configurator::instance().get_ps_info().begin_port_range), zombie_ps_detector_timer_id_(0)
	{
		zombie_ps_detector_timer_id_ = util::timer_queue::instance().add_timer(10 * 1000, true,
			&server_manager::on_zombie_ps_detect, this);

	}

	server_manager::~server_manager()
	{
		util::timer_queue::instance().remove_timer(zombie_ps_detector_timer_id_);
	}

	// static 
	server_manager& server_manager::instance()
	{
		static server_manager sm;
		return sm;
	}

	bool server_manager::start(uint16 port)
	{
		acceptor_.reset(new ps::acceptor("0.0.0.0", port));

		return acceptor_->start();
	}

	void server_manager::stop()
	{
		acceptor_->stop();
	}

	void server_manager::test()
	{
	}

	server_agent_ptr_t server_manager::execute_play_server(protocol::GameMode mode, int32 track_no)
	{
		ScopedLock lock(cs_);

		uint16 assigned_port_no = internal_next_port_no();
		uint16 ps_listen_port = configurator::instance().get_ps_info().ps_listen_port;
		bool use_daemon = configurator::instance().get_ps_info().use_daemon;
		auto full_path = configurator::instance().get_ps_info().play_server_path;

		std::ostringstream os;
		os << full_path;
		if (use_daemon)		os << " -batchmode";
		else os << " -playserver";

		os << " -ps_port=" << assigned_port_no
			<< " -mode=" << mode << " -track=" << track_no << " -ls_port=" << ps_listen_port;

		uint32 pid = 0;
		if (false == execute(os.str(), &pid))
		{
			write_fmt(Log::Error, "[server_manager::execute_play_server()] execute failed. (path:%s)", os.str().c_str());
			return server_agent_ptr_t();
		}

		server_agent_ptr_t agent_obj(new server_agent(assigned_port_no, pid));
		sa_map_.insert(std::make_pair(assigned_port_no, agent_obj));

		write_fmt(Log::Process, "[server_manager::execute_play_server()] execute NEW PlayServer (Port:%d)", assigned_port_no);

		return agent_obj;
	}

	void server_manager::kill_play_server(uint16 ps_no)
	{
		ScopedLock lock(cs_);
		internal_kill_play_server(ps_no);
	}

	void server_manager::internal_kill_play_server(uint16 ps_no)
	{
		auto it = sa_map_.find(ps_no);
		if (it == sa_map_.end())
			return;

		kill_process(it->second->get_pid());
		sa_map_.erase(ps_no);
	}

	bool server_manager::find(uint16 ps_no, server_agent_ptr_t& sa_obj)
	{
		ScopedLock lock(cs_);

		auto it = sa_map_.find(ps_no);
		if (it == sa_map_.end())
			return false;

		sa_obj = it->second;
		return true;
	}

	void server_manager::set_ps_link(uint16 ps_no, const network::link_ptr_t& link)
	{
		ScopedLock lock(cs_);

		auto it = sa_map_.find(ps_no);
		if (it != sa_map_.end())
			it->second->set_link(link);
	}

	uint16 server_manager::internal_next_port_no()
	{
		if (current_port_index_ == configurator::instance().get_ps_info().end_port_range)
		{
			current_port_index_ = configurator::instance().get_ps_info().begin_port_range;
		}

		do
		{
			current_port_index_++;
		} while (sa_map_.find(current_port_index_) != sa_map_.end());

		return current_port_index_;
	}

	// static 
	void server_manager::on_zombie_ps_detect(unsigned int timer_id, void* context)
	{
		server_manager* ctx = static_cast<server_manager*>(context);

		ScopedLock lock(ctx->cs_);

		std::vector<uint16> dead_ps_no_list;
		for (auto v : ctx->sa_map_)
		{
			if ((GET_TICK() - v.second->get_timestamp()) > (uint32)configurator::instance().get_ps_info().time_to_judge_zombie_ps)
			{
				dead_ps_no_list.push_back(v.first);
			}
		}

		for (auto ps_no : dead_ps_no_list)
			ctx->internal_kill_play_server(ps_no);

		write_fmt(Log::Debug, "[server_manager::on_zombie_ps_detect()] kill zombie ps...(count:%d)", dead_ps_no_list.size());
	}

}