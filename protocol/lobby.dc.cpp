#include "lobby.dc.h"
#include <stdexcept>


namespace protocol
{

// class name: connect_lobby_req, type id(decimal): 186005489, type id(hex): 0xB1637F1
static const SpringCat::Wave::type_info __connect_lobby_req_type_info__(0xB1637F1, "protocol.connect_lobby_req");
// class name: connect_lobby_ans, type id(decimal): 185993571, type id(hex): 0xB160963
static const SpringCat::Wave::type_info __connect_lobby_ans_type_info__(0xB160963, "protocol.connect_lobby_ans");
// class name: tutorial_progress_update_req, type id(decimal): 25612193, type id(hex): 0x186CFA1
static const SpringCat::Wave::type_info __tutorial_progress_update_req_type_info__(0x186CFA1, "protocol.tutorial_progress_update_req");
// class name: tutorial_progress_update_ans, type id(decimal): 25620787, type id(hex): 0x186F133
static const SpringCat::Wave::type_info __tutorial_progress_update_ans_type_info__(0x186F133, "protocol.tutorial_progress_update_ans");
// class name: first_vehicle_select_req, type id(decimal): 223507745, type id(hex): 0xD527521
static const SpringCat::Wave::type_info __first_vehicle_select_req_type_info__(0xD527521, "protocol.first_vehicle_select_req");
// class name: first_vehicle_select_ans, type id(decimal): 223497139, type id(hex): 0xD524BB3
static const SpringCat::Wave::type_info __first_vehicle_select_ans_type_info__(0xD524BB3, "protocol.first_vehicle_select_ans");
// class name: asset_info_req, type id(decimal): 196824849, type id(hex): 0xBBB4F11
static const SpringCat::Wave::type_info __asset_info_req_type_info__(0xBBB4F11, "protocol.asset_info_req");
// class name: asset_info_ans, type id(decimal): 196833667, type id(hex): 0xBBB7183
static const SpringCat::Wave::type_info __asset_info_ans_type_info__(0xBBB7183, "protocol.asset_info_ans");
// class name: match_item_buy_req, type id(decimal): 239768305, type id(hex): 0xE4A92F1
static const SpringCat::Wave::type_info __match_item_buy_req_type_info__(0xE4A92F1, "protocol.match_item_buy_req");
// class name: match_item_buy_ans, type id(decimal): 239775331, type id(hex): 0xE4AAE63
static const SpringCat::Wave::type_info __match_item_buy_ans_type_info__(0xE4AAE63, "protocol.match_item_buy_ans");
// class name: match_info_req, type id(decimal): 162532929, type id(hex): 0x9B00E41
static const SpringCat::Wave::type_info __match_info_req_type_info__(0x9B00E41, "protocol.match_info_req");
// class name: match_info_ans, type id(decimal): 162542291, type id(hex): 0x9B032D3
static const SpringCat::Wave::type_info __match_info_ans_type_info__(0x9B032D3, "protocol.match_info_ans");
// class name: match_start_req, type id(decimal): 221264561, type id(hex): 0xD303AB1
static const SpringCat::Wave::type_info __match_start_req_type_info__(0xD303AB1, "protocol.match_start_req");
// class name: match_start_ans, type id(decimal): 221251107, type id(hex): 0xD300623
static const SpringCat::Wave::type_info __match_start_ans_type_info__(0xD300623, "protocol.match_start_ans");
// class name: match_stop_req, type id(decimal): 138350049, type id(hex): 0x83F0DE1
static const SpringCat::Wave::type_info __match_stop_req_type_info__(0x83F0DE1, "protocol.match_stop_req");
// class name: match_stop_ans, type id(decimal): 138359667, type id(hex): 0x83F3373
static const SpringCat::Wave::type_info __match_stop_ans_type_info__(0x83F3373, "protocol.match_stop_ans");
// class name: match_complete_notify, type id(decimal): 95553433, type id(hex): 0x5B20799
static const SpringCat::Wave::type_info __match_complete_notify_type_info__(0x5B20799, "protocol.match_complete_notify");

connect_lobby_req::connect_lobby_req(void)
    : __has_bits__(),
    session_id_(0)
{
}

connect_lobby_req::connect_lobby_req(const connect_lobby_req& from)
    : __has_bits__(),
    session_id_(0)
{
    merge_from(from);
}

connect_lobby_req::~connect_lobby_req(void)
{
}

const SpringCat::Wave::type_info& connect_lobby_req::static_type_info(void)
{
    return __connect_lobby_req_type_info__;
}

const SpringCat::Wave::type_info& connect_lobby_req::runtime_type_info(void) const
{
    return static_type_info();
}

connect_lobby_req* connect_lobby_req::new_instance(void) const
{
    return new connect_lobby_req;
}

connect_lobby_req* connect_lobby_req::clone(void) const
{
    return new connect_lobby_req(*this);
}

void connect_lobby_req::clear(void)
{
    // session_id
    session_id_ = 0;
}

bool connect_lobby_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t connect_lobby_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // session_id
    total_size += SpringCat::Wave::internal::size(session_id_);

    return total_size;
}

void connect_lobby_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const connect_lobby_req& src = dynamic_cast<const connect_lobby_req&>(from);
    copy_from(src);
}

void connect_lobby_req::copy_from(const connect_lobby_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void connect_lobby_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const connect_lobby_req& src = dynamic_cast<const connect_lobby_req&>(from);
    merge_from(src);
}

void connect_lobby_req::merge_from(const connect_lobby_req& from)
{
    if (&from == this)
    {
        return;
    }

    // session_id
    set_session_id(from.get_session_id());
}

bool connect_lobby_req::serialize(SpringCat::System::Stream& output) const
{
    // session_id
    if (SpringCat::Wave::internal::serialize(output, session_id_) == false)
    {
        return false;
    }

    return true;
}

bool connect_lobby_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool connect_lobby_req::serialize(std::string& output) const
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

bool connect_lobby_req::deserialize(SpringCat::System::Stream& input)
{
    // session_id
    if (SpringCat::Wave::internal::deserialize(input, session_id_) == false)
    {
        return false;
    }

    return true;
}

bool connect_lobby_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool connect_lobby_req::deserialize(std::string& input)
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

SpringCat::int32_t connect_lobby_req::get_session_id(void) const
{
    return session_id_;
}

void connect_lobby_req::set_session_id(SpringCat::int32_t value)
{
    session_id_ = value;
}

connect_lobby_ans::connect_lobby_ans(void)
    : __has_bits__(),
    result_(0),
    player_no_(0)
{
}

connect_lobby_ans::connect_lobby_ans(const connect_lobby_ans& from)
    : __has_bits__(),
    result_(0),
    player_no_(0)
{
    merge_from(from);
}

connect_lobby_ans::~connect_lobby_ans(void)
{
}

const SpringCat::Wave::type_info& connect_lobby_ans::static_type_info(void)
{
    return __connect_lobby_ans_type_info__;
}

const SpringCat::Wave::type_info& connect_lobby_ans::runtime_type_info(void) const
{
    return static_type_info();
}

connect_lobby_ans* connect_lobby_ans::new_instance(void) const
{
    return new connect_lobby_ans;
}

connect_lobby_ans* connect_lobby_ans::clone(void) const
{
    return new connect_lobby_ans(*this);
}

void connect_lobby_ans::clear(void)
{
    // result
    result_ = 0;
    // player_no
    player_no_ = 0;
}

bool connect_lobby_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t connect_lobby_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // player_no
    total_size += SpringCat::Wave::internal::size(player_no_);

    return total_size;
}

void connect_lobby_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const connect_lobby_ans& src = dynamic_cast<const connect_lobby_ans&>(from);
    copy_from(src);
}

void connect_lobby_ans::copy_from(const connect_lobby_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void connect_lobby_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const connect_lobby_ans& src = dynamic_cast<const connect_lobby_ans&>(from);
    merge_from(src);
}

void connect_lobby_ans::merge_from(const connect_lobby_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // player_no
    set_player_no(from.get_player_no());
}

bool connect_lobby_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // player_no
    if (SpringCat::Wave::internal::serialize(output, player_no_) == false)
    {
        return false;
    }

    return true;
}

bool connect_lobby_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool connect_lobby_ans::serialize(std::string& output) const
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

bool connect_lobby_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // player_no
    if (SpringCat::Wave::internal::deserialize(input, player_no_) == false)
    {
        return false;
    }

    return true;
}

bool connect_lobby_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool connect_lobby_ans::deserialize(std::string& input)
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

SpringCat::int16_t connect_lobby_ans::get_result(void) const
{
    return result_;
}

void connect_lobby_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

