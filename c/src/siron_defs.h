#pragma once
#include "stdio.h"
#include "types/siron_token.h"
#include "siron_utils.h"

typedef struct siron_header {
    float version;
} siron_header;


siron_header siron_create_header(siron_token header_token) {
    siron_header header = { 0.0f };

    printf("Creating Header Type\n");

    siron_token* variables_token = siron_linked_list_get(header_token.tokens, 1);
    loop_list(index, variables_token->tokens) {
        siron_token* current_variable = siron_linked_list_get(variables_token->tokens, index);
        
        siron_token* variable_name = siron_linked_list_get(current_variable->tokens, 0);
        if (siron_string_equal(variable_name->text, "version"))
            header.version = siron_convert_string_to_float(((siron_token*)siron_linked_list_get(current_variable->tokens, 1))->text);
    }

    return header;
}