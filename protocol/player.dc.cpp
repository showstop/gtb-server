#include "player.dc.h"
#include <stdexcept>


namespace protocol
{

// class name: player_profile_info, type id(decimal): 180718719, type id(hex): 0xAC58C7F
static const SpringCat::Wave::type_info __player_profile_info_type_info__(0xAC58C7F, "protocol.player_profile_info");
// class name: player_record_info, type id(decimal): 220873199, type id(hex): 0xD2A41EF
static const SpringCat::Wave::type_info __player_record_info_type_info__(0xD2A41EF, "protocol.player_record_info");
// class name: player_profile_info_req, type id(decimal): 210742593, type id(hex): 0xC8FAD41
static const SpringCat::Wave::type_info __player_profile_info_req_type_info__(0xC8FAD41, "protocol.player_profile_info_req");
// class name: player_profile_info_ans, type id(decimal): 210736083, type id(hex): 0xC8F93D3
static const SpringCat::Wave::type_info __player_profile_info_ans_type_info__(0xC8F93D3, "protocol.player_profile_info_ans");
// class name: update_player_profile_info_req, type id(decimal): 241686081, type id(hex): 0xE67D641
static const SpringCat::Wave::type_info __update_player_profile_info_req_type_info__(0xE67D641, "protocol.update_player_profile_info_req");
// class name: update_player_profile_info_ans, type id(decimal): 241691347, type id(hex): 0xE67EAD3
static const SpringCat::Wave::type_info __update_player_profile_info_ans_type_info__(0xE67EAD3, "protocol.update_player_profile_info_ans");

player_profile_info::player_profile_info(void)
    : __has_bits__(),
    player_no_(0),
    game_nick_(),
    nation_code_(0),
    player_level_(0),
    exp_(0),
    exp_gauge_(0),
    trophy_(0),
    options_()
{
}

player_profile_info::player_profile_info(const player_profile_info& from)
    : __has_bits__(),
    player_no_(0),
    game_nick_(),
    nation_code_(0),
    player_level_(0),
    exp_(0),
    exp_gauge_(0),
    trophy_(0),
    options_()
{
    merge_from(from);
}

player_profile_info::~player_profile_info(void)
{
}

const SpringCat::Wave::type_info& player_profile_info::static_type_info(void)
{
    return __player_profile_info_type_info__;
}

const SpringCat::Wave::type_info& player_profile_info::runtime_type_info(void) const
{
    return static_type_info();
}

player_profile_info* player_profile_info::new_instance(void) const
{
    return new player_profile_info;
}

player_profile_info* player_profile_info::clone(void) const
{
    return new player_profile_info(*this);
}

void player_profile_info::clear(void)
{
    // player_no
    player_no_ = 0;
    // game_nick
    game_nick_.clear();
    // nation_code
    nation_code_ = 0;
    // player_level
    player_level_ = 0;
    // exp
    exp_ = 0;
    // exp_gauge
    exp_gauge_ = 0;
    // trophy
    trophy_ = 0;
    // options
    options_.clear();
}

bool player_profile_info::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t player_profile_info::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // player_no
    total_size += SpringCat::Wave::internal::size(player_no_);
    // game_nick
    total_size += SpringCat::Wave::internal::size(game_nick_, 0xFFFFFFFF);
    // nation_code
    total_size += SpringCat::Wave::internal::size(nation_code_);
    // player_level
    total_size += SpringCat::Wave::internal::size(player_level_);
    // exp
    total_size += SpringCat::Wave::internal::size(exp_);
    // exp_gauge
    total_size += SpringCat::Wave::internal::size(exp_gauge_);
    // trophy
    total_size += SpringCat::Wave::internal::size(trophy_);
    // options
    total_size += SpringCat::Wave::internal::size(options_, 0xFFFFFFFF);

    return total_size;
}

void player_profile_info::copy_from(const SpringCat::Wave::object_base& from)
{
    const player_profile_info& src = dynamic_cast<const player_profile_info&>(from);
    copy_from(src);
}

