#include "internal_ls_ps.dc.h"
#include <stdexcept>


namespace protocol
{

// class name: internal_register_ps_req, type id(decimal): 172093985, type id(hex): 0xA41F221
static const SpringCat::Wave::type_info __internal_register_ps_req_type_info__(0xA41F221, "protocol.internal_register_ps_req");
// class name: internal_register_ps_ans, type id(decimal): 172084915, type id(hex): 0xA41CEB3
static const SpringCat::Wave::type_info __internal_register_ps_ans_type_info__(0xA41CEB3, "protocol.internal_register_ps_ans");
// class name: player_requisite_info, type id(decimal): 30783039, type id(hex): 0x1D5B63F
static const SpringCat::Wave::type_info __player_requisite_info_type_info__(0x1D5B63F, "protocol.player_requisite_info");
// class name: internal_start_game_req, type id(decimal): 231845457, type id(hex): 0xDD1AE51
static const SpringCat::Wave::type_info __internal_start_game_req_type_info__(0xDD1AE51, "protocol.internal_start_game_req");
// class name: internal_start_game_ans, type id(decimal): 231838403, type id(hex): 0xDD192C3
static const SpringCat::Wave::type_info __internal_start_game_ans_type_info__(0xDD192C3, "protocol.internal_start_game_ans");
// class name: internal_player_end_game_report_req, type id(decimal): 210394225, type id(hex): 0xC8A5C71
static const SpringCat::Wave::type_info __internal_player_end_game_report_req_type_info__(0xC8A5C71, "protocol.internal_player_end_game_report_req");
// class name: internal_player_end_game_report_ans, type id(decimal): 210396387, type id(hex): 0xC8A64E3
static const SpringCat::Wave::type_info __internal_player_end_game_report_ans_type_info__(0xC8A64E3, "protocol.internal_player_end_game_report_ans");
// class name: internal_end_game_req, type id(decimal): 140340785, type id(hex): 0x85D6E31
static const SpringCat::Wave::type_info __internal_end_game_req_type_info__(0x85D6E31, "protocol.internal_end_game_req");
// class name: internal_end_game_ans, type id(decimal): 140333731, type id(hex): 0x85D52A3
static const SpringCat::Wave::type_info __internal_end_game_ans_type_info__(0x85D52A3, "protocol.internal_end_game_ans");

internal_register_ps_req::internal_register_ps_req(void)
    : __has_bits__(),
    ps_no_(0)
{
}

internal_register_ps_req::internal_register_ps_req(const internal_register_ps_req& from)
    : __has_bits__(),
    ps_no_(0)
{
    merge_from(from);
}

internal_register_ps_req::~internal_register_ps_req(void)
{
}

const SpringCat::Wave::type_info& internal_register_ps_req::static_type_info(void)
{
    return __internal_register_ps_req_type_info__;
}

const SpringCat::Wave::type_info& internal_register_ps_req::runtime_type_info(void) const
{
    return static_type_info();
}

internal_register_ps_req* internal_register_ps_req::new_instance(void) const
{
    return new internal_register_ps_req;
}

internal_register_ps_req* internal_register_ps_req::clone(void) const
{
    return new internal_register_ps_req(*this);
}

void internal_register_ps_req::clear(void)
{
    // ps_no
    ps_no_ = 0;
}

bool internal_register_ps_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t internal_register_ps_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // ps_no
    total_size += SpringCat::Wave::internal::size(ps_no_);

    return total_size;
}

void internal_register_ps_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const internal_register_ps_req& src = dynamic_cast<const internal_register_ps_req&>(from);
    copy_from(src);
}

void internal_register_ps_req::copy_from(const internal_register_ps_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void internal_register_ps_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const internal_register_ps_req& src = dynamic_cast<const internal_register_ps_req&>(from);
    merge_from(src);
}

void internal_register_ps_req::merge_from(const internal_register_ps_req& from)
{
    if (&from == this)
    {
        return;
    }

    // ps_no
    set_ps_no(from.get_ps_no());
}

bool internal_register_ps_req::serialize(SpringCat::System::Stream& output) const
{
    // ps_no
    if (SpringCat::Wave::internal::serialize(output, ps_no_) == false)
    {
        return false;
    }

    return true;
}

bool internal_register_ps_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool internal_register_ps_req::serialize(std::string& output) const
{
    SpringCat::System::Stream output_stream;
    if (serialize(output_stream) == false)
    {
        return false;
    }

    size_t output_size = output_stream.GetLength();
    std::string buffer;
    buffer.resize(output_size);
    if (output_stream.Peek(&buffer[0], output_size) != output_size)
    {
        return false;
    }

    output.swap(buffer);

    return true;
}

bool internal_register_ps_req::deserialize(SpringCat::System::Stream& input)
{
    // ps_no
    if (SpringCat::Wave::internal::deserialize(input, ps_no_) == false)
    {
        return false;
    }

    return true;
}

bool internal_register_ps_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool internal_register_ps_req::deserialize(std::string& input)
{
    size_t input_size = input.size();
    SpringCat::System::Stream input_stream(input_size);
    if (input_stream.Write(&input[0], input_size) != input_size)
    {
        return false;
    }

    if (deserialize(input_stream) == false)
    {
        return false;
    }

    input.clear();

    return true;
}

SpringCat::int32_t internal_register_ps_req::get_ps_no(void) const
{
    return ps_no_;
}

void internal_register_ps_req::set_ps_no(SpringCat::int32_t value)
{
    ps_no_ = value;
}

internal_register_ps_ans::internal_register_ps_ans(void)
    : __has_bits__(),
    result_(0)
{
}

internal_register_ps_ans::internal_register_ps_ans(const internal_register_ps_ans& from)
    : __has_bits__(),
    result_(0)
{
    merge_from(from);
}

