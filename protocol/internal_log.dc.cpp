#include "internal_log.dc.h"
#include <stdexcept>


namespace protocol
{

// class name: service_log, type id(decimal): 128570807, type id(hex): 0x7A9D5B7
static const SpringCat::Wave::type_info __service_log_type_info__(0x7A9D5B7, "protocol.service_log");

service_log::service_log(void)
    : __has_bits__(),
    log_msg_()
{
}

service_log::service_log(const service_log& from)
    : __has_bits__(),
    log_msg_()
{
    merge_from(from);
}

service_log::~service_log(void)
{
}

const SpringCat::Wave::type_info& service_log::static_type_info(void)
{
    return __service_log_type_info__;
}

const SpringCat::Wave::type_info& service_log::runtime_type_info(void) const
{
    return static_type_info();
}

service_log* service_log::new_instance(void) const
{
    return new service_log;
}

service_log* service_log::clone(void) const
{
    return new service_log(*this);
}

void service_log::clear(void)
{
    // log_msg
    log_msg_.clear();
}

bool service_log::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t service_log::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // log_msg
    total_size += SpringCat::Wave::internal::size(log_msg_, 0xFFFFFFFF);

    return total_size;
}

void service_log::copy_from(const SpringCat::Wave::object_base& from)
{
    const service_log& src = dynamic_cast<const service_log&>(from);
    copy_from(src);
}

void service_log::copy_from(const service_log& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void service_log::merge_from(const SpringCat::Wave::object_base& from)
{
    const service_log& src = dynamic_cast<const service_log&>(from);
    merge_from(src);
}

void service_log::merge_from(const service_log& from)
{
    if (&from == this)
    {
        return;
    }

    // log_msg
    set_log_msg(from.get_log_msg());
}

bool service_log::serialize(SpringCat::System::Stream& output) const
{
    // log_msg
    if (SpringCat::Wave::internal::serialize(output, log_msg_, 0xFFFFFFFF) == false)
    {
        return false;
    }

    return true;
}

bool service_log::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool service_log::serialize(std::string& output) const
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

bool service_log::deserialize(SpringCat::System::Stream& input)
{
    // log_msg
    if (SpringCat::Wave::internal::deserialize(input, log_msg_, 0xFFFFFFFF) == false)
    {
        return false;
    }

    return true;
}

bool service_log::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool service_log::deserialize(std::string& input)
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

const std::string& service_log::get_log_msg(void) const
{
    return log_msg_;
}

std::string* service_log::get_mutable_log_msg(void)
{
    return &log_msg_;
}

void service_log::set_log_msg(const std::string& value)
{
    log_msg_.assign(value);
}

void service_log::set_log_msg(const char* value)
{
    log_msg_.assign(value);
}



}    // namespace protocol
