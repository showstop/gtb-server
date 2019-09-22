#include "log_sender.h"
#include "../env/config.h"
#include <protocol/internal_log.dc.h>
#include <ServerBase/logger.h>
#include <util/timer_queue.h>

log_sender::log_sender() 
	: conn_(new network::connector_base(&thread_pool_, false)), 
	server_no_(0), thread_pool_(1), connected_(false)
{
		
}

log_sender::~log_sender() 
{
	//util::timer_queue::instance().remove_timer(connection_check_timer_id_);
	conn_->disconnect();
}

// static
void log_sender::on_connection_check(uint32 timer_id, void* context)
{
	log_sender* ls = static_cast<log_sender*>(context);
		
	ScopedLock lock(ls->cs_);
	if(!ls->connected_)
	{
		if(ls->conn_->connect(ls->log_server_addr_.first.c_str(), ls->log_server_addr_.second))
			ls->connected_ = true;
	}
}

// static 
log_sender& log_sender::instance()
{
	static log_sender ls;
	return ls;
}

bool log_sender::initialize(const std::string& ip, uint16 port, int32 server_no)
{
	log_server_addr_ = std::make_pair(ip, port);

	if (conn_->connect(ip.c_str(), port))
		connected_ = true;

	connection_check_timer_id_ = util::timer_queue::instance().add_timer(2000, true, &on_connection_check, this);
	conn_->set_handler(this);

	return connection_check_timer_id_ != 0;
}

void log_sender::write(service::action_code ac, player_no_t player_no, const Json::Value& json_obj)
{
	Json::FastWriter writer;
	auto json_str = writer.write(json_obj);
	send_log("%d\t%d\t%lld\t%s", (int)ac, server_no_, player_no, json_str.c_str());
}

void log_sender::send_log(const char* format, ...)
{
	char buffer[8192] = {0, };
	va_list args;

	va_start(args, format);
	FUNC_VSPRINTF_SAFE(buffer, sizeof(buffer) / sizeof(buffer[0]), format, args);
	va_end(args);

	protocol::service_log log_msg;
	log_msg.set_log_msg(buffer);
	bool ret = conn_->send(log_msg);

	if(!ret)
		Log(Log::Service) << buffer << "\t SEND_FAIL";
	else
		Log(Log::Service) << buffer;
}

void log_sender::on_closed()
{
	ScopedLock lock(cs_);
	connected_ = false;
}
