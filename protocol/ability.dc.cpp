#include "ability.dc.h"
#include <stdexcept>


namespace protocol
{

// class name: ability, type id(decimal): 215029913, type id(hex): 0xCD11899
static const SpringCat::Wave::type_info __ability_type_info__(0xCD11899, "protocol.ability");
// class name: ability_slot, type id(decimal): 154899684, type id(hex): 0x93B94E4
static const SpringCat::Wave::type_info __ability_slot_type_info__(0x93B94E4, "protocol.ability_slot");
// class name: ability_list, type id(decimal): 154747172, type id(hex): 0x9394124
static const SpringCat::Wave::type_info __ability_list_type_info__(0x9394124, "protocol.ability_list");
// class name: ability_list_req, type id(decimal): 18960769, type id(hex): 0x1215181
static const SpringCat::Wave::type_info __ability_list_req_type_info__(0x1215181, "protocol.ability_list_req");
// class name: ability_list_ans, type id(decimal): 18968339, type id(hex): 0x1216F13
static const SpringCat::Wave::type_info __ability_list_ans_type_info__(0x1216F13, "protocol.ability_list_ans");
// class name: ability_slot_open_req, type id(decimal): 950049, type id(hex): 0xE7F21
static const SpringCat::Wave::type_info __ability_slot_open_req_type_info__(0xE7F21, "protocol.ability_slot_open_req");
// class name: ability_slot_open_ans, type id(decimal): 934323, type id(hex): 0xE41B3
static const SpringCat::Wave::type_info __ability_slot_open_ans_type_info__(0xE41B3, "protocol.ability_slot_open_ans");
// class name: ability_equip_req, type id(decimal): 77063505, type id(hex): 0x497E551
static const SpringCat::Wave::type_info __ability_equip_req_type_info__(0x497E551, "protocol.ability_equip_req");
// class name: ability_equip_ans, type id(decimal): 77061059, type id(hex): 0x497DBC3
static const SpringCat::Wave::type_info __ability_equip_ans_type_info__(0x497DBC3, "protocol.ability_equip_ans");
// class name: ability_acquire_req, type id(decimal): 51239153, type id(hex): 0x30DD8F1
static const SpringCat::Wave::type_info __ability_acquire_req_type_info__(0x30DD8F1, "protocol.ability_acquire_req");
// class name: ability_acquire_ans, type id(decimal): 51243107, type id(hex): 0x30DE863
static const SpringCat::Wave::type_info __ability_acquire_ans_type_info__(0x30DE863, "protocol.ability_acquire_ans");

ability::ability(void)
    : __has_bits__(),
    ability_id_(0),
    level_(0)
{
}

ability::ability(const ability& from)
    : __has_bits__(),
    ability_id_(0),
    level_(0)
{
    merge_from(from);
}

ability::~ability(void)
{
}

const SpringCat::Wave::type_info& ability::static_type_info(void)
{
    return __ability_type_info__;
}

const SpringCat::Wave::type_info& ability::runtime_type_info(void) const
{
    return static_type_info();
}

ability* ability::new_instance(void) const
{
    return new ability;
}

ability* ability::clone(void) const
{
    return new ability(*this);
}

void ability::clear(void)
{
    // ability_id
    ability_id_ = 0;
    // level
    level_ = 0;
}

bool ability::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t ability::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // ability_id
    total_size += SpringCat::Wave::internal::size(ability_id_);
    // level
    total_size += SpringCat::Wave::internal::size(level_);

    return total_size;
}

void ability::copy_from(const SpringCat::Wave::object_base& from)
{
    const ability& src = dynamic_cast<const ability&>(from);
    copy_from(src);
}

