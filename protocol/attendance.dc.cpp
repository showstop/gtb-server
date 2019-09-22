#include "attendance.dc.h"
#include <stdexcept>


namespace protocol
{

// class name: attendance_info, type id(decimal): 202998127, type id(hex): 0xC19816F
static const SpringCat::Wave::type_info __attendance_info_type_info__(0xC19816F, "protocol.attendance_info");
// class name: attendance_list, type id(decimal): 203076868, type id(hex): 0xC1AB504
static const SpringCat::Wave::type_info __attendance_list_type_info__(0xC1AB504, "protocol.attendance_list");
// class name: attendance_list_req, type id(decimal): 84308593, type id(hex): 0x5067271
static const SpringCat::Wave::type_info __attendance_list_req_type_info__(0x5067271, "protocol.attendance_list_req");
// class name: attendance_list_ans, type id(decimal): 84299491, type id(hex): 0x5064EE3
static const SpringCat::Wave::type_info __attendance_list_ans_type_info__(0x5064EE3, "protocol.attendance_list_ans");
// class name: attendance_receive_reward_req, type id(decimal): 238214145, type id(hex): 0xE32DC01
static const SpringCat::Wave::type_info __attendance_receive_reward_req_type_info__(0xE32DC01, "protocol.attendance_receive_reward_req");
// class name: attendance_receive_reward_ans, type id(decimal): 238216339, type id(hex): 0xE32E493
static const SpringCat::Wave::type_info __attendance_receive_reward_ans_type_info__(0xE32E493, "protocol.attendance_receive_reward_ans");
// class name: attendance_monthly_reward_req, type id(decimal): 29299473, type id(hex): 0x1BF1311
static const SpringCat::Wave::type_info __attendance_monthly_reward_req_type_info__(0x1BF1311, "protocol.attendance_monthly_reward_req");
// class name: attendance_monthly_reward_ans, type id(decimal): 29306243, type id(hex): 0x1BF2D83
static const SpringCat::Wave::type_info __attendance_monthly_reward_ans_type_info__(0x1BF2D83, "protocol.attendance_monthly_reward_ans");

attendance_info::attendance_info(void)
    : __has_bits__(),
    day_seq_(0),
    reward_(new reward_info),
    receive_reward_(false),
    complete_(false)
{
}

attendance_info::attendance_info(const attendance_info& from)
    : __has_bits__(),
    day_seq_(0),
    reward_(new reward_info),
    receive_reward_(false),
    complete_(false)
{
    merge_from(from);
}

attendance_info::~attendance_info(void)
{
}

const SpringCat::Wave::type_info& attendance_info::static_type_info(void)
{
    return __attendance_info_type_info__;
}

const SpringCat::Wave::type_info& attendance_info::runtime_type_info(void) const
{
    return static_type_info();
}

attendance_info* attendance_info::new_instance(void) const
{
    return new attendance_info;
}

attendance_info* attendance_info::clone(void) const
{
    return new attendance_info(*this);
}

void attendance_info::clear(void)
{
    // day_seq
    day_seq_ = 0;
    // reward
    reward_->clear();
    // receive_reward
    receive_reward_ = false;
    // complete
    complete_ = false;
}

bool attendance_info::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t attendance_info::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // day_seq
    total_size += SpringCat::Wave::internal::size(day_seq_);
    // reward
    total_size += SpringCat::Wave::internal::size(*reward_);
    // receive_reward
    total_size += SpringCat::Wave::internal::size(receive_reward_);
    // complete
    total_size += SpringCat::Wave::internal::size(complete_);

    return total_size;
}

void attendance_info::copy_from(const SpringCat::Wave::object_base& from)
{
    const attendance_info& src = dynamic_cast<const attendance_info&>(from);
    copy_from(src);
}

