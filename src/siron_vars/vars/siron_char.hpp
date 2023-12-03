#pragma once

#include "../siron_var.hpp"

class siron_char : public siron_var {
private:
    char value;
public:
    operator char() { return value; }
    void set_data(char val) { value = val; };
public:
    virtual void ReadData(siron_token token) override { 
        value = token.get_subtoken(2).get_subtoken(0).token_text[1];
    }
    virtual siron_var_data WriteData() override { 
        siron_var_data data = siron_var_data();
        data.variable_type = "char";

        siron_string_type output = "'";
        output += value;
        output += "'";

        data.items.add(output);
        
        return data; 
    }

public:
    virtual siron_string_type to_string() override {
        return value;
    };
};