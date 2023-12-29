#pragma once

#include "../../siron_utils.hpp"

#include "../siron_def.hpp"
#include "../../siron_types/siron_vector_type.hpp"
#include "../../siron_types/siron_token.hpp"

//  siron_def_token
//      siron_def_type_token
//      siron_def_variables_token
//          siron_def_variable_token
//              siron_def_variable_name_token
//              siron_def_variable_value_token

struct siron_header : public siron_def {
public:
    float version = 0.0f;
public:
    virtual void Read(siron_token token) override {
        version = siron_utils::siron_convert_string_to_float(token.get_subtoken(1).get_subtoken(0).get_subtoken(1).token_text);
    }

    // this funciton will need to be redone
    virtual siron_def_data Write() override {
        siron_def_data data;
        data.define_type = "header";

        data.variables.add({ "version", siron_utils::siron_convert_float_to_string(version) });

        return data;
    }
};