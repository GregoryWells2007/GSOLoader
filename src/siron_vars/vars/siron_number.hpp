#pragma once

#include "../siron_var.hpp"

class siron_number : public siron_var {
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
    virtual void ReadData(siron_token token) override {
        value = siron_utils::siron_convert_string_to_double(token.get_subtoken(2).get_subtoken(0).token_text);
    };
    virtual siron_var_data WriteData() override { 
        siron_var_data data = siron_var_data();
        data.variable_type = "number";
        data.items.add(siron_utils::siron_convert_double_to_string(value));
        return data; 
    }
public:
    virtual siron_string_type to_string() override {
        return siron_utils::siron_convert_double_to_string(value);
    };
};