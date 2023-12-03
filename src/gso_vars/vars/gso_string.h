#pragma once

#include "../gso_var.h"

class gso_string : public gso_var {
private:
    gso_string_type value;
public:
    operator gso_string_type() { return value; }
    
    void set_data(char* val) { value = val; };
    void set_data(const char* val) { value = val; };
    void set_data(gso_string_type val) { value = val; };
public:
    virtual void ReadData(gso_token token) override { 
        value = token.get_subtoken(2).get_subtoken(0).token_text.substring(1, token.get_subtoken(2).get_subtoken(0).token_text.size() - 2);
    };
    virtual gso_var_data WriteData() override { 
        gso_var_data data = gso_var_data();
        data.variable_type = "string";
        gso_string_type output = "\"";
        output += value;
        output += "\"";
        data.items.add(output);
        return data; 
    }
public:
    virtual gso_string_type to_string() override {
        return value;
    }; 
};