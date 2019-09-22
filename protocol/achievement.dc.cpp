#include "achievement.dc.h"
#include <stdexcept>


namespace protocol
{

// class name: achievement_info, type id(decimal): 149654399, type id(hex): 0x8EB8B7F
static const SpringCat::Wave::type_info __achievement_info_type_info__(0x8EB8B7F, "protocol.achievement_info");
// class name: achievement_list, type id(decimal): 149733140, type id(hex): 0x8ECBF14
static const SpringCat::Wave::type_info __achievement_list_type_info__(0x8ECBF14, "protocol.achievement_list");
// class name: achievement_list_req, type id(decimal): 252871793, type id(hex): 0xF128471
static const SpringCat::Wave::type_info __achievement_list_req_type_info__(0xF128471, "protocol.achievement_list_req");
// class name: achievement_list_ans, type id(decimal): 252886243, type id(hex): 0xF12BCE3
static const SpringCat::Wave::type_info __achievement_list_ans_type_info__(0xF12BCE3, "protocol.achievement_list_ans");
// class name: achievement_receive_reward_req, type id(decimal): 205308145, type id(hex): 0xC3CC0F1
static const SpringCat::Wave::type_info __achievement_receive_reward_req_type_info__(0xC3CC0F1, "protocol.achievement_receive_reward_req");
// class name: achievement_receive_reward_ans, type id(decimal): 205324387, type id(hex): 0xC3D0063
static const SpringCat::Wave::type_info __achievement_receive_reward_ans_type_info__(0xC3D0063, "protocol.achievement_receive_reward_ans");
// class name: achievement_accomplished_notify, type id(decimal): 205303385, type id(hex): 0xC3CAE59
static const SpringCat::Wave::type_info __achievement_accomplished_notify_type_info__(0xC3CAE59, "protocol.achievement_accomplished_notify");

achievement_info::achievement_info(void)
    : __has_bits__(),
    achievement_id_(0),
    record_key_(0),
    progress_(0),
    goal_(0),
    receive_reward_(false),
    reward_(new reward_info)
{
}

achievement_info::achievement_info(const achievement_info& from)
    : __has_bits__(),
    achievement_id_(0),
    record_key_(0),
    progress_(0),
    goal_(0),
    receive_reward_(false),
    reward_(new reward_info)
{
    merge_from(from);
}

achievement_info::~achievement_info(void)
{
}

const SpringCat::Wave::type_info& achievement_info::static_type_info(void)
{
    return __achievement_info_type_info__;
}

const SpringCat::Wave::type_info& achievement_info::runtime_type_info(void) const
{
    return static_type_info();
}

achievement_info* achievement_info::new_instance(void) const
{
    return new achievement_info;
}

achievement_info* achievement_info::clone(void) const
{
    return new achievement_info(*this);
}

void achievement_info::clear(void)
{
    // achievement_id
    achievement_id_ = 0;
    // record_key
    record_key_ = 0;
    // progress
    progress_ = 0;
    // goal
    goal_ = 0;
    // receive_reward
    receive_reward_ = false;
    // reward
    reward_->clear();
}

bool achievement_info::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t achievement_info::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // achievement_id
    total_size += SpringCat::Wave::internal::size(achievement_id_);
    // record_key
    total_size += SpringCat::Wave::internal::size(record_key_);
    // progress
    total_size += SpringCat::Wave::internal::size(progress_);
    // goal
    total_size += SpringCat::Wave::internal::size(goal_);
    // receive_reward
    total_size += SpringCat::Wave::internal::size(receive_reward_);
    // reward
    total_size += SpringCat::Wave::internal::size(*reward_);

    return total_size;
}

void achievement_info::copy_from(const SpringCat::Wave::object_base& from)
{
    const achievement_info& src = dynamic_cast<const achievement_info&>(from);
    copy_from(src);
}

