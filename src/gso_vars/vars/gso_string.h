#pragma once

#include "../gso_var.h"

class gso_string : public gso_var {
private:
    gso_string_type value;
public:
    operator gso_string_type() { return value; }
public:
    virtual void ReadData(gso_token token) override { 
        value = token.get_subtoken(2).get_subtoken(0).token_text.substring(1, token.get_subtoken(2).get_subtoken(0).token_text.size() - 2);
    };
    virtual gso_token WriteData() override { return gso_token(); }
};