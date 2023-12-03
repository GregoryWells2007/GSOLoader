#pragma once

#include "../siron_var.hpp"

#include "siron_number.hpp"
#include "siron_int.hpp"
#include "siron_float.hpp"
#include "siron_double.hpp"
#include "siron_color.hpp"
#include "siron_char.hpp"
#include "siron_string.hpp"
#include "siron_file.hpp"
#include "siron_list.hpp"

#include "../../initial_items/initial_writer/siron_gen_variable.hpp"

class siron_container : public siron_var {
public:
    siron_vector_type<siron_var*> variables = {};
public:
    template<typename T>
    T get_variable(siron_string_type name) {
        for (int i = 0; i < variables.size(); i++) {
            if (variables[i]->name == name)
                return *dynamic_cast<T*>(variables[i]);
        }
        std::cout << "Could not find variable of type\n";
        return T();
    }

    siron_var* get_variable(siron_string_type name) {
        for (int i = 0; i < variables.size(); i++) {
            if (variables[i]->name == name)
                return variables[i];
        }
        std::cout << "Could not find variable of type\n";
        return nullptr;
    }

    void add_variable(siron_var* var) { variables.add(var); }
public:
    virtual void ReadData(siron_token token) override { 
        for (int i = 0; i < token.sub_tokens[2].sub_tokens.size(); i++) {
            siron_var* variable = nullptr;          
            siron_token_type token_type = token.sub_tokens[2].sub_tokens[i].sub_tokens[0].token_type;

            if (token_type == siron_token_type::siron_var_type_container_token)
                variable = new siron_container();
            if (token_type == siron_token_type::siron_var_type_number_token)
                variable = new siron_number();
            if (token_type == siron_token_type::siron_var_int_num1_token ||
                token_type == siron_token_type::siron_var_int_num2_token ||
                token_type == siron_token_type::siron_var_int_num3_token ||
                token_type == siron_token_type::siron_var_int_num4_token)
                variable = new siron_int();
            if (token_type == siron_token_type::siron_var_float_num1_token ||
                token_type == siron_token_type::siron_var_float_num2_token ||
                token_type == siron_token_type::siron_var_float_num3_token ||
                token_type == siron_token_type::siron_var_float_num4_token)
                variable = new siron_float();
            if (token_type == siron_token_type::siron_var_double_num1_token ||
                token_type == siron_token_type::siron_var_double_num2_token ||
                token_type == siron_token_type::siron_var_double_num3_token ||
                token_type == siron_token_type::siron_var_double_num4_token)
                variable = new siron_double();
            if (token_type ==  siron_token_type::siron_var_type_color_token)
                variable = new siron_color();
            if (token_type ==  siron_token_type::siron_var_type_char_token)
                variable = new siron_char();
            if (token_type == siron_token_type::siron_var_type_string_token)
                variable = new siron_string();
            if (token_type == siron_token_type::siron_var_type_file_token)
                variable = new siron_file();
            if (token_type == siron_token_type::siron_var_type_list_token)
                variable = new siron_list();

            variable->Read(token.sub_tokens[2].get_subtoken(i));
            variables.add(variable);
        }
    }
    virtual siron_var_data WriteData() override { 
        siron_var_data data = siron_var_data();
        data.variable_type = "container";
        data.is_indented = true;

        for (int i = 0; i < variables.size(); i++) {
            siron_string_type variable_output = siron_output_variable(variables[i]);
            data.items.add(variable_output);
        }

        return data; 
    }
public:
    virtual siron_string_type to_string() override {  
        return "Container cannot be cast to a string";
    };
};
