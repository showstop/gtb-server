#include "daily_mission.dc.h"
#include <stdexcept>


namespace protocol
{

// class name: daily_mission_info, type id(decimal): 236411999, type id(hex): 0xE175C5F
static const SpringCat::Wave::type_info __daily_mission_info_type_info__(0xE175C5F, "protocol.daily_mission_info");
// class name: daily_mission_list, type id(decimal): 236496948, type id(hex): 0xE18A834
static const SpringCat::Wave::type_info __daily_mission_list_type_info__(0xE18A834, "protocol.daily_mission_list");
// class name: daily_mission_list_req, type id(decimal): 137916513, type id(hex): 0x8387061
static const SpringCat::Wave::type_info __daily_mission_list_req_type_info__(0x8387061, "protocol.daily_mission_list_req");
// class name: daily_mission_list_ans, type id(decimal): 137908467, type id(hex): 0x83850F3
static const SpringCat::Wave::type_info __daily_mission_list_ans_type_info__(0x83850F3, "protocol.daily_mission_list_ans");
// class name: daily_mission_receive_reward_req, type id(decimal): 3006977, type id(hex): 0x2DE201
static const SpringCat::Wave::type_info __daily_mission_receive_reward_req_type_info__(0x2DE201, "protocol.daily_mission_receive_reward_req");
// class name: daily_mission_receive_reward_ans, type id(decimal): 3006099, type id(hex): 0x2DDE93
static const SpringCat::Wave::type_info __daily_mission_receive_reward_ans_type_info__(0x2DDE93, "protocol.daily_mission_receive_reward_ans");
// class name: daily_mission_accomplished_notify, type id(decimal): 191791385, type id(hex): 0xB6E8119
static const SpringCat::Wave::type_info __daily_mission_accomplished_notify_type_info__(0xB6E8119, "protocol.daily_mission_accomplished_notify");

daily_mission_info::daily_mission_info(void)
    : __has_bits__(),
    mission_id_(0),
    data_key_(0),
    progress_(0),
    goal_(0),
    receive_reward_(false),
    reward_(new reward_info)
{
}

daily_mission_info::daily_mission_info(const daily_mission_info& from)
    : __has_bits__(),
    mission_id_(0),
    data_key_(0),
    progress_(0),
    goal_(0),
    receive_reward_(false),
    reward_(new reward_info)
{
    merge_from(from);
}

daily_mission_info::~daily_mission_info(void)
{
}

const SpringCat::Wave::type_info& daily_mission_info::static_type_info(void)
{
    return __daily_mission_info_type_info__;
}

const SpringCat::Wave::type_info& daily_mission_info::runtime_type_info(void) const
{
    return static_type_info();
}

daily_mission_info* daily_mission_info::new_instance(void) const
{
    return new daily_mission_info;
}

daily_mission_info* daily_mission_info::clone(void) const
{
    return new daily_mission_info(*this);
}

void daily_mission_info::clear(void)
{
    // mission_id
    mission_id_ = 0;
    // data_key
    data_key_ = 0;
    // progress
    progress_ = 0;
    // goal
    goal_ = 0;
    // receive_reward
    receive_reward_ = false;
    // reward
    reward_->clear();
}

bool daily_mission_info::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t daily_mission_info::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // mission_id
    total_size += SpringCat::Wave::internal::size(mission_id_);
    // data_key
    total_size += SpringCat::Wave::internal::size(data_key_);
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

void daily_mission_info::copy_from(const SpringCat::Wave::object_base& from)
{
    const daily_mission_info& src = dynamic_cast<const daily_mission_info&>(from);
    copy_from(src);
}

void daily_mission_info::copy_from(const daily_mission_info& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void daily_mission_info::merge_from(const SpringCat::Wave::object_base& from)
{
    const daily_mission_info& src = dynamic_cast<const daily_mission_info&>(from);
    merge_from(src);
}

void daily_mission_info::merge_from(const daily_mission_info& from)
{
    if (&from == this)
    {
        return;
    }

    // mission_id
    set_mission_id(from.get_mission_id());
    // data_key
    set_data_key(from.get_data_key());
    // progress
    set_progress(from.get_progress());
    // goal
    set_goal(from.get_goal());
    // receive_reward
    set_receive_reward(from.get_receive_reward());
    // reward
    reward_->merge_from(*from.get_reward());
}

bool daily_mission_info::serialize(SpringCat::System::Stream& output) const
{
    // mission_id
    if (SpringCat::Wave::internal::serialize(output, mission_id_) == false)
    {
        return false;
    }
    // data_key
    if (SpringCat::Wave::internal::serialize(output, data_key_) == false)
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

bool daily_mission_info::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool daily_mission_info::serialize(std::string& output) const
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

bool daily_mission_info::deserialize(SpringCat::System::Stream& input)
{
    // mission_id
    if (SpringCat::Wave::internal::deserialize(input, mission_id_) == false)
    {
        return false;
    }
    // data_key
    if (SpringCat::Wave::internal::deserialize(input, data_key_) == false)
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

bool daily_mission_info::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool daily_mission_info::deserialize(std::string& input)
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

SpringCat::int32_t daily_mission_info::get_mission_id(void) const
{
    return mission_id_;
}

void daily_mission_info::set_mission_id(SpringCat::int32_t value)
{
    mission_id_ = value;
}

mission_data_key daily_mission_info::get_data_key(void) const
{
    return static_cast<mission_data_key>(data_key_);
}

void daily_mission_info::set_data_key(mission_data_key value)
{
    data_key_ = value;
}

SpringCat::int16_t daily_mission_info::get_progress(void) const
{
    return progress_;
}

void daily_mission_info::set_progress(SpringCat::int16_t value)
{
    progress_ = value;
}

SpringCat::int16_t daily_mission_info::get_goal(void) const
{
    return goal_;
}

void daily_mission_info::set_goal(SpringCat::int16_t value)
{
    goal_ = value;
}

bool daily_mission_info::get_receive_reward(void) const
{
    return receive_reward_;
}

void daily_mission_info::set_receive_reward(bool value)
{
    receive_reward_ = value;
}

const reward_info* daily_mission_info::get_reward(void) const
{
    return reward_.get();
}

reward_info* daily_mission_info::get_mutable_reward(void)
{
    return reward_.get();
}

daily_mission_list::daily_mission_list(void)
    : __has_bits__(),
    infos_()
{
}

daily_mission_list::daily_mission_list(const daily_mission_list& from)
    : __has_bits__(),
    infos_()
{
    merge_from(from);
}

daily_mission_list::~daily_mission_list(void)
{
    // infos
    SpringCat::uint32_t infos_size = static_cast<SpringCat::uint32_t>(infos_.size());
    for (SpringCat::uint32_t i = 0; i != infos_size; ++i)
    {
        delete infos_[i];
    }
    infos_.clear();
}

const SpringCat::Wave::type_info& daily_mission_list::static_type_info(void)
{
    return __daily_mission_list_type_info__;
}

const SpringCat::Wave::type_info& daily_mission_list::runtime_type_info(void) const
{
    return static_type_info();
}

daily_mission_list* daily_mission_list::new_instance(void) const
{
    return new daily_mission_list;
}

daily_mission_list* daily_mission_list::clone(void) const
{
    return new daily_mission_list(*this);
}

void daily_mission_list::clear(void)
{
    // infos
    SpringCat::uint32_t infos_size = static_cast<SpringCat::uint32_t>(infos_.size());
    for (SpringCat::uint32_t i = 0; i != infos_size; ++i)
    {
        delete infos_[i];
    }
    infos_.clear();
}

bool daily_mission_list::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t daily_mission_list::size(void) const
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

void daily_mission_list::copy_from(const SpringCat::Wave::object_base& from)
{
    const daily_mission_list& src = dynamic_cast<const daily_mission_list&>(from);
    copy_from(src);
}

void daily_mission_list::copy_from(const daily_mission_list& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void daily_mission_list::merge_from(const SpringCat::Wave::object_base& from)
{
    const daily_mission_list& src = dynamic_cast<const daily_mission_list&>(from);
    merge_from(src);
}

void daily_mission_list::merge_from(const daily_mission_list& from)
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

bool daily_mission_list::serialize(SpringCat::System::Stream& output) const
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

bool daily_mission_list::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool daily_mission_list::serialize(std::string& output) const
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

bool daily_mission_list::deserialize(SpringCat::System::Stream& input)
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
            std::auto_ptr<daily_mission_info> new_infos(new daily_mission_info);
            if (SpringCat::Wave::internal::deserialize(input, *new_infos) == false)
            {
                return false;
            }
            infos_.push_back(new_infos.release());
        }
    }

    return true;
}

bool daily_mission_list::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool daily_mission_list::deserialize(std::string& input)
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

const std::vector<daily_mission_info*>& daily_mission_list::get_infos(void) const
{
    return infos_;
}

std::vector<daily_mission_info*>* daily_mission_list::get_mutable_infos(void)
{
    return &infos_;
}

const daily_mission_info* daily_mission_list::get_infos(size_t index) const
{
    if (infos_.size() <= index)
    {
        throw std::out_of_range("daily_mission_list::infos_ index outside range");
    }

    return infos_[index];
}

daily_mission_info* daily_mission_list::get_mutable_infos(size_t index)
{
    if (infos_.size() <= index)
    {
        throw std::out_of_range("daily_mission_list::infos_ index outside range");
    }

    return infos_[index];
}

daily_mission_info* daily_mission_list::add_infos(void)
{
    std::auto_ptr<daily_mission_info> new_infos(new daily_mission_info);
    infos_.push_back(new_infos.get());

    return new_infos.release();
}

daily_mission_list_req::daily_mission_list_req(void)
{
}

daily_mission_list_req::daily_mission_list_req(const daily_mission_list_req& from)
{
    merge_from(from);
}

daily_mission_list_req::~daily_mission_list_req(void)
{
}

const SpringCat::Wave::type_info& daily_mission_list_req::static_type_info(void)
{
    return __daily_mission_list_req_type_info__;
}

const SpringCat::Wave::type_info& daily_mission_list_req::runtime_type_info(void) const
{
    return static_type_info();
}

daily_mission_list_req* daily_mission_list_req::new_instance(void) const
{
    return new daily_mission_list_req;
}

daily_mission_list_req* daily_mission_list_req::clone(void) const
{
    return new daily_mission_list_req(*this);
}

void daily_mission_list_req::clear(void)
{
}

bool daily_mission_list_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t daily_mission_list_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    return total_size;
}

void daily_mission_list_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const daily_mission_list_req& src = dynamic_cast<const daily_mission_list_req&>(from);
    copy_from(src);
}

