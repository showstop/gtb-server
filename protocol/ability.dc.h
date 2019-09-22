// Generated by the SpringCat.Wave compiler. DO NOT EDIT!

#ifndef __SPRINGCAT_WAVE_ABILITY_DC_H_INCLUDE__
#define __SPRINGCAT_WAVE_ABILITY_DC_H_INCLUDE__

#include <SpringCat/SpringCat.h>

#include "common_def.dc.h"

namespace protocol
{

class ability;
class ability_slot;
class ability_list;
class ability_list_req;
class ability_list_ans;
class ability_slot_open_req;
class ability_slot_open_ans;
class ability_equip_req;
class ability_equip_ans;
class ability_acquire_req;
class ability_acquire_ans;

enum ability_slot_no
{
    ability_slot_no_SLOT_1 = 1,
    ability_slot_no_SLOT_2 = 2,
    ability_slot_no_SLOT_3 = 3,
};    // enum ability_slot_no

// ================================================================================================

class ability : public SpringCat::Wave::object_base
{
private:
    SpringCat::Wave::internal::bitset<2> __has_bits__;

private:
    SpringCat::int32_t ability_id_;
    SpringCat::int16_t level_;

public:
    ability(void);
    ability(const ability& from);
    virtual ~ability(void);

    inline ability& operator=(const ability& rhs)
    {
        copy_from(rhs);
        return *this;
    }

    static const SpringCat::Wave::type_info& static_type_info(void);
    virtual const SpringCat::Wave::type_info& runtime_type_info(void) const;

    virtual ability* new_instance(void) const;
    virtual ability* clone(void) const;

    virtual void clear(void);

    virtual bool initialized(void) const;
    virtual SpringCat::uint32_t size(void) const;

    virtual void copy_from(const SpringCat::Wave::object_base& from);
    virtual void merge_from(const SpringCat::Wave::object_base& from);
    void copy_from(const ability& from);
    void merge_from(const ability& from);

    virtual bool serialize(SpringCat::System::Stream& output) const;
    virtual bool serialize(std::ostream& output) const;
    virtual bool serialize(std::string& output) const;

    virtual bool deserialize(SpringCat::System::Stream& input);
    virtual bool deserialize(std::ostream& input);
    virtual bool deserialize(std::string& input);

    // ability_id
    SpringCat::int32_t get_ability_id(void) const;
    void set_ability_id(SpringCat::int32_t value);

    // level
    SpringCat::int16_t get_level(void) const;
    void set_level(SpringCat::int16_t value);
};
// ------------------------------------------------------------------------------------------------

class ability_slot : public SpringCat::Wave::object_base
{
private:
    SpringCat::Wave::internal::bitset<1> __has_bits__;

private:
    std::map<ability_slot_no, SpringCat::int32_t> slots_;

public:
    ability_slot(void);
    ability_slot(const ability_slot& from);
    virtual ~ability_slot(void);

    inline ability_slot& operator=(const ability_slot& rhs)
    {
        copy_from(rhs);
        return *this;
    }

    static const SpringCat::Wave::type_info& static_type_info(void);
    virtual const SpringCat::Wave::type_info& runtime_type_info(void) const;

    virtual ability_slot* new_instance(void) const;
    virtual ability_slot* clone(void) const;

    virtual void clear(void);

    virtual bool initialized(void) const;
    virtual SpringCat::uint32_t size(void) const;

    virtual void copy_from(const SpringCat::Wave::object_base& from);
    virtual void merge_from(const SpringCat::Wave::object_base& from);
    void copy_from(const ability_slot& from);
    void merge_from(const ability_slot& from);

    virtual bool serialize(SpringCat::System::Stream& output) const;
    virtual bool serialize(std::ostream& output) const;
    virtual bool serialize(std::string& output) const;

    virtual bool deserialize(SpringCat::System::Stream& input);
    virtual bool deserialize(std::ostream& input);
    virtual bool deserialize(std::string& input);

