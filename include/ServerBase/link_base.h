#ifndef __K_SB_LINK__
#define __K_SB_LINK__

#include <ServerBase/serverbase.h>
#include <ServerBase/sb_define.h>
#include <boost/shared_ptr.hpp>

namespace network {

	typedef int link_id_t;
	typedef int64 ref_id_t;

	class SB_EXPORT_API link_base
	{
		friend class acceptor_base;
		friend class connector_base;
	public:
		enum type
		{
			UNKNOWN = 0,
			GAME_CLIENT,
			GAME_SERVER,
			AUTH_SERVER,
		};
	public:
		link_base(BaseCat::Network::Link::Handle link_handle);
		virtual ~link_base();

		bool is_connected() const;

		bool get_session_key(byte* key, byte* iv) const;
		bool set_session_key(byte* key, byte* iv);
		bool is_set_session_key() const;

		bool send(const SpringCat::Wave::object_base& msg);
		bool send(const SpringCat::System::SmartHeap::Block data);

		void close();

		void activate();
		void deactivate();
		bool is_activated() const;

		session_id_t get_session_id() const;
		void set_session_id(session_id_t session_id);

		link_id_t get_link_id() const;
		void set_link_id(link_id_t link_id);

		type get_link_type() const;
		void set_link_type(link_base::type link_type);

		void set_ref_id(ref_id_t id);
		ref_id_t get_ref_id() const;

		bool is_dead(unsigned int dead_interval) const;
		bool update_timestamp(unsigned int max_recv_count_per_sec);

		CriticalSection& get_lock_object() const;
		// org member func.
		BaseCat::Network::Link::Handle get_raw_link_ptr() const;
	protected:
		bool operator== (const boost::shared_ptr<link_base>& rhs) const;

		void set_connect_flag(bool connect);

	private:
		struct impl;
		impl* pimpl_;
	};

	typedef boost::shared_ptr<link_base> link_ptr_t;

	class autostream
	{
	public:
		autostream(BaseCat::Network::Link::Handle handle)
			: handle_(handle)
		{
			BaseCat::System::Stream::Handle stream = BaseCat::Network::Link::LockReadStream(handle_);
			stream_.Attach(BaseCat::System::Stream::Detach(stream));
		}
		~autostream()
		{
			BaseCat::Network::Link::UnlockReadStream(handle_);
		}

		BaseCat::Network::Link::Handle handle_;
		SpringCat::System::Stream stream_;
	};
}

#endif