#include "common_def.dc.h"
#include <stdexcept>


namespace protocol
{

// class name: match_item_info, type id(decimal): 262380735, type id(hex): 0xFA39CBF
static const SpringCat::Wave::type_info __match_item_info_type_info__(0xFA39CBF, "protocol.match_item_info");
// class name: reward_info, type id(decimal): 11957871, type id(hex): 0xB6766F
static const SpringCat::Wave::type_info __reward_info_type_info__(0xB6766F, "protocol.reward_info");
// class name: server_address, type id(decimal): 247843283, type id(hex): 0xEC5C9D3
static const SpringCat::Wave::type_info __server_address_type_info__(0xEC5C9D3, "protocol.server_address");
// class name: asset_info, type id(decimal): 237493167, type id(hex): 0xE27DBAF
static const SpringCat::Wave::type_info __asset_info_type_info__(0xE27DBAF, "protocol.asset_info");

match_item_info::match_item_info(void)
    : __has_bits__(),
    infos_()
{
}

match_item_info::match_item_info(const match_item_info& from)
    : __has_bits__(),
    infos_()
{
    merge_from(from);
}

match_item_info::~match_item_info(void)
{
    // infos
    infos_.clear();
}

const SpringCat::Wave::type_info& match_item_info::static_type_info(void)
{
    return __match_item_info_type_info__;
}

const SpringCat::Wave::type_info& match_item_info::runtime_type_info(void) const
{
    return static_type_info();
}

match_item_info* match_item_info::new_instance(void) const
{
    return new match_item_info;
}

match_item_info* match_item_info::clone(void) const
{
    return new match_item_info(*this);
}

void match_item_info::clear(void)
{
    // infos
    infos_.clear();
}

bool match_item_info::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t match_item_info::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // infos
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint32_t));
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::int32_t) * infos_.size());
    for(std::map<SpringCat::int32_t, SpringCat::int16_t>::const_iterator it = infos_.begin(); it != infos_.end(); ++it)
    {
        total_size += sizeof(it->second);
    }

    return total_size;
}

void match_item_info::copy_from(const SpringCat::Wave::object_base& from)
{
    const match_item_info& src = dynamic_cast<const match_item_info&>(from);
    copy_from(src);
}

void match_item_info::copy_from(const match_item_info& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void match_item_info::merge_from(const SpringCat::Wave::object_base& from)
{
    const match_item_info& src = dynamic_cast<const match_item_info&>(from);
    merge_from(src);
}

void match_item_info::merge_from(const match_item_info& from)
{
    if (&from == this)
    {
        return;
    }

    // infos
    for(std::map<SpringCat::int32_t, SpringCat::int16_t>::const_iterator it = from.infos_.begin(); it != from.infos_.end(); ++it)
    {
        insert_infos(it->first, it->second);
    }
}

bool match_item_info::serialize(SpringCat::System::Stream& output) const
{
    // infos
    SpringCat::uint32_t infos_size = static_cast<SpringCat::uint32_t>(infos_.size());
    if (SpringCat::Wave::internal::serialize(output, infos_size) == false)
    {
        return false;
    }
    for(std::map<SpringCat::int32_t, SpringCat::int16_t>::const_iterator it = infos_.begin(); it != infos_.end(); ++it)
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

bool match_item_info::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool match_item_info::serialize(std::string& output) const
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

bool match_item_info::deserialize(SpringCat::System::Stream& input)
{
    // infos
    SpringCat::uint32_t infos_size = 0;
    if (SpringCat::Wave::internal::deserialize(input, infos_size) == false)
    {
        return false;
    }
    for (SpringCat::uint32_t i = 0; i != infos_size; ++i)
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
        insert_infos(key, value);
    }

    return true;
}

bool match_item_info::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool match_item_info::deserialize(std::string& input)
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

const std::map<SpringCat::int32_t, SpringCat::int16_t>& match_item_info::get_infos(void) const
{
    return infos_;
}

std::map<SpringCat::int32_t, SpringCat::int16_t>* match_item_info::get_mutable_infos(void)
{
    return &infos_;
}

bool match_item_info::get_infos(SpringCat::int32_t key, SpringCat::int16_t* value) const
{
    std::map<SpringCat::int32_t, SpringCat::int16_t>::const_iterator it = infos_.find(key);
    if(it == infos_.end())
    {
        return false;
    }

    if(value)
    {
        *value = it->second;
    }

    return true;
}

void match_item_info::set_infos(SpringCat::int32_t key, SpringCat::int16_t value)
{
    infos_[key] = value;
}

bool match_item_info::insert_infos(SpringCat::int32_t key, SpringCat::int16_t value)
{
    return infos_.insert(std::make_pair(key, value)).second;
}


reward_info::reward_info(void)
    : __has_bits__(),
    type_(0),
    specific_id_(0),
    quantity_(0)
{
}

reward_info::reward_info(const reward_info& from)
    : __has_bits__(),
    type_(0),
    specific_id_(0),
    quantity_(0)
{
    merge_from(from);
}

reward_info::~reward_info(void)
{
}

const SpringCat::Wave::type_info& reward_info::static_type_info(void)
{
    return __reward_info_type_info__;
}

const SpringCat::Wave::type_info& reward_info::runtime_type_info(void) const
{
    return static_type_info();
}

reward_info* reward_info::new_instance(void) const
{
    return new reward_info;
}

reward_info* reward_info::clone(void) const
{
    return new reward_info(*this);
}

void reward_info::clear(void)
{
    // type
    type_ = 0;
    // specific_id
    specific_id_ = 0;
    // quantity
    quantity_ = 0;
}

bool reward_info::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t reward_info::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // type
    total_size += SpringCat::Wave::internal::size(type_);
    // specific_id
    total_size += SpringCat::Wave::internal::size(specific_id_);
    // quantity
    total_size += SpringCat::Wave::internal::size(quantity_);

    return total_size;
}

