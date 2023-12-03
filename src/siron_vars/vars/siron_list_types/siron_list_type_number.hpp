#pragma once

#include "siron_list_type.hpp"

class siron_list_number : public siron_list_type {
private:
    // i want to write a custom number class for siron files that allows the numbers to be infinite in size but im lazy af so
    // that is not going to happen for a while
    double value;
public:
    operator double() { return value; }
    operator float() { return value; }
    operator int() { return value; }

    void set_data(double val) { value = val; }
public:
    virtual void Read(siron_token token) override { 
        value = siron_utils::siron_convert_string_to_double(token.token_text);
    };

    virtual siron_string_type Write() override { return siron_utils::siron_convert_double_to_string(value); }
public:
    virtual siron_string_type to_string() override {
        return siron_utils::siron_convert_double_to_string(value);
    }
};