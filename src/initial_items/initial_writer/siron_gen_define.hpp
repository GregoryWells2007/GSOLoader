#pragma once

#include "../../siron_utils.hpp"
#include "../../siron_defs/siron_def.hpp"
#include "../../siron_types/siron_token.hpp"

siron_string_type siron_output_define(siron_def* define) {
    siron_def_data define_data = define->Write();

    siron_string_type output = "";

    output += "def<";
    output += define_data.define_type;
    output += "> { \n";

    for (int i = 0 ; i < define_data.variables.size(); i++) {     
        output += "\t";
        output += tuple_get<0>(define_data.variables[i]) + ": ";
        output += tuple_get<1>(define_data.variables[i]) + "\n";
    }

    output += "}\n";

    return output;
}