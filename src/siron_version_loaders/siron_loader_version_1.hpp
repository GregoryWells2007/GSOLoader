#pragma once

#include "../siron_utils.hpp"

#include "../siron_object.hpp"
#include "../siron_defs/siron_def.hpp"
#include "../siron_defs/defs/siron_header.hpp"
#include "../siron_types/siron_vector_type.hpp"
#include "../siron_types/siron_string_type.hpp"
#include "../siron_types/siron_token.hpp"

#include "../siron_vars/vars/siron_vars_include.hpp"

namespace siron_loader_1 {
    siron_token siron_ceate_variable_token(siron_token token);

    siron_vector_type<siron_token> get_variable_tokens(siron_token token) {
        siron_vector_type<siron_token> tokens = {};

        siron_token current_token = siron_token();
        siron_string_type token_text = "";

        bool loading_token = false;
        int cbrackers_index = 0;

        siron_vector_type<siron_string_type> components = siron_utils::siron_get_components(token.token_text);
        for (int i = 0; i < components.size(); i++) {
            if (loading_token) {
                token_text += " ";
                token_text += components[i];
                if (components[i].find('{') != -1) {
                    cbrackers_index++;
                }
                else if (components[i].find('}') != -1) {
                    cbrackers_index--;
                    if (cbrackers_index == 0) {
                        loading_token = false;
                        current_token.token_text = token_text;
                        tokens.add(current_token);
                        current_token = siron_token();
                    }
                }  
            } else {
                if (components[i].find("var") != -1 && components[i].find("def") == -1) {
                    current_token.token_type = siron_token_type::siron_var_token;
                    loading_token = true;
                    cbrackers_index = 0;
                    token_text = components[i];
                }
            }
        }
        return tokens;
    }

