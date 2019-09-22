#include "reward_station.dc.h"
#include <stdexcept>


namespace protocol
{

// class name: reward_station_info, type id(decimal): 18738847, type id(hex): 0x11DEE9F
static const SpringCat::Wave::type_info __reward_station_info_type_info__(0x11DEE9F, "protocol.reward_station_info");
// class name: reward_station_info_req, type id(decimal): 245789985, type id(hex): 0xEA67521
static const SpringCat::Wave::type_info __reward_station_info_req_type_info__(0xEA67521, "protocol.reward_station_info_req");
// class name: reward_station_info_ans, type id(decimal): 245779379, type id(hex): 0xEA64BB3
static const SpringCat::Wave::type_info __reward_station_info_ans_type_info__(0xEA64BB3, "protocol.reward_station_info_ans");
// class name: reward_station_video_ad_req, type id(decimal): 194876321, type id(hex): 0xB9D93A1
static const SpringCat::Wave::type_info __reward_station_video_ad_req_type_info__(0xB9D93A1, "protocol.reward_station_video_ad_req");
// class name: reward_station_video_ad_ans, type id(decimal): 194882867, type id(hex): 0xB9DAD33
static const SpringCat::Wave::type_info __reward_station_video_ad_ans_type_info__(0xB9DAD33, "protocol.reward_station_video_ad_ans");
// class name: reward_station_video_ad_complete_req, type id(decimal): 111175729, type id(hex): 0x6A06831
static const SpringCat::Wave::type_info __reward_station_video_ad_complete_req_type_info__(0x6A06831, "protocol.reward_station_video_ad_complete_req");
// class name: reward_station_video_ad_complete_ans, type id(decimal): 111171747, type id(hex): 0x6A058A3
static const SpringCat::Wave::type_info __reward_station_video_ad_complete_ans_type_info__(0x6A058A3, "protocol.reward_station_video_ad_complete_ans");
// class name: reward_station_fb_post_req, type id(decimal): 125340481, type id(hex): 0x7788B41
static const SpringCat::Wave::type_info __reward_station_fb_post_req_type_info__(0x7788B41, "protocol.reward_station_fb_post_req");
// class name: reward_station_fb_post_ans, type id(decimal): 125351379, type id(hex): 0x778B5D3
static const SpringCat::Wave::type_info __reward_station_fb_post_ans_type_info__(0x778B5D3, "protocol.reward_station_fb_post_ans");
// class name: reward_station_fb_invite_req, type id(decimal): 239836385, type id(hex): 0xE4B9CE1
static const SpringCat::Wave::type_info __reward_station_fb_invite_req_type_info__(0xE4B9CE1, "protocol.reward_station_fb_invite_req");
// class name: reward_station_fb_invite_ans, type id(decimal): 239838323, type id(hex): 0xE4BA473
static const SpringCat::Wave::type_info __reward_station_fb_invite_ans_type_info__(0xE4BA473, "protocol.reward_station_fb_invite_ans");
// class name: reward_station_gold_bonus_req, type id(decimal): 95563665, type id(hex): 0x5B22F91
static const SpringCat::Wave::type_info __reward_station_gold_bonus_req_type_info__(0x5B22F91, "protocol.reward_station_gold_bonus_req");
// class name: reward_station_gold_bonus_ans, type id(decimal): 95555843, type id(hex): 0x5B21103
static const SpringCat::Wave::type_info __reward_station_gold_bonus_ans_type_info__(0x5B21103, "protocol.reward_station_gold_bonus_ans");

reward_station_info::reward_station_info(void)
    : __has_bits__(),
    video_ad_(new reward_info),
    next_video_ad_time_(0),
    fb_post_(new reward_info),
    next_fb_post_(0),
    fb_invite_(new reward_info),
    gold_bonus_(new reward_info),
    next_gold_bonus_(0)
{
}

reward_station_info::reward_station_info(const reward_station_info& from)
    : __has_bits__(),
    video_ad_(new reward_info),
    next_video_ad_time_(0),
    fb_post_(new reward_info),
    next_fb_post_(0),
    fb_invite_(new reward_info),
    gold_bonus_(new reward_info),
    next_gold_bonus_(0)
{
    merge_from(from);
}

reward_station_info::~reward_station_info(void)
{
}

const SpringCat::Wave::type_info& reward_station_info::static_type_info(void)
{
    return __reward_station_info_type_info__;
}

const SpringCat::Wave::type_info& reward_station_info::runtime_type_info(void) const
{
    return static_type_info();
}

reward_station_info* reward_station_info::new_instance(void) const
{
    return new reward_station_info;
}

reward_station_info* reward_station_info::clone(void) const
{
    return new reward_station_info(*this);
}

void reward_station_info::clear(void)
{
    // video_ad
    video_ad_->clear();
    // next_video_ad_time
    next_video_ad_time_ = 0;
    // fb_post
    fb_post_->clear();
    // next_fb_post
    next_fb_post_ = 0;
    // fb_invite
    fb_invite_->clear();
    // gold_bonus
    gold_bonus_->clear();
    // next_gold_bonus
    next_gold_bonus_ = 0;
}

bool reward_station_info::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t reward_station_info::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // video_ad
    total_size += SpringCat::Wave::internal::size(*video_ad_);
    // next_video_ad_time
    total_size += SpringCat::Wave::internal::size(next_video_ad_time_);
    // fb_post
    total_size += SpringCat::Wave::internal::size(*fb_post_);
    // next_fb_post
    total_size += SpringCat::Wave::internal::size(next_fb_post_);
    // fb_invite
    total_size += SpringCat::Wave::internal::size(*fb_invite_);
    // gold_bonus
    total_size += SpringCat::Wave::internal::size(*gold_bonus_);
    // next_gold_bonus
    total_size += SpringCat::Wave::internal::size(next_gold_bonus_);

