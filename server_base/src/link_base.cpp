#include <ServerBase/link_base.h>
#include <ServerBase/protocol.h>
#include <aes.h>
#include <modes.h>

namespace network {

	// session key attribute name
	const char * const CONTEXT_NAME = "Crypto::SessionKey::Context";

	struct link_base::impl : public SpringCat::System::TL::SmallObject<link_base::impl>
	{
		impl(BaseCat::Network::Link::Handle link_handle)
			: link_handle_(link_handle), link_type_(link_base::UNKNOWN), link_id_(0), 
			recv_packet_count_(0), timestamp_(GET_TICK()), activated_(false), connected_(false), ref_id_(0), session_id_(0)
		{
			BaseCat::Network::Link::AddRef(link_handle_);

			auto config_handle = BaseCat::Network::Link::GetConfig(link_handle_);
			BaseCat::Network::LinkConfig::SetValue(config_handle, BaseCat::Network::LinkConfig::TCP_NO_DELAY, 1);
		}
		~impl()
		{
			BaseCat::Network::Link::Release(link_handle_);
		}

		// thread-safe object
		//SpringCat::Network::LinkPtr link_ptr_;
		BaseCat::Network::Link::Handle link_handle_;

		// not changed.
		link_base::type link_type_;

		link_id_t link_id_;

		// not changed.
		ref_id_t ref_id_;

		session_id_t session_id_;

		CriticalSection cs_;
		unsigned int recv_packet_count_;
		unsigned int timestamp_;
		bool activated_;
		bool connected_;
		
		struct session_key
		{
			bool flag_;
			byte key_[CryptoPP::AES::DEFAULT_KEYLENGTH];
			byte iv_[CryptoPP::AES::BLOCKSIZE];

			//std::auto_ptr<CryptoPP::CFB_Mode<CryptoPP::AES>::Encryption> encryptor_;
			//std::auto_ptr<CryptoPP::CFB_Mode<CryptoPP::AES>::Decryption> decryptor_;
		};
	};

	link_base::link_base(BaseCat::Network::Link::Handle link_handle)
		: pimpl_(new impl(link_handle))
	{

	}

	link_base::~link_base()
	{
		delete pimpl_;
		pimpl_ = NULL;
	}

	bool link_base::is_connected() const
	{
		return pimpl_->connected_;
	}
	
	void link_base::set_connect_flag(bool connect)
	{
		pimpl_->connected_ = connect;
	}

	bool link_base::get_session_key(byte* key, byte* iv) const
	{
		assert(key != NULL);
		assert(iv != NULL);

		ScopedLock lock(pimpl_->cs_);

		impl::session_key* attr_key = NULL;
		if(false == BaseCat::Network::Link::FindAttribute(pimpl_->link_handle_, CONTEXT_NAME, 
			reinterpret_cast<void**>(&attr_key)))
			return false;

		memcpy(key, attr_key->key_, CryptoPP::AES::DEFAULT_KEYLENGTH);
		memcpy(iv, attr_key->iv_, CryptoPP::AES::BLOCKSIZE);
		return true;
	}

	bool link_base::set_session_key(byte* key, byte* iv)
	{
		assert(key != NULL);
		assert(iv != NULL);

		ScopedLock lock(pimpl_->cs_);

		impl::session_key* attr_key = NULL;
		if(false == BaseCat::Network::Link::FindAttribute(pimpl_->link_handle_, CONTEXT_NAME, 
			reinterpret_cast<void**>(&attr_key)))
			return false;

		memcpy(attr_key->key_, key, CryptoPP::AES::DEFAULT_KEYLENGTH);
		memcpy(attr_key->iv_, iv, CryptoPP::AES::BLOCKSIZE);
		attr_key->flag_ = true;		// use AES
		
		/*attr_key->encryptor_.reset(new CryptoPP::CFB_Mode<CryptoPP::AES>::Encryption(
			attr_key->key_, CryptoPP::AES::DEFAULT_KEYLENGTH, attr_key->iv_));
		attr_key->decryptor_.reset(new CryptoPP::CFB_Mode<CryptoPP::AES>::Decryption(
			attr_key->key_, CryptoPP::AES::DEFAULT_KEYLENGTH, attr_key->iv_));*/
		return true;
	}

