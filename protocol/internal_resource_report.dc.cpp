#include "internal_resource_report.dc.h"
#include <stdexcept>


namespace protocol
{

// class name: game_monitor_data, type id(decimal): 140584161, type id(hex): 0x86124E1
static const SpringCat::Wave::type_info __game_monitor_data_type_info__(0x86124E1, "protocol.game_monitor_data");
// class name: monitor_data_req, type id(decimal): 177511585, type id(hex): 0xA949CA1
static const SpringCat::Wave::type_info __monitor_data_req_type_info__(0xA949CA1, "protocol.monitor_data_req");
// class name: monitor_data_ans, type id(decimal): 177513523, type id(hex): 0xA94A433
static const SpringCat::Wave::type_info __monitor_data_ans_type_info__(0xA94A433, "protocol.monitor_data_ans");

game_monitor_data::game_monitor_data(void)
    : __has_bits__(),
    machine_name_(),
    machine_resource_info_(),
    game_resource_info_()
{
}

game_monitor_data::game_monitor_data(const game_monitor_data& from)
    : __has_bits__(),
    machine_name_(),
    machine_resource_info_(),
    game_resource_info_()
{
    merge_from(from);
}

game_monitor_data::~game_monitor_data(void)
{
    // machine_resource_info
    machine_resource_info_.clear();
    // game_resource_info
    game_resource_info_.clear();
}

const SpringCat::Wave::type_info& game_monitor_data::static_type_info(void)
{
    return __game_monitor_data_type_info__;
}

const SpringCat::Wave::type_info& game_monitor_data::runtime_type_info(void) const
{
    return static_type_info();
}

game_monitor_data* game_monitor_data::new_instance(void) const
{
    return new game_monitor_data;
}

game_monitor_data* game_monitor_data::clone(void) const
{
    return new game_monitor_data(*this);
}

void game_monitor_data::clear(void)
{
    // machine_name
    machine_name_.clear();
    // machine_resource_info
    machine_resource_info_.clear();
    // game_resource_info
    game_resource_info_.clear();
}

bool game_monitor_data::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t game_monitor_data::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // machine_name
    total_size += SpringCat::Wave::internal::size(machine_name_, 0xFFFFFFFF);
    // machine_resource_info
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint32_t));
    total_size += static_cast<SpringCat::uint32_t>(sizeof(HardwareResourceKey) * machine_resource_info_.size());
    for(std::map<HardwareResourceKey, SpringCat::int32_t>::const_iterator it = machine_resource_info_.begin(); it != machine_resource_info_.end(); ++it)
    {
        total_size += sizeof(it->second);
    }
    // game_resource_info
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint32_t));
    total_size += static_cast<SpringCat::uint32_t>(sizeof(GameResourceKey) * game_resource_info_.size());
    for(std::map<GameResourceKey, SpringCat::int32_t>::const_iterator it = game_resource_info_.begin(); it != game_resource_info_.end(); ++it)
    {
        total_size += sizeof(it->second);
    }

    return total_size;
}

void game_monitor_data::copy_from(const SpringCat::Wave::object_base& from)
{
    const game_monitor_data& src = dynamic_cast<const game_monitor_data&>(from);
    copy_from(src);
}