void attendance_info::copy_from(const attendance_info& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void attendance_info::merge_from(const SpringCat::Wave::object_base& from)
{
    const attendance_info& src = dynamic_cast<const attendance_info&>(from);
    merge_from(src);
}

void attendance_info::merge_from(const attendance_info& from)
{
    if (&from == this)
    {
        return;
    }

    // day_seq
    set_day_seq(from.get_day_seq());
    // reward
    reward_->merge_from(*from.get_reward());
    // receive_reward
    set_receive_reward(from.get_receive_reward());
    // complete
    set_complete(from.get_complete());
}

bool attendance_info::serialize(SpringCat::System::Stream& output) const
{
    // day_seq
    if (SpringCat::Wave::internal::serialize(output, day_seq_) == false)
    {
        return false;
    }
    // reward
    if (SpringCat::Wave::internal::serialize(output, *reward_) == false)
    {
        return false;
    }
    // receive_reward
    if (SpringCat::Wave::internal::serialize(output, receive_reward_) == false)
    {
        return false;
    }
    // complete
    if (SpringCat::Wave::internal::serialize(output, complete_) == false)
    {
        return false;
    }

    return true;
}

bool attendance_info::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool attendance_info::serialize(std::string& output) const
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

bool attendance_info::deserialize(SpringCat::System::Stream& input)
{
    // day_seq
    if (SpringCat::Wave::internal::deserialize(input, day_seq_) == false)
    {
        return false;
    }
    // reward
    if (SpringCat::Wave::internal::deserialize(input, *reward_) == false)
    {
        return false;
    }
    // receive_reward
    if (SpringCat::Wave::internal::deserialize(input, receive_reward_) == false)
    {
        return false;
    }
    // complete
    if (SpringCat::Wave::internal::deserialize(input, complete_) == false)
    {
        return false;
    }

    return true;
}

bool attendance_info::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool attendance_info::deserialize(std::string& input)
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

SpringCat::int32_t attendance_info::get_day_seq(void) const
{
    return day_seq_;
}

void attendance_info::set_day_seq(SpringCat::int32_t value)
{
    day_seq_ = value;
}

const reward_info* attendance_info::get_reward(void) const
{
    return reward_.get();
}

reward_info* attendance_info::get_mutable_reward(void)
{
    return reward_.get();
}

bool attendance_info::get_receive_reward(void) const
{
    return receive_reward_;
}

void attendance_info::set_receive_reward(bool value)
{
    receive_reward_ = value;
}

bool attendance_info::get_complete(void) const
{
    return complete_;
}

void attendance_info::set_complete(bool value)
{
    complete_ = value;
}

attendance_list::attendance_list(void)
    : __has_bits__(),
    infos_()
{
}

attendance_list::attendance_list(const attendance_list& from)
    : __has_bits__(),
    infos_()
{
    merge_from(from);
}

attendance_list::~attendance_list(void)
{
    // infos
    SpringCat::uint32_t infos_size = static_cast<SpringCat::uint32_t>(infos_.size());
    for (SpringCat::uint32_t i = 0; i != infos_size; ++i)
    {
        delete infos_[i];
    }
    infos_.clear();
}

const SpringCat::Wave::type_info& attendance_list::static_type_info(void)
{
    return __attendance_list_type_info__;
}

const SpringCat::Wave::type_info& attendance_list::runtime_type_info(void) const
{
    return static_type_info();
}

attendance_list* attendance_list::new_instance(void) const
{
    return new attendance_list;
}

attendance_list* attendance_list::clone(void) const
{
    return new attendance_list(*this);
}

void attendance_list::clear(void)
{
    // infos
    SpringCat::uint32_t infos_size = static_cast<SpringCat::uint32_t>(infos_.size());
    for (SpringCat::uint32_t i = 0; i != infos_size; ++i)
    {
        delete infos_[i];
    }
    infos_.clear();
}

bool attendance_list::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t attendance_list::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // infos
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint32_t));
    SpringCat::uint32_t infos_size = static_cast<SpringCat::uint32_t>(infos_.size());
    for (SpringCat::uint32_t i = 0; i != infos_size; ++i)
    {
        total_size += SpringCat::Wave::internal::size(*infos_[i]);
    }

    return total_size;
}