void player_profile_info::copy_from(const player_profile_info& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void player_profile_info::merge_from(const SpringCat::Wave::object_base& from)
{
    const player_profile_info& src = dynamic_cast<const player_profile_info&>(from);
    merge_from(src);
}

void player_profile_info::merge_from(const player_profile_info& from)
{
    if (&from == this)
    {
        return;
    }

    // player_no
    set_player_no(from.get_player_no());
    // game_nick
    set_game_nick(from.get_game_nick());
    // nation_code
    set_nation_code(from.get_nation_code());
    // player_level
    set_player_level(from.get_player_level());
    // exp
    set_exp(from.get_exp());
    // exp_gauge
    set_exp_gauge(from.get_exp_gauge());
    // trophy
    set_trophy(from.get_trophy());
    // options
    set_options(from.get_options());
}

bool player_profile_info::serialize(SpringCat::System::Stream& output) const
{
    // player_no
    if (SpringCat::Wave::internal::serialize(output, player_no_) == false)
    {
        return false;
    }
    // game_nick
    if (SpringCat::Wave::internal::serialize(output, game_nick_, 0xFFFFFFFF) == false)
    {
        return false;
    }
    // nation_code
    if (SpringCat::Wave::internal::serialize(output, nation_code_) == false)
    {
        return false;
    }
    // player_level
    if (SpringCat::Wave::internal::serialize(output, player_level_) == false)
    {
        return false;
    }
    // exp
    if (SpringCat::Wave::internal::serialize(output, exp_) == false)
    {
        return false;
    }
    // exp_gauge
    if (SpringCat::Wave::internal::serialize(output, exp_gauge_) == false)
    {
        return false;
    }
    // trophy
    if (SpringCat::Wave::internal::serialize(output, trophy_) == false)
    {
        return false;
    }
    // options
    if (SpringCat::Wave::internal::serialize(output, options_, 0xFFFFFFFF) == false)
    {
        return false;
    }

    return true;
}

bool player_profile_info::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool player_profile_info::serialize(std::string& output) const
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

bool player_profile_info::deserialize(SpringCat::System::Stream& input)
{
    // player_no
    if (SpringCat::Wave::internal::deserialize(input, player_no_) == false)
    {
        return false;
    }
    // game_nick
    if (SpringCat::Wave::internal::deserialize(input, game_nick_, 0xFFFFFFFF) == false)
    {
        return false;
    }
    // nation_code
    if (SpringCat::Wave::internal::deserialize(input, nation_code_) == false)
    {
        return false;
    }
    // player_level
    if (SpringCat::Wave::internal::deserialize(input, player_level_) == false)
    {
        return false;
    }
    // exp
    if (SpringCat::Wave::internal::deserialize(input, exp_) == false)
    {
        return false;
    }
    // exp_gauge
    if (SpringCat::Wave::internal::deserialize(input, exp_gauge_) == false)
    {
        return false;
    }
    // trophy
    if (SpringCat::Wave::internal::deserialize(input, trophy_) == false)
    {
        return false;
    }
    // options
    if (SpringCat::Wave::internal::deserialize(input, options_, 0xFFFFFFFF) == false)
    {
        return false;
    }

    return true;
}

bool player_profile_info::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool player_profile_info::deserialize(std::string& input)
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

SpringCat::uint64_t player_profile_info::get_player_no(void) const
{
    return player_no_;
}

void player_profile_info::set_player_no(SpringCat::uint64_t value)
{
    player_no_ = value;
}

const std::string& player_profile_info::get_game_nick(void) const
{
    return game_nick_;
}

std::string* player_profile_info::get_mutable_game_nick(void)
{
    return &game_nick_;
}

void player_profile_info::set_game_nick(const std::string& value)
{
    game_nick_.assign(value);
}

void player_profile_info::set_game_nick(const char* value)
{
    game_nick_.assign(value);
}

SpringCat::int16_t player_profile_info::get_nation_code(void) const
{
    return nation_code_;
}

void player_profile_info::set_nation_code(SpringCat::int16_t value)
{
    nation_code_ = value;
}

SpringCat::uint16_t player_profile_info::get_player_level(void) const
{
    return player_level_;
}

void player_profile_info::set_player_level(SpringCat::uint16_t value)
{
    player_level_ = value;
}

SpringCat::int32_t player_profile_info::get_exp(void) const
{
    return exp_;
}

void player_profile_info::set_exp(SpringCat::int32_t value)
{
    exp_ = value;
}

SpringCat::int16_t player_profile_info::get_exp_gauge(void) const
{
    return exp_gauge_;
}

void player_profile_info::set_exp_gauge(SpringCat::int16_t value)
{
    exp_gauge_ = value;
}

SpringCat::int32_t player_profile_info::get_trophy(void) const
{
    return trophy_;
}

void player_profile_info::set_trophy(SpringCat::int32_t value)
{
    trophy_ = value;
}

const std::string& player_profile_info::get_options(void) const
{
    return options_;
}

std::string* player_profile_info::get_mutable_options(void)
{
    return &options_;
}

void player_profile_info::set_options(const std::string& value)
{
    options_.assign(value);
}

void player_profile_info::set_options(const char* value)
{
    options_.assign(value);
}

player_record_info::player_record_info(void)
{
}

player_record_info::player_record_info(const player_record_info& from)
{
    merge_from(from);
}

player_record_info::~player_record_info(void)
{
}

const SpringCat::Wave::type_info& player_record_info::static_type_info(void)
{
    return __player_record_info_type_info__;
}

const SpringCat::Wave::type_info& player_record_info::runtime_type_info(void) const
{
    return static_type_info();
}

player_record_info* player_record_info::new_instance(void) const
{
    return new player_record_info;
}

player_record_info* player_record_info::clone(void) const
{
    return new player_record_info(*this);
}

void player_record_info::clear(void)
{
}

bool player_record_info::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t player_record_info::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    return total_size;
}

