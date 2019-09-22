#include "internal_ls_mms.dc.h"
#include <stdexcept>


namespace protocol
{

// class name: internal_register_player_req, type id(decimal): 86901457, type id(hex): 0x52E02D1
static const SpringCat::Wave::type_info __internal_register_player_req_type_info__(0x52E02D1, "protocol.internal_register_player_req");
// class name: internal_register_player_ans, type id(decimal): 86916675, type id(hex): 0x52E3E43
static const SpringCat::Wave::type_info __internal_register_player_ans_type_info__(0x52E3E43, "protocol.internal_register_player_ans");
// class name: internal_unregister_player_req, type id(decimal): 221382305, type id(hex): 0xD3206A1
static const SpringCat::Wave::type_info __internal_unregister_player_req_type_info__(0xD3206A1, "protocol.internal_unregister_player_req");
// class name: internal_unregister_player_ans, type id(decimal): 221395507, type id(hex): 0xD323A33
static const SpringCat::Wave::type_info __internal_unregister_player_ans_type_info__(0xD323A33, "protocol.internal_unregister_player_ans");
// class name: internal_match_player_info, type id(decimal): 202985615, type id(hex): 0xC19508F
static const SpringCat::Wave::type_info __internal_match_player_info_type_info__(0xC19508F, "protocol.internal_match_player_info");
// class name: internal_create_ps_req, type id(decimal): 48681073, type id(hex): 0x2E6D071
static const SpringCat::Wave::type_info __internal_create_ps_req_type_info__(0x2E6D071, "protocol.internal_create_ps_req");
// class name: internal_create_ps_ans, type id(decimal): 48689379, type id(hex): 0x2E6F0E3
static const SpringCat::Wave::type_info __internal_create_ps_ans_type_info__(0x2E6F0E3, "protocol.internal_create_ps_ans");
// class name: internal_match_complete_notify, type id(decimal): 246685785, type id(hex): 0xEB42059
static const SpringCat::Wave::type_info __internal_match_complete_notify_type_info__(0xEB42059, "protocol.internal_match_complete_notify");

internal_register_player_req::internal_register_player_req(void)
    : __has_bits__(),
    mode_(0),
    info_(new player_profile_info),
    using_match_items_(new match_item_info)
{
}

internal_register_player_req::internal_register_player_req(const internal_register_player_req& from)
    : __has_bits__(),
    mode_(0),
    info_(new player_profile_info),
    using_match_items_(new match_item_info)
{
    merge_from(from);
}

internal_register_player_req::~internal_register_player_req(void)
{
}

const SpringCat::Wave::type_info& internal_register_player_req::static_type_info(void)
{
    return __internal_register_player_req_type_info__;
}

const SpringCat::Wave::type_info& internal_register_player_req::runtime_type_info(void) const
{
    return static_type_info();
}

internal_register_player_req* internal_register_player_req::new_instance(void) const
{
    return new internal_register_player_req;
}

internal_register_player_req* internal_register_player_req::clone(void) const
{
    return new internal_register_player_req(*this);
}

void internal_register_player_req::clear(void)
{
    // mode
    mode_ = 0;
    // info
    info_->clear();
    // using_match_items
    using_match_items_->clear();
}

bool internal_register_player_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t internal_register_player_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // mode
    total_size += SpringCat::Wave::internal::size(mode_);
    // info
    total_size += SpringCat::Wave::internal::size(*info_);
    // using_match_items
    total_size += SpringCat::Wave::internal::size(*using_match_items_);

    return total_size;
}

void internal_register_player_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const internal_register_player_req& src = dynamic_cast<const internal_register_player_req&>(from);
    copy_from(src);
}

void internal_register_player_req::copy_from(const internal_register_player_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void internal_register_player_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const internal_register_player_req& src = dynamic_cast<const internal_register_player_req&>(from);
    merge_from(src);
}

void internal_register_player_req::merge_from(const internal_register_player_req& from)
{
    if (&from == this)
    {
        return;
    }

    // mode
    set_mode(from.get_mode());
    // info
    info_->merge_from(*from.get_info());
    // using_match_items
    using_match_items_->merge_from(*from.get_using_match_items());
}

bool internal_register_player_req::serialize(SpringCat::System::Stream& output) const
{
    // mode
    if (SpringCat::Wave::internal::serialize(output, mode_) == false)
    {
        return false;
    }
    // info
    if (SpringCat::Wave::internal::serialize(output, *info_) == false)
    {
        return false;
    }
    // using_match_items
    if (SpringCat::Wave::internal::serialize(output, *using_match_items_) == false)
    {
        return false;
    }

    return true;
}

bool internal_register_player_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool internal_register_player_req::serialize(std::string& output) const
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

bool internal_register_player_req::deserialize(SpringCat::System::Stream& input)
{
    // mode
    if (SpringCat::Wave::internal::deserialize(input, mode_) == false)
    {
        return false;
    }
    // info
    if (SpringCat::Wave::internal::deserialize(input, *info_) == false)
    {
        return false;
    }
    // using_match_items
    if (SpringCat::Wave::internal::deserialize(input, *using_match_items_) == false)
    {
        return false;
    }

    return true;
}

