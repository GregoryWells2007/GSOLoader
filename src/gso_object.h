#pragma once

#include "gso_types/gso_token.h"
#include "gso_defs/defs/gso_header.h"
#include "gso_vars/gso_var.h"

#include "iostream"

struct gso_object {
public:
    gso_token token = gso_token(); // the master token to decide how to read the GSO file if it needs to be reread
    gso_header header = gso_header();
    gso_vector_type<gso_var*> vars = {};
public:

    template<typename T>
    T get_variable(gso_string_type name) {
        for (int i = 0; i < vars.size(); i++) {
            if (vars[i]->name == name)
                return *dynamic_cast<T*>(vars[i]);
        }
        std::cout << "Could not find variable of type\n";
        return T();
    }

    gso_var* get_variable(gso_string_type name) {
        for (int i = 0; i < vars.size(); i++) {
            if (vars[i]->name == name)
                return vars[i];
        }
        std::cout << "Could not find variable of type\n";
        return nullptr;
    }

    void print_token_hierarchy() {
        token.print_token_hierarchy(0);
    }

    ~gso_object() {
        // std::cout << "deleting object";
        // for (int i = 0; i < vars.size(); i++) {
        //     delete vars[i];
        // }
    }
};