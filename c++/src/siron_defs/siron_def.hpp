#pragma once

#include "../siron_types/siron_vector_type.hpp"
#include "../siron_types/siron_tuple_type.hpp"
#include "../siron_types/siron_token.hpp"

struct siron_def_data {
public:
    siron_string_type define_type = "NoType";
    siron_vector_type<siron_tuple_type<siron_string_type, siron_string_type>> variables = {};
};

class siron_def {
public:
    virtual void Read(siron_token token) = 0;
    virtual siron_def_data Write() = 0;
};