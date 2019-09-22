#include "vehicle.dc.h"
#include <stdexcept>


namespace protocol
{

// class name: vehicle_stat, type id(decimal): 32028580, type id(hex): 0x1E8B7A4
static const SpringCat::Wave::type_info __vehicle_stat_type_info__(0x1E8B7A4, "protocol.vehicle_stat");
// class name: vehicle_stuff, type id(decimal): 244017622, type id(hex): 0xE8B69D6
static const SpringCat::Wave::type_info __vehicle_stuff_type_info__(0xE8B69D6, "protocol.vehicle_stuff");
// class name: vehicle_skill, type id(decimal): 243912252, type id(hex): 0xE89CE3C
static const SpringCat::Wave::type_info __vehicle_skill_type_info__(0xE89CE3C, "protocol.vehicle_skill");
// class name: vehicle_parts, type id(decimal): 243751843, type id(hex): 0xE875BA3
static const SpringCat::Wave::type_info __vehicle_parts_type_info__(0xE875BA3, "protocol.vehicle_parts");
// class name: vehicle, type id(decimal): 132239893, type id(hex): 0x7E1D215
static const SpringCat::Wave::type_info __vehicle_type_info__(0x7E1D215, "protocol.vehicle");
// class name: vehicle_list, type id(decimal): 32263556, type id(hex): 0x1EC4D84
static const SpringCat::Wave::type_info __vehicle_list_type_info__(0x1EC4D84, "protocol.vehicle_list");
// class name: vehicle_list_req, type id(decimal): 227116161, type id(hex): 0xD898481
static const SpringCat::Wave::type_info __vehicle_list_req_type_info__(0xD898481, "protocol.vehicle_list_req");
// class name: vehicle_list_ans, type id(decimal): 227130387, type id(hex): 0xD89BC13
static const SpringCat::Wave::type_info __vehicle_list_ans_type_info__(0xD89BC13, "protocol.vehicle_list_ans");
// class name: vehicle_select_req, type id(decimal): 172158913, type id(hex): 0xA42EFC1
static const SpringCat::Wave::type_info __vehicle_select_req_type_info__(0xA42EFC1, "protocol.vehicle_select_req");
// class name: vehicle_select_ans, type id(decimal): 172151123, type id(hex): 0xA42D153
static const SpringCat::Wave::type_info __vehicle_select_ans_type_info__(0xA42D153, "protocol.vehicle_select_ans");
// class name: vehicle_upgrade_req, type id(decimal): 153670737, type id(hex): 0x928D451
static const SpringCat::Wave::type_info __vehicle_upgrade_req_type_info__(0x928D451, "protocol.vehicle_upgrade_req");
// class name: vehicle_upgrade_ans, type id(decimal): 153676995, type id(hex): 0x928ECC3
static const SpringCat::Wave::type_info __vehicle_upgrade_ans_type_info__(0x928ECC3, "protocol.vehicle_upgrade_ans");
// class name: vehicle_parts_tuning_req, type id(decimal): 104048433, type id(hex): 0x633A731
static const SpringCat::Wave::type_info __vehicle_parts_tuning_req_type_info__(0x633A731, "protocol.vehicle_parts_tuning_req");
// class name: vehicle_parts_tuning_ans, type id(decimal): 104044963, type id(hex): 0x63399A3
static const SpringCat::Wave::type_info __vehicle_parts_tuning_ans_type_info__(0x63399A3, "protocol.vehicle_parts_tuning_ans");

vehicle_stat::vehicle_stat(void)
    : __has_bits__(),
    spd_(0),
    pow_(0),
    acc_(0),
    hp_(0)
{
}

vehicle_stat::vehicle_stat(const vehicle_stat& from)
    : __has_bits__(),
    spd_(0),
    pow_(0),
    acc_(0),
    hp_(0)
{
    merge_from(from);
}

vehicle_stat::~vehicle_stat(void)
{
}

const SpringCat::Wave::type_info& vehicle_stat::static_type_info(void)
{
    return __vehicle_stat_type_info__;
}

const SpringCat::Wave::type_info& vehicle_stat::runtime_type_info(void) const
{
    return static_type_info();
}

vehicle_stat* vehicle_stat::new_instance(void) const
{
    return new vehicle_stat;
}

vehicle_stat* vehicle_stat::clone(void) const
{
    return new vehicle_stat(*this);
}

void vehicle_stat::clear(void)
{
    // spd
    spd_ = 0;
    // pow
    pow_ = 0;
    // acc
    acc_ = 0;
    // hp
    hp_ = 0;
}

bool vehicle_stat::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t vehicle_stat::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // spd
    total_size += SpringCat::Wave::internal::size(spd_);
    // pow
    total_size += SpringCat::Wave::internal::size(pow_);
    // acc
    total_size += SpringCat::Wave::internal::size(acc_);
    // hp
    total_size += SpringCat::Wave::internal::size(hp_);

    return total_size;
}

void vehicle_stat::copy_from(const SpringCat::Wave::object_base& from)
{
    const vehicle_stat& src = dynamic_cast<const vehicle_stat&>(from);
    copy_from(src);
}

void vehicle_stat::copy_from(const vehicle_stat& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void vehicle_stat::merge_from(const SpringCat::Wave::object_base& from)
{
    const vehicle_stat& src = dynamic_cast<const vehicle_stat&>(from);
    merge_from(src);
}

void vehicle_stat::merge_from(const vehicle_stat& from)
{
    if (&from == this)
    {
        return;
    }

    // spd
    set_spd(from.get_spd());
    // pow
    set_pow(from.get_pow());
    // acc
    set_acc(from.get_acc());
    // hp
    set_hp(from.get_hp());
}

bool vehicle_stat::serialize(SpringCat::System::Stream& output) const
{
    // spd
    if (SpringCat::Wave::internal::serialize(output, spd_) == false)
    {
        return false;
    }
    // pow
    if (SpringCat::Wave::internal::serialize(output, pow_) == false)
    {
        return false;
    }
    // acc
    if (SpringCat::Wave::internal::serialize(output, acc_) == false)
    {
        return false;
    }
    // hp
    if (SpringCat::Wave::internal::serialize(output, hp_) == false)
    {
        return false;
    }

    return true;
}

bool vehicle_stat::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool vehicle_stat::serialize(std::string& output) const
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

bool vehicle_stat::deserialize(SpringCat::System::Stream& input)
{
    // spd
    if (SpringCat::Wave::internal::deserialize(input, spd_) == false)
    {
        return false;
    }
    // pow
    if (SpringCat::Wave::internal::deserialize(input, pow_) == false)
    {
        return false;
    }
    // acc
    if (SpringCat::Wave::internal::deserialize(input, acc_) == false)
    {
        return false;
    }
    // hp
    if (SpringCat::Wave::internal::deserialize(input, hp_) == false)
    {
        return false;
    }

    return true;
}

bool vehicle_stat::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool vehicle_stat::deserialize(std::string& input)
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

SpringCat::int16_t vehicle_stat::get_spd(void) const
{
    return spd_;
}

void vehicle_stat::set_spd(SpringCat::int16_t value)
{
    spd_ = value;
}

SpringCat::int16_t vehicle_stat::get_pow(void) const
{
    return pow_;
}

void vehicle_stat::set_pow(SpringCat::int16_t value)
{
    pow_ = value;
}

SpringCat::int16_t vehicle_stat::get_acc(void) const
{
    return acc_;
}

void vehicle_stat::set_acc(SpringCat::int16_t value)
{
    acc_ = value;
}

SpringCat::int16_t vehicle_stat::get_hp(void) const
{
    return hp_;
}

void vehicle_stat::set_hp(SpringCat::int16_t value)
{
    hp_ = value;
}

vehicle_stuff::vehicle_stuff(void)
    : __has_bits__(),
    stuff_info_()
{
}

vehicle_stuff::vehicle_stuff(const vehicle_stuff& from)
    : __has_bits__(),
    stuff_info_()
{
    merge_from(from);
}

vehicle_stuff::~vehicle_stuff(void)
{
    // stuff_info
    stuff_info_.clear();
}

const SpringCat::Wave::type_info& vehicle_stuff::static_type_info(void)
{
    return __vehicle_stuff_type_info__;
}

const SpringCat::Wave::type_info& vehicle_stuff::runtime_type_info(void) const
{
    return static_type_info();
}

vehicle_stuff* vehicle_stuff::new_instance(void) const
{
    return new vehicle_stuff;
}

vehicle_stuff* vehicle_stuff::clone(void) const
{
    return new vehicle_stuff(*this);
}

void vehicle_stuff::clear(void)
{
    // stuff_info
    stuff_info_.clear();
}

bool vehicle_stuff::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t vehicle_stuff::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // stuff_info
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint32_t));
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::int32_t) * stuff_info_.size());
    for(std::map<SpringCat::int32_t, SpringCat::int32_t>::const_iterator it = stuff_info_.begin(); it != stuff_info_.end(); ++it)
    {
        total_size += sizeof(it->second);
    }

    return total_size;
}

