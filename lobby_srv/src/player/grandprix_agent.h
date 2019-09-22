#ifndef __GTB_GRANDPRIX_AGENT__
#define __GTB_GRANDPRIX_AGENT__

#include <SpringCat/System/System.h>
#include <common/server_consts.h>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <ServerBase/link_base.h>
#include <protocol/grandprix.dc.h>

namespace grandprix {

	class agent
	{
	public:
		agent(const player_no_t player_no);
		virtual~agent();

		bool load();

		void get_grandprix_info(protocol::grandprix_info& info);

	private:

		const player_no_t player_no_;
		protocol::grandprix_info info_;
	};
	typedef boost::shared_ptr<agent> agent_ptr_t;

}

#endif