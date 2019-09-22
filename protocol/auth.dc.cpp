#include "auth.dc.h"
#include <stdexcept>


namespace protocol
{

// class name: session_key_req, type id(decimal): 74914321, type id(hex): 0x4771A11
static const SpringCat::Wave::type_info __session_key_req_type_info__(0x4771A11, "protocol.session_key_req");
// class name: session_key_ans, type id(decimal): 74917507, type id(hex): 0x4772683
static const SpringCat::Wave::type_info __session_key_ans_type_info__(0x4772683, "protocol.session_key_ans");
// class name: login_req, type id(decimal): 49042113, type id(hex): 0x2EC52C1
static const SpringCat::Wave::type_info __login_req_type_info__(0x2EC52C1, "protocol.login_req");
// class name: login_ans, type id(decimal): 49049171, type id(hex): 0x2EC6E53
static const SpringCat::Wave::type_info __login_ans_type_info__(0x2EC6E53, "protocol.login_ans");
// class name: logout_req, type id(decimal): 72075505, type id(hex): 0x44BC8F1
static const SpringCat::Wave::type_info __logout_req_type_info__(0x44BC8F1, "protocol.logout_req");
// class name: logout_ans, type id(decimal): 72087651, type id(hex): 0x44BF863
static const SpringCat::Wave::type_info __logout_ans_type_info__(0x44BF863, "protocol.logout_ans");
// class name: heartbeat, type id(decimal): 129150564, type id(hex): 0x7B2AE64
static const SpringCat::Wave::type_info __heartbeat_type_info__(0x7B2AE64, "protocol.heartbeat");
// class name: quit_req, type id(decimal): 268233713, type id(hex): 0xFFCEBF1
static const SpringCat::Wave::type_info __quit_req_type_info__(0xFFCEBF1, "protocol.quit_req");
// class name: quit_ans, type id(decimal): 268227939, type id(hex): 0xFFCD563
static const SpringCat::Wave::type_info __quit_ans_type_info__(0xFFCD563, "protocol.quit_ans");

session_key_req::session_key_req(void)
{
}

session_key_req::session_key_req(const session_key_req& from)
{
    merge_from(from);
}

session_key_req::~session_key_req(void)
{
}

const SpringCat::Wave::type_info& session_key_req::static_type_info(void)
{
    return __session_key_req_type_info__;
}

const SpringCat::Wave::type_info& session_key_req::runtime_type_info(void) const
{
    return static_type_info();
}

session_key_req* session_key_req::new_instance(void) const
{
    return new session_key_req;
}

session_key_req* session_key_req::clone(void) const
{
    return new session_key_req(*this);
}

void session_key_req::clear(void)
{
}

bool session_key_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t session_key_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    return total_size;
}

void session_key_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const session_key_req& src = dynamic_cast<const session_key_req&>(from);
    copy_from(src);
}

void session_key_req::copy_from(const session_key_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void session_key_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const session_key_req& src = dynamic_cast<const session_key_req&>(from);
    merge_from(src);
}

void session_key_req::merge_from(const session_key_req& from)
{
    if (&from == this)
    {
        return;
    }
}

bool session_key_req::serialize(SpringCat::System::Stream& output) const
{
    return true;
}

bool session_key_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool session_key_req::serialize(std::string& output) const
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

bool session_key_req::deserialize(SpringCat::System::Stream& input)
{
    return true;
}

bool session_key_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool session_key_req::deserialize(std::string& input)
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

session_key_ans::session_key_ans(void)
    : __has_bits__(),
    key_(),
    iv_()
{
}

session_key_ans::session_key_ans(const session_key_ans& from)
    : __has_bits__(),
    key_(),
    iv_()
{
    merge_from(from);
}

session_key_ans::~session_key_ans(void)
{
}

const SpringCat::Wave::type_info& session_key_ans::static_type_info(void)
{
    return __session_key_ans_type_info__;
}

const SpringCat::Wave::type_info& session_key_ans::runtime_type_info(void) const
{
    return static_type_info();
}

session_key_ans* session_key_ans::new_instance(void) const
{
    return new session_key_ans;
}

session_key_ans* session_key_ans::clone(void) const
{
    return new session_key_ans(*this);
}

void session_key_ans::clear(void)
{
    // key
    key_.clear();
    // iv
    iv_.clear();
}

bool session_key_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t session_key_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // key
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint32_t));
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint8_t) * key_.size());
    // iv
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint32_t));
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint8_t) * iv_.size());

    return total_size;
}

void session_key_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const session_key_ans& src = dynamic_cast<const session_key_ans&>(from);
    copy_from(src);
}