bool internal_register_player_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool internal_register_player_req::deserialize(std::string& input)
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

GameMode internal_register_player_req::get_mode(void) const
{
    return static_cast<GameMode>(mode_);
}

void internal_register_player_req::set_mode(GameMode value)
{
    mode_ = value;
}

const player_profile_info* internal_register_player_req::get_info(void) const
{
    return info_.get();
}

player_profile_info* internal_register_player_req::get_mutable_info(void)
{
    return info_.get();
}

const match_item_info* internal_register_player_req::get_using_match_items(void) const
{
    return using_match_items_.get();
}

match_item_info* internal_register_player_req::get_mutable_using_match_items(void)
{
    return using_match_items_.get();
}

internal_register_player_ans::internal_register_player_ans(void)
    : __has_bits__(),
    result_(0),
    estimated_sec_(0),
    dest_player_no_(0)
{
}

internal_register_player_ans::internal_register_player_ans(const internal_register_player_ans& from)
    : __has_bits__(),
    result_(0),
    estimated_sec_(0),
    dest_player_no_(0)
{
    merge_from(from);
}

internal_register_player_ans::~internal_register_player_ans(void)
{
}

const SpringCat::Wave::type_info& internal_register_player_ans::static_type_info(void)
{
    return __internal_register_player_ans_type_info__;
}

const SpringCat::Wave::type_info& internal_register_player_ans::runtime_type_info(void) const
{
    return static_type_info();
}

internal_register_player_ans* internal_register_player_ans::new_instance(void) const
{
    return new internal_register_player_ans;
}

internal_register_player_ans* internal_register_player_ans::clone(void) const
{
    return new internal_register_player_ans(*this);
}

void internal_register_player_ans::clear(void)
{
    // result
    result_ = 0;
    // estimated_sec
    estimated_sec_ = 0;
    // dest_player_no
    dest_player_no_ = 0;
}

bool internal_register_player_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t internal_register_player_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // estimated_sec
    total_size += SpringCat::Wave::internal::size(estimated_sec_);
    // dest_player_no
    total_size += SpringCat::Wave::internal::size(dest_player_no_);

    return total_size;
}

void internal_register_player_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const internal_register_player_ans& src = dynamic_cast<const internal_register_player_ans&>(from);
    copy_from(src);
}

void internal_register_player_ans::copy_from(const internal_register_player_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void internal_register_player_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const internal_register_player_ans& src = dynamic_cast<const internal_register_player_ans&>(from);
    merge_from(src);
}

void internal_register_player_ans::merge_from(const internal_register_player_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // estimated_sec
    set_estimated_sec(from.get_estimated_sec());
    // dest_player_no
    set_dest_player_no(from.get_dest_player_no());
}

bool internal_register_player_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // estimated_sec
    if (SpringCat::Wave::internal::serialize(output, estimated_sec_) == false)
    {
        return false;
    }
    // dest_player_no
    if (SpringCat::Wave::internal::serialize(output, dest_player_no_) == false)
    {
        return false;
    }

    return true;
}

bool internal_register_player_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool internal_register_player_ans::serialize(std::string& output) const
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

bool internal_register_player_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // estimated_sec
    if (SpringCat::Wave::internal::deserialize(input, estimated_sec_) == false)
    {
        return false;
    }
    // dest_player_no
    if (SpringCat::Wave::internal::deserialize(input, dest_player_no_) == false)
    {
        return false;
    }

    return true;
}

bool internal_register_player_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool internal_register_player_ans::deserialize(std::string& input)
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

SpringCat::int16_t internal_register_player_ans::get_result(void) const
{
    return result_;
}

void internal_register_player_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

SpringCat::int32_t internal_register_player_ans::get_estimated_sec(void) const
{
    return estimated_sec_;
}

void internal_register_player_ans::set_estimated_sec(SpringCat::int32_t value)
{
    estimated_sec_ = value;
}

SpringCat::uint64_t internal_register_player_ans::get_dest_player_no(void) const
{
    return dest_player_no_;
}

void internal_register_player_ans::set_dest_player_no(SpringCat::uint64_t value)
{
    dest_player_no_ = value;
}

internal_unregister_player_req::internal_unregister_player_req(void)
    : __has_bits__(),
    mode_(0),
    player_no_(0)
{
}

internal_unregister_player_req::internal_unregister_player_req(const internal_unregister_player_req& from)
    : __has_bits__(),
    mode_(0),
    player_no_(0)
{
    merge_from(from);
}

internal_unregister_player_req::~internal_unregister_player_req(void)
{
}

const SpringCat::Wave::type_info& internal_unregister_player_req::static_type_info(void)
{
    return __internal_unregister_player_req_type_info__;
}

const SpringCat::Wave::type_info& internal_unregister_player_req::runtime_type_info(void) const
{
    return static_type_info();
}

internal_unregister_player_req* internal_unregister_player_req::new_instance(void) const
{
    return new internal_unregister_player_req;
}

internal_unregister_player_req* internal_unregister_player_req::clone(void) const
{
    return new internal_unregister_player_req(*this);
}