void player_record_info::copy_from(const SpringCat::Wave::object_base& from)
{
    const player_record_info& src = dynamic_cast<const player_record_info&>(from);
    copy_from(src);
}

void player_record_info::copy_from(const player_record_info& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void player_record_info::merge_from(const SpringCat::Wave::object_base& from)
{
    const player_record_info& src = dynamic_cast<const player_record_info&>(from);
    merge_from(src);
}

void player_record_info::merge_from(const player_record_info& from)
{
    if (&from == this)
    {
        return;
    }
}

bool player_record_info::serialize(SpringCat::System::Stream& output) const
{
    return true;
}

bool player_record_info::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool player_record_info::serialize(std::string& output) const
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

bool player_record_info::deserialize(SpringCat::System::Stream& input)
{
    return true;
}

bool player_record_info::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool player_record_info::deserialize(std::string& input)
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

player_profile_info_req::player_profile_info_req(void)
    : __has_bits__(),
    player_no_(0)
{
}

player_profile_info_req::player_profile_info_req(const player_profile_info_req& from)
    : __has_bits__(),
    player_no_(0)
{
    merge_from(from);
}

player_profile_info_req::~player_profile_info_req(void)
{
}

const SpringCat::Wave::type_info& player_profile_info_req::static_type_info(void)
{
    return __player_profile_info_req_type_info__;
}

const SpringCat::Wave::type_info& player_profile_info_req::runtime_type_info(void) const
{
    return static_type_info();
}

player_profile_info_req* player_profile_info_req::new_instance(void) const
{
    return new player_profile_info_req;
}

player_profile_info_req* player_profile_info_req::clone(void) const
{
    return new player_profile_info_req(*this);
}

void player_profile_info_req::clear(void)
{
    // player_no
    player_no_ = 0;
}

bool player_profile_info_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t player_profile_info_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // player_no
    total_size += SpringCat::Wave::internal::size(player_no_);

    return total_size;
}

void player_profile_info_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const player_profile_info_req& src = dynamic_cast<const player_profile_info_req&>(from);
    copy_from(src);
}

void player_profile_info_req::copy_from(const player_profile_info_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void player_profile_info_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const player_profile_info_req& src = dynamic_cast<const player_profile_info_req&>(from);
    merge_from(src);
}

void player_profile_info_req::merge_from(const player_profile_info_req& from)
{
    if (&from == this)
    {
        return;
    }

    // player_no
    set_player_no(from.get_player_no());
}

bool player_profile_info_req::serialize(SpringCat::System::Stream& output) const
{
    // player_no
    if (SpringCat::Wave::internal::serialize(output, player_no_) == false)
    {
        return false;
    }

    return true;
}

bool player_profile_info_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool player_profile_info_req::serialize(std::string& output) const
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

bool player_profile_info_req::deserialize(SpringCat::System::Stream& input)
{
    // player_no
    if (SpringCat::Wave::internal::deserialize(input, player_no_) == false)
    {
        return false;
    }

    return true;
}

bool player_profile_info_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool player_profile_info_req::deserialize(std::string& input)
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