SpringCat::uint64_t connect_lobby_ans::get_player_no(void) const
{
    return player_no_;
}

void connect_lobby_ans::set_player_no(SpringCat::uint64_t value)
{
    player_no_ = value;
}

tutorial_progress_update_req::tutorial_progress_update_req(void)
    : __has_bits__(),
    progress_(0)
{
}

tutorial_progress_update_req::tutorial_progress_update_req(const tutorial_progress_update_req& from)
    : __has_bits__(),
    progress_(0)
{
    merge_from(from);
}

tutorial_progress_update_req::~tutorial_progress_update_req(void)
{
}

const SpringCat::Wave::type_info& tutorial_progress_update_req::static_type_info(void)
{
    return __tutorial_progress_update_req_type_info__;
}

const SpringCat::Wave::type_info& tutorial_progress_update_req::runtime_type_info(void) const
{
    return static_type_info();
}

tutorial_progress_update_req* tutorial_progress_update_req::new_instance(void) const
{
    return new tutorial_progress_update_req;
}

tutorial_progress_update_req* tutorial_progress_update_req::clone(void) const
{
    return new tutorial_progress_update_req(*this);
}

void tutorial_progress_update_req::clear(void)
{
    // progress
    progress_ = 0;
}

bool tutorial_progress_update_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t tutorial_progress_update_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // progress
    total_size += SpringCat::Wave::internal::size(progress_);

    return total_size;
}

void tutorial_progress_update_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const tutorial_progress_update_req& src = dynamic_cast<const tutorial_progress_update_req&>(from);
    copy_from(src);
}

void tutorial_progress_update_req::copy_from(const tutorial_progress_update_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void tutorial_progress_update_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const tutorial_progress_update_req& src = dynamic_cast<const tutorial_progress_update_req&>(from);
    merge_from(src);
}

void tutorial_progress_update_req::merge_from(const tutorial_progress_update_req& from)
{
    if (&from == this)
    {
        return;
    }

    // progress
    set_progress(from.get_progress());
}

bool tutorial_progress_update_req::serialize(SpringCat::System::Stream& output) const
{
    // progress
    if (SpringCat::Wave::internal::serialize(output, progress_) == false)
    {
        return false;
    }

    return true;
}

bool tutorial_progress_update_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool tutorial_progress_update_req::serialize(std::string& output) const
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

bool tutorial_progress_update_req::deserialize(SpringCat::System::Stream& input)
{
    // progress
    if (SpringCat::Wave::internal::deserialize(input, progress_) == false)
    {
        return false;
    }

    return true;
}

bool tutorial_progress_update_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool tutorial_progress_update_req::deserialize(std::string& input)
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

TutorialProgress tutorial_progress_update_req::get_progress(void) const
{
    return static_cast<TutorialProgress>(progress_);
}

void tutorial_progress_update_req::set_progress(TutorialProgress value)
{
    progress_ = value;
}

tutorial_progress_update_ans::tutorial_progress_update_ans(void)
    : __has_bits__(),
    result_(0),
    progress_(0)
{
}

tutorial_progress_update_ans::tutorial_progress_update_ans(const tutorial_progress_update_ans& from)
    : __has_bits__(),
    result_(0),
    progress_(0)
{
    merge_from(from);
}

tutorial_progress_update_ans::~tutorial_progress_update_ans(void)
{
}

const SpringCat::Wave::type_info& tutorial_progress_update_ans::static_type_info(void)
{
    return __tutorial_progress_update_ans_type_info__;
}

const SpringCat::Wave::type_info& tutorial_progress_update_ans::runtime_type_info(void) const
{
    return static_type_info();
}

tutorial_progress_update_ans* tutorial_progress_update_ans::new_instance(void) const
{
    return new tutorial_progress_update_ans;
}

tutorial_progress_update_ans* tutorial_progress_update_ans::clone(void) const
{
    return new tutorial_progress_update_ans(*this);
}

void tutorial_progress_update_ans::clear(void)
{
    // result
    result_ = 0;
    // progress
    progress_ = 0;
}

bool tutorial_progress_update_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t tutorial_progress_update_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // progress
    total_size += SpringCat::Wave::internal::size(progress_);

    return total_size;
}

void tutorial_progress_update_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const tutorial_progress_update_ans& src = dynamic_cast<const tutorial_progress_update_ans&>(from);
    copy_from(src);
}

void tutorial_progress_update_ans::copy_from(const tutorial_progress_update_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void tutorial_progress_update_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const tutorial_progress_update_ans& src = dynamic_cast<const tutorial_progress_update_ans&>(from);
    merge_from(src);
}

void tutorial_progress_update_ans::merge_from(const tutorial_progress_update_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // progress
    set_progress(from.get_progress());
}

bool tutorial_progress_update_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // progress
    if (SpringCat::Wave::internal::serialize(output, progress_) == false)
    {
        return false;
    }

    return true;
}

bool tutorial_progress_update_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool tutorial_progress_update_ans::serialize(std::string& output) const
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

bool tutorial_progress_update_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // progress
    if (SpringCat::Wave::internal::deserialize(input, progress_) == false)
    {
        return false;
    }

    return true;
}

bool tutorial_progress_update_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool tutorial_progress_update_ans::deserialize(std::string& input)
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

SpringCat::int16_t tutorial_progress_update_ans::get_result(void) const
{
    return result_;
}

void tutorial_progress_update_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

TutorialProgress tutorial_progress_update_ans::get_progress(void) const
{
    return static_cast<TutorialProgress>(progress_);
}

void tutorial_progress_update_ans::set_progress(TutorialProgress value)
{
    progress_ = value;
}

first_vehicle_select_req::first_vehicle_select_req(void)
    : __has_bits__(),
    selected_vehicle_no_(0)
{
}

first_vehicle_select_req::first_vehicle_select_req(const first_vehicle_select_req& from)
    : __has_bits__(),
    selected_vehicle_no_(0)
{
    merge_from(from);
}

first_vehicle_select_req::~first_vehicle_select_req(void)
{
}

const SpringCat::Wave::type_info& first_vehicle_select_req::static_type_info(void)
{
    return __first_vehicle_select_req_type_info__;
}

const SpringCat::Wave::type_info& first_vehicle_select_req::runtime_type_info(void) const
{
    return static_type_info();
}

first_vehicle_select_req* first_vehicle_select_req::new_instance(void) const
{
    return new first_vehicle_select_req;
}

first_vehicle_select_req* first_vehicle_select_req::clone(void) const
{
    return new first_vehicle_select_req(*this);
}

void first_vehicle_select_req::clear(void)
{
    // selected_vehicle_no
    selected_vehicle_no_ = 0;
}

bool first_vehicle_select_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t first_vehicle_select_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // selected_vehicle_no
    total_size += SpringCat::Wave::internal::size(selected_vehicle_no_);

    return total_size;
}

void first_vehicle_select_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const first_vehicle_select_req& src = dynamic_cast<const first_vehicle_select_req&>(from);
    copy_from(src);
}

void first_vehicle_select_req::copy_from(const first_vehicle_select_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void first_vehicle_select_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const first_vehicle_select_req& src = dynamic_cast<const first_vehicle_select_req&>(from);
    merge_from(src);
}

void first_vehicle_select_req::merge_from(const first_vehicle_select_req& from)
{
    if (&from == this)
    {
        return;
    }

    // selected_vehicle_no
    set_selected_vehicle_no(from.get_selected_vehicle_no());
}

bool first_vehicle_select_req::serialize(SpringCat::System::Stream& output) const
{
    // selected_vehicle_no
    if (SpringCat::Wave::internal::serialize(output, selected_vehicle_no_) == false)
    {
        return false;
    }

    return true;
}

bool first_vehicle_select_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool first_vehicle_select_req::serialize(std::string& output) const
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

bool first_vehicle_select_req::deserialize(SpringCat::System::Stream& input)
{
    // selected_vehicle_no
    if (SpringCat::Wave::internal::deserialize(input, selected_vehicle_no_) == false)
    {
        return false;
    }

    return true;
}

bool first_vehicle_select_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool first_vehicle_select_req::deserialize(std::string& input)
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

SpringCat::int32_t first_vehicle_select_req::get_selected_vehicle_no(void) const
{
    return selected_vehicle_no_;
}

void first_vehicle_select_req::set_selected_vehicle_no(SpringCat::int32_t value)
{
    selected_vehicle_no_ = value;
}

first_vehicle_select_ans::first_vehicle_select_ans(void)
    : __has_bits__(),
    result_(0),
    selected_vehicle_(new vehicle)
{
}

