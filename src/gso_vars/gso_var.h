#pragma once

#include "../gso_types/gso_token.h"
#include "../gso_types/gso_string_type.h"

class gso_var {
public:
    gso_string_type name = "";
public:
    gso_var () {

    }

    void Read(gso_token token) {
        name = token.get_subtoken(1).token_text;
        ReadData(token);
    }
    gso_token Write() {
        return WriteData();
    }

    virtual void ReadData(gso_token token) = 0;
    virtual gso_token WriteData() = 0;
};