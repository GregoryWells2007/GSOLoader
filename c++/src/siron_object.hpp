#pragma once

#include "siron_types/siron_token.hpp"
#include "siron_defs/defs/siron_header.hpp"
#include "siron_vars/siron_var.hpp"

#include "iostream"

struct siron_object {
public:
    siron_token token = siron_token(); // the master token to decide how to read the siron file if it needs to be reread
    siron_header header = siron_header();
    siron_vector_type<siron_var*> vars = {};
public:

    template<typename T>
    T get_variable(siron_string_type name) {
        for (int i = 0; i < vars.size(); i++) {
            if (vars[i]->name == name)
                return *dynamic_cast<T*>(vars[i]);
        }
        std::cout << "Could not find variable of type\n";
        return T();
    }

    void add_variable(siron_var* variable) {vars.add(variable); }
    
    siron_var* get_variable(siron_string_type name) {
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

    ~siron_object() {
        // std::cout << "deleting object";
        // for (int i = 0; i < vars.size(); i++) {
        //     delete vars[i];
        // }
    }
};