void achievement_info::copy_from(const achievement_info& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void achievement_info::merge_from(const SpringCat::Wave::object_base& from)
{
    const achievement_info& src = dynamic_cast<const achievement_info&>(from);
    merge_from(src);
}

void achievement_info::merge_from(const achievement_info& from)
{
    if (&from == this)
    {
        return;
    }

    // achievement_id
    set_achievement_id(from.get_achievement_id());
    // record_key
    set_record_key(from.get_record_key());
    // progress
    set_progress(from.get_progress());
    // goal
    set_goal(from.get_goal());
    // receive_reward
    set_receive_reward(from.get_receive_reward());
    // reward
    reward_->merge_from(*from.get_reward());
}

bool achievement_info::serialize(SpringCat::System::Stream& output) const
{
    // achievement_id
    if (SpringCat::Wave::internal::serialize(output, achievement_id_) == false)
    {
        return false;
    }
    // record_key
    if (SpringCat::Wave::internal::serialize(output, record_key_) == false)
    {
        return false;
    }
    // progress
    if (SpringCat::Wave::internal::serialize(output, progress_) == false)
    {
        return false;
    }
    // goal
    if (SpringCat::Wave::internal::serialize(output, goal_) == false)
    {
        return false;
    }
    // receive_reward
    if (SpringCat::Wave::internal::serialize(output, receive_reward_) == false)
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

bool achievement_info::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool achievement_info::serialize(std::string& output) const
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

bool achievement_info::deserialize(SpringCat::System::Stream& input)
{
    // achievement_id
    if (SpringCat::Wave::internal::deserialize(input, achievement_id_) == false)
    {
        return false;
    }
    // record_key
    if (SpringCat::Wave::internal::deserialize(input, record_key_) == false)
    {
        return false;
    }
    // progress
    if (SpringCat::Wave::internal::deserialize(input, progress_) == false)
    {
        return false;
    }
    // goal
    if (SpringCat::Wave::internal::deserialize(input, goal_) == false)
    {
        return false;
    }
    // receive_reward
    if (SpringCat::Wave::internal::deserialize(input, receive_reward_) == false)
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

bool achievement_info::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool achievement_info::deserialize(std::string& input)
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

SpringCat::int32_t achievement_info::get_achievement_id(void) const
{
    return achievement_id_;
}

void achievement_info::set_achievement_id(SpringCat::int32_t value)
{
    achievement_id_ = value;
}

record_data_key achievement_info::get_record_key(void) const
{
    return static_cast<record_data_key>(record_key_);
}

void achievement_info::set_record_key(record_data_key value)
{
    record_key_ = value;
}

SpringCat::int32_t achievement_info::get_progress(void) const
{
    return progress_;
}

void achievement_info::set_progress(SpringCat::int32_t value)
{
    progress_ = value;
}

SpringCat::int32_t achievement_info::get_goal(void) const
{
    return goal_;
}

void achievement_info::set_goal(SpringCat::int32_t value)
{
    goal_ = value;
}

bool achievement_info::get_receive_reward(void) const
{
    return receive_reward_;
}

void achievement_info::set_receive_reward(bool value)
{
    receive_reward_ = value;
}

const reward_info* achievement_info::get_reward(void) const
{
    return reward_.get();
}

reward_info* achievement_info::get_mutable_reward(void)
{
    return reward_.get();
}

achievement_list::achievement_list(void)
    : __has_bits__(),
    infos_()
{
}

achievement_list::achievement_list(const achievement_list& from)
    : __has_bits__(),
    infos_()
{
    merge_from(from);
}

achievement_list::~achievement_list(void)
{
    // infos
    SpringCat::uint32_t infos_size = static_cast<SpringCat::uint32_t>(infos_.size());
    for (SpringCat::uint32_t i = 0; i != infos_size; ++i)
    {
        delete infos_[i];
    }
    infos_.clear();
}

const SpringCat::Wave::type_info& achievement_list::static_type_info(void)
{
    return __achievement_list_type_info__;
}

const SpringCat::Wave::type_info& achievement_list::runtime_type_info(void) const
{
    return static_type_info();
}

achievement_list* achievement_list::new_instance(void) const
{
    return new achievement_list;
}

achievement_list* achievement_list::clone(void) const
{
    return new achievement_list(*this);
}

void achievement_list::clear(void)
{
    // infos
    SpringCat::uint32_t infos_size = static_cast<SpringCat::uint32_t>(infos_.size());
    for (SpringCat::uint32_t i = 0; i != infos_size; ++i)
    {
        delete infos_[i];
    }
    infos_.clear();
}

bool achievement_list::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t achievement_list::size(void) const
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

void achievement_list::copy_from(const SpringCat::Wave::object_base& from)
{
    const achievement_list& src = dynamic_cast<const achievement_list&>(from);
    copy_from(src);
}

void achievement_list::copy_from(const achievement_list& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void achievement_list::merge_from(const SpringCat::Wave::object_base& from)
{
    const achievement_list& src = dynamic_cast<const achievement_list&>(from);
    merge_from(src);
}

void achievement_list::merge_from(const achievement_list& from)
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

bool achievement_list::serialize(SpringCat::System::Stream& output) const
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

bool achievement_list::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool achievement_list::serialize(std::string& output) const
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

bool achievement_list::deserialize(SpringCat::System::Stream& input)
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
            std::auto_ptr<achievement_info> new_infos(new achievement_info);
            if (SpringCat::Wave::internal::deserialize(input, *new_infos) == false)
            {
                return false;
            }
            infos_.push_back(new_infos.release());
        }
    }

    return true;
}

bool achievement_list::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool achievement_list::deserialize(std::string& input)
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

const std::vector<achievement_info*>& achievement_list::get_infos(void) const
{
    return infos_;
}

std::vector<achievement_info*>* achievement_list::get_mutable_infos(void)
{
    return &infos_;
}

const achievement_info* achievement_list::get_infos(size_t index) const
{
    if (infos_.size() <= index)
    {
        throw std::out_of_range("achievement_list::infos_ index outside range");
    }

    return infos_[index];
}

achievement_info* achievement_list::get_mutable_infos(size_t index)
{
    if (infos_.size() <= index)
    {
        throw std::out_of_range("achievement_list::infos_ index outside range");
    }

    return infos_[index];
}

achievement_info* achievement_list::add_infos(void)
{
    std::auto_ptr<achievement_info> new_infos(new achievement_info);
    infos_.push_back(new_infos.get());

    return new_infos.release();
}

achievement_list_req::achievement_list_req(void)
{
}

achievement_list_req::achievement_list_req(const achievement_list_req& from)
{
    merge_from(from);
}

achievement_list_req::~achievement_list_req(void)
{
}

const SpringCat::Wave::type_info& achievement_list_req::static_type_info(void)
{
    return __achievement_list_req_type_info__;
}

const SpringCat::Wave::type_info& achievement_list_req::runtime_type_info(void) const
{
    return static_type_info();
}

achievement_list_req* achievement_list_req::new_instance(void) const
{
    return new achievement_list_req;
}

achievement_list_req* achievement_list_req::clone(void) const
{
    return new achievement_list_req(*this);
}

void achievement_list_req::clear(void)
{
}

bool achievement_list_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t achievement_list_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    return total_size;
}