    return total_size;
}

void reward_station_info::copy_from(const SpringCat::Wave::object_base& from)
{
    const reward_station_info& src = dynamic_cast<const reward_station_info&>(from);
    copy_from(src);
}

void reward_station_info::copy_from(const reward_station_info& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void reward_station_info::merge_from(const SpringCat::Wave::object_base& from)
{
    const reward_station_info& src = dynamic_cast<const reward_station_info&>(from);
    merge_from(src);
}

void reward_station_info::merge_from(const reward_station_info& from)
{
    if (&from == this)
    {
        return;
    }

    // video_ad
    video_ad_->merge_from(*from.get_video_ad());
    // next_video_ad_time
    set_next_video_ad_time(from.get_next_video_ad_time());
    // fb_post
    fb_post_->merge_from(*from.get_fb_post());
    // next_fb_post
    set_next_fb_post(from.get_next_fb_post());
    // fb_invite
    fb_invite_->merge_from(*from.get_fb_invite());
    // gold_bonus
    gold_bonus_->merge_from(*from.get_gold_bonus());
    // next_gold_bonus
    set_next_gold_bonus(from.get_next_gold_bonus());
}

bool reward_station_info::serialize(SpringCat::System::Stream& output) const
{
    // video_ad
    if (SpringCat::Wave::internal::serialize(output, *video_ad_) == false)
    {
        return false;
    }
    // next_video_ad_time
    if (SpringCat::Wave::internal::serialize(output, next_video_ad_time_) == false)
    {
        return false;
    }
    // fb_post
    if (SpringCat::Wave::internal::serialize(output, *fb_post_) == false)
    {
        return false;
    }
    // next_fb_post
    if (SpringCat::Wave::internal::serialize(output, next_fb_post_) == false)
    {
        return false;
    }
    // fb_invite
    if (SpringCat::Wave::internal::serialize(output, *fb_invite_) == false)
    {
        return false;
    }
    // gold_bonus
    if (SpringCat::Wave::internal::serialize(output, *gold_bonus_) == false)
    {
        return false;
    }
    // next_gold_bonus
    if (SpringCat::Wave::internal::serialize(output, next_gold_bonus_) == false)
    {
        return false;
    }

    return true;
}

bool reward_station_info::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool reward_station_info::serialize(std::string& output) const
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

bool reward_station_info::deserialize(SpringCat::System::Stream& input)
{
    // video_ad
    if (SpringCat::Wave::internal::deserialize(input, *video_ad_) == false)
    {
        return false;
    }
    // next_video_ad_time
    if (SpringCat::Wave::internal::deserialize(input, next_video_ad_time_) == false)
    {
        return false;
    }
    // fb_post
    if (SpringCat::Wave::internal::deserialize(input, *fb_post_) == false)
    {
        return false;
    }
    // next_fb_post
    if (SpringCat::Wave::internal::deserialize(input, next_fb_post_) == false)
    {
        return false;
    }
    // fb_invite
    if (SpringCat::Wave::internal::deserialize(input, *fb_invite_) == false)
    {
        return false;
    }
    // gold_bonus
    if (SpringCat::Wave::internal::deserialize(input, *gold_bonus_) == false)
    {
        return false;
    }
    // next_gold_bonus
    if (SpringCat::Wave::internal::deserialize(input, next_gold_bonus_) == false)
    {
        return false;
    }

    return true;
}

bool reward_station_info::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool reward_station_info::deserialize(std::string& input)
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

const reward_info* reward_station_info::get_video_ad(void) const
{
    return video_ad_.get();
}

reward_info* reward_station_info::get_mutable_video_ad(void)
{
    return video_ad_.get();
}

SpringCat::int64_t reward_station_info::get_next_video_ad_time(void) const
{
    return next_video_ad_time_;
}

void reward_station_info::set_next_video_ad_time(SpringCat::int64_t value)
{
    next_video_ad_time_ = value;
}

const reward_info* reward_station_info::get_fb_post(void) const
{
    return fb_post_.get();
}

reward_info* reward_station_info::get_mutable_fb_post(void)
{
    return fb_post_.get();
}

SpringCat::int64_t reward_station_info::get_next_fb_post(void) const
{
    return next_fb_post_;
}

void reward_station_info::set_next_fb_post(SpringCat::int64_t value)
{
    next_fb_post_ = value;
}

const reward_info* reward_station_info::get_fb_invite(void) const
{
    return fb_invite_.get();
}

reward_info* reward_station_info::get_mutable_fb_invite(void)
{
    return fb_invite_.get();
}

const reward_info* reward_station_info::get_gold_bonus(void) const
{
    return gold_bonus_.get();
}

reward_info* reward_station_info::get_mutable_gold_bonus(void)
{
    return gold_bonus_.get();
}

SpringCat::int64_t reward_station_info::get_next_gold_bonus(void) const
{
    return next_gold_bonus_;
}

void reward_station_info::set_next_gold_bonus(SpringCat::int64_t value)
{
    next_gold_bonus_ = value;
}

reward_station_info_req::reward_station_info_req(void)
{
}

reward_station_info_req::reward_station_info_req(const reward_station_info_req& from)
{
    merge_from(from);
}

reward_station_info_req::~reward_station_info_req(void)
{
}

const SpringCat::Wave::type_info& reward_station_info_req::static_type_info(void)
{
    return __reward_station_info_req_type_info__;
}

const SpringCat::Wave::type_info& reward_station_info_req::runtime_type_info(void) const
{
    return static_type_info();
}

reward_station_info_req* reward_station_info_req::new_instance(void) const
{
    return new reward_station_info_req;
}

reward_station_info_req* reward_station_info_req::clone(void) const
{
    return new reward_station_info_req(*this);
}

void reward_station_info_req::clear(void)
{
}

bool reward_station_info_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t reward_station_info_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    return total_size;
}

