#pragma once

#include "gso_list_type.h"

class gso_list_char : public gso_list_type {
private:
    char value = ' ';
public:
    operator char() { return value; }
public:
    virtual void Read(gso_token token) override { 
        value = token.token_text[1];
    };
};