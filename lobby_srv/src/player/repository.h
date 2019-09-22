#ifndef __GTB_LOBBY_REPOSITORY__
#define __GTB_LOBBY_REPOSITORY__

#include <SpringCat/System/System.h>
#include <ServerBase/sb_define.h>
#include <common/server_consts.h>
#include <boost/unordered_map.hpp>
#include <ServerBase/link_base.h>
#include <aes.h>
#include <time.h>
#include "player.h"

namespace player {

	class repository : public SpringCat::System::TL::NonCopyable
	{
	private:
		repository();

	public:
		virtual ~repository();

		static repository& instance();

		network::session_id_t reserve_session(player_no_t player_no, byte* key, byte* iv);

		bool add(network::session_id_t session_id, network::link_ptr_t link);
		void confirm_reserved_session(network::session_id_t session_id, network::link_ptr_t link);

		player_ptr_t find(player_no_t player_no);

		void remove(player_no_t player_no);

		bool load_player_profile_info(player_no_t player_no, protocol::player_profile_info& info);
		bool load_selected_vehicle_info(player_no_t player_no, protocol::vehicle& info);
		bool load_ability_slot_info(player_no_t player_no, protocol::ability_slot& info);
		bool load_ability_list(player_no_t player_no, protocol::ability_list& infos);
	private:
		bool internal_check_if_valid(network::session_id_t session_id, network::link_ptr_t link);
		void internal_remove_session(network::session_id_t session_id);
		player_ptr_t internal_find(player_no_t player_no);

		static void detect_expired_session(unsigned int, void*);
		network::session_id_t generate_session_id() const;
		void make_seed();

	private:
		mutable CriticalSection cs_;

		typedef BaseCat::System::TL::Allocator<std::pair<player_no_t, player_ptr_t>> player_repos_allocator;
		typedef boost::unordered_map<player_no_t, player_ptr_t, std::hash<player_no_t>, std::equal_to<player_no_t>, player_repos_allocator> repos_t;
		repos_t repos_;


		struct reserved_session_info
		{
			reserved_session_info() {}
			reserved_session_info(player_no_t player_no, byte* key, byte* iv)
				: player_no_(player_no), registered_timestamp_(::time(0))
			{
				memcpy(key_, key, CryptoPP::AES::DEFAULT_KEYLENGTH);
				memcpy(iv_, iv, CryptoPP::AES::BLOCKSIZE);
			}

			player_no_t player_no_;
			byte key_[CryptoPP::AES::DEFAULT_KEYLENGTH];
			byte iv_[CryptoPP::AES::BLOCKSIZE];
			int64 registered_timestamp_;
		};
		std::map<network::session_id_t, reserved_session_info> reserved_session_list_;

		unsigned int detect_expired_session_timer_id_;
	};

}


#endif