    siron_token siron_load_variable_container(siron_token token) {
        siron_vector_type<siron_token> variable_tokens = get_variable_tokens(token);
        for (int i = 0; i < variable_tokens.size(); i++) {
            variable_tokens[i] = siron_ceate_variable_token(variable_tokens[i]);
            token.add_subtoken(variable_tokens[i]);
        }

        return token;
    }
    siron_token siron_load_variable_number(siron_token token) { 
        siron_token siron_data_token = siron_token();
        siron_data_token.set_token_type(siron_token_type::siron_var_number_value_token);
        siron_data_token.set_token_text(token.token_text);

        token.add_subtoken(siron_data_token);

        return token; 
    }
    siron_token siron_load_variable_int(int size, siron_token token) { 
        siron_vector_type<siron_string_type> components = siron_utils::siron_get_components(token.token_text);

        for (int i = 0; i < size; i++) {
            siron_token component_token = siron_token();
            if (i == 0)
                component_token.set_token_type(siron_token_type::siron_var_int_num1_token);
            if (i == 1)
                component_token.set_token_type(siron_token_type::siron_var_int_num2_token);
            if (i == 2)
                component_token.set_token_type(siron_token_type::siron_var_int_num3_token);
            if (i == 3)
                component_token.set_token_type(siron_token_type::siron_var_int_num4_token);
            component_token.set_token_text(components[i]);
            token.add_subtoken(component_token);
        }

        return token; 
    }
    siron_token siron_load_variable_float(int size, siron_token token) { 
        siron_vector_type<siron_string_type> components = siron_utils::siron_get_components(token.token_text);

        for (int i = 0; i < size; i++) {
            siron_token component_token = siron_token();
            if (i == 0)
                component_token.set_token_type(siron_token_type::siron_var_float_num1_token);
            if (i == 1)
                component_token.set_token_type(siron_token_type::siron_var_float_num2_token);
            if (i == 2)
                component_token.set_token_type(siron_token_type::siron_var_float_num3_token);
            if (i == 3)
                component_token.set_token_type(siron_token_type::siron_var_float_num4_token);
            component_token.set_token_text(components[i]);
            token.add_subtoken(component_token);
        }

        return token; 
    }
    siron_token siron_load_variable_double(int size, siron_token token) { 
        siron_vector_type<siron_string_type> components = siron_utils::siron_get_components(token.token_text);

        for (int i = 0; i < size; i++) {
            siron_token component_token = siron_token();
            if (i == 0)
                component_token.set_token_type(siron_token_type::siron_var_double_num1_token);
            if (i == 1)
                component_token.set_token_type(siron_token_type::siron_var_double_num2_token);
            if (i == 2)
                component_token.set_token_type(siron_token_type::siron_var_double_num3_token);
            if (i == 3)
                component_token.set_token_type(siron_token_type::siron_var_double_num4_token);
            component_token.set_token_text(components[i]);
            token.add_subtoken(component_token);
        }

        return token;   
    }
    siron_token siron_load_variable_color(siron_token token) { 
        siron_vector_type<siron_string_type> components = siron_utils::siron_get_components(token.token_text);

        siron_token color_r_token = siron_token();
        siron_token color_g_token = siron_token();
        siron_token color_b_token = siron_token();
        siron_token color_a_token = siron_token();

        color_r_token.set_token_type(siron_token_type::siron_var_color_r_token);
        color_r_token.set_token_text(components[0]);

        color_g_token.set_token_type(siron_token_type::siron_var_color_g_token);
        color_g_token.set_token_text(components[1]);

        color_b_token.set_token_type(siron_token_type::siron_var_color_b_token);
        color_b_token.set_token_text(components[2]);

        color_a_token.set_token_type(siron_token_type::siron_var_color_a_token);
        color_a_token.set_token_text(components[3]);

        token.add_subtoken(color_r_token);
        token.add_subtoken(color_g_token);
        token.add_subtoken(color_b_token);
        token.add_subtoken(color_a_token);



        return token; 
    }
    siron_token siron_load_variable_char(siron_token token) { 
        siron_token siron_data_token = siron_token();
        siron_data_token.set_token_type(siron_token_type::siron_var_char_value_token);
        siron_data_token.set_token_text(token.token_text);

        token.add_subtoken(siron_data_token);

        return token; 
    }
    siron_token siron_load_variable_string(siron_token token) { 
        siron_token siron_data_token = siron_token();
        siron_data_token.set_token_type(siron_token_type::siron_var_string_value_token);
        siron_data_token.set_token_text(token.token_text);

        token.add_subtoken(siron_data_token);

        return token; 
    }
    siron_token siron_load_variable_file(siron_token token) { 
        siron_token siron_data_token = siron_token();
        siron_data_token.set_token_type(siron_token_type::siron_var_file_path_token);
        siron_data_token.set_token_text(token.token_text);

        token.add_subtoken(siron_data_token);

        return token;
    }
    siron_token siron_load_variable_list(siron_token token) { 
        siron_string_type items_string = "";

        siron_vector_type<siron_string_type> components = siron_utils::siron_get_components(token.token_text);

        for (int c = 2; c < components.size() - 1; c++)
            items_string += components[c] + ' ';



        siron_token list_type_token = siron_token();
        list_type_token.set_token_type(siron_token_type::siron_var_list_type_token);
        list_type_token.set_token_text(components[0]);

        siron_token list_items_token = siron_token();
        list_items_token.set_token_type(siron_token_type::siron_var_list_items_token);
        list_items_token.set_token_text(items_string);

        bool adding_multipart_component = false;
        siron_string_type multipart_component_text = "";
        siron_token multipart_compoent = siron_token();

        for (int c = 2; c < components.size() - 1; c++) {
            if (components[c][0] == '(') {
                adding_multipart_component = true;
                multipart_component_text = "";
                multipart_compoent = siron_token();
            }

            if (!adding_multipart_component) {
                siron_token list_item_token = siron_token();
                list_item_token.set_token_type(siron_token_type::siron_var_list_item_token);
                list_item_token.set_token_text(components[c]);
                list_items_token.add_subtoken(list_item_token);
            } else {
                multipart_component_text += components[c] + " ";

                if (components[c] == "(")
                    continue;
                else if (components[c][0] == '(')
                    components[c] = components[c].substring(1, components[c].size());

                siron_token multipart_token = siron_token();
                multipart_token.set_token_text(components[c]);

                if (components[c][components[c].size() - 1] == ')')
                    multipart_token.set_token_text(components[c].substring(0, components[c].size() - 1));

                multipart_compoent.add_subtoken(multipart_token);

                if (components[c][components[c].size() - 1] == ')') {
                    adding_multipart_component = false;
                    multipart_compoent.set_token_type(siron_token_type::siron_var_list_item_token);
                    multipart_compoent.set_token_text(multipart_component_text);
                    list_items_token.add_subtoken(multipart_compoent);
                }
            }

        }

        token.add_subtoken(list_type_token);
        token.add_subtoken(list_items_token);

        return token; 
    }