void daily_mission_list_req::copy_from(const daily_mission_list_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void daily_mission_list_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const daily_mission_list_req& src = dynamic_cast<const daily_mission_list_req&>(from);
    merge_from(src);
}

void daily_mission_list_req::merge_from(const daily_mission_list_req& from)
{
    if (&from == this)
    {
        return;
    }
}

bool daily_mission_list_req::serialize(SpringCat::System::Stream& output) const
{
    return true;
}

bool daily_mission_list_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool daily_mission_list_req::serialize(std::string& output) const
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

bool daily_mission_list_req::deserialize(SpringCat::System::Stream& input)
{
    return true;
}

bool daily_mission_list_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool daily_mission_list_req::deserialize(std::string& input)
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

daily_mission_list_ans::daily_mission_list_ans(void)
    : __has_bits__(),
    result_(0),
    infos_(new daily_mission_list)
{
}

daily_mission_list_ans::daily_mission_list_ans(const daily_mission_list_ans& from)
    : __has_bits__(),
    result_(0),
    infos_(new daily_mission_list)
{
    merge_from(from);
}

daily_mission_list_ans::~daily_mission_list_ans(void)
{
}

const SpringCat::Wave::type_info& daily_mission_list_ans::static_type_info(void)
{
    return __daily_mission_list_ans_type_info__;
}

