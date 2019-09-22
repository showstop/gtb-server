#include "dev_test.dc.h"
#include <stdexcept>


namespace dev
{

// class name: put_vehicle_card_req, type id(decimal): 224486337, type id(hex): 0xD6163C1
static const SpringCat::Wave::type_info __put_vehicle_card_req_type_info__(0xD6163C1, "dev.put_vehicle_card_req");
// class name: put_vehicle_card_ans, type id(decimal): 224484691, type id(hex): 0xD615D53
static const SpringCat::Wave::type_info __put_vehicle_card_ans_type_info__(0xD615D53, "dev.put_vehicle_card_ans");
// class name: put_vehicle_stuff_req, type id(decimal): 89975585, type id(hex): 0x55CEB21
static const SpringCat::Wave::type_info __put_vehicle_stuff_req_type_info__(0x55CEB21, "dev.put_vehicle_stuff_req");
// class name: put_vehicle_stuff_ans, type id(decimal): 89970099, type id(hex): 0x55CD5B3
static const SpringCat::Wave::type_info __put_vehicle_stuff_ans_type_info__(0x55CD5B3, "dev.put_vehicle_stuff_ans");

put_vehicle_card_req::put_vehicle_card_req(void)
    : __has_bits__(),
    vehicle_no_(0),
    quantity_(0)
{
}

put_vehicle_card_req::put_vehicle_card_req(const put_vehicle_card_req& from)
    : __has_bits__(),
    vehicle_no_(0),
    quantity_(0)
{
    merge_from(from);
}

put_vehicle_card_req::~put_vehicle_card_req(void)
{
}

const SpringCat::Wave::type_info& put_vehicle_card_req::static_type_info(void)
{
    return __put_vehicle_card_req_type_info__;
}

const SpringCat::Wave::type_info& put_vehicle_card_req::runtime_type_info(void) const
{
    return static_type_info();
}

put_vehicle_card_req* put_vehicle_card_req::new_instance(void) const
{
    return new put_vehicle_card_req;
}

put_vehicle_card_req* put_vehicle_card_req::clone(void) const
{
    return new put_vehicle_card_req(*this);
}

void put_vehicle_card_req::clear(void)
{
    // vehicle_no
    vehicle_no_ = 0;
    // quantity
    quantity_ = 0;
}

bool put_vehicle_card_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t put_vehicle_card_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // vehicle_no
    total_size += SpringCat::Wave::internal::size(vehicle_no_);
    // quantity
    total_size += SpringCat::Wave::internal::size(quantity_);

    return total_size;
}

void put_vehicle_card_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const put_vehicle_card_req& src = dynamic_cast<const put_vehicle_card_req&>(from);
    copy_from(src);
}

void put_vehicle_card_req::copy_from(const put_vehicle_card_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void put_vehicle_card_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const put_vehicle_card_req& src = dynamic_cast<const put_vehicle_card_req&>(from);
    merge_from(src);
}

void put_vehicle_card_req::merge_from(const put_vehicle_card_req& from)
{
    if (&from == this)
    {
        return;
    }

    // vehicle_no
    set_vehicle_no(from.get_vehicle_no());
    // quantity
    set_quantity(from.get_quantity());
}