void reward_station_info_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const reward_station_info_req& src = dynamic_cast<const reward_station_info_req&>(from);
    copy_from(src);
}

void reward_station_info_req::copy_from(const reward_station_info_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void reward_station_info_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const reward_station_info_req& src = dynamic_cast<const reward_station_info_req&>(from);
    merge_from(src);
}

void reward_station_info_req::merge_from(const reward_station_info_req& from)
{
    if (&from == this)
    {
        return;
    }
}

bool reward_station_info_req::serialize(SpringCat::System::Stream& output) const
{
    return true;
}

bool reward_station_info_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool reward_station_info_req::serialize(std::string& output) const
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

bool reward_station_info_req::deserialize(SpringCat::System::Stream& input)
{
    return true;
}

bool reward_station_info_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool reward_station_info_req::deserialize(std::string& input)
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

reward_station_info_ans::reward_station_info_ans(void)
    : __has_bits__(),
    result_(0),
    info_(new reward_station_info)
{
}

reward_station_info_ans::reward_station_info_ans(const reward_station_info_ans& from)
    : __has_bits__(),
    result_(0),
    info_(new reward_station_info)
{
    merge_from(from);
}

reward_station_info_ans::~reward_station_info_ans(void)
{
}

const SpringCat::Wave::type_info& reward_station_info_ans::static_type_info(void)
{
    return __reward_station_info_ans_type_info__;
}

const SpringCat::Wave::type_info& reward_station_info_ans::runtime_type_info(void) const
{
    return static_type_info();
}

reward_station_info_ans* reward_station_info_ans::new_instance(void) const
{
    return new reward_station_info_ans;
}

reward_station_info_ans* reward_station_info_ans::clone(void) const
{
    return new reward_station_info_ans(*this);
}

void reward_station_info_ans::clear(void)
{
    // result
    result_ = 0;
    // info
    info_->clear();
}

bool reward_station_info_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t reward_station_info_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // info
    total_size += SpringCat::Wave::internal::size(*info_);

    return total_size;
}

void reward_station_info_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const reward_station_info_ans& src = dynamic_cast<const reward_station_info_ans&>(from);
    copy_from(src);
}

void reward_station_info_ans::copy_from(const reward_station_info_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void reward_station_info_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const reward_station_info_ans& src = dynamic_cast<const reward_station_info_ans&>(from);
    merge_from(src);
}

void reward_station_info_ans::merge_from(const reward_station_info_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // info
    info_->merge_from(*from.get_info());
}

bool reward_station_info_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // info
    if (SpringCat::Wave::internal::serialize(output, *info_) == false)
    {
        return false;
    }

    return true;
}

bool reward_station_info_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool reward_station_info_ans::serialize(std::string& output) const
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

bool reward_station_info_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // info
    if (SpringCat::Wave::internal::deserialize(input, *info_) == false)
    {
        return false;
    }

    return true;
}

bool reward_station_info_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool reward_station_info_ans::deserialize(std::string& input)
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

SpringCat::int16_t reward_station_info_ans::get_result(void) const
{
    return result_;
}

void reward_station_info_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

const reward_station_info* reward_station_info_ans::get_info(void) const
{
    return info_.get();
}

reward_station_info* reward_station_info_ans::get_mutable_info(void)
{
    return info_.get();
}

reward_station_video_ad_req::reward_station_video_ad_req(void)
{
}

reward_station_video_ad_req::reward_station_video_ad_req(const reward_station_video_ad_req& from)
{
    merge_from(from);
}

reward_station_video_ad_req::~reward_station_video_ad_req(void)
{
}

const SpringCat::Wave::type_info& reward_station_video_ad_req::static_type_info(void)
{
    return __reward_station_video_ad_req_type_info__;
}

const SpringCat::Wave::type_info& reward_station_video_ad_req::runtime_type_info(void) const
{
    return static_type_info();
}

reward_station_video_ad_req* reward_station_video_ad_req::new_instance(void) const
{
    return new reward_station_video_ad_req;
}

reward_station_video_ad_req* reward_station_video_ad_req::clone(void) const
{
    return new reward_station_video_ad_req(*this);
}

void reward_station_video_ad_req::clear(void)
{
}

