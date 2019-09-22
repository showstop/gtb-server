#include "web_client.h"

extern "C" {
#include <curl/curl.h> 
}
#include <map>
#include <string>

namespace web {

	// static 
	void client::global_init()
	{
		curl_global_init( CURL_GLOBAL_ALL );
	}
	
	// static 
	void client::global_cleanup()
	{
		curl_global_cleanup();
	}

	struct client::impl
	{
		impl()
			: context_(nullptr), sheader_(nullptr) {}

		CURL* context_;
		std::string url_;
		std::string script_;
		std::map<std::string, std::string> params_;

		std::string buff_str_;
		curl_slist* sheader_;
	};

	client::client()
		: pimpl_(new client::impl())
	{
		pimpl_->context_ = curl_easy_init();
	}

	client::~client()
	{
		curl_easy_cleanup( pimpl_->context_ );
		pimpl_->context_ = nullptr;
	}

	void client::clear_param()
	{
		pimpl_->params_.clear();
	}

	void client::add_param(const std::string& name, const std::string& value)
	{
		pimpl_->params_[name] = value;
	}

	void client::set_base_url(const std::string& url)
	{
		pimpl_->url_ = url;
	}

	void client::set_script(const std::string& script)
	{
		pimpl_->script_ = script;
	}

	void client::add_header(const std::string& header)
	{
		/*curl_slist* header = nullptr ;
        header = curl_slist_append( header, "User-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; .NET CLR 1.0.3705) " ) ;
        header = curl_slist_append( header, "Content-Type: application/x-www-form-urlencoded" ) ;
        curl_easy_setopt( pimpl_->context_, CURLOPT_HTTPHEADER , header ) ;*/

		pimpl_->sheader_ = curl_slist_append( pimpl_->sheader_, header.c_str() );
		
	}

	void client::set_header()
	{
		curl_easy_setopt( pimpl_->context_, CURLOPT_HTTPHEADER, pimpl_->sheader_ );
	}

	size_t on_web_response_func(void* ptr, size_t size, size_t count, void* data)
	{
	    (static_cast<std::string*>(data))->append((char*)ptr, 0, size*count); 
		return size * count;
	}

	bool client::send_request_get()
	{
		curl_version_info_data * vinfo = curl_version_info(CURLVERSION_NOW);

		if( !(vinfo->features & CURL_VERSION_SSL))
		{
			clear_param();
			return false;
		}

		std::string form_action(pimpl_->url_);
		form_action.append(pimpl_->script_);
		form_action.append("?");

		size_t size = pimpl_->params_.size();
		size_t cnt = 0;
		auto it = pimpl_->params_.begin();
		for(;it!=pimpl_->params_.end();++it)
		{
			form_action.append(it->first);
			form_action.append("=");
			form_action.append(it->second);
			if(cnt != size-1)
				form_action.append("&");
			cnt++;
		} 

		curl_easy_setopt( pimpl_->context_, CURLOPT_URL, form_action.c_str());
		curl_easy_setopt( pimpl_->context_, CURLOPT_SSL_VERIFYPEER, 0 );
		curl_easy_setopt( pimpl_->context_, CURLOPT_HTTPGET, 1);
		curl_easy_setopt( pimpl_->context_, CURLOPT_WRITEFUNCTION, on_web_response_func);
		curl_easy_setopt( pimpl_->context_, CURLOPT_WRITEDATA, &pimpl_->buff_str_);

		const CURLcode ret = curl_easy_perform( pimpl_->context_ );
		if(ret != CURLE_OK)
		{
			clear_param();
			return false;
		}

		clear_param();
		return true;
	}

	bool client::send_request_post(const std::string& form_data)
	{
		curl_version_info_data * vinfo = curl_version_info(CURLVERSION_NOW);

		if( !(vinfo->features & CURL_VERSION_SSL))
		{
			clear_param();
			return false;
		}

		std::string url(pimpl_->url_);
		url.append(pimpl_->script_);
		
		std::string form_action;
		if(form_data.empty())
		{
			size_t size = pimpl_->params_.size();
			size_t cnt = 0;
			auto it = pimpl_->params_.begin();
			for(;it!=pimpl_->params_.end();++it)
			{
				form_action.append(it->first);
				form_action.append("=");
				form_action.append(it->second);
				if(cnt != size-1)
					form_action.append("&");
				cnt++;
			} 
		}
		else
		{
			form_action = form_data;
		}

		//curl_easy_setopt( pimpl_->context_, CURLOPT_HTTPHEADER, pimpl_->sheader_);
		curl_easy_setopt( pimpl_->context_, CURLOPT_SSL_VERIFYHOST,  2);
		curl_easy_setopt( pimpl_->context_, CURLOPT_URL, url.c_str());
		curl_easy_setopt( pimpl_->context_, CURLOPT_SSL_VERIFYPEER, 0 );
		curl_easy_setopt( pimpl_->context_, CURLOPT_POSTFIELDS, form_action.c_str());
		curl_easy_setopt( pimpl_->context_, CURLOPT_POST, 1);
		curl_easy_setopt( pimpl_->context_, CURLOPT_WRITEFUNCTION, on_web_response_func);
		curl_easy_setopt( pimpl_->context_, CURLOPT_WRITEDATA, &pimpl_->buff_str_);

		const CURLcode ret = curl_easy_perform( pimpl_->context_ );
		if(ret != CURLE_OK)
		{
			clear_param();
			return false;
		}

		clear_param();
		return true;
	}

	const std::string& client::get_result() const
	{
		return pimpl_->buff_str_;
	}

	
}