#ifndef __K_SB_CRYPTO_AES_FILTER__
#define __K_SB_CRYPTO_AES_FILTER__

#include <SpringCat/System/TL/SmallObject.h>
#include <SpringCat/Common/Exceptions.h>
#include <SpringCat/Network/Filter.h>

#include <ServerBase/protocol.h>

#include <aes.h>
#include <modes.h>
#include <boost/crc.hpp>


namespace network { namespace filters {

	namespace Detail
	{
		namespace AESFilter
		{
			const char * const FILTER_NAME = "Crypto::SessionKey";
			const char * const CONTEXT_NAME = "Crypto::SessionKey::Context";
		}
	}

	class AESFilter : public SpringCat::Network::IFilter
	{
	private:
		struct Context : public BaseCat::System::TL::SmallObject<Context>
		{
			Context()
				: flag_(false)
			{
			}
			bool flag_;
			byte key_[CryptoPP::AES::DEFAULT_KEYLENGTH];
			byte iv_[CryptoPP::AES::BLOCKSIZE];

			//std::auto_ptr<CryptoPP::CFB_Mode<CryptoPP::AES>::Encryption> encryptor_;
			//std::auto_ptr<CryptoPP::CFB_Mode<CryptoPP::AES>::Decryption> decryptor_;
		};
	public:
		AESFilter()
			: IFilter(Detail::AESFilter::FILTER_NAME)
		{

		}

		virtual ~AESFilter(void)
		{

		}

	protected:
		virtual void OnOpened(BaseCat::Network::Filter::Handle next,
			BaseCat::Network::Link::Handle link)
		{
			Context *context = new Context();
			if (BaseCat::Network::Link::AddAttribute(link,
				Detail::AESFilter::CONTEXT_NAME, context) == false)
			{
				delete context;
				context = NULL;
				BaseCat::Network::Link::Close(link);
				return;
			}

			BaseCat::Network::Filter::DoOnLinkOpened(next, link);
		}

		virtual void OnClosed(BaseCat::Network::Filter::Handle next,
			BaseCat::Network::Link::Handle link)
		{
			Context *context = NULL;
			if (BaseCat::Network::Link::FindAttribute(link, Detail::AESFilter::CONTEXT_NAME,
				reinterpret_cast<void **>(&context)) == false)
			{
				return;
			}
			BaseCat::Network::Link::RemoveAttribute(link, Detail::AESFilter::CONTEXT_NAME);
			delete context;
			context = NULL;

			BaseCat::Network::Filter::DoOnLinkClosed(next, link);
		}

		virtual void OnSend(BaseCat::Network::Filter::Handle next,
			BaseCat::Network::Link::Handle link,
			BaseCat::System::SmartHeap::Block buffer, size_t size)
		{
			Context *context = NULL;
			if (BaseCat::Network::Link::FindAttribute(link, Detail::AESFilter::CONTEXT_NAME,
				reinterpret_cast<void **>(&context)) == false)
			{
				return;
			}

			int payload_size = static_cast<int>(size - sizeof(protocol::packet_header));
			if(payload_size > 0 && context->flag_)
			{
				protocol::packet_header* header = reinterpret_cast<protocol::packet_header*>(buffer);

				byte* payload_ptr = reinterpret_cast<byte*>(buffer) + sizeof(protocol::packet_header);

				//context->encryptor_->ProcessData(payload_ptr, payload_ptr, payload_size);
				/*CryptoPP::CFB_Mode<CryptoPP::AES>::Encryption encryptor(
					context->key_, CryptoPP::AES::DEFAULT_KEYLENGTH, context->iv_);
				encryptor.ProcessData(payload_ptr, payload_ptr, payload_size);*/
				
				for(int i=0,k=0;i<payload_size;i++,k++)
				{
					payload_ptr[i]^=context->key_[k];
					payload_ptr[i]^=context->iv_[k];

					if(k == sizeof(context->key_) -1)
						k = 0;
				}

				header->flag = 0x01;
			}
			BaseCat::Network::Filter::DoOnSend(next, link, buffer, size);
		}

		virtual void OnReceived(BaseCat::Network::Filter::Handle next, 
			BaseCat::Network::Link::Handle link, 
			BaseCat::System::SmartHeap::Block buffer, size_t size)
		{
			Context *context = NULL;
			if (BaseCat::Network::Link::FindAttribute(link, Detail::AESFilter::CONTEXT_NAME,
				reinterpret_cast<void **>(&context)) == false)
			{
				return;
			}

			int payload_size = static_cast<int>(size - sizeof(protocol::packet_header));
			if(payload_size > 0 && context->flag_)
			{
				protocol::packet_header* header = reinterpret_cast<protocol::packet_header*>(buffer);

				byte* payload_ptr = reinterpret_cast<byte*>(buffer) + sizeof(protocol::packet_header);

				//context->decryptor_->ProcessData(payload_ptr, payload_ptr, payload_size);
				/*CryptoPP::CFB_Mode<CryptoPP::AES>::Decryption decryptor(
					context->key_, CryptoPP::AES::DEFAULT_KEYLENGTH, context->iv_);
				decryptor.ProcessData(payload_ptr, payload_ptr, payload_size);*/

				for(int i=0,k=0;i<payload_size;i++,k++)
				{
					payload_ptr[i]^=context->key_[k];
					payload_ptr[i]^=context->iv_[k];

					if(k == sizeof(context->key_) -1)
						k = 0;
				}
			}
			BaseCat::Network::Filter::DoOnReceived(next, link, buffer, size);
		}
	};

}}

#endif