void vehicle_stuff::copy_from(const SpringCat::Wave::object_base& from)
{
    const vehicle_stuff& src = dynamic_cast<const vehicle_stuff&>(from);
    copy_from(src);
}

void vehicle_stuff::copy_from(const vehicle_stuff& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void vehicle_stuff::merge_from(const SpringCat::Wave::object_base& from)
{
    const vehicle_stuff& src = dynamic_cast<const vehicle_stuff&>(from);
    merge_from(src);
}

void vehicle_stuff::merge_from(const vehicle_stuff& from)
{
    if (&from == this)
    {
        return;
    }

    // stuff_info
    for(std::map<SpringCat::int32_t, SpringCat::int32_t>::const_iterator it = from.stuff_info_.begin(); it != from.stuff_info_.end(); ++it)
    {
        insert_stuff_info(it->first, it->second);
    }
}

bool vehicle_stuff::serialize(SpringCat::System::Stream& output) const
{
    // stuff_info
    SpringCat::uint32_t stuff_info_size = static_cast<SpringCat::uint32_t>(stuff_info_.size());
    if (SpringCat::Wave::internal::serialize(output, stuff_info_size) == false)
    {
        return false;
    }
    for(std::map<SpringCat::int32_t, SpringCat::int32_t>::const_iterator it = stuff_info_.begin(); it != stuff_info_.end(); ++it)
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

bool vehicle_stuff::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool vehicle_stuff::serialize(std::string& output) const
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

bool vehicle_stuff::deserialize(SpringCat::System::Stream& input)
{
    // stuff_info
    SpringCat::uint32_t stuff_info_size = 0;
    if (SpringCat::Wave::internal::deserialize(input, stuff_info_size) == false)
    {
        return false;
    }
    for (SpringCat::uint32_t i = 0; i != stuff_info_size; ++i)
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
        insert_stuff_info(key, value);
    }

    return true;
}

bool vehicle_stuff::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool vehicle_stuff::deserialize(std::string& input)
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

const std::map<SpringCat::int32_t, SpringCat::int32_t>& vehicle_stuff::get_stuff_info(void) const
{
    return stuff_info_;
}

std::map<SpringCat::int32_t, SpringCat::int32_t>* vehicle_stuff::get_mutable_stuff_info(void)
{
    return &stuff_info_;
}

bool vehicle_stuff::get_stuff_info(SpringCat::int32_t key, SpringCat::int32_t* value) const
{
    std::map<SpringCat::int32_t, SpringCat::int32_t>::const_iterator it = stuff_info_.find(key);
    if(it == stuff_info_.end())
    {
        return false;
    }

    if(value)
    {
        *value = it->second;
    }

    return true;
}

void vehicle_stuff::set_stuff_info(SpringCat::int32_t key, SpringCat::int32_t value)
{
    stuff_info_[key] = value;
}

bool vehicle_stuff::insert_stuff_info(SpringCat::int32_t key, SpringCat::int32_t value)
{
    return stuff_info_.insert(std::make_pair(key, value)).second;
}


vehicle_skill::vehicle_skill(void)
    : __has_bits__(),
    skill_id_(0),
    skill_lv_(0)
{
}

vehicle_skill::vehicle_skill(const vehicle_skill& from)
    : __has_bits__(),
    skill_id_(0),
    skill_lv_(0)
{
    merge_from(from);
}

vehicle_skill::~vehicle_skill(void)
{
}

const SpringCat::Wave::type_info& vehicle_skill::static_type_info(void)
{
    return __vehicle_skill_type_info__;
}

const SpringCat::Wave::type_info& vehicle_skill::runtime_type_info(void) const
{
    return static_type_info();
}

vehicle_skill* vehicle_skill::new_instance(void) const
{
    return new vehicle_skill;
}

vehicle_skill* vehicle_skill::clone(void) const
{
    return new vehicle_skill(*this);
}

void vehicle_skill::clear(void)
{
    // skill_id
    skill_id_ = 0;
    // skill_lv
    skill_lv_ = 0;
}

bool vehicle_skill::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t vehicle_skill::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // skill_id
    total_size += SpringCat::Wave::internal::size(skill_id_);
    // skill_lv
    total_size += SpringCat::Wave::internal::size(skill_lv_);

    return total_size;
}

void vehicle_skill::copy_from(const SpringCat::Wave::object_base& from)
{
    const vehicle_skill& src = dynamic_cast<const vehicle_skill&>(from);
    copy_from(src);
}

