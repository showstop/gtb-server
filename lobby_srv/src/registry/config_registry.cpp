#include "config_registry.h"
#include <util/db_odbc.h>
#include <ServerBase/logger.h>
#include <json/json.h>
#include <util/random_util.h>

namespace config {

	registry::registry()
	{
		load_ability_slot_info();
		load_reward_card_probability();
		load_stuff_list();
		load_vehicle_upgrade_info();

		std::vector<int32> silver, gold, platinum;
		int s = 0;
		for (int i = 0; i < 100; i++)
		{
			silver.push_back(get_reward_stuff_id(SILVER));
			gold.push_back(get_reward_stuff_id(GOLD));
			platinum.push_back(get_reward_stuff_id(PLATINUM));
		}
	}

	registry::~registry()
	{

	}

	registry& registry::instance()
	{
		static registry r;
		return r;
	}

	bool registry::is_valid_stuff_id(int32 stuff_id) const
	{
		return stuff_id_list_.end() != std::find(stuff_id_list_.begin(), stuff_id_list_.end(), stuff_id);
	}

	int32 registry::get_reward_stuff_id(reward_card card_type)
	{
		auto it = reward_card_prob_map_.find(card_type);
		if (it == reward_card_prob_map_.end())
			return 0;

		auto gen_num = rand_helper::gen_probability_number(1, 1000);
		int32 decided_rarity = 0;
		
		int accumulated_val = 0;
		for (auto p : it->second.prob_)
		{
			accumulated_val += p.second;
			if (gen_num <= accumulated_val)
			{
				decided_rarity = p.first;
				break;
			}
		}

		std::vector<int32> extracted_stuff_ids;
		std::copy_if(stuff_id_list_.begin(), stuff_id_list_.end(), std::back_inserter(extracted_stuff_ids),
			[decided_rarity](int32 stuff_id) -> bool
		{
			return decided_rarity == static_cast<int32>(stuff_id / 100);
		});

		auto dest_stuff_count = static_cast<int32>(extracted_stuff_ids.size());
		auto picked = rand_helper::gen_probability_number(0, dest_stuff_count - 1);
		return extracted_stuff_ids[picked];
	}

	bool registry::load_config(const std::string& key, std::string& val)
	{
		db::connection_pool cp;
		db::prepared_statement_ptr pstmt;

		const std::string query("call load_game_config(?);");
		if (false == cp.prepare(query, pstmt))
			return false;

		pstmt->set_string(1, key);

		if (false == cp.execute(pstmt))
			return false;

		if (false == pstmt->fetch())
			return false;

		val = pstmt->get_string(1);
		return true;
	}


	bool registry::load_ability_slot_info()
	{
		std::string result;
		if (false == load_config("ability_slot", result))
			return false;

		Json::Value root;
		Json::Reader reader;
		if (false == reader.parse(result, root))
		{
			write_fmt(Log::Error, "[config_registry::load_ability_slot_info] invalid json. (%s)", result.c_str());
			return false;
		}

		for (auto it = root.begin(); it != root.end(); ++it)
		{
			auto unit = (*it);
			auto unlock_lv = unit["UnlockLevel"].asInt();
			auto slot_no = static_cast<uint16>(unit["SlotNO"].asUInt());
			auto price_diamond = unit["CashPrice"].asInt();

			ability_slot_info asi;
			asi.unlock_level_ = static_cast<int16>(unlock_lv);
			asi.price_diamond_ = price_diamond;
			
			ability_slot_info_map_.insert(std::make_pair(slot_no, asi));
		}

		write_fmt(Log::Process, "[config_registry::load_ability_slot_info] ability slot info load complete.");
		return true;
	}


	bool registry::load_reward_card_probability()
	{
		std::string result;
		if (false == load_config("reward_card_probability", result))
			return false;

		Json::Value root;
		Json::Reader reader;
		if (false == reader.parse(result, root))
		{
			write_fmt(Log::Error, "[config_registry::load_reward_card_probability] invalid json. (%s)", result.c_str());
			return false;
		}

		for (auto it = root.begin(); it != root.end(); ++it)
		{
			auto unit = (*it);
			auto card_type = unit["Card"].asString();

			reward_card_probability_info rcpi;
			int32 prob = 0;
			prob = static_cast<int32>(unit["Material Rarity 1"].asFloat() * 1000);			rcpi.prob_.push_back(std::make_pair(1, prob));
			prob = static_cast<int32>(unit["Material Rarity 2"].asFloat() * 1000);			rcpi.prob_.push_back(std::make_pair(2, prob));
			prob = static_cast<int32>(unit["Material Rarity 3"].asFloat() * 1000);			rcpi.prob_.push_back(std::make_pair(3, prob));
			prob = static_cast<int32>(unit["Material Rarity 4"].asFloat() * 1000);			rcpi.prob_.push_back(std::make_pair(4, prob));

			assert(rcpi.vaild());

			std::sort(rcpi.prob_.begin(), rcpi.prob_.end(),
				[](const std::pair<int16, int32>& lhs, const std::pair<int16, int32>& rhs) -> bool
			{return lhs.second < rhs.second; });

			reward_card card;
			if (card_type == "Silver")			card = SILVER;
			else if (card_type == "Gold")		card = GOLD;
			else if (card_type == "Platinum")	card = PLATINUM;

			reward_card_prob_map_.insert(std::make_pair(card, rcpi));
		}

		write_fmt(Log::Process, "[config_registry::load_reward_card_probability] reward card probability load complete.");
		return true;
	}

	bool registry::load_stuff_list()
	{
		std::string result;
		if (false == load_config("stuff_id_list", result))
			return false;

		Json::Value root;
		Json::Reader reader;
		if (false == reader.parse(result, root))
		{
			write_fmt(Log::Error, "[config_registry::load_stuff_list] invalid json. (%s)", result.c_str());
			return false;
		}

		for (auto it = root.begin(); it != root.end(); ++it)
		{
			auto stuff_id = (*it).asInt();
			stuff_id_list_.push_back(stuff_id);
		}

		write_fmt(Log::Process, "[config_registry::load_stuff_list] stuff list load complete.");
		return true;
	}

	bool registry::load_vehicle_upgrade_info()
	{
		std::string result;
		if (false == load_config("vehicle_upgrade", result))
			return false;

		Json::Value root;
		Json::Reader reader;
		if (false == reader.parse(result, root))
		{
			write_fmt(Log::Error, "[config_registry::load_vehicle_upgrade_info] invalid json. (%s)", result.c_str());
			return false;
		}

		for (auto it = root.begin(); it != root.end(); ++it)
		{
			auto unit = (*it);
			auto grade = unit["Grade"].asInt();

			need_card_map_t ncm;
			ncm[protocol::vehicle_level_D_CLASS] = unit["D"].asInt();
			ncm[protocol::vehicle_level_C_CLASS] = unit["C"].asInt();
			ncm[protocol::vehicle_level_B_CLASS] = unit["B"].asInt();
			ncm[protocol::vehicle_level_A_CLASS] = unit["A"].asInt();
			ncm[protocol::vehicle_level_S_CLASS] = unit["S"].asInt();

			vehicle_upgrade_info_.insert(std::make_pair(grade, ncm));
		}

		write_fmt(Log::Process, "[config_registry::load_vehicle_upgrade_info] vehicle upgrade info load complete.");

		return true;
	}

}