void ability::copy_from(const ability& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void ability::merge_from(const SpringCat::Wave::object_base& from)
{
    const ability& src = dynamic_cast<const ability&>(from);
    merge_from(src);
}

void ability::merge_from(const ability& from)
{
    if (&from == this)
    {
        return;
    }

    // ability_id
    set_ability_id(from.get_ability_id());
    // level
    set_level(from.get_level());
}

bool ability::serialize(SpringCat::System::Stream& output) const
{
    // ability_id
    if (SpringCat::Wave::internal::serialize(output, ability_id_) == false)
    {
        return false;
    }
    // level
    if (SpringCat::Wave::internal::serialize(output, level_) == false)
    {
        return false;
    }

    return true;
}

bool ability::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool ability::serialize(std::string& output) const
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

bool ability::deserialize(SpringCat::System::Stream& input)
{
    // ability_id
    if (SpringCat::Wave::internal::deserialize(input, ability_id_) == false)
    {
        return false;
    }
    // level
    if (SpringCat::Wave::internal::deserialize(input, level_) == false)
    {
        return false;
    }

    return true;
}

bool ability::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool ability::deserialize(std::string& input)
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

SpringCat::int32_t ability::get_ability_id(void) const
{
    return ability_id_;
}

void ability::set_ability_id(SpringCat::int32_t value)
{
    ability_id_ = value;
}

SpringCat::int16_t ability::get_level(void) const
{
    return level_;
}

void ability::set_level(SpringCat::int16_t value)
{
    level_ = value;
}

ability_slot::ability_slot(void)
    : __has_bits__(),
    slots_()
{
}

ability_slot::ability_slot(const ability_slot& from)
    : __has_bits__(),
    slots_()
{
    merge_from(from);
}

ability_slot::~ability_slot(void)
{
    // slots
    slots_.clear();
}

const SpringCat::Wave::type_info& ability_slot::static_type_info(void)
{
    return __ability_slot_type_info__;
}

const SpringCat::Wave::type_info& ability_slot::runtime_type_info(void) const
{
    return static_type_info();
}

ability_slot* ability_slot::new_instance(void) const
{
    return new ability_slot;
}

ability_slot* ability_slot::clone(void) const
{
    return new ability_slot(*this);
}

void ability_slot::clear(void)
{
    // slots
    slots_.clear();
}

bool ability_slot::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t ability_slot::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // slots
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint32_t));
    total_size += static_cast<SpringCat::uint32_t>(sizeof(ability_slot_no) * slots_.size());
    for(std::map<ability_slot_no, SpringCat::int32_t>::const_iterator it = slots_.begin(); it != slots_.end(); ++it)
    {
        total_size += sizeof(it->second);
    }

    return total_size;
}

void ability_slot::copy_from(const SpringCat::Wave::object_base& from)
{
    const ability_slot& src = dynamic_cast<const ability_slot&>(from);
    copy_from(src);
}