void attendance_list::copy_from(const SpringCat::Wave::object_base& from)
{
    const attendance_list& src = dynamic_cast<const attendance_list&>(from);
    copy_from(src);
}

void attendance_list::copy_from(const attendance_list& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void attendance_list::merge_from(const SpringCat::Wave::object_base& from)
{
    const attendance_list& src = dynamic_cast<const attendance_list&>(from);
    merge_from(src);
}

void attendance_list::merge_from(const attendance_list& from)
{
    if (&from == this)
    {
        return;
    }

    // infos
    SpringCat::uint32_t infos_size = static_cast<SpringCat::uint32_t>(from.infos_.size());
    infos_.reserve(infos_.size() + infos_size);
    for (SpringCat::uint32_t i = 0; i != infos_size; ++i)
    {
        infos_.push_back(from.infos_[i]->clone());
    }
}

bool attendance_list::serialize(SpringCat::System::Stream& output) const
{
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

bool attendance_list::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool attendance_list::serialize(std::string& output) const
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

bool attendance_list::deserialize(SpringCat::System::Stream& input)
{
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
            std::auto_ptr<attendance_info> new_infos(new attendance_info);
            if (SpringCat::Wave::internal::deserialize(input, *new_infos) == false)
            {
                return false;
            }
            infos_.push_back(new_infos.release());
        }
    }

    return true;
}

bool attendance_list::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool attendance_list::deserialize(std::string& input)
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

const std::vector<attendance_info*>& attendance_list::get_infos(void) const
{
    return infos_;
}

std::vector<attendance_info*>* attendance_list::get_mutable_infos(void)
{
    return &infos_;
}

const attendance_info* attendance_list::get_infos(size_t index) const
{
    if (infos_.size() <= index)
    {
        throw std::out_of_range("attendance_list::infos_ index outside range");
    }

    return infos_[index];
}

attendance_info* attendance_list::get_mutable_infos(size_t index)
{
    if (infos_.size() <= index)
    {
        throw std::out_of_range("attendance_list::infos_ index outside range");
    }

    return infos_[index];
}

attendance_info* attendance_list::add_infos(void)
{
    std::auto_ptr<attendance_info> new_infos(new attendance_info);
    infos_.push_back(new_infos.get());

    return new_infos.release();
}

attendance_list_req::attendance_list_req(void)
{
}

attendance_list_req::attendance_list_req(const attendance_list_req& from)
{
    merge_from(from);
}

attendance_list_req::~attendance_list_req(void)
{
}

const SpringCat::Wave::type_info& attendance_list_req::static_type_info(void)
{
    return __attendance_list_req_type_info__;
}

const SpringCat::Wave::type_info& attendance_list_req::runtime_type_info(void) const
{
    return static_type_info();
}

attendance_list_req* attendance_list_req::new_instance(void) const
{
    return new attendance_list_req;
}

attendance_list_req* attendance_list_req::clone(void) const
{
    return new attendance_list_req(*this);
}

void attendance_list_req::clear(void)
{
}

bool attendance_list_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t attendance_list_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    return total_size;
}

void attendance_list_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const attendance_list_req& src = dynamic_cast<const attendance_list_req&>(from);
    copy_from(src);
}

void attendance_list_req::copy_from(const attendance_list_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void attendance_list_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const attendance_list_req& src = dynamic_cast<const attendance_list_req&>(from);
    merge_from(src);
}

void attendance_list_req::merge_from(const attendance_list_req& from)
{
    if (&from == this)
    {
        return;
    }
}

bool attendance_list_req::serialize(SpringCat::System::Stream& output) const
{
    return true;
}

bool attendance_list_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool attendance_list_req::serialize(std::string& output) const
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

