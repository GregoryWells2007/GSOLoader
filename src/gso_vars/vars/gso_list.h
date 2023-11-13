#pragma once

#include "../gso_var.h"
#include "gso_list_types/gso_list_type.h"
#include "gso_list_types/gso_list_types_include.h"

class gso_list : public gso_var {
public:
    gso_string_type type;
    gso_vector_type<gso_list_type*> items;
public:
    template<typename T> 
    T get_item(int index) { return *dynamic_cast<T*>(items[index]); }

    void set_type(gso_string_type new_type) { type = new_type; }
    void add_item(gso_list_type* item) { items.add(item); }
    void clear() { items.clear(); }
public:
    virtual void ReadData(gso_token token) override { 
        type = token.get_subtoken(2).get_subtoken(0).token_text;
        gso_token data_token = token.get_subtoken(2).get_subtoken(1);

        for (int i = 0; i < data_token.sub_tokens.size(); i++) {
            gso_list_type* new_list_item = nullptr;

            if (type == "char")
                new_list_item = new gso_list_char();
            if (type == "color")
                new_list_item = new gso_list_color();
            if (type == "number")
                new_list_item = new gso_list_number();
            if (type == "string")
                new_list_item = new gso_list_string();

            new_list_item->Read(data_token.sub_tokens[i]);
            items.add(new_list_item);
        }
    };
    virtual gso_var_data WriteData() override { return gso_var_data(); }
};