first_vehicle_select_ans::first_vehicle_select_ans(const first_vehicle_select_ans& from)
    : __has_bits__(),
    result_(0),
    selected_vehicle_(new vehicle)
{
    merge_from(from);
}

first_vehicle_select_ans::~first_vehicle_select_ans(void)
{
}

const SpringCat::Wave::type_info& first_vehicle_select_ans::static_type_info(void)
{
    return __first_vehicle_select_ans_type_info__;
}

const SpringCat::Wave::type_info& first_vehicle_select_ans::runtime_type_info(void) const
{
    return static_type_info();
}

first_vehicle_select_ans* first_vehicle_select_ans::new_instance(void) const
{
    return new first_vehicle_select_ans;
}

first_vehicle_select_ans* first_vehicle_select_ans::clone(void) const
{
    return new first_vehicle_select_ans(*this);
}

void first_vehicle_select_ans::clear(void)
{
    // result
    result_ = 0;
    // selected_vehicle
    selected_vehicle_->clear();
}

bool first_vehicle_select_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t first_vehicle_select_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // selected_vehicle
    total_size += SpringCat::Wave::internal::size(*selected_vehicle_);

    return total_size;
}

void first_vehicle_select_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const first_vehicle_select_ans& src = dynamic_cast<const first_vehicle_select_ans&>(from);
    copy_from(src);
}

void first_vehicle_select_ans::copy_from(const first_vehicle_select_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void first_vehicle_select_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const first_vehicle_select_ans& src = dynamic_cast<const first_vehicle_select_ans&>(from);
    merge_from(src);
}

void first_vehicle_select_ans::merge_from(const first_vehicle_select_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // selected_vehicle
    selected_vehicle_->merge_from(*from.get_selected_vehicle());
}

bool first_vehicle_select_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // selected_vehicle
    if (SpringCat::Wave::internal::serialize(output, *selected_vehicle_) == false)
    {
        return false;
    }

    return true;
}

bool first_vehicle_select_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool first_vehicle_select_ans::serialize(std::string& output) const
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

bool first_vehicle_select_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // selected_vehicle
    if (SpringCat::Wave::internal::deserialize(input, *selected_vehicle_) == false)
    {
        return false;
    }

    return true;
}

bool first_vehicle_select_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool first_vehicle_select_ans::deserialize(std::string& input)
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

SpringCat::int16_t first_vehicle_select_ans::get_result(void) const
{
    return result_;
}

void first_vehicle_select_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

const vehicle* first_vehicle_select_ans::get_selected_vehicle(void) const
{
    return selected_vehicle_.get();
}

vehicle* first_vehicle_select_ans::get_mutable_selected_vehicle(void)
{
    return selected_vehicle_.get();
}

asset_info_req::asset_info_req(void)
    : __has_bits__(),
    player_no_(0)
{
}

asset_info_req::asset_info_req(const asset_info_req& from)
    : __has_bits__(),
    player_no_(0)
{
    merge_from(from);
}

asset_info_req::~asset_info_req(void)
{
}

const SpringCat::Wave::type_info& asset_info_req::static_type_info(void)
{
    return __asset_info_req_type_info__;
}

const SpringCat::Wave::type_info& asset_info_req::runtime_type_info(void) const
{
    return static_type_info();
}

asset_info_req* asset_info_req::new_instance(void) const
{
    return new asset_info_req;
}

asset_info_req* asset_info_req::clone(void) const
{
    return new asset_info_req(*this);
}

void asset_info_req::clear(void)
{
    // player_no
    player_no_ = 0;
}

bool asset_info_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t asset_info_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // player_no
    total_size += SpringCat::Wave::internal::size(player_no_);

    return total_size;
}

void asset_info_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const asset_info_req& src = dynamic_cast<const asset_info_req&>(from);
    copy_from(src);
}

void asset_info_req::copy_from(const asset_info_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void asset_info_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const asset_info_req& src = dynamic_cast<const asset_info_req&>(from);
    merge_from(src);
}

void asset_info_req::merge_from(const asset_info_req& from)
{
    if (&from == this)
    {
        return;
    }

    // player_no
    set_player_no(from.get_player_no());
}

bool asset_info_req::serialize(SpringCat::System::Stream& output) const
{
    // player_no
    if (SpringCat::Wave::internal::serialize(output, player_no_) == false)
    {
        return false;
    }

    return true;
}

bool asset_info_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool asset_info_req::serialize(std::string& output) const
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

bool asset_info_req::deserialize(SpringCat::System::Stream& input)
{
    // player_no
    if (SpringCat::Wave::internal::deserialize(input, player_no_) == false)
    {
        return false;
    }

    return true;
}

bool asset_info_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool asset_info_req::deserialize(std::string& input)
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

SpringCat::uint64_t asset_info_req::get_player_no(void) const
{
    return player_no_;
}

void asset_info_req::set_player_no(SpringCat::uint64_t value)
{
    player_no_ = value;
}

asset_info_ans::asset_info_ans(void)
    : __has_bits__(),
    result_(0),
    info_(new asset_info)
{
}

asset_info_ans::asset_info_ans(const asset_info_ans& from)
    : __has_bits__(),
    result_(0),
    info_(new asset_info)
{
    merge_from(from);
}

asset_info_ans::~asset_info_ans(void)
{
}

const SpringCat::Wave::type_info& asset_info_ans::static_type_info(void)
{
    return __asset_info_ans_type_info__;
}

const SpringCat::Wave::type_info& asset_info_ans::runtime_type_info(void) const
{
    return static_type_info();
}

asset_info_ans* asset_info_ans::new_instance(void) const
{
    return new asset_info_ans;
}

asset_info_ans* asset_info_ans::clone(void) const
{
    return new asset_info_ans(*this);
}

void asset_info_ans::clear(void)
{
    // result
    result_ = 0;
    // info
    info_->clear();
}

bool asset_info_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t asset_info_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // info
    total_size += SpringCat::Wave::internal::size(*info_);

    return total_size;
}

void asset_info_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const asset_info_ans& src = dynamic_cast<const asset_info_ans&>(from);
    copy_from(src);
}

void asset_info_ans::copy_from(const asset_info_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void asset_info_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const asset_info_ans& src = dynamic_cast<const asset_info_ans&>(from);
    merge_from(src);
}

void asset_info_ans::merge_from(const asset_info_ans& from)
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

bool asset_info_ans::serialize(SpringCat::System::Stream& output) const
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

bool asset_info_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool asset_info_ans::serialize(std::string& output) const
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

bool asset_info_ans::deserialize(SpringCat::System::Stream& input)
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

bool asset_info_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool asset_info_ans::deserialize(std::string& input)
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

SpringCat::int16_t asset_info_ans::get_result(void) const
{
    return result_;
}

void asset_info_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

const asset_info* asset_info_ans::get_info(void) const
{
    return info_.get();
}

asset_info* asset_info_ans::get_mutable_info(void)
{
    return info_.get();
}

match_item_buy_req::match_item_buy_req(void)
    : __has_bits__(),
    item_id_(0)
{
}

match_item_buy_req::match_item_buy_req(const match_item_buy_req& from)
    : __has_bits__(),
    item_id_(0)
{
    merge_from(from);
}

match_item_buy_req::~match_item_buy_req(void)
{
}

const SpringCat::Wave::type_info& match_item_buy_req::static_type_info(void)
{
    return __match_item_buy_req_type_info__;
}

const SpringCat::Wave::type_info& match_item_buy_req::runtime_type_info(void) const
{
    return static_type_info();
}

match_item_buy_req* match_item_buy_req::new_instance(void) const
{
    return new match_item_buy_req;
}

match_item_buy_req* match_item_buy_req::clone(void) const
{
    return new match_item_buy_req(*this);
}

void match_item_buy_req::clear(void)
{
    // item_id
    item_id_ = 0;
}

bool match_item_buy_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t match_item_buy_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // item_id
    total_size += SpringCat::Wave::internal::size(item_id_);

    return total_size;
}

void match_item_buy_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const match_item_buy_req& src = dynamic_cast<const match_item_buy_req&>(from);
    copy_from(src);
}

void match_item_buy_req::copy_from(const match_item_buy_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void match_item_buy_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const match_item_buy_req& src = dynamic_cast<const match_item_buy_req&>(from);
    merge_from(src);
}

void match_item_buy_req::merge_from(const match_item_buy_req& from)
{
    if (&from == this)
    {
        return;
    }

    // item_id
    set_item_id(from.get_item_id());
}

bool match_item_buy_req::serialize(SpringCat::System::Stream& output) const
{
    // item_id
    if (SpringCat::Wave::internal::serialize(output, item_id_) == false)
    {
        return false;
    }

    return true;
}