void reward_info::copy_from(const SpringCat::Wave::object_base& from)
{
    const reward_info& src = dynamic_cast<const reward_info&>(from);
    copy_from(src);
}

void reward_info::copy_from(const reward_info& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void reward_info::merge_from(const SpringCat::Wave::object_base& from)
{
    const reward_info& src = dynamic_cast<const reward_info&>(from);
    merge_from(src);
}

void reward_info::merge_from(const reward_info& from)
{
    if (&from == this)
    {
        return;
    }

    // type
    set_type(from.get_type());
    // specific_id
    set_specific_id(from.get_specific_id());
    // quantity
    set_quantity(from.get_quantity());
}

bool reward_info::serialize(SpringCat::System::Stream& output) const
{
    // type
    if (SpringCat::Wave::internal::serialize(output, type_) == false)
    {
        return false;
    }
    // specific_id
    if (SpringCat::Wave::internal::serialize(output, specific_id_) == false)
    {
        return false;
    }
    // quantity
    if (SpringCat::Wave::internal::serialize(output, quantity_) == false)
    {
        return false;
    }

    return true;
}

bool reward_info::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool reward_info::serialize(std::string& output) const
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

bool reward_info::deserialize(SpringCat::System::Stream& input)
{
    // type
    if (SpringCat::Wave::internal::deserialize(input, type_) == false)
    {
        return false;
    }
    // specific_id
    if (SpringCat::Wave::internal::deserialize(input, specific_id_) == false)
    {
        return false;
    }
    // quantity
    if (SpringCat::Wave::internal::deserialize(input, quantity_) == false)
    {
        return false;
    }

    return true;
}

bool reward_info::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool reward_info::deserialize(std::string& input)
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

RewardType reward_info::get_type(void) const
{
    return static_cast<RewardType>(type_);
}

void reward_info::set_type(RewardType value)
{
    type_ = value;
}

SpringCat::int32_t reward_info::get_specific_id(void) const
{
    return specific_id_;
}

void reward_info::set_specific_id(SpringCat::int32_t value)
{
    specific_id_ = value;
}

SpringCat::int32_t reward_info::get_quantity(void) const
{
    return quantity_;
}

void reward_info::set_quantity(SpringCat::int32_t value)
{
    quantity_ = value;
}

server_address::server_address(void)
    : __has_bits__(),
    domain_(),
    port_(0)
{
}

server_address::server_address(const server_address& from)
    : __has_bits__(),
    domain_(),
    port_(0)
{
    merge_from(from);
}

server_address::~server_address(void)
{
}

const SpringCat::Wave::type_info& server_address::static_type_info(void)
{
    return __server_address_type_info__;
}

const SpringCat::Wave::type_info& server_address::runtime_type_info(void) const
{
    return static_type_info();
}

server_address* server_address::new_instance(void) const
{
    return new server_address;
}

server_address* server_address::clone(void) const
{
    return new server_address(*this);
}

void server_address::clear(void)
{
    // domain
    domain_.clear();
    // port
    port_ = 0;
}

bool server_address::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t server_address::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // domain
    total_size += SpringCat::Wave::internal::size(domain_, 0xFFFFFFFF);
    // port
    total_size += SpringCat::Wave::internal::size(port_);

    return total_size;
}