void ability_slot::copy_from(const ability_slot& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void ability_slot::merge_from(const SpringCat::Wave::object_base& from)
{
    const ability_slot& src = dynamic_cast<const ability_slot&>(from);
    merge_from(src);
}

void ability_slot::merge_from(const ability_slot& from)
{
    if (&from == this)
    {
        return;
    }

    // slots
    for(std::map<ability_slot_no, SpringCat::int32_t>::const_iterator it = from.slots_.begin(); it != from.slots_.end(); ++it)
    {
        insert_slots(it->first, it->second);
    }
}

bool ability_slot::serialize(SpringCat::System::Stream& output) const
{
    // slots
    SpringCat::uint32_t slots_size = static_cast<SpringCat::uint32_t>(slots_.size());
    if (SpringCat::Wave::internal::serialize(output, slots_size) == false)
    {
        return false;
    }
    for(std::map<ability_slot_no, SpringCat::int32_t>::const_iterator it = slots_.begin(); it != slots_.end(); ++it)
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

bool ability_slot::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool ability_slot::serialize(std::string& output) const
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

bool ability_slot::deserialize(SpringCat::System::Stream& input)
{
    // slots
    SpringCat::uint32_t slots_size = 0;
    if (SpringCat::Wave::internal::deserialize(input, slots_size) == false)
    {
        return false;
    }
    for (SpringCat::uint32_t i = 0; i != slots_size; ++i)
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
        insert_slots(static_cast<ability_slot_no>(key), value);
    }

    return true;
}

bool ability_slot::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool ability_slot::deserialize(std::string& input)
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

const std::map<ability_slot_no, SpringCat::int32_t>& ability_slot::get_slots(void) const
{
    return slots_;
}

std::map<ability_slot_no, SpringCat::int32_t>* ability_slot::get_mutable_slots(void)
{
    return &slots_;
}

bool ability_slot::get_slots(ability_slot_no key, SpringCat::int32_t* value) const
{
    std::map<ability_slot_no, SpringCat::int32_t>::const_iterator it = slots_.find(key);
    if(it == slots_.end())
    {
        return false;
    }

    if(value)
    {
        *value = it->second;
    }

    return true;
}

void ability_slot::set_slots(ability_slot_no key, SpringCat::int32_t value)
{
    slots_[key] = value;
}

bool ability_slot::insert_slots(ability_slot_no key, SpringCat::int32_t value)
{
    return slots_.insert(std::make_pair(key, value)).second;
}


ability_list::ability_list(void)
    : __has_bits__(),
    infos_()
{
}

ability_list::ability_list(const ability_list& from)
    : __has_bits__(),
    infos_()
{
    merge_from(from);
}

ability_list::~ability_list(void)
{
    // infos
    SpringCat::uint32_t infos_size = static_cast<SpringCat::uint32_t>(infos_.size());
    for (SpringCat::uint32_t i = 0; i != infos_size; ++i)
    {
        delete infos_[i];
    }
    infos_.clear();
}

const SpringCat::Wave::type_info& ability_list::static_type_info(void)
{
    return __ability_list_type_info__;
}

const SpringCat::Wave::type_info& ability_list::runtime_type_info(void) const
{
    return static_type_info();
}

ability_list* ability_list::new_instance(void) const
{
    return new ability_list;
}

ability_list* ability_list::clone(void) const
{
    return new ability_list(*this);
}

void ability_list::clear(void)
{
    // infos
    SpringCat::uint32_t infos_size = static_cast<SpringCat::uint32_t>(infos_.size());
    for (SpringCat::uint32_t i = 0; i != infos_size; ++i)
    {
        delete infos_[i];
    }
    infos_.clear();
}

bool ability_list::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t ability_list::size(void) const
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

void ability_list::copy_from(const SpringCat::Wave::object_base& from)
{
    const ability_list& src = dynamic_cast<const ability_list&>(from);
    copy_from(src);
}

void ability_list::copy_from(const ability_list& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void ability_list::merge_from(const SpringCat::Wave::object_base& from)
{
    const ability_list& src = dynamic_cast<const ability_list&>(from);
    merge_from(src);
}

void ability_list::merge_from(const ability_list& from)
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

bool ability_list::serialize(SpringCat::System::Stream& output) const
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

bool ability_list::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool ability_list::serialize(std::string& output) const
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

bool ability_list::deserialize(SpringCat::System::Stream& input)
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
            std::auto_ptr<ability> new_infos(new ability);
            if (SpringCat::Wave::internal::deserialize(input, *new_infos) == false)
            {
                return false;
            }
            infos_.push_back(new_infos.release());
        }
    }

    return true;
}

bool ability_list::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool ability_list::deserialize(std::string& input)
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

const std::vector<ability*>& ability_list::get_infos(void) const
{
    return infos_;
}

std::vector<ability*>* ability_list::get_mutable_infos(void)
{
    return &infos_;
}

const ability* ability_list::get_infos(size_t index) const
{
    if (infos_.size() <= index)
    {
        throw std::out_of_range("ability_list::infos_ index outside range");
    }

    return infos_[index];
}

ability* ability_list::get_mutable_infos(size_t index)
{
    if (infos_.size() <= index)
    {
        throw std::out_of_range("ability_list::infos_ index outside range");
    }

    return infos_[index];
}

ability* ability_list::add_infos(void)
{
    std::auto_ptr<ability> new_infos(new ability);
    infos_.push_back(new_infos.get());

    return new_infos.release();
}

ability_list_req::ability_list_req(void)
{
}

