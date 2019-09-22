#ifndef __TR_WEBCLIENT__
#define __TR_WEBCLIENT__

#include <boost/scoped_ptr.hpp>
#include <ServerBase/sb_define.h>

namespace web {

	class client
	{
	public:
		client();
		virtual ~client();

		static void global_init();
		static void global_cleanup();

		void clear_param();
		void add_param(const std::string& name, const std::string& value);

		void set_base_url(const std::string& url);
		void set_script(const std::string& script);
		void add_header(const std::string& header);
		void set_header();

		bool send_request_get();
		bool send_request_post(const std::string& form_data = "");

		const std::string& get_result() const;

	private:
		struct impl;
		boost::scoped_ptr<impl> pimpl_;
	};

}


#endif