bool attendance_list_req::deserialize(SpringCat::System::Stream& input)
{
    return true;
}

bool attendance_list_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool attendance_list_req::deserialize(std::string& input)
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

attendance_list_ans::attendance_list_ans(void)
    : __has_bits__(),
    result_(0),
    infos_(new attendance_list)
{
}

attendance_list_ans::attendance_list_ans(const attendance_list_ans& from)
    : __has_bits__(),
    result_(0),
    infos_(new attendance_list)
{
    merge_from(from);
}

attendance_list_ans::~attendance_list_ans(void)
{
}

const SpringCat::Wave::type_info& attendance_list_ans::static_type_info(void)
{
    return __attendance_list_ans_type_info__;
}

const SpringCat::Wave::type_info& attendance_list_ans::runtime_type_info(void) const
{
    return static_type_info();
}

attendance_list_ans* attendance_list_ans::new_instance(void) const
{
    return new attendance_list_ans;
}

attendance_list_ans* attendance_list_ans::clone(void) const
{
    return new attendance_list_ans(*this);
}

void attendance_list_ans::clear(void)
{
    // result
    result_ = 0;
    // infos
    infos_->clear();
}

bool attendance_list_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t attendance_list_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // infos
    total_size += SpringCat::Wave::internal::size(*infos_);

    return total_size;
}

void attendance_list_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const attendance_list_ans& src = dynamic_cast<const attendance_list_ans&>(from);
    copy_from(src);
}

void attendance_list_ans::copy_from(const attendance_list_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void attendance_list_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const attendance_list_ans& src = dynamic_cast<const attendance_list_ans&>(from);
    merge_from(src);
}

void attendance_list_ans::merge_from(const attendance_list_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // infos
    infos_->merge_from(*from.get_infos());
}

bool attendance_list_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // infos
    if (SpringCat::Wave::internal::serialize(output, *infos_) == false)
    {
        return false;
    }

    return true;
}

bool attendance_list_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool attendance_list_ans::serialize(std::string& output) const
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

bool attendance_list_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // infos
    if (SpringCat::Wave::internal::deserialize(input, *infos_) == false)
    {
        return false;
    }

    return true;
}

bool attendance_list_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool attendance_list_ans::deserialize(std::string& input)
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

SpringCat::int16_t attendance_list_ans::get_result(void) const
{
    return result_;
}

void attendance_list_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

const attendance_list* attendance_list_ans::get_infos(void) const
{
    return infos_.get();
}

attendance_list* attendance_list_ans::get_mutable_infos(void)
{
    return infos_.get();
}

attendance_receive_reward_req::attendance_receive_reward_req(void)
    : __has_bits__(),
    day_seq_(0)
{
}

attendance_receive_reward_req::attendance_receive_reward_req(const attendance_receive_reward_req& from)
    : __has_bits__(),
    day_seq_(0)
{
    merge_from(from);
}

attendance_receive_reward_req::~attendance_receive_reward_req(void)
{
}

const SpringCat::Wave::type_info& attendance_receive_reward_req::static_type_info(void)
{
    return __attendance_receive_reward_req_type_info__;
}

const SpringCat::Wave::type_info& attendance_receive_reward_req::runtime_type_info(void) const
{
    return static_type_info();
}

attendance_receive_reward_req* attendance_receive_reward_req::new_instance(void) const
{
    return new attendance_receive_reward_req;
}

attendance_receive_reward_req* attendance_receive_reward_req::clone(void) const
{
    return new attendance_receive_reward_req(*this);
}

void attendance_receive_reward_req::clear(void)
{
    // day_seq
    day_seq_ = 0;
}

bool attendance_receive_reward_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t attendance_receive_reward_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // day_seq
    total_size += SpringCat::Wave::internal::size(day_seq_);

    return total_size;
}

void attendance_receive_reward_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const attendance_receive_reward_req& src = dynamic_cast<const attendance_receive_reward_req&>(from);
    copy_from(src);
}