    // slots
    const std::map<ability_slot_no, SpringCat::int32_t>& get_slots(void) const;
    std::map<ability_slot_no, SpringCat::int32_t>* get_mutable_slots(void);
    bool get_slots(ability_slot_no key, SpringCat::int32_t* value) const;
    void set_slots(ability_slot_no key, SpringCat::int32_t value);
    bool insert_slots(ability_slot_no key, SpringCat::int32_t value);
};
// ------------------------------------------------------------------------------------------------

class ability_list : public SpringCat::Wave::object_base
{
private:
    SpringCat::Wave::internal::bitset<1> __has_bits__;

private:
    std::vector<ability*> infos_;

public:
    ability_list(void);
    ability_list(const ability_list& from);
    virtual ~ability_list(void);

    inline ability_list& operator=(const ability_list& rhs)
    {
        copy_from(rhs);
        return *this;
    }

    static const SpringCat::Wave::type_info& static_type_info(void);
    virtual const SpringCat::Wave::type_info& runtime_type_info(void) const;

    virtual ability_list* new_instance(void) const;
    virtual ability_list* clone(void) const;

    virtual void clear(void);

    virtual bool initialized(void) const;
    virtual SpringCat::uint32_t size(void) const;

    virtual void copy_from(const SpringCat::Wave::object_base& from);
    virtual void merge_from(const SpringCat::Wave::object_base& from);
    void copy_from(const ability_list& from);
    void merge_from(const ability_list& from);

    virtual bool serialize(SpringCat::System::Stream& output) const;
    virtual bool serialize(std::ostream& output) const;
    virtual bool serialize(std::string& output) const;

    virtual bool deserialize(SpringCat::System::Stream& input);
    virtual bool deserialize(std::ostream& input);
    virtual bool deserialize(std::string& input);

    // infos
    const std::vector<ability*>& get_infos(void) const;
    std::vector<ability*>* get_mutable_infos(void);
    const ability* get_infos(size_t index) const;
    ability* get_mutable_infos(size_t index);
    ability* add_infos(void);
};
// ------------------------------------------------------------------------------------------------

class ability_list_req : public SpringCat::Wave::object_base
{
private:
    SpringCat::Wave::internal::bitset<0> __has_bits__;

private:

public:
    ability_list_req(void);
    ability_list_req(const ability_list_req& from);
    virtual ~ability_list_req(void);

    inline ability_list_req& operator=(const ability_list_req& rhs)
    {
        copy_from(rhs);
        return *this;
    }

    static const SpringCat::Wave::type_info& static_type_info(void);
    virtual const SpringCat::Wave::type_info& runtime_type_info(void) const;

    virtual ability_list_req* new_instance(void) const;
    virtual ability_list_req* clone(void) const;

    virtual void clear(void);

    virtual bool initialized(void) const;
    virtual SpringCat::uint32_t size(void) const;

    virtual void copy_from(const SpringCat::Wave::object_base& from);
    virtual void merge_from(const SpringCat::Wave::object_base& from);
    void copy_from(const ability_list_req& from);
    void merge_from(const ability_list_req& from);

    virtual bool serialize(SpringCat::System::Stream& output) const;
    virtual bool serialize(std::ostream& output) const;
    virtual bool serialize(std::string& output) const;

    virtual bool deserialize(SpringCat::System::Stream& input);
    virtual bool deserialize(std::ostream& input);
    virtual bool deserialize(std::string& input);
};
// ------------------------------------------------------------------------------------------------

class ability_list_ans : public SpringCat::Wave::object_base
{
private:
    SpringCat::Wave::internal::bitset<3> __has_bits__;

private:
    SpringCat::int16_t result_;
    std::auto_ptr<ability_list> infos_;
    std::auto_ptr<ability_slot> slot_;

public:
    ability_list_ans(void);
    ability_list_ans(const ability_list_ans& from);
    virtual ~ability_list_ans(void);

