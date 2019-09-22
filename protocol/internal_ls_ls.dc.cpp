#include "internal_ls_ls.dc.h"
#include <stdexcept>


namespace protocol
{

// class name: internal_player_end_game_report_notify, type id(decimal): 119367545, type id(hex): 0x71D6779
static const SpringCat::Wave::type_info __internal_player_end_game_report_notify_type_info__(0x71D6779, "protocol.internal_player_end_game_report_notify");

internal_player_end_game_report_notify::internal_player_end_game_report_notify(void)
    : __has_bits__(),
    mode_(0),
    player_no_(0),
    vehicle_no_(0),
    is_giveup_(false),
    final_rank_(0),
    inc_game_money_(0),
    inc_exp_(0),
    first_reward_stuff_id_(0),
    second_reward_stuff_id_(0),
    play_data_()
{
}

internal_player_end_game_report_notify::internal_player_end_game_report_notify(const internal_player_end_game_report_notify& from)
    : __has_bits__(),
    mode_(0),
    player_no_(0),
    vehicle_no_(0),
    is_giveup_(false),
    final_rank_(0),
    inc_game_money_(0),
    inc_exp_(0),
    first_reward_stuff_id_(0),
    second_reward_stuff_id_(0),
    play_data_()
{
    merge_from(from);
}

internal_player_end_game_report_notify::~internal_player_end_game_report_notify(void)
{
    // play_data
    play_data_.clear();
}

const SpringCat::Wave::type_info& internal_player_end_game_report_notify::static_type_info(void)
{
    return __internal_player_end_game_report_notify_type_info__;
}

const SpringCat::Wave::type_info& internal_player_end_game_report_notify::runtime_type_info(void) const
{
    return static_type_info();
}

internal_player_end_game_report_notify* internal_player_end_game_report_notify::new_instance(void) const
{
    return new internal_player_end_game_report_notify;
}

internal_player_end_game_report_notify* internal_player_end_game_report_notify::clone(void) const
{
    return new internal_player_end_game_report_notify(*this);
}

void internal_player_end_game_report_notify::clear(void)
{
    // mode
    mode_ = 0;
    // player_no
    player_no_ = 0;
    // vehicle_no
    vehicle_no_ = 0;
    // is_giveup
    is_giveup_ = false;
    // final_rank
    final_rank_ = 0;
    // inc_game_money
    inc_game_money_ = 0;
    // inc_exp
    inc_exp_ = 0;
    // first_reward_stuff_id
    first_reward_stuff_id_ = 0;
    // second_reward_stuff_id
    second_reward_stuff_id_ = 0;
    // play_data
    play_data_.clear();
}

bool internal_player_end_game_report_notify::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t internal_player_end_game_report_notify::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // mode
    total_size += SpringCat::Wave::internal::size(mode_);
    // player_no
    total_size += SpringCat::Wave::internal::size(player_no_);
    // vehicle_no
    total_size += SpringCat::Wave::internal::size(vehicle_no_);
    // is_giveup
    total_size += SpringCat::Wave::internal::size(is_giveup_);
    // final_rank
    total_size += SpringCat::Wave::internal::size(final_rank_);
    // inc_game_money
    total_size += SpringCat::Wave::internal::size(inc_game_money_);
    // inc_exp
    total_size += SpringCat::Wave::internal::size(inc_exp_);
    // first_reward_stuff_id
    total_size += SpringCat::Wave::internal::size(first_reward_stuff_id_);
    // second_reward_stuff_id
    total_size += SpringCat::Wave::internal::size(second_reward_stuff_id_);
    // play_data
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint32_t));
    total_size += static_cast<SpringCat::uint32_t>(sizeof(record_data_key) * play_data_.size());
    for(std::map<record_data_key, SpringCat::int32_t>::const_iterator it = play_data_.begin(); it != play_data_.end(); ++it)
    {
        total_size += sizeof(it->second);
    }

    return total_size;
}

void internal_player_end_game_report_notify::copy_from(const SpringCat::Wave::object_base& from)
{
    const internal_player_end_game_report_notify& src = dynamic_cast<const internal_player_end_game_report_notify&>(from);
    copy_from(src);
}

