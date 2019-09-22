#include "gc_auth_handler.h"
#include <ServerBase/logger.h>
#include <common/error_code.h>
#include <util/helper_util.h>
#include <ServerBase/server_crypto.h>

namespace protocol {

	bool session_key_req_job::process()
	{
		session_key_ans ans;

		unsigned char new_key[16] = { 0, }, new_iv[16] = { 0, };
		crypto::make_session_key(new_key, new_iv);

		unsigned char encrypted_key[256] = { 0, }, encrypted_iv[256] = { 0, };
		crypto::encrypt_session_key(new_key, new_iv, encrypted_key, encrypted_iv);

		auto& key = *ans.get_mutable_key();
		key.resize(sizeof(encrypted_key));
		memcpy(&key[0], encrypted_key, sizeof(encrypted_key));
		memcpy(&key[0], new_key, sizeof(new_key));

		auto& iv = *ans.get_mutable_iv();
		iv.resize(sizeof(encrypted_iv));
		memcpy(&iv[0], encrypted_iv, sizeof(encrypted_iv));
		memcpy(&iv[0], new_iv, sizeof(new_iv));

		link_->send(ans);

		link_->set_session_key(new_key, new_iv);


		return true;
	}

}