#include "grandprix.dc.h"
#include <stdexcept>


namespace protocol
{

// class name: grandprix_info, type id(decimal): 223596847, type id(hex): 0xD53D12F
static const SpringCat::Wave::type_info __grandprix_info_type_info__(0xD53D12F, "protocol.grandprix_info");
// class name: grandprix_rank_unit, type id(decimal): 199479348, type id(hex): 0xBE3D034
static const SpringCat::Wave::type_info __grandprix_rank_unit_type_info__(0xBE3D034, "protocol.grandprix_rank_unit");
// class name: grandprix_info_req, type id(decimal): 20593425, type id(hex): 0x13A3B11
static const SpringCat::Wave::type_info __grandprix_info_req_type_info__(0x13A3B11, "protocol.grandprix_info_req");
// class name: grandprix_info_ans, type id(decimal): 20579715, type id(hex): 0x13A0583
static const SpringCat::Wave::type_info __grandprix_info_ans_type_info__(0x13A0583, "protocol.grandprix_info_ans");
// class name: grandprix_rank_info_req, type id(decimal): 1083857, type id(hex): 0x1089D1
static const SpringCat::Wave::type_info __grandprix_rank_info_req_type_info__(0x1089D1, "protocol.grandprix_rank_info_req");
// class name: grandprix_rank_info_ans, type id(decimal): 1095491, type id(hex): 0x10B743
static const SpringCat::Wave::type_info __grandprix_rank_info_ans_type_info__(0x10B743, "protocol.grandprix_rank_info_ans");

grandprix_info::grandprix_info(void)
    : __has_bits__(),
    gp_point_(0),
    repeat_count_(0),
    reward_date_(0),
    repeat_reward_(new reward_info),
    league_(0),
    my_rank_(0),
    my_rank_percentile_(0)
{
}

grandprix_info::grandprix_info(const grandprix_info& from)
    : __has_bits__(),
    gp_point_(0),
    repeat_count_(0),
    reward_date_(0),
    repeat_reward_(new reward_info),
    league_(0),
    my_rank_(0),
    my_rank_percentile_(0)
{
    merge_from(from);
}

grandprix_info::~grandprix_info(void)
{
}

const SpringCat::Wave::type_info& grandprix_info::static_type_info(void)
{
    return __grandprix_info_type_info__;
}

const SpringCat::Wave::type_info& grandprix_info::runtime_type_info(void) const
{
    return static_type_info();
}

grandprix_info* grandprix_info::new_instance(void) const
{
    return new grandprix_info;
}

grandprix_info* grandprix_info::clone(void) const
{
    return new grandprix_info(*this);
}

void grandprix_info::clear(void)
{
    // gp_point
    gp_point_ = 0;
    // repeat_count
    repeat_count_ = 0;
    // reward_date
    reward_date_ = 0;
    // repeat_reward
    repeat_reward_->clear();
    // league
    league_ = 0;
    // my_rank
    my_rank_ = 0;
    // my_rank_percentile
    my_rank_percentile_ = 0;
}

bool grandprix_info::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t grandprix_info::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // gp_point
    total_size += SpringCat::Wave::internal::size(gp_point_);
    // repeat_count
    total_size += SpringCat::Wave::internal::size(repeat_count_);
    // reward_date
    total_size += SpringCat::Wave::internal::size(reward_date_);
    // repeat_reward
    total_size += SpringCat::Wave::internal::size(*repeat_reward_);
    // league
    total_size += SpringCat::Wave::internal::size(league_);
    // my_rank
    total_size += SpringCat::Wave::internal::size(my_rank_);
    // my_rank_percentile
    total_size += SpringCat::Wave::internal::size(my_rank_percentile_);

    return total_size;
}

void grandprix_info::copy_from(const SpringCat::Wave::object_base& from)
{
    const grandprix_info& src = dynamic_cast<const grandprix_info&>(from);
    copy_from(src);
}

