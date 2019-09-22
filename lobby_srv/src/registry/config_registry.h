#ifndef __GTB_CONFIG_REGISTRY__
#define __GTB_CONFIG_REGISTRY__

#include <serverbase/sb_define.h>
#include <protocol/vehicle.dc.h>
#include <numeric>

namespace config {

	enum reward_card
	{
		SILVER = 1,
		GOLD,
		PLATINUM,
	};

	class registry
	{
	public:
		registry();
		~registry();

		static registry& instance();

		bool is_valid_stuff_id(int32 stuff_id) const;
		int32 get_reward_stuff_id(reward_card card_type);

	private:
		bool load_ability_slot_info();
		bool load_reward_card_probability();
		bool load_stuff_list();
		bool load_vehicle_upgrade_info();

		bool load_config(const std::string& key, std::string& val);
	private:
		struct ability_slot_info
		{
			int16 unlock_level_;
			int32 price_diamond_;
		};
		std::map<uint16, ability_slot_info> ability_slot_info_map_;

		struct reward_card_probability_info
		{
			std::vector<std::pair<int16, int32>> prob_;			// rarity, prob
			bool vaild()
			{
				return 1000 == std::accumulate(prob_.begin(), prob_.end(), 0, 
					[](int acc, const std::pair<int16, int32>& p) -> int32
				{
					return acc + p.second;
				});
			}
		};
		std::map<reward_card, reward_card_probability_info> reward_card_prob_map_;

		std::vector<int32> stuff_id_list_;

		typedef std::map<protocol::vehicle_level, int32> need_card_map_t;
		std::map<int16, need_card_map_t> vehicle_upgrade_info_;
	};
}

#endif
