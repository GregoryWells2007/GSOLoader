#pragma once

#include "../gso_types/gso_token.h"
#include "../gso_types/gso_string_type.h"

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
    gso_var () {

    }

    void Read(gso_token token) {
        name = token.get_subtoken(1).token_text;
        ReadData(token);
    }
    gso_var_data Write() {
        return WriteData();
    }

    void set_name(gso_string_type new_name) { name = new_name; }
public:
    virtual void ReadData(gso_token token) = 0;
    virtual gso_var_data WriteData() = 0;
};