void vehicle_skill::copy_from(const vehicle_skill& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void vehicle_skill::merge_from(const SpringCat::Wave::object_base& from)
{
    const vehicle_skill& src = dynamic_cast<const vehicle_skill&>(from);
    merge_from(src);
}

void vehicle_skill::merge_from(const vehicle_skill& from)
{
    if (&from == this)
    {
        return;
    }

    // skill_id
    set_skill_id(from.get_skill_id());
    // skill_lv
    set_skill_lv(from.get_skill_lv());
}

bool vehicle_skill::serialize(SpringCat::System::Stream& output) const
{
    // skill_id
    if (SpringCat::Wave::internal::serialize(output, skill_id_) == false)
    {
        return false;
    }
    // skill_lv
    if (SpringCat::Wave::internal::serialize(output, skill_lv_) == false)
    {
        return false;
    }

    return true;
}

bool vehicle_skill::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool vehicle_skill::serialize(std::string& output) const
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

bool vehicle_skill::deserialize(SpringCat::System::Stream& input)
{
    // skill_id
    if (SpringCat::Wave::internal::deserialize(input, skill_id_) == false)
    {
        return false;
    }
    // skill_lv
    if (SpringCat::Wave::internal::deserialize(input, skill_lv_) == false)
    {
        return false;
    }

    return true;
}

bool vehicle_skill::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool vehicle_skill::deserialize(std::string& input)
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

SpringCat::int32_t vehicle_skill::get_skill_id(void) const
{
    return skill_id_;
}

void vehicle_skill::set_skill_id(SpringCat::int32_t value)
{
    skill_id_ = value;
}

SpringCat::int16_t vehicle_skill::get_skill_lv(void) const
{
    return skill_lv_;
}

void vehicle_skill::set_skill_lv(SpringCat::int16_t value)
{
    skill_lv_ = value;
}

vehicle_parts::vehicle_parts(void)
    : __has_bits__(),
    parts_id_(0),
    level_(0),
    exp_(0),
    need_stuffs_()
{
}

vehicle_parts::vehicle_parts(const vehicle_parts& from)
    : __has_bits__(),
    parts_id_(0),
    level_(0),
    exp_(0),
    need_stuffs_()
{
    merge_from(from);
}

vehicle_parts::~vehicle_parts(void)
{
    // need_stuffs
    need_stuffs_.clear();
}

const SpringCat::Wave::type_info& vehicle_parts::static_type_info(void)
{
    return __vehicle_parts_type_info__;
}

const SpringCat::Wave::type_info& vehicle_parts::runtime_type_info(void) const
{
    return static_type_info();
}

vehicle_parts* vehicle_parts::new_instance(void) const
{
    return new vehicle_parts;
}

vehicle_parts* vehicle_parts::clone(void) const
{
    return new vehicle_parts(*this);
}

void vehicle_parts::clear(void)
{
    // parts_id
    parts_id_ = 0;
    // level
    level_ = 0;
    // exp
    exp_ = 0;
    // need_stuffs
    need_stuffs_.clear();
}

bool vehicle_parts::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t vehicle_parts::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // parts_id
    total_size += SpringCat::Wave::internal::size(parts_id_);
    // level
    total_size += SpringCat::Wave::internal::size(level_);
    // exp
    total_size += SpringCat::Wave::internal::size(exp_);
    // need_stuffs
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint32_t));
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::int32_t) * need_stuffs_.size());
    for(std::map<SpringCat::int32_t, SpringCat::int16_t>::const_iterator it = need_stuffs_.begin(); it != need_stuffs_.end(); ++it)
    {
        total_size += sizeof(it->second);
    }

    return total_size;
}

void vehicle_parts::copy_from(const SpringCat::Wave::object_base& from)
{
    const vehicle_parts& src = dynamic_cast<const vehicle_parts&>(from);
    copy_from(src);
}

void vehicle_parts::copy_from(const vehicle_parts& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void vehicle_parts::merge_from(const SpringCat::Wave::object_base& from)
{
    const vehicle_parts& src = dynamic_cast<const vehicle_parts&>(from);
    merge_from(src);
}

void vehicle_parts::merge_from(const vehicle_parts& from)
{
    if (&from == this)
    {
        return;
    }

    // parts_id
    set_parts_id(from.get_parts_id());
    // level
    set_level(from.get_level());
    // exp
    set_exp(from.get_exp());
    // need_stuffs
    for(std::map<SpringCat::int32_t, SpringCat::int16_t>::const_iterator it = from.need_stuffs_.begin(); it != from.need_stuffs_.end(); ++it)
    {
        insert_need_stuffs(it->first, it->second);
    }
}

bool vehicle_parts::serialize(SpringCat::System::Stream& output) const
{
    // parts_id
    if (SpringCat::Wave::internal::serialize(output, parts_id_) == false)
    {
        return false;
    }
    // level
    if (SpringCat::Wave::internal::serialize(output, level_) == false)
    {
        return false;
    }
    // exp
    if (SpringCat::Wave::internal::serialize(output, exp_) == false)
    {
        return false;
    }
    // need_stuffs
    SpringCat::uint32_t need_stuffs_size = static_cast<SpringCat::uint32_t>(need_stuffs_.size());
    if (SpringCat::Wave::internal::serialize(output, need_stuffs_size) == false)
    {
        return false;
    }
    for(std::map<SpringCat::int32_t, SpringCat::int16_t>::const_iterator it = need_stuffs_.begin(); it != need_stuffs_.end(); ++it)
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

bool vehicle_parts::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool vehicle_parts::serialize(std::string& output) const
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

bool vehicle_parts::deserialize(SpringCat::System::Stream& input)
{
    // parts_id
    if (SpringCat::Wave::internal::deserialize(input, parts_id_) == false)
    {
        return false;
    }
    // level
    if (SpringCat::Wave::internal::deserialize(input, level_) == false)
    {
        return false;
    }
    // exp
    if (SpringCat::Wave::internal::deserialize(input, exp_) == false)
    {
        return false;
    }
    // need_stuffs
    SpringCat::uint32_t need_stuffs_size = 0;
    if (SpringCat::Wave::internal::deserialize(input, need_stuffs_size) == false)
    {
        return false;
    }
    for (SpringCat::uint32_t i = 0; i != need_stuffs_size; ++i)
    {
        SpringCat::int32_t key;
        if (SpringCat::Wave::internal::deserialize(input, key) == false)
        {
            return false;
        }
        SpringCat::int16_t value;
        if (SpringCat::Wave::internal::deserialize(input, value) == false)
        {
            return false;
        }
        insert_need_stuffs(key, value);
    }

    return true;
}

bool vehicle_parts::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool vehicle_parts::deserialize(std::string& input)
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

vehicle_parts_id vehicle_parts::get_parts_id(void) const
{
    return static_cast<vehicle_parts_id>(parts_id_);
}

void vehicle_parts::set_parts_id(vehicle_parts_id value)
{
    parts_id_ = value;
}

SpringCat::int16_t vehicle_parts::get_level(void) const
{
    return level_;
}

void vehicle_parts::set_level(SpringCat::int16_t value)
{
    level_ = value;
}

SpringCat::int16_t vehicle_parts::get_exp(void) const
{
    return exp_;
}

void vehicle_parts::set_exp(SpringCat::int16_t value)
{
    exp_ = value;
}

const std::map<SpringCat::int32_t, SpringCat::int16_t>& vehicle_parts::get_need_stuffs(void) const
{
    return need_stuffs_;
}

std::map<SpringCat::int32_t, SpringCat::int16_t>* vehicle_parts::get_mutable_need_stuffs(void)
{
    return &need_stuffs_;
}

bool vehicle_parts::get_need_stuffs(SpringCat::int32_t key, SpringCat::int16_t* value) const
{
    std::map<SpringCat::int32_t, SpringCat::int16_t>::const_iterator it = need_stuffs_.find(key);
    if(it == need_stuffs_.end())
    {
        return false;
    }

    if(value)
    {
        *value = it->second;
    }

    return true;
}

void vehicle_parts::set_need_stuffs(SpringCat::int32_t key, SpringCat::int16_t value)
{
    need_stuffs_[key] = value;
}

bool vehicle_parts::insert_need_stuffs(SpringCat::int32_t key, SpringCat::int16_t value)
{
    return need_stuffs_.insert(std::make_pair(key, value)).second;
}


vehicle::vehicle(void)
    : __has_bits__(),
    vehicle_no_(0),
    level_(0),
    hold_card_(0),
    skills_(),
    parts_(),
    stat_(new vehicle_stat)
{
}

vehicle::vehicle(const vehicle& from)
    : __has_bits__(),
    vehicle_no_(0),
    level_(0),
    hold_card_(0),
    skills_(),
    parts_(),
    stat_(new vehicle_stat)
{
    merge_from(from);
}

vehicle::~vehicle(void)
{
    // skills
    SpringCat::uint32_t skills_size = static_cast<SpringCat::uint32_t>(skills_.size());
    for (SpringCat::uint32_t i = 0; i != skills_size; ++i)
    {
        delete skills_[i];
    }
    skills_.clear();
    // parts
    SpringCat::uint32_t parts_size = static_cast<SpringCat::uint32_t>(parts_.size());
    for (SpringCat::uint32_t i = 0; i != parts_size; ++i)
    {
        delete parts_[i];
    }
    parts_.clear();
}

const SpringCat::Wave::type_info& vehicle::static_type_info(void)
{
    return __vehicle_type_info__;
}

const SpringCat::Wave::type_info& vehicle::runtime_type_info(void) const
{
    return static_type_info();
}

vehicle* vehicle::new_instance(void) const
{
    return new vehicle;
}

vehicle* vehicle::clone(void) const
{
    return new vehicle(*this);
}

void vehicle::clear(void)
{
    // vehicle_no
    vehicle_no_ = 0;
    // level
    level_ = 0;
    // hold_card
    hold_card_ = 0;
    // skills
    SpringCat::uint32_t skills_size = static_cast<SpringCat::uint32_t>(skills_.size());
    for (SpringCat::uint32_t i = 0; i != skills_size; ++i)
    {
        delete skills_[i];
    }
    skills_.clear();
    // parts
    SpringCat::uint32_t parts_size = static_cast<SpringCat::uint32_t>(parts_.size());
    for (SpringCat::uint32_t i = 0; i != parts_size; ++i)
    {
        delete parts_[i];
    }
    parts_.clear();
    // stat
    stat_->clear();
}

bool vehicle::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t vehicle::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // vehicle_no
    total_size += SpringCat::Wave::internal::size(vehicle_no_);
    // level
    total_size += SpringCat::Wave::internal::size(level_);
    // hold_card
    total_size += SpringCat::Wave::internal::size(hold_card_);
    // skills
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint32_t));
    SpringCat::uint32_t skills_size = static_cast<SpringCat::uint32_t>(skills_.size());
    for (SpringCat::uint32_t i = 0; i != skills_size; ++i)
    {
        total_size += SpringCat::Wave::internal::size(*skills_[i]);
    }
    // parts
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint32_t));
    SpringCat::uint32_t parts_size = static_cast<SpringCat::uint32_t>(parts_.size());
    for (SpringCat::uint32_t i = 0; i != parts_size; ++i)
    {
        total_size += SpringCat::Wave::internal::size(*parts_[i]);
    }
    // stat
    total_size += SpringCat::Wave::internal::size(*stat_);

    return total_size;
}

