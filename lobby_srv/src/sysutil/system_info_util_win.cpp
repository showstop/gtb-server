#if defined(_WIN32) || defined(_WIN64)

#include "system_info_util.h"
#include "wmi.hpp"
#include <windows.h>

#include <ServerBase/logger.h>
#include <util/random_util.h>

namespace sysutils {

	namespace helper {

		unsigned __int64 atoui64(const char *szUnsignedInt) {
			return _strtoui64(szUnsignedInt, NULL, 10);
		}

		inline std::wstring mbs_to_wcs(const std::string& str)
		{
			wchar_t ret[1024] = {0, };
			MultiByteToWideChar(CP_ACP, 0, str.c_str(), static_cast<int>(str.length()+1), ret, sizeof(ret));
			return std::wstring(ret);
		}

		inline std::string wcs_to_mbs(const std::wstring& str)
		{
			char ret[1024] = {0, };
			int len = WideCharToMultiByte(CP_ACP, 0, str.c_str(), static_cast<int>(str.length()+1), ret, sizeof(ret), NULL, NULL);
			return std::string(ret);
		}

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
			Wmi wmi;
			Wmi::RowSet rs1;
			wmi.connect();

			if (true == wmi.getClassProperties(L"Win32_PerfRawData_PerfOS_Processor", rs1))
            {
				auto total_cpu_index = rs1.size() - 1;

                if (prev_process_time_ == 0 || prev_timestamp_ == 0)
                {
					prev_process_time_ = helper::atoui64(helper::wcs_to_mbs(rs1[total_cpu_index][L"PercentProcessorTime"]).c_str());
					prev_timestamp_ = helper::atoui64(helper::wcs_to_mbs(rs1[total_cpu_index][L"Timestamp_Sys100NS"]).c_str());
                }

                char sTemp[MAX_PATH + 1] = {0,};

                // Last one is Total Processor
                uint64 process_time = helper::atoui64(helper::wcs_to_mbs(rs1[total_cpu_index][L"PercentProcessorTime"]).c_str());
                uint64 timestamp = helper::atoui64(helper::wcs_to_mbs(rs1[total_cpu_index][L"Timestamp_Sys100NS"]).c_str());

                uint64 cpu_uage = 0;
                if (prev_timestamp_ > 0 && prev_process_time_ > 0 && timestamp > prev_timestamp_)
                {
                    cpu_uage = 100 - ((process_time - prev_process_time_) * 100 / (timestamp - prev_timestamp_));
                    if (cpu_uage > 100)
                    {
                        cpu_uage = 100;
                    }
                }
                prev_process_time_ = process_time;
                prev_timestamp_ = timestamp;
				write_fmt(Log::Debug, "cpu_usage : %d", cpu_uage);
				return static_cast<int32>(cpu_uage);
            }
			return -1;
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

	int32 resource_checker::get_ram_usage()
	{
		// TODO
		return rand_helper::gen_probability_number(28, 31);
	}

	int32 resource_checker::get_disk_usage()
	{
		// TODO
		return 9;
	}

}


#endif