const SpringCat::Wave::type_info& daily_mission_list_ans::runtime_type_info(void) const
{
    return static_type_info();
}

daily_mission_list_ans* daily_mission_list_ans::new_instance(void) const
{
    return new daily_mission_list_ans;
}

daily_mission_list_ans* daily_mission_list_ans::clone(void) const
{
    return new daily_mission_list_ans(*this);
}

void daily_mission_list_ans::clear(void)
{
    // result
    result_ = 0;
    // infos
    infos_->clear();
}

bool daily_mission_list_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t daily_mission_list_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // infos
    total_size += SpringCat::Wave::internal::size(*infos_);

    return total_size;
}

void daily_mission_list_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const daily_mission_list_ans& src = dynamic_cast<const daily_mission_list_ans&>(from);
    copy_from(src);
}

void daily_mission_list_ans::copy_from(const daily_mission_list_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void daily_mission_list_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const daily_mission_list_ans& src = dynamic_cast<const daily_mission_list_ans&>(from);
    merge_from(src);
}

void daily_mission_list_ans::merge_from(const daily_mission_list_ans& from)
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

bool daily_mission_list_ans::serialize(SpringCat::System::Stream& output) const
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

bool daily_mission_list_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool daily_mission_list_ans::serialize(std::string& output) const
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

bool daily_mission_list_ans::deserialize(SpringCat::System::Stream& input)
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

bool daily_mission_list_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool daily_mission_list_ans::deserialize(std::string& input)
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