void vehicle::copy_from(const SpringCat::Wave::object_base& from)
{
    const vehicle& src = dynamic_cast<const vehicle&>(from);
    copy_from(src);
}

void vehicle::copy_from(const vehicle& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void vehicle::merge_from(const SpringCat::Wave::object_base& from)
{
    const vehicle& src = dynamic_cast<const vehicle&>(from);
    merge_from(src);
}

void vehicle::merge_from(const vehicle& from)
{
    if (&from == this)
    {
        return;
    }

    // vehicle_no
    set_vehicle_no(from.get_vehicle_no());
    // level
    set_level(from.get_level());
    // hold_card
    set_hold_card(from.get_hold_card());
    // skills
    SpringCat::uint32_t skills_size = static_cast<SpringCat::uint32_t>(from.skills_.size());
    skills_.reserve(skills_.size() + skills_size);
    for (SpringCat::uint32_t i = 0; i != skills_size; ++i)
    {
        skills_.push_back(from.skills_[i]->clone());
    }
    // parts
    SpringCat::uint32_t parts_size = static_cast<SpringCat::uint32_t>(from.parts_.size());
    parts_.reserve(parts_.size() + parts_size);
    for (SpringCat::uint32_t i = 0; i != parts_size; ++i)
    {
        parts_.push_back(from.parts_[i]->clone());
    }
    // stat
    stat_->merge_from(*from.get_stat());
}

bool vehicle::serialize(SpringCat::System::Stream& output) const
{
    // vehicle_no
    if (SpringCat::Wave::internal::serialize(output, vehicle_no_) == false)
    {
        return false;
    }
    // level
    if (SpringCat::Wave::internal::serialize(output, level_) == false)
    {
        return false;
    }
    // hold_card
    if (SpringCat::Wave::internal::serialize(output, hold_card_) == false)
    {
        return false;
    }
    // skills
    SpringCat::uint32_t skills_size = static_cast<SpringCat::uint32_t>(skills_.size());
    if (SpringCat::Wave::internal::serialize(output, skills_size) == false)
    {
        return false;
    }
    for (SpringCat::uint32_t i = 0; i != skills_size; ++i)
    {
        if (SpringCat::Wave::internal::serialize(output, *skills_[i]) == false)
        {
            return false;
        }
    }
    // parts
    SpringCat::uint32_t parts_size = static_cast<SpringCat::uint32_t>(parts_.size());
    if (SpringCat::Wave::internal::serialize(output, parts_size) == false)
    {
        return false;
    }
    for (SpringCat::uint32_t i = 0; i != parts_size; ++i)
    {
        if (SpringCat::Wave::internal::serialize(output, *parts_[i]) == false)
        {
            return false;
        }
    }
    // stat
    if (SpringCat::Wave::internal::serialize(output, *stat_) == false)
    {
        return false;
    }

    return true;
}

bool vehicle::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool vehicle::serialize(std::string& output) const
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

bool vehicle::deserialize(SpringCat::System::Stream& input)
{
    // vehicle_no
    if (SpringCat::Wave::internal::deserialize(input, vehicle_no_) == false)
    {
        return false;
    }
    // level
    if (SpringCat::Wave::internal::deserialize(input, level_) == false)
    {
        return false;
    }
    // hold_card
    if (SpringCat::Wave::internal::deserialize(input, hold_card_) == false)
    {
        return false;
    }
    // skills
    SpringCat::uint32_t skills_size = 0;
    if (SpringCat::Wave::internal::deserialize(input, skills_size) == false)
    {
        return false;
    }
    if (skills_size > 0)
    {
        skills_.reserve(skills_size);
        for (SpringCat::uint32_t i = 0; i != skills_size; ++i)
        {
            std::auto_ptr<vehicle_skill> new_skills(new vehicle_skill);
            if (SpringCat::Wave::internal::deserialize(input, *new_skills) == false)
            {
                return false;
            }
            skills_.push_back(new_skills.release());
        }
    }
    // parts
    SpringCat::uint32_t parts_size = 0;
    if (SpringCat::Wave::internal::deserialize(input, parts_size) == false)
    {
        return false;
    }
    if (parts_size > 0)
    {
        parts_.reserve(parts_size);
        for (SpringCat::uint32_t i = 0; i != parts_size; ++i)
        {
            std::auto_ptr<vehicle_parts> new_parts(new vehicle_parts);
            if (SpringCat::Wave::internal::deserialize(input, *new_parts) == false)
            {
                return false;
            }
            parts_.push_back(new_parts.release());
        }
    }
    // stat
    if (SpringCat::Wave::internal::deserialize(input, *stat_) == false)
    {
        return false;
    }

    return true;
}

bool vehicle::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool vehicle::deserialize(std::string& input)
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

SpringCat::int32_t vehicle::get_vehicle_no(void) const
{
    return vehicle_no_;
}

void vehicle::set_vehicle_no(SpringCat::int32_t value)
{
    vehicle_no_ = value;
}

vehicle_level vehicle::get_level(void) const
{
    return static_cast<vehicle_level>(level_);
}

void vehicle::set_level(vehicle_level value)
{
    level_ = value;
}

SpringCat::int16_t vehicle::get_hold_card(void) const
{
    return hold_card_;
}

void vehicle::set_hold_card(SpringCat::int16_t value)
{
    hold_card_ = value;
}

const std::vector<vehicle_skill*>& vehicle::get_skills(void) const
{
    return skills_;
}

std::vector<vehicle_skill*>* vehicle::get_mutable_skills(void)
{
    return &skills_;
}

const vehicle_skill* vehicle::get_skills(size_t index) const
{
    if (skills_.size() <= index)
    {
        throw std::out_of_range("vehicle::skills_ index outside range");
    }

    return skills_[index];
}

vehicle_skill* vehicle::get_mutable_skills(size_t index)
{
    if (skills_.size() <= index)
    {
        throw std::out_of_range("vehicle::skills_ index outside range");
    }

    return skills_[index];
}

vehicle_skill* vehicle::add_skills(void)
{
    std::auto_ptr<vehicle_skill> new_skills(new vehicle_skill);
    skills_.push_back(new_skills.get());

    return new_skills.release();
}

const std::vector<vehicle_parts*>& vehicle::get_parts(void) const
{
    return parts_;
}

std::vector<vehicle_parts*>* vehicle::get_mutable_parts(void)
{
    return &parts_;
}

const vehicle_parts* vehicle::get_parts(size_t index) const
{
    if (parts_.size() <= index)
    {
        throw std::out_of_range("vehicle::parts_ index outside range");
    }

    return parts_[index];
}

vehicle_parts* vehicle::get_mutable_parts(size_t index)
{
    if (parts_.size() <= index)
    {
        throw std::out_of_range("vehicle::parts_ index outside range");
    }

    return parts_[index];
}

vehicle_parts* vehicle::add_parts(void)
{
    std::auto_ptr<vehicle_parts> new_parts(new vehicle_parts);
    parts_.push_back(new_parts.get());

    return new_parts.release();
}

const vehicle_stat* vehicle::get_stat(void) const
{
    return stat_.get();
}

vehicle_stat* vehicle::get_mutable_stat(void)
{
    return stat_.get();
}

vehicle_list::vehicle_list(void)
    : __has_bits__(),
    infos_()
{
}

vehicle_list::vehicle_list(const vehicle_list& from)
    : __has_bits__(),
    infos_()
{
    merge_from(from);
}

vehicle_list::~vehicle_list(void)
{
    // infos
    SpringCat::uint32_t infos_size = static_cast<SpringCat::uint32_t>(infos_.size());
    for (SpringCat::uint32_t i = 0; i != infos_size; ++i)
    {
        delete infos_[i];
    }
    infos_.clear();
}

const SpringCat::Wave::type_info& vehicle_list::static_type_info(void)
{
    return __vehicle_list_type_info__;
}

const SpringCat::Wave::type_info& vehicle_list::runtime_type_info(void) const
{
    return static_type_info();
}

vehicle_list* vehicle_list::new_instance(void) const
{
    return new vehicle_list;
}

vehicle_list* vehicle_list::clone(void) const
{
    return new vehicle_list(*this);
}

void vehicle_list::clear(void)
{
    // infos
    SpringCat::uint32_t infos_size = static_cast<SpringCat::uint32_t>(infos_.size());
    for (SpringCat::uint32_t i = 0; i != infos_size; ++i)
    {
        delete infos_[i];
    }
    infos_.clear();
}

bool vehicle_list::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t vehicle_list::size(void) const
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

void vehicle_list::copy_from(const SpringCat::Wave::object_base& from)
{
    const vehicle_list& src = dynamic_cast<const vehicle_list&>(from);
    copy_from(src);
}

void vehicle_list::copy_from(const vehicle_list& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void vehicle_list::merge_from(const SpringCat::Wave::object_base& from)
{
    const vehicle_list& src = dynamic_cast<const vehicle_list&>(from);
    merge_from(src);
}

void vehicle_list::merge_from(const vehicle_list& from)
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

bool vehicle_list::serialize(SpringCat::System::Stream& output) const
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

bool vehicle_list::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool vehicle_list::serialize(std::string& output) const
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

bool vehicle_list::deserialize(SpringCat::System::Stream& input)
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
            std::auto_ptr<vehicle> new_infos(new vehicle);
            if (SpringCat::Wave::internal::deserialize(input, *new_infos) == false)
            {
                return false;
            }
            infos_.push_back(new_infos.release());
        }
    }

    return true;
}