void attendance_receive_reward_req::copy_from(const attendance_receive_reward_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void attendance_receive_reward_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const attendance_receive_reward_req& src = dynamic_cast<const attendance_receive_reward_req&>(from);
    merge_from(src);
}

void attendance_receive_reward_req::merge_from(const attendance_receive_reward_req& from)
{
    if (&from == this)
    {
        return;
    }

    // day_seq
    set_day_seq(from.get_day_seq());
}

bool attendance_receive_reward_req::serialize(SpringCat::System::Stream& output) const
{
    // day_seq
    if (SpringCat::Wave::internal::serialize(output, day_seq_) == false)
    {
        return false;
    }

    return true;
}

bool attendance_receive_reward_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool attendance_receive_reward_req::serialize(std::string& output) const
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

bool attendance_receive_reward_req::deserialize(SpringCat::System::Stream& input)
{
    // day_seq
    if (SpringCat::Wave::internal::deserialize(input, day_seq_) == false)
    {
        return false;
    }

    return true;
}

bool attendance_receive_reward_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool attendance_receive_reward_req::deserialize(std::string& input)
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

SpringCat::int32_t attendance_receive_reward_req::get_day_seq(void) const
{
    return day_seq_;
}

void attendance_receive_reward_req::set_day_seq(SpringCat::int32_t value)
{
    day_seq_ = value;
}

attendance_receive_reward_ans::attendance_receive_reward_ans(void)
    : __has_bits__(),
    result_(0),
    reward_(new reward_info)
{
}

attendance_receive_reward_ans::attendance_receive_reward_ans(const attendance_receive_reward_ans& from)
    : __has_bits__(),
    result_(0),
    reward_(new reward_info)
{
    merge_from(from);
}

attendance_receive_reward_ans::~attendance_receive_reward_ans(void)
{
}

const SpringCat::Wave::type_info& attendance_receive_reward_ans::static_type_info(void)
{
    return __attendance_receive_reward_ans_type_info__;
}

const SpringCat::Wave::type_info& attendance_receive_reward_ans::runtime_type_info(void) const
{
    return static_type_info();
}

attendance_receive_reward_ans* attendance_receive_reward_ans::new_instance(void) const
{
    return new attendance_receive_reward_ans;
}

attendance_receive_reward_ans* attendance_receive_reward_ans::clone(void) const
{
    return new attendance_receive_reward_ans(*this);
}

void attendance_receive_reward_ans::clear(void)
{
    // result
    result_ = 0;
    // reward
    reward_->clear();
}

bool attendance_receive_reward_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t attendance_receive_reward_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // reward
    total_size += SpringCat::Wave::internal::size(*reward_);

    return total_size;
}

void attendance_receive_reward_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const attendance_receive_reward_ans& src = dynamic_cast<const attendance_receive_reward_ans&>(from);
    copy_from(src);
}

void attendance_receive_reward_ans::copy_from(const attendance_receive_reward_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void attendance_receive_reward_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const attendance_receive_reward_ans& src = dynamic_cast<const attendance_receive_reward_ans&>(from);
    merge_from(src);
}

void attendance_receive_reward_ans::merge_from(const attendance_receive_reward_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // reward
    reward_->merge_from(*from.get_reward());
}

bool attendance_receive_reward_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // reward
    if (SpringCat::Wave::internal::serialize(output, *reward_) == false)
    {
        return false;
    }

    return true;
}

bool attendance_receive_reward_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool attendance_receive_reward_ans::serialize(std::string& output) const
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

bool attendance_receive_reward_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // reward
    if (SpringCat::Wave::internal::deserialize(input, *reward_) == false)
    {
        return false;
    }

    return true;
}

bool attendance_receive_reward_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool attendance_receive_reward_ans::deserialize(std::string& input)
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

SpringCat::int16_t attendance_receive_reward_ans::get_result(void) const
{
    return result_;
}

