#pragma once

#include "../../gso_vars/gso_var.h"

gso_string_type gso_output_variable(gso_var* variable) {
    gso_var_data data = variable->Write();
    gso_string_type output = "var<";

    output += data.variable_type;

    output += "> : ";
    output += variable->name;
    output += " -> {";

    if (data.is_indented)
        output += "\n";

    for (int i = 0; i < data.items.size(); i++) {
        if (data.is_indented)
            output += "\t";

        output += data.items[i] + "\n";
    }

    output += "}";

    return output;   
}