void grandprix_info::copy_from(const grandprix_info& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void grandprix_info::merge_from(const SpringCat::Wave::object_base& from)
{
    const grandprix_info& src = dynamic_cast<const grandprix_info&>(from);
    merge_from(src);
}

void grandprix_info::merge_from(const grandprix_info& from)
{
    if (&from == this)
    {
        return;
    }

    // gp_point
    set_gp_point(from.get_gp_point());
    // repeat_count
    set_repeat_count(from.get_repeat_count());
    // reward_date
    set_reward_date(from.get_reward_date());
    // repeat_reward
    repeat_reward_->merge_from(*from.get_repeat_reward());
    // league
    set_league(from.get_league());
    // my_rank
    set_my_rank(from.get_my_rank());
    // my_rank_percentile
    set_my_rank_percentile(from.get_my_rank_percentile());
}

bool grandprix_info::serialize(SpringCat::System::Stream& output) const
{
    // gp_point
    if (SpringCat::Wave::internal::serialize(output, gp_point_) == false)
    {
        return false;
    }
    // repeat_count
    if (SpringCat::Wave::internal::serialize(output, repeat_count_) == false)
    {
        return false;
    }
    // reward_date
    if (SpringCat::Wave::internal::serialize(output, reward_date_) == false)
    {
        return false;
    }
    // repeat_reward
    if (SpringCat::Wave::internal::serialize(output, *repeat_reward_) == false)
    {
        return false;
    }
    // league
    if (SpringCat::Wave::internal::serialize(output, league_) == false)
    {
        return false;
    }
    // my_rank
    if (SpringCat::Wave::internal::serialize(output, my_rank_) == false)
    {
        return false;
    }
    // my_rank_percentile
    if (SpringCat::Wave::internal::serialize(output, my_rank_percentile_) == false)
    {
        return false;
    }

    return true;
}

bool grandprix_info::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool grandprix_info::serialize(std::string& output) const
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

bool grandprix_info::deserialize(SpringCat::System::Stream& input)
{
    // gp_point
    if (SpringCat::Wave::internal::deserialize(input, gp_point_) == false)
    {
        return false;
    }
    // repeat_count
    if (SpringCat::Wave::internal::deserialize(input, repeat_count_) == false)
    {
        return false;
    }
    // reward_date
    if (SpringCat::Wave::internal::deserialize(input, reward_date_) == false)
    {
        return false;
    }
    // repeat_reward
    if (SpringCat::Wave::internal::deserialize(input, *repeat_reward_) == false)
    {
        return false;
    }
    // league
    if (SpringCat::Wave::internal::deserialize(input, league_) == false)
    {
        return false;
    }
    // my_rank
    if (SpringCat::Wave::internal::deserialize(input, my_rank_) == false)
    {
        return false;
    }
    // my_rank_percentile
    if (SpringCat::Wave::internal::deserialize(input, my_rank_percentile_) == false)
    {
        return false;
    }

    return true;
}

bool grandprix_info::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool grandprix_info::deserialize(std::string& input)
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

SpringCat::int32_t grandprix_info::get_gp_point(void) const
{
    return gp_point_;
}

void grandprix_info::set_gp_point(SpringCat::int32_t value)
{
    gp_point_ = value;
}

SpringCat::int16_t grandprix_info::get_repeat_count(void) const
{
    return repeat_count_;
}

void grandprix_info::set_repeat_count(SpringCat::int16_t value)
{
    repeat_count_ = value;
}

SpringCat::int64_t grandprix_info::get_reward_date(void) const
{
    return reward_date_;
}

void grandprix_info::set_reward_date(SpringCat::int64_t value)
{
    reward_date_ = value;
}

const reward_info* grandprix_info::get_repeat_reward(void) const
{
    return repeat_reward_.get();
}

reward_info* grandprix_info::get_mutable_repeat_reward(void)
{
    return repeat_reward_.get();
}

grandprix_league grandprix_info::get_league(void) const
{
    return static_cast<grandprix_league>(league_);
}

void grandprix_info::set_league(grandprix_league value)
{
    league_ = value;
}

SpringCat::uint64_t grandprix_info::get_my_rank(void) const
{
    return my_rank_;
}

void grandprix_info::set_my_rank(SpringCat::uint64_t value)
{
    my_rank_ = value;
}

SpringCat::int32_t grandprix_info::get_my_rank_percentile(void) const
{
    return my_rank_percentile_;
}

void grandprix_info::set_my_rank_percentile(SpringCat::int32_t value)
{
    my_rank_percentile_ = value;
}

grandprix_rank_unit::grandprix_rank_unit(void)
    : __has_bits__(),
    player_no_(0),
    rank_(0),
    nation_code_(0),
    nick_(),
    level_(0),
    gp_point_(0)
{
}

grandprix_rank_unit::grandprix_rank_unit(const grandprix_rank_unit& from)
    : __has_bits__(),
    player_no_(0),
    rank_(0),
    nation_code_(0),
    nick_(),
    level_(0),
    gp_point_(0)
{
    merge_from(from);
}

grandprix_rank_unit::~grandprix_rank_unit(void)
{
}

const SpringCat::Wave::type_info& grandprix_rank_unit::static_type_info(void)
{
    return __grandprix_rank_unit_type_info__;
}

const SpringCat::Wave::type_info& grandprix_rank_unit::runtime_type_info(void) const
{
    return static_type_info();
}

grandprix_rank_unit* grandprix_rank_unit::new_instance(void) const
{
    return new grandprix_rank_unit;
}

grandprix_rank_unit* grandprix_rank_unit::clone(void) const
{
    return new grandprix_rank_unit(*this);
}

void grandprix_rank_unit::clear(void)
{
    // player_no
    player_no_ = 0;
    // rank
    rank_ = 0;
    // nation_code
    nation_code_ = 0;
    // nick
    nick_.clear();
    // level
    level_ = 0;
    // gp_point
    gp_point_ = 0;
}

bool grandprix_rank_unit::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t grandprix_rank_unit::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // player_no
    total_size += SpringCat::Wave::internal::size(player_no_);
    // rank
    total_size += SpringCat::Wave::internal::size(rank_);
    // nation_code
    total_size += SpringCat::Wave::internal::size(nation_code_);
    // nick
    total_size += SpringCat::Wave::internal::size(nick_, 0xFFFFFFFF);
    // level
    total_size += SpringCat::Wave::internal::size(level_);
    // gp_point
    total_size += SpringCat::Wave::internal::size(gp_point_);

    return total_size;
}