bool match_item_buy_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool match_item_buy_req::serialize(std::string& output) const
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

bool match_item_buy_req::deserialize(SpringCat::System::Stream& input)
{
    // item_id
    if (SpringCat::Wave::internal::deserialize(input, item_id_) == false)
    {
        return false;
    }

    return true;
}

bool match_item_buy_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool match_item_buy_req::deserialize(std::string& input)
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

SpringCat::int32_t match_item_buy_req::get_item_id(void) const
{
    return item_id_;
}

void match_item_buy_req::set_item_id(SpringCat::int32_t value)
{
    item_id_ = value;
}

match_item_buy_ans::match_item_buy_ans(void)
    : __has_bits__(),
    result_(0),
    updated_match_items_(new match_item_info),
    updated_asset_info_(new asset_info)
{
}

match_item_buy_ans::match_item_buy_ans(const match_item_buy_ans& from)
    : __has_bits__(),
    result_(0),
    updated_match_items_(new match_item_info),
    updated_asset_info_(new asset_info)
{
    merge_from(from);
}

match_item_buy_ans::~match_item_buy_ans(void)
{
}

const SpringCat::Wave::type_info& match_item_buy_ans::static_type_info(void)
{
    return __match_item_buy_ans_type_info__;
}

const SpringCat::Wave::type_info& match_item_buy_ans::runtime_type_info(void) const
{
    return static_type_info();
}

match_item_buy_ans* match_item_buy_ans::new_instance(void) const
{
    return new match_item_buy_ans;
}

match_item_buy_ans* match_item_buy_ans::clone(void) const
{
    return new match_item_buy_ans(*this);
}

void match_item_buy_ans::clear(void)
{
    // result
    result_ = 0;
    // updated_match_items
    updated_match_items_->clear();
    // updated_asset_info
    updated_asset_info_->clear();
}

bool match_item_buy_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t match_item_buy_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // updated_match_items
    total_size += SpringCat::Wave::internal::size(*updated_match_items_);
    // updated_asset_info
    total_size += SpringCat::Wave::internal::size(*updated_asset_info_);

    return total_size;
}

void match_item_buy_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const match_item_buy_ans& src = dynamic_cast<const match_item_buy_ans&>(from);
    copy_from(src);
}

void match_item_buy_ans::copy_from(const match_item_buy_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void match_item_buy_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const match_item_buy_ans& src = dynamic_cast<const match_item_buy_ans&>(from);
    merge_from(src);
}

void match_item_buy_ans::merge_from(const match_item_buy_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // updated_match_items
    updated_match_items_->merge_from(*from.get_updated_match_items());
    // updated_asset_info
    updated_asset_info_->merge_from(*from.get_updated_asset_info());
}

bool match_item_buy_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // updated_match_items
    if (SpringCat::Wave::internal::serialize(output, *updated_match_items_) == false)
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

bool match_item_buy_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool match_item_buy_ans::serialize(std::string& output) const
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

bool match_item_buy_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // updated_match_items
    if (SpringCat::Wave::internal::deserialize(input, *updated_match_items_) == false)
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

bool match_item_buy_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool match_item_buy_ans::deserialize(std::string& input)
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

SpringCat::int16_t match_item_buy_ans::get_result(void) const
{
    return result_;
}

void match_item_buy_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

const match_item_info* match_item_buy_ans::get_updated_match_items(void) const
{
    return updated_match_items_.get();
}

match_item_info* match_item_buy_ans::get_mutable_updated_match_items(void)
{
    return updated_match_items_.get();
}

const asset_info* match_item_buy_ans::get_updated_asset_info(void) const
{
    return updated_asset_info_.get();
}

asset_info* match_item_buy_ans::get_mutable_updated_asset_info(void)
{
    return updated_asset_info_.get();
}

match_info_req::match_info_req(void)
    : __has_bits__(),
    mode_(0)
{
}

match_info_req::match_info_req(const match_info_req& from)
    : __has_bits__(),
    mode_(0)
{
    merge_from(from);
}

match_info_req::~match_info_req(void)
{
}

const SpringCat::Wave::type_info& match_info_req::static_type_info(void)
{
    return __match_info_req_type_info__;
}

const SpringCat::Wave::type_info& match_info_req::runtime_type_info(void) const
{
    return static_type_info();
}

match_info_req* match_info_req::new_instance(void) const
{
    return new match_info_req;
}

match_info_req* match_info_req::clone(void) const
{
    return new match_info_req(*this);
}

void match_info_req::clear(void)
{
    // mode
    mode_ = 0;
}

bool match_info_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t match_info_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // mode
    total_size += SpringCat::Wave::internal::size(mode_);

    return total_size;
}

void match_info_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const match_info_req& src = dynamic_cast<const match_info_req&>(from);
    copy_from(src);
}

void match_info_req::copy_from(const match_info_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void match_info_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const match_info_req& src = dynamic_cast<const match_info_req&>(from);
    merge_from(src);
}

void match_info_req::merge_from(const match_info_req& from)
{
    if (&from == this)
    {
        return;
    }

    // mode
    set_mode(from.get_mode());
}

bool match_info_req::serialize(SpringCat::System::Stream& output) const
{
    // mode
    if (SpringCat::Wave::internal::serialize(output, mode_) == false)
    {
        return false;
    }

    return true;
}

bool match_info_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool match_info_req::serialize(std::string& output) const
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

bool match_info_req::deserialize(SpringCat::System::Stream& input)
{
    // mode
    if (SpringCat::Wave::internal::deserialize(input, mode_) == false)
    {
        return false;
    }

    return true;
}

bool match_info_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool match_info_req::deserialize(std::string& input)
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

GameMode match_info_req::get_mode(void) const
{
    return static_cast<GameMode>(mode_);
}

void match_info_req::set_mode(GameMode value)
{
    mode_ = value;
}

match_info_ans::match_info_ans(void)
    : __has_bits__(),
    result_(0),
    available_(),
    restricted_(),
    match_items_(new match_item_info)
{
}

match_info_ans::match_info_ans(const match_info_ans& from)
    : __has_bits__(),
    result_(0),
    available_(),
    restricted_(),
    match_items_(new match_item_info)
{
    merge_from(from);
}

match_info_ans::~match_info_ans(void)
{
    // available
    SpringCat::uint32_t available_size = static_cast<SpringCat::uint32_t>(available_.size());
    for (SpringCat::uint32_t i = 0; i != available_size; ++i)
    {
        delete available_[i];
    }
    available_.clear();
    // restricted
    SpringCat::uint32_t restricted_size = static_cast<SpringCat::uint32_t>(restricted_.size());
    for (SpringCat::uint32_t i = 0; i != restricted_size; ++i)
    {
        delete restricted_[i];
    }
    restricted_.clear();
}

const SpringCat::Wave::type_info& match_info_ans::static_type_info(void)
{
    return __match_info_ans_type_info__;
}

const SpringCat::Wave::type_info& match_info_ans::runtime_type_info(void) const
{
    return static_type_info();
}

match_info_ans* match_info_ans::new_instance(void) const
{
    return new match_info_ans;
}

match_info_ans* match_info_ans::clone(void) const
{
    return new match_info_ans(*this);
}

void match_info_ans::clear(void)
{
    // result
    result_ = 0;
    // available
    SpringCat::uint32_t available_size = static_cast<SpringCat::uint32_t>(available_.size());
    for (SpringCat::uint32_t i = 0; i != available_size; ++i)
    {
        delete available_[i];
    }
    available_.clear();
    // restricted
    SpringCat::uint32_t restricted_size = static_cast<SpringCat::uint32_t>(restricted_.size());
    for (SpringCat::uint32_t i = 0; i != restricted_size; ++i)
    {
        delete restricted_[i];
    }
    restricted_.clear();
    // match_items
    match_items_->clear();
}

bool match_info_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t match_info_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // available
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint32_t));
    SpringCat::uint32_t available_size = static_cast<SpringCat::uint32_t>(available_.size());
    for (SpringCat::uint32_t i = 0; i != available_size; ++i)
    {
        total_size += SpringCat::Wave::internal::size(*available_[i]);
    }
    // restricted
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint32_t));
    SpringCat::uint32_t restricted_size = static_cast<SpringCat::uint32_t>(restricted_.size());
    for (SpringCat::uint32_t i = 0; i != restricted_size; ++i)
    {
        total_size += SpringCat::Wave::internal::size(*restricted_[i]);
    }
    // match_items
    total_size += SpringCat::Wave::internal::size(*match_items_);

    return total_size;
}

void match_info_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const match_info_ans& src = dynamic_cast<const match_info_ans&>(from);
    copy_from(src);
}

