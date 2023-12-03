#pragma once

#include "../siron_types/siron_vector_type.hpp"
#include "../siron_types/siron_token.hpp"

class siron_def {
public:
    virtual void Read(siron_token token) = 0;
    virtual siron_token Write() = 0;
};