void achievement_list_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const achievement_list_req& src = dynamic_cast<const achievement_list_req&>(from);
    copy_from(src);
}

void achievement_list_req::copy_from(const achievement_list_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void achievement_list_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const achievement_list_req& src = dynamic_cast<const achievement_list_req&>(from);
    merge_from(src);
}

void achievement_list_req::merge_from(const achievement_list_req& from)
{
    if (&from == this)
    {
        return;
    }
}

bool achievement_list_req::serialize(SpringCat::System::Stream& output) const
{
    return true;
}

bool achievement_list_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool achievement_list_req::serialize(std::string& output) const
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

bool achievement_list_req::deserialize(SpringCat::System::Stream& input)
{
    return true;
}

bool achievement_list_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool achievement_list_req::deserialize(std::string& input)
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

achievement_list_ans::achievement_list_ans(void)
    : __has_bits__(),
    result_(0),
    infos_(new achievement_list)
{
}

achievement_list_ans::achievement_list_ans(const achievement_list_ans& from)
    : __has_bits__(),
    result_(0),
    infos_(new achievement_list)
{
    merge_from(from);
}

achievement_list_ans::~achievement_list_ans(void)
{
}

const SpringCat::Wave::type_info& achievement_list_ans::static_type_info(void)
{
    return __achievement_list_ans_type_info__;
}