bool put_vehicle_card_req::serialize(SpringCat::System::Stream& output) const
{
    // vehicle_no
    if (SpringCat::Wave::internal::serialize(output, vehicle_no_) == false)
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

bool put_vehicle_card_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool put_vehicle_card_req::serialize(std::string& output) const
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

bool put_vehicle_card_req::deserialize(SpringCat::System::Stream& input)
{
    // vehicle_no
    if (SpringCat::Wave::internal::deserialize(input, vehicle_no_) == false)
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

bool put_vehicle_card_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool put_vehicle_card_req::deserialize(std::string& input)
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

SpringCat::int32_t put_vehicle_card_req::get_vehicle_no(void) const
{
    return vehicle_no_;
}

void put_vehicle_card_req::set_vehicle_no(SpringCat::int32_t value)
{
    vehicle_no_ = value;
}

SpringCat::int32_t put_vehicle_card_req::get_quantity(void) const
{
    return quantity_;
}

void put_vehicle_card_req::set_quantity(SpringCat::int32_t value)
{
    quantity_ = value;
}

put_vehicle_card_ans::put_vehicle_card_ans(void)
    : __has_bits__(),
    result_(0),
    updated_vehicle_(new protocol::vehicle)
{
}

put_vehicle_card_ans::put_vehicle_card_ans(const put_vehicle_card_ans& from)
    : __has_bits__(),
    result_(0),
    updated_vehicle_(new protocol::vehicle)
{
    merge_from(from);
}

put_vehicle_card_ans::~put_vehicle_card_ans(void)
{
}

const SpringCat::Wave::type_info& put_vehicle_card_ans::static_type_info(void)
{
    return __put_vehicle_card_ans_type_info__;
}

const SpringCat::Wave::type_info& put_vehicle_card_ans::runtime_type_info(void) const
{
    return static_type_info();
}

put_vehicle_card_ans* put_vehicle_card_ans::new_instance(void) const
{
    return new put_vehicle_card_ans;
}

put_vehicle_card_ans* put_vehicle_card_ans::clone(void) const
{
    return new put_vehicle_card_ans(*this);
}

void put_vehicle_card_ans::clear(void)
{
    // result
    result_ = 0;
    // updated_vehicle
    updated_vehicle_->clear();
}

bool put_vehicle_card_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t put_vehicle_card_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // updated_vehicle
    total_size += SpringCat::Wave::internal::size(*updated_vehicle_);

    return total_size;
}

void put_vehicle_card_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const put_vehicle_card_ans& src = dynamic_cast<const put_vehicle_card_ans&>(from);
    copy_from(src);
}

void put_vehicle_card_ans::copy_from(const put_vehicle_card_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void put_vehicle_card_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const put_vehicle_card_ans& src = dynamic_cast<const put_vehicle_card_ans&>(from);
    merge_from(src);
}

void put_vehicle_card_ans::merge_from(const put_vehicle_card_ans& from)
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

bool put_vehicle_card_ans::serialize(SpringCat::System::Stream& output) const
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

bool put_vehicle_card_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool put_vehicle_card_ans::serialize(std::string& output) const
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

bool put_vehicle_card_ans::deserialize(SpringCat::System::Stream& input)
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

bool put_vehicle_card_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool put_vehicle_card_ans::deserialize(std::string& input)
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

SpringCat::int16_t put_vehicle_card_ans::get_result(void) const
{
    return result_;
}

void put_vehicle_card_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

const protocol::vehicle* put_vehicle_card_ans::get_updated_vehicle(void) const
{
    return updated_vehicle_.get();
}

protocol::vehicle* put_vehicle_card_ans::get_mutable_updated_vehicle(void)
{
    return updated_vehicle_.get();
}

put_vehicle_stuff_req::put_vehicle_stuff_req(void)
    : __has_bits__(),
    stuff_id_(0),
    quantity_(0)
{
}

put_vehicle_stuff_req::put_vehicle_stuff_req(const put_vehicle_stuff_req& from)
    : __has_bits__(),
    stuff_id_(0),
    quantity_(0)
{
    merge_from(from);
}

put_vehicle_stuff_req::~put_vehicle_stuff_req(void)
{
}

const SpringCat::Wave::type_info& put_vehicle_stuff_req::static_type_info(void)
{
    return __put_vehicle_stuff_req_type_info__;
}

const SpringCat::Wave::type_info& put_vehicle_stuff_req::runtime_type_info(void) const
{
    return static_type_info();
}

put_vehicle_stuff_req* put_vehicle_stuff_req::new_instance(void) const
{
    return new put_vehicle_stuff_req;
}

put_vehicle_stuff_req* put_vehicle_stuff_req::clone(void) const
{
    return new put_vehicle_stuff_req(*this);
}

void put_vehicle_stuff_req::clear(void)
{
    // stuff_id
    stuff_id_ = 0;
    // quantity
    quantity_ = 0;
}

bool put_vehicle_stuff_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t put_vehicle_stuff_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // stuff_id
    total_size += SpringCat::Wave::internal::size(stuff_id_);
    // quantity
    total_size += SpringCat::Wave::internal::size(quantity_);

    return total_size;
}

void put_vehicle_stuff_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const put_vehicle_stuff_req& src = dynamic_cast<const put_vehicle_stuff_req&>(from);
    copy_from(src);
}

void put_vehicle_stuff_req::copy_from(const put_vehicle_stuff_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void put_vehicle_stuff_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const put_vehicle_stuff_req& src = dynamic_cast<const put_vehicle_stuff_req&>(from);
    merge_from(src);
}

