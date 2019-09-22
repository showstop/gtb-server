#if defined(__linux__)

#include "system_info_util.h"
#include <ServerBase/logger.h>

namespace sysutils {

	namespace helper {

		

	}

	struct resource_checker::impl
	{
		uint64 prev_process_time_;
		uint64 prev_timestamp_;


		impl()
		{
			
		}

		~impl()
		{
			
		}

		int32 get_cpu_usage()
		{
			return 0;		// todo
		}
	};

	resource_checker::resource_checker()
		: pimpl_(new impl())
	{

	}
	
	resource_checker::~resource_checker()
	{

	}

	int32 resource_checker::get_cpu_usage()
	{
		return pimpl_->get_cpu_usage();
	}

}


#endif
