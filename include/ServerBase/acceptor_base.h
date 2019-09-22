#ifndef __K_SB_ACCEPTOR__
#define __K_SB_ACCEPTOR__

#include <ServerBase/serverbase.h>
#include <SpringCat/SpringCat.h>
#include "link_base.h"
#include <ServerBase/protocol.h>


namespace network {

	class acceptor_base_io_handler_itf;
	class SB_EXPORT_API acceptor_base
	{
	public:
		acceptor_base(SpringCat::System::Threading::ThreadPool* thread_pool, const char* ip, unsigned short port, bool port_reuse = false, bool use_cipher = true);
		virtual ~acceptor_base();

		bool start();
		bool stop();

		void set_pending_buff_size(int size);
		void set_pending_count(int count);

		void set_handler(acceptor_base_io_handler_itf* handler);
	private:
		struct impl;
		impl* pimpl_;
	};

}


#endif