void session_key_ans::copy_from(const session_key_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void session_key_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const session_key_ans& src = dynamic_cast<const session_key_ans&>(from);
    merge_from(src);
}

void session_key_ans::merge_from(const session_key_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // key
    SpringCat::uint32_t key_size = static_cast<SpringCat::uint32_t>(from.key_.size());
    key_.reserve(key_.size() + key_size);
    std::copy(from.key_.begin(), from.key_.end(), std::back_inserter(key_));
    // iv
    SpringCat::uint32_t iv_size = static_cast<SpringCat::uint32_t>(from.iv_.size());
    iv_.reserve(iv_.size() + iv_size);
    std::copy(from.iv_.begin(), from.iv_.end(), std::back_inserter(iv_));
}

bool session_key_ans::serialize(SpringCat::System::Stream& output) const
{
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

bool session_key_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool session_key_ans::serialize(std::string& output) const
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

bool session_key_ans::deserialize(SpringCat::System::Stream& input)
{
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

bool session_key_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool session_key_ans::deserialize(std::string& input)
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

const std::vector<SpringCat::uint8_t>& session_key_ans::get_key(void) const
{
    return key_;
}

std::vector<SpringCat::uint8_t>* session_key_ans::get_mutable_key(void)
{
    return &key_;
}

SpringCat::uint8_t session_key_ans::get_key(size_t index) const
{
    if (key_.size() <= index)
    {
        throw std::out_of_range("session_key_ans::key_ index outside range");
    }

    return key_[index];
}

void session_key_ans::set_key(size_t index, SpringCat::uint8_t value)
{
    if (key_.size() <= index)
    {
        throw std::out_of_range("session_key_ans::key_ index outside range");
    }

    key_[index] = value;
}

void session_key_ans::add_key(SpringCat::uint8_t value)
{
    key_.push_back(value);
}

const std::vector<SpringCat::uint8_t>& session_key_ans::get_iv(void) const
{
    return iv_;
}

std::vector<SpringCat::uint8_t>* session_key_ans::get_mutable_iv(void)
{
    return &iv_;
}

SpringCat::uint8_t session_key_ans::get_iv(size_t index) const
{
    if (iv_.size() <= index)
    {
        throw std::out_of_range("session_key_ans::iv_ index outside range");
    }

    return iv_[index];
}

void session_key_ans::set_iv(size_t index, SpringCat::uint8_t value)
{
    if (iv_.size() <= index)
    {
        throw std::out_of_range("session_key_ans::iv_ index outside range");
    }

    iv_[index] = value;
}

void session_key_ans::add_iv(SpringCat::uint8_t value)
{
    iv_.push_back(value);
}

login_req::login_req(void)
    : __has_bits__(),
    login_type_(0),
    version_(0),
    acc_token_()
{
}

login_req::login_req(const login_req& from)
    : __has_bits__(),
    login_type_(0),
    version_(0),
    acc_token_()
{
    merge_from(from);
}

login_req::~login_req(void)
{
}

const SpringCat::Wave::type_info& login_req::static_type_info(void)
{
    return __login_req_type_info__;
}

const SpringCat::Wave::type_info& login_req::runtime_type_info(void) const
{
    return static_type_info();
}

login_req* login_req::new_instance(void) const
{
    return new login_req;
}

login_req* login_req::clone(void) const
{
    return new login_req(*this);
}

void login_req::clear(void)
{
    // login_type
    login_type_ = 0;
    // version
    version_ = 0;
    // acc_token
    acc_token_.clear();
}

bool login_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t login_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // login_type
    total_size += SpringCat::Wave::internal::size(login_type_);
    // version
    total_size += SpringCat::Wave::internal::size(version_);
    // acc_token
    total_size += SpringCat::Wave::internal::size(acc_token_, 1024);

    return total_size;
}

void login_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const login_req& src = dynamic_cast<const login_req&>(from);
    copy_from(src);
}

void login_req::copy_from(const login_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void login_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const login_req& src = dynamic_cast<const login_req&>(from);
    merge_from(src);
}

void login_req::merge_from(const login_req& from)
{
    if (&from == this)
    {
        return;
    }

    // login_type
    set_login_type(from.get_login_type());
    // version
    set_version(from.get_version());
    // acc_token
    set_acc_token(from.get_acc_token());
}

bool login_req::serialize(SpringCat::System::Stream& output) const
{
    // login_type
    if (SpringCat::Wave::internal::serialize(output, login_type_) == false)
    {
        return false;
    }
    // version
    if (SpringCat::Wave::internal::serialize(output, version_) == false)
    {
        return false;
    }
    // acc_token
    if (SpringCat::Wave::internal::serialize(output, acc_token_, 1024) == false)
    {
        return false;
    }

    return true;
}