bool vehicle_list::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool vehicle_list::deserialize(std::string& input)
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

const std::vector<vehicle*>& vehicle_list::get_infos(void) const
{
    return infos_;
}

std::vector<vehicle*>* vehicle_list::get_mutable_infos(void)
{
    return &infos_;
}

const vehicle* vehicle_list::get_infos(size_t index) const
{
    if (infos_.size() <= index)
    {
        throw std::out_of_range("vehicle_list::infos_ index outside range");
    }

    return infos_[index];
}

vehicle* vehicle_list::get_mutable_infos(size_t index)
{
    if (infos_.size() <= index)
    {
        throw std::out_of_range("vehicle_list::infos_ index outside range");
    }

    return infos_[index];
}

vehicle* vehicle_list::add_infos(void)
{
    std::auto_ptr<vehicle> new_infos(new vehicle);
    infos_.push_back(new_infos.get());

    return new_infos.release();
}

vehicle_list_req::vehicle_list_req(void)
    : __has_bits__(),
    player_no_(0)
{
}

vehicle_list_req::vehicle_list_req(const vehicle_list_req& from)
    : __has_bits__(),
    player_no_(0)
{
    merge_from(from);
}

vehicle_list_req::~vehicle_list_req(void)
{
}

const SpringCat::Wave::type_info& vehicle_list_req::static_type_info(void)
{
    return __vehicle_list_req_type_info__;
}

const SpringCat::Wave::type_info& vehicle_list_req::runtime_type_info(void) const
{
    return static_type_info();
}

vehicle_list_req* vehicle_list_req::new_instance(void) const
{
    return new vehicle_list_req;
}

vehicle_list_req* vehicle_list_req::clone(void) const
{
    return new vehicle_list_req(*this);
}

void vehicle_list_req::clear(void)
{
    // player_no
    player_no_ = 0;
}

bool vehicle_list_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t vehicle_list_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // player_no
    total_size += SpringCat::Wave::internal::size(player_no_);

    return total_size;
}

void vehicle_list_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const vehicle_list_req& src = dynamic_cast<const vehicle_list_req&>(from);
    copy_from(src);
}

void vehicle_list_req::copy_from(const vehicle_list_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void vehicle_list_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const vehicle_list_req& src = dynamic_cast<const vehicle_list_req&>(from);
    merge_from(src);
}

void vehicle_list_req::merge_from(const vehicle_list_req& from)
{
    if (&from == this)
    {
        return;
    }

    // player_no
    set_player_no(from.get_player_no());
}

bool vehicle_list_req::serialize(SpringCat::System::Stream& output) const
{
    // player_no
    if (SpringCat::Wave::internal::serialize(output, player_no_) == false)
    {
        return false;
    }

    return true;
}

bool vehicle_list_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool vehicle_list_req::serialize(std::string& output) const
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

bool vehicle_list_req::deserialize(SpringCat::System::Stream& input)
{
    // player_no
    if (SpringCat::Wave::internal::deserialize(input, player_no_) == false)
    {
        return false;
    }

    return true;
}

bool vehicle_list_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool vehicle_list_req::deserialize(std::string& input)
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

SpringCat::uint64_t vehicle_list_req::get_player_no(void) const
{
    return player_no_;
}

void vehicle_list_req::set_player_no(SpringCat::uint64_t value)
{
    player_no_ = value;
}

vehicle_list_ans::vehicle_list_ans(void)
    : __has_bits__(),
    result_(0),
    infos_(new vehicle_list),
    selected_vehicle_no_(0),
    stuffs_(new vehicle_stuff)
{
}

