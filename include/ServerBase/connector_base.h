#ifndef __K_SB_CONNECTOR__
#define __K_SB_CONNECTOR__

#include <ServerBase/serverbase.h>
#include <SpringCat/SpringCat.h>
#include "link_base.h"
#include <ServerBase/protocol.h>

namespace network {

	class connector_base_io_handler_itf;
	class SB_EXPORT_API connector_base
	{
	public:
		connector_base(SpringCat::System::Threading::ThreadPool* thread_pool, bool use_cipher=true);
		virtual ~connector_base();

		bool connect(const char* ip, unsigned short port, unsigned short timeout = 1000);
		void disconnect();
		
		void set_pending_buff_size(int size);
		void set_pending_count(int count);

		void set_handler(connector_base_io_handler_itf* handler);

		bool send(const SpringCat::Wave::object_base& msg);

		void get_link_ptr(network::link_ptr_t& link_ptr) const;

	private:
		struct impl;
		impl* pimpl_;
	};

}

#endif