void server_address::copy_from(const SpringCat::Wave::object_base& from)
{
    const server_address& src = dynamic_cast<const server_address&>(from);
    copy_from(src);
}

void server_address::copy_from(const server_address& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void server_address::merge_from(const SpringCat::Wave::object_base& from)
{
    const server_address& src = dynamic_cast<const server_address&>(from);
    merge_from(src);
}

void server_address::merge_from(const server_address& from)
{
    if (&from == this)
    {
        return;
    }

    // domain
    set_domain(from.get_domain());
    // port
    set_port(from.get_port());
}

bool server_address::serialize(SpringCat::System::Stream& output) const
{
    // domain
    if (SpringCat::Wave::internal::serialize(output, domain_, 0xFFFFFFFF) == false)
    {
        return false;
    }
    // port
    if (SpringCat::Wave::internal::serialize(output, port_) == false)
    {
        return false;
    }

    return true;
}

bool server_address::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool server_address::serialize(std::string& output) const
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

bool server_address::deserialize(SpringCat::System::Stream& input)
{
    // domain
    if (SpringCat::Wave::internal::deserialize(input, domain_, 0xFFFFFFFF) == false)
    {
        return false;
    }
    // port
    if (SpringCat::Wave::internal::deserialize(input, port_) == false)
    {
        return false;
    }

    return true;
}

bool server_address::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool server_address::deserialize(std::string& input)
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

const std::string& server_address::get_domain(void) const
{
    return domain_;
}

std::string* server_address::get_mutable_domain(void)
{
    return &domain_;
}

void server_address::set_domain(const std::string& value)
{
    domain_.assign(value);
}

void server_address::set_domain(const char* value)
{
    domain_.assign(value);
}

SpringCat::uint16_t server_address::get_port(void) const
{
    return port_;
}

void server_address::set_port(SpringCat::uint16_t value)
{
    port_ = value;
}

asset_info::asset_info(void)
    : __has_bits__(),
    gold_(0),
    diamond_(0),
    quick_ticket_(0),
    quick_timestamp_(0),
    grandprix_ticket_(0),
    grandprix_timestamp_(0)
{
}

asset_info::asset_info(const asset_info& from)
    : __has_bits__(),
    gold_(0),
    diamond_(0),
    quick_ticket_(0),
    quick_timestamp_(0),
    grandprix_ticket_(0),
    grandprix_timestamp_(0)
{
    merge_from(from);
}

asset_info::~asset_info(void)
{
}

const SpringCat::Wave::type_info& asset_info::static_type_info(void)
{
    return __asset_info_type_info__;
}

const SpringCat::Wave::type_info& asset_info::runtime_type_info(void) const
{
    return static_type_info();
}

asset_info* asset_info::new_instance(void) const
{
    return new asset_info;
}

asset_info* asset_info::clone(void) const
{
    return new asset_info(*this);
}

void asset_info::clear(void)
{
    // gold
    gold_ = 0;
    // diamond
    diamond_ = 0;
    // quick_ticket
    quick_ticket_ = 0;
    // quick_timestamp
    quick_timestamp_ = 0;
    // grandprix_ticket
    grandprix_ticket_ = 0;
    // grandprix_timestamp
    grandprix_timestamp_ = 0;
}

bool asset_info::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t asset_info::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // gold
    total_size += SpringCat::Wave::internal::size(gold_);
    // diamond
    total_size += SpringCat::Wave::internal::size(diamond_);
    // quick_ticket
    total_size += SpringCat::Wave::internal::size(quick_ticket_);
    // quick_timestamp
    total_size += SpringCat::Wave::internal::size(quick_timestamp_);
    // grandprix_ticket
    total_size += SpringCat::Wave::internal::size(grandprix_ticket_);
    // grandprix_timestamp
    total_size += SpringCat::Wave::internal::size(grandprix_timestamp_);

    return total_size;
}

