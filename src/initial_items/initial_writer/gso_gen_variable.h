#pragma once

#include "../../gso_vars/gso_var.h"

gso_string_type gso_output_variable(gso_var* variable) {
    gso_var_data data = variable->write();
    gso_string_type output = "var<";

    output += data.variable_type;

    output += "> : ";
    output += variable->name;
    output += " -> { ";

    for (int i = 0; i < data.items.size(); i++) {
        if (data.is_indented)
            output += "\n    ";

        output += data.items[i];

        if ((i + 1) < data.items.size())
            output += " ";
    }

    if (data.is_indented)
        output += "\n}";
    else
        output += " }";

    return output;   
}