bool login_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool login_req::serialize(std::string& output) const
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

bool login_req::deserialize(SpringCat::System::Stream& input)
{
    // login_type
    if (SpringCat::Wave::internal::deserialize(input, login_type_) == false)
    {
        return false;
    }
    // version
    if (SpringCat::Wave::internal::deserialize(input, version_) == false)
    {
        return false;
    }
    // acc_token
    if (SpringCat::Wave::internal::deserialize(input, acc_token_, 1024) == false)
    {
        return false;
    }

    return true;
}

bool login_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool login_req::deserialize(std::string& input)
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

LoginType login_req::get_login_type(void) const
{
    return static_cast<LoginType>(login_type_);
}

void login_req::set_login_type(LoginType value)
{
    login_type_ = value;
}

SpringCat::int16_t login_req::get_version(void) const
{
    return version_;
}

void login_req::set_version(SpringCat::int16_t value)
{
    version_ = value;
}

const std::string& login_req::get_acc_token(void) const
{
    return acc_token_;
}

std::string* login_req::get_mutable_acc_token(void)
{
    return &acc_token_;
}

void login_req::set_acc_token(const std::string& value)
{
    acc_token_.assign(value);
}

void login_req::set_acc_token(const char* value)
{
    acc_token_.assign(value);
}

login_ans::login_ans(void)
    : __has_bits__(),
    result_(0),
    session_id_(0),
    server_timestamp_(0),
    assigned_ls_addr_(new server_address),
    progress_(0)
{
}

login_ans::login_ans(const login_ans& from)
    : __has_bits__(),
    result_(0),
    session_id_(0),
    server_timestamp_(0),
    assigned_ls_addr_(new server_address),
    progress_(0)
{
    merge_from(from);
}

login_ans::~login_ans(void)
{
}

const SpringCat::Wave::type_info& login_ans::static_type_info(void)
{
    return __login_ans_type_info__;
}

const SpringCat::Wave::type_info& login_ans::runtime_type_info(void) const
{
    return static_type_info();
}

login_ans* login_ans::new_instance(void) const
{
    return new login_ans;
}

login_ans* login_ans::clone(void) const
{
    return new login_ans(*this);
}

void login_ans::clear(void)
{
    // result
    result_ = 0;
    // session_id
    session_id_ = 0;
    // server_timestamp
    server_timestamp_ = 0;
    // assigned_ls_addr
    assigned_ls_addr_->clear();
    // progress
    progress_ = 0;
}

bool login_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t login_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // session_id
    total_size += SpringCat::Wave::internal::size(session_id_);
    // server_timestamp
    total_size += SpringCat::Wave::internal::size(server_timestamp_);
    // assigned_ls_addr
    total_size += SpringCat::Wave::internal::size(*assigned_ls_addr_);
    // progress
    total_size += SpringCat::Wave::internal::size(progress_);

    return total_size;
}

void login_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const login_ans& src = dynamic_cast<const login_ans&>(from);
    copy_from(src);
}

void login_ans::copy_from(const login_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void login_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const login_ans& src = dynamic_cast<const login_ans&>(from);
    merge_from(src);
}

void login_ans::merge_from(const login_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // session_id
    set_session_id(from.get_session_id());
    // server_timestamp
    set_server_timestamp(from.get_server_timestamp());
    // assigned_ls_addr
    assigned_ls_addr_->merge_from(*from.get_assigned_ls_addr());
    // progress
    set_progress(from.get_progress());
}

bool login_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // session_id
    if (SpringCat::Wave::internal::serialize(output, session_id_) == false)
    {
        return false;
    }
    // server_timestamp
    if (SpringCat::Wave::internal::serialize(output, server_timestamp_) == false)
    {
        return false;
    }
    // assigned_ls_addr
    if (SpringCat::Wave::internal::serialize(output, *assigned_ls_addr_) == false)
    {
        return false;
    }
    // progress
    if (SpringCat::Wave::internal::serialize(output, progress_) == false)
    {
        return false;
    }

    return true;
}

bool login_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool login_ans::serialize(std::string& output) const
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

bool login_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // session_id
    if (SpringCat::Wave::internal::deserialize(input, session_id_) == false)
    {
        return false;
    }
    // server_timestamp
    if (SpringCat::Wave::internal::deserialize(input, server_timestamp_) == false)
    {
        return false;
    }
    // assigned_ls_addr
    if (SpringCat::Wave::internal::deserialize(input, *assigned_ls_addr_) == false)
    {
        return false;
    }
    // progress
    if (SpringCat::Wave::internal::deserialize(input, progress_) == false)
    {
        return false;
    }

    return true;
}

