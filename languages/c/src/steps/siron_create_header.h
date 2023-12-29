#pragma once
#include "../siron_defs.h"

typedef struct header_def_variable {
    char* name;
    char* value;
    siron_token* token;
} header_def_variable;


siron_token siron_create_header_token(char* string) {
    siron_token header_token = siron_create_token(siron_def_token, string);
    siron_token def_type_token = siron_create_token(siron_def_type_token, "header");

    int start_index = siron_find_in_string(string, '{');
    int end_index = siron_find_in_string(string, '}');

    char* variables = siron_substring(string, start_index + 2, end_index - 1 );

    siron_linked_list* components = siron_splitstring(variables, ' ');
    siron_token def_vars_token = siron_create_token(siron_def_variables_token, variables);


    siron_linked_list* variable_items = siron_linked_list_create(NULL);

    char* first_var_name = siron_linked_list_get(components, 0);
    header_def_variable new_var = { siron_substring(first_var_name, 0, strlen(first_var_name) - 1), siron_linked_list_get(components, 1) };
    siron_linked_list_set(variable_items, 0, (void*)(&new_var));


    for (int i = 2; i < siron_linked_list_size(components); i += 2) {
        char* var_name = siron_linked_list_get(components, i);

        header_def_variable new_creation = { 
            siron_substring(var_name, 0, strlen(var_name) - 1), 
            siron_linked_list_get(components, i + 1) 
        };
        siron_linked_list_add(variable_items, (void*)(&new_creation));
        free(var_name);
    }

    loop_list(item_index, variable_items) {
        header_def_variable* otherVariable = (header_def_variable*)siron_linked_list_get(variable_items, item_index);
        char* new_value = siron_addstring(siron_addstring(otherVariable->name, ": "), otherVariable->value);
        otherVariable->token = siron_create_tokenptr(siron_def_variable_token, new_value);

        siron_token* var_name_token = siron_create_tokenptr(siron_def_variable_name_token, otherVariable->name);
        siron_token* var_value_token = siron_create_tokenptr(siron_def_variable_value_token, otherVariable->value);

        siron_add_subtokenptr(otherVariable->token, var_name_token);
        siron_add_subtokenptr(otherVariable->token, var_value_token);

        siron_add_subtokenptr(&def_vars_token, otherVariable->token);
    }



    siron_add_subtoken(&header_token, def_type_token);
    siron_add_subtoken(&header_token, def_vars_token);
    free(variable_items);
    free(components);
    return header_token;
}