void grandprix_rank_unit::copy_from(const SpringCat::Wave::object_base& from)
{
    const grandprix_rank_unit& src = dynamic_cast<const grandprix_rank_unit&>(from);
    copy_from(src);
}

void grandprix_rank_unit::copy_from(const grandprix_rank_unit& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void grandprix_rank_unit::merge_from(const SpringCat::Wave::object_base& from)
{
    const grandprix_rank_unit& src = dynamic_cast<const grandprix_rank_unit&>(from);
    merge_from(src);
}

void grandprix_rank_unit::merge_from(const grandprix_rank_unit& from)
{
    if (&from == this)
    {
        return;
    }

    // player_no
    set_player_no(from.get_player_no());
    // rank
    set_rank(from.get_rank());
    // nation_code
    set_nation_code(from.get_nation_code());
    // nick
    set_nick(from.get_nick());
    // level
    set_level(from.get_level());
    // gp_point
    set_gp_point(from.get_gp_point());
}

bool grandprix_rank_unit::serialize(SpringCat::System::Stream& output) const
{
    // player_no
    if (SpringCat::Wave::internal::serialize(output, player_no_) == false)
    {
        return false;
    }
    // rank
    if (SpringCat::Wave::internal::serialize(output, rank_) == false)
    {
        return false;
    }
    // nation_code
    if (SpringCat::Wave::internal::serialize(output, nation_code_) == false)
    {
        return false;
    }
    // nick
    if (SpringCat::Wave::internal::serialize(output, nick_, 0xFFFFFFFF) == false)
    {
        return false;
    }
    // level
    if (SpringCat::Wave::internal::serialize(output, level_) == false)
    {
        return false;
    }
    // gp_point
    if (SpringCat::Wave::internal::serialize(output, gp_point_) == false)
    {
        return false;
    }

    return true;
}

bool grandprix_rank_unit::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool grandprix_rank_unit::serialize(std::string& output) const
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

bool grandprix_rank_unit::deserialize(SpringCat::System::Stream& input)
{
    // player_no
    if (SpringCat::Wave::internal::deserialize(input, player_no_) == false)
    {
        return false;
    }
    // rank
    if (SpringCat::Wave::internal::deserialize(input, rank_) == false)
    {
        return false;
    }
    // nation_code
    if (SpringCat::Wave::internal::deserialize(input, nation_code_) == false)
    {
        return false;
    }
    // nick
    if (SpringCat::Wave::internal::deserialize(input, nick_, 0xFFFFFFFF) == false)
    {
        return false;
    }
    // level
    if (SpringCat::Wave::internal::deserialize(input, level_) == false)
    {
        return false;
    }
    // gp_point
    if (SpringCat::Wave::internal::deserialize(input, gp_point_) == false)
    {
        return false;
    }

    return true;
}

bool grandprix_rank_unit::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool grandprix_rank_unit::deserialize(std::string& input)
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

SpringCat::uint64_t grandprix_rank_unit::get_player_no(void) const
{
    return player_no_;
}

void grandprix_rank_unit::set_player_no(SpringCat::uint64_t value)
{
    player_no_ = value;
}

SpringCat::uint64_t grandprix_rank_unit::get_rank(void) const
{
    return rank_;
}

void grandprix_rank_unit::set_rank(SpringCat::uint64_t value)
{
    rank_ = value;
}

SpringCat::int16_t grandprix_rank_unit::get_nation_code(void) const
{
    return nation_code_;
}

void grandprix_rank_unit::set_nation_code(SpringCat::int16_t value)
{
    nation_code_ = value;
}

const std::string& grandprix_rank_unit::get_nick(void) const
{
    return nick_;
}

std::string* grandprix_rank_unit::get_mutable_nick(void)
{
    return &nick_;
}

void grandprix_rank_unit::set_nick(const std::string& value)
{
    nick_.assign(value);
}

void grandprix_rank_unit::set_nick(const char* value)
{
    nick_.assign(value);
}

SpringCat::int16_t grandprix_rank_unit::get_level(void) const
{
    return level_;
}

void grandprix_rank_unit::set_level(SpringCat::int16_t value)
{
    level_ = value;
}

SpringCat::int32_t grandprix_rank_unit::get_gp_point(void) const
{
    return gp_point_;
}

void grandprix_rank_unit::set_gp_point(SpringCat::int32_t value)
{
    gp_point_ = value;
}

grandprix_info_req::grandprix_info_req(void)
{
}

grandprix_info_req::grandprix_info_req(const grandprix_info_req& from)
{
    merge_from(from);
}

grandprix_info_req::~grandprix_info_req(void)
{
}

const SpringCat::Wave::type_info& grandprix_info_req::static_type_info(void)
{
    return __grandprix_info_req_type_info__;
}

const SpringCat::Wave::type_info& grandprix_info_req::runtime_type_info(void) const
{
    return static_type_info();
}

grandprix_info_req* grandprix_info_req::new_instance(void) const
{
    return new grandprix_info_req;
}

grandprix_info_req* grandprix_info_req::clone(void) const
{
    return new grandprix_info_req(*this);
}

void grandprix_info_req::clear(void)
{
}

bool grandprix_info_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t grandprix_info_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    return total_size;
}

