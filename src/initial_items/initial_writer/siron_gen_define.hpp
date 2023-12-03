#pragma once

#include "../../siron_utils.hpp"
#include "../../siron_defs/siron_def.hpp"
#include "../../siron_types/siron_token.hpp"

siron_string_type siron_output_define(siron_def* define) {
    siron_token define_token = define->Write();

    siron_string_type output = "";

    output += "def<";
    output += define_token.get_subtoken(0).token_text;
    output += "> { \n";

    for (int i = 0 ; i < define_token.get_subtoken(1).sub_tokens.size(); i++) {     
        output += "\t";
        output += define_token.get_subtoken(1).sub_tokens[i].get_subtoken(0).token_text + ": ";
        output += define_token.get_subtoken(1).sub_tokens[i].get_subtoken(1).token_text + "\n";
    }

    output += "}\n";

    return output;
}