void internal_unregister_player_req::clear(void)
{
    // mode
    mode_ = 0;
    // player_no
    player_no_ = 0;
}

bool internal_unregister_player_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t internal_unregister_player_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // mode
    total_size += SpringCat::Wave::internal::size(mode_);
    // player_no
    total_size += SpringCat::Wave::internal::size(player_no_);

    return total_size;
}

void internal_unregister_player_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const internal_unregister_player_req& src = dynamic_cast<const internal_unregister_player_req&>(from);
    copy_from(src);
}

void internal_unregister_player_req::copy_from(const internal_unregister_player_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void internal_unregister_player_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const internal_unregister_player_req& src = dynamic_cast<const internal_unregister_player_req&>(from);
    merge_from(src);
}

void internal_unregister_player_req::merge_from(const internal_unregister_player_req& from)
{
    if (&from == this)
    {
        return;
    }

    // mode
    set_mode(from.get_mode());
    // player_no
    set_player_no(from.get_player_no());
}

bool internal_unregister_player_req::serialize(SpringCat::System::Stream& output) const
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

    return true;
}

bool internal_unregister_player_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool internal_unregister_player_req::serialize(std::string& output) const
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

bool internal_unregister_player_req::deserialize(SpringCat::System::Stream& input)
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

    return true;
}

bool internal_unregister_player_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool internal_unregister_player_req::deserialize(std::string& input)
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

GameMode internal_unregister_player_req::get_mode(void) const
{
    return static_cast<GameMode>(mode_);
}

void internal_unregister_player_req::set_mode(GameMode value)
{
    mode_ = value;
}

SpringCat::uint64_t internal_unregister_player_req::get_player_no(void) const
{
    return player_no_;
}

void internal_unregister_player_req::set_player_no(SpringCat::uint64_t value)
{
    player_no_ = value;
}

internal_unregister_player_ans::internal_unregister_player_ans(void)
    : __has_bits__(),
    result_(0),
    dest_player_no_(0)
{
}

internal_unregister_player_ans::internal_unregister_player_ans(const internal_unregister_player_ans& from)
    : __has_bits__(),
    result_(0),
    dest_player_no_(0)
{
    merge_from(from);
}

internal_unregister_player_ans::~internal_unregister_player_ans(void)
{
}

const SpringCat::Wave::type_info& internal_unregister_player_ans::static_type_info(void)
{
    return __internal_unregister_player_ans_type_info__;
}

const SpringCat::Wave::type_info& internal_unregister_player_ans::runtime_type_info(void) const
{
    return static_type_info();
}

internal_unregister_player_ans* internal_unregister_player_ans::new_instance(void) const
{
    return new internal_unregister_player_ans;
}

internal_unregister_player_ans* internal_unregister_player_ans::clone(void) const
{
    return new internal_unregister_player_ans(*this);
}

void internal_unregister_player_ans::clear(void)
{
    // result
    result_ = 0;
    // dest_player_no
    dest_player_no_ = 0;
}

bool internal_unregister_player_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t internal_unregister_player_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // dest_player_no
    total_size += SpringCat::Wave::internal::size(dest_player_no_);

    return total_size;
}

void internal_unregister_player_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const internal_unregister_player_ans& src = dynamic_cast<const internal_unregister_player_ans&>(from);
    copy_from(src);
}

void internal_unregister_player_ans::copy_from(const internal_unregister_player_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void internal_unregister_player_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const internal_unregister_player_ans& src = dynamic_cast<const internal_unregister_player_ans&>(from);
    merge_from(src);
}

void internal_unregister_player_ans::merge_from(const internal_unregister_player_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // dest_player_no
    set_dest_player_no(from.get_dest_player_no());
}

bool internal_unregister_player_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // dest_player_no
    if (SpringCat::Wave::internal::serialize(output, dest_player_no_) == false)
    {
        return false;
    }

    return true;
}

bool internal_unregister_player_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool internal_unregister_player_ans::serialize(std::string& output) const
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

bool internal_unregister_player_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // dest_player_no
    if (SpringCat::Wave::internal::deserialize(input, dest_player_no_) == false)
    {
        return false;
    }

    return true;
}

bool internal_unregister_player_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool internal_unregister_player_ans::deserialize(std::string& input)
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

SpringCat::int16_t internal_unregister_player_ans::get_result(void) const
{
    return result_;
}

void internal_unregister_player_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

SpringCat::uint64_t internal_unregister_player_ans::get_dest_player_no(void) const
{
    return dest_player_no_;
}

void internal_unregister_player_ans::set_dest_player_no(SpringCat::uint64_t value)
{
    dest_player_no_ = value;
}

internal_match_player_info::internal_match_player_info(void)
    : __has_bits__(),
    is_ai_(false),
    binded_xnet_addr_()
{
}

internal_match_player_info::internal_match_player_info(const internal_match_player_info& from)
    : __has_bits__(),
    is_ai_(false),
    binded_xnet_addr_()
{
    merge_from(from);
}

internal_match_player_info::~internal_match_player_info(void)
{
}

