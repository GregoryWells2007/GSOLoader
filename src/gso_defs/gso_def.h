#pragma once

#include "../gso_types/gso_vector_type.h"
#include "../gso_types/gso_token.h"

class gso_def {
public:
    bool is_container = false;

public:
    virtual void Read(gso_token token) = 0;
    virtual gso_token Write() = 0;
};