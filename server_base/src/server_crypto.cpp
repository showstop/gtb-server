#include <ServerBase/server_crypto.h>

#if defined(WIN32) || defined(_WIN64)
#include <rsa.h>
#include <hex.h>
#include <osrng.h>
#include <filters.h>
#include <aes.h>

namespace crypto {

	const std::string pub_key = "30820120300D06092A864886F70D01010105000382010D00308201080282010100D7256781F4FB2AA59323226769262ED7EC631937E9AE85C817444E18BBEC360A84BACBF19B63CC42EF8EA409B6E750E82CE4DA1F6A3A7549377988677911C53CD340E5B519CB194089A3DAF0A8C9386AD4BC8FE3EEBDC04155183ACB4DAF5FE85988BE80F95A755C67D503E5C8936DE58ED2DE9C2AF796FB17920B986D876B2E309D6E0207C76D27C6762A58F2255F5F54EC0936E3838D11C6E7BBF45B7EBE7EBD0461061AF75E2602732C823EDE69E8283D24CF3F3607A1D9EF4BB6A7A8F483A894934697E2323FDEDA3091C8E64F06ECEE9A3722D086C6F48440C2540733E673C3FBD384DBB6CA5C6B12EDFDB5FA04DD8BADCE4AF2E86216602C75DB970E63020111";

	CryptoPP::AutoSeededRandomPool g_rnd;
	CryptoPP::RSAES_OAEP_SHA_Encryptor g_encrytor_with_pubkey( CryptoPP::StringSource(pub_key, true, new CryptoPP::HexDecoder));

	SB_EXPORT_API void make_session_key(unsigned char* new_key, unsigned char* new_iv)
	{
		CryptoPP::SecByteBlock key(CryptoPP::AES::DEFAULT_KEYLENGTH);
		g_rnd.GenerateBlock( key, key.size() );

		memcpy(new_key, &key[0], key.size() );
		// Generate a random IV
		byte iv[CryptoPP::AES::BLOCKSIZE];
		g_rnd.GenerateBlock(iv, CryptoPP::AES::BLOCKSIZE);

		memcpy(new_iv, &iv[0], CryptoPP::AES::BLOCKSIZE);
	}

	SB_EXPORT_API void encrypt_session_key(const unsigned char* plain_key, const unsigned char* plain_iv, 
		unsigned char* encrypted_key, unsigned char* encrypted_iv)
	{
		const int RSA_ENCRYPTED_KEY_LEN = 256;

		CryptoPP::ArraySource(plain_key, CryptoPP::AES::DEFAULT_KEYLENGTH, true, new CryptoPP::PK_EncryptorFilter(g_rnd, g_encrytor_with_pubkey, 
			new CryptoPP::ArraySink(encrypted_key, RSA_ENCRYPTED_KEY_LEN)));

		CryptoPP::ArraySource(plain_iv, CryptoPP::AES::DEFAULT_KEYLENGTH, true, new CryptoPP::PK_EncryptorFilter(g_rnd, g_encrytor_with_pubkey, 
			new CryptoPP::ArraySink(encrypted_iv, RSA_ENCRYPTED_KEY_LEN)));
	}
}

#else

namespace crypto {

	SB_EXPORT_API void make_session_key(unsigned char* new_key, unsigned char* new_iv)
	{
		//todo
	}

	SB_EXPORT_API void encrypt_session_key(const unsigned char* plain_key, const unsigned char* plain_iv, 
		unsigned char* encrypted_key, unsigned char* encrypted_iv)
	{
		//todo
	}

}
#endif