const SpringCat::Wave::type_info& internal_match_player_info::static_type_info(void)
{
    return __internal_match_player_info_type_info__;
}

const SpringCat::Wave::type_info& internal_match_player_info::runtime_type_info(void) const
{
    return static_type_info();
}

internal_match_player_info* internal_match_player_info::new_instance(void) const
{
    return new internal_match_player_info;
}

internal_match_player_info* internal_match_player_info::clone(void) const
{
    return new internal_match_player_info(*this);
}

void internal_match_player_info::clear(void)
{
    // is_ai
    is_ai_ = false;
    // binded_xnet_addr
    binded_xnet_addr_.clear();
}

bool internal_match_player_info::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t internal_match_player_info::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // is_ai
    total_size += SpringCat::Wave::internal::size(is_ai_);
    // binded_xnet_addr
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint32_t));
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::int8_t) * binded_xnet_addr_.size());

    return total_size;
}

void internal_match_player_info::copy_from(const SpringCat::Wave::object_base& from)
{
    const internal_match_player_info& src = dynamic_cast<const internal_match_player_info&>(from);
    copy_from(src);
}

void internal_match_player_info::copy_from(const internal_match_player_info& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void internal_match_player_info::merge_from(const SpringCat::Wave::object_base& from)
{
    const internal_match_player_info& src = dynamic_cast<const internal_match_player_info&>(from);
    merge_from(src);
}

void internal_match_player_info::merge_from(const internal_match_player_info& from)
{
    if (&from == this)
    {
        return;
    }

    // is_ai
    set_is_ai(from.get_is_ai());
    // binded_xnet_addr
    SpringCat::uint32_t binded_xnet_addr_size = static_cast<SpringCat::uint32_t>(from.binded_xnet_addr_.size());
    binded_xnet_addr_.reserve(binded_xnet_addr_.size() + binded_xnet_addr_size);
    std::copy(from.binded_xnet_addr_.begin(), from.binded_xnet_addr_.end(), std::back_inserter(binded_xnet_addr_));
}

bool internal_match_player_info::serialize(SpringCat::System::Stream& output) const
{
    // is_ai
    if (SpringCat::Wave::internal::serialize(output, is_ai_) == false)
    {
        return false;
    }
    // binded_xnet_addr
    SpringCat::uint32_t binded_xnet_addr_size = static_cast<SpringCat::uint32_t>(binded_xnet_addr_.size());
    if (SpringCat::Wave::internal::serialize(output, binded_xnet_addr_size) == false)
    {
        return false;
    }
    for (SpringCat::uint32_t i = 0; i != binded_xnet_addr_size; ++i)
    {
        if (SpringCat::Wave::internal::serialize(output, binded_xnet_addr_[i]) == false)
        {
            return false;
        }
    }

    return true;
}

bool internal_match_player_info::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool internal_match_player_info::serialize(std::string& output) const
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

bool internal_match_player_info::deserialize(SpringCat::System::Stream& input)
{
    // is_ai
    if (SpringCat::Wave::internal::deserialize(input, is_ai_) == false)
    {
        return false;
    }
    // binded_xnet_addr
    SpringCat::uint32_t binded_xnet_addr_size = 0;
    if (SpringCat::Wave::internal::deserialize(input, binded_xnet_addr_size) == false)
    {
        return false;
    }
    if (binded_xnet_addr_size > 0)
    {
        if (binded_xnet_addr_size > 0xFFFFFFFF)
        {
            binded_xnet_addr_size = 0xFFFFFFFF;
        }
        binded_xnet_addr_.resize(binded_xnet_addr_size);
        for (SpringCat::uint32_t i = 0; i != binded_xnet_addr_size; ++i)
        {
            if (SpringCat::Wave::internal::deserialize(input, binded_xnet_addr_[i]) == false)
            {
                return false;
            }
        }
    }

    return true;
}

bool internal_match_player_info::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool internal_match_player_info::deserialize(std::string& input)
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

bool internal_match_player_info::get_is_ai(void) const
{
    return is_ai_;
}

void internal_match_player_info::set_is_ai(bool value)
{
    is_ai_ = value;
}

const std::vector<SpringCat::int8_t>& internal_match_player_info::get_binded_xnet_addr(void) const
{
    return binded_xnet_addr_;
}

std::vector<SpringCat::int8_t>* internal_match_player_info::get_mutable_binded_xnet_addr(void)
{
    return &binded_xnet_addr_;
}

SpringCat::int8_t internal_match_player_info::get_binded_xnet_addr(size_t index) const
{
    if (binded_xnet_addr_.size() <= index)
    {
        throw std::out_of_range("internal_match_player_info::binded_xnet_addr_ index outside range");
    }

    return binded_xnet_addr_[index];
}

void internal_match_player_info::set_binded_xnet_addr(size_t index, SpringCat::int8_t value)
{
    if (binded_xnet_addr_.size() <= index)
    {
        throw std::out_of_range("internal_match_player_info::binded_xnet_addr_ index outside range");
    }

    binded_xnet_addr_[index] = value;
}

void internal_match_player_info::add_binded_xnet_addr(SpringCat::int8_t value)
{
    binded_xnet_addr_.push_back(value);
}

internal_create_ps_req::internal_create_ps_req(void)
    : __has_bits__(),
    mode_(0),
    room_no_(0),
    match_players_(),
    map_no_(0)
{
}

internal_create_ps_req::internal_create_ps_req(const internal_create_ps_req& from)
    : __has_bits__(),
    mode_(0),
    room_no_(0),
    match_players_(),
    map_no_(0)
{
    merge_from(from);
}

internal_create_ps_req::~internal_create_ps_req(void)
{
    // match_players
    for(std::map<SpringCat::uint64_t, internal_match_player_info*>::iterator it = match_players_.begin(); it != match_players_.end(); ++it)
    {
        delete it->second;
    }
    match_players_.clear();
}

const SpringCat::Wave::type_info& internal_create_ps_req::static_type_info(void)
{
    return __internal_create_ps_req_type_info__;
}

const SpringCat::Wave::type_info& internal_create_ps_req::runtime_type_info(void) const
{
    return static_type_info();
}

internal_create_ps_req* internal_create_ps_req::new_instance(void) const
{
    return new internal_create_ps_req;
}

internal_create_ps_req* internal_create_ps_req::clone(void) const
{
    return new internal_create_ps_req(*this);
}

void internal_create_ps_req::clear(void)
{
    // mode
    mode_ = 0;
    // room_no
    room_no_ = 0;
    // match_players
    for(std::map<SpringCat::uint64_t, internal_match_player_info*>::iterator it = match_players_.begin(); it != match_players_.end(); ++it)
    {
        delete it->second;
    }
    match_players_.clear();
    // map_no
    map_no_ = 0;
}

bool internal_create_ps_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t internal_create_ps_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // mode
    total_size += SpringCat::Wave::internal::size(mode_);
    // room_no
    total_size += SpringCat::Wave::internal::size(room_no_);
    // match_players
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint32_t));
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint64_t) * match_players_.size());
    for(std::map<SpringCat::uint64_t, internal_match_player_info*>::const_iterator it = match_players_.begin(); it != match_players_.end(); ++it)
    {
        total_size += SpringCat::Wave::internal::size(*it->second);
    }
    // map_no
    total_size += SpringCat::Wave::internal::size(map_no_);

    return total_size;
}