void game_monitor_data::copy_from(const game_monitor_data& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void game_monitor_data::merge_from(const SpringCat::Wave::object_base& from)
{
    const game_monitor_data& src = dynamic_cast<const game_monitor_data&>(from);
    merge_from(src);
}

void game_monitor_data::merge_from(const game_monitor_data& from)
{
    if (&from == this)
    {
        return;
    }

    // machine_name
    set_machine_name(from.get_machine_name());
    // machine_resource_info
    for(std::map<HardwareResourceKey, SpringCat::int32_t>::const_iterator it = from.machine_resource_info_.begin(); it != from.machine_resource_info_.end(); ++it)
    {
        insert_machine_resource_info(it->first, it->second);
    }
    // game_resource_info
    for(std::map<GameResourceKey, SpringCat::int32_t>::const_iterator it = from.game_resource_info_.begin(); it != from.game_resource_info_.end(); ++it)
    {
        insert_game_resource_info(it->first, it->second);
    }
}

bool game_monitor_data::serialize(SpringCat::System::Stream& output) const
{
    // machine_name
    if (SpringCat::Wave::internal::serialize(output, machine_name_, 0xFFFFFFFF) == false)
    {
        return false;
    }
    // machine_resource_info
    SpringCat::uint32_t machine_resource_info_size = static_cast<SpringCat::uint32_t>(machine_resource_info_.size());
    if (SpringCat::Wave::internal::serialize(output, machine_resource_info_size) == false)
    {
        return false;
    }
    for(std::map<HardwareResourceKey, SpringCat::int32_t>::const_iterator it = machine_resource_info_.begin(); it != machine_resource_info_.end(); ++it)
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
    // game_resource_info
    SpringCat::uint32_t game_resource_info_size = static_cast<SpringCat::uint32_t>(game_resource_info_.size());
    if (SpringCat::Wave::internal::serialize(output, game_resource_info_size) == false)
    {
        return false;
    }
    for(std::map<GameResourceKey, SpringCat::int32_t>::const_iterator it = game_resource_info_.begin(); it != game_resource_info_.end(); ++it)
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

bool game_monitor_data::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool game_monitor_data::serialize(std::string& output) const
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

bool game_monitor_data::deserialize(SpringCat::System::Stream& input)
{
    // machine_name
    if (SpringCat::Wave::internal::deserialize(input, machine_name_, 0xFFFFFFFF) == false)
    {
        return false;
    }
    // machine_resource_info
    SpringCat::uint32_t machine_resource_info_size = 0;
    if (SpringCat::Wave::internal::deserialize(input, machine_resource_info_size) == false)
    {
        return false;
    }
    for (SpringCat::uint32_t i = 0; i != machine_resource_info_size; ++i)
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
        insert_machine_resource_info(static_cast<HardwareResourceKey>(key), value);
    }
    // game_resource_info
    SpringCat::uint32_t game_resource_info_size = 0;
    if (SpringCat::Wave::internal::deserialize(input, game_resource_info_size) == false)
    {
        return false;
    }
    for (SpringCat::uint32_t i = 0; i != game_resource_info_size; ++i)
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
        insert_game_resource_info(static_cast<GameResourceKey>(key), value);
    }

    return true;
}

bool game_monitor_data::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool game_monitor_data::deserialize(std::string& input)
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

const std::string& game_monitor_data::get_machine_name(void) const
{
    return machine_name_;
}

std::string* game_monitor_data::get_mutable_machine_name(void)
{
    return &machine_name_;
}

void game_monitor_data::set_machine_name(const std::string& value)
{
    machine_name_.assign(value);
}

void game_monitor_data::set_machine_name(const char* value)
{
    machine_name_.assign(value);
}

const std::map<HardwareResourceKey, SpringCat::int32_t>& game_monitor_data::get_machine_resource_info(void) const
{
    return machine_resource_info_;
}

std::map<HardwareResourceKey, SpringCat::int32_t>* game_monitor_data::get_mutable_machine_resource_info(void)
{
    return &machine_resource_info_;
}

bool game_monitor_data::get_machine_resource_info(HardwareResourceKey key, SpringCat::int32_t* value) const
{
    std::map<HardwareResourceKey, SpringCat::int32_t>::const_iterator it = machine_resource_info_.find(key);
    if(it == machine_resource_info_.end())
    {
        return false;
    }

    if(value)
    {
        *value = it->second;
    }

    return true;
}

void game_monitor_data::set_machine_resource_info(HardwareResourceKey key, SpringCat::int32_t value)
{
    machine_resource_info_[key] = value;
}

bool game_monitor_data::insert_machine_resource_info(HardwareResourceKey key, SpringCat::int32_t value)
{
    return machine_resource_info_.insert(std::make_pair(key, value)).second;
}


const std::map<GameResourceKey, SpringCat::int32_t>& game_monitor_data::get_game_resource_info(void) const
{
    return game_resource_info_;
}

std::map<GameResourceKey, SpringCat::int32_t>* game_monitor_data::get_mutable_game_resource_info(void)
{
    return &game_resource_info_;
}

bool game_monitor_data::get_game_resource_info(GameResourceKey key, SpringCat::int32_t* value) const
{
    std::map<GameResourceKey, SpringCat::int32_t>::const_iterator it = game_resource_info_.find(key);
    if(it == game_resource_info_.end())
    {
        return false;
    }

    if(value)
    {
        *value = it->second;
    }

    return true;
}

