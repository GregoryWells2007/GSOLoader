#pragma once

#include "siron_list_type.hpp"

class siron_list_char : public siron_list_type {
private:
    char value = ' ';
public:
    operator char() { return value; }
    void set_data(char val) { value = val; }
public:
    virtual void Read(siron_token token) override { 
        value = token.token_text[1];
    };

    virtual siron_string_type Write() override {
        siron_string_type output = "'";
        output += value;
        output += "'";
        return output;
    }
public:
    virtual siron_string_type to_string() override {
        return value;
    }
};