void internal_create_ps_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const internal_create_ps_req& src = dynamic_cast<const internal_create_ps_req&>(from);
    copy_from(src);
}

void internal_create_ps_req::copy_from(const internal_create_ps_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void internal_create_ps_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const internal_create_ps_req& src = dynamic_cast<const internal_create_ps_req&>(from);
    merge_from(src);
}

void internal_create_ps_req::merge_from(const internal_create_ps_req& from)
{
    if (&from == this)
    {
        return;
    }

    // mode
    set_mode(from.get_mode());
    // room_no
    set_room_no(from.get_room_no());
    // match_players
    for(std::map<SpringCat::uint64_t, internal_match_player_info*>::const_iterator it = from.match_players_.begin(); it != from.match_players_.end(); ++it)
    {
        insert_match_players(it->first)->copy_from(*it->second);
    }
    // map_no
    set_map_no(from.get_map_no());
}

bool internal_create_ps_req::serialize(SpringCat::System::Stream& output) const
{
    // mode
    if (SpringCat::Wave::internal::serialize(output, mode_) == false)
    {
        return false;
    }
    // room_no
    if (SpringCat::Wave::internal::serialize(output, room_no_) == false)
    {
        return false;
    }
    // match_players
    SpringCat::uint32_t match_players_size = static_cast<SpringCat::uint32_t>(match_players_.size());
    if (SpringCat::Wave::internal::serialize(output, match_players_size) == false)
    {
        return false;
    }
    for(std::map<SpringCat::uint64_t, internal_match_player_info*>::const_iterator it = match_players_.begin(); it != match_players_.end(); ++it)
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
    // map_no
    if (SpringCat::Wave::internal::serialize(output, map_no_) == false)
    {
        return false;
    }

    return true;
}

bool internal_create_ps_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool internal_create_ps_req::serialize(std::string& output) const
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

bool internal_create_ps_req::deserialize(SpringCat::System::Stream& input)
{
    // mode
    if (SpringCat::Wave::internal::deserialize(input, mode_) == false)
    {
        return false;
    }
    // room_no
    if (SpringCat::Wave::internal::deserialize(input, room_no_) == false)
    {
        return false;
    }
    // match_players
    SpringCat::uint32_t match_players_size = 0;
    if (SpringCat::Wave::internal::deserialize(input, match_players_size) == false)
    {
        return false;
    }
    for (SpringCat::uint32_t i = 0; i != match_players_size; ++i)
    {
        SpringCat::uint64_t key;
        if (SpringCat::Wave::internal::deserialize(input, key) == false)
        {
            return false;
        }
        internal_match_player_info* inserted = insert_match_players(key);
        if (SpringCat::Wave::internal::deserialize(input, *inserted) == false)
        {
        	return false;
        }
    }
    // map_no
    if (SpringCat::Wave::internal::deserialize(input, map_no_) == false)
    {
        return false;
    }

    return true;
}

