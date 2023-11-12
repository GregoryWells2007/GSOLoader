#pragma once

#include "initial_writer/gso_gen_define.h"

void gso_write_to_file(gso_object file, gso_string_type path) {
    gso_file_type new_file = gso_file_data(path);

    gso_string_type data = "";
    
    data += gso_output_define(&file.header);

    new_file.clear();
    new_file.set_data(data);
    
    gso_write_file_data(new_file);
}