void game_monitor_data::set_game_resource_info(GameResourceKey key, SpringCat::int32_t value)
{
    game_resource_info_[key] = value;
}

bool game_monitor_data::insert_game_resource_info(GameResourceKey key, SpringCat::int32_t value)
{
    return game_resource_info_.insert(std::make_pair(key, value)).second;
}


monitor_data_req::monitor_data_req(void)
{
}

monitor_data_req::monitor_data_req(const monitor_data_req& from)
{
    merge_from(from);
}

monitor_data_req::~monitor_data_req(void)
{
}

const SpringCat::Wave::type_info& monitor_data_req::static_type_info(void)
{
    return __monitor_data_req_type_info__;
}

const SpringCat::Wave::type_info& monitor_data_req::runtime_type_info(void) const
{
    return static_type_info();
}

monitor_data_req* monitor_data_req::new_instance(void) const
{
    return new monitor_data_req;
}

monitor_data_req* monitor_data_req::clone(void) const
{
    return new monitor_data_req(*this);
}

void monitor_data_req::clear(void)
{
}

bool monitor_data_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t monitor_data_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    return total_size;
}

void monitor_data_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const monitor_data_req& src = dynamic_cast<const monitor_data_req&>(from);
    copy_from(src);
}

void monitor_data_req::copy_from(const monitor_data_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void monitor_data_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const monitor_data_req& src = dynamic_cast<const monitor_data_req&>(from);
    merge_from(src);
}

void monitor_data_req::merge_from(const monitor_data_req& from)
{
    if (&from == this)
    {
        return;
    }
}

bool monitor_data_req::serialize(SpringCat::System::Stream& output) const
{
    return true;
}

bool monitor_data_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool monitor_data_req::serialize(std::string& output) const
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

bool monitor_data_req::deserialize(SpringCat::System::Stream& input)
{
    return true;
}

bool monitor_data_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool monitor_data_req::deserialize(std::string& input)
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

monitor_data_ans::monitor_data_ans(void)
    : __has_bits__(),
    result_(0),
    data_(new game_monitor_data)
{
}

monitor_data_ans::monitor_data_ans(const monitor_data_ans& from)
    : __has_bits__(),
    result_(0),
    data_(new game_monitor_data)
{
    merge_from(from);
}

monitor_data_ans::~monitor_data_ans(void)
{
}

const SpringCat::Wave::type_info& monitor_data_ans::static_type_info(void)
{
    return __monitor_data_ans_type_info__;
}

const SpringCat::Wave::type_info& monitor_data_ans::runtime_type_info(void) const
{
    return static_type_info();
}

monitor_data_ans* monitor_data_ans::new_instance(void) const
{
    return new monitor_data_ans;
}

monitor_data_ans* monitor_data_ans::clone(void) const
{
    return new monitor_data_ans(*this);
}

void monitor_data_ans::clear(void)
{
    // result
    result_ = 0;
    // data
    data_->clear();
}

bool monitor_data_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t monitor_data_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // data
    total_size += SpringCat::Wave::internal::size(*data_);

    return total_size;
}

void monitor_data_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const monitor_data_ans& src = dynamic_cast<const monitor_data_ans&>(from);
    copy_from(src);
}

void monitor_data_ans::copy_from(const monitor_data_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void monitor_data_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const monitor_data_ans& src = dynamic_cast<const monitor_data_ans&>(from);
    merge_from(src);
}

void monitor_data_ans::merge_from(const monitor_data_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // data
    data_->merge_from(*from.get_data());
}

bool monitor_data_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // data
    if (SpringCat::Wave::internal::serialize(output, *data_) == false)
    {
        return false;
    }

    return true;
}

bool monitor_data_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool monitor_data_ans::serialize(std::string& output) const
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

bool monitor_data_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // data
    if (SpringCat::Wave::internal::deserialize(input, *data_) == false)
    {
        return false;
    }

    return true;
}

bool monitor_data_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool monitor_data_ans::deserialize(std::string& input)
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

SpringCat::int16_t monitor_data_ans::get_result(void) const
{
    return result_;
}

void monitor_data_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

const game_monitor_data* monitor_data_ans::get_data(void) const
{
    return data_.get();
}

game_monitor_data* monitor_data_ans::get_mutable_data(void)
{
    return data_.get();
}



}    // namespace protocol