bool internal_create_ps_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool internal_create_ps_req::deserialize(std::string& input)
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

GameMode internal_create_ps_req::get_mode(void) const
{
    return static_cast<GameMode>(mode_);
}

void internal_create_ps_req::set_mode(GameMode value)
{
    mode_ = value;
}

SpringCat::uint32_t internal_create_ps_req::get_room_no(void) const
{
    return room_no_;
}

void internal_create_ps_req::set_room_no(SpringCat::uint32_t value)
{
    room_no_ = value;
}

const std::map<SpringCat::uint64_t, internal_match_player_info*>& internal_create_ps_req::get_match_players(void) const
{
    return match_players_;
}

std::map<SpringCat::uint64_t, internal_match_player_info*>* internal_create_ps_req::get_mutable_match_players(void)
{
    return &match_players_;
}

const internal_match_player_info* internal_create_ps_req::get_match_players(SpringCat::uint64_t key) const
{
    std::map<SpringCat::uint64_t, internal_match_player_info*>::const_iterator it = match_players_.find(key);
    if(it == match_players_.end())
    {
        return NULL;
    }
    return it->second;
}

internal_match_player_info* internal_create_ps_req::get_mutable_match_players(SpringCat::uint64_t key)
{
    std::map<SpringCat::uint64_t, internal_match_player_info*>::iterator it = match_players_.find(key);
    if(it == match_players_.end())
    {
        return NULL;
    }
    return it->second;
}

internal_match_player_info* internal_create_ps_req::insert_match_players(SpringCat::uint64_t key)
{
    std::map<SpringCat::uint64_t, internal_match_player_info*>::iterator it = match_players_.find(key);
    if(it != match_players_.end())
    {
        return it->second;
    }
    std::auto_ptr<internal_match_player_info> new_match_players(new internal_match_player_info);
    match_players_.insert(std::make_pair(key, new_match_players.get()));
    return new_match_players.release();
}

SpringCat::int32_t internal_create_ps_req::get_map_no(void) const
{
    return map_no_;
}

void internal_create_ps_req::set_map_no(SpringCat::int32_t value)
{
    map_no_ = value;
}

internal_create_ps_ans::internal_create_ps_ans(void)
    : __has_bits__(),
    result_(0),
    mode_(0),
    room_no_(0),
    ps_addr_(new server_address)
{
}

internal_create_ps_ans::internal_create_ps_ans(const internal_create_ps_ans& from)
    : __has_bits__(),
    result_(0),
    mode_(0),
    room_no_(0),
    ps_addr_(new server_address)
{
    merge_from(from);
}

internal_create_ps_ans::~internal_create_ps_ans(void)
{
}

const SpringCat::Wave::type_info& internal_create_ps_ans::static_type_info(void)
{
    return __internal_create_ps_ans_type_info__;
}

const SpringCat::Wave::type_info& internal_create_ps_ans::runtime_type_info(void) const
{
    return static_type_info();
}

internal_create_ps_ans* internal_create_ps_ans::new_instance(void) const
{
    return new internal_create_ps_ans;
}

internal_create_ps_ans* internal_create_ps_ans::clone(void) const
{
    return new internal_create_ps_ans(*this);
}

void internal_create_ps_ans::clear(void)
{
    // result
    result_ = 0;
    // mode
    mode_ = 0;
    // room_no
    room_no_ = 0;
    // ps_addr
    ps_addr_->clear();
}

bool internal_create_ps_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t internal_create_ps_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // mode
    total_size += SpringCat::Wave::internal::size(mode_);
    // room_no
    total_size += SpringCat::Wave::internal::size(room_no_);
    // ps_addr
    total_size += SpringCat::Wave::internal::size(*ps_addr_);

    return total_size;
}

void internal_create_ps_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const internal_create_ps_ans& src = dynamic_cast<const internal_create_ps_ans&>(from);
    copy_from(src);
}

void internal_create_ps_ans::copy_from(const internal_create_ps_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void internal_create_ps_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const internal_create_ps_ans& src = dynamic_cast<const internal_create_ps_ans&>(from);
    merge_from(src);
}

void internal_create_ps_ans::merge_from(const internal_create_ps_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // mode
    set_mode(from.get_mode());
    // room_no
    set_room_no(from.get_room_no());
    // ps_addr
    ps_addr_->merge_from(*from.get_ps_addr());
}

bool internal_create_ps_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // mode
    if (SpringCat::Wave::internal::serialize(output, mode_) == false)
    {
        return false;
    }
    // room_no
    if (SpringCat::Wave::internal::serialize(output, room_no_) == false)
    {
        return false;
    }
    // ps_addr
    if (SpringCat::Wave::internal::serialize(output, *ps_addr_) == false)
    {
        return false;
    }

    return true;
}

bool internal_create_ps_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool internal_create_ps_ans::serialize(std::string& output) const
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