SpringCat::uint64_t player_profile_info_req::get_player_no(void) const
{
    return player_no_;
}

void player_profile_info_req::set_player_no(SpringCat::uint64_t value)
{
    player_no_ = value;
}

player_profile_info_ans::player_profile_info_ans(void)
    : __has_bits__(),
    result_(0),
    info_(new player_profile_info)
{
}

player_profile_info_ans::player_profile_info_ans(const player_profile_info_ans& from)
    : __has_bits__(),
    result_(0),
    info_(new player_profile_info)
{
    merge_from(from);
}

player_profile_info_ans::~player_profile_info_ans(void)
{
}

const SpringCat::Wave::type_info& player_profile_info_ans::static_type_info(void)
{
    return __player_profile_info_ans_type_info__;
}

const SpringCat::Wave::type_info& player_profile_info_ans::runtime_type_info(void) const
{
    return static_type_info();
}

player_profile_info_ans* player_profile_info_ans::new_instance(void) const
{
    return new player_profile_info_ans;
}

player_profile_info_ans* player_profile_info_ans::clone(void) const
{
    return new player_profile_info_ans(*this);
}

void player_profile_info_ans::clear(void)
{
    // result
    result_ = 0;
    // info
    info_->clear();
}

bool player_profile_info_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t player_profile_info_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // info
    total_size += SpringCat::Wave::internal::size(*info_);

    return total_size;
}

void player_profile_info_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const player_profile_info_ans& src = dynamic_cast<const player_profile_info_ans&>(from);
    copy_from(src);
}

void player_profile_info_ans::copy_from(const player_profile_info_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void player_profile_info_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const player_profile_info_ans& src = dynamic_cast<const player_profile_info_ans&>(from);
    merge_from(src);
}

void player_profile_info_ans::merge_from(const player_profile_info_ans& from)
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

bool player_profile_info_ans::serialize(SpringCat::System::Stream& output) const
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

bool player_profile_info_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool player_profile_info_ans::serialize(std::string& output) const
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

bool player_profile_info_ans::deserialize(SpringCat::System::Stream& input)
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

bool player_profile_info_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool player_profile_info_ans::deserialize(std::string& input)
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

SpringCat::int16_t player_profile_info_ans::get_result(void) const
{
    return result_;
}

void player_profile_info_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

const player_profile_info* player_profile_info_ans::get_info(void) const
{
    return info_.get();
}

player_profile_info* player_profile_info_ans::get_mutable_info(void)
{
    return info_.get();
}

update_player_profile_info_req::update_player_profile_info_req(void)
    : __has_bits__(),
    game_nick_(),
    nation_code_(0)
{
}

update_player_profile_info_req::update_player_profile_info_req(const update_player_profile_info_req& from)
    : __has_bits__(),
    game_nick_(),
    nation_code_(0)
{
    merge_from(from);
}

update_player_profile_info_req::~update_player_profile_info_req(void)
{
}

const SpringCat::Wave::type_info& update_player_profile_info_req::static_type_info(void)
{
    return __update_player_profile_info_req_type_info__;
}

const SpringCat::Wave::type_info& update_player_profile_info_req::runtime_type_info(void) const
{
    return static_type_info();
}

update_player_profile_info_req* update_player_profile_info_req::new_instance(void) const
{
    return new update_player_profile_info_req;
}

update_player_profile_info_req* update_player_profile_info_req::clone(void) const
{
    return new update_player_profile_info_req(*this);
}

void update_player_profile_info_req::clear(void)
{
    // game_nick
    game_nick_.clear();
    // nation_code
    nation_code_ = 0;
}

bool update_player_profile_info_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t update_player_profile_info_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // game_nick
    total_size += SpringCat::Wave::internal::size(game_nick_, 0xFFFFFFFF);
    // nation_code
    total_size += SpringCat::Wave::internal::size(nation_code_);

    return total_size;
}

void update_player_profile_info_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const update_player_profile_info_req& src = dynamic_cast<const update_player_profile_info_req&>(from);
    copy_from(src);
}

void update_player_profile_info_req::copy_from(const update_player_profile_info_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void update_player_profile_info_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const update_player_profile_info_req& src = dynamic_cast<const update_player_profile_info_req&>(from);
    merge_from(src);
}

