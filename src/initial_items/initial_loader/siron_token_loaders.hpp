#pragma once

#include "../../siron_utils.hpp"

#include "../../siron_object.hpp"
#include "../../siron_defs/siron_def.hpp"
#include "../../siron_defs/defs/siron_header.hpp"
#include "../../siron_types/siron_vector_type.hpp"
#include "../../siron_types/siron_string_type.hpp"
#include "../../siron_types/siron_tuple_type.hpp"
#include "../../siron_types/siron_token.hpp"

#include "../../siron_file_reader.hpp"

// version loaders
#include "../../siron_version_loaders/siron_current_loader.hpp"

#include "../../siron_loader_data.hpp"

namespace siron_token_loaders {
    siron_token siron_load_def_token(siron_token def_token) {
        siron_vector_type<siron_string_type> components = siron_utils::siron_get_components(def_token.token_text);

        // load type
        siron_token define_type_token = siron_token();
        define_type_token.token_type = siron_token_type::siron_def_type_token;
        define_type_token.token_text = components[0].substring(4, components[0].size() - 1);;

        siron_token define_variables_token = siron_token();
        define_variables_token.set_token_type(siron_token_type::siron_def_variables_token);

        def_token.add_subtoken(define_type_token);

        // load vars

        siron_string_type siron_def_variables_text = "";

        for (int i = 2; i < components.size() - 1; i += 2) {
            siron_string_type variable_token_text = components[i] + " " + components[i + 1];

            siron_token variable_token = siron_token();
            variable_token.token_type = siron_token_type::siron_def_variable_token;
            variable_token.token_text = variable_token_text;

            siron_token variable_name_token = siron_token();
            variable_name_token.token_type = siron_token_type::siron_def_variable_name_token;
            variable_name_token.token_text = components[i].substring(0, components[i].size() - 1);
            variable_token.add_subtoken(variable_name_token);

            siron_token variable_value_token = siron_token();
            variable_value_token.token_type = siron_token_type::siron_def_variable_value_token;
            variable_value_token.token_text = components[i + 1];
            variable_token.add_subtoken(variable_value_token);

            define_variables_token.add_subtoken(variable_token);
        }

        def_token.add_subtoken(define_variables_token);
        define_variables_token.set_token_text(siron_def_variables_text);

        return def_token;
    }
    siron_token siron_load_var_token(siron_token var_token) {
        siron_vector_type<siron_string_type> components = siron_utils::siron_get_components(var_token.token_text);
        
        siron_token variable_type_token = siron_token();
        variable_type_token.token_type = siron_token_type::siron_var_type_token;
        variable_type_token.token_text = components[0].substring(4, components[0].size() - 1);
        var_token.sub_tokens.add(variable_type_token);
        
        siron_token variable_name_token = siron_token();
        variable_name_token.token_type = siron_token_type::siron_var_name_token;
        variable_type_token.token_text = components[2];

        siron_string_type variable_data_token_text = siron_string_type();

        for (int i = 4; i < components.size(); i++) {
            variable_data_token_text += components[i] + ' ';
        }

        siron_token variable_data_token = siron_token();
        variable_data_token.token_type = siron_token_type::siron_var_data_token;
        variable_data_token.token_text = variable_data_token_text;

        std::cout << variable_data_token_text << "\n";

        return var_token;
    }
}
