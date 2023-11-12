#pragma once

#include "../../gso_utils.h"

#include "../../gso_object.h"
#include "../../gso_defs/gso_def.h"
#include "../../gso_defs/defs/gso_header.h"
#include "../../gso_types/gso_vector_type.h"
#include "../../gso_types/gso_string_type.h"
#include "../../gso_types/gso_tuple_type.h"
#include "../../gso_types/gso_token.h"

#include "../../gso_file_reader.h"

// version loaders
#include "../../gso_version_loaders/gso_current_loader.h"

#include "../../gso_loader_data.h"

gso_string_type gso_output_define(gso_def* define) {
    gso_token define_token = define->Write();

    gso_string_type output = "";

    output += "def<";
    output += define_token.get_subtoken(0).token_text;
    output += "> { \n";

    for (int i = 0 ; i < define_token.get_subtoken(1).sub_tokens.size(); i++) {
        define_token.get_subtoken(1).sub_tokens[i].print_token_hierarchy(0);        

        output += "\t";
        output += define_token.get_subtoken(1).sub_tokens[i].get_subtoken(0).token_text + ": ";
        output += define_token.get_subtoken(1).sub_tokens[i].get_subtoken(1).token_text + "\n";
    }

    output += "}\n";
    
    return output;
}