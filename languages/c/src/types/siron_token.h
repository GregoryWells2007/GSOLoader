#pragma once
#include "stdlib.h"
#include "siron_linked_list.h"
#include "string.h"

#define arr_size(obj_type, count) malloc(count * sizeof(obj_type))

struct siron_token;
enum siron_token_type;

typedef enum siron_token_type {
    siron_null_token,

    siron_master_token,
    
    siron_def_token, 
    siron_def_type_token,
    siron_def_variables_token,
    siron_def_variable_token,
    siron_def_variable_name_token,
    siron_def_variable_value_token,

    siron_var_token,
    siron_var_type_token,
    siron_var_name_token,
    siron_var_data_token,
    
    siron_var_type_container_token,
    siron_var_type_number_token, siron_var_number_value_token,
    
    siron_var_type_int_token, 
    siron_var_type_int2_token, 
    siron_var_type_int3_token, 
    siron_var_type_int4_token, siron_var_int_num1_token, siron_var_int_num2_token, siron_var_int_num3_token, siron_var_int_num4_token,

    siron_var_type_float_token, 
    siron_var_type_float2_token, 
    siron_var_type_float3_token, 
    siron_var_type_float4_token, siron_var_float_num1_token, siron_var_float_num2_token, siron_var_float_num3_token, siron_var_float_num4_token,

    siron_var_type_double_token, 
    siron_var_type_double2_token, 
    siron_var_type_double3_token, 
    siron_var_type_double4_token, siron_var_double_num1_token, siron_var_double_num2_token, siron_var_double_num3_token, siron_var_double_num4_token,

    siron_var_type_color_token, siron_var_color_r_token, siron_var_color_g_token, siron_var_color_b_token, siron_var_color_a_token,
    siron_var_type_char_token, siron_var_char_value_token,

    siron_var_type_string_token, siron_var_string_value_token,
    siron_var_type_file_token, siron_var_file_path_token,
    siron_var_type_list_token, siron_var_list_type_token, siron_var_list_items_token, siron_var_list_item_token
} siron_token_type;

typedef struct siron_token {
    siron_linked_list* tokens;
    siron_token_type token_type;
    char* text;
} siron_token;

siron_token* siron_create_tokenptr(siron_token_type type, char* text) {
    siron_token* token = malloc(sizeof(siron_token));
    token->tokens = malloc(sizeof(siron_linked_list));
    token->tokens->data = NULL;

    token->token_type = type;
    token->text = text;
    return token;
}

siron_token siron_create_token(siron_token_type type, char* text) { 
    siron_token* token = siron_create_tokenptr(type, text); 
    return *token;
}


void siron_add_subtoken(siron_token* token, siron_token token_to_add) {
    siron_token* new_subtoken = malloc(sizeof(siron_token));
    new_subtoken->tokens = token_to_add.tokens;
    new_subtoken->text = token_to_add.text;
    new_subtoken->token_type = token_to_add.token_type;

    if (token->tokens->data == NULL)
        token->tokens->data = new_subtoken;
    else    
        siron_linked_list_add(token->tokens, new_subtoken);
}

void siron_add_subtokenptr(siron_token* token, siron_token* token_to_add) {
    if (token->tokens->data == NULL)
        token->tokens->data = token_to_add;
    else   
        siron_linked_list_add(token->tokens, token_to_add);
}

#define do_times(thing, count) for (int i = 0; i < count; i++) { thing; }

void siron_print_token(siron_token* token, int depth) {
    do_times(printf(" "), depth);
    printf("{%s}\n", token->text);

    loop_list(index, token->tokens) {
        siron_token* token_data = siron_linked_list_get(token->tokens, index);
        siron_print_token(token_data, depth + 1);
    }
}