    inline ability_list_ans& operator=(const ability_list_ans& rhs)
    {
        copy_from(rhs);
        return *this;
    }

    static const SpringCat::Wave::type_info& static_type_info(void);
    virtual const SpringCat::Wave::type_info& runtime_type_info(void) const;

    virtual ability_list_ans* new_instance(void) const;
    virtual ability_list_ans* clone(void) const;

    virtual void clear(void);

    virtual bool initialized(void) const;
    virtual SpringCat::uint32_t size(void) const;

    virtual void copy_from(const SpringCat::Wave::object_base& from);
    virtual void merge_from(const SpringCat::Wave::object_base& from);
    void copy_from(const ability_list_ans& from);
    void merge_from(const ability_list_ans& from);

    virtual bool serialize(SpringCat::System::Stream& output) const;
    virtual bool serialize(std::ostream& output) const;
    virtual bool serialize(std::string& output) const;

    virtual bool deserialize(SpringCat::System::Stream& input);
    virtual bool deserialize(std::ostream& input);
    virtual bool deserialize(std::string& input);

    // result
    SpringCat::int16_t get_result(void) const;
    void set_result(SpringCat::int16_t value);

    // infos
    const ability_list* get_infos(void) const;
    ability_list* get_mutable_infos(void);

    // slot
    const ability_slot* get_slot(void) const;
    ability_slot* get_mutable_slot(void);
};
// ------------------------------------------------------------------------------------------------

class ability_slot_open_req : public SpringCat::Wave::object_base
{
private:
    SpringCat::Wave::internal::bitset<1> __has_bits__;

private:
    SpringCat::int32_t slot_no_;

public:
    ability_slot_open_req(void);
    ability_slot_open_req(const ability_slot_open_req& from);
    virtual ~ability_slot_open_req(void);

    inline ability_slot_open_req& operator=(const ability_slot_open_req& rhs)
    {
        copy_from(rhs);
        return *this;
    }

    static const SpringCat::Wave::type_info& static_type_info(void);
    virtual const SpringCat::Wave::type_info& runtime_type_info(void) const;

    virtual ability_slot_open_req* new_instance(void) const;
    virtual ability_slot_open_req* clone(void) const;

    virtual void clear(void);

    virtual bool initialized(void) const;
    virtual SpringCat::uint32_t size(void) const;

    virtual void copy_from(const SpringCat::Wave::object_base& from);
    virtual void merge_from(const SpringCat::Wave::object_base& from);
    void copy_from(const ability_slot_open_req& from);
    void merge_from(const ability_slot_open_req& from);

    virtual bool serialize(SpringCat::System::Stream& output) const;
    virtual bool serialize(std::ostream& output) const;
    virtual bool serialize(std::string& output) const;

    virtual bool deserialize(SpringCat::System::Stream& input);
    virtual bool deserialize(std::ostream& input);
    virtual bool deserialize(std::string& input);

    // slot_no
    ability_slot_no get_slot_no(void) const;
    void set_slot_no(ability_slot_no value);
};
// ------------------------------------------------------------------------------------------------

class ability_slot_open_ans : public SpringCat::Wave::object_base
{
private:
    SpringCat::Wave::internal::bitset<2> __has_bits__;

private:
    SpringCat::int16_t result_;
    std::auto_ptr<ability_slot> updated_slot_;

public:
    ability_slot_open_ans(void);
    ability_slot_open_ans(const ability_slot_open_ans& from);
    virtual ~ability_slot_open_ans(void);

    inline ability_slot_open_ans& operator=(const ability_slot_open_ans& rhs)
    {
        copy_from(rhs);
        return *this;
    }

    static const SpringCat::Wave::type_info& static_type_info(void);
    virtual const SpringCat::Wave::type_info& runtime_type_info(void) const;

    virtual ability_slot_open_ans* new_instance(void) const;
    virtual ability_slot_open_ans* clone(void) const;

    virtual void clear(void);

    virtual bool initialized(void) const;
    virtual SpringCat::uint32_t size(void) const;

