// Generated by the SpringCat.Wave compiler. DO NOT EDIT!

#ifndef __SPRINGCAT_WAVE_AUTH_DC_H_INCLUDE__
#define __SPRINGCAT_WAVE_AUTH_DC_H_INCLUDE__

#include <SpringCat/SpringCat.h>

#include "common_def.dc.h"

namespace protocol
{

class session_key_req;
class session_key_ans;
class login_req;
class login_ans;
class logout_req;
class logout_ans;
class heartbeat;
class quit_req;
class quit_ans;

// ================================================================================================

class session_key_req : public SpringCat::Wave::object_base
{
private:
    SpringCat::Wave::internal::bitset<0> __has_bits__;

private:

public:
    session_key_req(void);
    session_key_req(const session_key_req& from);
    virtual ~session_key_req(void);

    inline session_key_req& operator=(const session_key_req& rhs)
    {
        copy_from(rhs);
        return *this;
    }

    static const SpringCat::Wave::type_info& static_type_info(void);
    virtual const SpringCat::Wave::type_info& runtime_type_info(void) const;

    virtual session_key_req* new_instance(void) const;
    virtual session_key_req* clone(void) const;

    virtual void clear(void);

    virtual bool initialized(void) const;
    virtual SpringCat::uint32_t size(void) const;

    virtual void copy_from(const SpringCat::Wave::object_base& from);
    virtual void merge_from(const SpringCat::Wave::object_base& from);
    void copy_from(const session_key_req& from);
    void merge_from(const session_key_req& from);

    virtual bool serialize(SpringCat::System::Stream& output) const;
    virtual bool serialize(std::ostream& output) const;
    virtual bool serialize(std::string& output) const;

    virtual bool deserialize(SpringCat::System::Stream& input);
    virtual bool deserialize(std::ostream& input);
    virtual bool deserialize(std::string& input);
};
// ------------------------------------------------------------------------------------------------

class session_key_ans : public SpringCat::Wave::object_base
{
private:
    SpringCat::Wave::internal::bitset<2> __has_bits__;

private:
    std::vector<SpringCat::uint8_t> key_;
    std::vector<SpringCat::uint8_t> iv_;

public:
    session_key_ans(void);
    session_key_ans(const session_key_ans& from);
    virtual ~session_key_ans(void);

    inline session_key_ans& operator=(const session_key_ans& rhs)
    {
        copy_from(rhs);
        return *this;
    }

    static const SpringCat::Wave::type_info& static_type_info(void);
    virtual const SpringCat::Wave::type_info& runtime_type_info(void) const;

    virtual session_key_ans* new_instance(void) const;
    virtual session_key_ans* clone(void) const;

    virtual void clear(void);

    virtual bool initialized(void) const;
    virtual SpringCat::uint32_t size(void) const;

    virtual void copy_from(const SpringCat::Wave::object_base& from);
    virtual void merge_from(const SpringCat::Wave::object_base& from);
    void copy_from(const session_key_ans& from);
    void merge_from(const session_key_ans& from);

    virtual bool serialize(SpringCat::System::Stream& output) const;
    virtual bool serialize(std::ostream& output) const;
    virtual bool serialize(std::string& output) const;

    virtual bool deserialize(SpringCat::System::Stream& input);
    virtual bool deserialize(std::ostream& input);
    virtual bool deserialize(std::string& input);

    // key
    const std::vector<SpringCat::uint8_t>& get_key(void) const;
    std::vector<SpringCat::uint8_t>* get_mutable_key(void);
    SpringCat::uint8_t get_key(size_t index) const;
    void set_key(size_t index, SpringCat::uint8_t value);
    void add_key(SpringCat::uint8_t value);

    // iv
    const std::vector<SpringCat::uint8_t>& get_iv(void) const;
    std::vector<SpringCat::uint8_t>* get_mutable_iv(void);
    SpringCat::uint8_t get_iv(size_t index) const;
    void set_iv(size_t index, SpringCat::uint8_t value);
    void add_iv(SpringCat::uint8_t value);
};
// ------------------------------------------------------------------------------------------------

class login_req : public SpringCat::Wave::object_base
{
private:
    SpringCat::Wave::internal::bitset<3> __has_bits__;

private:
    SpringCat::int32_t login_type_;
    SpringCat::int16_t version_;
    std::string acc_token_;

public:
    login_req(void);
    login_req(const login_req& from);
    virtual ~login_req(void);

    inline login_req& operator=(const login_req& rhs)
    {
        copy_from(rhs);
        return *this;
    }

    static const SpringCat::Wave::type_info& static_type_info(void);
    virtual const SpringCat::Wave::type_info& runtime_type_info(void) const;

    virtual login_req* new_instance(void) const;
    virtual login_req* clone(void) const;

    virtual void clear(void);

    virtual bool initialized(void) const;
    virtual SpringCat::uint32_t size(void) const;

    virtual void copy_from(const SpringCat::Wave::object_base& from);
    virtual void merge_from(const SpringCat::Wave::object_base& from);
    void copy_from(const login_req& from);
    void merge_from(const login_req& from);

