#pragma once

#include "../gso_types/gso_token.h"
#include "../gso_types/gso_string_type.h"
#include "../gso_utils.h"

struct gso_var_data {
public:
    gso_string_type variable_type = "NoType";
    bool is_indented = false;
    gso_vector_type<gso_string_type> items = {};
};

class gso_var {
public:
    gso_string_type name = "NewVariable";
public:
    void Read(gso_token token) {
        name = token.get_subtoken(1).token_text;
        ReadData(token);
    }
public:
    gso_var () {}
    gso_var_data write() { return WriteData(); }
    void set_name(gso_string_type new_name) { name = new_name; }
    operator gso_string_type() { return "i like big balls and i cannot lie"; }
public:
    virtual void ReadData(gso_token token) = 0;
    virtual gso_var_data WriteData() = 0;

    virtual gso_string_type to_string() = 0;
};