const SpringCat::Wave::type_info& achievement_list_ans::runtime_type_info(void) const
{
    return static_type_info();
}

achievement_list_ans* achievement_list_ans::new_instance(void) const
{
    return new achievement_list_ans;
}

achievement_list_ans* achievement_list_ans::clone(void) const
{
    return new achievement_list_ans(*this);
}

void achievement_list_ans::clear(void)
{
    // result
    result_ = 0;
    // infos
    infos_->clear();
}

bool achievement_list_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t achievement_list_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // infos
    total_size += SpringCat::Wave::internal::size(*infos_);

    return total_size;
}

void achievement_list_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const achievement_list_ans& src = dynamic_cast<const achievement_list_ans&>(from);
    copy_from(src);
}

void achievement_list_ans::copy_from(const achievement_list_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void achievement_list_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const achievement_list_ans& src = dynamic_cast<const achievement_list_ans&>(from);
    merge_from(src);
}

void achievement_list_ans::merge_from(const achievement_list_ans& from)
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

bool achievement_list_ans::serialize(SpringCat::System::Stream& output) const
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

bool achievement_list_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool achievement_list_ans::serialize(std::string& output) const
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

bool achievement_list_ans::deserialize(SpringCat::System::Stream& input)
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

bool achievement_list_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool achievement_list_ans::deserialize(std::string& input)
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

SpringCat::int16_t achievement_list_ans::get_result(void) const
{
    return result_;
}

void achievement_list_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

const achievement_list* achievement_list_ans::get_infos(void) const
{
    return infos_.get();
}

achievement_list* achievement_list_ans::get_mutable_infos(void)
{
    return infos_.get();
}

achievement_receive_reward_req::achievement_receive_reward_req(void)
    : __has_bits__(),
    achievement_id_(0)
{
}

achievement_receive_reward_req::achievement_receive_reward_req(const achievement_receive_reward_req& from)
    : __has_bits__(),
    achievement_id_(0)
{
    merge_from(from);
}

achievement_receive_reward_req::~achievement_receive_reward_req(void)
{
}

const SpringCat::Wave::type_info& achievement_receive_reward_req::static_type_info(void)
{
    return __achievement_receive_reward_req_type_info__;
}

const SpringCat::Wave::type_info& achievement_receive_reward_req::runtime_type_info(void) const
{
    return static_type_info();
}

achievement_receive_reward_req* achievement_receive_reward_req::new_instance(void) const
{
    return new achievement_receive_reward_req;
}

achievement_receive_reward_req* achievement_receive_reward_req::clone(void) const
{
    return new achievement_receive_reward_req(*this);
}

void achievement_receive_reward_req::clear(void)
{
    // achievement_id
    achievement_id_ = 0;
}

bool achievement_receive_reward_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t achievement_receive_reward_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // achievement_id
    total_size += SpringCat::Wave::internal::size(achievement_id_);

    return total_size;
}

void achievement_receive_reward_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const achievement_receive_reward_req& src = dynamic_cast<const achievement_receive_reward_req&>(from);
    copy_from(src);
}