bool reward_station_video_ad_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t reward_station_video_ad_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    return total_size;
}

void reward_station_video_ad_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const reward_station_video_ad_req& src = dynamic_cast<const reward_station_video_ad_req&>(from);
    copy_from(src);
}

void reward_station_video_ad_req::copy_from(const reward_station_video_ad_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void reward_station_video_ad_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const reward_station_video_ad_req& src = dynamic_cast<const reward_station_video_ad_req&>(from);
    merge_from(src);
}

void reward_station_video_ad_req::merge_from(const reward_station_video_ad_req& from)
{
    if (&from == this)
    {
        return;
    }
}

bool reward_station_video_ad_req::serialize(SpringCat::System::Stream& output) const
{
    return true;
}

bool reward_station_video_ad_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool reward_station_video_ad_req::serialize(std::string& output) const
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

bool reward_station_video_ad_req::deserialize(SpringCat::System::Stream& input)
{
    return true;
}

bool reward_station_video_ad_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool reward_station_video_ad_req::deserialize(std::string& input)
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

reward_station_video_ad_ans::reward_station_video_ad_ans(void)
    : __has_bits__(),
    result_(0)
{
}

reward_station_video_ad_ans::reward_station_video_ad_ans(const reward_station_video_ad_ans& from)
    : __has_bits__(),
    result_(0)
{
    merge_from(from);
}

reward_station_video_ad_ans::~reward_station_video_ad_ans(void)
{
}

const SpringCat::Wave::type_info& reward_station_video_ad_ans::static_type_info(void)
{
    return __reward_station_video_ad_ans_type_info__;
}

const SpringCat::Wave::type_info& reward_station_video_ad_ans::runtime_type_info(void) const
{
    return static_type_info();
}

reward_station_video_ad_ans* reward_station_video_ad_ans::new_instance(void) const
{
    return new reward_station_video_ad_ans;
}

reward_station_video_ad_ans* reward_station_video_ad_ans::clone(void) const
{
    return new reward_station_video_ad_ans(*this);
}

void reward_station_video_ad_ans::clear(void)
{
    // result
    result_ = 0;
}

bool reward_station_video_ad_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t reward_station_video_ad_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);

    return total_size;
}

void reward_station_video_ad_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const reward_station_video_ad_ans& src = dynamic_cast<const reward_station_video_ad_ans&>(from);
    copy_from(src);
}

void reward_station_video_ad_ans::copy_from(const reward_station_video_ad_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void reward_station_video_ad_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const reward_station_video_ad_ans& src = dynamic_cast<const reward_station_video_ad_ans&>(from);
    merge_from(src);
}

void reward_station_video_ad_ans::merge_from(const reward_station_video_ad_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
}

bool reward_station_video_ad_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }

    return true;
}

bool reward_station_video_ad_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool reward_station_video_ad_ans::serialize(std::string& output) const
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

bool reward_station_video_ad_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }

    return true;
}

bool reward_station_video_ad_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool reward_station_video_ad_ans::deserialize(std::string& input)
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

SpringCat::int16_t reward_station_video_ad_ans::get_result(void) const
{
    return result_;
}

void reward_station_video_ad_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

reward_station_video_ad_complete_req::reward_station_video_ad_complete_req(void)
{
}

reward_station_video_ad_complete_req::reward_station_video_ad_complete_req(const reward_station_video_ad_complete_req& from)
{
    merge_from(from);
}

reward_station_video_ad_complete_req::~reward_station_video_ad_complete_req(void)
{
}

const SpringCat::Wave::type_info& reward_station_video_ad_complete_req::static_type_info(void)
{
    return __reward_station_video_ad_complete_req_type_info__;
}

const SpringCat::Wave::type_info& reward_station_video_ad_complete_req::runtime_type_info(void) const
{
    return static_type_info();
}

reward_station_video_ad_complete_req* reward_station_video_ad_complete_req::new_instance(void) const
{
    return new reward_station_video_ad_complete_req;
}

reward_station_video_ad_complete_req* reward_station_video_ad_complete_req::clone(void) const
{
    return new reward_station_video_ad_complete_req(*this);
}

void reward_station_video_ad_complete_req::clear(void)
{
}

bool reward_station_video_ad_complete_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t reward_station_video_ad_complete_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    return total_size;
}

void reward_station_video_ad_complete_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const reward_station_video_ad_complete_req& src = dynamic_cast<const reward_station_video_ad_complete_req&>(from);
    copy_from(src);
}

void reward_station_video_ad_complete_req::copy_from(const reward_station_video_ad_complete_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void reward_station_video_ad_complete_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const reward_station_video_ad_complete_req& src = dynamic_cast<const reward_station_video_ad_complete_req&>(from);
    merge_from(src);
}

void reward_station_video_ad_complete_req::merge_from(const reward_station_video_ad_complete_req& from)
{
    if (&from == this)
    {
        return;
    }
}

bool reward_station_video_ad_complete_req::serialize(SpringCat::System::Stream& output) const
{
    return true;
}

bool reward_station_video_ad_complete_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool reward_station_video_ad_complete_req::serialize(std::string& output) const
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

bool reward_station_video_ad_complete_req::deserialize(SpringCat::System::Stream& input)
{
    return true;
}

