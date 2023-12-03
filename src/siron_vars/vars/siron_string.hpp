#pragma once

#include "../siron_var.hpp"

class siron_string : public siron_var {
private:
    siron_string_type value;
public:
    operator siron_string_type() { return value; }
    
    void set_data(char* val) { value = val; };
    void set_data(const char* val) { value = val; };
    void set_data(siron_string_type val) { value = val; };
public:
    virtual void ReadData(siron_token token) override { 
        value = token.get_subtoken(2).get_subtoken(0).token_text.substring(1, token.get_subtoken(2).get_subtoken(0).token_text.size() - 2);
    };
    virtual siron_var_data WriteData() override { 
        siron_var_data data = siron_var_data();
        data.variable_type = "string";
        siron_string_type output = "\"";
        output += value;
        output += "\"";
        data.items.add(output);
        return data; 
    }
public:
    virtual siron_string_type to_string() override {
        return value;
    }; 
};