void update_player_profile_info_req::merge_from(const update_player_profile_info_req& from)
{
    if (&from == this)
    {
        return;
    }

    // game_nick
    set_game_nick(from.get_game_nick());
    // nation_code
    set_nation_code(from.get_nation_code());
}

bool update_player_profile_info_req::serialize(SpringCat::System::Stream& output) const
{
    // game_nick
    if (SpringCat::Wave::internal::serialize(output, game_nick_, 0xFFFFFFFF) == false)
    {
        return false;
    }
    // nation_code
    if (SpringCat::Wave::internal::serialize(output, nation_code_) == false)
    {
        return false;
    }

    return true;
}

bool update_player_profile_info_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool update_player_profile_info_req::serialize(std::string& output) const
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

bool update_player_profile_info_req::deserialize(SpringCat::System::Stream& input)
{
    // game_nick
    if (SpringCat::Wave::internal::deserialize(input, game_nick_, 0xFFFFFFFF) == false)
    {
        return false;
    }
    // nation_code
    if (SpringCat::Wave::internal::deserialize(input, nation_code_) == false)
    {
        return false;
    }

    return true;
}

bool update_player_profile_info_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool update_player_profile_info_req::deserialize(std::string& input)
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

const std::string& update_player_profile_info_req::get_game_nick(void) const
{
    return game_nick_;
}

std::string* update_player_profile_info_req::get_mutable_game_nick(void)
{
    return &game_nick_;
}

void update_player_profile_info_req::set_game_nick(const std::string& value)
{
    game_nick_.assign(value);
}

void update_player_profile_info_req::set_game_nick(const char* value)
{
    game_nick_.assign(value);
}

SpringCat::int16_t update_player_profile_info_req::get_nation_code(void) const
{
    return nation_code_;
}

void update_player_profile_info_req::set_nation_code(SpringCat::int16_t value)
{
    nation_code_ = value;
}

update_player_profile_info_ans::update_player_profile_info_ans(void)
    : __has_bits__(),
    result_(0),
    info_(new player_profile_info)
{
}

update_player_profile_info_ans::update_player_profile_info_ans(const update_player_profile_info_ans& from)
    : __has_bits__(),
    result_(0),
    info_(new player_profile_info)
{
    merge_from(from);
}

update_player_profile_info_ans::~update_player_profile_info_ans(void)
{
}

const SpringCat::Wave::type_info& update_player_profile_info_ans::static_type_info(void)
{
    return __update_player_profile_info_ans_type_info__;
}

const SpringCat::Wave::type_info& update_player_profile_info_ans::runtime_type_info(void) const
{
    return static_type_info();
}

update_player_profile_info_ans* update_player_profile_info_ans::new_instance(void) const
{
    return new update_player_profile_info_ans;
}

update_player_profile_info_ans* update_player_profile_info_ans::clone(void) const
{
    return new update_player_profile_info_ans(*this);
}

void update_player_profile_info_ans::clear(void)
{
    // result
    result_ = 0;
    // info
    info_->clear();
}

bool update_player_profile_info_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t update_player_profile_info_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // info
    total_size += SpringCat::Wave::internal::size(*info_);

    return total_size;
}

void update_player_profile_info_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const update_player_profile_info_ans& src = dynamic_cast<const update_player_profile_info_ans&>(from);
    copy_from(src);
}

void update_player_profile_info_ans::copy_from(const update_player_profile_info_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void update_player_profile_info_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const update_player_profile_info_ans& src = dynamic_cast<const update_player_profile_info_ans&>(from);
    merge_from(src);
}

void update_player_profile_info_ans::merge_from(const update_player_profile_info_ans& from)
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

bool update_player_profile_info_ans::serialize(SpringCat::System::Stream& output) const
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

bool update_player_profile_info_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool update_player_profile_info_ans::serialize(std::string& output) const
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

bool update_player_profile_info_ans::deserialize(SpringCat::System::Stream& input)
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

bool update_player_profile_info_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool update_player_profile_info_ans::deserialize(std::string& input)
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

SpringCat::int16_t update_player_profile_info_ans::get_result(void) const
{
    return result_;
}

void update_player_profile_info_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

const player_profile_info* update_player_profile_info_ans::get_info(void) const
{
    return info_.get();
}

player_profile_info* update_player_profile_info_ans::get_mutable_info(void)
{
    return info_.get();
}



}    // namespace protocol