internal_register_ps_ans::~internal_register_ps_ans(void)
{
}

const SpringCat::Wave::type_info& internal_register_ps_ans::static_type_info(void)
{
    return __internal_register_ps_ans_type_info__;
}

const SpringCat::Wave::type_info& internal_register_ps_ans::runtime_type_info(void) const
{
    return static_type_info();
}

internal_register_ps_ans* internal_register_ps_ans::new_instance(void) const
{
    return new internal_register_ps_ans;
}

internal_register_ps_ans* internal_register_ps_ans::clone(void) const
{
    return new internal_register_ps_ans(*this);
}

void internal_register_ps_ans::clear(void)
{
    // result
    result_ = 0;
}

bool internal_register_ps_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t internal_register_ps_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);

    return total_size;
}

void internal_register_ps_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const internal_register_ps_ans& src = dynamic_cast<const internal_register_ps_ans&>(from);
    copy_from(src);
}

void internal_register_ps_ans::copy_from(const internal_register_ps_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void internal_register_ps_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const internal_register_ps_ans& src = dynamic_cast<const internal_register_ps_ans&>(from);
    merge_from(src);
}

void internal_register_ps_ans::merge_from(const internal_register_ps_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
}

bool internal_register_ps_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }

    return true;
}

bool internal_register_ps_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool internal_register_ps_ans::serialize(std::string& output) const
{
    SpringCat::System::Stream output_stream;
    if (serialize(output_stream) == false)
    {
        return false;
    }

    size_t output_size = output_stream.GetLength();
    std::string buffer;
    buffer.resize(output_size);
    if (output_stream.Peek(&buffer[0], output_size) != output_size)
    {
        return false;
    }

    output.swap(buffer);

    return true;
}

bool internal_register_ps_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }

    return true;
}

bool internal_register_ps_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool internal_register_ps_ans::deserialize(std::string& input)
{
    size_t input_size = input.size();
    SpringCat::System::Stream input_stream(input_size);
    if (input_stream.Write(&input[0], input_size) != input_size)
    {
        return false;
    }

    if (deserialize(input_stream) == false)
    {
        return false;
    }

    input.clear();

    return true;
}

SpringCat::int16_t internal_register_ps_ans::get_result(void) const
{
    return result_;
}

void internal_register_ps_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

player_requisite_info::player_requisite_info(void)
    : __has_bits__(),
    is_ai_(false),
    profile_(new player_profile_info),
    selected_car_(new vehicle),
    equipped_ability_(new ability_slot),
    abilities_(new ability_list),
    match_items_(new match_item_info)
{
}

player_requisite_info::player_requisite_info(const player_requisite_info& from)
    : __has_bits__(),
    is_ai_(false),
    profile_(new player_profile_info),
    selected_car_(new vehicle),
    equipped_ability_(new ability_slot),
    abilities_(new ability_list),
    match_items_(new match_item_info)
{
    merge_from(from);
}

player_requisite_info::~player_requisite_info(void)
{
}

const SpringCat::Wave::type_info& player_requisite_info::static_type_info(void)
{
    return __player_requisite_info_type_info__;
}

const SpringCat::Wave::type_info& player_requisite_info::runtime_type_info(void) const
{
    return static_type_info();
}

player_requisite_info* player_requisite_info::new_instance(void) const
{
    return new player_requisite_info;
}

player_requisite_info* player_requisite_info::clone(void) const
{
    return new player_requisite_info(*this);
}

void player_requisite_info::clear(void)
{
    // is_ai
    is_ai_ = false;
    // profile
    profile_->clear();
    // selected_car
    selected_car_->clear();
    // equipped_ability
    equipped_ability_->clear();
    // abilities
    abilities_->clear();
    // match_items
    match_items_->clear();
}

bool player_requisite_info::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t player_requisite_info::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // is_ai
    total_size += SpringCat::Wave::internal::size(is_ai_);
    // profile
    total_size += SpringCat::Wave::internal::size(*profile_);
    // selected_car
    total_size += SpringCat::Wave::internal::size(*selected_car_);
    // equipped_ability
    total_size += SpringCat::Wave::internal::size(*equipped_ability_);
    // abilities
    total_size += SpringCat::Wave::internal::size(*abilities_);
    // match_items
    total_size += SpringCat::Wave::internal::size(*match_items_);

    return total_size;
}

void player_requisite_info::copy_from(const SpringCat::Wave::object_base& from)
{
    const player_requisite_info& src = dynamic_cast<const player_requisite_info&>(from);
    copy_from(src);
}