bool internal_create_ps_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // mode
    if (SpringCat::Wave::internal::deserialize(input, mode_) == false)
    {
        return false;
    }
    // room_no
    if (SpringCat::Wave::internal::deserialize(input, room_no_) == false)
    {
        return false;
    }
    // ps_addr
    if (SpringCat::Wave::internal::deserialize(input, *ps_addr_) == false)
    {
        return false;
    }

    return true;
}

bool internal_create_ps_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool internal_create_ps_ans::deserialize(std::string& input)
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

SpringCat::int16_t internal_create_ps_ans::get_result(void) const
{
    return result_;
}

void internal_create_ps_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

GameMode internal_create_ps_ans::get_mode(void) const
{
    return static_cast<GameMode>(mode_);
}

void internal_create_ps_ans::set_mode(GameMode value)
{
    mode_ = value;
}

SpringCat::uint32_t internal_create_ps_ans::get_room_no(void) const
{
    return room_no_;
}

void internal_create_ps_ans::set_room_no(SpringCat::uint32_t value)
{
    room_no_ = value;
}

const server_address* internal_create_ps_ans::get_ps_addr(void) const
{
    return ps_addr_.get();
}

server_address* internal_create_ps_ans::get_mutable_ps_addr(void)
{
    return ps_addr_.get();
}

internal_match_complete_notify::internal_match_complete_notify(void)
    : __has_bits__(),
    result_(0),
    dest_player_no_(0),
    player_list_(),
    mode_(0),
    use_standalone_(false),
    map_no_(0),
    ps_addr_(new server_address),
    using_match_items_(new match_item_info)
{
}

internal_match_complete_notify::internal_match_complete_notify(const internal_match_complete_notify& from)
    : __has_bits__(),
    result_(0),
    dest_player_no_(0),
    player_list_(),
    mode_(0),
    use_standalone_(false),
    map_no_(0),
    ps_addr_(new server_address),
    using_match_items_(new match_item_info)
{
    merge_from(from);
}

internal_match_complete_notify::~internal_match_complete_notify(void)
{
    // player_list
    player_list_.clear();
}

const SpringCat::Wave::type_info& internal_match_complete_notify::static_type_info(void)
{
    return __internal_match_complete_notify_type_info__;
}

const SpringCat::Wave::type_info& internal_match_complete_notify::runtime_type_info(void) const
{
    return static_type_info();
}

internal_match_complete_notify* internal_match_complete_notify::new_instance(void) const
{
    return new internal_match_complete_notify;
}

internal_match_complete_notify* internal_match_complete_notify::clone(void) const
{
    return new internal_match_complete_notify(*this);
}

void internal_match_complete_notify::clear(void)
{
    // result
    result_ = 0;
    // dest_player_no
    dest_player_no_ = 0;
    // player_list
    player_list_.clear();
    // mode
    mode_ = 0;
    // use_standalone
    use_standalone_ = false;
    // map_no
    map_no_ = 0;
    // ps_addr
    ps_addr_->clear();
    // using_match_items
    using_match_items_->clear();
}

bool internal_match_complete_notify::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t internal_match_complete_notify::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // dest_player_no
    total_size += SpringCat::Wave::internal::size(dest_player_no_);
    // player_list
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint32_t));
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint64_t) * player_list_.size());
    for(std::map<SpringCat::uint64_t, bool>::const_iterator it = player_list_.begin(); it != player_list_.end(); ++it)
    {
        total_size += sizeof(it->second);
    }
    // mode
    total_size += SpringCat::Wave::internal::size(mode_);
    // use_standalone
    total_size += SpringCat::Wave::internal::size(use_standalone_);
    // map_no
    total_size += SpringCat::Wave::internal::size(map_no_);
    // ps_addr
    total_size += SpringCat::Wave::internal::size(*ps_addr_);
    // using_match_items
    total_size += SpringCat::Wave::internal::size(*using_match_items_);

    return total_size;
}

void internal_match_complete_notify::copy_from(const SpringCat::Wave::object_base& from)
{
    const internal_match_complete_notify& src = dynamic_cast<const internal_match_complete_notify&>(from);
    copy_from(src);
}

void internal_match_complete_notify::copy_from(const internal_match_complete_notify& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void internal_match_complete_notify::merge_from(const SpringCat::Wave::object_base& from)
{
    const internal_match_complete_notify& src = dynamic_cast<const internal_match_complete_notify&>(from);
    merge_from(src);
}

void internal_match_complete_notify::merge_from(const internal_match_complete_notify& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // dest_player_no
    set_dest_player_no(from.get_dest_player_no());
    // player_list
    for(std::map<SpringCat::uint64_t, bool>::const_iterator it = from.player_list_.begin(); it != from.player_list_.end(); ++it)
    {
        insert_player_list(it->first, it->second);
    }
    // mode
    set_mode(from.get_mode());
    // use_standalone
    set_use_standalone(from.get_use_standalone());
    // map_no
    set_map_no(from.get_map_no());
    // ps_addr
    ps_addr_->merge_from(*from.get_ps_addr());
    // using_match_items
    using_match_items_->merge_from(*from.get_using_match_items());
}

bool internal_match_complete_notify::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // dest_player_no
    if (SpringCat::Wave::internal::serialize(output, dest_player_no_) == false)
    {
        return false;
    }
    // player_list
    SpringCat::uint32_t player_list_size = static_cast<SpringCat::uint32_t>(player_list_.size());
    if (SpringCat::Wave::internal::serialize(output, player_list_size) == false)
    {
        return false;
    }
    for(std::map<SpringCat::uint64_t, bool>::const_iterator it = player_list_.begin(); it != player_list_.end(); ++it)
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
    // mode
    if (SpringCat::Wave::internal::serialize(output, mode_) == false)
    {
        return false;
    }
    // use_standalone
    if (SpringCat::Wave::internal::serialize(output, use_standalone_) == false)
    {
        return false;
    }
    // map_no
    if (SpringCat::Wave::internal::serialize(output, map_no_) == false)
    {
        return false;
    }
    // ps_addr
    if (SpringCat::Wave::internal::serialize(output, *ps_addr_) == false)
    {
        return false;
    }
    // using_match_items
    if (SpringCat::Wave::internal::serialize(output, *using_match_items_) == false)
    {
        return false;
    }

    return true;
}