bool reward_station_video_ad_complete_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool reward_station_video_ad_complete_req::deserialize(std::string& input)
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

reward_station_video_ad_complete_ans::reward_station_video_ad_complete_ans(void)
    : __has_bits__(),
    result_(0),
    updated_asset_info_(new asset_info)
{
}

reward_station_video_ad_complete_ans::reward_station_video_ad_complete_ans(const reward_station_video_ad_complete_ans& from)
    : __has_bits__(),
    result_(0),
    updated_asset_info_(new asset_info)
{
    merge_from(from);
}

reward_station_video_ad_complete_ans::~reward_station_video_ad_complete_ans(void)
{
}

const SpringCat::Wave::type_info& reward_station_video_ad_complete_ans::static_type_info(void)
{
    return __reward_station_video_ad_complete_ans_type_info__;
}

const SpringCat::Wave::type_info& reward_station_video_ad_complete_ans::runtime_type_info(void) const
{
    return static_type_info();
}

reward_station_video_ad_complete_ans* reward_station_video_ad_complete_ans::new_instance(void) const
{
    return new reward_station_video_ad_complete_ans;
}

reward_station_video_ad_complete_ans* reward_station_video_ad_complete_ans::clone(void) const
{
    return new reward_station_video_ad_complete_ans(*this);
}

void reward_station_video_ad_complete_ans::clear(void)
{
    // result
    result_ = 0;
    // updated_asset_info
    updated_asset_info_->clear();
}

bool reward_station_video_ad_complete_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t reward_station_video_ad_complete_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // updated_asset_info
    total_size += SpringCat::Wave::internal::size(*updated_asset_info_);

    return total_size;
}

void reward_station_video_ad_complete_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const reward_station_video_ad_complete_ans& src = dynamic_cast<const reward_station_video_ad_complete_ans&>(from);
    copy_from(src);
}

void reward_station_video_ad_complete_ans::copy_from(const reward_station_video_ad_complete_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void reward_station_video_ad_complete_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const reward_station_video_ad_complete_ans& src = dynamic_cast<const reward_station_video_ad_complete_ans&>(from);
    merge_from(src);
}

void reward_station_video_ad_complete_ans::merge_from(const reward_station_video_ad_complete_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // updated_asset_info
    updated_asset_info_->merge_from(*from.get_updated_asset_info());
}

bool reward_station_video_ad_complete_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // updated_asset_info
    if (SpringCat::Wave::internal::serialize(output, *updated_asset_info_) == false)
    {
        return false;
    }

    return true;
}

bool reward_station_video_ad_complete_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool reward_station_video_ad_complete_ans::serialize(std::string& output) const
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

bool reward_station_video_ad_complete_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // updated_asset_info
    if (SpringCat::Wave::internal::deserialize(input, *updated_asset_info_) == false)
    {
        return false;
    }

    return true;
}

bool reward_station_video_ad_complete_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool reward_station_video_ad_complete_ans::deserialize(std::string& input)
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

SpringCat::int16_t reward_station_video_ad_complete_ans::get_result(void) const
{
    return result_;
}

void reward_station_video_ad_complete_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

const asset_info* reward_station_video_ad_complete_ans::get_updated_asset_info(void) const
{
    return updated_asset_info_.get();
}

asset_info* reward_station_video_ad_complete_ans::get_mutable_updated_asset_info(void)
{
    return updated_asset_info_.get();
}

reward_station_fb_post_req::reward_station_fb_post_req(void)
{
}

reward_station_fb_post_req::reward_station_fb_post_req(const reward_station_fb_post_req& from)
{
    merge_from(from);
}

reward_station_fb_post_req::~reward_station_fb_post_req(void)
{
}

const SpringCat::Wave::type_info& reward_station_fb_post_req::static_type_info(void)
{
    return __reward_station_fb_post_req_type_info__;
}

const SpringCat::Wave::type_info& reward_station_fb_post_req::runtime_type_info(void) const
{
    return static_type_info();
}

reward_station_fb_post_req* reward_station_fb_post_req::new_instance(void) const
{
    return new reward_station_fb_post_req;
}

reward_station_fb_post_req* reward_station_fb_post_req::clone(void) const
{
    return new reward_station_fb_post_req(*this);
}

void reward_station_fb_post_req::clear(void)
{
}

bool reward_station_fb_post_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t reward_station_fb_post_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    return total_size;
}

void reward_station_fb_post_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const reward_station_fb_post_req& src = dynamic_cast<const reward_station_fb_post_req&>(from);
    copy_from(src);
}

void reward_station_fb_post_req::copy_from(const reward_station_fb_post_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void reward_station_fb_post_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const reward_station_fb_post_req& src = dynamic_cast<const reward_station_fb_post_req&>(from);
    merge_from(src);
}

void reward_station_fb_post_req::merge_from(const reward_station_fb_post_req& from)
{
    if (&from == this)
    {
        return;
    }
}

bool reward_station_fb_post_req::serialize(SpringCat::System::Stream& output) const
{
    return true;
}

bool reward_station_fb_post_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool reward_station_fb_post_req::serialize(std::string& output) const
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

bool reward_station_fb_post_req::deserialize(SpringCat::System::Stream& input)
{
    return true;
}

bool reward_station_fb_post_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool reward_station_fb_post_req::deserialize(std::string& input)
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

