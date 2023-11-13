#pragma once

#include "../gso_var.h"

class gso_char : public gso_var {
private:
    char value;
public:
    operator char() { return value; }
    void set_data(char val) { value = val; };
public:
    virtual void ReadData(gso_token token) override { 
        value = token.get_subtoken(2).get_subtoken(0).token_text[1];
    }
    virtual gso_var_data WriteData() override { return gso_var_data(); }
};