void match_info_ans::copy_from(const match_info_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void match_info_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const match_info_ans& src = dynamic_cast<const match_info_ans&>(from);
    merge_from(src);
}

void match_info_ans::merge_from(const match_info_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // available
    SpringCat::uint32_t available_size = static_cast<SpringCat::uint32_t>(from.available_.size());
    available_.reserve(available_.size() + available_size);
    for (SpringCat::uint32_t i = 0; i != available_size; ++i)
    {
        available_.push_back(from.available_[i]->clone());
    }
    // restricted
    SpringCat::uint32_t restricted_size = static_cast<SpringCat::uint32_t>(from.restricted_.size());
    restricted_.reserve(restricted_.size() + restricted_size);
    for (SpringCat::uint32_t i = 0; i != restricted_size; ++i)
    {
        restricted_.push_back(from.restricted_[i]->clone());
    }
    // match_items
    match_items_->merge_from(*from.get_match_items());
}

bool match_info_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // available
    SpringCat::uint32_t available_size = static_cast<SpringCat::uint32_t>(available_.size());
    if (SpringCat::Wave::internal::serialize(output, available_size) == false)
    {
        return false;
    }
    for (SpringCat::uint32_t i = 0; i != available_size; ++i)
    {
        if (SpringCat::Wave::internal::serialize(output, *available_[i]) == false)
        {
            return false;
        }
    }
    // restricted
    SpringCat::uint32_t restricted_size = static_cast<SpringCat::uint32_t>(restricted_.size());
    if (SpringCat::Wave::internal::serialize(output, restricted_size) == false)
    {
        return false;
    }
    for (SpringCat::uint32_t i = 0; i != restricted_size; ++i)
    {
        if (SpringCat::Wave::internal::serialize(output, *restricted_[i]) == false)
        {
            return false;
        }
    }
    // match_items
    if (SpringCat::Wave::internal::serialize(output, *match_items_) == false)
    {
        return false;
    }

    return true;
}

bool match_info_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool match_info_ans::serialize(std::string& output) const
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

bool match_info_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // available
    SpringCat::uint32_t available_size = 0;
    if (SpringCat::Wave::internal::deserialize(input, available_size) == false)
    {
        return false;
    }
    if (available_size > 0)
    {
        available_.reserve(available_size);
        for (SpringCat::uint32_t i = 0; i != available_size; ++i)
        {
            std::auto_ptr<vehicle> new_available(new vehicle);
            if (SpringCat::Wave::internal::deserialize(input, *new_available) == false)
            {
                return false;
            }
            available_.push_back(new_available.release());
        }
    }
    // restricted
    SpringCat::uint32_t restricted_size = 0;
    if (SpringCat::Wave::internal::deserialize(input, restricted_size) == false)
    {
        return false;
    }
    if (restricted_size > 0)
    {
        restricted_.reserve(restricted_size);
        for (SpringCat::uint32_t i = 0; i != restricted_size; ++i)
        {
            std::auto_ptr<vehicle> new_restricted(new vehicle);
            if (SpringCat::Wave::internal::deserialize(input, *new_restricted) == false)
            {
                return false;
            }
            restricted_.push_back(new_restricted.release());
        }
    }
    // match_items
    if (SpringCat::Wave::internal::deserialize(input, *match_items_) == false)
    {
        return false;
    }

    return true;
}

bool match_info_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool match_info_ans::deserialize(std::string& input)
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

SpringCat::int16_t match_info_ans::get_result(void) const
{
    return result_;
}

void match_info_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

const std::vector<vehicle*>& match_info_ans::get_available(void) const
{
    return available_;
}

std::vector<vehicle*>* match_info_ans::get_mutable_available(void)
{
    return &available_;
}

const vehicle* match_info_ans::get_available(size_t index) const
{
    if (available_.size() <= index)
    {
        throw std::out_of_range("match_info_ans::available_ index outside range");
    }

    return available_[index];
}

vehicle* match_info_ans::get_mutable_available(size_t index)
{
    if (available_.size() <= index)
    {
        throw std::out_of_range("match_info_ans::available_ index outside range");
    }

    return available_[index];
}

vehicle* match_info_ans::add_available(void)
{
    std::auto_ptr<vehicle> new_available(new vehicle);
    available_.push_back(new_available.get());

    return new_available.release();
}

const std::vector<vehicle*>& match_info_ans::get_restricted(void) const
{
    return restricted_;
}

std::vector<vehicle*>* match_info_ans::get_mutable_restricted(void)
{
    return &restricted_;
}

const vehicle* match_info_ans::get_restricted(size_t index) const
{
    if (restricted_.size() <= index)
    {
        throw std::out_of_range("match_info_ans::restricted_ index outside range");
    }

    return restricted_[index];
}

vehicle* match_info_ans::get_mutable_restricted(size_t index)
{
    if (restricted_.size() <= index)
    {
        throw std::out_of_range("match_info_ans::restricted_ index outside range");
    }

    return restricted_[index];
}

vehicle* match_info_ans::add_restricted(void)
{
    std::auto_ptr<vehicle> new_restricted(new vehicle);
    restricted_.push_back(new_restricted.get());

    return new_restricted.release();
}

const match_item_info* match_info_ans::get_match_items(void) const
{
    return match_items_.get();
}

match_item_info* match_info_ans::get_mutable_match_items(void)
{
    return match_items_.get();
}

match_start_req::match_start_req(void)
    : __has_bits__(),
    mode_(0),
    using_match_items_(new match_item_info)
{
}

match_start_req::match_start_req(const match_start_req& from)
    : __has_bits__(),
    mode_(0),
    using_match_items_(new match_item_info)
{
    merge_from(from);
}

match_start_req::~match_start_req(void)
{
}

const SpringCat::Wave::type_info& match_start_req::static_type_info(void)
{
    return __match_start_req_type_info__;
}

const SpringCat::Wave::type_info& match_start_req::runtime_type_info(void) const
{
    return static_type_info();
}

match_start_req* match_start_req::new_instance(void) const
{
    return new match_start_req;
}

match_start_req* match_start_req::clone(void) const
{
    return new match_start_req(*this);
}

void match_start_req::clear(void)
{
    // mode
    mode_ = 0;
    // using_match_items
    using_match_items_->clear();
}

bool match_start_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t match_start_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // mode
    total_size += SpringCat::Wave::internal::size(mode_);
    // using_match_items
    total_size += SpringCat::Wave::internal::size(*using_match_items_);

    return total_size;
}

void match_start_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const match_start_req& src = dynamic_cast<const match_start_req&>(from);
    copy_from(src);
}

void match_start_req::copy_from(const match_start_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void match_start_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const match_start_req& src = dynamic_cast<const match_start_req&>(from);
    merge_from(src);
}

void match_start_req::merge_from(const match_start_req& from)
{
    if (&from == this)
    {
        return;
    }

    // mode
    set_mode(from.get_mode());
    // using_match_items
    using_match_items_->merge_from(*from.get_using_match_items());
}

bool match_start_req::serialize(SpringCat::System::Stream& output) const
{
    // mode
    if (SpringCat::Wave::internal::serialize(output, mode_) == false)
    {
        return false;
    }
    // using_match_items
    if (SpringCat::Wave::internal::serialize(output, *using_match_items_) == false)
    {
        return false;
    }

    return true;
}

bool match_start_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool match_start_req::serialize(std::string& output) const
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

bool match_start_req::deserialize(SpringCat::System::Stream& input)
{
    // mode
    if (SpringCat::Wave::internal::deserialize(input, mode_) == false)
    {
        return false;
    }
    // using_match_items
    if (SpringCat::Wave::internal::deserialize(input, *using_match_items_) == false)
    {
        return false;
    }

    return true;
}

bool match_start_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool match_start_req::deserialize(std::string& input)
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

GameMode match_start_req::get_mode(void) const
{
    return static_cast<GameMode>(mode_);
}

void match_start_req::set_mode(GameMode value)
{
    mode_ = value;
}

const match_item_info* match_start_req::get_using_match_items(void) const
{
    return using_match_items_.get();
}

match_item_info* match_start_req::get_mutable_using_match_items(void)
{
    return using_match_items_.get();
}

match_start_ans::match_start_ans(void)
    : __has_bits__(),
    result_(0),
    estimated_sec_(0)
{
}

match_start_ans::match_start_ans(const match_start_ans& from)
    : __has_bits__(),
    result_(0),
    estimated_sec_(0)
{
    merge_from(from);
}

match_start_ans::~match_start_ans(void)
{
}

const SpringCat::Wave::type_info& match_start_ans::static_type_info(void)
{
    return __match_start_ans_type_info__;
}