    virtual bool serialize(SpringCat::System::Stream& output) const;
    virtual bool serialize(std::ostream& output) const;
    virtual bool serialize(std::string& output) const;

    virtual bool deserialize(SpringCat::System::Stream& input);
    virtual bool deserialize(std::ostream& input);
    virtual bool deserialize(std::string& input);

    // login_type
    LoginType get_login_type(void) const;
    void set_login_type(LoginType value);

    // version
    SpringCat::int16_t get_version(void) const;
    void set_version(SpringCat::int16_t value);

    // acc_token
    const std::string& get_acc_token(void) const;
    std::string* get_mutable_acc_token(void);
    void set_acc_token(const std::string& value);
    void set_acc_token(const char* value);
};
// ------------------------------------------------------------------------------------------------

class login_ans : public SpringCat::Wave::object_base
{
private:
    SpringCat::Wave::internal::bitset<5> __has_bits__;

private:
    SpringCat::int16_t result_;
    SpringCat::int32_t session_id_;
    SpringCat::int64_t server_timestamp_;
    std::auto_ptr<server_address> assigned_ls_addr_;
    SpringCat::int32_t progress_;

public:
    login_ans(void);
    login_ans(const login_ans& from);
    virtual ~login_ans(void);

    inline login_ans& operator=(const login_ans& rhs)
    {
        copy_from(rhs);
        return *this;
    }

    static const SpringCat::Wave::type_info& static_type_info(void);
    virtual const SpringCat::Wave::type_info& runtime_type_info(void) const;

    virtual login_ans* new_instance(void) const;
    virtual login_ans* clone(void) const;

    virtual void clear(void);

    virtual bool initialized(void) const;
    virtual SpringCat::uint32_t size(void) const;

    virtual void copy_from(const SpringCat::Wave::object_base& from);
    virtual void merge_from(const SpringCat::Wave::object_base& from);
    void copy_from(const login_ans& from);
    void merge_from(const login_ans& from);

    virtual bool serialize(SpringCat::System::Stream& output) const;
    virtual bool serialize(std::ostream& output) const;
    virtual bool serialize(std::string& output) const;

    virtual bool deserialize(SpringCat::System::Stream& input);
    virtual bool deserialize(std::ostream& input);
    virtual bool deserialize(std::string& input);

    // result
    SpringCat::int16_t get_result(void) const;
    void set_result(SpringCat::int16_t value);

    // session_id
    SpringCat::int32_t get_session_id(void) const;
    void set_session_id(SpringCat::int32_t value);

    // server_timestamp
    SpringCat::int64_t get_server_timestamp(void) const;
    void set_server_timestamp(SpringCat::int64_t value);

    // assigned_ls_addr
    const server_address* get_assigned_ls_addr(void) const;
    server_address* get_mutable_assigned_ls_addr(void);

    // progress
    TutorialProgress get_progress(void) const;
    void set_progress(TutorialProgress value);
};
// ------------------------------------------------------------------------------------------------

class logout_req : public SpringCat::Wave::object_base
{
private:
    SpringCat::Wave::internal::bitset<1> __has_bits__;

private:
    SpringCat::int32_t session_id_;

public:
    logout_req(void);
    logout_req(const logout_req& from);
    virtual ~logout_req(void);

    inline logout_req& operator=(const logout_req& rhs)
    {
        copy_from(rhs);
        return *this;
    }

    static const SpringCat::Wave::type_info& static_type_info(void);
    virtual const SpringCat::Wave::type_info& runtime_type_info(void) const;

    virtual logout_req* new_instance(void) const;
    virtual logout_req* clone(void) const;

    virtual void clear(void);

    virtual bool initialized(void) const;
    virtual SpringCat::uint32_t size(void) const;

    virtual void copy_from(const SpringCat::Wave::object_base& from);
    virtual void merge_from(const SpringCat::Wave::object_base& from);
    void copy_from(const logout_req& from);
    void merge_from(const logout_req& from);

    virtual bool serialize(SpringCat::System::Stream& output) const;
    virtual bool serialize(std::ostream& output) const;
    virtual bool serialize(std::string& output) const;

    virtual bool deserialize(SpringCat::System::Stream& input);
    virtual bool deserialize(std::ostream& input);
    virtual bool deserialize(std::string& input);

    // session_id
    SpringCat::int32_t get_session_id(void) const;
    void set_session_id(SpringCat::int32_t value);
};
// ------------------------------------------------------------------------------------------------

class logout_ans : public SpringCat::Wave::object_base
{
private:
    SpringCat::Wave::internal::bitset<1> __has_bits__;

private:
    SpringCat::int16_t result_;

public:
    logout_ans(void);
    logout_ans(const logout_ans& from);
    virtual ~logout_ans(void);

    inline logout_ans& operator=(const logout_ans& rhs)
    {
        copy_from(rhs);
        return *this;
    }

    static const SpringCat::Wave::type_info& static_type_info(void);
    virtual const SpringCat::Wave::type_info& runtime_type_info(void) const;

    virtual logout_ans* new_instance(void) const;
    virtual logout_ans* clone(void) const;

    virtual void clear(void);