vehicle_list_ans::vehicle_list_ans(const vehicle_list_ans& from)
    : __has_bits__(),
    result_(0),
    infos_(new vehicle_list),
    selected_vehicle_no_(0),
    stuffs_(new vehicle_stuff)
{
    merge_from(from);
}

vehicle_list_ans::~vehicle_list_ans(void)
{
}

const SpringCat::Wave::type_info& vehicle_list_ans::static_type_info(void)
{
    return __vehicle_list_ans_type_info__;
}

const SpringCat::Wave::type_info& vehicle_list_ans::runtime_type_info(void) const
{
    return static_type_info();
}

vehicle_list_ans* vehicle_list_ans::new_instance(void) const
{
    return new vehicle_list_ans;
}

vehicle_list_ans* vehicle_list_ans::clone(void) const
{
    return new vehicle_list_ans(*this);
}

void vehicle_list_ans::clear(void)
{
    // result
    result_ = 0;
    // infos
    infos_->clear();
    // selected_vehicle_no
    selected_vehicle_no_ = 0;
    // stuffs
    stuffs_->clear();
}

bool vehicle_list_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t vehicle_list_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // infos
    total_size += SpringCat::Wave::internal::size(*infos_);
    // selected_vehicle_no
    total_size += SpringCat::Wave::internal::size(selected_vehicle_no_);
    // stuffs
    total_size += SpringCat::Wave::internal::size(*stuffs_);

    return total_size;
}

void vehicle_list_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const vehicle_list_ans& src = dynamic_cast<const vehicle_list_ans&>(from);
    copy_from(src);
}

void vehicle_list_ans::copy_from(const vehicle_list_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void vehicle_list_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const vehicle_list_ans& src = dynamic_cast<const vehicle_list_ans&>(from);
    merge_from(src);
}

void vehicle_list_ans::merge_from(const vehicle_list_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // infos
    infos_->merge_from(*from.get_infos());
    // selected_vehicle_no
    set_selected_vehicle_no(from.get_selected_vehicle_no());
    // stuffs
    stuffs_->merge_from(*from.get_stuffs());
}

bool vehicle_list_ans::serialize(SpringCat::System::Stream& output) const
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
    // selected_vehicle_no
    if (SpringCat::Wave::internal::serialize(output, selected_vehicle_no_) == false)
    {
        return false;
    }
    // stuffs
    if (SpringCat::Wave::internal::serialize(output, *stuffs_) == false)
    {
        return false;
    }

    return true;
}

bool vehicle_list_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool vehicle_list_ans::serialize(std::string& output) const
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

bool vehicle_list_ans::deserialize(SpringCat::System::Stream& input)
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
    // selected_vehicle_no
    if (SpringCat::Wave::internal::deserialize(input, selected_vehicle_no_) == false)
    {
        return false;
    }
    // stuffs
    if (SpringCat::Wave::internal::deserialize(input, *stuffs_) == false)
    {
        return false;
    }

    return true;
}

bool vehicle_list_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool vehicle_list_ans::deserialize(std::string& input)
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

SpringCat::int16_t vehicle_list_ans::get_result(void) const
{
    return result_;
}

void vehicle_list_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

const vehicle_list* vehicle_list_ans::get_infos(void) const
{
    return infos_.get();
}

vehicle_list* vehicle_list_ans::get_mutable_infos(void)
{
    return infos_.get();
}

SpringCat::int32_t vehicle_list_ans::get_selected_vehicle_no(void) const
{
    return selected_vehicle_no_;
}

void vehicle_list_ans::set_selected_vehicle_no(SpringCat::int32_t value)
{
    selected_vehicle_no_ = value;
}

const vehicle_stuff* vehicle_list_ans::get_stuffs(void) const
{
    return stuffs_.get();
}

vehicle_stuff* vehicle_list_ans::get_mutable_stuffs(void)
{
    return stuffs_.get();
}

vehicle_select_req::vehicle_select_req(void)
    : __has_bits__(),
    vehicle_no_(0)
{
}

vehicle_select_req::vehicle_select_req(const vehicle_select_req& from)
    : __has_bits__(),
    vehicle_no_(0)
{
    merge_from(from);
}

vehicle_select_req::~vehicle_select_req(void)
{
}

const SpringCat::Wave::type_info& vehicle_select_req::static_type_info(void)
{
    return __vehicle_select_req_type_info__;
}

const SpringCat::Wave::type_info& vehicle_select_req::runtime_type_info(void) const
{
    return static_type_info();
}

vehicle_select_req* vehicle_select_req::new_instance(void) const
{
    return new vehicle_select_req;
}

vehicle_select_req* vehicle_select_req::clone(void) const
{
    return new vehicle_select_req(*this);
}

void vehicle_select_req::clear(void)
{
    // vehicle_no
    vehicle_no_ = 0;
}

bool vehicle_select_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t vehicle_select_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // vehicle_no
    total_size += SpringCat::Wave::internal::size(vehicle_no_);

    return total_size;
}

void vehicle_select_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const vehicle_select_req& src = dynamic_cast<const vehicle_select_req&>(from);
    copy_from(src);
}

void vehicle_select_req::copy_from(const vehicle_select_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void vehicle_select_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const vehicle_select_req& src = dynamic_cast<const vehicle_select_req&>(from);
    merge_from(src);
}

void vehicle_select_req::merge_from(const vehicle_select_req& from)
{
    if (&from == this)
    {
        return;
    }

    // vehicle_no
    set_vehicle_no(from.get_vehicle_no());
}

bool vehicle_select_req::serialize(SpringCat::System::Stream& output) const
{
    // vehicle_no
    if (SpringCat::Wave::internal::serialize(output, vehicle_no_) == false)
    {
        return false;
    }

    return true;
}

bool vehicle_select_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool vehicle_select_req::serialize(std::string& output) const
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

bool vehicle_select_req::deserialize(SpringCat::System::Stream& input)
{
    // vehicle_no
    if (SpringCat::Wave::internal::deserialize(input, vehicle_no_) == false)
    {
        return false;
    }

    return true;
}

bool vehicle_select_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool vehicle_select_req::deserialize(std::string& input)
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

SpringCat::int32_t vehicle_select_req::get_vehicle_no(void) const
{
    return vehicle_no_;
}

void vehicle_select_req::set_vehicle_no(SpringCat::int32_t value)
{
    vehicle_no_ = value;
}

vehicle_select_ans::vehicle_select_ans(void)
    : __has_bits__(),
    result_(0),
    selected_vehicle_no_(0)
{
}

vehicle_select_ans::vehicle_select_ans(const vehicle_select_ans& from)
    : __has_bits__(),
    result_(0),
    selected_vehicle_no_(0)
{
    merge_from(from);
}

vehicle_select_ans::~vehicle_select_ans(void)
{
}

const SpringCat::Wave::type_info& vehicle_select_ans::static_type_info(void)
{
    return __vehicle_select_ans_type_info__;
}

const SpringCat::Wave::type_info& vehicle_select_ans::runtime_type_info(void) const
{
    return static_type_info();
}

vehicle_select_ans* vehicle_select_ans::new_instance(void) const
{
    return new vehicle_select_ans;
}

vehicle_select_ans* vehicle_select_ans::clone(void) const
{
    return new vehicle_select_ans(*this);
}

void vehicle_select_ans::clear(void)
{
    // result
    result_ = 0;
    // selected_vehicle_no
    selected_vehicle_no_ = 0;
}