bool internal_match_complete_notify::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool internal_match_complete_notify::serialize(std::string& output) const
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

bool internal_match_complete_notify::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // dest_player_no
    if (SpringCat::Wave::internal::deserialize(input, dest_player_no_) == false)
    {
        return false;
    }
    // player_list
    SpringCat::uint32_t player_list_size = 0;
    if (SpringCat::Wave::internal::deserialize(input, player_list_size) == false)
    {
        return false;
    }
    for (SpringCat::uint32_t i = 0; i != player_list_size; ++i)
    {
        SpringCat::uint64_t key;
        if (SpringCat::Wave::internal::deserialize(input, key) == false)
        {
            return false;
        }
        bool value;
        if (SpringCat::Wave::internal::deserialize(input, value) == false)
        {
            return false;
        }
        insert_player_list(key, value);
    }
    // mode
    if (SpringCat::Wave::internal::deserialize(input, mode_) == false)
    {
        return false;
    }
    // use_standalone
    if (SpringCat::Wave::internal::deserialize(input, use_standalone_) == false)
    {
        return false;
    }
    // map_no
    if (SpringCat::Wave::internal::deserialize(input, map_no_) == false)
    {
        return false;
    }
    // ps_addr
    if (SpringCat::Wave::internal::deserialize(input, *ps_addr_) == false)
    {
        return false;
    }
    // using_match_items
    if (SpringCat::Wave::internal::deserialize(input, *using_match_items_) == false)
    {
        return false;
    }

    return true;
}

bool internal_match_complete_notify::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool internal_match_complete_notify::deserialize(std::string& input)
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

SpringCat::int16_t internal_match_complete_notify::get_result(void) const
{
    return result_;
}

void internal_match_complete_notify::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

SpringCat::uint64_t internal_match_complete_notify::get_dest_player_no(void) const
{
    return dest_player_no_;
}

void internal_match_complete_notify::set_dest_player_no(SpringCat::uint64_t value)
{
    dest_player_no_ = value;
}

const std::map<SpringCat::uint64_t, bool>& internal_match_complete_notify::get_player_list(void) const
{
    return player_list_;
}

std::map<SpringCat::uint64_t, bool>* internal_match_complete_notify::get_mutable_player_list(void)
{
    return &player_list_;
}

bool internal_match_complete_notify::get_player_list(SpringCat::uint64_t key, bool* value) const
{
    std::map<SpringCat::uint64_t, bool>::const_iterator it = player_list_.find(key);
    if(it == player_list_.end())
    {
        return false;
    }

    if(value)
    {
        *value = it->second;
    }

    return true;
}

void internal_match_complete_notify::set_player_list(SpringCat::uint64_t key, bool value)
{
    player_list_[key] = value;
}

bool internal_match_complete_notify::insert_player_list(SpringCat::uint64_t key, bool value)
{
    return player_list_.insert(std::make_pair(key, value)).second;
}


GameMode internal_match_complete_notify::get_mode(void) const
{
    return static_cast<GameMode>(mode_);
}

void internal_match_complete_notify::set_mode(GameMode value)
{
    mode_ = value;
}

bool internal_match_complete_notify::get_use_standalone(void) const
{
    return use_standalone_;
}

void internal_match_complete_notify::set_use_standalone(bool value)
{
    use_standalone_ = value;
}

SpringCat::int32_t internal_match_complete_notify::get_map_no(void) const
{
    return map_no_;
}

void internal_match_complete_notify::set_map_no(SpringCat::int32_t value)
{
    map_no_ = value;
}

const server_address* internal_match_complete_notify::get_ps_addr(void) const
{
    return ps_addr_.get();
}

server_address* internal_match_complete_notify::get_mutable_ps_addr(void)
{
    return ps_addr_.get();
}

const match_item_info* internal_match_complete_notify::get_using_match_items(void) const
{
    return using_match_items_.get();
}

match_item_info* internal_match_complete_notify::get_mutable_using_match_items(void)
{
    return using_match_items_.get();
}



}    // namespace protocol
