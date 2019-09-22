#ifndef __K_UTIL_SERVER_CRYPTO__
#define __K_UTIL_SERVER_CRYPTO__

#include <ServerBase/serverbase.h>
#include <SpringCat/Config/StdIntDefs.h>

namespace crypto {

	const int CRYPTO_LEN = 16;

	SB_EXPORT_API void make_session_key(unsigned char* new_key, unsigned char* new_iv);
	
	SB_EXPORT_API void encrypt_session_key(const unsigned char* plain_key, const unsigned char* plain_iv, 
		unsigned char* encrypted_key, unsigned char* encrypted_iv);
}

#endif