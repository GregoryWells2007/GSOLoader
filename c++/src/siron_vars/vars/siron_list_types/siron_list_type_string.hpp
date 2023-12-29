#pragma once

#include "siron_list_type.hpp"

class siron_list_string : public siron_list_type {
private:
    siron_string_type value;
public:
    operator siron_string_type() { return value; } 

    void set_data(char* val) { value = val; }
    void set_data(const char* val) { value = val; }
    void set_data(siron_string_type val) { value = val; }
public:
    // these dont have a write function yet
    virtual void Read(siron_token token) override { 
        value = token.token_text.substring(1, token.token_text.size() - 1);
    };

    virtual siron_string_type Write() override {
        siron_string_type output = "\"";
        output += value;
        output += "\"";
        return output;
    }
public:
    virtual siron_string_type to_string() override {
        return value;
    }
};