#pragma once

#include "gso_list_type.h"

class gso_list_string : public gso_list_type {
private:
    gso_string_type value;
public:
    operator gso_string_type() { return value; } 

    void set_data(char* val) { value = val; }
    void set_data(const char* val) { value = val; }
    void set_data(gso_string_type val) { value = val; }
public:
    // these dont have a write function yet
    virtual void Read(gso_token token) override { 
        value = token.token_text.substring(1, token.token_text.size() - 1);
    };

    virtual gso_string_type Write() override {
        gso_string_type output = "\"";
        output += value;
        output += "\"";
        return output;
    }
};