void grandprix_info_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const grandprix_info_req& src = dynamic_cast<const grandprix_info_req&>(from);
    copy_from(src);
}

void grandprix_info_req::copy_from(const grandprix_info_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void grandprix_info_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const grandprix_info_req& src = dynamic_cast<const grandprix_info_req&>(from);
    merge_from(src);
}

void grandprix_info_req::merge_from(const grandprix_info_req& from)
{
    if (&from == this)
    {
        return;
    }
}

bool grandprix_info_req::serialize(SpringCat::System::Stream& output) const
{
    return true;
}

bool grandprix_info_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool grandprix_info_req::serialize(std::string& output) const
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

bool grandprix_info_req::deserialize(SpringCat::System::Stream& input)
{
    return true;
}

bool grandprix_info_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool grandprix_info_req::deserialize(std::string& input)
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

grandprix_info_ans::grandprix_info_ans(void)
    : __has_bits__(),
    result_(0),
    info_(new grandprix_info)
{
}

grandprix_info_ans::grandprix_info_ans(const grandprix_info_ans& from)
    : __has_bits__(),
    result_(0),
    info_(new grandprix_info)
{
    merge_from(from);
}

grandprix_info_ans::~grandprix_info_ans(void)
{
}

const SpringCat::Wave::type_info& grandprix_info_ans::static_type_info(void)
{
    return __grandprix_info_ans_type_info__;
}