ability_list_req::ability_list_req(const ability_list_req& from)
{
    merge_from(from);
}

ability_list_req::~ability_list_req(void)
{
}

const SpringCat::Wave::type_info& ability_list_req::static_type_info(void)
{
    return __ability_list_req_type_info__;
}

const SpringCat::Wave::type_info& ability_list_req::runtime_type_info(void) const
{
    return static_type_info();
}

ability_list_req* ability_list_req::new_instance(void) const
{
    return new ability_list_req;
}

ability_list_req* ability_list_req::clone(void) const
{
    return new ability_list_req(*this);
}

void ability_list_req::clear(void)
{
}

bool ability_list_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t ability_list_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    return total_size;
}

void ability_list_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const ability_list_req& src = dynamic_cast<const ability_list_req&>(from);
    copy_from(src);
}

void ability_list_req::copy_from(const ability_list_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void ability_list_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const ability_list_req& src = dynamic_cast<const ability_list_req&>(from);
    merge_from(src);
}

void ability_list_req::merge_from(const ability_list_req& from)
{
    if (&from == this)
    {
        return;
    }
}

bool ability_list_req::serialize(SpringCat::System::Stream& output) const
{
    return true;
}

bool ability_list_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool ability_list_req::serialize(std::string& output) const
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

bool ability_list_req::deserialize(SpringCat::System::Stream& input)
{
    return true;
}

bool ability_list_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool ability_list_req::deserialize(std::string& input)
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

ability_list_ans::ability_list_ans(void)
    : __has_bits__(),
    result_(0),
    infos_(new ability_list),
    slot_(new ability_slot)
{
}

ability_list_ans::ability_list_ans(const ability_list_ans& from)
    : __has_bits__(),
    result_(0),
    infos_(new ability_list),
    slot_(new ability_slot)
{
    merge_from(from);
}

ability_list_ans::~ability_list_ans(void)
{
}

const SpringCat::Wave::type_info& ability_list_ans::static_type_info(void)
{
    return __ability_list_ans_type_info__;
}

const SpringCat::Wave::type_info& ability_list_ans::runtime_type_info(void) const
{
    return static_type_info();
}

ability_list_ans* ability_list_ans::new_instance(void) const
{
    return new ability_list_ans;
}

ability_list_ans* ability_list_ans::clone(void) const
{
    return new ability_list_ans(*this);
}

void ability_list_ans::clear(void)
{
    // result
    result_ = 0;
    // infos
    infos_->clear();
    // slot
    slot_->clear();
}

bool ability_list_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t ability_list_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // infos
    total_size += SpringCat::Wave::internal::size(*infos_);
    // slot
    total_size += SpringCat::Wave::internal::size(*slot_);

    return total_size;
}

void ability_list_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const ability_list_ans& src = dynamic_cast<const ability_list_ans&>(from);
    copy_from(src);
}

void ability_list_ans::copy_from(const ability_list_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void ability_list_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const ability_list_ans& src = dynamic_cast<const ability_list_ans&>(from);
    merge_from(src);
}

void ability_list_ans::merge_from(const ability_list_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // infos
    infos_->merge_from(*from.get_infos());
    // slot
    slot_->merge_from(*from.get_slot());
}

bool ability_list_ans::serialize(SpringCat::System::Stream& output) const
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
    // slot
    if (SpringCat::Wave::internal::serialize(output, *slot_) == false)
    {
        return false;
    }

    return true;
}

bool ability_list_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool ability_list_ans::serialize(std::string& output) const
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

bool ability_list_ans::deserialize(SpringCat::System::Stream& input)
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
    // slot
    if (SpringCat::Wave::internal::deserialize(input, *slot_) == false)
    {
        return false;
    }

    return true;
}

bool ability_list_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool ability_list_ans::deserialize(std::string& input)
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

SpringCat::int16_t ability_list_ans::get_result(void) const
{
    return result_;
}

void ability_list_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

const ability_list* ability_list_ans::get_infos(void) const
{
    return infos_.get();
}

ability_list* ability_list_ans::get_mutable_infos(void)
{
    return infos_.get();
}