void player_requisite_info::copy_from(const player_requisite_info& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void player_requisite_info::merge_from(const SpringCat::Wave::object_base& from)
{
    const player_requisite_info& src = dynamic_cast<const player_requisite_info&>(from);
    merge_from(src);
}

void player_requisite_info::merge_from(const player_requisite_info& from)
{
    if (&from == this)
    {
        return;
    }

    // is_ai
    set_is_ai(from.get_is_ai());
    // profile
    profile_->merge_from(*from.get_profile());
    // selected_car
    selected_car_->merge_from(*from.get_selected_car());
    // equipped_ability
    equipped_ability_->merge_from(*from.get_equipped_ability());
    // abilities
    abilities_->merge_from(*from.get_abilities());
    // match_items
    match_items_->merge_from(*from.get_match_items());
}

bool player_requisite_info::serialize(SpringCat::System::Stream& output) const
{
    // is_ai
    if (SpringCat::Wave::internal::serialize(output, is_ai_) == false)
    {
        return false;
    }
    // profile
    if (SpringCat::Wave::internal::serialize(output, *profile_) == false)
    {
        return false;
    }
    // selected_car
    if (SpringCat::Wave::internal::serialize(output, *selected_car_) == false)
    {
        return false;
    }
    // equipped_ability
    if (SpringCat::Wave::internal::serialize(output, *equipped_ability_) == false)
    {
        return false;
    }
    // abilities
    if (SpringCat::Wave::internal::serialize(output, *abilities_) == false)
    {
        return false;
    }
    // match_items
    if (SpringCat::Wave::internal::serialize(output, *match_items_) == false)
    {
        return false;
    }

    return true;
}

bool player_requisite_info::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool player_requisite_info::serialize(std::string& output) const
{
    SpringCat::System::Stream output_stream;
    if (serialize(output_stream) == false)
    {
        return false;
    }

    size_t output_size = output_stream.GetLength();
    std::string buffer;
    buffer.resize(output_size);
    if (output_stream.Peek(&buffer[0], output_size) != output_size)
    {
        return false;
    }

    output.swap(buffer);

    return true;
}

bool player_requisite_info::deserialize(SpringCat::System::Stream& input)
{
    // is_ai
    if (SpringCat::Wave::internal::deserialize(input, is_ai_) == false)
    {
        return false;
    }
    // profile
    if (SpringCat::Wave::internal::deserialize(input, *profile_) == false)
    {
        return false;
    }
    // selected_car
    if (SpringCat::Wave::internal::deserialize(input, *selected_car_) == false)
    {
        return false;
    }
    // equipped_ability
    if (SpringCat::Wave::internal::deserialize(input, *equipped_ability_) == false)
    {
        return false;
    }
    // abilities
    if (SpringCat::Wave::internal::deserialize(input, *abilities_) == false)
    {
        return false;
    }
    // match_items
    if (SpringCat::Wave::internal::deserialize(input, *match_items_) == false)
    {
        return false;
    }

    return true;
}

bool player_requisite_info::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool player_requisite_info::deserialize(std::string& input)
{
    size_t input_size = input.size();
    SpringCat::System::Stream input_stream(input_size);
    if (input_stream.Write(&input[0], input_size) != input_size)
    {
        return false;
    }

    if (deserialize(input_stream) == false)
    {
        return false;
    }

    input.clear();

    return true;
}

bool player_requisite_info::get_is_ai(void) const
{
    return is_ai_;
}

void player_requisite_info::set_is_ai(bool value)
{
    is_ai_ = value;
}

const player_profile_info* player_requisite_info::get_profile(void) const
{
    return profile_.get();
}

player_profile_info* player_requisite_info::get_mutable_profile(void)
{
    return profile_.get();
}

const vehicle* player_requisite_info::get_selected_car(void) const
{
    return selected_car_.get();
}

vehicle* player_requisite_info::get_mutable_selected_car(void)
{
    return selected_car_.get();
}

const ability_slot* player_requisite_info::get_equipped_ability(void) const
{
    return equipped_ability_.get();
}

ability_slot* player_requisite_info::get_mutable_equipped_ability(void)
{
    return equipped_ability_.get();
}

const ability_list* player_requisite_info::get_abilities(void) const
{
    return abilities_.get();
}

ability_list* player_requisite_info::get_mutable_abilities(void)
{
    return abilities_.get();
}

const match_item_info* player_requisite_info::get_match_items(void) const
{
    return match_items_.get();
}

match_item_info* player_requisite_info::get_mutable_match_items(void)
{
    return match_items_.get();
}

internal_start_game_req::internal_start_game_req(void)
    : __has_bits__(),
    player_infos_()
{
}

internal_start_game_req::internal_start_game_req(const internal_start_game_req& from)
    : __has_bits__(),
    player_infos_()
{
    merge_from(from);
}

internal_start_game_req::~internal_start_game_req(void)
{
    // player_infos
    for(std::map<SpringCat::uint64_t, player_requisite_info*>::iterator it = player_infos_.begin(); it != player_infos_.end(); ++it)
    {
        delete it->second;
    }
    player_infos_.clear();
}

const SpringCat::Wave::type_info& internal_start_game_req::static_type_info(void)
{
    return __internal_start_game_req_type_info__;
}

const SpringCat::Wave::type_info& internal_start_game_req::runtime_type_info(void) const
{
    return static_type_info();
}

internal_start_game_req* internal_start_game_req::new_instance(void) const
{
    return new internal_start_game_req;
}

internal_start_game_req* internal_start_game_req::clone(void) const
{
    return new internal_start_game_req(*this);
}

void internal_start_game_req::clear(void)
{
    // player_infos
    for(std::map<SpringCat::uint64_t, player_requisite_info*>::iterator it = player_infos_.begin(); it != player_infos_.end(); ++it)
    {
        delete it->second;
    }
    player_infos_.clear();
}

bool internal_start_game_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t internal_start_game_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // player_infos
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint32_t));
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint64_t) * player_infos_.size());
    for(std::map<SpringCat::uint64_t, player_requisite_info*>::const_iterator it = player_infos_.begin(); it != player_infos_.end(); ++it)
    {
        total_size += SpringCat::Wave::internal::size(*it->second);
    }

    return total_size;
}

void internal_start_game_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const internal_start_game_req& src = dynamic_cast<const internal_start_game_req&>(from);
    copy_from(src);
}

void internal_start_game_req::copy_from(const internal_start_game_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void internal_start_game_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const internal_start_game_req& src = dynamic_cast<const internal_start_game_req&>(from);
    merge_from(src);
}

void internal_start_game_req::merge_from(const internal_start_game_req& from)
{
    if (&from == this)
    {
        return;
    }

    // player_infos
    for(std::map<SpringCat::uint64_t, player_requisite_info*>::const_iterator it = from.player_infos_.begin(); it != from.player_infos_.end(); ++it)
    {
        insert_player_infos(it->first)->copy_from(*it->second);
    }
}

