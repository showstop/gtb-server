#include "ps_acceptor.h"
#include <ServerBase/logger.h>
#include <util/helper_util.h>
#include "../env/config.h"
#include "ps_handler.h"
#include "../playserver/ps_manager.h"

#if defined(WIN32) || defined(_WIN64)
#define REG_MSG(msgid) dispatcher_->add(msgid##::static_type_info().id(), &message_dispatch<msgid##_job>)
#else 
#define REG_MSG(msgid) dispatcher_->add(msgid ::static_type_info().id(), &message_dispatch<msgid _job>)
#endif

namespace ps {

	acceptor::acceptor(const std::string& ip, uint16 port)
		: dispatcher_(new dispatcher_t),
		msgQ_(new protocol::message_queue(1)),
		thread_pool_(new ThreadPool(1)),
		acceptor_(NULL)
	{
		boost::scoped_ptr<network::acceptor_base> ab(new network::acceptor_base(
			thread_pool_.get(),
			nullptr,
			port,
			false));
		ab->set_handler(this);

		acceptor_.swap(ab);
		register_handler();

		write_fmt(Log::Process, "[ps::acceptor] gc-acceptor constructed (binded ip : %s, listen port : %d)", ip.c_str(), port);
	}

	acceptor::~acceptor()
	{
		stop();
		write_fmt(Log::Process, "[ps::acceptor] gc-acceptor destructed");
	}

	void acceptor::register_handler()
	{
		REG_MSG(protocol::internal_register_ps_req);
		REG_MSG(protocol::internal_start_game_ans);
		REG_MSG(protocol::internal_end_game_req);
		REG_MSG(protocol::internal_player_end_game_report_req);
	}

	bool acceptor::start()
	{
		return acceptor_->start();
	}

	bool acceptor::stop()
	{
		return acceptor_->stop();
	}

	void acceptor::on_opened(const network::link_ptr_t& link)
	{
		write_fmt(Log::Process | Log::Debug, "[ps::acceptor::on_opened] accept link (%s)", helper::get_remote_address(link).c_str());
	}

	void acceptor::on_closed(const network::link_ptr_t& link)
	{
		play::server_manager::instance().kill_play_server(static_cast<uint16>(link->get_ref_id()));
		write_fmt(Log::Debug | Log::Process, "[ps::acceptor::on_closed] (%s)", helper::get_remote_address(link).c_str());
	}

	void acceptor::on_received(const network::link_ptr_t& link, StreamPtr source_packet,
		const protocol::packet_header& header, StreamPtr payload)
	{
		write_fmt(Log::Debug, "[ps::acceptor::on_received] enter");

		if (false == dispatcher_->dispatch(header.msgid, link, payload, this))
		{
			write_fmt(Log::Error, "[ps::acceptor::on_received] Message dispatch failed (IP:%s msgid:%d)",
				helper::get_remote_address(link).c_str(), header.msgid);
			return;
		}
		write_fmt(Log::Debug, "[ps::acceptor::on_received] (%s - msgid:%d, packet_size:%d)",
			helper::get_remote_address(link).c_str(),
			header.msgid,
			payload->GetLength());

		write_fmt(Log::Debug, "[ps::acceptor::on_received] leave");
	}

	// static 
	template <typename THandler>
	void acceptor::message_dispatch(const network::link_ptr_t& link, StreamPtr& msg, void* context)
	{
		(static_cast<acceptor*>(context))->msgQ_->add(new THandler(link, msg));
	}

}