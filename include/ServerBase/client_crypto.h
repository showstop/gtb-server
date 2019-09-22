#ifndef __K_UTIL_CLIENT_CRYPTO__
#define __K_UTIL_CLIENT_CRYPTO__

#include <ServerBase/serverbase.h>
#include <SpringCat/Config/StdIntDefs.h>


namespace crypto {

	SB_EXPORT_API void decrypt_session_key(const unsigned char* encrypted_session_key, const unsigned char* encrypted_iv, const char* rsa_private_key, 
		unsigned char* decrypted_session_key, unsigned char* decrypted_iv);

}


#endif