reward_station_fb_post_ans::reward_station_fb_post_ans(void)
    : __has_bits__(),
    result_(0),
    updated_asset_info_(new asset_info)
{
}

reward_station_fb_post_ans::reward_station_fb_post_ans(const reward_station_fb_post_ans& from)
    : __has_bits__(),
    result_(0),
    updated_asset_info_(new asset_info)
{
    merge_from(from);
}

reward_station_fb_post_ans::~reward_station_fb_post_ans(void)
{
}

const SpringCat::Wave::type_info& reward_station_fb_post_ans::static_type_info(void)
{
    return __reward_station_fb_post_ans_type_info__;
}

const SpringCat::Wave::type_info& reward_station_fb_post_ans::runtime_type_info(void) const
{
    return static_type_info();
}

reward_station_fb_post_ans* reward_station_fb_post_ans::new_instance(void) const
{
    return new reward_station_fb_post_ans;
}

reward_station_fb_post_ans* reward_station_fb_post_ans::clone(void) const
{
    return new reward_station_fb_post_ans(*this);
}

void reward_station_fb_post_ans::clear(void)
{
    // result
    result_ = 0;
    // updated_asset_info
    updated_asset_info_->clear();
}

bool reward_station_fb_post_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t reward_station_fb_post_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // updated_asset_info
    total_size += SpringCat::Wave::internal::size(*updated_asset_info_);

    return total_size;
}

void reward_station_fb_post_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const reward_station_fb_post_ans& src = dynamic_cast<const reward_station_fb_post_ans&>(from);
    copy_from(src);
}

void reward_station_fb_post_ans::copy_from(const reward_station_fb_post_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void reward_station_fb_post_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const reward_station_fb_post_ans& src = dynamic_cast<const reward_station_fb_post_ans&>(from);
    merge_from(src);
}

void reward_station_fb_post_ans::merge_from(const reward_station_fb_post_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // updated_asset_info
    updated_asset_info_->merge_from(*from.get_updated_asset_info());
}

bool reward_station_fb_post_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // updated_asset_info
    if (SpringCat::Wave::internal::serialize(output, *updated_asset_info_) == false)
    {
        return false;
    }

    return true;
}

bool reward_station_fb_post_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool reward_station_fb_post_ans::serialize(std::string& output) const
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

bool reward_station_fb_post_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // updated_asset_info
    if (SpringCat::Wave::internal::deserialize(input, *updated_asset_info_) == false)
    {
        return false;
    }

    return true;
}

bool reward_station_fb_post_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool reward_station_fb_post_ans::deserialize(std::string& input)
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

SpringCat::int16_t reward_station_fb_post_ans::get_result(void) const
{
    return result_;
}

void reward_station_fb_post_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

const asset_info* reward_station_fb_post_ans::get_updated_asset_info(void) const
{
    return updated_asset_info_.get();
}

asset_info* reward_station_fb_post_ans::get_mutable_updated_asset_info(void)
{
    return updated_asset_info_.get();
}

reward_station_fb_invite_req::reward_station_fb_invite_req(void)
    : __has_bits__(),
    fb_uuid_(0)
{
}

reward_station_fb_invite_req::reward_station_fb_invite_req(const reward_station_fb_invite_req& from)
    : __has_bits__(),
    fb_uuid_(0)
{
    merge_from(from);
}

reward_station_fb_invite_req::~reward_station_fb_invite_req(void)
{
}

const SpringCat::Wave::type_info& reward_station_fb_invite_req::static_type_info(void)
{
    return __reward_station_fb_invite_req_type_info__;
}

const SpringCat::Wave::type_info& reward_station_fb_invite_req::runtime_type_info(void) const
{
    return static_type_info();
}

reward_station_fb_invite_req* reward_station_fb_invite_req::new_instance(void) const
{
    return new reward_station_fb_invite_req;
}

reward_station_fb_invite_req* reward_station_fb_invite_req::clone(void) const
{
    return new reward_station_fb_invite_req(*this);
}

void reward_station_fb_invite_req::clear(void)
{
    // fb_uuid
    fb_uuid_ = 0;
}

bool reward_station_fb_invite_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t reward_station_fb_invite_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // fb_uuid
    total_size += SpringCat::Wave::internal::size(fb_uuid_);

    return total_size;
}

void reward_station_fb_invite_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const reward_station_fb_invite_req& src = dynamic_cast<const reward_station_fb_invite_req&>(from);
    copy_from(src);
}

void reward_station_fb_invite_req::copy_from(const reward_station_fb_invite_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void reward_station_fb_invite_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const reward_station_fb_invite_req& src = dynamic_cast<const reward_station_fb_invite_req&>(from);
    merge_from(src);
}

void reward_station_fb_invite_req::merge_from(const reward_station_fb_invite_req& from)
{
    if (&from == this)
    {
        return;
    }

    // fb_uuid
    set_fb_uuid(from.get_fb_uuid());
}

bool reward_station_fb_invite_req::serialize(SpringCat::System::Stream& output) const
{
    // fb_uuid
    if (SpringCat::Wave::internal::serialize(output, fb_uuid_) == false)
    {
        return false;
    }

    return true;
}

bool reward_station_fb_invite_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool reward_station_fb_invite_req::serialize(std::string& output) const
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