const SpringCat::Wave::type_info& match_start_ans::runtime_type_info(void) const
{
    return static_type_info();
}

match_start_ans* match_start_ans::new_instance(void) const
{
    return new match_start_ans;
}

match_start_ans* match_start_ans::clone(void) const
{
    return new match_start_ans(*this);
}

void match_start_ans::clear(void)
{
    // result
    result_ = 0;
    // estimated_sec
    estimated_sec_ = 0;
}

bool match_start_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t match_start_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // estimated_sec
    total_size += SpringCat::Wave::internal::size(estimated_sec_);

    return total_size;
}

void match_start_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const match_start_ans& src = dynamic_cast<const match_start_ans&>(from);
    copy_from(src);
}

void match_start_ans::copy_from(const match_start_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void match_start_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const match_start_ans& src = dynamic_cast<const match_start_ans&>(from);
    merge_from(src);
}

void match_start_ans::merge_from(const match_start_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // estimated_sec
    set_estimated_sec(from.get_estimated_sec());
}

bool match_start_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // estimated_sec
    if (SpringCat::Wave::internal::serialize(output, estimated_sec_) == false)
    {
        return false;
    }

    return true;
}

bool match_start_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool match_start_ans::serialize(std::string& output) const
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

bool match_start_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // estimated_sec
    if (SpringCat::Wave::internal::deserialize(input, estimated_sec_) == false)
    {
        return false;
    }

    return true;
}

bool match_start_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool match_start_ans::deserialize(std::string& input)
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

SpringCat::int16_t match_start_ans::get_result(void) const
{
    return result_;
}

void match_start_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

SpringCat::int32_t match_start_ans::get_estimated_sec(void) const
{
    return estimated_sec_;
}

void match_start_ans::set_estimated_sec(SpringCat::int32_t value)
{
    estimated_sec_ = value;
}

match_stop_req::match_stop_req(void)
    : __has_bits__(),
    mode_(0)
{
}

match_stop_req::match_stop_req(const match_stop_req& from)
    : __has_bits__(),
    mode_(0)
{
    merge_from(from);
}

match_stop_req::~match_stop_req(void)
{
}

const SpringCat::Wave::type_info& match_stop_req::static_type_info(void)
{
    return __match_stop_req_type_info__;
}

const SpringCat::Wave::type_info& match_stop_req::runtime_type_info(void) const
{
    return static_type_info();
}

match_stop_req* match_stop_req::new_instance(void) const
{
    return new match_stop_req;
}

match_stop_req* match_stop_req::clone(void) const
{
    return new match_stop_req(*this);
}

void match_stop_req::clear(void)
{
    // mode
    mode_ = 0;
}

bool match_stop_req::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t match_stop_req::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // mode
    total_size += SpringCat::Wave::internal::size(mode_);

    return total_size;
}

void match_stop_req::copy_from(const SpringCat::Wave::object_base& from)
{
    const match_stop_req& src = dynamic_cast<const match_stop_req&>(from);
    copy_from(src);
}

void match_stop_req::copy_from(const match_stop_req& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void match_stop_req::merge_from(const SpringCat::Wave::object_base& from)
{
    const match_stop_req& src = dynamic_cast<const match_stop_req&>(from);
    merge_from(src);
}

void match_stop_req::merge_from(const match_stop_req& from)
{
    if (&from == this)
    {
        return;
    }

    // mode
    set_mode(from.get_mode());
}

bool match_stop_req::serialize(SpringCat::System::Stream& output) const
{
    // mode
    if (SpringCat::Wave::internal::serialize(output, mode_) == false)
    {
        return false;
    }

    return true;
}

bool match_stop_req::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool match_stop_req::serialize(std::string& output) const
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

bool match_stop_req::deserialize(SpringCat::System::Stream& input)
{
    // mode
    if (SpringCat::Wave::internal::deserialize(input, mode_) == false)
    {
        return false;
    }

    return true;
}

bool match_stop_req::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool match_stop_req::deserialize(std::string& input)
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

GameMode match_stop_req::get_mode(void) const
{
    return static_cast<GameMode>(mode_);
}

void match_stop_req::set_mode(GameMode value)
{
    mode_ = value;
}

match_stop_ans::match_stop_ans(void)
    : __has_bits__(),
    result_(0)
{
}

match_stop_ans::match_stop_ans(const match_stop_ans& from)
    : __has_bits__(),
    result_(0)
{
    merge_from(from);
}

match_stop_ans::~match_stop_ans(void)
{
}

const SpringCat::Wave::type_info& match_stop_ans::static_type_info(void)
{
    return __match_stop_ans_type_info__;
}

const SpringCat::Wave::type_info& match_stop_ans::runtime_type_info(void) const
{
    return static_type_info();
}

match_stop_ans* match_stop_ans::new_instance(void) const
{
    return new match_stop_ans;
}

match_stop_ans* match_stop_ans::clone(void) const
{
    return new match_stop_ans(*this);
}

void match_stop_ans::clear(void)
{
    // result
    result_ = 0;
}

bool match_stop_ans::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t match_stop_ans::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);

    return total_size;
}

void match_stop_ans::copy_from(const SpringCat::Wave::object_base& from)
{
    const match_stop_ans& src = dynamic_cast<const match_stop_ans&>(from);
    copy_from(src);
}

void match_stop_ans::copy_from(const match_stop_ans& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void match_stop_ans::merge_from(const SpringCat::Wave::object_base& from)
{
    const match_stop_ans& src = dynamic_cast<const match_stop_ans&>(from);
    merge_from(src);
}

void match_stop_ans::merge_from(const match_stop_ans& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
}

bool match_stop_ans::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }

    return true;
}

bool match_stop_ans::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool match_stop_ans::serialize(std::string& output) const
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

bool match_stop_ans::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }

    return true;
}

bool match_stop_ans::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool match_stop_ans::deserialize(std::string& input)
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

SpringCat::int16_t match_stop_ans::get_result(void) const
{
    return result_;
}

void match_stop_ans::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

match_complete_notify::match_complete_notify(void)
    : __has_bits__(),
    result_(0),
    mode_(0),
    map_no_(0),
    use_standalone_(false),
    ps_addr_(new server_address),
    profiles_(),
    vehicles_(),
    equipped_ability_(),
    abilities_()
{
}

match_complete_notify::match_complete_notify(const match_complete_notify& from)
    : __has_bits__(),
    result_(0),
    mode_(0),
    map_no_(0),
    use_standalone_(false),
    ps_addr_(new server_address),
    profiles_(),
    vehicles_(),
    equipped_ability_(),
    abilities_()
{
    merge_from(from);
}

match_complete_notify::~match_complete_notify(void)
{
    // profiles
    for(std::map<SpringCat::uint64_t, player_profile_info*>::iterator it = profiles_.begin(); it != profiles_.end(); ++it)
    {
        delete it->second;
    }
    profiles_.clear();
    // vehicles
    for(std::map<SpringCat::uint64_t, vehicle*>::iterator it = vehicles_.begin(); it != vehicles_.end(); ++it)
    {
        delete it->second;
    }
    vehicles_.clear();
    // equipped_ability
    for(std::map<SpringCat::uint64_t, ability_slot*>::iterator it = equipped_ability_.begin(); it != equipped_ability_.end(); ++it)
    {
        delete it->second;
    }
    equipped_ability_.clear();
    // abilities
    for(std::map<SpringCat::uint64_t, ability_list*>::iterator it = abilities_.begin(); it != abilities_.end(); ++it)
    {
        delete it->second;
    }
    abilities_.clear();
}

const SpringCat::Wave::type_info& match_complete_notify::static_type_info(void)
{
    return __match_complete_notify_type_info__;
}

const SpringCat::Wave::type_info& match_complete_notify::runtime_type_info(void) const
{
    return static_type_info();
}

match_complete_notify* match_complete_notify::new_instance(void) const
{
    return new match_complete_notify;
}

match_complete_notify* match_complete_notify::clone(void) const
{
    return new match_complete_notify(*this);
}

void match_complete_notify::clear(void)
{
    // result
    result_ = 0;
    // mode
    mode_ = 0;
    // map_no
    map_no_ = 0;
    // use_standalone
    use_standalone_ = false;
    // ps_addr
    ps_addr_->clear();
    // profiles
    for(std::map<SpringCat::uint64_t, player_profile_info*>::iterator it = profiles_.begin(); it != profiles_.end(); ++it)
    {
        delete it->second;
    }
    profiles_.clear();
    // vehicles
    for(std::map<SpringCat::uint64_t, vehicle*>::iterator it = vehicles_.begin(); it != vehicles_.end(); ++it)
    {
        delete it->second;
    }
    vehicles_.clear();
    // equipped_ability
    for(std::map<SpringCat::uint64_t, ability_slot*>::iterator it = equipped_ability_.begin(); it != equipped_ability_.end(); ++it)
    {
        delete it->second;
    }
    equipped_ability_.clear();
    // abilities
    for(std::map<SpringCat::uint64_t, ability_list*>::iterator it = abilities_.begin(); it != abilities_.end(); ++it)
    {
        delete it->second;
    }
    abilities_.clear();
}