bool login_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool login_ans::deserialize(std::string& input)
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

SpringCat::int16_t login_ans::get_result(void) const
{
    return result_;
}

void login_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

SpringCat::int32_t login_ans::get_session_id(void) const
{
    return session_id_;
}

void login_ans::set_session_id(SpringCat::int32_t value)
{
    session_id_ = value;
}

SpringCat::int64_t login_ans::get_server_timestamp(void) const
{
    return server_timestamp_;
}

void login_ans::set_server_timestamp(SpringCat::int64_t value)
{
    server_timestamp_ = value;
}

const server_address* login_ans::get_assigned_ls_addr(void) const
{
    return assigned_ls_addr_.get();
}

server_address* login_ans::get_mutable_assigned_ls_addr(void)
{
    return assigned_ls_addr_.get();
}

TutorialProgress login_ans::get_progress(void) const
{
    return static_cast<TutorialProgress>(progress_);
}

void login_ans::set_progress(TutorialProgress value)
{
    progress_ = value;
}

logout_req::logout_req(void)
    : __has_bits__(),
    session_id_(0)
{
}

logout_req::logout_req(const logout_req& from)
    : __has_bits__(),
    session_id_(0)
{
    merge_from(from);
}

logout_req::~logout_req(void)
{
}

const SpringCat::Wave::type_info& logout_req::static_type_info(void)
{
    return __logout_req_type_info__;
}

const SpringCat::Wave::type_info& logout_req::runtime_type_info(void) const
{
    return static_type_info();
}

logout_req* logout_req::new_instance(void) const
{
    return new logout_req;
}

logout_req* logout_req::clone(void) const
{
    return new logout_req(*this);
}

void logout_req::clear(void)
{
    // session_id
    session_id_ = 0;
}

bool logout_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t logout_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // session_id
    total_size += SpringCat::Wave::internal::size(session_id_);

    return total_size;
}

void logout_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const logout_req& src = dynamic_cast<const logout_req&>(from);
    copy_from(src);
}

void logout_req::copy_from(const logout_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void logout_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const logout_req& src = dynamic_cast<const logout_req&>(from);
    merge_from(src);
}

void logout_req::merge_from(const logout_req& from)
{
    if (&from == this)
    {
        return;
    }

    // session_id
    set_session_id(from.get_session_id());
}

bool logout_req::serialize(SpringCat::System::Stream& output) const
{
    // session_id
    if (SpringCat::Wave::internal::serialize(output, session_id_) == false)
    {
        return false;
    }

    return true;
}

bool logout_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool logout_req::serialize(std::string& output) const
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

bool logout_req::deserialize(SpringCat::System::Stream& input)
{
    // session_id
    if (SpringCat::Wave::internal::deserialize(input, session_id_) == false)
    {
        return false;
    }

    return true;
}

bool logout_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool logout_req::deserialize(std::string& input)
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

SpringCat::int32_t logout_req::get_session_id(void) const
{
    return session_id_;
}

void logout_req::set_session_id(SpringCat::int32_t value)
{
    session_id_ = value;
}

logout_ans::logout_ans(void)
    : __has_bits__(),
    result_(0)
{
}

logout_ans::logout_ans(const logout_ans& from)
    : __has_bits__(),
    result_(0)
{
    merge_from(from);
}

logout_ans::~logout_ans(void)
{
}

const SpringCat::Wave::type_info& logout_ans::static_type_info(void)
{
    return __logout_ans_type_info__;
}

const SpringCat::Wave::type_info& logout_ans::runtime_type_info(void) const
{
    return static_type_info();
}

logout_ans* logout_ans::new_instance(void) const
{
    return new logout_ans;
}

logout_ans* logout_ans::clone(void) const
{
    return new logout_ans(*this);
}

void logout_ans::clear(void)
{
    // result
    result_ = 0;
}

bool logout_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t logout_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);

    return total_size;
}

void logout_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const logout_ans& src = dynamic_cast<const logout_ans&>(from);
    copy_from(src);
}

void logout_ans::copy_from(const logout_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void logout_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const logout_ans& src = dynamic_cast<const logout_ans&>(from);
    merge_from(src);
}

void logout_ans::merge_from(const logout_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
}

bool logout_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }

    return true;
}

bool logout_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool logout_ans::serialize(std::string& output) const
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

bool logout_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }

    return true;
}

