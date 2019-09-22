#ifndef __GTB_COMMON_EXCEPTION__
#define __GTB_COMMON_EXCEPTION__

#include <string>
#include <boost/shared_ptr.hpp>
#include <common/error_code.h>

class exception_x : public std::exception
{
public:
	exception_x(error::code_t errcode, const char* msg, ...)
	{
		err_code_ = errcode;

		char buff[1024] = { 0, };
		va_list args;

		va_start(args, msg);
		int res = _vsnprintf_s(buff, sizeof(1024), msg, args);
		va_end(args);

		if (res == -1)
			msg_ = "invalid format";

		msg_ = buff;
	}

	virtual ~exception_x() {}

	std::string msg_;
	short err_code_;
};

typedef boost::shared_ptr<exception_x> exception_x_ptr_t;


#endif
