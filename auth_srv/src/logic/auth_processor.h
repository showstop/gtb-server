#ifndef __GTB_AUTH_PROCESSOR__
#define __GTB_AUTH_PROCESSOR__

#include <ServerBase/sb_define.h>
#include <ServerBase/link_base.h>
#include <protocol/auth.dc.h>

namespace auth
{
	class processor
	{
	private:
		processor();
		virtual ~processor();

	public:
		static processor& instance();
		bool add_request(const protocol::login_req& req, const network::link_ptr_t& link);

	private:
		bool process_login(const protocol::login_req& req, const network::link_ptr_t& link);

	private:
		ThreadPool thread_pool_;
	};

}



#endif