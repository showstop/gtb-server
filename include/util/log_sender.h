#ifndef __GTB_LOG_SENDER__
#define __GTB_LOG_SENDER__

#include <ServerBase/sb_define.h>
#include <ServerBase/connector_base.h>
#include <ServerBase/io_handler.h>
#include <json/json.h>
#include <common/server_consts.h>

	class log_sender : public network::connector_base_io_handler_itf
	{
	private:
		log_sender();
		virtual ~log_sender();

	public:
		static log_sender& instance();

		bool initialize(const std::string& ip, uint16 port, int32 server_no);

		void write(service::action_code ac, player_no_t player_no, const Json::Value& json_obj);
	private:
		void send_log(const char* format, ...);

		virtual void on_closed();
		virtual void on_received(
			SpringCat::System::StreamPtr source_packet, const protocol::packet_header& header, SpringCat::System::StreamPtr payload) {}
		
	private:
		CriticalSection cs_;
		ThreadPool thread_pool_;
		std::auto_ptr<network::connector_base> conn_;
		bool connected_;
		std::pair<std::string, uint16> log_server_addr_;
		int32 server_no_;

		uint32 connection_check_timer_id_;
		static void on_connection_check(uint32, void*);
	};

#endif