bool match_complete_notify::initialized(void) const
{
    //this call is not implemented yet

    return true;
}

SpringCat::uint32_t match_complete_notify::size(void) const
{
    SpringCat::uint32_t total_size = 0;

    // result
    total_size += SpringCat::Wave::internal::size(result_);
    // mode
    total_size += SpringCat::Wave::internal::size(mode_);
    // map_no
    total_size += SpringCat::Wave::internal::size(map_no_);
    // use_standalone
    total_size += SpringCat::Wave::internal::size(use_standalone_);
    // ps_addr
    total_size += SpringCat::Wave::internal::size(*ps_addr_);
    // profiles
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint32_t));
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint64_t) * profiles_.size());
    for(std::map<SpringCat::uint64_t, player_profile_info*>::const_iterator it = profiles_.begin(); it != profiles_.end(); ++it)
    {
        total_size += SpringCat::Wave::internal::size(*it->second);
    }
    // vehicles
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint32_t));
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint64_t) * vehicles_.size());
    for(std::map<SpringCat::uint64_t, vehicle*>::const_iterator it = vehicles_.begin(); it != vehicles_.end(); ++it)
    {
        total_size += SpringCat::Wave::internal::size(*it->second);
    }
    // equipped_ability
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint32_t));
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint64_t) * equipped_ability_.size());
    for(std::map<SpringCat::uint64_t, ability_slot*>::const_iterator it = equipped_ability_.begin(); it != equipped_ability_.end(); ++it)
    {
        total_size += SpringCat::Wave::internal::size(*it->second);
    }
    // abilities
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint32_t));
    total_size += static_cast<SpringCat::uint32_t>(sizeof(SpringCat::uint64_t) * abilities_.size());
    for(std::map<SpringCat::uint64_t, ability_list*>::const_iterator it = abilities_.begin(); it != abilities_.end(); ++it)
    {
        total_size += SpringCat::Wave::internal::size(*it->second);
    }

    return total_size;
}

void match_complete_notify::copy_from(const SpringCat::Wave::object_base& from)
{
    const match_complete_notify& src = dynamic_cast<const match_complete_notify&>(from);
    copy_from(src);
}

void match_complete_notify::copy_from(const match_complete_notify& from)
{
    if (&from == this)
    {
        return;
    }

    clear();
    merge_from(from);
}

void match_complete_notify::merge_from(const SpringCat::Wave::object_base& from)
{
    const match_complete_notify& src = dynamic_cast<const match_complete_notify&>(from);
    merge_from(src);
}

void match_complete_notify::merge_from(const match_complete_notify& from)
{
    if (&from == this)
    {
        return;
    }

    // result
    set_result(from.get_result());
    // mode
    set_mode(from.get_mode());
    // map_no
    set_map_no(from.get_map_no());
    // use_standalone
    set_use_standalone(from.get_use_standalone());
    // ps_addr
    ps_addr_->merge_from(*from.get_ps_addr());
    // profiles
    for(std::map<SpringCat::uint64_t, player_profile_info*>::const_iterator it = from.profiles_.begin(); it != from.profiles_.end(); ++it)
    {
        insert_profiles(it->first)->copy_from(*it->second);
    }
    // vehicles
    for(std::map<SpringCat::uint64_t, vehicle*>::const_iterator it = from.vehicles_.begin(); it != from.vehicles_.end(); ++it)
    {
        insert_vehicles(it->first)->copy_from(*it->second);
    }
    // equipped_ability
    for(std::map<SpringCat::uint64_t, ability_slot*>::const_iterator it = from.equipped_ability_.begin(); it != from.equipped_ability_.end(); ++it)
    {
        insert_equipped_ability(it->first)->copy_from(*it->second);
    }
    // abilities
    for(std::map<SpringCat::uint64_t, ability_list*>::const_iterator it = from.abilities_.begin(); it != from.abilities_.end(); ++it)
    {
        insert_abilities(it->first)->copy_from(*it->second);
    }
}

bool match_complete_notify::serialize(SpringCat::System::Stream& output) const
{
    // result
    if (SpringCat::Wave::internal::serialize(output, result_) == false)
    {
        return false;
    }
    // mode
    if (SpringCat::Wave::internal::serialize(output, mode_) == false)
    {
        return false;
    }
    // map_no
    if (SpringCat::Wave::internal::serialize(output, map_no_) == false)
    {
        return false;
    }
    // use_standalone
    if (SpringCat::Wave::internal::serialize(output, use_standalone_) == false)
    {
        return false;
    }
    // ps_addr
    if (SpringCat::Wave::internal::serialize(output, *ps_addr_) == false)
    {
        return false;
    }
    // profiles
    SpringCat::uint32_t profiles_size = static_cast<SpringCat::uint32_t>(profiles_.size());
    if (SpringCat::Wave::internal::serialize(output, profiles_size) == false)
    {
        return false;
    }
    for(std::map<SpringCat::uint64_t, player_profile_info*>::const_iterator it = profiles_.begin(); it != profiles_.end(); ++it)
    {
        if (SpringCat::Wave::internal::serialize(output, it->first) == false)
        {
            return false;
        }
        if (SpringCat::Wave::internal::serialize(output, *it->second) == false)
        {
            return false;
        }
    }
    // vehicles
    SpringCat::uint32_t vehicles_size = static_cast<SpringCat::uint32_t>(vehicles_.size());
    if (SpringCat::Wave::internal::serialize(output, vehicles_size) == false)
    {
        return false;
    }
    for(std::map<SpringCat::uint64_t, vehicle*>::const_iterator it = vehicles_.begin(); it != vehicles_.end(); ++it)
    {
        if (SpringCat::Wave::internal::serialize(output, it->first) == false)
        {
            return false;
        }
        if (SpringCat::Wave::internal::serialize(output, *it->second) == false)
        {
            return false;
        }
    }
    // equipped_ability
    SpringCat::uint32_t equipped_ability_size = static_cast<SpringCat::uint32_t>(equipped_ability_.size());
    if (SpringCat::Wave::internal::serialize(output, equipped_ability_size) == false)
    {
        return false;
    }
    for(std::map<SpringCat::uint64_t, ability_slot*>::const_iterator it = equipped_ability_.begin(); it != equipped_ability_.end(); ++it)
    {
        if (SpringCat::Wave::internal::serialize(output, it->first) == false)
        {
            return false;
        }
        if (SpringCat::Wave::internal::serialize(output, *it->second) == false)
        {
            return false;
        }
    }
    // abilities
    SpringCat::uint32_t abilities_size = static_cast<SpringCat::uint32_t>(abilities_.size());
    if (SpringCat::Wave::internal::serialize(output, abilities_size) == false)
    {
        return false;
    }
    for(std::map<SpringCat::uint64_t, ability_list*>::const_iterator it = abilities_.begin(); it != abilities_.end(); ++it)
    {
        if (SpringCat::Wave::internal::serialize(output, it->first) == false)
        {
            return false;
        }
        if (SpringCat::Wave::internal::serialize(output, *it->second) == false)
        {
            return false;
        }
    }

    return true;
}

bool match_complete_notify::serialize(std::ostream& output) const
{
    //this call is not implemented yet

    return true;
}

bool match_complete_notify::serialize(std::string& output) const
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