    siron_token siron_ceate_variable_token(siron_token token) {
        siron_vector_type<siron_string_type> components = siron_utils::siron_get_components(token.token_text);

        siron_string_type siron_token_data = "";

        for (int i = 5; i < components.size() - 1; i++) {
            siron_token_data += components[i] + " ";
        }

        siron_token variable_type_token = siron_token();
        siron_token variable_name_token = siron_token();
        siron_token variable_data_token = siron_token();

        variable_type_token.set_token_type(siron_token_type::siron_var_type_token);
        variable_type_token.set_token_text(components[0].substring(4, components[0].size() - 1));

        variable_name_token.set_token_type(siron_token_type::siron_var_name_token);
        variable_name_token.set_token_text(components[2]);

        variable_data_token.set_token_type(siron_token_type::siron_var_data_token);
        variable_data_token.set_token_text(siron_token_data);

        if (variable_type_token.token_text == "container") {
            variable_type_token.token_type = siron_token_type::siron_var_type_container_token;
            variable_data_token = siron_load_variable_container(variable_data_token);
        }
        if (variable_type_token.token_text == "number") {
            variable_type_token.token_type = siron_token_type::siron_var_type_number_token;
            variable_data_token = siron_load_variable_number(variable_data_token);
        }
        if (variable_type_token.token_text.find("int") != -1) {
            variable_type_token.token_text += "1";
            int size = variable_type_token.token_text[3] - '0';
                
            if (size == 1)
                variable_type_token.token_type = siron_token_type::siron_var_type_int_token;
            if (size == 2)
                variable_type_token.token_type = siron_token_type::siron_var_type_int2_token;
            if (size == 3)
                variable_type_token.token_type = siron_token_type::siron_var_type_int3_token;
            if (size == 4)
                variable_type_token.token_type = siron_token_type::siron_var_type_int4_token;

            variable_data_token = siron_load_variable_int(size, variable_data_token);
        }
        if (variable_type_token.token_text.find("float") != -1) {
            variable_type_token.token_text += "1";
            int size = variable_type_token.token_text[5] - '0';

            if (size == 1)
                variable_type_token.token_type = siron_token_type::siron_var_type_float_token;
            if (size == 2)
                variable_type_token.token_type = siron_token_type::siron_var_type_float2_token;
            if (size == 3)
                variable_type_token.token_type = siron_token_type::siron_var_type_float3_token;
            if (size == 4)
                variable_type_token.token_type = siron_token_type::siron_var_type_float4_token;
        
            variable_data_token = siron_load_variable_float(size, variable_data_token);
        }
        if (variable_type_token.token_text.find("double") != -1) {
        
            variable_type_token.token_text += "1";
            int size = variable_type_token.token_text[6] - '0';

            if (size == 1)
                variable_type_token.token_type = siron_token_type::siron_var_type_double_token;
            if (size == 2)
                variable_type_token.token_type = siron_token_type::siron_var_type_double2_token;
            if (size == 3)
                variable_type_token.token_type = siron_token_type::siron_var_type_double3_token;
            if (size == 4)
                variable_type_token.token_type = siron_token_type::siron_var_type_double4_token;

            variable_data_token = siron_load_variable_double(size, variable_data_token);
        }
        if (variable_type_token.token_text == "color") {
            variable_type_token.token_type = siron_token_type::siron_var_type_color_token;
            variable_data_token = siron_load_variable_color(variable_data_token);
        }
        if (variable_type_token.token_text == "char") {
            variable_type_token.token_type = siron_token_type::siron_var_type_char_token;
            variable_data_token = siron_load_variable_char(variable_data_token);
        }
        if (variable_type_token.token_text == "string") {
            variable_type_token.token_type = siron_token_type::siron_var_type_string_token;
            variable_data_token = siron_load_variable_string(variable_data_token);
        }
        if (variable_type_token.token_text == "file") {
            variable_type_token.token_type = siron_token_type::siron_var_type_file_token;
            variable_data_token = siron_load_variable_file(variable_data_token);
        }
        if (variable_type_token.token_text == "list") {
            variable_type_token.token_type = siron_token_type::siron_var_type_list_token;
            variable_data_token = siron_load_variable_list(variable_data_token);
        }

        token.add_subtoken(variable_type_token);
        token.add_subtoken(variable_name_token);
        token.add_subtoken(variable_data_token);

        return token;
    }

