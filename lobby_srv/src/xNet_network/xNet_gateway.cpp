#include "xNet_gateway.h"
#include "xNet_handler.h"
#include <ServerBase/logger.h>
#include <util/log_sender.h>


#if defined(WIN32) || defined(_WIN64)
#define REG_MSG(msgid) xNet_dispatcher_->add(msgid##::static_type_info().id(), &message_dispatch<msgid##_job>)
#else 
#define REG_MSG(msgid) xNet_dispatcher_->add(msgid ::static_type_info().id(), &message_dispatch<msgid _job>)
#endif

namespace xNet {

	gateway::gateway()
		: xNet_socket_(nullptr), xNet_dispatcher_(new dispatcher_t)
	{
		register_handler();
	}

	gateway::~gateway()
	{

	}

	gateway& gateway::instance()
	{
		static gateway g;
		return g;
	}

	bool gateway::start()
	{
		if (false == xNet::connector::instance().start())
		{
			write_fmt(Log::Error, "Couldn't has connection to xNet.");
			return false;
		}

		xNet_socket_ = xNet::connector::instance().create_socket();
		if (nullptr == xNet_socket_)
		{
			write_fmt(Log::Error, "xNet initialized failed.");
			return false;
		}

		xNet_socket_->join("LOBBY");
		xNet_socket_->join("MONITOR");

		xNet_socket_->set_handler(on_received_from_xNet, this);

		return true;
	}

	void gateway::stop()
	{
		if (xNet_socket_)
		{
			xNet_socket_->leave("LOBBY");
			xNet_socket_->leave("MONITOR");

			xNet::connector::instance().destroy_socket(xNet_socket_);
		}

		xNet::connector::instance().stop();
	}

	bool gateway::send(const xNet::address& dest, const SpringCat::Wave::object_base& msg)
	{
		return xNet_socket_->send(dest, msg);
	}

	xNet::socket* gateway::create_socket(uint64 ref_id)
	{
		auto new_sock = xNet::connector::instance().create_socket();
		if (new_sock && ref_id > 0)
		{
			new_sock->set_ref_id(ref_id);
		}
		return new_sock;
	}

	void gateway::destroy_socket(xNet::socket* sock)
	{
		xNet::connector::instance().destroy_socket(sock);
	}

	void gateway::register_handler()
	{
		REG_MSG(protocol::internal_login_req);

		REG_MSG(protocol::internal_create_ps_req);
		REG_MSG(protocol::internal_register_player_ans);
		REG_MSG(protocol::internal_unregister_player_ans);

		REG_MSG(protocol::monitor_data_req);

		REG_MSG(protocol::internal_match_complete_notify);

		REG_MSG(protocol::internal_player_end_game_report_notify);
	}

	void gateway::on_received_from_xNet(const xNet::address& src, const xNet::address& dest, SpringCat::System::StreamPtr data, void* context)
	{
		auto ctx = static_cast<gateway*>(context);
		uint32 msg_id = 0;
		data->Read(&msg_id, sizeof(uint32));

		if (false == ctx->xNet_dispatcher_->dispatch(msg_id, ctx->xNet_socket_, src, data, context))
		{
			write_fmt(Log::Error, "[gateway::acceptor::on_received_from_xNet] Message dispatch failed (src_addr:%s msgid:%d)",
				xNet::address_ext(src).to_string(), msg_id);
			return;
		}
	}

	template <typename THandler>
	void gateway::message_dispatch(xNet::socket* sock, const xNet::address& src, StreamPtr& msg, void* context)
	{
		THandler(sock, src, msg).process();
	}

}
