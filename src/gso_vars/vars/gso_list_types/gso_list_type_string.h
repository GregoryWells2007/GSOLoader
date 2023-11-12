#pragma once

#include "gso_list_type.h"

class gso_list_string : public gso_list_type {
private:
    gso_string_type value;
public:
    operator gso_string_type() { return value; } 
public:
    // these dont have a write function yet
    virtual void Read(gso_token token) override { 
        value = token.token_text.substring(1, token.token_text.size() - 1);
    };
};