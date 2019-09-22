#include "internal_as_ls.dc.h"
#include <stdexcept>


namespace protocol
{

// class name: internal_login_req, type id(decimal): 198342017, type id(hex): 0xBD27581
static const SpringCat::Wave::type_info __internal_login_req_type_info__(0xBD27581, "protocol.internal_login_req");
// class name: internal_login_ans, type id(decimal): 198331155, type id(hex): 0xBD24B13
static const SpringCat::Wave::type_info __internal_login_ans_type_info__(0xBD24B13, "protocol.internal_login_ans");

internal_login_req::internal_login_req(void)
    : __has_bits__(),
    player_no_(0),
    key_(),
    iv_()
{
}

internal_login_req::internal_login_req(const internal_login_req& from)
    : __has_bits__(),
    player_no_(0),
    key_(),
    iv_()
{
    merge_from(from);
}

internal_login_req::~internal_login_req(void)
{
}

const SpringCat::Wave::type_info& internal_login_req::static_type_info(void)
{
    return __internal_login_req_type_info__;
}

const SpringCat::Wave::type_info& internal_login_req::runtime_type_info(void) const
{
    return static_type_info();
}

internal_login_req* internal_login_req::new_instance(void) const
{
    return new internal_login_req;
}

internal_login_req* internal_login_req::clone(void) const
{
    return new internal_login_req(*this);
}

void internal_login_req::clear(void)
{
    // player_no
    player_no_ = 0;
    // key
    key_.clear();
    // iv
    iv_.clear();
}

bool internal_login_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t internal_login_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // player_no
    total_size += SpringCat::Wave::internal::size(player_no_);
    // key
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint32_t));
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint8_t) * key_.size());
    // iv
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint32_t));
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint8_t) * iv_.size());

    return total_size;
}

void internal_login_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const internal_login_req& src = dynamic_cast<const internal_login_req&>(from);
    copy_from(src);
}

void internal_login_req::copy_from(const internal_login_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void internal_login_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const internal_login_req& src = dynamic_cast<const internal_login_req&>(from);
    merge_from(src);
}

void internal_login_req::merge_from(const internal_login_req& from)
{
    if (&from == this)
    {
        return;
    }

    // player_no
    set_player_no(from.get_player_no());
    // key
    SpringCat::uint32_t key_size = static_cast<SpringCat::uint32_t>(from.key_.size());
    key_.reserve(key_.size() + key_size);
    std::copy(from.key_.begin(), from.key_.end(), std::back_inserter(key_));
    // iv
    SpringCat::uint32_t iv_size = static_cast<SpringCat::uint32_t>(from.iv_.size());
    iv_.reserve(iv_.size() + iv_size);
    std::copy(from.iv_.begin(), from.iv_.end(), std::back_inserter(iv_));
}

bool internal_login_req::serialize(SpringCat::System::Stream& output) const
{
    // player_no
    if (SpringCat::Wave::internal::serialize(output, player_no_) == false)
    {
        return false;
    }
    // key
    SpringCat::uint32_t key_size = static_cast<SpringCat::uint32_t>(key_.size());
    if (SpringCat::Wave::internal::serialize(output, key_size) == false)
    {
        return false;
    }
    for (SpringCat::uint32_t i = 0; i != key_size; ++i)
    {
        if (SpringCat::Wave::internal::serialize(output, key_[i]) == false)
        {
            return false;
        }
    }
    // iv
    SpringCat::uint32_t iv_size = static_cast<SpringCat::uint32_t>(iv_.size());
    if (SpringCat::Wave::internal::serialize(output, iv_size) == false)
    {
        return false;
    }
    for (SpringCat::uint32_t i = 0; i != iv_size; ++i)
    {
        if (SpringCat::Wave::internal::serialize(output, iv_[i]) == false)
        {
            return false;
        }
    }

    return true;
}

bool internal_login_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool internal_login_req::serialize(std::string& output) const
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

bool internal_login_req::deserialize(SpringCat::System::Stream& input)
{
    // player_no
    if (SpringCat::Wave::internal::deserialize(input, player_no_) == false)
    {
        return false;
    }
    // key
    SpringCat::uint32_t key_size = 0;
    if (SpringCat::Wave::internal::deserialize(input, key_size) == false)
    {
        return false;
    }
    if (key_size > 0)
    {
        if (key_size > 0xFFFFFFFF)
        {
            key_size = 0xFFFFFFFF;
        }
        key_.resize(key_size);
        for (SpringCat::uint32_t i = 0; i != key_size; ++i)
        {
            if (SpringCat::Wave::internal::deserialize(input, key_[i]) == false)
            {
                return false;
            }
        }
    }
    // iv
    SpringCat::uint32_t iv_size = 0;
    if (SpringCat::Wave::internal::deserialize(input, iv_size) == false)
    {
        return false;
    }
    if (iv_size > 0)
    {
        if (iv_size > 0xFFFFFFFF)
        {
            iv_size = 0xFFFFFFFF;
        }
        iv_.resize(iv_size);
        for (SpringCat::uint32_t i = 0; i != iv_size; ++i)
        {
            if (SpringCat::Wave::internal::deserialize(input, iv_[i]) == false)
            {
                return false;
            }
        }
    }

    return true;
}

bool internal_login_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool internal_login_req::deserialize(std::string& input)
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

SpringCat::uint64_t internal_login_req::get_player_no(void) const
{
    return player_no_;
}