void achievement_receive_reward_req::copy_from(const achievement_receive_reward_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void achievement_receive_reward_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const achievement_receive_reward_req& src = dynamic_cast<const achievement_receive_reward_req&>(from);
    merge_from(src);
}

void achievement_receive_reward_req::merge_from(const achievement_receive_reward_req& from)
{
    if (&from == this)
    {
        return;
    }

    // achievement_id
    set_achievement_id(from.get_achievement_id());
}

bool achievement_receive_reward_req::serialize(SpringCat::System::Stream& output) const
{
    // achievement_id
    if (SpringCat::Wave::internal::serialize(output, achievement_id_) == false)
    {
        return false;
    }

    return true;
}

bool achievement_receive_reward_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool achievement_receive_reward_req::serialize(std::string& output) const
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

bool achievement_receive_reward_req::deserialize(SpringCat::System::Stream& input)
{
    // achievement_id
    if (SpringCat::Wave::internal::deserialize(input, achievement_id_) == false)
    {
        return false;
    }

    return true;
}

bool achievement_receive_reward_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool achievement_receive_reward_req::deserialize(std::string& input)
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

SpringCat::int32_t achievement_receive_reward_req::get_achievement_id(void) const
{
    return achievement_id_;
}

void achievement_receive_reward_req::set_achievement_id(SpringCat::int32_t value)
{
    achievement_id_ = value;
}

achievement_receive_reward_ans::achievement_receive_reward_ans(void)
    : __has_bits__(),
    result_(0),
    reward_(new reward_info),
    updated_info_(new achievement_info)
{
}

achievement_receive_reward_ans::achievement_receive_reward_ans(const achievement_receive_reward_ans& from)
    : __has_bits__(),
    result_(0),
    reward_(new reward_info),
    updated_info_(new achievement_info)
{
    merge_from(from);
}

achievement_receive_reward_ans::~achievement_receive_reward_ans(void)
{
}

const SpringCat::Wave::type_info& achievement_receive_reward_ans::static_type_info(void)
{
    return __achievement_receive_reward_ans_type_info__;
}

const SpringCat::Wave::type_info& achievement_receive_reward_ans::runtime_type_info(void) const
{
    return static_type_info();
}

achievement_receive_reward_ans* achievement_receive_reward_ans::new_instance(void) const
{
    return new achievement_receive_reward_ans;
}

achievement_receive_reward_ans* achievement_receive_reward_ans::clone(void) const
{
    return new achievement_receive_reward_ans(*this);
}

void achievement_receive_reward_ans::clear(void)
{
    // result
    result_ = 0;
    // reward
    reward_->clear();
    // updated_info
    updated_info_->clear();
}

bool achievement_receive_reward_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t achievement_receive_reward_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // reward
    total_size += SpringCat::Wave::internal::size(*reward_);
    // updated_info
    total_size += SpringCat::Wave::internal::size(*updated_info_);

    return total_size;
}

void achievement_receive_reward_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const achievement_receive_reward_ans& src = dynamic_cast<const achievement_receive_reward_ans&>(from);
    copy_from(src);
}

void achievement_receive_reward_ans::copy_from(const achievement_receive_reward_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void achievement_receive_reward_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const achievement_receive_reward_ans& src = dynamic_cast<const achievement_receive_reward_ans&>(from);
    merge_from(src);
}

void achievement_receive_reward_ans::merge_from(const achievement_receive_reward_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // reward
    reward_->merge_from(*from.get_reward());
    // updated_info
    updated_info_->merge_from(*from.get_updated_info());
}

bool achievement_receive_reward_ans::serialize(SpringCat::System::Stream& output) const
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
    // updated_info
    if (SpringCat::Wave::internal::serialize(output, *updated_info_) == false)
    {
        return false;
    }

    return true;
}

bool achievement_receive_reward_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool achievement_receive_reward_ans::serialize(std::string& output) const
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