const ability_slot* ability_list_ans::get_slot(void) const
{
    return slot_.get();
}

ability_slot* ability_list_ans::get_mutable_slot(void)
{
    return slot_.get();
}

ability_slot_open_req::ability_slot_open_req(void)
    : __has_bits__(),
    slot_no_(0)
{
}

ability_slot_open_req::ability_slot_open_req(const ability_slot_open_req& from)
    : __has_bits__(),
    slot_no_(0)
{
    merge_from(from);
}

ability_slot_open_req::~ability_slot_open_req(void)
{
}

const SpringCat::Wave::type_info& ability_slot_open_req::static_type_info(void)
{
    return __ability_slot_open_req_type_info__;
}

const SpringCat::Wave::type_info& ability_slot_open_req::runtime_type_info(void) const
{
    return static_type_info();
}

ability_slot_open_req* ability_slot_open_req::new_instance(void) const
{
    return new ability_slot_open_req;
}

ability_slot_open_req* ability_slot_open_req::clone(void) const
{
    return new ability_slot_open_req(*this);
}

void ability_slot_open_req::clear(void)
{
    // slot_no
    slot_no_ = 0;
}

bool ability_slot_open_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t ability_slot_open_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // slot_no
    total_size += SpringCat::Wave::internal::size(slot_no_);

    return total_size;
}

void ability_slot_open_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const ability_slot_open_req& src = dynamic_cast<const ability_slot_open_req&>(from);
    copy_from(src);
}

void ability_slot_open_req::copy_from(const ability_slot_open_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void ability_slot_open_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const ability_slot_open_req& src = dynamic_cast<const ability_slot_open_req&>(from);
    merge_from(src);
}

void ability_slot_open_req::merge_from(const ability_slot_open_req& from)
{
    if (&from == this)
    {
        return;
    }

    // slot_no
    set_slot_no(from.get_slot_no());
}

bool ability_slot_open_req::serialize(SpringCat::System::Stream& output) const
{
    // slot_no
    if (SpringCat::Wave::internal::serialize(output, slot_no_) == false)
    {
        return false;
    }

    return true;
}

bool ability_slot_open_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool ability_slot_open_req::serialize(std::string& output) const
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

bool ability_slot_open_req::deserialize(SpringCat::System::Stream& input)
{
    // slot_no
    if (SpringCat::Wave::internal::deserialize(input, slot_no_) == false)
    {
        return false;
    }

    return true;
}

bool ability_slot_open_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool ability_slot_open_req::deserialize(std::string& input)
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

ability_slot_no ability_slot_open_req::get_slot_no(void) const
{
    return static_cast<ability_slot_no>(slot_no_);
}

void ability_slot_open_req::set_slot_no(ability_slot_no value)
{
    slot_no_ = value;
}

ability_slot_open_ans::ability_slot_open_ans(void)
    : __has_bits__(),
    result_(0),
    updated_slot_(new ability_slot)
{
}

ability_slot_open_ans::ability_slot_open_ans(const ability_slot_open_ans& from)
    : __has_bits__(),
    result_(0),
    updated_slot_(new ability_slot)
{
    merge_from(from);
}

ability_slot_open_ans::~ability_slot_open_ans(void)
{
}

const SpringCat::Wave::type_info& ability_slot_open_ans::static_type_info(void)
{
    return __ability_slot_open_ans_type_info__;
}

const SpringCat::Wave::type_info& ability_slot_open_ans::runtime_type_info(void) const
{
    return static_type_info();
}

ability_slot_open_ans* ability_slot_open_ans::new_instance(void) const
{
    return new ability_slot_open_ans;
}

ability_slot_open_ans* ability_slot_open_ans::clone(void) const
{
    return new ability_slot_open_ans(*this);
}

void ability_slot_open_ans::clear(void)
{
    // result
    result_ = 0;
    // updated_slot
    updated_slot_->clear();
}

bool ability_slot_open_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t ability_slot_open_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // updated_slot
    total_size += SpringCat::Wave::internal::size(*updated_slot_);

    return total_size;
}