SpringCat::int16_t daily_mission_list_ans::get_result(void) const
{
    return result_;
}

void daily_mission_list_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

const daily_mission_list* daily_mission_list_ans::get_infos(void) const
{
    return infos_.get();
}

daily_mission_list* daily_mission_list_ans::get_mutable_infos(void)
{
    return infos_.get();
}

daily_mission_receive_reward_req::daily_mission_receive_reward_req(void)
    : __has_bits__(),
    mission_id_(0)
{
}

daily_mission_receive_reward_req::daily_mission_receive_reward_req(const daily_mission_receive_reward_req& from)
    : __has_bits__(),
    mission_id_(0)
{
    merge_from(from);
}

daily_mission_receive_reward_req::~daily_mission_receive_reward_req(void)
{
}

const SpringCat::Wave::type_info& daily_mission_receive_reward_req::static_type_info(void)
{
    return __daily_mission_receive_reward_req_type_info__;
}

const SpringCat::Wave::type_info& daily_mission_receive_reward_req::runtime_type_info(void) const
{
    return static_type_info();
}

daily_mission_receive_reward_req* daily_mission_receive_reward_req::new_instance(void) const
{
    return new daily_mission_receive_reward_req;
}

daily_mission_receive_reward_req* daily_mission_receive_reward_req::clone(void) const
{
    return new daily_mission_receive_reward_req(*this);
}

void daily_mission_receive_reward_req::clear(void)
{
    // mission_id
    mission_id_ = 0;
}

bool daily_mission_receive_reward_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t daily_mission_receive_reward_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // mission_id
    total_size += SpringCat::Wave::internal::size(mission_id_);

    return total_size;
}

void daily_mission_receive_reward_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const daily_mission_receive_reward_req& src = dynamic_cast<const daily_mission_receive_reward_req&>(from);
    copy_from(src);
}

void daily_mission_receive_reward_req::copy_from(const daily_mission_receive_reward_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void daily_mission_receive_reward_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const daily_mission_receive_reward_req& src = dynamic_cast<const daily_mission_receive_reward_req&>(from);
    merge_from(src);
}

void daily_mission_receive_reward_req::merge_from(const daily_mission_receive_reward_req& from)
{
    if (&from == this)
    {
        return;
    }

    // mission_id
    set_mission_id(from.get_mission_id());
}

bool daily_mission_receive_reward_req::serialize(SpringCat::System::Stream& output) const
{
    // mission_id
    if (SpringCat::Wave::internal::serialize(output, mission_id_) == false)
    {
        return false;
    }

    return true;
}

bool daily_mission_receive_reward_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool daily_mission_receive_reward_req::serialize(std::string& output) const
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

bool daily_mission_receive_reward_req::deserialize(SpringCat::System::Stream& input)
{
    // mission_id
    if (SpringCat::Wave::internal::deserialize(input, mission_id_) == false)
    {
        return false;
    }

    return true;
}

bool daily_mission_receive_reward_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool daily_mission_receive_reward_req::deserialize(std::string& input)
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

SpringCat::int32_t daily_mission_receive_reward_req::get_mission_id(void) const
{
    return mission_id_;
}

void daily_mission_receive_reward_req::set_mission_id(SpringCat::int32_t value)
{
    mission_id_ = value;
}

daily_mission_receive_reward_ans::daily_mission_receive_reward_ans(void)
    : __has_bits__(),
    result_(0),
    reward_(new reward_info)
{
}

daily_mission_receive_reward_ans::daily_mission_receive_reward_ans(const daily_mission_receive_reward_ans& from)
    : __has_bits__(),
    result_(0),
    reward_(new reward_info)
{
    merge_from(from);
}

daily_mission_receive_reward_ans::~daily_mission_receive_reward_ans(void)
{
}

const SpringCat::Wave::type_info& daily_mission_receive_reward_ans::static_type_info(void)
{
    return __daily_mission_receive_reward_ans_type_info__;
}

const SpringCat::Wave::type_info& daily_mission_receive_reward_ans::runtime_type_info(void) const
{
    return static_type_info();
}

daily_mission_receive_reward_ans* daily_mission_receive_reward_ans::new_instance(void) const
{
    return new daily_mission_receive_reward_ans;
}

daily_mission_receive_reward_ans* daily_mission_receive_reward_ans::clone(void) const
{
    return new daily_mission_receive_reward_ans(*this);
}

void daily_mission_receive_reward_ans::clear(void)
{
    // result
    result_ = 0;
    // reward
    reward_->clear();
}

