#include "gc_acceptor.h"
#include <ServerBase/logger.h>
#include <util/helper_util.h>
#include "../env/config.h"
#include "gc_handler.h"

#if defined(WIN32) || defined(_WIN64)
#define REG_MSG(msgid) dispatcher_->add(msgid##::static_type_info().id(), &message_dispatch<msgid##_job>)
#else 
#define REG_MSG(msgid) dispatcher_->add(msgid ::static_type_info().id(), &message_dispatch<msgid _job>)
#endif

namespace gc {

	acceptor::acceptor(const std::string& ip, uint16 port)
		: dispatcher_(new dispatcher_t),
		msgQ_(new protocol::message_queue(configurator::instance().get_gc_info().working_thread_count)),
		thread_pool_(new ThreadPool(configurator::instance().get_gc_info().net_thread_count)),
		acceptor_(NULL)
	{
		boost::scoped_ptr<network::acceptor_base> ab(new network::acceptor_base(
			thread_pool_.get(),
			nullptr,
			port,
			true));
		ab->set_handler(this);

		acceptor_.swap(ab);
		register_handler();

		write_fmt(Log::Process, "[gc::acceptor] gc-acceptor constructed (binded ip : %s, listen port : %d)", ip.c_str(), port);
	}

	acceptor::~acceptor()
	{
		stop();
		write_fmt(Log::Process, "[gc::acceptor] gc-acceptor destructed");
	}

	void acceptor::register_handler()
	{
		REG_MSG(protocol::session_key_req);
		REG_MSG(protocol::login_req);
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
		// set link type
		link->set_link_type(network::link_base::GAME_CLIENT);

		write_fmt(Log::Process | Log::Debug, "[gc::acceptor::on_opened] accept link (%s)", helper::get_remote_address(link).c_str());
	}

	void acceptor::on_closed(const network::link_ptr_t& link)
	{
		auto client_addr = helper::get_remote_address(link);

		write_fmt(Log::Debug | Log::Process, "[gc::acceptor::on_closed] (%s)", client_addr.c_str());

		Json::Value log_obj;
		log_obj["CLIENT_ADDRESS"] = client_addr;
		//log_sender::instance().write(service::CONNECTION_CLOSED, link->get_ref_id(), log_obj);

		//msgQ_->add(new protocol::gc_close_event_job(link, StreamPtr()));
	}

	void acceptor::on_received(const network::link_ptr_t& link, StreamPtr source_packet,
		const protocol::packet_header& header, StreamPtr payload)
	{
		write_fmt(Log::Debug, "[gc::acceptor::on_received] enter");

		if (false == dispatcher_->dispatch(header.msgid, link, payload, this))
		{
			write_fmt(Log::Error, "[gc::acceptor::on_received] Message dispatch failed (IP:%s msgid:%d)",
				helper::get_remote_address(link).c_str(), header.msgid);
			return;
		}
		write_fmt(Log::Debug, "[gc::acceptor::on_received] (%s - msgid:%d, packet_size:%d)",
			helper::get_remote_address(link).c_str(),
			header.msgid,
			payload->GetLength());

		int cps = 0x0F;
		if (false == link->update_timestamp(cps))
		{
			write_fmt(Log::Error, "[gc::acceptor::on_receive] exceed limit CPS (max_cps:%d, player_no:%lld, client_address:%s)",
				cps, link->get_ref_id(), helper::get_remote_address(link).c_str());

			/*action_desc_t desc;
			desc["CONFIG_CPS"] = mkstr(cps);
			write_service_log(game_log::LLS_OVER_CPS, link, desc, 0);*/

			link->close();
		}
		write_fmt(Log::Debug, "[gc::acceptor::on_received] leave");
	}

	// static 
	template <typename THandler>
	void acceptor::message_dispatch(const network::link_ptr_t& link, StreamPtr& msg, void* context)
	{
		(static_cast<acceptor*>(context))->msgQ_->add(new THandler(link, msg));
	}

}