    virtual void copy_from(const SpringCat::Wave::object_base& from);
    virtual void merge_from(const SpringCat::Wave::object_base& from);
    void copy_from(const ability_slot_open_ans& from);
    void merge_from(const ability_slot_open_ans& from);

    virtual bool serialize(SpringCat::System::Stream& output) const;
    virtual bool serialize(std::ostream& output) const;
    virtual bool serialize(std::string& output) const;

    virtual bool deserialize(SpringCat::System::Stream& input);
    virtual bool deserialize(std::ostream& input);
    virtual bool deserialize(std::string& input);

    // result
    SpringCat::int16_t get_result(void) const;
    void set_result(SpringCat::int16_t value);

    // updated_slot
    const ability_slot* get_updated_slot(void) const;
    ability_slot* get_mutable_updated_slot(void);
};
// ------------------------------------------------------------------------------------------------

class ability_equip_req : public SpringCat::Wave::object_base
{
private:
    SpringCat::Wave::internal::bitset<2> __has_bits__;

private:
    SpringCat::int32_t ability_id_;
    SpringCat::int32_t slot_no_;

public:
    ability_equip_req(void);
    ability_equip_req(const ability_equip_req& from);
    virtual ~ability_equip_req(void);

    inline ability_equip_req& operator=(const ability_equip_req& rhs)
    {
        copy_from(rhs);
        return *this;
    }

    static const SpringCat::Wave::type_info& static_type_info(void);
    virtual const SpringCat::Wave::type_info& runtime_type_info(void) const;

    virtual ability_equip_req* new_instance(void) const;
    virtual ability_equip_req* clone(void) const;

    virtual void clear(void);

    virtual bool initialized(void) const;
    virtual SpringCat::uint32_t size(void) const;

    virtual void copy_from(const SpringCat::Wave::object_base& from);
    virtual void merge_from(const SpringCat::Wave::object_base& from);
    void copy_from(const ability_equip_req& from);
    void merge_from(const ability_equip_req& from);

    virtual bool serialize(SpringCat::System::Stream& output) const;
    virtual bool serialize(std::ostream& output) const;
    virtual bool serialize(std::string& output) const;

    virtual bool deserialize(SpringCat::System::Stream& input);
    virtual bool deserialize(std::ostream& input);
    virtual bool deserialize(std::string& input);

    // ability_id
    SpringCat::int32_t get_ability_id(void) const;
    void set_ability_id(SpringCat::int32_t value);

    // slot_no
    ability_slot_no get_slot_no(void) const;
    void set_slot_no(ability_slot_no value);
};
// ------------------------------------------------------------------------------------------------

class ability_equip_ans : public SpringCat::Wave::object_base
{
private:
    SpringCat::Wave::internal::bitset<2> __has_bits__;

private:
    SpringCat::int16_t result_;
    std::auto_ptr<ability_slot> updated_slot_;

public:
    ability_equip_ans(void);
    ability_equip_ans(const ability_equip_ans& from);
    virtual ~ability_equip_ans(void);

    inline ability_equip_ans& operator=(const ability_equip_ans& rhs)
    {
        copy_from(rhs);
        return *this;
    }

    static const SpringCat::Wave::type_info& static_type_info(void);
    virtual const SpringCat::Wave::type_info& runtime_type_info(void) const;

    virtual ability_equip_ans* new_instance(void) const;
    virtual ability_equip_ans* clone(void) const;

    virtual void clear(void);

    virtual bool initialized(void) const;
    virtual SpringCat::uint32_t size(void) const;

    virtual void copy_from(const SpringCat::Wave::object_base& from);
    virtual void merge_from(const SpringCat::Wave::object_base& from);
    void copy_from(const ability_equip_ans& from);
    void merge_from(const ability_equip_ans& from);

    virtual bool serialize(SpringCat::System::Stream& output) const;
    virtual bool serialize(std::ostream& output) const;
    virtual bool serialize(std::string& output) const;

