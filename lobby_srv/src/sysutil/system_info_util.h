#ifndef __TR_SYSUTILS__
#define __TR_SYSUTILS__

#include <ServerBase/sb_define.h>
#include <boost/scoped_ptr.hpp>

namespace sysutils {

	class resource_checker
	{
	private:
		resource_checker();
		virtual ~resource_checker();

	public:
		static resource_checker& instance()
		{
			static resource_checker rc;
			return rc;
		}
		int32 get_cpu_usage();
		int32 get_ram_usage();
		int32 get_disk_usage();

	private:
		struct impl;
		boost::scoped_ptr<impl> pimpl_;
	};
}

#endif