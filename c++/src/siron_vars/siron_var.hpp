#pragma once

#include "../siron_types/siron_token.hpp"
#include "../siron_types/siron_string_type.hpp"
#include "../siron_utils.hpp"

struct siron_var_data {
public:
    siron_string_type variable_type = "NoType";
    bool is_indented = false;
    siron_vector_type<siron_string_type> items = {};
};

class siron_var {
public:
    siron_string_type name = "NewVariable";
public:
    void Read(siron_token token) {
        name = token.get_subtoken(1).token_text;
        ReadData(token);
    }
public:
    siron_var () {}
    siron_var_data write() { return WriteData(); }
    void set_name(siron_string_type new_name) { name = new_name; }
    operator siron_string_type() { return "i like big balls and i cannot lie"; }
public:
    virtual void ReadData(siron_token token) = 0;
    virtual siron_var_data WriteData() = 0;

    virtual siron_string_type to_string() = 0;
};