    virtual bool deserialize(SpringCat::System::Stream& input);
    virtual bool deserialize(std::ostream& input);
    virtual bool deserialize(std::string& input);

    // result
    SpringCat::int16_t get_result(void) const;
    void set_result(SpringCat::int16_t value);

    // updated_slot
    const ability_slot* get_updated_slot(void) const;
    ability_slot* get_mutable_updated_slot(void);
};
// ------------------------------------------------------------------------------------------------

class ability_acquire_req : public SpringCat::Wave::object_base
{
private:
    SpringCat::Wave::internal::bitset<1> __has_bits__;

private:
    SpringCat::int32_t ability_id_;

public:
    ability_acquire_req(void);
    ability_acquire_req(const ability_acquire_req& from);
    virtual ~ability_acquire_req(void);

    inline ability_acquire_req& operator=(const ability_acquire_req& rhs)
    {
        copy_from(rhs);
        return *this;
    }

    static const SpringCat::Wave::type_info& static_type_info(void);
    virtual const SpringCat::Wave::type_info& runtime_type_info(void) const;

    virtual ability_acquire_req* new_instance(void) const;
    virtual ability_acquire_req* clone(void) const;

    virtual void clear(void);

    virtual bool initialized(void) const;
    virtual SpringCat::uint32_t size(void) const;

    virtual void copy_from(const SpringCat::Wave::object_base& from);
    virtual void merge_from(const SpringCat::Wave::object_base& from);
    void copy_from(const ability_acquire_req& from);
    void merge_from(const ability_acquire_req& from);

    virtual bool serialize(SpringCat::System::Stream& output) const;
    virtual bool serialize(std::ostream& output) const;
    virtual bool serialize(std::string& output) const;

    virtual bool deserialize(SpringCat::System::Stream& input);
    virtual bool deserialize(std::ostream& input);
    virtual bool deserialize(std::string& input);

    // ability_id
    SpringCat::int32_t get_ability_id(void) const;
    void set_ability_id(SpringCat::int32_t value);
};
// ------------------------------------------------------------------------------------------------

class ability_acquire_ans : public SpringCat::Wave::object_base
{
private:
    SpringCat::Wave::internal::bitset<2> __has_bits__;

private:
    SpringCat::int16_t result_;
    std::auto_ptr<ability> updated_ability_;

public:
    ability_acquire_ans(void);
    ability_acquire_ans(const ability_acquire_ans& from);
    virtual ~ability_acquire_ans(void);

    inline ability_acquire_ans& operator=(const ability_acquire_ans& rhs)
    {
        copy_from(rhs);
        return *this;
    }

    static const SpringCat::Wave::type_info& static_type_info(void);
    virtual const SpringCat::Wave::type_info& runtime_type_info(void) const;

    virtual ability_acquire_ans* new_instance(void) const;
    virtual ability_acquire_ans* clone(void) const;

    virtual void clear(void);

    virtual bool initialized(void) const;
    virtual SpringCat::uint32_t size(void) const;

    virtual void copy_from(const SpringCat::Wave::object_base& from);
    virtual void merge_from(const SpringCat::Wave::object_base& from);
    void copy_from(const ability_acquire_ans& from);
    void merge_from(const ability_acquire_ans& from);

    virtual bool serialize(SpringCat::System::Stream& output) const;
    virtual bool serialize(std::ostream& output) const;
    virtual bool serialize(std::string& output) const;

    virtual bool deserialize(SpringCat::System::Stream& input);
    virtual bool deserialize(std::ostream& input);
    virtual bool deserialize(std::string& input);

    // result
    SpringCat::int16_t get_result(void) const;
    void set_result(SpringCat::int16_t value);

    // updated_ability
    const ability* get_updated_ability(void) const;
    ability* get_mutable_updated_ability(void);
};
// ------------------------------------------------------------------------------------------------



}    // namespace protocol

#endif    // __SPRINGCAT_WAVE_ABILITY_DC_INCLUDE__