void ability_slot_open_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const ability_slot_open_ans& src = dynamic_cast<const ability_slot_open_ans&>(from);
    copy_from(src);
}

void ability_slot_open_ans::copy_from(const ability_slot_open_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void ability_slot_open_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const ability_slot_open_ans& src = dynamic_cast<const ability_slot_open_ans&>(from);
    merge_from(src);
}

void ability_slot_open_ans::merge_from(const ability_slot_open_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // updated_slot
    updated_slot_->merge_from(*from.get_updated_slot());
}

bool ability_slot_open_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // updated_slot
    if (SpringCat::Wave::internal::serialize(output, *updated_slot_) == false)
    {
        return false;
    }

    return true;
}

bool ability_slot_open_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool ability_slot_open_ans::serialize(std::string& output) const
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

bool ability_slot_open_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // updated_slot
    if (SpringCat::Wave::internal::deserialize(input, *updated_slot_) == false)
    {
        return false;
    }

    return true;
}

bool ability_slot_open_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool ability_slot_open_ans::deserialize(std::string& input)
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

SpringCat::int16_t ability_slot_open_ans::get_result(void) const
{
    return result_;
}

void ability_slot_open_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

const ability_slot* ability_slot_open_ans::get_updated_slot(void) const
{
    return updated_slot_.get();
}

ability_slot* ability_slot_open_ans::get_mutable_updated_slot(void)
{
    return updated_slot_.get();
}

ability_equip_req::ability_equip_req(void)
    : __has_bits__(),
    ability_id_(0),
    slot_no_(0)
{
}

ability_equip_req::ability_equip_req(const ability_equip_req& from)
    : __has_bits__(),
    ability_id_(0),
    slot_no_(0)
{
    merge_from(from);
}

ability_equip_req::~ability_equip_req(void)
{
}

const SpringCat::Wave::type_info& ability_equip_req::static_type_info(void)
{
    return __ability_equip_req_type_info__;
}

const SpringCat::Wave::type_info& ability_equip_req::runtime_type_info(void) const
{
    return static_type_info();
}

ability_equip_req* ability_equip_req::new_instance(void) const
{
    return new ability_equip_req;
}

ability_equip_req* ability_equip_req::clone(void) const
{
    return new ability_equip_req(*this);
}

void ability_equip_req::clear(void)
{
    // ability_id
    ability_id_ = 0;
    // slot_no
    slot_no_ = 0;
}

bool ability_equip_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t ability_equip_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // ability_id
    total_size += SpringCat::Wave::internal::size(ability_id_);
    // slot_no
    total_size += SpringCat::Wave::internal::size(slot_no_);

    return total_size;
}

void ability_equip_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const ability_equip_req& src = dynamic_cast<const ability_equip_req&>(from);
    copy_from(src);
}

void ability_equip_req::copy_from(const ability_equip_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void ability_equip_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const ability_equip_req& src = dynamic_cast<const ability_equip_req&>(from);
    merge_from(src);
}

void ability_equip_req::merge_from(const ability_equip_req& from)
{
    if (&from == this)
    {
        return;
    }

    // ability_id
    set_ability_id(from.get_ability_id());
    // slot_no
    set_slot_no(from.get_slot_no());
}

bool ability_equip_req::serialize(SpringCat::System::Stream& output) const
{
    // ability_id
    if (SpringCat::Wave::internal::serialize(output, ability_id_) == false)
    {
        return false;
    }
    // slot_no
    if (SpringCat::Wave::internal::serialize(output, slot_no_) == false)
    {
        return false;
    }

    return true;
}

bool ability_equip_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool ability_equip_req::serialize(std::string& output) const
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

bool ability_equip_req::deserialize(SpringCat::System::Stream& input)
{
    // ability_id
    if (SpringCat::Wave::internal::deserialize(input, ability_id_) == false)
    {
        return false;
    }
    // slot_no
    if (SpringCat::Wave::internal::deserialize(input, slot_no_) == false)
    {
        return false;
    }

    return true;
}

