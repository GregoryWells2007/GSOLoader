#pragma once

#include "../gso_var.h"

class gso_number : public gso_var {
private:
    // need to write a custom type that allows any sized numbers
    double value;
public:
    operator double() { return value; }
    operator float() { return value; }
    operator int() { return value; }

    void set_data(double val) { value = val; };
    void set_data(float val) { value = val; };
    void set_data(int val) { value = val; };
public:
    virtual void ReadData(gso_token token) override {
        value = gso_utils::gso_convert_string_to_double(token.get_subtoken(2).get_subtoken(0).token_text);
    };
    virtual gso_var_data WriteData() override { 
        gso_var_data data = gso_var_data();
        data.variable_type = "number";
        data.items.add(gso_utils::gso_convert_double_to_string(value));
        return data; 
    }
};