void internal_login_req::set_player_no(SpringCat::uint64_t value)
{
    player_no_ = value;
}

const std::vector<SpringCat::uint8_t>& internal_login_req::get_key(void) const
{
    return key_;
}

std::vector<SpringCat::uint8_t>* internal_login_req::get_mutable_key(void)
{
    return &key_;
}

SpringCat::uint8_t internal_login_req::get_key(size_t index) const
{
    if (key_.size() <= index)
    {
        throw std::out_of_range("internal_login_req::key_ index outside range");
    }

    return key_[index];
}

void internal_login_req::set_key(size_t index, SpringCat::uint8_t value)
{
    if (key_.size() <= index)
    {
        throw std::out_of_range("internal_login_req::key_ index outside range");
    }

    key_[index] = value;
}

void internal_login_req::add_key(SpringCat::uint8_t value)
{
    key_.push_back(value);
}

const std::vector<SpringCat::uint8_t>& internal_login_req::get_iv(void) const
{
    return iv_;
}

std::vector<SpringCat::uint8_t>* internal_login_req::get_mutable_iv(void)
{
    return &iv_;
}

SpringCat::uint8_t internal_login_req::get_iv(size_t index) const
{
    if (iv_.size() <= index)
    {
        throw std::out_of_range("internal_login_req::iv_ index outside range");
    }

    return iv_[index];
}

void internal_login_req::set_iv(size_t index, SpringCat::uint8_t value)
{
    if (iv_.size() <= index)
    {
        throw std::out_of_range("internal_login_req::iv_ index outside range");
    }

    iv_[index] = value;
}

void internal_login_req::add_iv(SpringCat::uint8_t value)
{
    iv_.push_back(value);
}

internal_login_ans::internal_login_ans(void)
    : __has_bits__(),
    result_(0),
    player_no_(0),
    session_id_(0),
    ls_addr_(new server_address)
{
}

internal_login_ans::internal_login_ans(const internal_login_ans& from)
    : __has_bits__(),
    result_(0),
    player_no_(0),
    session_id_(0),
    ls_addr_(new server_address)
{
    merge_from(from);
}

internal_login_ans::~internal_login_ans(void)
{
}

const SpringCat::Wave::type_info& internal_login_ans::static_type_info(void)
{
    return __internal_login_ans_type_info__;
}

const SpringCat::Wave::type_info& internal_login_ans::runtime_type_info(void) const
{
    return static_type_info();
}

internal_login_ans* internal_login_ans::new_instance(void) const
{
    return new internal_login_ans;
}

internal_login_ans* internal_login_ans::clone(void) const
{
    return new internal_login_ans(*this);
}

void internal_login_ans::clear(void)
{
    // result
    result_ = 0;
    // player_no
    player_no_ = 0;
    // session_id
    session_id_ = 0;
    // ls_addr
    ls_addr_->clear();
}

bool internal_login_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t internal_login_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // player_no
    total_size += SpringCat::Wave::internal::size(player_no_);
    // session_id
    total_size += SpringCat::Wave::internal::size(session_id_);
    // ls_addr
    total_size += SpringCat::Wave::internal::size(*ls_addr_);

    return total_size;
}

void internal_login_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const internal_login_ans& src = dynamic_cast<const internal_login_ans&>(from);
    copy_from(src);
}

void internal_login_ans::copy_from(const internal_login_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void internal_login_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const internal_login_ans& src = dynamic_cast<const internal_login_ans&>(from);
    merge_from(src);
}

void internal_login_ans::merge_from(const internal_login_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // player_no
    set_player_no(from.get_player_no());
    // session_id
    set_session_id(from.get_session_id());
    // ls_addr
    ls_addr_->merge_from(*from.get_ls_addr());
}

bool internal_login_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // player_no
    if (SpringCat::Wave::internal::serialize(output, player_no_) == false)
    {
        return false;
    }
    // session_id
    if (SpringCat::Wave::internal::serialize(output, session_id_) == false)
    {
        return false;
    }
    // ls_addr
    if (SpringCat::Wave::internal::serialize(output, *ls_addr_) == false)
    {
        return false;
    }

    return true;
}

bool internal_login_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool internal_login_ans::serialize(std::string& output) const
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

bool internal_login_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // player_no
    if (SpringCat::Wave::internal::deserialize(input, player_no_) == false)
    {
        return false;
    }
    // session_id
    if (SpringCat::Wave::internal::deserialize(input, session_id_) == false)
    {
        return false;
    }
    // ls_addr
    if (SpringCat::Wave::internal::deserialize(input, *ls_addr_) == false)
    {
        return false;
    }

    return true;
}

bool internal_login_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool internal_login_ans::deserialize(std::string& input)
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

SpringCat::int16_t internal_login_ans::get_result(void) const
{
    return result_;
}

void internal_login_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

SpringCat::uint64_t internal_login_ans::get_player_no(void) const
{
    return player_no_;
}

void internal_login_ans::set_player_no(SpringCat::uint64_t value)
{
    player_no_ = value;
}

SpringCat::int32_t internal_login_ans::get_session_id(void) const
{
    return session_id_;
}

void internal_login_ans::set_session_id(SpringCat::int32_t value)
{
    session_id_ = value;
}

const server_address* internal_login_ans::get_ls_addr(void) const
{
    return ls_addr_.get();
}

server_address* internal_login_ans::get_mutable_ls_addr(void)
{
    return ls_addr_.get();
}



}    // namespace protocol