	bool link_base::is_set_session_key() const
	{
		ScopedLock lock(pimpl_->cs_);

		impl::session_key* attr_key = NULL;
		if(false == BaseCat::Network::Link::FindAttribute(pimpl_->link_handle_, CONTEXT_NAME, 
			reinterpret_cast<void**>(&attr_key)))
			return false;

		return attr_key->flag_;
	}

	bool link_base::send(const SpringCat::Wave::object_base& msg)
	{
		SpringCat::System::Stream stream;
		protocol::build(pimpl_->session_id_, msg, stream);	
		assert(0!=stream.GetLength());
		return send(stream.GetRawPtr());
	}

	bool link_base::send(const SpringCat::System::SmartHeap::Block data)
	{
		assert(0!=SpringCat::System::SmartHeap::GetSize(data));
		return BaseCat::Network::Link::Send(pimpl_->link_handle_, data);
	}

	void link_base::close()
	{
		BaseCat::Network::Link::Close(pimpl_->link_handle_);
	}

	void link_base::activate()
	{
		ScopedLock lock(pimpl_->cs_);
		pimpl_->activated_ = true;
	}

	void link_base::deactivate()
	{
		ScopedLock lock(pimpl_->cs_);
		pimpl_->activated_ = false;
	}

	bool link_base::is_activated() const
	{
		ScopedLock lock(pimpl_->cs_);
		return pimpl_->activated_;
	}

	session_id_t link_base::get_session_id() const
	{
		ScopedLock lock(pimpl_->cs_);
		return pimpl_->session_id_;
	}

	void link_base::set_session_id(session_id_t session_id)
	{
		ScopedLock lock(pimpl_->cs_);
		pimpl_->session_id_ = session_id;
	}

	link_id_t link_base::get_link_id() const
	{
		ScopedLock lock(pimpl_->cs_);
		return pimpl_->link_id_;
	}

	void link_base::set_link_id(link_id_t link_id)
	{
		ScopedLock lock(pimpl_->cs_);
		pimpl_->link_id_ = link_id;
	}

	void link_base::set_ref_id(int64 id)
	{
		ScopedLock lock(pimpl_->cs_);
		pimpl_->ref_id_ = id;
	}

	int64 link_base::get_ref_id() const
	{
		ScopedLock lock(pimpl_->cs_);
		return pimpl_->ref_id_;
	}

	link_base::type link_base::get_link_type() const
	{
		ScopedLock lock(pimpl_->cs_);
		return pimpl_->link_type_;
	}

	void link_base::set_link_type(link_base::type link_type)
	{
		ScopedLock lock(pimpl_->cs_);
		pimpl_->link_type_ = link_type;
	}

	bool link_base::update_timestamp(unsigned int max_recv_count_per_sec)
	{
		ScopedLock lock(pimpl_->cs_);

		pimpl_->recv_packet_count_++;

		uint32 cur_tick = GET_TICK();
		int32 interval = cur_tick - pimpl_->timestamp_;

		if(interval >= 1000)	// 1 sec
		{
			pimpl_->timestamp_ = cur_tick;

			if(max_recv_count_per_sec != 0)
			{
				if( max_recv_count_per_sec < (static_cast<float>(pimpl_->recv_packet_count_) / static_cast<float>(interval / 1000.0f)) )
					return false;
			}
			pimpl_->recv_packet_count_ =  0;
		}
		return true;
	}

	bool link_base::is_dead(unsigned int dead_interval) const
	{
		ScopedLock lock(pimpl_->cs_);
		uint32 cur_tick = GET_TICK();
		return (cur_tick - pimpl_->timestamp_ > dead_interval) ? true : false;
	}

	BaseCat::Network::Link::Handle link_base::get_raw_link_ptr() const
	{
		return pimpl_->link_handle_;
	}

	bool link_base::operator== (const boost::shared_ptr<link_base>& rhs) const
	{
		return this == rhs.get();
	}

	CriticalSection& link_base::get_lock_object() const
	{
		return pimpl_->cs_;
	}


}