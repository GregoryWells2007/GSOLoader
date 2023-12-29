#pragma once
#include "siron_vector_type.hpp"
#include "siron_string_type.hpp"

#include <vector> 

enum class siron_token_type {
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
};

siron_string_type token_type_to_string(siron_token_type type) {
    switch (type)
    {
    case siron_token_type::siron_null_token: return "siron_null_token";

    case siron_token_type::siron_master_token: return "siron_master_token";

    case siron_token_type::siron_def_token: return "siron_def_token"; 
    case siron_token_type::siron_def_type_token: return "siron_def_type_token";
    case siron_token_type::siron_def_variables_token: return "siron_def_variables_token";
    case siron_token_type::siron_def_variable_token: return "siron_def_variable_token";
    case siron_token_type::siron_def_variable_name_token: return "siron_def_variable_name_token";
    case siron_token_type::siron_def_variable_value_token: return "siron_def_variable_value_token";

    case siron_token_type::siron_var_token: return "siron_var_token";
    case siron_token_type::siron_var_type_token: return "siron_var_type_token";
    case siron_token_type::siron_var_name_token: return "siron_var_name_token";
    case siron_token_type::siron_var_data_token: return "siron_var_data_token";

    case siron_token_type::siron_var_type_container_token: return "siron_var_type_container_token";

    case siron_token_type::siron_var_type_number_token: return "siron_var_type_number_token";
    case siron_token_type::siron_var_number_value_token: return "siron_var_number_value_token";

    case siron_token_type::siron_var_type_int_token: return "siron_var_type_int_token"; 
    case siron_token_type::siron_var_type_int2_token: return "siron_var_type_int2_token"; 
    case siron_token_type::siron_var_type_int3_token: return "siron_var_type_int3_token"; 
    case siron_token_type::siron_var_type_int4_token: return "siron_var_type_int4_token";
    case siron_token_type::siron_var_int_num1_token: return "siron_var_int_num1_token";
    case siron_token_type::siron_var_int_num2_token: return "siron_var_int_num2_token";
    case siron_token_type::siron_var_int_num3_token: return "siron_var_int_num3_token";
    case siron_token_type::siron_var_int_num4_token: return "siron_var_int_num4_token";
    

    case siron_token_type::siron_var_type_float_token: return "siron_var_type_float_token"; 
    case siron_token_type::siron_var_type_float2_token: return "siron_var_type_float2_token"; 
    case siron_token_type::siron_var_type_float3_token: return "siron_var_type_float3_token"; 
    case siron_token_type::siron_var_type_float4_token: return "siron_var_type_float4_token";
    case siron_token_type::siron_var_float_num1_token: return "siron_var_float_num1_token"; 
    case siron_token_type::siron_var_float_num2_token: return "siron_var_float_num2_token";  
    case siron_token_type::siron_var_float_num3_token: return "siron_var_float_num3_token"; 
    case siron_token_type::siron_var_float_num4_token: return "siron_var_float_num4_token"; 

    case siron_token_type::siron_var_type_double_token: return "siron_var_type_double_token"; 
    case siron_token_type::siron_var_type_double2_token: return "siron_var_type_double2_token"; 
    case siron_token_type::siron_var_type_double3_token: return "siron_var_type_double3_token"; 
    case siron_token_type::siron_var_type_double4_token: return "siron_var_type_double4_token";
    case siron_token_type::siron_var_double_num1_token: return "siron_var_double_num1_token"; 
    case siron_token_type::siron_var_double_num2_token: return "siron_var_double_num2_token";  
    case siron_token_type::siron_var_double_num3_token: return "siron_var_double_num3_token"; 
    case siron_token_type::siron_var_double_num4_token: return "siron_var_double_num4_token"; 

    case siron_token_type::siron_var_type_color_token: return "siron_var_type_color_token";
    case siron_token_type::siron_var_color_r_token: return "siron_var_color_r_token";
    case siron_token_type::siron_var_color_g_token: return "siron_var_color_g_token";
    case siron_token_type::siron_var_color_b_token: return "siron_var_color_b_token";
    case siron_token_type::siron_var_color_a_token: return "siron_var_color_a_token";

    case siron_token_type::siron_var_type_char_token: return "siron_var_type_char_token";
    case siron_token_type::siron_var_char_value_token: return "siron_var_char_value_token";
    
    case siron_token_type::siron_var_type_string_token: return "siron_var_type_string_token";
    case siron_token_type::siron_var_string_value_token: return "siron_var_string_value_token";

    case siron_token_type::siron_var_type_file_token: return "siron_var_type_file_token";
    case siron_token_type::siron_var_file_path_token: return "siron_var_file_path_token";

    case siron_token_type::siron_var_type_list_token: return "siron_var_type_list_token";
    case siron_token_type::siron_var_list_type_token: return "siron_var_list_type_token";
    case siron_token_type::siron_var_list_items_token: return "siron_var_list_items_token";
    case siron_token_type::siron_var_list_item_token: return "siron_var_list_item_token";
    }
    return "siron_no_token_type";
}




struct siron_token {
public:
    siron_token_type token_type = siron_token_type::siron_null_token;
    siron_vector_type<siron_token> sub_tokens = {};
    siron_string_type token_text = "";
public:
    siron_token get_subtoken(int index) { return sub_tokens[index]; }
    void add_subtoken(siron_token token) { sub_tokens.add(token); }

    void set_token_text(siron_string_type text) { token_text = text; }
    void set_token_type(siron_token_type type) { token_type = type; }
public:
    void print_token_hierarchy(int index) {
        siron_string_type before_string = "";
        for (int x = 0; x < index; x++)
            before_string += "  ";

        std::cout << before_string << token_type_to_string(token_type) << "\n";
        for (int c = 0; c < sub_tokens.size(); c++) {
            sub_tokens[c].print_token_hierarchy(index + 1);
        }
    }
};