const SpringCat::Wave::type_info& grandprix_info_ans::runtime_type_info(void) const
{
    return static_type_info();
}

grandprix_info_ans* grandprix_info_ans::new_instance(void) const
{
    return new grandprix_info_ans;
}

grandprix_info_ans* grandprix_info_ans::clone(void) const
{
    return new grandprix_info_ans(*this);
}

void grandprix_info_ans::clear(void)
{
    // result
    result_ = 0;
    // info
    info_->clear();
}

bool grandprix_info_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t grandprix_info_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // info
    total_size += SpringCat::Wave::internal::size(*info_);

    return total_size;
}

void grandprix_info_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const grandprix_info_ans& src = dynamic_cast<const grandprix_info_ans&>(from);
    copy_from(src);
}

void grandprix_info_ans::copy_from(const grandprix_info_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void grandprix_info_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const grandprix_info_ans& src = dynamic_cast<const grandprix_info_ans&>(from);
    merge_from(src);
}

void grandprix_info_ans::merge_from(const grandprix_info_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // info
    info_->merge_from(*from.get_info());
}

bool grandprix_info_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // info
    if (SpringCat::Wave::internal::serialize(output, *info_) == false)
    {
        return false;
    }

    return true;
}

bool grandprix_info_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool grandprix_info_ans::serialize(std::string& output) const
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

bool grandprix_info_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // info
    if (SpringCat::Wave::internal::deserialize(input, *info_) == false)
    {
        return false;
    }

    return true;
}

bool grandprix_info_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool grandprix_info_ans::deserialize(std::string& input)
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

SpringCat::int16_t grandprix_info_ans::get_result(void) const
{
    return result_;
}

void grandprix_info_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

const grandprix_info* grandprix_info_ans::get_info(void) const
{
    return info_.get();
}

grandprix_info* grandprix_info_ans::get_mutable_info(void)
{
    return info_.get();
}

grandprix_rank_info_req::grandprix_rank_info_req(void)
    : __has_bits__(),
    rank_type_(0),
    begin_rank_(0),
    req_count_(0)
{
}

grandprix_rank_info_req::grandprix_rank_info_req(const grandprix_rank_info_req& from)
    : __has_bits__(),
    rank_type_(0),
    begin_rank_(0),
    req_count_(0)
{
    merge_from(from);
}

grandprix_rank_info_req::~grandprix_rank_info_req(void)
{
}

const SpringCat::Wave::type_info& grandprix_rank_info_req::static_type_info(void)
{
    return __grandprix_rank_info_req_type_info__;
}

const SpringCat::Wave::type_info& grandprix_rank_info_req::runtime_type_info(void) const
{
    return static_type_info();
}

grandprix_rank_info_req* grandprix_rank_info_req::new_instance(void) const
{
    return new grandprix_rank_info_req;
}

grandprix_rank_info_req* grandprix_rank_info_req::clone(void) const
{
    return new grandprix_rank_info_req(*this);
}

void grandprix_rank_info_req::clear(void)
{
    // rank_type
    rank_type_ = 0;
    // begin_rank
    begin_rank_ = 0;
    // req_count
    req_count_ = 0;
}

bool grandprix_rank_info_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t grandprix_rank_info_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // rank_type
    total_size += SpringCat::Wave::internal::size(rank_type_);
    // begin_rank
    total_size += SpringCat::Wave::internal::size(begin_rank_);
    // req_count
    total_size += SpringCat::Wave::internal::size(req_count_);

    return total_size;
}

void grandprix_rank_info_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const grandprix_rank_info_req& src = dynamic_cast<const grandprix_rank_info_req&>(from);
    copy_from(src);
}

void grandprix_rank_info_req::copy_from(const grandprix_rank_info_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void grandprix_rank_info_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const grandprix_rank_info_req& src = dynamic_cast<const grandprix_rank_info_req&>(from);
    merge_from(src);
}

