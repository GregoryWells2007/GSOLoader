#pragma once

#include "../../../siron_types/siron_token.hpp"

class siron_list_type {
public:
    // these dont have a write function yet
    virtual void Read(siron_token value) = 0;
    virtual siron_string_type Write() = 0;
public:
    virtual siron_string_type to_string() = 0;
};