void internal_player_end_game_report_notify::copy_from(const internal_player_end_game_report_notify& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void internal_player_end_game_report_notify::merge_from(const SpringCat::Wave::object_base& from)
{
    const internal_player_end_game_report_notify& src = dynamic_cast<const internal_player_end_game_report_notify&>(from);
    merge_from(src);
}

void internal_player_end_game_report_notify::merge_from(const internal_player_end_game_report_notify& from)
{
    if (&from == this)
    {
        return;
    }

    // mode
    set_mode(from.get_mode());
    // player_no
    set_player_no(from.get_player_no());
    // vehicle_no
    set_vehicle_no(from.get_vehicle_no());
    // is_giveup
    set_is_giveup(from.get_is_giveup());
    // final_rank
    set_final_rank(from.get_final_rank());
    // inc_game_money
    set_inc_game_money(from.get_inc_game_money());
    // inc_exp
    set_inc_exp(from.get_inc_exp());
    // first_reward_stuff_id
    set_first_reward_stuff_id(from.get_first_reward_stuff_id());
    // second_reward_stuff_id
    set_second_reward_stuff_id(from.get_second_reward_stuff_id());
    // play_data
    for(std::map<record_data_key, SpringCat::int32_t>::const_iterator it = from.play_data_.begin(); it != from.play_data_.end(); ++it)
    {
        insert_play_data(it->first, it->second);
    }
}

bool internal_player_end_game_report_notify::serialize(SpringCat::System::Stream& output) const
{
    // mode
    if (SpringCat::Wave::internal::serialize(output, mode_) == false)
    {
        return false;
    }
    // player_no
    if (SpringCat::Wave::internal::serialize(output, player_no_) == false)
    {
        return false;
    }
    // vehicle_no
    if (SpringCat::Wave::internal::serialize(output, vehicle_no_) == false)
    {
        return false;
    }
    // is_giveup
    if (SpringCat::Wave::internal::serialize(output, is_giveup_) == false)
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
    // inc_exp
    if (SpringCat::Wave::internal::serialize(output, inc_exp_) == false)
    {
        return false;
    }
    // first_reward_stuff_id
    if (SpringCat::Wave::internal::serialize(output, first_reward_stuff_id_) == false)
    {
        return false;
    }
    // second_reward_stuff_id
    if (SpringCat::Wave::internal::serialize(output, second_reward_stuff_id_) == false)
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

bool internal_player_end_game_report_notify::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool internal_player_end_game_report_notify::serialize(std::string& output) const
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

bool internal_player_end_game_report_notify::deserialize(SpringCat::System::Stream& input)
{
    // mode
    if (SpringCat::Wave::internal::deserialize(input, mode_) == false)
    {
        return false;
    }
    // player_no
    if (SpringCat::Wave::internal::deserialize(input, player_no_) == false)
    {
        return false;
    }
    // vehicle_no
    if (SpringCat::Wave::internal::deserialize(input, vehicle_no_) == false)
    {
        return false;
    }
    // is_giveup
    if (SpringCat::Wave::internal::deserialize(input, is_giveup_) == false)
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
    // inc_exp
    if (SpringCat::Wave::internal::deserialize(input, inc_exp_) == false)
    {
        return false;
    }
    // first_reward_stuff_id
    if (SpringCat::Wave::internal::deserialize(input, first_reward_stuff_id_) == false)
    {
        return false;
    }
    // second_reward_stuff_id
    if (SpringCat::Wave::internal::deserialize(input, second_reward_stuff_id_) == false)
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

bool internal_player_end_game_report_notify::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool internal_player_end_game_report_notify::deserialize(std::string& input)
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

GameMode internal_player_end_game_report_notify::get_mode(void) const
{
    return static_cast<GameMode>(mode_);
}

void internal_player_end_game_report_notify::set_mode(GameMode value)
{
    mode_ = value;
}

SpringCat::uint64_t internal_player_end_game_report_notify::get_player_no(void) const
{
    return player_no_;
}

void internal_player_end_game_report_notify::set_player_no(SpringCat::uint64_t value)
{
    player_no_ = value;
}

SpringCat::int32_t internal_player_end_game_report_notify::get_vehicle_no(void) const
{
    return vehicle_no_;
}

void internal_player_end_game_report_notify::set_vehicle_no(SpringCat::int32_t value)
{
    vehicle_no_ = value;
}

bool internal_player_end_game_report_notify::get_is_giveup(void) const
{
    return is_giveup_;
}

void internal_player_end_game_report_notify::set_is_giveup(bool value)
{
    is_giveup_ = value;
}

SpringCat::int8_t internal_player_end_game_report_notify::get_final_rank(void) const
{
    return final_rank_;
}

void internal_player_end_game_report_notify::set_final_rank(SpringCat::int8_t value)
{
    final_rank_ = value;
}

SpringCat::int32_t internal_player_end_game_report_notify::get_inc_game_money(void) const
{
    return inc_game_money_;
}

void internal_player_end_game_report_notify::set_inc_game_money(SpringCat::int32_t value)
{
    inc_game_money_ = value;
}

SpringCat::int32_t internal_player_end_game_report_notify::get_inc_exp(void) const
{
    return inc_exp_;
}

void internal_player_end_game_report_notify::set_inc_exp(SpringCat::int32_t value)
{
    inc_exp_ = value;
}

SpringCat::int32_t internal_player_end_game_report_notify::get_first_reward_stuff_id(void) const
{
    return first_reward_stuff_id_;
}

void internal_player_end_game_report_notify::set_first_reward_stuff_id(SpringCat::int32_t value)
{
    first_reward_stuff_id_ = value;
}

SpringCat::int32_t internal_player_end_game_report_notify::get_second_reward_stuff_id(void) const
{
    return second_reward_stuff_id_;
}

void internal_player_end_game_report_notify::set_second_reward_stuff_id(SpringCat::int32_t value)
{
    second_reward_stuff_id_ = value;
}

const std::map<record_data_key, SpringCat::int32_t>& internal_player_end_game_report_notify::get_play_data(void) const
{
    return play_data_;
}

std::map<record_data_key, SpringCat::int32_t>* internal_player_end_game_report_notify::get_mutable_play_data(void)
{
    return &play_data_;
}

bool internal_player_end_game_report_notify::get_play_data(record_data_key key, SpringCat::int32_t* value) const
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

void internal_player_end_game_report_notify::set_play_data(record_data_key key, SpringCat::int32_t value)
{
    play_data_[key] = value;
}

bool internal_player_end_game_report_notify::insert_play_data(record_data_key key, SpringCat::int32_t value)
{
    return play_data_.insert(std::make_pair(key, value)).second;
}




}    // namespace protocol