void asset_info::copy_from(const SpringCat::Wave::object_base& from)
{
    const asset_info& src = dynamic_cast<const asset_info&>(from);
    copy_from(src);
}

void asset_info::copy_from(const asset_info& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void asset_info::merge_from(const SpringCat::Wave::object_base& from)
{
    const asset_info& src = dynamic_cast<const asset_info&>(from);
    merge_from(src);
}

void asset_info::merge_from(const asset_info& from)
{
    if (&from == this)
    {
        return;
    }

    // gold
    set_gold(from.get_gold());
    // diamond
    set_diamond(from.get_diamond());
    // quick_ticket
    set_quick_ticket(from.get_quick_ticket());
    // quick_timestamp
    set_quick_timestamp(from.get_quick_timestamp());
    // grandprix_ticket
    set_grandprix_ticket(from.get_grandprix_ticket());
    // grandprix_timestamp
    set_grandprix_timestamp(from.get_grandprix_timestamp());
}

bool asset_info::serialize(SpringCat::System::Stream& output) const
{
    // gold
    if (SpringCat::Wave::internal::serialize(output, gold_) == false)
    {
        return false;
    }
    // diamond
    if (SpringCat::Wave::internal::serialize(output, diamond_) == false)
    {
        return false;
    }
    // quick_ticket
    if (SpringCat::Wave::internal::serialize(output, quick_ticket_) == false)
    {
        return false;
    }
    // quick_timestamp
    if (SpringCat::Wave::internal::serialize(output, quick_timestamp_) == false)
    {
        return false;
    }
    // grandprix_ticket
    if (SpringCat::Wave::internal::serialize(output, grandprix_ticket_) == false)
    {
        return false;
    }
    // grandprix_timestamp
    if (SpringCat::Wave::internal::serialize(output, grandprix_timestamp_) == false)
    {
        return false;
    }

    return true;
}

bool asset_info::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool asset_info::serialize(std::string& output) const
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

bool asset_info::deserialize(SpringCat::System::Stream& input)
{
    // gold
    if (SpringCat::Wave::internal::deserialize(input, gold_) == false)
    {
        return false;
    }
    // diamond
    if (SpringCat::Wave::internal::deserialize(input, diamond_) == false)
    {
        return false;
    }
    // quick_ticket
    if (SpringCat::Wave::internal::deserialize(input, quick_ticket_) == false)
    {
        return false;
    }
    // quick_timestamp
    if (SpringCat::Wave::internal::deserialize(input, quick_timestamp_) == false)
    {
        return false;
    }
    // grandprix_ticket
    if (SpringCat::Wave::internal::deserialize(input, grandprix_ticket_) == false)
    {
        return false;
    }
    // grandprix_timestamp
    if (SpringCat::Wave::internal::deserialize(input, grandprix_timestamp_) == false)
    {
        return false;
    }

    return true;
}

bool asset_info::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool asset_info::deserialize(std::string& input)
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

SpringCat::int32_t asset_info::get_gold(void) const
{
    return gold_;
}

void asset_info::set_gold(SpringCat::int32_t value)
{
    gold_ = value;
}

SpringCat::int32_t asset_info::get_diamond(void) const
{
    return diamond_;
}

void asset_info::set_diamond(SpringCat::int32_t value)
{
    diamond_ = value;
}

SpringCat::int16_t asset_info::get_quick_ticket(void) const
{
    return quick_ticket_;
}

void asset_info::set_quick_ticket(SpringCat::int16_t value)
{
    quick_ticket_ = value;
}

SpringCat::int64_t asset_info::get_quick_timestamp(void) const
{
    return quick_timestamp_;
}

void asset_info::set_quick_timestamp(SpringCat::int64_t value)
{
    quick_timestamp_ = value;
}

SpringCat::int16_t asset_info::get_grandprix_ticket(void) const
{
    return grandprix_ticket_;
}

void asset_info::set_grandprix_ticket(SpringCat::int16_t value)
{
    grandprix_ticket_ = value;
}

SpringCat::int64_t asset_info::get_grandprix_timestamp(void) const
{
    return grandprix_timestamp_;
}

void asset_info::set_grandprix_timestamp(SpringCat::int64_t value)
{
    grandprix_timestamp_ = value;
}



}    // namespace protocol