void grandprix_rank_info_req::merge_from(const grandprix_rank_info_req& from)
{
    if (&from == this)
    {
        return;
    }

    // rank_type
    set_rank_type(from.get_rank_type());
    // begin_rank
    set_begin_rank(from.get_begin_rank());
    // req_count
    set_req_count(from.get_req_count());
}

bool grandprix_rank_info_req::serialize(SpringCat::System::Stream& output) const
{
    // rank_type
    if (SpringCat::Wave::internal::serialize(output, rank_type_) == false)
    {
        return false;
    }
    // begin_rank
    if (SpringCat::Wave::internal::serialize(output, begin_rank_) == false)
    {
        return false;
    }
    // req_count
    if (SpringCat::Wave::internal::serialize(output, req_count_) == false)
    {
        return false;
    }

    return true;
}

bool grandprix_rank_info_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool grandprix_rank_info_req::serialize(std::string& output) const
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

bool grandprix_rank_info_req::deserialize(SpringCat::System::Stream& input)
{
    // rank_type
    if (SpringCat::Wave::internal::deserialize(input, rank_type_) == false)
    {
        return false;
    }
    // begin_rank
    if (SpringCat::Wave::internal::deserialize(input, begin_rank_) == false)
    {
        return false;
    }
    // req_count
    if (SpringCat::Wave::internal::deserialize(input, req_count_) == false)
    {
        return false;
    }

    return true;
}

bool grandprix_rank_info_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool grandprix_rank_info_req::deserialize(std::string& input)
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

grandprix_rank_type grandprix_rank_info_req::get_rank_type(void) const
{
    return static_cast<grandprix_rank_type>(rank_type_);
}

void grandprix_rank_info_req::set_rank_type(grandprix_rank_type value)
{
    rank_type_ = value;
}

SpringCat::int64_t grandprix_rank_info_req::get_begin_rank(void) const
{
    return begin_rank_;
}

void grandprix_rank_info_req::set_begin_rank(SpringCat::int64_t value)
{
    begin_rank_ = value;
}

SpringCat::int16_t grandprix_rank_info_req::get_req_count(void) const
{
    return req_count_;
}

void grandprix_rank_info_req::set_req_count(SpringCat::int16_t value)
{
    req_count_ = value;
}

grandprix_rank_info_ans::grandprix_rank_info_ans(void)
    : __has_bits__(),
    result_(0),
    rank_type_(0),
    infos_()
{
}

grandprix_rank_info_ans::grandprix_rank_info_ans(const grandprix_rank_info_ans& from)
    : __has_bits__(),
    result_(0),
    rank_type_(0),
    infos_()
{
    merge_from(from);
}

grandprix_rank_info_ans::~grandprix_rank_info_ans(void)
{
    // infos
    SpringCat::uint32_t infos_size = static_cast<SpringCat::uint32_t>(infos_.size());
    for (SpringCat::uint32_t i = 0; i != infos_size; ++i)
    {
        delete infos_[i];
    }
    infos_.clear();
}

const SpringCat::Wave::type_info& grandprix_rank_info_ans::static_type_info(void)
{
    return __grandprix_rank_info_ans_type_info__;
}

const SpringCat::Wave::type_info& grandprix_rank_info_ans::runtime_type_info(void) const
{
    return static_type_info();
}

grandprix_rank_info_ans* grandprix_rank_info_ans::new_instance(void) const
{
    return new grandprix_rank_info_ans;
}

grandprix_rank_info_ans* grandprix_rank_info_ans::clone(void) const
{
    return new grandprix_rank_info_ans(*this);
}

void grandprix_rank_info_ans::clear(void)
{
    // result
    result_ = 0;
    // rank_type
    rank_type_ = 0;
    // infos
    SpringCat::uint32_t infos_size = static_cast<SpringCat::uint32_t>(infos_.size());
    for (SpringCat::uint32_t i = 0; i != infos_size; ++i)
    {
        delete infos_[i];
    }
    infos_.clear();
}

bool grandprix_rank_info_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t grandprix_rank_info_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // rank_type
    total_size += SpringCat::Wave::internal::size(rank_type_);
    // infos
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint32_t));
    SpringCat::uint32_t infos_size = static_cast<SpringCat::uint32_t>(infos_.size());
    for (SpringCat::uint32_t i = 0; i != infos_size; ++i)
    {
        total_size += SpringCat::Wave::internal::size(*infos_[i]);
    }

    return total_size;
}

