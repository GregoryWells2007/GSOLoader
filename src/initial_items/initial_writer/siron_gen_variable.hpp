#pragma once

#include "../../siron_vars/siron_var.hpp"

siron_string_type siron_output_variable(siron_var* variable) {
    siron_var_data data = variable->write();
    siron_string_type output = "var<";

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