#pragma once

#include "gso_list_type.h"

class gso_list_number : public gso_list_type {
private:
    // i want to write a custom number class for GSO files that allows the numbers to be infinite in size but im lazy af so
    // that is not going to happen for a while
    double value;
public:
    operator double() { return value; }
    operator float() { return value; }
    operator int() { return value; }

    void set_data(double val) { value = val; }
public:
    virtual void Read(gso_token token) override { 
        value = gso_utils::gso_convert_string_to_double(token.token_text);
    };

    virtual gso_string_type Write() override { return gso_utils::gso_convert_double_to_string(value); }
};