bool internal_start_game_req::serialize(SpringCat::System::Stream& output) const
{
    // player_infos
    SpringCat::uint32_t player_infos_size = static_cast<SpringCat::uint32_t>(player_infos_.size());
    if (SpringCat::Wave::internal::serialize(output, player_infos_size) == false)
    {
        return false;
    }
    for(std::map<SpringCat::uint64_t, player_requisite_info*>::const_iterator it = player_infos_.begin(); it != player_infos_.end(); ++it)
    {
        if (SpringCat::Wave::internal::serialize(output, it->first) == false)
        {
            return false;
        }
        if (SpringCat::Wave::internal::serialize(output, *it->second) == false)
        {
            return false;
        }
    }

    return true;
}

bool internal_start_game_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool internal_start_game_req::serialize(std::string& output) const
{
    SpringCat::System::Stream output_stream;
    if (serialize(output_stream) == false)
    {
        return false;
    }

    size_t output_size = output_stream.GetLength();
    std::string buffer;
    buffer.resize(output_size);
    if (output_stream.Peek(&buffer[0], output_size) != output_size)
    {
        return false;
    }

    output.swap(buffer);

    return true;
}

bool internal_start_game_req::deserialize(SpringCat::System::Stream& input)
{
    // player_infos
    SpringCat::uint32_t player_infos_size = 0;
    if (SpringCat::Wave::internal::deserialize(input, player_infos_size) == false)
    {
        return false;
    }
    for (SpringCat::uint32_t i = 0; i != player_infos_size; ++i)
    {
        SpringCat::uint64_t key;
        if (SpringCat::Wave::internal::deserialize(input, key) == false)
        {
            return false;
        }
        player_requisite_info* inserted = insert_player_infos(key);
        if (SpringCat::Wave::internal::deserialize(input, *inserted) == false)
        {
        	return false;
        }
    }

    return true;
}

bool internal_start_game_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool internal_start_game_req::deserialize(std::string& input)
{
    size_t input_size = input.size();
    SpringCat::System::Stream input_stream(input_size);
    if (input_stream.Write(&input[0], input_size) != input_size)
    {
        return false;
    }

    if (deserialize(input_stream) == false)
    {
        return false;
    }

    input.clear();

    return true;
}

const std::map<SpringCat::uint64_t, player_requisite_info*>& internal_start_game_req::get_player_infos(void) const
{
    return player_infos_;
}

std::map<SpringCat::uint64_t, player_requisite_info*>* internal_start_game_req::get_mutable_player_infos(void)
{
    return &player_infos_;
}

const player_requisite_info* internal_start_game_req::get_player_infos(SpringCat::uint64_t key) const
{
    std::map<SpringCat::uint64_t, player_requisite_info*>::const_iterator it = player_infos_.find(key);
    if(it == player_infos_.end())
    {
        return NULL;
    }
    return it->second;
}

player_requisite_info* internal_start_game_req::get_mutable_player_infos(SpringCat::uint64_t key)
{
    std::map<SpringCat::uint64_t, player_requisite_info*>::iterator it = player_infos_.find(key);
    if(it == player_infos_.end())
    {
        return NULL;
    }
    return it->second;
}

player_requisite_info* internal_start_game_req::insert_player_infos(SpringCat::uint64_t key)
{
    std::map<SpringCat::uint64_t, player_requisite_info*>::iterator it = player_infos_.find(key);
    if(it != player_infos_.end())
    {
        return it->second;
    }
    std::auto_ptr<player_requisite_info> new_player_infos(new player_requisite_info);
    player_infos_.insert(std::make_pair(key, new_player_infos.get()));
    return new_player_infos.release();
}

internal_start_game_ans::internal_start_game_ans(void)
    : __has_bits__(),
    result_(0)
{
}

internal_start_game_ans::internal_start_game_ans(const internal_start_game_ans& from)
    : __has_bits__(),
    result_(0)
{
    merge_from(from);
}

internal_start_game_ans::~internal_start_game_ans(void)
{
}

const SpringCat::Wave::type_info& internal_start_game_ans::static_type_info(void)
{
    return __internal_start_game_ans_type_info__;
}

const SpringCat::Wave::type_info& internal_start_game_ans::runtime_type_info(void) const
{
    return static_type_info();
}

internal_start_game_ans* internal_start_game_ans::new_instance(void) const
{
    return new internal_start_game_ans;
}

internal_start_game_ans* internal_start_game_ans::clone(void) const
{
    return new internal_start_game_ans(*this);
}

void internal_start_game_ans::clear(void)
{
    // result
    result_ = 0;
}

bool internal_start_game_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t internal_start_game_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);

    return total_size;
}

void internal_start_game_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const internal_start_game_ans& src = dynamic_cast<const internal_start_game_ans&>(from);
    copy_from(src);
}

void internal_start_game_ans::copy_from(const internal_start_game_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void internal_start_game_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const internal_start_game_ans& src = dynamic_cast<const internal_start_game_ans&>(from);
    merge_from(src);
}

void internal_start_game_ans::merge_from(const internal_start_game_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
}

bool internal_start_game_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }

    return true;
}

bool internal_start_game_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool internal_start_game_ans::serialize(std::string& output) const
{
    SpringCat::System::Stream output_stream;
    if (serialize(output_stream) == false)
    {
        return false;
    }

    size_t output_size = output_stream.GetLength();
    std::string buffer;
    buffer.resize(output_size);
    if (output_stream.Peek(&buffer[0], output_size) != output_size)
    {
        return false;
    }

    output.swap(buffer);

    return true;
}

bool internal_start_game_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }

    return true;
}

bool internal_start_game_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool internal_start_game_ans::deserialize(std::string& input)
{
    size_t input_size = input.size();
    SpringCat::System::Stream input_stream(input_size);
    if (input_stream.Write(&input[0], input_size) != input_size)
    {
        return false;
    }

    if (deserialize(input_stream) == false)
    {
        return false;
    }

    input.clear();

    return true;
}