bool achievement_receive_reward_ans::deserialize(SpringCat::System::Stream& input)
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
    // updated_info
    if (SpringCat::Wave::internal::deserialize(input, *updated_info_) == false)
    {
        return false;
    }

    return true;
}

bool achievement_receive_reward_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool achievement_receive_reward_ans::deserialize(std::string& input)
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

SpringCat::int16_t achievement_receive_reward_ans::get_result(void) const
{
    return result_;
}

void achievement_receive_reward_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

const reward_info* achievement_receive_reward_ans::get_reward(void) const
{
    return reward_.get();
}

reward_info* achievement_receive_reward_ans::get_mutable_reward(void)
{
    return reward_.get();
}

const achievement_info* achievement_receive_reward_ans::get_updated_info(void) const
{
    return updated_info_.get();
}

achievement_info* achievement_receive_reward_ans::get_mutable_updated_info(void)
{
    return updated_info_.get();
}

achievement_accomplished_notify::achievement_accomplished_notify(void)
    : __has_bits__(),
    achievement_id_(0)
{
}

achievement_accomplished_notify::achievement_accomplished_notify(const achievement_accomplished_notify& from)
    : __has_bits__(),
    achievement_id_(0)
{
    merge_from(from);
}

achievement_accomplished_notify::~achievement_accomplished_notify(void)
{
}

const SpringCat::Wave::type_info& achievement_accomplished_notify::static_type_info(void)
{
    return __achievement_accomplished_notify_type_info__;
}

const SpringCat::Wave::type_info& achievement_accomplished_notify::runtime_type_info(void) const
{
    return static_type_info();
}

achievement_accomplished_notify* achievement_accomplished_notify::new_instance(void) const
{
    return new achievement_accomplished_notify;
}

achievement_accomplished_notify* achievement_accomplished_notify::clone(void) const
{
    return new achievement_accomplished_notify(*this);
}

void achievement_accomplished_notify::clear(void)
{
    // achievement_id
    achievement_id_ = 0;
}

bool achievement_accomplished_notify::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t achievement_accomplished_notify::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // achievement_id
    total_size += SpringCat::Wave::internal::size(achievement_id_);

    return total_size;
}

void achievement_accomplished_notify::copy_from(const SpringCat::Wave::object_base& from)
{
    const achievement_accomplished_notify& src = dynamic_cast<const achievement_accomplished_notify&>(from);
    copy_from(src);
}

void achievement_accomplished_notify::copy_from(const achievement_accomplished_notify& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void achievement_accomplished_notify::merge_from(const SpringCat::Wave::object_base& from)
{
    const achievement_accomplished_notify& src = dynamic_cast<const achievement_accomplished_notify&>(from);
    merge_from(src);
}

void achievement_accomplished_notify::merge_from(const achievement_accomplished_notify& from)
{
    if (&from == this)
    {
        return;
    }

    // achievement_id
    set_achievement_id(from.get_achievement_id());
}

bool achievement_accomplished_notify::serialize(SpringCat::System::Stream& output) const
{
    // achievement_id
    if (SpringCat::Wave::internal::serialize(output, achievement_id_) == false)
    {
        return false;
    }

    return true;
}

bool achievement_accomplished_notify::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool achievement_accomplished_notify::serialize(std::string& output) const
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

bool achievement_accomplished_notify::deserialize(SpringCat::System::Stream& input)
{
    // achievement_id
    if (SpringCat::Wave::internal::deserialize(input, achievement_id_) == false)
    {
        return false;
    }

    return true;
}

bool achievement_accomplished_notify::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool achievement_accomplished_notify::deserialize(std::string& input)
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

SpringCat::int32_t achievement_accomplished_notify::get_achievement_id(void) const
{
    return achievement_id_;
}

void achievement_accomplished_notify::set_achievement_id(SpringCat::int32_t value)
{
    achievement_id_ = value;
}



}    // namespace protocol