void put_vehicle_stuff_req::merge_from(const put_vehicle_stuff_req& from)
{
    if (&from == this)
    {
        return;
    }

    // stuff_id
    set_stuff_id(from.get_stuff_id());
    // quantity
    set_quantity(from.get_quantity());
}

bool put_vehicle_stuff_req::serialize(SpringCat::System::Stream& output) const
{
    // stuff_id
    if (SpringCat::Wave::internal::serialize(output, stuff_id_) == false)
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

bool put_vehicle_stuff_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool put_vehicle_stuff_req::serialize(std::string& output) const
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

bool put_vehicle_stuff_req::deserialize(SpringCat::System::Stream& input)
{
    // stuff_id
    if (SpringCat::Wave::internal::deserialize(input, stuff_id_) == false)
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

bool put_vehicle_stuff_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool put_vehicle_stuff_req::deserialize(std::string& input)
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

SpringCat::int32_t put_vehicle_stuff_req::get_stuff_id(void) const
{
    return stuff_id_;
}

void put_vehicle_stuff_req::set_stuff_id(SpringCat::int32_t value)
{
    stuff_id_ = value;
}

SpringCat::int32_t put_vehicle_stuff_req::get_quantity(void) const
{
    return quantity_;
}

void put_vehicle_stuff_req::set_quantity(SpringCat::int32_t value)
{
    quantity_ = value;
}

put_vehicle_stuff_ans::put_vehicle_stuff_ans(void)
    : __has_bits__(),
    result_(0),
    updated_stuffs_(new protocol::vehicle_stuff)
{
}

put_vehicle_stuff_ans::put_vehicle_stuff_ans(const put_vehicle_stuff_ans& from)
    : __has_bits__(),
    result_(0),
    updated_stuffs_(new protocol::vehicle_stuff)
{
    merge_from(from);
}

put_vehicle_stuff_ans::~put_vehicle_stuff_ans(void)
{
}

const SpringCat::Wave::type_info& put_vehicle_stuff_ans::static_type_info(void)
{
    return __put_vehicle_stuff_ans_type_info__;
}

const SpringCat::Wave::type_info& put_vehicle_stuff_ans::runtime_type_info(void) const
{
    return static_type_info();
}

put_vehicle_stuff_ans* put_vehicle_stuff_ans::new_instance(void) const
{
    return new put_vehicle_stuff_ans;
}

put_vehicle_stuff_ans* put_vehicle_stuff_ans::clone(void) const
{
    return new put_vehicle_stuff_ans(*this);
}

void put_vehicle_stuff_ans::clear(void)
{
    // result
    result_ = 0;
    // updated_stuffs
    updated_stuffs_->clear();
}

bool put_vehicle_stuff_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t put_vehicle_stuff_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // updated_stuffs
    total_size += SpringCat::Wave::internal::size(*updated_stuffs_);

    return total_size;
}

void put_vehicle_stuff_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const put_vehicle_stuff_ans& src = dynamic_cast<const put_vehicle_stuff_ans&>(from);
    copy_from(src);
}

void put_vehicle_stuff_ans::copy_from(const put_vehicle_stuff_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void put_vehicle_stuff_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const put_vehicle_stuff_ans& src = dynamic_cast<const put_vehicle_stuff_ans&>(from);
    merge_from(src);
}

void put_vehicle_stuff_ans::merge_from(const put_vehicle_stuff_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // updated_stuffs
    updated_stuffs_->merge_from(*from.get_updated_stuffs());
}

bool put_vehicle_stuff_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
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

bool put_vehicle_stuff_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool put_vehicle_stuff_ans::serialize(std::string& output) const
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

bool put_vehicle_stuff_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
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

bool put_vehicle_stuff_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool put_vehicle_stuff_ans::deserialize(std::string& input)
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

SpringCat::int16_t put_vehicle_stuff_ans::get_result(void) const
{
    return result_;
}

void put_vehicle_stuff_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

const protocol::vehicle_stuff* put_vehicle_stuff_ans::get_updated_stuffs(void) const
{
    return updated_stuffs_.get();
}

protocol::vehicle_stuff* put_vehicle_stuff_ans::get_mutable_updated_stuffs(void)
{
    return updated_stuffs_.get();
}



}    // namespace dev