bool ability_equip_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool ability_equip_req::deserialize(std::string& input)
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

SpringCat::int32_t ability_equip_req::get_ability_id(void) const
{
    return ability_id_;
}

void ability_equip_req::set_ability_id(SpringCat::int32_t value)
{
    ability_id_ = value;
}

ability_slot_no ability_equip_req::get_slot_no(void) const
{
    return static_cast<ability_slot_no>(slot_no_);
}

void ability_equip_req::set_slot_no(ability_slot_no value)
{
    slot_no_ = value;
}

ability_equip_ans::ability_equip_ans(void)
    : __has_bits__(),
    result_(0),
    updated_slot_(new ability_slot)
{
}

ability_equip_ans::ability_equip_ans(const ability_equip_ans& from)
    : __has_bits__(),
    result_(0),
    updated_slot_(new ability_slot)
{
    merge_from(from);
}

ability_equip_ans::~ability_equip_ans(void)
{
}

const SpringCat::Wave::type_info& ability_equip_ans::static_type_info(void)
{
    return __ability_equip_ans_type_info__;
}

const SpringCat::Wave::type_info& ability_equip_ans::runtime_type_info(void) const
{
    return static_type_info();
}

ability_equip_ans* ability_equip_ans::new_instance(void) const
{
    return new ability_equip_ans;
}

ability_equip_ans* ability_equip_ans::clone(void) const
{
    return new ability_equip_ans(*this);
}

void ability_equip_ans::clear(void)
{
    // result
    result_ = 0;
    // updated_slot
    updated_slot_->clear();
}

bool ability_equip_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t ability_equip_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // updated_slot
    total_size += SpringCat::Wave::internal::size(*updated_slot_);

    return total_size;
}

void ability_equip_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const ability_equip_ans& src = dynamic_cast<const ability_equip_ans&>(from);
    copy_from(src);
}

void ability_equip_ans::copy_from(const ability_equip_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void ability_equip_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const ability_equip_ans& src = dynamic_cast<const ability_equip_ans&>(from);
    merge_from(src);
}

void ability_equip_ans::merge_from(const ability_equip_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // updated_slot
    updated_slot_->merge_from(*from.get_updated_slot());
}

bool ability_equip_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // updated_slot
    if (SpringCat::Wave::internal::serialize(output, *updated_slot_) == false)
    {
        return false;
    }

    return true;
}

bool ability_equip_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool ability_equip_ans::serialize(std::string& output) const
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

bool ability_equip_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // updated_slot
    if (SpringCat::Wave::internal::deserialize(input, *updated_slot_) == false)
    {
        return false;
    }

    return true;
}

bool ability_equip_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool ability_equip_ans::deserialize(std::string& input)
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

SpringCat::int16_t ability_equip_ans::get_result(void) const
{
    return result_;
}

void ability_equip_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

const ability_slot* ability_equip_ans::get_updated_slot(void) const
{
    return updated_slot_.get();
}

ability_slot* ability_equip_ans::get_mutable_updated_slot(void)
{
    return updated_slot_.get();
}

ability_acquire_req::ability_acquire_req(void)
    : __has_bits__(),
    ability_id_(0)
{
}

ability_acquire_req::ability_acquire_req(const ability_acquire_req& from)
    : __has_bits__(),
    ability_id_(0)
{
    merge_from(from);
}

ability_acquire_req::~ability_acquire_req(void)
{
}

const SpringCat::Wave::type_info& ability_acquire_req::static_type_info(void)
{
    return __ability_acquire_req_type_info__;
}

const SpringCat::Wave::type_info& ability_acquire_req::runtime_type_info(void) const
{
    return static_type_info();
}

ability_acquire_req* ability_acquire_req::new_instance(void) const
{
    return new ability_acquire_req;
}

ability_acquire_req* ability_acquire_req::clone(void) const
{
    return new ability_acquire_req(*this);
}

void ability_acquire_req::clear(void)
{
    // ability_id
    ability_id_ = 0;
}

bool ability_acquire_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t ability_acquire_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // ability_id
    total_size += SpringCat::Wave::internal::size(ability_id_);

    return total_size;
}