bool logout_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool logout_ans::deserialize(std::string& input)
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

SpringCat::int16_t logout_ans::get_result(void) const
{
    return result_;
}

void logout_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

heartbeat::heartbeat(void)
{
}

heartbeat::heartbeat(const heartbeat& from)
{
    merge_from(from);
}

heartbeat::~heartbeat(void)
{
}

const SpringCat::Wave::type_info& heartbeat::static_type_info(void)
{
    return __heartbeat_type_info__;
}

const SpringCat::Wave::type_info& heartbeat::runtime_type_info(void) const
{
    return static_type_info();
}

heartbeat* heartbeat::new_instance(void) const
{
    return new heartbeat;
}

heartbeat* heartbeat::clone(void) const
{
    return new heartbeat(*this);
}

void heartbeat::clear(void)
{
}

bool heartbeat::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t heartbeat::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    return total_size;
}

void heartbeat::copy_from(const SpringCat::Wave::object_base& from)
{
    const heartbeat& src = dynamic_cast<const heartbeat&>(from);
    copy_from(src);
}

void heartbeat::copy_from(const heartbeat& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void heartbeat::merge_from(const SpringCat::Wave::object_base& from)
{
    const heartbeat& src = dynamic_cast<const heartbeat&>(from);
    merge_from(src);
}

void heartbeat::merge_from(const heartbeat& from)
{
    if (&from == this)
    {
        return;
    }
}

bool heartbeat::serialize(SpringCat::System::Stream& output) const
{
    return true;
}

bool heartbeat::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool heartbeat::serialize(std::string& output) const
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

bool heartbeat::deserialize(SpringCat::System::Stream& input)
{
    return true;
}

bool heartbeat::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool heartbeat::deserialize(std::string& input)
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

quit_req::quit_req(void)
{
}

quit_req::quit_req(const quit_req& from)
{
    merge_from(from);
}

quit_req::~quit_req(void)
{
}

const SpringCat::Wave::type_info& quit_req::static_type_info(void)
{
    return __quit_req_type_info__;
}

const SpringCat::Wave::type_info& quit_req::runtime_type_info(void) const
{
    return static_type_info();
}

quit_req* quit_req::new_instance(void) const
{
    return new quit_req;
}

quit_req* quit_req::clone(void) const
{
    return new quit_req(*this);
}

void quit_req::clear(void)
{
}

bool quit_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t quit_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    return total_size;
}

void quit_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const quit_req& src = dynamic_cast<const quit_req&>(from);
    copy_from(src);
}

void quit_req::copy_from(const quit_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void quit_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const quit_req& src = dynamic_cast<const quit_req&>(from);
    merge_from(src);
}

void quit_req::merge_from(const quit_req& from)
{
    if (&from == this)
    {
        return;
    }
}

bool quit_req::serialize(SpringCat::System::Stream& output) const
{
    return true;
}

bool quit_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool quit_req::serialize(std::string& output) const
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

bool quit_req::deserialize(SpringCat::System::Stream& input)
{
    return true;
}

bool quit_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool quit_req::deserialize(std::string& input)
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

quit_ans::quit_ans(void)
    : __has_bits__(),
    result_(0)
{
}

quit_ans::quit_ans(const quit_ans& from)
    : __has_bits__(),
    result_(0)
{
    merge_from(from);
}

quit_ans::~quit_ans(void)
{
}

const SpringCat::Wave::type_info& quit_ans::static_type_info(void)
{
    return __quit_ans_type_info__;
}

const SpringCat::Wave::type_info& quit_ans::runtime_type_info(void) const
{
    return static_type_info();
}

quit_ans* quit_ans::new_instance(void) const
{
    return new quit_ans;
}

quit_ans* quit_ans::clone(void) const
{
    return new quit_ans(*this);
}

void quit_ans::clear(void)
{
    // result
    result_ = 0;
}

bool quit_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t quit_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);

    return total_size;
}

void quit_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const quit_ans& src = dynamic_cast<const quit_ans&>(from);
    copy_from(src);
}

void quit_ans::copy_from(const quit_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void quit_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const quit_ans& src = dynamic_cast<const quit_ans&>(from);
    merge_from(src);
}

void quit_ans::merge_from(const quit_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
}

bool quit_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }

    return true;
}

bool quit_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool quit_ans::serialize(std::string& output) const
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

bool quit_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }

    return true;
}

bool quit_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool quit_ans::deserialize(std::string& input)
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

SpringCat::int16_t quit_ans::get_result(void) const
{
    return result_;
}

void quit_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}



}    // namespace protocol
