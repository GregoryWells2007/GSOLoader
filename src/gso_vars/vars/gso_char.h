#pragma once

#include "../gso_var.h"

class gso_char : public gso_var {
private:
    char value;
public:
    operator char() { return value; }
public:
    virtual void ReadData(gso_token token) override { 
        value = token.get_subtoken(2).get_subtoken(0).token_text[1];
    }
    virtual gso_token WriteData() override { return gso_token(); }
};