bool vehicle_select_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t vehicle_select_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // selected_vehicle_no
    total_size += SpringCat::Wave::internal::size(selected_vehicle_no_);

    return total_size;
}

void vehicle_select_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const vehicle_select_ans& src = dynamic_cast<const vehicle_select_ans&>(from);
    copy_from(src);
}

void vehicle_select_ans::copy_from(const vehicle_select_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void vehicle_select_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const vehicle_select_ans& src = dynamic_cast<const vehicle_select_ans&>(from);
    merge_from(src);
}

void vehicle_select_ans::merge_from(const vehicle_select_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // selected_vehicle_no
    set_selected_vehicle_no(from.get_selected_vehicle_no());
}

bool vehicle_select_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // selected_vehicle_no
    if (SpringCat::Wave::internal::serialize(output, selected_vehicle_no_) == false)
    {
        return false;
    }

    return true;
}

bool vehicle_select_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool vehicle_select_ans::serialize(std::string& output) const
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

bool vehicle_select_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // selected_vehicle_no
    if (SpringCat::Wave::internal::deserialize(input, selected_vehicle_no_) == false)
    {
        return false;
    }

    return true;
}

bool vehicle_select_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool vehicle_select_ans::deserialize(std::string& input)
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

SpringCat::int16_t vehicle_select_ans::get_result(void) const
{
    return result_;
}

void vehicle_select_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

SpringCat::int32_t vehicle_select_ans::get_selected_vehicle_no(void) const
{
    return selected_vehicle_no_;
}

void vehicle_select_ans::set_selected_vehicle_no(SpringCat::int32_t value)
{
    selected_vehicle_no_ = value;
}

vehicle_upgrade_req::vehicle_upgrade_req(void)
    : __has_bits__(),
    vehicle_no_(0)
{
}

vehicle_upgrade_req::vehicle_upgrade_req(const vehicle_upgrade_req& from)
    : __has_bits__(),
    vehicle_no_(0)
{
    merge_from(from);
}

vehicle_upgrade_req::~vehicle_upgrade_req(void)
{
}

const SpringCat::Wave::type_info& vehicle_upgrade_req::static_type_info(void)
{
    return __vehicle_upgrade_req_type_info__;
}

const SpringCat::Wave::type_info& vehicle_upgrade_req::runtime_type_info(void) const
{
    return static_type_info();
}

vehicle_upgrade_req* vehicle_upgrade_req::new_instance(void) const
{
    return new vehicle_upgrade_req;
}

vehicle_upgrade_req* vehicle_upgrade_req::clone(void) const
{
    return new vehicle_upgrade_req(*this);
}

void vehicle_upgrade_req::clear(void)
{
    // vehicle_no
    vehicle_no_ = 0;
}

bool vehicle_upgrade_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t vehicle_upgrade_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // vehicle_no
    total_size += SpringCat::Wave::internal::size(vehicle_no_);

    return total_size;
}

void vehicle_upgrade_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const vehicle_upgrade_req& src = dynamic_cast<const vehicle_upgrade_req&>(from);
    copy_from(src);
}

void vehicle_upgrade_req::copy_from(const vehicle_upgrade_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void vehicle_upgrade_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const vehicle_upgrade_req& src = dynamic_cast<const vehicle_upgrade_req&>(from);
    merge_from(src);
}

void vehicle_upgrade_req::merge_from(const vehicle_upgrade_req& from)
{
    if (&from == this)
    {
        return;
    }

    // vehicle_no
    set_vehicle_no(from.get_vehicle_no());
}

bool vehicle_upgrade_req::serialize(SpringCat::System::Stream& output) const
{
    // vehicle_no
    if (SpringCat::Wave::internal::serialize(output, vehicle_no_) == false)
    {
        return false;
    }

    return true;
}

bool vehicle_upgrade_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool vehicle_upgrade_req::serialize(std::string& output) const
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

bool vehicle_upgrade_req::deserialize(SpringCat::System::Stream& input)
{
    // vehicle_no
    if (SpringCat::Wave::internal::deserialize(input, vehicle_no_) == false)
    {
        return false;
    }

    return true;
}

bool vehicle_upgrade_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool vehicle_upgrade_req::deserialize(std::string& input)
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

SpringCat::int32_t vehicle_upgrade_req::get_vehicle_no(void) const
{
    return vehicle_no_;
}

void vehicle_upgrade_req::set_vehicle_no(SpringCat::int32_t value)
{
    vehicle_no_ = value;
}

vehicle_upgrade_ans::vehicle_upgrade_ans(void)
    : __has_bits__(),
    result_(0),
    updated_vehicle_(new vehicle)
{
}

vehicle_upgrade_ans::vehicle_upgrade_ans(const vehicle_upgrade_ans& from)
    : __has_bits__(),
    result_(0),
    updated_vehicle_(new vehicle)
{
    merge_from(from);
}

vehicle_upgrade_ans::~vehicle_upgrade_ans(void)
{
}

const SpringCat::Wave::type_info& vehicle_upgrade_ans::static_type_info(void)
{
    return __vehicle_upgrade_ans_type_info__;
}

const SpringCat::Wave::type_info& vehicle_upgrade_ans::runtime_type_info(void) const
{
    return static_type_info();
}

vehicle_upgrade_ans* vehicle_upgrade_ans::new_instance(void) const
{
    return new vehicle_upgrade_ans;
}

vehicle_upgrade_ans* vehicle_upgrade_ans::clone(void) const
{
    return new vehicle_upgrade_ans(*this);
}

void vehicle_upgrade_ans::clear(void)
{
    // result
    result_ = 0;
    // updated_vehicle
    updated_vehicle_->clear();
}

bool vehicle_upgrade_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t vehicle_upgrade_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // updated_vehicle
    total_size += SpringCat::Wave::internal::size(*updated_vehicle_);

    return total_size;
}

void vehicle_upgrade_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const vehicle_upgrade_ans& src = dynamic_cast<const vehicle_upgrade_ans&>(from);
    copy_from(src);
}

void vehicle_upgrade_ans::copy_from(const vehicle_upgrade_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void vehicle_upgrade_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const vehicle_upgrade_ans& src = dynamic_cast<const vehicle_upgrade_ans&>(from);
    merge_from(src);
}

void vehicle_upgrade_ans::merge_from(const vehicle_upgrade_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // updated_vehicle
    updated_vehicle_->merge_from(*from.get_updated_vehicle());
}

bool vehicle_upgrade_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // updated_vehicle
    if (SpringCat::Wave::internal::serialize(output, *updated_vehicle_) == false)
    {
        return false;
    }

    return true;
}

bool vehicle_upgrade_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool vehicle_upgrade_ans::serialize(std::string& output) const
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

bool vehicle_upgrade_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // updated_vehicle
    if (SpringCat::Wave::internal::deserialize(input, *updated_vehicle_) == false)
    {
        return false;
    }

    return true;
}

bool vehicle_upgrade_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool vehicle_upgrade_ans::deserialize(std::string& input)
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

SpringCat::int16_t vehicle_upgrade_ans::get_result(void) const
{
    return result_;
}

void vehicle_upgrade_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

const vehicle* vehicle_upgrade_ans::get_updated_vehicle(void) const
{
    return updated_vehicle_.get();
}

vehicle* vehicle_upgrade_ans::get_mutable_updated_vehicle(void)
{
    return updated_vehicle_.get();
}

vehicle_parts_tuning_req::vehicle_parts_tuning_req(void)
    : __has_bits__(),
    vehicle_no_(0),
    parts_id_(0)
{
}

