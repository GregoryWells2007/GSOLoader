#pragma once

#include "../siron_var.hpp"
#include "siron_list_types/siron_list_type.hpp"
#include "siron_list_types/siron_list_types_include.hpp"

class siron_list : public siron_var {
public:
    siron_string_type type;
    siron_vector_type<siron_list_type*> items;
public:
    template<typename T> 
    T get_item(int index) { return *dynamic_cast<T*>(items[index]); }

    void set_type(siron_string_type new_type) { type = new_type; }
    void add_item(siron_list_type* item) { items.add(item); }
    void clear() { items.clear(); }
public:
    virtual void ReadData(siron_token token) override { 
        type = token.get_subtoken(2).get_subtoken(0).token_text;
        siron_token data_token = token.get_subtoken(2).get_subtoken(1);

        for (int i = 0; i < data_token.sub_tokens.size(); i++) {
            siron_list_type* new_list_item = nullptr;

            if (type == "char")
                new_list_item = new siron_list_char();
            if (type == "color")
                new_list_item = new siron_list_color();
            if (type == "number")
                new_list_item = new siron_list_number();
            if (type == "string")
                new_list_item = new siron_list_string();

            new_list_item->Read(data_token.sub_tokens[i]);
            items.add(new_list_item);
        }
    };
    virtual siron_var_data WriteData() override { 
        siron_var_data data = siron_var_data();
        data.variable_type = "list";
        data.items.add(type);
        
        data.items.add("[");

        for (int i = 0; i < items.size(); i++) {
            data.items.add(items[i]->Write());
        }

        data.items.add("]");

        return data; 
    }
public:
    virtual siron_string_type to_string() override {
        siron_string_type output = "[";
        for (int i = 0; i < items.size() - 1; i++)
            output += items[i]->to_string() + ", ";
        output += items[items.size() - 1]->to_string();
        output += "]";
        return output;
    };
};