void grandprix_rank_info_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const grandprix_rank_info_ans& src = dynamic_cast<const grandprix_rank_info_ans&>(from);
    copy_from(src);
}

void grandprix_rank_info_ans::copy_from(const grandprix_rank_info_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void grandprix_rank_info_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const grandprix_rank_info_ans& src = dynamic_cast<const grandprix_rank_info_ans&>(from);
    merge_from(src);
}

void grandprix_rank_info_ans::merge_from(const grandprix_rank_info_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // rank_type
    set_rank_type(from.get_rank_type());
    // infos
    SpringCat::uint32_t infos_size = static_cast<SpringCat::uint32_t>(from.infos_.size());
    infos_.reserve(infos_.size() + infos_size);
    for (SpringCat::uint32_t i = 0; i != infos_size; ++i)
    {
        infos_.push_back(from.infos_[i]->clone());
    }
}

bool grandprix_rank_info_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // rank_type
    if (SpringCat::Wave::internal::serialize(output, rank_type_) == false)
    {
        return false;
    }
    // infos
    SpringCat::uint32_t infos_size = static_cast<SpringCat::uint32_t>(infos_.size());
    if (SpringCat::Wave::internal::serialize(output, infos_size) == false)
    {
        return false;
    }
    for (SpringCat::uint32_t i = 0; i != infos_size; ++i)
    {
        if (SpringCat::Wave::internal::serialize(output, *infos_[i]) == false)
        {
            return false;
        }
    }

    return true;
}

bool grandprix_rank_info_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool grandprix_rank_info_ans::serialize(std::string& output) const
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

bool grandprix_rank_info_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // rank_type
    if (SpringCat::Wave::internal::deserialize(input, rank_type_) == false)
    {
        return false;
    }
    // infos
    SpringCat::uint32_t infos_size = 0;
    if (SpringCat::Wave::internal::deserialize(input, infos_size) == false)
    {
        return false;
    }
    if (infos_size > 0)
    {
        infos_.reserve(infos_size);
        for (SpringCat::uint32_t i = 0; i != infos_size; ++i)
        {
            std::auto_ptr<grandprix_rank_unit> new_infos(new grandprix_rank_unit);
            if (SpringCat::Wave::internal::deserialize(input, *new_infos) == false)
            {
                return false;
            }
            infos_.push_back(new_infos.release());
        }
    }

    return true;
}

bool grandprix_rank_info_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool grandprix_rank_info_ans::deserialize(std::string& input)
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

SpringCat::int16_t grandprix_rank_info_ans::get_result(void) const
{
    return result_;
}

void grandprix_rank_info_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

grandprix_rank_type grandprix_rank_info_ans::get_rank_type(void) const
{
    return static_cast<grandprix_rank_type>(rank_type_);
}

void grandprix_rank_info_ans::set_rank_type(grandprix_rank_type value)
{
    rank_type_ = value;
}

const std::vector<grandprix_rank_unit*>& grandprix_rank_info_ans::get_infos(void) const
{
    return infos_;
}

std::vector<grandprix_rank_unit*>* grandprix_rank_info_ans::get_mutable_infos(void)
{
    return &infos_;
}

const grandprix_rank_unit* grandprix_rank_info_ans::get_infos(size_t index) const
{
    if (infos_.size() <= index)
    {
        throw std::out_of_range("grandprix_rank_info_ans::infos_ index outside range");
    }

    return infos_[index];
}

grandprix_rank_unit* grandprix_rank_info_ans::get_mutable_infos(size_t index)
{
    if (infos_.size() <= index)
    {
        throw std::out_of_range("grandprix_rank_info_ans::infos_ index outside range");
    }

    return infos_[index];
}

grandprix_rank_unit* grandprix_rank_info_ans::add_infos(void)
{
    std::auto_ptr<grandprix_rank_unit> new_infos(new grandprix_rank_unit);
    infos_.push_back(new_infos.get());

    return new_infos.release();
}



}    // namespace protocol