void attendance_receive_reward_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

const reward_info* attendance_receive_reward_ans::get_reward(void) const
{
    return reward_.get();
}

reward_info* attendance_receive_reward_ans::get_mutable_reward(void)
{
    return reward_.get();
}

attendance_monthly_reward_req::attendance_monthly_reward_req(void)
{
}

attendance_monthly_reward_req::attendance_monthly_reward_req(const attendance_monthly_reward_req& from)
{
    merge_from(from);
}

attendance_monthly_reward_req::~attendance_monthly_reward_req(void)
{
}

const SpringCat::Wave::type_info& attendance_monthly_reward_req::static_type_info(void)
{
    return __attendance_monthly_reward_req_type_info__;
}

const SpringCat::Wave::type_info& attendance_monthly_reward_req::runtime_type_info(void) const
{
    return static_type_info();
}

attendance_monthly_reward_req* attendance_monthly_reward_req::new_instance(void) const
{
    return new attendance_monthly_reward_req;
}

attendance_monthly_reward_req* attendance_monthly_reward_req::clone(void) const
{
    return new attendance_monthly_reward_req(*this);
}

void attendance_monthly_reward_req::clear(void)
{
}

bool attendance_monthly_reward_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t attendance_monthly_reward_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    return total_size;
}

void attendance_monthly_reward_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const attendance_monthly_reward_req& src = dynamic_cast<const attendance_monthly_reward_req&>(from);
    copy_from(src);
}

void attendance_monthly_reward_req::copy_from(const attendance_monthly_reward_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void attendance_monthly_reward_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const attendance_monthly_reward_req& src = dynamic_cast<const attendance_monthly_reward_req&>(from);
    merge_from(src);
}

void attendance_monthly_reward_req::merge_from(const attendance_monthly_reward_req& from)
{
    if (&from == this)
    {
        return;
    }
}

bool attendance_monthly_reward_req::serialize(SpringCat::System::Stream& output) const
{
    return true;
}

bool attendance_monthly_reward_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool attendance_monthly_reward_req::serialize(std::string& output) const
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

bool attendance_monthly_reward_req::deserialize(SpringCat::System::Stream& input)
{
    return true;
}

bool attendance_monthly_reward_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool attendance_monthly_reward_req::deserialize(std::string& input)
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

attendance_monthly_reward_ans::attendance_monthly_reward_ans(void)
    : __has_bits__(),
    result_(0),
    rewards_()
{
}

attendance_monthly_reward_ans::attendance_monthly_reward_ans(const attendance_monthly_reward_ans& from)
    : __has_bits__(),
    result_(0),
    rewards_()
{
    merge_from(from);
}

attendance_monthly_reward_ans::~attendance_monthly_reward_ans(void)
{
    // rewards
    SpringCat::uint32_t rewards_size = static_cast<SpringCat::uint32_t>(rewards_.size());
    for (SpringCat::uint32_t i = 0; i != rewards_size; ++i)
    {
        delete rewards_[i];
    }
    rewards_.clear();
}

const SpringCat::Wave::type_info& attendance_monthly_reward_ans::static_type_info(void)
{
    return __attendance_monthly_reward_ans_type_info__;
}

const SpringCat::Wave::type_info& attendance_monthly_reward_ans::runtime_type_info(void) const
{
    return static_type_info();
}

attendance_monthly_reward_ans* attendance_monthly_reward_ans::new_instance(void) const
{
    return new attendance_monthly_reward_ans;
}

attendance_monthly_reward_ans* attendance_monthly_reward_ans::clone(void) const
{
    return new attendance_monthly_reward_ans(*this);
}

void attendance_monthly_reward_ans::clear(void)
{
    // result
    result_ = 0;
    // rewards
    SpringCat::uint32_t rewards_size = static_cast<SpringCat::uint32_t>(rewards_.size());
    for (SpringCat::uint32_t i = 0; i != rewards_size; ++i)
    {
        delete rewards_[i];
    }
    rewards_.clear();
}