bool reward_station_fb_invite_req::deserialize(SpringCat::System::Stream& input)
{
    // fb_uuid
    if (SpringCat::Wave::internal::deserialize(input, fb_uuid_) == false)
    {
        return false;
    }

    return true;
}

bool reward_station_fb_invite_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool reward_station_fb_invite_req::deserialize(std::string& input)
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

SpringCat::uint64_t reward_station_fb_invite_req::get_fb_uuid(void) const
{
    return fb_uuid_;
}

void reward_station_fb_invite_req::set_fb_uuid(SpringCat::uint64_t value)
{
    fb_uuid_ = value;
}

reward_station_fb_invite_ans::reward_station_fb_invite_ans(void)
    : __has_bits__(),
    result_(0),
    updated_asset_info_(new asset_info)
{
}

reward_station_fb_invite_ans::reward_station_fb_invite_ans(const reward_station_fb_invite_ans& from)
    : __has_bits__(),
    result_(0),
    updated_asset_info_(new asset_info)
{
    merge_from(from);
}

reward_station_fb_invite_ans::~reward_station_fb_invite_ans(void)
{
}

const SpringCat::Wave::type_info& reward_station_fb_invite_ans::static_type_info(void)
{
    return __reward_station_fb_invite_ans_type_info__;
}

const SpringCat::Wave::type_info& reward_station_fb_invite_ans::runtime_type_info(void) const
{
    return static_type_info();
}

reward_station_fb_invite_ans* reward_station_fb_invite_ans::new_instance(void) const
{
    return new reward_station_fb_invite_ans;
}

reward_station_fb_invite_ans* reward_station_fb_invite_ans::clone(void) const
{
    return new reward_station_fb_invite_ans(*this);
}

void reward_station_fb_invite_ans::clear(void)
{
    // result
    result_ = 0;
    // updated_asset_info
    updated_asset_info_->clear();
}

bool reward_station_fb_invite_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t reward_station_fb_invite_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // updated_asset_info
    total_size += SpringCat::Wave::internal::size(*updated_asset_info_);

    return total_size;
}

void reward_station_fb_invite_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const reward_station_fb_invite_ans& src = dynamic_cast<const reward_station_fb_invite_ans&>(from);
    copy_from(src);
}

void reward_station_fb_invite_ans::copy_from(const reward_station_fb_invite_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void reward_station_fb_invite_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const reward_station_fb_invite_ans& src = dynamic_cast<const reward_station_fb_invite_ans&>(from);
    merge_from(src);
}

void reward_station_fb_invite_ans::merge_from(const reward_station_fb_invite_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // updated_asset_info
    updated_asset_info_->merge_from(*from.get_updated_asset_info());
}

bool reward_station_fb_invite_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // updated_asset_info
    if (SpringCat::Wave::internal::serialize(output, *updated_asset_info_) == false)
    {
        return false;
    }

    return true;
}

bool reward_station_fb_invite_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool reward_station_fb_invite_ans::serialize(std::string& output) const
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

bool reward_station_fb_invite_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // updated_asset_info
    if (SpringCat::Wave::internal::deserialize(input, *updated_asset_info_) == false)
    {
        return false;
    }

    return true;
}

bool reward_station_fb_invite_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool reward_station_fb_invite_ans::deserialize(std::string& input)
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

SpringCat::int16_t reward_station_fb_invite_ans::get_result(void) const
{
    return result_;
}

void reward_station_fb_invite_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

const asset_info* reward_station_fb_invite_ans::get_updated_asset_info(void) const
{
    return updated_asset_info_.get();
}

asset_info* reward_station_fb_invite_ans::get_mutable_updated_asset_info(void)
{
    return updated_asset_info_.get();
}

reward_station_gold_bonus_req::reward_station_gold_bonus_req(void)
    : __has_bits__(),
    use_dice_(false)
{
}

reward_station_gold_bonus_req::reward_station_gold_bonus_req(const reward_station_gold_bonus_req& from)
    : __has_bits__(),
    use_dice_(false)
{
    merge_from(from);
}

reward_station_gold_bonus_req::~reward_station_gold_bonus_req(void)
{
}

const SpringCat::Wave::type_info& reward_station_gold_bonus_req::static_type_info(void)
{
    return __reward_station_gold_bonus_req_type_info__;
}

const SpringCat::Wave::type_info& reward_station_gold_bonus_req::runtime_type_info(void) const
{
    return static_type_info();
}

reward_station_gold_bonus_req* reward_station_gold_bonus_req::new_instance(void) const
{
    return new reward_station_gold_bonus_req;
}

reward_station_gold_bonus_req* reward_station_gold_bonus_req::clone(void) const
{
    return new reward_station_gold_bonus_req(*this);
}

void reward_station_gold_bonus_req::clear(void)
{
    // use_dice
    use_dice_ = false;
}

bool reward_station_gold_bonus_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t reward_station_gold_bonus_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // use_dice
    total_size += SpringCat::Wave::internal::size(use_dice_);

    return total_size;
}

void reward_station_gold_bonus_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const reward_station_gold_bonus_req& src = dynamic_cast<const reward_station_gold_bonus_req&>(from);
    copy_from(src);
}

