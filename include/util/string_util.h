#ifndef __K_STR_UTIL__
#define __K_STR_UTIL__

#include <time.h>
#include <cctype>

namespace util
{
	const short MAX_FIELD_LEN = 1024;
	
	inline std::string convert_to_utf8(const std::string& str)
	{
		if(str.length() > MAX_FIELD_LEN)
		{
			*const_cast<std::string*>(&str) = str.substr(0, MAX_FIELD_LEN);
		}

		wchar_t wret[MAX_FIELD_LEN + 1] = {0, };
		MultiByteToWideChar(CP_ACP, 0, str.c_str(), static_cast<int>(str.length()+1), wret, sizeof(wret));

		std::wstring ws(wret);
		char ret[MAX_FIELD_LEN + 1] = {0, };
		int len = WideCharToMultiByte(CP_UTF8, 0, ws.c_str(), static_cast<int>(ws.length()+1), ret, sizeof(ret), NULL, NULL);
		return std::string(ret);
	}

	inline std::string convert_to_ansi(const std::string& str)
	{
		if(str.length() > MAX_FIELD_LEN)
		{
			*const_cast<std::string*>(&str) = str.substr(0, MAX_FIELD_LEN);
		}

		wchar_t wret[MAX_FIELD_LEN + 1] = {0, };
		MultiByteToWideChar(CP_UTF8, 0, str.c_str(), static_cast<int>(str.length()+1), wret, sizeof(wret));

		std::wstring ws(wret);
		char ret[MAX_FIELD_LEN + 1] = {0, };
		int len = WideCharToMultiByte(CP_ACP, 0, ws.c_str(), static_cast<int>(ws.length()+1), ret, sizeof(ret), NULL, NULL);
		return std::string(ret);
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
	
	

	static int64 convert_time_str_to_int64(std::string time_str)
	{
		int year = 0, month = 0, day = 0, hour = 0, min = 0, sec = 0;
		sscanf(time_str.c_str(), "%04d-%02d-%02d %02d:%02d:%02d", &year, &month, &day, &hour, &min, &sec);

		struct tm cur_time_tm;
		cur_time_tm.tm_year = year - 1900;
		cur_time_tm.tm_mon = month - 1;
		cur_time_tm.tm_mday = day;
		cur_time_tm.tm_hour = hour;
		cur_time_tm.tm_min = min;
		cur_time_tm.tm_sec = sec;

		time_t timestamp_int64 = mktime(&cur_time_tm);
		return timestamp_int64;
	}

	static std::string convert_time_int64_to_str(int64 timestamp)
	{
		char buff[24] = {0, };
		struct tm t = *localtime(&timestamp);
		sprintf(buff, "%04d-%02d-%02d %02d:%02d:%02d", t.tm_year+1900, t.tm_mon+1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec);
		return buff;
	}

	inline static std::string get_current_time_str()
	{
		return convert_time_int64_to_str(time(0));
	}

	inline std::string trim(std::string& s)
	{
		return s.erase(s.find_last_not_of(" ")+1);
	}
}


#endif