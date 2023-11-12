#pragma once

#include "../../gso_utils.h"

#include "../../gso_object.h"
#include "../../gso_defs/gso_def.h"
#include "../../gso_defs/defs/gso_header.h"
#include "../../gso_types/gso_vector_type.h"
#include "../../gso_types/gso_string_type.h"
#include "../../gso_types/gso_tuple_type.h"
#include "../../gso_types/gso_token.h"

#include "../../gso_file_reader.h"

// version loaders
#include "../../gso_version_loaders/gso_current_loader.h"

#include "../../gso_loader_data.h"

namespace gso_token_loaders {
    gso_token gso_load_def_token(gso_token def_token) {
        gso_vector_type<gso_string_type> components = gso_utils::gso_get_components(def_token.token_text);

        // load type
        gso_token define_type_token = gso_token();
        define_type_token.token_type = gso_token_type::gso_def_type_token;
        define_type_token.token_text = components[0].substring(4, components[0].size() - 1);;

        gso_token define_variables_token = gso_token();
        define_variables_token.set_token_type(gso_token_type::gso_def_variables_token);

        def_token.add_subtoken(define_type_token);

        // load vars

        gso_string_type gso_def_variables_text = "";

        for (int i = 2; i < components.size() - 1; i += 2) {
            gso_string_type variable_token_text = components[i] + " " + components[i + 1];

            gso_token variable_token = gso_token();
            variable_token.token_type = gso_token_type::gso_def_variable_token;
            variable_token.token_text = variable_token_text;

            gso_token variable_name_token = gso_token();
            variable_name_token.token_type = gso_token_type::gso_def_variable_name_token;
            variable_name_token.token_text = components[i].substring(0, components[i].size() - 1);
            variable_token.add_subtoken(variable_name_token);

            gso_token variable_value_token = gso_token();
            variable_value_token.token_type = gso_token_type::gso_def_variable_value_token;
            variable_value_token.token_text = components[i + 1];
            variable_token.add_subtoken(variable_value_token);

            define_variables_token.add_subtoken(variable_token);
        }

        def_token.add_subtoken(define_variables_token);
        define_variables_token.set_token_text(gso_def_variables_text);

        return def_token;
    }
    gso_token gso_load_var_token(gso_token var_token) {
        gso_vector_type<gso_string_type> components = gso_utils::gso_get_components(var_token.token_text);
        
        gso_token variable_type_token = gso_token();
        variable_type_token.token_type = gso_token_type::gso_var_type_token;
        variable_type_token.token_text = components[0].substring(4, components[0].size() - 1);
        var_token.sub_tokens.add(variable_type_token);
        
        gso_token variable_name_token = gso_token();
        variable_name_token.token_type = gso_token_type::gso_var_name_token;
        variable_type_token.token_text = components[2];

        gso_string_type variable_data_token_text = gso_string_type();

        for (int i = 4; i < components.size(); i++) {
            variable_data_token_text += components[i] + ' ';
        }

        gso_token variable_data_token = gso_token();
        variable_data_token.token_type = gso_token_type::gso_var_data_token;
        variable_data_token.token_text = variable_data_token_text;

        std::cout << variable_data_token_text << "\n";

        return var_token;
    }
}