SpringCat::int16_t internal_start_game_ans::get_result(void) const
{
    return result_;
}

void internal_start_game_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

internal_player_end_game_report_req::internal_player_end_game_report_req(void)
    : __has_bits__(),
    player_no_(0),
    using_vehicle_no_(0),
    giveup_game_(false),
    final_rank_(0),
    inc_game_money_(0),
    inc_player_exp_(0),
    play_data_()
{
}

internal_player_end_game_report_req::internal_player_end_game_report_req(const internal_player_end_game_report_req& from)
    : __has_bits__(),
    player_no_(0),
    using_vehicle_no_(0),
    giveup_game_(false),
    final_rank_(0),
    inc_game_money_(0),
    inc_player_exp_(0),
    play_data_()
{
    merge_from(from);
}

internal_player_end_game_report_req::~internal_player_end_game_report_req(void)
{
    // play_data
    play_data_.clear();
}

const SpringCat::Wave::type_info& internal_player_end_game_report_req::static_type_info(void)
{
    return __internal_player_end_game_report_req_type_info__;
}

const SpringCat::Wave::type_info& internal_player_end_game_report_req::runtime_type_info(void) const
{
    return static_type_info();
}

internal_player_end_game_report_req* internal_player_end_game_report_req::new_instance(void) const
{
    return new internal_player_end_game_report_req;
}

internal_player_end_game_report_req* internal_player_end_game_report_req::clone(void) const
{
    return new internal_player_end_game_report_req(*this);
}

void internal_player_end_game_report_req::clear(void)
{
    // player_no
    player_no_ = 0;
    // using_vehicle_no
    using_vehicle_no_ = 0;
    // giveup_game
    giveup_game_ = false;
    // final_rank
    final_rank_ = 0;
    // inc_game_money
    inc_game_money_ = 0;
    // inc_player_exp
    inc_player_exp_ = 0;
    // play_data
    play_data_.clear();
}

bool internal_player_end_game_report_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t internal_player_end_game_report_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // player_no
    total_size += SpringCat::Wave::internal::size(player_no_);
    // using_vehicle_no
    total_size += SpringCat::Wave::internal::size(using_vehicle_no_);
    // giveup_game
    total_size += SpringCat::Wave::internal::size(giveup_game_);
    // final_rank
    total_size += SpringCat::Wave::internal::size(final_rank_);
    // inc_game_money
    total_size += SpringCat::Wave::internal::size(inc_game_money_);
    // inc_player_exp
    total_size += SpringCat::Wave::internal::size(inc_player_exp_);
    // play_data
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint32_t));
    total_size += static_cast<SpringCat::uint32_t>(sizeof(record_data_key) * play_data_.size());
    for(std::map<record_data_key, SpringCat::int32_t>::const_iterator it = play_data_.begin(); it != play_data_.end(); ++it)
    {
        total_size += sizeof(it->second);
    }

    return total_size;
}

void internal_player_end_game_report_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const internal_player_end_game_report_req& src = dynamic_cast<const internal_player_end_game_report_req&>(from);
    copy_from(src);
}

void internal_player_end_game_report_req::copy_from(const internal_player_end_game_report_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void internal_player_end_game_report_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const internal_player_end_game_report_req& src = dynamic_cast<const internal_player_end_game_report_req&>(from);
    merge_from(src);
}

void internal_player_end_game_report_req::merge_from(const internal_player_end_game_report_req& from)
{
    if (&from == this)
    {
        return;
    }

    // player_no
    set_player_no(from.get_player_no());
    // using_vehicle_no
    set_using_vehicle_no(from.get_using_vehicle_no());
    // giveup_game
    set_giveup_game(from.get_giveup_game());
    // final_rank
    set_final_rank(from.get_final_rank());
    // inc_game_money
    set_inc_game_money(from.get_inc_game_money());
    // inc_player_exp
    set_inc_player_exp(from.get_inc_player_exp());
    // play_data
    for(std::map<record_data_key, SpringCat::int32_t>::const_iterator it = from.play_data_.begin(); it != from.play_data_.end(); ++it)
    {
        insert_play_data(it->first, it->second);
    }
}

bool internal_player_end_game_report_req::serialize(SpringCat::System::Stream& output) const
{
    // player_no
    if (SpringCat::Wave::internal::serialize(output, player_no_) == false)
    {
        return false;
    }
    // using_vehicle_no
    if (SpringCat::Wave::internal::serialize(output, using_vehicle_no_) == false)
    {
        return false;
    }
    // giveup_game
    if (SpringCat::Wave::internal::serialize(output, giveup_game_) == false)
    {
        return false;
    }
    // final_rank
    if (SpringCat::Wave::internal::serialize(output, final_rank_) == false)
    {
        return false;
    }
    // inc_game_money
    if (SpringCat::Wave::internal::serialize(output, inc_game_money_) == false)
    {
        return false;
    }
    // inc_player_exp
    if (SpringCat::Wave::internal::serialize(output, inc_player_exp_) == false)
    {
        return false;
    }
    // play_data
    SpringCat::uint32_t play_data_size = static_cast<SpringCat::uint32_t>(play_data_.size());
    if (SpringCat::Wave::internal::serialize(output, play_data_size) == false)
    {
        return false;
    }
    for(std::map<record_data_key, SpringCat::int32_t>::const_iterator it = play_data_.begin(); it != play_data_.end(); ++it)
    {
        if (SpringCat::Wave::internal::serialize(output, it->first) == false)
        {
            return false;
        }
        if (SpringCat::Wave::internal::serialize(output, it->second) == false)
        {
            return false;
        }
    }

    return true;
}