bool match_complete_notify::deserialize(SpringCat::System::Stream& input)
{
    // result
    if (SpringCat::Wave::internal::deserialize(input, result_) == false)
    {
        return false;
    }
    // mode
    if (SpringCat::Wave::internal::deserialize(input, mode_) == false)
    {
        return false;
    }
    // map_no
    if (SpringCat::Wave::internal::deserialize(input, map_no_) == false)
    {
        return false;
    }
    // use_standalone
    if (SpringCat::Wave::internal::deserialize(input, use_standalone_) == false)
    {
        return false;
    }
    // ps_addr
    if (SpringCat::Wave::internal::deserialize(input, *ps_addr_) == false)
    {
        return false;
    }
    // profiles
    SpringCat::uint32_t profiles_size = 0;
    if (SpringCat::Wave::internal::deserialize(input, profiles_size) == false)
    {
        return false;
    }
    for (SpringCat::uint32_t i = 0; i != profiles_size; ++i)
    {
        SpringCat::uint64_t key;
        if (SpringCat::Wave::internal::deserialize(input, key) == false)
        {
            return false;
        }
        player_profile_info* inserted = insert_profiles(key);
        if (SpringCat::Wave::internal::deserialize(input, *inserted) == false)
        {
        	return false;
        }
    }
    // vehicles
    SpringCat::uint32_t vehicles_size = 0;
    if (SpringCat::Wave::internal::deserialize(input, vehicles_size) == false)
    {
        return false;
    }
    for (SpringCat::uint32_t i = 0; i != vehicles_size; ++i)
    {
        SpringCat::uint64_t key;
        if (SpringCat::Wave::internal::deserialize(input, key) == false)
        {
            return false;
        }
        vehicle* inserted = insert_vehicles(key);
        if (SpringCat::Wave::internal::deserialize(input, *inserted) == false)
        {
        	return false;
        }
    }
    // equipped_ability
    SpringCat::uint32_t equipped_ability_size = 0;
    if (SpringCat::Wave::internal::deserialize(input, equipped_ability_size) == false)
    {
        return false;
    }
    for (SpringCat::uint32_t i = 0; i != equipped_ability_size; ++i)
    {
        SpringCat::uint64_t key;
        if (SpringCat::Wave::internal::deserialize(input, key) == false)
        {
            return false;
        }
        ability_slot* inserted = insert_equipped_ability(key);
        if (SpringCat::Wave::internal::deserialize(input, *inserted) == false)
        {
        	return false;
        }
    }
    // abilities
    SpringCat::uint32_t abilities_size = 0;
    if (SpringCat::Wave::internal::deserialize(input, abilities_size) == false)
    {
        return false;
    }
    for (SpringCat::uint32_t i = 0; i != abilities_size; ++i)
    {
        SpringCat::uint64_t key;
        if (SpringCat::Wave::internal::deserialize(input, key) == false)
        {
            return false;
        }
        ability_list* inserted = insert_abilities(key);
        if (SpringCat::Wave::internal::deserialize(input, *inserted) == false)
        {
        	return false;
        }
    }

    return true;
}

bool match_complete_notify::deserialize(std::ostream& input)
{
    //this call is not implemented yet

    return true;
}

bool match_complete_notify::deserialize(std::string& input)
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

SpringCat::int16_t match_complete_notify::get_result(void) const
{
    return result_;
}

void match_complete_notify::set_result(SpringCat::int16_t value)
{
    result_ = value;
}

GameMode match_complete_notify::get_mode(void) const
{
    return static_cast<GameMode>(mode_);
}

void match_complete_notify::set_mode(GameMode value)
{
    mode_ = value;
}

SpringCat::int32_t match_complete_notify::get_map_no(void) const
{
    return map_no_;
}

void match_complete_notify::set_map_no(SpringCat::int32_t value)
{
    map_no_ = value;
}

bool match_complete_notify::get_use_standalone(void) const
{
    return use_standalone_;
}

void match_complete_notify::set_use_standalone(bool value)
{
    use_standalone_ = value;
}

const server_address* match_complete_notify::get_ps_addr(void) const
{
    return ps_addr_.get();
}

server_address* match_complete_notify::get_mutable_ps_addr(void)
{
    return ps_addr_.get();
}

const std::map<SpringCat::uint64_t, player_profile_info*>& match_complete_notify::get_profiles(void) const
{
    return profiles_;
}

std::map<SpringCat::uint64_t, player_profile_info*>* match_complete_notify::get_mutable_profiles(void)
{
    return &profiles_;
}

const player_profile_info* match_complete_notify::get_profiles(SpringCat::uint64_t key) const
{
    std::map<SpringCat::uint64_t, player_profile_info*>::const_iterator it = profiles_.find(key);
    if(it == profiles_.end())
    {
        return NULL;
    }
    return it->second;
}

player_profile_info* match_complete_notify::get_mutable_profiles(SpringCat::uint64_t key)
{
    std::map<SpringCat::uint64_t, player_profile_info*>::iterator it = profiles_.find(key);
    if(it == profiles_.end())
    {
        return NULL;
    }
    return it->second;
}

player_profile_info* match_complete_notify::insert_profiles(SpringCat::uint64_t key)
{
    std::map<SpringCat::uint64_t, player_profile_info*>::iterator it = profiles_.find(key);
    if(it != profiles_.end())
    {
        return it->second;
    }
    std::auto_ptr<player_profile_info> new_profiles(new player_profile_info);
    profiles_.insert(std::make_pair(key, new_profiles.get()));
    return new_profiles.release();
}

const std::map<SpringCat::uint64_t, vehicle*>& match_complete_notify::get_vehicles(void) const
{
    return vehicles_;
}

std::map<SpringCat::uint64_t, vehicle*>* match_complete_notify::get_mutable_vehicles(void)
{
    return &vehicles_;
}

const vehicle* match_complete_notify::get_vehicles(SpringCat::uint64_t key) const
{
    std::map<SpringCat::uint64_t, vehicle*>::const_iterator it = vehicles_.find(key);
    if(it == vehicles_.end())
    {
        return NULL;
    }
    return it->second;
}

vehicle* match_complete_notify::get_mutable_vehicles(SpringCat::uint64_t key)
{
    std::map<SpringCat::uint64_t, vehicle*>::iterator it = vehicles_.find(key);
    if(it == vehicles_.end())
    {
        return NULL;
    }
    return it->second;
}

vehicle* match_complete_notify::insert_vehicles(SpringCat::uint64_t key)
{
    std::map<SpringCat::uint64_t, vehicle*>::iterator it = vehicles_.find(key);
    if(it != vehicles_.end())
    {
        return it->second;
    }
    std::auto_ptr<vehicle> new_vehicles(new vehicle);
    vehicles_.insert(std::make_pair(key, new_vehicles.get()));
    return new_vehicles.release();
}

const std::map<SpringCat::uint64_t, ability_slot*>& match_complete_notify::get_equipped_ability(void) const
{
    return equipped_ability_;
}

std::map<SpringCat::uint64_t, ability_slot*>* match_complete_notify::get_mutable_equipped_ability(void)
{
    return &equipped_ability_;
}

const ability_slot* match_complete_notify::get_equipped_ability(SpringCat::uint64_t key) const
{
    std::map<SpringCat::uint64_t, ability_slot*>::const_iterator it = equipped_ability_.find(key);
    if(it == equipped_ability_.end())
    {
        return NULL;
    }
    return it->second;
}

ability_slot* match_complete_notify::get_mutable_equipped_ability(SpringCat::uint64_t key)
{
    std::map<SpringCat::uint64_t, ability_slot*>::iterator it = equipped_ability_.find(key);
    if(it == equipped_ability_.end())
    {
        return NULL;
    }
    return it->second;
}

ability_slot* match_complete_notify::insert_equipped_ability(SpringCat::uint64_t key)
{
    std::map<SpringCat::uint64_t, ability_slot*>::iterator it = equipped_ability_.find(key);
    if(it != equipped_ability_.end())
    {
        return it->second;
    }
    std::auto_ptr<ability_slot> new_equipped_ability(new ability_slot);
    equipped_ability_.insert(std::make_pair(key, new_equipped_ability.get()));
    return new_equipped_ability.release();
}

const std::map<SpringCat::uint64_t, ability_list*>& match_complete_notify::get_abilities(void) const
{
    return abilities_;
}

std::map<SpringCat::uint64_t, ability_list*>* match_complete_notify::get_mutable_abilities(void)
{
    return &abilities_;
}

const ability_list* match_complete_notify::get_abilities(SpringCat::uint64_t key) const
{
    std::map<SpringCat::uint64_t, ability_list*>::const_iterator it = abilities_.find(key);
    if(it == abilities_.end())
    {
        return NULL;
    }
    return it->second;
}

ability_list* match_complete_notify::get_mutable_abilities(SpringCat::uint64_t key)
{
    std::map<SpringCat::uint64_t, ability_list*>::iterator it = abilities_.find(key);
    if(it == abilities_.end())
    {
        return NULL;
    }
    return it->second;
}

ability_list* match_complete_notify::insert_abilities(SpringCat::uint64_t key)
{
    std::map<SpringCat::uint64_t, ability_list*>::iterator it = abilities_.find(key);
    if(it != abilities_.end())
    {
        return it->second;
    }
    std::auto_ptr<ability_list> new_abilities(new ability_list);
    abilities_.insert(std::make_pair(key, new_abilities.get()));
    return new_abilities.release();
}



}    // namespace protocol
