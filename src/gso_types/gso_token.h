#pragma once
#include "gso_vector_type.h"
#include "gso_string_type.h"

#include <vector> 

enum class gso_token_type {
    gso_null_token,

    gso_master_token,
    
    gso_def_token, 
    gso_def_type_token,
    gso_def_variables_token,
    gso_def_variable_token,
    gso_def_variable_name_token,
    gso_def_variable_value_token,

    gso_var_token,
    gso_var_type_token,
    gso_var_name_token,
    gso_var_data_token,
    
    gso_var_type_container_token,
    gso_var_type_number_token, gso_var_number_value_token,
    
    gso_var_type_int_token, 
    gso_var_type_int2_token, 
    gso_var_type_int3_token, 
    gso_var_type_int4_token, gso_var_int_num1_token, gso_var_int_num2_token, gso_var_int_num3_token, gso_var_int_num4_token,

    gso_var_type_float_token, 
    gso_var_type_float2_token, 
    gso_var_type_float3_token, 
    gso_var_type_float4_token, gso_var_float_num1_token, gso_var_float_num2_token, gso_var_float_num3_token, gso_var_float_num4_token,

    gso_var_type_double_token, 
    gso_var_type_double2_token, 
    gso_var_type_double3_token, 
    gso_var_type_double4_token, gso_var_double_num1_token, gso_var_double_num2_token, gso_var_double_num3_token, gso_var_double_num4_token,

    gso_var_type_color_token, gso_var_color_r_token, gso_var_color_g_token, gso_var_color_b_token, gso_var_color_a_token,
    gso_var_type_char_token, gso_var_char_value_token,

    gso_var_type_string_token, gso_var_string_value_token,
    gso_var_type_file_token, gso_var_file_path_token,
    gso_var_type_list_token, gso_var_list_type_token, gso_var_list_items_token, gso_var_list_item_token
};

gso_string_type token_type_to_string(gso_token_type type) {
    switch (type)
    {
    case gso_token_type::gso_null_token: return "gso_null_token";

    case gso_token_type::gso_master_token: return "gso_master_token";

    case gso_token_type::gso_def_token: return "gso_def_token"; 
    case gso_token_type::gso_def_type_token: return "gso_def_type_token";
    case gso_token_type::gso_def_variables_token: return "gso_def_variables_token";
    case gso_token_type::gso_def_variable_token: return "gso_def_variable_token";
    case gso_token_type::gso_def_variable_name_token: return "gso_def_variable_name_token";
    case gso_token_type::gso_def_variable_value_token: return "gso_def_variable_value_token";

    case gso_token_type::gso_var_token: return "gso_var_token";
    case gso_token_type::gso_var_type_token: return "gso_var_type_token";
    case gso_token_type::gso_var_name_token: return "gso_var_name_token";
    case gso_token_type::gso_var_data_token: return "gso_var_data_token";

    case gso_token_type::gso_var_type_container_token: return "gso_var_type_container_token";

    case gso_token_type::gso_var_type_number_token: return "gso_var_type_number_token";
    case gso_token_type::gso_var_number_value_token: return "gso_var_number_value_token";

    case gso_token_type::gso_var_type_int_token: return "gso_var_type_int_token"; 
    case gso_token_type::gso_var_type_int2_token: return "gso_var_type_int2_token"; 
    case gso_token_type::gso_var_type_int3_token: return "gso_var_type_int3_token"; 
    case gso_token_type::gso_var_type_int4_token: return "gso_var_type_int4_token";
    case gso_token_type::gso_var_int_num1_token: return "gso_var_int_num1_token";
    case gso_token_type::gso_var_int_num2_token: return "gso_var_int_num2_token";
    case gso_token_type::gso_var_int_num3_token: return "gso_var_int_num3_token";
    case gso_token_type::gso_var_int_num4_token: return "gso_var_int_num4_token";
    

    case gso_token_type::gso_var_type_float_token: return "gso_var_type_float_token"; 
    case gso_token_type::gso_var_type_float2_token: return "gso_var_type_float2_token"; 
    case gso_token_type::gso_var_type_float3_token: return "gso_var_type_float3_token"; 
    case gso_token_type::gso_var_type_float4_token: return "gso_var_type_float4_token";
    case gso_token_type::gso_var_float_num1_token: return "gso_var_float_num1_token"; 
    case gso_token_type::gso_var_float_num2_token: return "gso_var_float_num2_token";  
    case gso_token_type::gso_var_float_num3_token: return "gso_var_float_num3_token"; 
    case gso_token_type::gso_var_float_num4_token: return "gso_var_float_num4_token"; 

    case gso_token_type::gso_var_type_double_token: return "gso_var_type_double_token"; 
    case gso_token_type::gso_var_type_double2_token: return "gso_var_type_double2_token"; 
    case gso_token_type::gso_var_type_double3_token: return "gso_var_type_double3_token"; 
    case gso_token_type::gso_var_type_double4_token: return "gso_var_type_double4_token";
    case gso_token_type::gso_var_double_num1_token: return "gso_var_double_num1_token"; 
    case gso_token_type::gso_var_double_num2_token: return "gso_var_double_num2_token";  
    case gso_token_type::gso_var_double_num3_token: return "gso_var_double_num3_token"; 
    case gso_token_type::gso_var_double_num4_token: return "gso_var_double_num4_token"; 

    case gso_token_type::gso_var_type_color_token: return "gso_var_type_color_token";
    case gso_token_type::gso_var_color_r_token: return "gso_var_color_r_token";
    case gso_token_type::gso_var_color_g_token: return "gso_var_color_g_token";
    case gso_token_type::gso_var_color_b_token: return "gso_var_color_b_token";
    case gso_token_type::gso_var_color_a_token: return "gso_var_color_a_token";

    case gso_token_type::gso_var_type_char_token: return "gso_var_type_char_token";
    case gso_token_type::gso_var_char_value_token: return "gso_var_char_value_token";
    
    case gso_token_type::gso_var_type_string_token: return "gso_var_type_string_token";
    case gso_token_type::gso_var_string_value_token: return "gso_var_string_value_token";

    case gso_token_type::gso_var_type_file_token: return "gso_var_type_file_token";
    case gso_token_type::gso_var_file_path_token: return "gso_var_file_path_token";

    case gso_token_type::gso_var_type_list_token: return "gso_var_type_list_token";
    case gso_token_type::gso_var_list_type_token: return "gso_var_list_type_token";
    case gso_token_type::gso_var_list_items_token: return "gso_var_list_items_token";
    case gso_token_type::gso_var_list_item_token: return "gso_var_list_item_token";
    }
    return "gso_no_token_type";
}




struct gso_token {
public:
    gso_token_type token_type = gso_token_type::gso_null_token;
    gso_vector_type<gso_token> sub_tokens = {};
    gso_string_type token_text = "";
public:
    gso_token get_subtoken(int index) { return sub_tokens[index]; }
    void add_subtoken(gso_token token) { sub_tokens.add(token); }

    void set_token_text(gso_string_type text) { token_text = text; }
    void set_token_type(gso_token_type type) { token_type = type; }
public:
    void print_token_hierarchy(int index) {
        gso_string_type before_string = "";
        for (int x = 0; x < index; x++)
            before_string += "  ";

        std::cout << before_string << token_type_to_string(token_type) << "\n";
        for (int c = 0; c < sub_tokens.size(); c++) {
            sub_tokens[c].print_token_hierarchy(index + 1);
        }
    }
};