bool internal_player_end_game_report_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool internal_player_end_game_report_req::serialize(std::string& output) const
{
    SpringCat::System::Stream output_stream;
    if (serialize(output_stream) == false)
    {
        return false;
    }

    size_t output_size = output_stream.GetLength();
    std::string buffer;
    buffer.resize(output_size);
    if (output_stream.Peek(&buffer[0], output_size) != output_size)
    {
        return false;
    }

    output.swap(buffer);

    return true;
}

bool internal_player_end_game_report_req::deserialize(SpringCat::System::Stream& input)
{
    // player_no
    if (SpringCat::Wave::internal::deserialize(input, player_no_) == false)
    {
        return false;
    }
    // using_vehicle_no
    if (SpringCat::Wave::internal::deserialize(input, using_vehicle_no_) == false)
    {
        return false;
    }
    // giveup_game
    if (SpringCat::Wave::internal::deserialize(input, giveup_game_) == false)
    {
        return false;
    }
    // final_rank
    if (SpringCat::Wave::internal::deserialize(input, final_rank_) == false)
    {
        return false;
    }
    // inc_game_money
    if (SpringCat::Wave::internal::deserialize(input, inc_game_money_) == false)
    {
        return false;
    }
    // inc_player_exp
    if (SpringCat::Wave::internal::deserialize(input, inc_player_exp_) == false)
    {
        return false;
    }
    // play_data
    SpringCat::uint32_t play_data_size = 0;
    if (SpringCat::Wave::internal::deserialize(input, play_data_size) == false)
    {
        return false;
    }
    for (SpringCat::uint32_t i = 0; i != play_data_size; ++i)
    {
        SpringCat::int32_t key;
        if (SpringCat::Wave::internal::deserialize(input, key) == false)
        {
            return false;
        }
        SpringCat::int32_t value;
        if (SpringCat::Wave::internal::deserialize(input, value) == false)
        {
            return false;
        }
        insert_play_data(static_cast<record_data_key>(key), value);
    }

    return true;
}

bool internal_player_end_game_report_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool internal_player_end_game_report_req::deserialize(std::string& input)
{
    size_t input_size = input.size();
    SpringCat::System::Stream input_stream(input_size);
    if (input_stream.Write(&input[0], input_size) != input_size)
    {
        return false;
    }

    if (deserialize(input_stream) == false)
    {
        return false;
    }

    input.clear();

    return true;
}

SpringCat::uint64_t internal_player_end_game_report_req::get_player_no(void) const
{
    return player_no_;
}

void internal_player_end_game_report_req::set_player_no(SpringCat::uint64_t value)
{
    player_no_ = value;
}

SpringCat::int32_t internal_player_end_game_report_req::get_using_vehicle_no(void) const
{
    return using_vehicle_no_;
}

void internal_player_end_game_report_req::set_using_vehicle_no(SpringCat::int32_t value)
{
    using_vehicle_no_ = value;
}

bool internal_player_end_game_report_req::get_giveup_game(void) const
{
    return giveup_game_;
}

void internal_player_end_game_report_req::set_giveup_game(bool value)
{
    giveup_game_ = value;
}

SpringCat::int8_t internal_player_end_game_report_req::get_final_rank(void) const
{
    return final_rank_;
}

void internal_player_end_game_report_req::set_final_rank(SpringCat::int8_t value)
{
    final_rank_ = value;
}

SpringCat::int16_t internal_player_end_game_report_req::get_inc_game_money(void) const
{
    return inc_game_money_;
}

void internal_player_end_game_report_req::set_inc_game_money(SpringCat::int16_t value)
{
    inc_game_money_ = value;
}

SpringCat::int16_t internal_player_end_game_report_req::get_inc_player_exp(void) const
{
    return inc_player_exp_;
}

void internal_player_end_game_report_req::set_inc_player_exp(SpringCat::int16_t value)
{
    inc_player_exp_ = value;
}

const std::map<record_data_key, SpringCat::int32_t>& internal_player_end_game_report_req::get_play_data(void) const
{
    return play_data_;
}

std::map<record_data_key, SpringCat::int32_t>* internal_player_end_game_report_req::get_mutable_play_data(void)
{
    return &play_data_;
}

bool internal_player_end_game_report_req::get_play_data(record_data_key key, SpringCat::int32_t* value) const
{
    std::map<record_data_key, SpringCat::int32_t>::const_iterator it = play_data_.find(key);
    if(it == play_data_.end())
    {
        return false;
    }

    if(value)
    {
        *value = it->second;
    }

    return true;
}

void internal_player_end_game_report_req::set_play_data(record_data_key key, SpringCat::int32_t value)
{
    play_data_[key] = value;
}

bool internal_player_end_game_report_req::insert_play_data(record_data_key key, SpringCat::int32_t value)
{
    return play_data_.insert(std::make_pair(key, value)).second;
}


internal_player_end_game_report_ans::internal_player_end_game_report_ans(void)
    : __has_bits__(),
    player_no_(0),
    giveup_game_(false),
    final_rank_(0),
    first_acquired_stuff_id_(0),
    second_acquired_stuff_id_(0)
{
}

internal_player_end_game_report_ans::internal_player_end_game_report_ans(const internal_player_end_game_report_ans& from)
    : __has_bits__(),
    player_no_(0),
    giveup_game_(false),
    final_rank_(0),
    first_acquired_stuff_id_(0),
    second_acquired_stuff_id_(0)
{
    merge_from(from);
}

internal_player_end_game_report_ans::~internal_player_end_game_report_ans(void)
{
}

const SpringCat::Wave::type_info& internal_player_end_game_report_ans::static_type_info(void)
{
    return __internal_player_end_game_report_ans_type_info__;
}

const SpringCat::Wave::type_info& internal_player_end_game_report_ans::runtime_type_info(void) const
{
    return static_type_info();
}