bool attendance_monthly_reward_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t attendance_monthly_reward_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // rewards
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint32_t));
    SpringCat::uint32_t rewards_size = static_cast<SpringCat::uint32_t>(rewards_.size());
    for (SpringCat::uint32_t i = 0; i != rewards_size; ++i)
    {
        total_size += SpringCat::Wave::internal::size(*rewards_[i]);
    }

    return total_size;
}

void attendance_monthly_reward_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const attendance_monthly_reward_ans& src = dynamic_cast<const attendance_monthly_reward_ans&>(from);
    copy_from(src);
}

void attendance_monthly_reward_ans::copy_from(const attendance_monthly_reward_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void attendance_monthly_reward_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const attendance_monthly_reward_ans& src = dynamic_cast<const attendance_monthly_reward_ans&>(from);
    merge_from(src);
}

void attendance_monthly_reward_ans::merge_from(const attendance_monthly_reward_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // rewards
    SpringCat::uint32_t rewards_size = static_cast<SpringCat::uint32_t>(from.rewards_.size());
    rewards_.reserve(rewards_.size() + rewards_size);
    for (SpringCat::uint32_t i = 0; i != rewards_size; ++i)
    {
        rewards_.push_back(from.rewards_[i]->clone());
    }
}

bool attendance_monthly_reward_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // rewards
    SpringCat::uint32_t rewards_size = static_cast<SpringCat::uint32_t>(rewards_.size());
    if (SpringCat::Wave::internal::serialize(output, rewards_size) == false)
    {
        return false;
    }
    for (SpringCat::uint32_t i = 0; i != rewards_size; ++i)
    {
        if (SpringCat::Wave::internal::serialize(output, *rewards_[i]) == false)
        {
            return false;
        }
    }

    return true;
}

bool attendance_monthly_reward_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool attendance_monthly_reward_ans::serialize(std::string& output) const
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

bool attendance_monthly_reward_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // rewards
    SpringCat::uint32_t rewards_size = 0;
    if (SpringCat::Wave::internal::deserialize(input, rewards_size) == false)
    {
        return false;
    }
    if (rewards_size > 0)
    {
        rewards_.reserve(rewards_size);
        for (SpringCat::uint32_t i = 0; i != rewards_size; ++i)
        {
            std::auto_ptr<reward_info> new_rewards(new reward_info);
            if (SpringCat::Wave::internal::deserialize(input, *new_rewards) == false)
            {
                return false;
            }
            rewards_.push_back(new_rewards.release());
        }
    }

    return true;
}

bool attendance_monthly_reward_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool attendance_monthly_reward_ans::deserialize(std::string& input)
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

SpringCat::int16_t attendance_monthly_reward_ans::get_result(void) const
{
    return result_;
}

void attendance_monthly_reward_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

const std::vector<reward_info*>& attendance_monthly_reward_ans::get_rewards(void) const
{
    return rewards_;
}

std::vector<reward_info*>* attendance_monthly_reward_ans::get_mutable_rewards(void)
{
    return &rewards_;
}

const reward_info* attendance_monthly_reward_ans::get_rewards(size_t index) const
{
    if (rewards_.size() <= index)
    {
        throw std::out_of_range("attendance_monthly_reward_ans::rewards_ index outside range");
    }

    return rewards_[index];
}

reward_info* attendance_monthly_reward_ans::get_mutable_rewards(size_t index)
{
    if (rewards_.size() <= index)
    {
        throw std::out_of_range("attendance_monthly_reward_ans::rewards_ index outside range");
    }

    return rewards_[index];
}

reward_info* attendance_monthly_reward_ans::add_rewards(void)
{
    std::auto_ptr<reward_info> new_rewards(new reward_info);
    rewards_.push_back(new_rewards.get());

    return new_rewards.release();
}



}    // namespace protocol
