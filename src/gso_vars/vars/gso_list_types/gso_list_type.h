#pragma once

#include "../../../gso_types/gso_token.h"

class gso_list_type {
public:
    // these dont have a write function yet
    virtual void Read(gso_token value) = 0;
};