void reward_station_gold_bonus_req::copy_from(const reward_station_gold_bonus_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void reward_station_gold_bonus_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const reward_station_gold_bonus_req& src = dynamic_cast<const reward_station_gold_bonus_req&>(from);
    merge_from(src);
}

void reward_station_gold_bonus_req::merge_from(const reward_station_gold_bonus_req& from)
{
    if (&from == this)
    {
        return;
    }

    // use_dice
    set_use_dice(from.get_use_dice());
}

bool reward_station_gold_bonus_req::serialize(SpringCat::System::Stream& output) const
{
    // use_dice
    if (SpringCat::Wave::internal::serialize(output, use_dice_) == false)
    {
        return false;
    }

    return true;
}

bool reward_station_gold_bonus_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool reward_station_gold_bonus_req::serialize(std::string& output) const
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

bool reward_station_gold_bonus_req::deserialize(SpringCat::System::Stream& input)
{
    // use_dice
    if (SpringCat::Wave::internal::deserialize(input, use_dice_) == false)
    {
        return false;
    }

    return true;
}

bool reward_station_gold_bonus_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool reward_station_gold_bonus_req::deserialize(std::string& input)
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

bool reward_station_gold_bonus_req::get_use_dice(void) const
{
    return use_dice_;
}

void reward_station_gold_bonus_req::set_use_dice(bool value)
{
    use_dice_ = value;
}

reward_station_gold_bonus_ans::reward_station_gold_bonus_ans(void)
    : __has_bits__(),
    result_(0),
    acquired_gold_(0),
    updated_asset_info_(new asset_info)
{
}

reward_station_gold_bonus_ans::reward_station_gold_bonus_ans(const reward_station_gold_bonus_ans& from)
    : __has_bits__(),
    result_(0),
    acquired_gold_(0),
    updated_asset_info_(new asset_info)
{
    merge_from(from);
}

reward_station_gold_bonus_ans::~reward_station_gold_bonus_ans(void)
{
}

const SpringCat::Wave::type_info& reward_station_gold_bonus_ans::static_type_info(void)
{
    return __reward_station_gold_bonus_ans_type_info__;
}

const SpringCat::Wave::type_info& reward_station_gold_bonus_ans::runtime_type_info(void) const
{
    return static_type_info();
}

reward_station_gold_bonus_ans* reward_station_gold_bonus_ans::new_instance(void) const
{
    return new reward_station_gold_bonus_ans;
}

reward_station_gold_bonus_ans* reward_station_gold_bonus_ans::clone(void) const
{
    return new reward_station_gold_bonus_ans(*this);
}

void reward_station_gold_bonus_ans::clear(void)
{
    // result
    result_ = 0;
    // acquired_gold
    acquired_gold_ = 0;
    // updated_asset_info
    updated_asset_info_->clear();
}

bool reward_station_gold_bonus_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t reward_station_gold_bonus_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // acquired_gold
    total_size += SpringCat::Wave::internal::size(acquired_gold_);
    // updated_asset_info
    total_size += SpringCat::Wave::internal::size(*updated_asset_info_);

    return total_size;
}

void reward_station_gold_bonus_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const reward_station_gold_bonus_ans& src = dynamic_cast<const reward_station_gold_bonus_ans&>(from);
    copy_from(src);
}

void reward_station_gold_bonus_ans::copy_from(const reward_station_gold_bonus_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void reward_station_gold_bonus_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const reward_station_gold_bonus_ans& src = dynamic_cast<const reward_station_gold_bonus_ans&>(from);
    merge_from(src);
}

void reward_station_gold_bonus_ans::merge_from(const reward_station_gold_bonus_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // acquired_gold
    set_acquired_gold(from.get_acquired_gold());
    // updated_asset_info
    updated_asset_info_->merge_from(*from.get_updated_asset_info());
}

bool reward_station_gold_bonus_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // acquired_gold
    if (SpringCat::Wave::internal::serialize(output, acquired_gold_) == false)
    {
        return false;
    }
    // updated_asset_info
    if (SpringCat::Wave::internal::serialize(output, *updated_asset_info_) == false)
    {
        return false;
    }

    return true;
}

bool reward_station_gold_bonus_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool reward_station_gold_bonus_ans::serialize(std::string& output) const
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

bool reward_station_gold_bonus_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // acquired_gold
    if (SpringCat::Wave::internal::deserialize(input, acquired_gold_) == false)
    {
        return false;
    }
    // updated_asset_info
    if (SpringCat::Wave::internal::deserialize(input, *updated_asset_info_) == false)
    {
        return false;
    }

    return true;
}

bool reward_station_gold_bonus_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool reward_station_gold_bonus_ans::deserialize(std::string& input)
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

SpringCat::int16_t reward_station_gold_bonus_ans::get_result(void) const
{
    return result_;
}

void reward_station_gold_bonus_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

SpringCat::int16_t reward_station_gold_bonus_ans::get_acquired_gold(void) const
{
    return acquired_gold_;
}

void reward_station_gold_bonus_ans::set_acquired_gold(SpringCat::int16_t value)
{
    acquired_gold_ = value;
}

const asset_info* reward_station_gold_bonus_ans::get_updated_asset_info(void) const
{
    return updated_asset_info_.get();
}

asset_info* reward_station_gold_bonus_ans::get_mutable_updated_asset_info(void)
{
    return updated_asset_info_.get();
}



}    // namespace protocol