    siron_var* siron_create_variable(siron_token token) {
        siron_var* variable = nullptr;

        if (token.get_subtoken(0).token_type ==  siron_token_type::siron_var_type_container_token)
            variable = new siron_container();
        if (token.get_subtoken(0).token_type ==  siron_token_type::siron_var_type_number_token)
            variable = new siron_number();
        if (token.get_subtoken(0).token_type == siron_token_type::siron_var_type_int_token ||
            token.get_subtoken(0).token_type == siron_token_type::siron_var_type_int2_token ||
            token.get_subtoken(0).token_type == siron_token_type::siron_var_type_int3_token ||
            token.get_subtoken(0).token_type == siron_token_type::siron_var_type_int4_token)
            variable = new siron_int();
        if (token.get_subtoken(0).token_type == siron_token_type::siron_var_type_float_token ||
            token.get_subtoken(0).token_type == siron_token_type::siron_var_type_float2_token ||
            token.get_subtoken(0).token_type == siron_token_type::siron_var_type_float3_token ||
            token.get_subtoken(0).token_type == siron_token_type::siron_var_type_float4_token)
            variable = new siron_float();
        if (token.get_subtoken(0).token_type == siron_token_type::siron_var_type_double_token ||
            token.get_subtoken(0).token_type == siron_token_type::siron_var_type_double2_token ||
            token.get_subtoken(0).token_type == siron_token_type::siron_var_type_double3_token ||
            token.get_subtoken(0).token_type == siron_token_type::siron_var_type_double4_token)
            variable = new siron_double();
        if (token.get_subtoken(0).token_type ==  siron_token_type::siron_var_type_color_token)
            variable = new siron_color();
        if (token.get_subtoken(0).token_type ==  siron_token_type::siron_var_type_char_token)
            variable = new siron_char();
        if (token.get_subtoken(0).token_type == siron_token_type::siron_var_type_string_token)
            variable = new siron_string();
        if (token.get_subtoken(0).token_type == siron_token_type::siron_var_type_file_token)
            variable = new siron_file();
        if (token.get_subtoken(0).token_type == siron_token_type::siron_var_type_list_token)
            variable = new siron_list();

        variable->Read(token);

        return variable;
    }

    siron_object siron_load_version_1_0(siron_object object) {
        siron_vector_type<siron_token> variable_tokens = get_variable_tokens(object.token);
        
        for (int i = 0; i < variable_tokens.size(); i++) {
            variable_tokens[i] = siron_ceate_variable_token(variable_tokens[i]);
            object.token.add_subtoken(variable_tokens[i]);
            siron_var* siron_variable = siron_create_variable(variable_tokens[i]);
            object.vars.add(siron_variable);
        }

        return object;

    }
}