internal_player_end_game_report_ans* internal_player_end_game_report_ans::new_instance(void) const
{
    return new internal_player_end_game_report_ans;
}

internal_player_end_game_report_ans* internal_player_end_game_report_ans::clone(void) const
{
    return new internal_player_end_game_report_ans(*this);
}

void internal_player_end_game_report_ans::clear(void)
{
    // player_no
    player_no_ = 0;
    // giveup_game
    giveup_game_ = false;
    // final_rank
    final_rank_ = 0;
    // first_acquired_stuff_id
    first_acquired_stuff_id_ = 0;
    // second_acquired_stuff_id
    second_acquired_stuff_id_ = 0;
}

bool internal_player_end_game_report_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t internal_player_end_game_report_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // player_no
    total_size += SpringCat::Wave::internal::size(player_no_);
    // giveup_game
    total_size += SpringCat::Wave::internal::size(giveup_game_);
    // final_rank
    total_size += SpringCat::Wave::internal::size(final_rank_);
    // first_acquired_stuff_id
    total_size += SpringCat::Wave::internal::size(first_acquired_stuff_id_);
    // second_acquired_stuff_id
    total_size += SpringCat::Wave::internal::size(second_acquired_stuff_id_);

    return total_size;
}

void internal_player_end_game_report_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const internal_player_end_game_report_ans& src = dynamic_cast<const internal_player_end_game_report_ans&>(from);
    copy_from(src);
}

void internal_player_end_game_report_ans::copy_from(const internal_player_end_game_report_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void internal_player_end_game_report_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const internal_player_end_game_report_ans& src = dynamic_cast<const internal_player_end_game_report_ans&>(from);
    merge_from(src);
}

void internal_player_end_game_report_ans::merge_from(const internal_player_end_game_report_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // player_no
    set_player_no(from.get_player_no());
    // giveup_game
    set_giveup_game(from.get_giveup_game());
    // final_rank
    set_final_rank(from.get_final_rank());
    // first_acquired_stuff_id
    set_first_acquired_stuff_id(from.get_first_acquired_stuff_id());
    // second_acquired_stuff_id
    set_second_acquired_stuff_id(from.get_second_acquired_stuff_id());
}

bool internal_player_end_game_report_ans::serialize(SpringCat::System::Stream& output) const
{
    // player_no
    if (SpringCat::Wave::internal::serialize(output, player_no_) == false)
    {
        return false;
    }
    // giveup_game
    if (SpringCat::Wave::internal::serialize(output, giveup_game_) == false)
    {
        return false;
    }
    // final_rank
    if (SpringCat::Wave::internal::serialize(output, final_rank_) == false)
    {
        return false;
    }
    // first_acquired_stuff_id
    if (SpringCat::Wave::internal::serialize(output, first_acquired_stuff_id_) == false)
    {
        return false;
    }
    // second_acquired_stuff_id
    if (SpringCat::Wave::internal::serialize(output, second_acquired_stuff_id_) == false)
    {
        return false;
    }

    return true;
}

bool internal_player_end_game_report_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool internal_player_end_game_report_ans::serialize(std::string& output) const
{
    SpringCat::System::Stream output_stream;
    if (serialize(output_stream) == false)
    {
        return false;
    }

    size_t output_size = output_stream.GetLength();
    std::string buffer;
    buffer.resize(output_size);
    if (output_stream.Peek(&buffer[0], output_size) != output_size)
    {
        return false;
    }

    output.swap(buffer);

    return true;
}

bool internal_player_end_game_report_ans::deserialize(SpringCat::System::Stream& input)
{
    // player_no
    if (SpringCat::Wave::internal::deserialize(input, player_no_) == false)
    {
        return false;
    }
    // giveup_game
    if (SpringCat::Wave::internal::deserialize(input, giveup_game_) == false)
    {
        return false;
    }
    // final_rank
    if (SpringCat::Wave::internal::deserialize(input, final_rank_) == false)
    {
        return false;
    }
    // first_acquired_stuff_id
    if (SpringCat::Wave::internal::deserialize(input, first_acquired_stuff_id_) == false)
    {
        return false;
    }
    // second_acquired_stuff_id
    if (SpringCat::Wave::internal::deserialize(input, second_acquired_stuff_id_) == false)
    {
        return false;
    }

    return true;
}

bool internal_player_end_game_report_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool internal_player_end_game_report_ans::deserialize(std::string& input)
{
    size_t input_size = input.size();
    SpringCat::System::Stream input_stream(input_size);
    if (input_stream.Write(&input[0], input_size) != input_size)
    {
        return false;
    }

    if (deserialize(input_stream) == false)
    {
        return false;
    }

    input.clear();

    return true;
}

SpringCat::uint64_t internal_player_end_game_report_ans::get_player_no(void) const
{
    return player_no_;
}

void internal_player_end_game_report_ans::set_player_no(SpringCat::uint64_t value)
{
    player_no_ = value;
}

bool internal_player_end_game_report_ans::get_giveup_game(void) const
{
    return giveup_game_;
}

void internal_player_end_game_report_ans::set_giveup_game(bool value)
{
    giveup_game_ = value;
}

SpringCat::int8_t internal_player_end_game_report_ans::get_final_rank(void) const
{
    return final_rank_;
}

void internal_player_end_game_report_ans::set_final_rank(SpringCat::int8_t value)
{
    final_rank_ = value;
}

SpringCat::int32_t internal_player_end_game_report_ans::get_first_acquired_stuff_id(void) const
{
    return first_acquired_stuff_id_;
}

void internal_player_end_game_report_ans::set_first_acquired_stuff_id(SpringCat::int32_t value)
{
    first_acquired_stuff_id_ = value;
}

SpringCat::int32_t internal_player_end_game_report_ans::get_second_acquired_stuff_id(void) const
{
    return second_acquired_stuff_id_;
}