vehicle_parts_tuning_req::vehicle_parts_tuning_req(const vehicle_parts_tuning_req& from)
    : __has_bits__(),
    vehicle_no_(0),
    parts_id_(0)
{
    merge_from(from);
}

vehicle_parts_tuning_req::~vehicle_parts_tuning_req(void)
{
}

const SpringCat::Wave::type_info& vehicle_parts_tuning_req::static_type_info(void)
{
    return __vehicle_parts_tuning_req_type_info__;
}

const SpringCat::Wave::type_info& vehicle_parts_tuning_req::runtime_type_info(void) const
{
    return static_type_info();
}

vehicle_parts_tuning_req* vehicle_parts_tuning_req::new_instance(void) const
{
    return new vehicle_parts_tuning_req;
}

vehicle_parts_tuning_req* vehicle_parts_tuning_req::clone(void) const
{
    return new vehicle_parts_tuning_req(*this);
}

void vehicle_parts_tuning_req::clear(void)
{
    // vehicle_no
    vehicle_no_ = 0;
    // parts_id
    parts_id_ = 0;
}

bool vehicle_parts_tuning_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t vehicle_parts_tuning_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // vehicle_no
    total_size += SpringCat::Wave::internal::size(vehicle_no_);
    // parts_id
    total_size += SpringCat::Wave::internal::size(parts_id_);

    return total_size;
}

void vehicle_parts_tuning_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const vehicle_parts_tuning_req& src = dynamic_cast<const vehicle_parts_tuning_req&>(from);
    copy_from(src);
}

void vehicle_parts_tuning_req::copy_from(const vehicle_parts_tuning_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void vehicle_parts_tuning_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const vehicle_parts_tuning_req& src = dynamic_cast<const vehicle_parts_tuning_req&>(from);
    merge_from(src);
}

void vehicle_parts_tuning_req::merge_from(const vehicle_parts_tuning_req& from)
{
    if (&from == this)
    {
        return;
    }

    // vehicle_no
    set_vehicle_no(from.get_vehicle_no());
    // parts_id
    set_parts_id(from.get_parts_id());
}

bool vehicle_parts_tuning_req::serialize(SpringCat::System::Stream& output) const
{
    // vehicle_no
    if (SpringCat::Wave::internal::serialize(output, vehicle_no_) == false)
    {
        return false;
    }
    // parts_id
    if (SpringCat::Wave::internal::serialize(output, parts_id_) == false)
    {
        return false;
    }

    return true;
}

bool vehicle_parts_tuning_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool vehicle_parts_tuning_req::serialize(std::string& output) const
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

bool vehicle_parts_tuning_req::deserialize(SpringCat::System::Stream& input)
{
    // vehicle_no
    if (SpringCat::Wave::internal::deserialize(input, vehicle_no_) == false)
    {
        return false;
    }
    // parts_id
    if (SpringCat::Wave::internal::deserialize(input, parts_id_) == false)
    {
        return false;
    }

    return true;
}

bool vehicle_parts_tuning_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool vehicle_parts_tuning_req::deserialize(std::string& input)
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

SpringCat::int32_t vehicle_parts_tuning_req::get_vehicle_no(void) const
{
    return vehicle_no_;
}

void vehicle_parts_tuning_req::set_vehicle_no(SpringCat::int32_t value)
{
    vehicle_no_ = value;
}

vehicle_parts_id vehicle_parts_tuning_req::get_parts_id(void) const
{
    return static_cast<vehicle_parts_id>(parts_id_);
}

void vehicle_parts_tuning_req::set_parts_id(vehicle_parts_id value)
{
    parts_id_ = value;
}

vehicle_parts_tuning_ans::vehicle_parts_tuning_ans(void)
    : __has_bits__(),
    result_(0),
    updated_vehicle_(new vehicle),
    updated_stuffs_(new vehicle_stuff)
{
}

vehicle_parts_tuning_ans::vehicle_parts_tuning_ans(const vehicle_parts_tuning_ans& from)
    : __has_bits__(),
    result_(0),
    updated_vehicle_(new vehicle),
    updated_stuffs_(new vehicle_stuff)
{
    merge_from(from);
}

vehicle_parts_tuning_ans::~vehicle_parts_tuning_ans(void)
{
}

const SpringCat::Wave::type_info& vehicle_parts_tuning_ans::static_type_info(void)
{
    return __vehicle_parts_tuning_ans_type_info__;
}

const SpringCat::Wave::type_info& vehicle_parts_tuning_ans::runtime_type_info(void) const
{
    return static_type_info();
}

vehicle_parts_tuning_ans* vehicle_parts_tuning_ans::new_instance(void) const
{
    return new vehicle_parts_tuning_ans;
}

vehicle_parts_tuning_ans* vehicle_parts_tuning_ans::clone(void) const
{
    return new vehicle_parts_tuning_ans(*this);
}

void vehicle_parts_tuning_ans::clear(void)
{
    // result
    result_ = 0;
    // updated_vehicle
    updated_vehicle_->clear();
    // updated_stuffs
    updated_stuffs_->clear();
}

bool vehicle_parts_tuning_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t vehicle_parts_tuning_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // updated_vehicle
    total_size += SpringCat::Wave::internal::size(*updated_vehicle_);
    // updated_stuffs
    total_size += SpringCat::Wave::internal::size(*updated_stuffs_);

    return total_size;
}

void vehicle_parts_tuning_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const vehicle_parts_tuning_ans& src = dynamic_cast<const vehicle_parts_tuning_ans&>(from);
    copy_from(src);
}

void vehicle_parts_tuning_ans::copy_from(const vehicle_parts_tuning_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void vehicle_parts_tuning_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const vehicle_parts_tuning_ans& src = dynamic_cast<const vehicle_parts_tuning_ans&>(from);
    merge_from(src);
}

void vehicle_parts_tuning_ans::merge_from(const vehicle_parts_tuning_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // updated_vehicle
    updated_vehicle_->merge_from(*from.get_updated_vehicle());
    // updated_stuffs
    updated_stuffs_->merge_from(*from.get_updated_stuffs());
}

bool vehicle_parts_tuning_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // updated_vehicle
    if (SpringCat::Wave::internal::serialize(output, *updated_vehicle_) == false)
    {
        return false;
    }
    // updated_stuffs
    if (SpringCat::Wave::internal::serialize(output, *updated_stuffs_) == false)
    {
        return false;
    }

    return true;
}

bool vehicle_parts_tuning_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool vehicle_parts_tuning_ans::serialize(std::string& output) const
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

bool vehicle_parts_tuning_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // updated_vehicle
    if (SpringCat::Wave::internal::deserialize(input, *updated_vehicle_) == false)
    {
        return false;
    }
    // updated_stuffs
    if (SpringCat::Wave::internal::deserialize(input, *updated_stuffs_) == false)
    {
        return false;
    }

    return true;
}

bool vehicle_parts_tuning_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool vehicle_parts_tuning_ans::deserialize(std::string& input)
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

SpringCat::int16_t vehicle_parts_tuning_ans::get_result(void) const
{
    return result_;
}

void vehicle_parts_tuning_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

const vehicle* vehicle_parts_tuning_ans::get_updated_vehicle(void) const
{
    return updated_vehicle_.get();
}

vehicle* vehicle_parts_tuning_ans::get_mutable_updated_vehicle(void)
{
    return updated_vehicle_.get();
}

const vehicle_stuff* vehicle_parts_tuning_ans::get_updated_stuffs(void) const
{
    return updated_stuffs_.get();
}

vehicle_stuff* vehicle_parts_tuning_ans::get_mutable_updated_stuffs(void)
{
    return updated_stuffs_.get();
}



}    // namespace protocol
