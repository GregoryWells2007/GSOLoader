#pragma once

#include "../../gso_utils.h"

#include "../gso_def.h"
#include "../../gso_types/gso_vector_type.h"
#include "../../gso_types/gso_token.h"

//  gso_def_token
//      gso_def_type_token
//      gso_def_variables_token
//          gso_def_variable_token
//              gso_def_variable_name_token
//              gso_def_variable_value_token

struct gso_header : public gso_def {
public:
    float version = 0.0f;
public:
    virtual void Read(gso_token token) override {
        version = gso_utils::gso_convert_string_to_float(token.get_subtoken(1).get_subtoken(0).get_subtoken(1).token_text);
    }

    // this funciton will need to be redone
    virtual gso_token Write() override {
        gso_token output_token = gso_token();
        output_token.set_token_type(gso_token_type::gso_def_token);

        gso_token gso_def_type_token = gso_token();
        gso_def_type_token.set_token_type(gso_token_type::gso_def_type_token);
        gso_def_type_token.set_token_text("header");

        gso_token gso_def_variables_token = gso_token();
        gso_def_variables_token.set_token_type(gso_token_type::gso_def_variables_token);

        // build variables
        gso_token gso_def_version_token = gso_token();
        gso_def_version_token.set_token_type(gso_token_type::gso_def_variable_token);

        gso_token gso_def_version_name = gso_token();
        gso_def_version_name.set_token_type(gso_token_type::gso_def_variable_name_token);
        gso_def_version_name.set_token_text("version");
        
        gso_token gso_def_version_value = gso_token();
        gso_def_version_value.set_token_type(gso_token_type::gso_def_variable_value_token);
        gso_def_version_value.set_token_text(gso_utils::gso_convert_float_to_string(version));

        gso_def_version_token.add_subtoken(gso_def_version_name);
        gso_def_version_token.add_subtoken(gso_def_version_value);

        gso_def_variables_token.add_subtoken(gso_def_version_token);

        // add subtokens to parent
        output_token.add_subtoken(gso_def_type_token);
        output_token.add_subtoken(gso_def_variables_token);

        return output_token;
    }
};