void internal_player_end_game_report_ans::set_second_acquired_stuff_id(SpringCat::int32_t value)
{
    second_acquired_stuff_id_ = value;
}

internal_end_game_req::internal_end_game_req(void)
    : __has_bits__(),
    ps_no_(0)
{
}

internal_end_game_req::internal_end_game_req(const internal_end_game_req& from)
    : __has_bits__(),
    ps_no_(0)
{
    merge_from(from);
}

internal_end_game_req::~internal_end_game_req(void)
{
}

const SpringCat::Wave::type_info& internal_end_game_req::static_type_info(void)
{
    return __internal_end_game_req_type_info__;
}

const SpringCat::Wave::type_info& internal_end_game_req::runtime_type_info(void) const
{
    return static_type_info();
}

internal_end_game_req* internal_end_game_req::new_instance(void) const
{
    return new internal_end_game_req;
}

internal_end_game_req* internal_end_game_req::clone(void) const
{
    return new internal_end_game_req(*this);
}

void internal_end_game_req::clear(void)
{
    // ps_no
    ps_no_ = 0;
}

bool internal_end_game_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t internal_end_game_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // ps_no
    total_size += SpringCat::Wave::internal::size(ps_no_);

    return total_size;
}

void internal_end_game_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const internal_end_game_req& src = dynamic_cast<const internal_end_game_req&>(from);
    copy_from(src);
}

void internal_end_game_req::copy_from(const internal_end_game_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void internal_end_game_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const internal_end_game_req& src = dynamic_cast<const internal_end_game_req&>(from);
    merge_from(src);
}

void internal_end_game_req::merge_from(const internal_end_game_req& from)
{
    if (&from == this)
    {
        return;
    }

    // ps_no
    set_ps_no(from.get_ps_no());
}

bool internal_end_game_req::serialize(SpringCat::System::Stream& output) const
{
    // ps_no
    if (SpringCat::Wave::internal::serialize(output, ps_no_) == false)
    {
        return false;
    }

    return true;
}

bool internal_end_game_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool internal_end_game_req::serialize(std::string& output) const
{
    SpringCat::System::Stream output_stream;
    if (serialize(output_stream) == false)
    {
        return false;
    }

    size_t output_size = output_stream.GetLength();
    std::string buffer;
    buffer.resize(output_size);
    if (output_stream.Peek(&buffer[0], output_size) != output_size)
    {
        return false;
    }

    output.swap(buffer);

    return true;
}

bool internal_end_game_req::deserialize(SpringCat::System::Stream& input)
{
    // ps_no
    if (SpringCat::Wave::internal::deserialize(input, ps_no_) == false)
    {
        return false;
    }

    return true;
}

bool internal_end_game_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool internal_end_game_req::deserialize(std::string& input)
{
    size_t input_size = input.size();
    SpringCat::System::Stream input_stream(input_size);
    if (input_stream.Write(&input[0], input_size) != input_size)
    {
        return false;
    }

    if (deserialize(input_stream) == false)
    {
        return false;
    }

    input.clear();

    return true;
}

SpringCat::int32_t internal_end_game_req::get_ps_no(void) const
{
    return ps_no_;
}

void internal_end_game_req::set_ps_no(SpringCat::int32_t value)
{
    ps_no_ = value;
}

internal_end_game_ans::internal_end_game_ans(void)
    : __has_bits__(),
    result_(0)
{
}

internal_end_game_ans::internal_end_game_ans(const internal_end_game_ans& from)
    : __has_bits__(),
    result_(0)
{
    merge_from(from);
}

internal_end_game_ans::~internal_end_game_ans(void)
{
}

const SpringCat::Wave::type_info& internal_end_game_ans::static_type_info(void)
{
    return __internal_end_game_ans_type_info__;
}

const SpringCat::Wave::type_info& internal_end_game_ans::runtime_type_info(void) const
{
    return static_type_info();
}

internal_end_game_ans* internal_end_game_ans::new_instance(void) const
{
    return new internal_end_game_ans;
}

internal_end_game_ans* internal_end_game_ans::clone(void) const
{
    return new internal_end_game_ans(*this);
}

void internal_end_game_ans::clear(void)
{
    // result
    result_ = 0;
}

bool internal_end_game_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t internal_end_game_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);

    return total_size;
}

void internal_end_game_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const internal_end_game_ans& src = dynamic_cast<const internal_end_game_ans&>(from);
    copy_from(src);
}

void internal_end_game_ans::copy_from(const internal_end_game_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void internal_end_game_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const internal_end_game_ans& src = dynamic_cast<const internal_end_game_ans&>(from);
    merge_from(src);
}

void internal_end_game_ans::merge_from(const internal_end_game_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
}

bool internal_end_game_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }

    return true;
}

bool internal_end_game_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool internal_end_game_ans::serialize(std::string& output) const
{
    SpringCat::System::Stream output_stream;
    if (serialize(output_stream) == false)
    {
        return false;
    }

    size_t output_size = output_stream.GetLength();
    std::string buffer;
    buffer.resize(output_size);
    if (output_stream.Peek(&buffer[0], output_size) != output_size)
    {
        return false;
    }

    output.swap(buffer);

    return true;
}

bool internal_end_game_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }

    return true;
}

bool internal_end_game_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool internal_end_game_ans::deserialize(std::string& input)
{
    size_t input_size = input.size();
    SpringCat::System::Stream input_stream(input_size);
    if (input_stream.Write(&input[0], input_size) != input_size)
    {
        return false;
    }

    if (deserialize(input_stream) == false)
    {
        return false;
    }

    input.clear();

    return true;
}

SpringCat::int16_t internal_end_game_ans::get_result(void) const
{
    return result_;
}

void internal_end_game_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}



}    // namespace protocol