bool daily_mission_receive_reward_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t daily_mission_receive_reward_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // reward
    total_size += SpringCat::Wave::internal::size(*reward_);

    return total_size;
}

void daily_mission_receive_reward_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const daily_mission_receive_reward_ans& src = dynamic_cast<const daily_mission_receive_reward_ans&>(from);
    copy_from(src);
}

void daily_mission_receive_reward_ans::copy_from(const daily_mission_receive_reward_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void daily_mission_receive_reward_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const daily_mission_receive_reward_ans& src = dynamic_cast<const daily_mission_receive_reward_ans&>(from);
    merge_from(src);
}

void daily_mission_receive_reward_ans::merge_from(const daily_mission_receive_reward_ans& from)
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

bool daily_mission_receive_reward_ans::serialize(SpringCat::System::Stream& output) const
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

bool daily_mission_receive_reward_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool daily_mission_receive_reward_ans::serialize(std::string& output) const
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

bool daily_mission_receive_reward_ans::deserialize(SpringCat::System::Stream& input)
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

bool daily_mission_receive_reward_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool daily_mission_receive_reward_ans::deserialize(std::string& input)
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

SpringCat::int16_t daily_mission_receive_reward_ans::get_result(void) const
{
    return result_;
}

void daily_mission_receive_reward_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

const reward_info* daily_mission_receive_reward_ans::get_reward(void) const
{
    return reward_.get();
}

reward_info* daily_mission_receive_reward_ans::get_mutable_reward(void)
{
    return reward_.get();
}

daily_mission_accomplished_notify::daily_mission_accomplished_notify(void)
    : __has_bits__(),
    mission_id_(0)
{
}

daily_mission_accomplished_notify::daily_mission_accomplished_notify(const daily_mission_accomplished_notify& from)
    : __has_bits__(),
    mission_id_(0)
{
    merge_from(from);
}

daily_mission_accomplished_notify::~daily_mission_accomplished_notify(void)
{
}

const SpringCat::Wave::type_info& daily_mission_accomplished_notify::static_type_info(void)
{
    return __daily_mission_accomplished_notify_type_info__;
}

const SpringCat::Wave::type_info& daily_mission_accomplished_notify::runtime_type_info(void) const
{
    return static_type_info();
}

daily_mission_accomplished_notify* daily_mission_accomplished_notify::new_instance(void) const
{
    return new daily_mission_accomplished_notify;
}

daily_mission_accomplished_notify* daily_mission_accomplished_notify::clone(void) const
{
    return new daily_mission_accomplished_notify(*this);
}

void daily_mission_accomplished_notify::clear(void)
{
    // mission_id
    mission_id_ = 0;
}

bool daily_mission_accomplished_notify::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t daily_mission_accomplished_notify::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // mission_id
    total_size += SpringCat::Wave::internal::size(mission_id_);

    return total_size;
}

void daily_mission_accomplished_notify::copy_from(const SpringCat::Wave::object_base& from)
{
    const daily_mission_accomplished_notify& src = dynamic_cast<const daily_mission_accomplished_notify&>(from);
    copy_from(src);
}

void daily_mission_accomplished_notify::copy_from(const daily_mission_accomplished_notify& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void daily_mission_accomplished_notify::merge_from(const SpringCat::Wave::object_base& from)
{
    const daily_mission_accomplished_notify& src = dynamic_cast<const daily_mission_accomplished_notify&>(from);
    merge_from(src);
}

void daily_mission_accomplished_notify::merge_from(const daily_mission_accomplished_notify& from)
{
    if (&from == this)
    {
        return;
    }

    // mission_id
    set_mission_id(from.get_mission_id());
}

bool daily_mission_accomplished_notify::serialize(SpringCat::System::Stream& output) const
{
    // mission_id
    if (SpringCat::Wave::internal::serialize(output, mission_id_) == false)
    {
        return false;
    }

    return true;
}

bool daily_mission_accomplished_notify::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool daily_mission_accomplished_notify::serialize(std::string& output) const
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

bool daily_mission_accomplished_notify::deserialize(SpringCat::System::Stream& input)
{
    // mission_id
    if (SpringCat::Wave::internal::deserialize(input, mission_id_) == false)
    {
        return false;
    }

    return true;
}

bool daily_mission_accomplished_notify::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool daily_mission_accomplished_notify::deserialize(std::string& input)
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

SpringCat::int32_t daily_mission_accomplished_notify::get_mission_id(void) const
{
    return mission_id_;
}

void daily_mission_accomplished_notify::set_mission_id(SpringCat::int32_t value)
{
    mission_id_ = value;
}



}    // namespace protocol