    virtual bool initialized(void) const;
    virtual SpringCat::uint32_t size(void) const;

    virtual void copy_from(const SpringCat::Wave::object_base& from);
    virtual void merge_from(const SpringCat::Wave::object_base& from);
    void copy_from(const logout_ans& from);
    void merge_from(const logout_ans& from);

    virtual bool serialize(SpringCat::System::Stream& output) const;
    virtual bool serialize(std::ostream& output) const;
    virtual bool serialize(std::string& output) const;

    virtual bool deserialize(SpringCat::System::Stream& input);
    virtual bool deserialize(std::ostream& input);
    virtual bool deserialize(std::string& input);

    // result
    SpringCat::int16_t get_result(void) const;
    void set_result(SpringCat::int16_t value);
};
// ------------------------------------------------------------------------------------------------

class heartbeat : public SpringCat::Wave::object_base
{
private:
    SpringCat::Wave::internal::bitset<0> __has_bits__;

private:

public:
    heartbeat(void);
    heartbeat(const heartbeat& from);
    virtual ~heartbeat(void);

    inline heartbeat& operator=(const heartbeat& rhs)
    {
        copy_from(rhs);
        return *this;
    }

    static const SpringCat::Wave::type_info& static_type_info(void);
    virtual const SpringCat::Wave::type_info& runtime_type_info(void) const;

    virtual heartbeat* new_instance(void) const;
    virtual heartbeat* clone(void) const;

    virtual void clear(void);

    virtual bool initialized(void) const;
    virtual SpringCat::uint32_t size(void) const;

    virtual void copy_from(const SpringCat::Wave::object_base& from);
    virtual void merge_from(const SpringCat::Wave::object_base& from);
    void copy_from(const heartbeat& from);
    void merge_from(const heartbeat& from);

    virtual bool serialize(SpringCat::System::Stream& output) const;
    virtual bool serialize(std::ostream& output) const;
    virtual bool serialize(std::string& output) const;

    virtual bool deserialize(SpringCat::System::Stream& input);
    virtual bool deserialize(std::ostream& input);
    virtual bool deserialize(std::string& input);
};
// ------------------------------------------------------------------------------------------------

class quit_req : public SpringCat::Wave::object_base
{
private:
    SpringCat::Wave::internal::bitset<0> __has_bits__;

private:

public:
    quit_req(void);
    quit_req(const quit_req& from);
    virtual ~quit_req(void);

    inline quit_req& operator=(const quit_req& rhs)
    {
        copy_from(rhs);
        return *this;
    }

    static const SpringCat::Wave::type_info& static_type_info(void);
    virtual const SpringCat::Wave::type_info& runtime_type_info(void) const;

    virtual quit_req* new_instance(void) const;
    virtual quit_req* clone(void) const;

    virtual void clear(void);

    virtual bool initialized(void) const;
    virtual SpringCat::uint32_t size(void) const;

    virtual void copy_from(const SpringCat::Wave::object_base& from);
    virtual void merge_from(const SpringCat::Wave::object_base& from);
    void copy_from(const quit_req& from);
    void merge_from(const quit_req& from);

    virtual bool serialize(SpringCat::System::Stream& output) const;
    virtual bool serialize(std::ostream& output) const;
    virtual bool serialize(std::string& output) const;

    virtual bool deserialize(SpringCat::System::Stream& input);
    virtual bool deserialize(std::ostream& input);
    virtual bool deserialize(std::string& input);
};
// ------------------------------------------------------------------------------------------------

class quit_ans : public SpringCat::Wave::object_base
{
private:
    SpringCat::Wave::internal::bitset<1> __has_bits__;

private:
    SpringCat::int16_t result_;

public:
    quit_ans(void);
    quit_ans(const quit_ans& from);
    virtual ~quit_ans(void);

    inline quit_ans& operator=(const quit_ans& rhs)
    {
        copy_from(rhs);
        return *this;
    }

    static const SpringCat::Wave::type_info& static_type_info(void);
    virtual const SpringCat::Wave::type_info& runtime_type_info(void) const;

    virtual quit_ans* new_instance(void) const;
    virtual quit_ans* clone(void) const;

    virtual void clear(void);

    virtual bool initialized(void) const;
    virtual SpringCat::uint32_t size(void) const;

    virtual void copy_from(const SpringCat::Wave::object_base& from);
    virtual void merge_from(const SpringCat::Wave::object_base& from);
    void copy_from(const quit_ans& from);
    void merge_from(const quit_ans& from);

    virtual bool serialize(SpringCat::System::Stream& output) const;
    virtual bool serialize(std::ostream& output) const;
    virtual bool serialize(std::string& output) const;

    virtual bool deserialize(SpringCat::System::Stream& input);
    virtual bool deserialize(std::ostream& input);
    virtual bool deserialize(std::string& input);

    // result
    SpringCat::int16_t get_result(void) const;
    void set_result(SpringCat::int16_t value);
};
// ------------------------------------------------------------------------------------------------



}    // namespace protocol

#endif    // __SPRINGCAT_WAVE_AUTH_DC_INCLUDE__
