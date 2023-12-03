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
    virtual siron_token Write() override {
        siron_token output_token = siron_token();
        output_token.set_token_type(siron_token_type::siron_def_token);

        siron_token siron_def_type_token = siron_token();
        siron_def_type_token.set_token_type(siron_token_type::siron_def_type_token);
        siron_def_type_token.set_token_text("header");

        siron_token siron_def_variables_token = siron_token();
        siron_def_variables_token.set_token_type(siron_token_type::siron_def_variables_token);

        // build variables
        siron_token siron_def_version_token = siron_token();
        siron_def_version_token.set_token_type(siron_token_type::siron_def_variable_token);

        siron_token siron_def_version_name = siron_token();
        siron_def_version_name.set_token_type(siron_token_type::siron_def_variable_name_token);
        siron_def_version_name.set_token_text("version");
        
        siron_token siron_def_version_value = siron_token();
        siron_def_version_value.set_token_type(siron_token_type::siron_def_variable_value_token);
        siron_def_version_value.set_token_text(siron_utils::siron_convert_float_to_string(version));

        siron_def_version_token.add_subtoken(siron_def_version_name);
        siron_def_version_token.add_subtoken(siron_def_version_value);

        siron_def_variables_token.add_subtoken(siron_def_version_token);

        // add subtokens to parent
        output_token.add_subtoken(siron_def_type_token);
        output_token.add_subtoken(siron_def_variables_token);

        return output_token;
    }
};