void ability_acquire_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const ability_acquire_req& src = dynamic_cast<const ability_acquire_req&>(from);
    copy_from(src);
}

void ability_acquire_req::copy_from(const ability_acquire_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void ability_acquire_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const ability_acquire_req& src = dynamic_cast<const ability_acquire_req&>(from);
    merge_from(src);
}

void ability_acquire_req::merge_from(const ability_acquire_req& from)
{
    if (&from == this)
    {
        return;
    }

    // ability_id
    set_ability_id(from.get_ability_id());
}

bool ability_acquire_req::serialize(SpringCat::System::Stream& output) const
{
    // ability_id
    if (SpringCat::Wave::internal::serialize(output, ability_id_) == false)
    {
        return false;
    }

    return true;
}

bool ability_acquire_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool ability_acquire_req::serialize(std::string& output) const
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

bool ability_acquire_req::deserialize(SpringCat::System::Stream& input)
{
    // ability_id
    if (SpringCat::Wave::internal::deserialize(input, ability_id_) == false)
    {
        return false;
    }

    return true;
}

bool ability_acquire_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool ability_acquire_req::deserialize(std::string& input)
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

SpringCat::int32_t ability_acquire_req::get_ability_id(void) const
{
    return ability_id_;
}

void ability_acquire_req::set_ability_id(SpringCat::int32_t value)
{
    ability_id_ = value;
}

ability_acquire_ans::ability_acquire_ans(void)
    : __has_bits__(),
    result_(0),
    updated_ability_(new ability)
{
}

ability_acquire_ans::ability_acquire_ans(const ability_acquire_ans& from)
    : __has_bits__(),
    result_(0),
    updated_ability_(new ability)
{
    merge_from(from);
}

ability_acquire_ans::~ability_acquire_ans(void)
{
}

const SpringCat::Wave::type_info& ability_acquire_ans::static_type_info(void)
{
    return __ability_acquire_ans_type_info__;
}

const SpringCat::Wave::type_info& ability_acquire_ans::runtime_type_info(void) const
{
    return static_type_info();
}

ability_acquire_ans* ability_acquire_ans::new_instance(void) const
{
    return new ability_acquire_ans;
}

ability_acquire_ans* ability_acquire_ans::clone(void) const
{
    return new ability_acquire_ans(*this);
}

void ability_acquire_ans::clear(void)
{
    // result
    result_ = 0;
    // updated_ability
    updated_ability_->clear();
}

bool ability_acquire_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t ability_acquire_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // updated_ability
    total_size += SpringCat::Wave::internal::size(*updated_ability_);

    return total_size;
}

void ability_acquire_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const ability_acquire_ans& src = dynamic_cast<const ability_acquire_ans&>(from);
    copy_from(src);
}

void ability_acquire_ans::copy_from(const ability_acquire_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void ability_acquire_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const ability_acquire_ans& src = dynamic_cast<const ability_acquire_ans&>(from);
    merge_from(src);
}

void ability_acquire_ans::merge_from(const ability_acquire_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // updated_ability
    updated_ability_->merge_from(*from.get_updated_ability());
}

bool ability_acquire_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // updated_ability
    if (SpringCat::Wave::internal::serialize(output, *updated_ability_) == false)
    {
        return false;
    }

    return true;
}

bool ability_acquire_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool ability_acquire_ans::serialize(std::string& output) const
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

bool ability_acquire_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // updated_ability
    if (SpringCat::Wave::internal::deserialize(input, *updated_ability_) == false)
    {
        return false;
    }

    return true;
}

bool ability_acquire_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool ability_acquire_ans::deserialize(std::string& input)
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

SpringCat::int16_t ability_acquire_ans::get_result(void) const
{
    return result_;
}

void ability_acquire_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

const ability* ability_acquire_ans::get_updated_ability(void) const
{
    return updated_ability_.get();
}

ability* ability_acquire_ans::get_mutable_updated_ability(void)
{
    return updated_ability_.get();
}



}    // namespace protocol
