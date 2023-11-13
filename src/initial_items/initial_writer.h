#pragma once

#include "initial_writer/gso_gen_define.h"
#include "initial_writer/gso_gen_variable.h"

void gso_write_to_file(gso_object object_to_write, gso_string_type path) {
    gso_file_type new_file = gso_file_data(path);

    gso_string_type data = "";
    
    data += gso_output_define(&object_to_write.header) + "\n";
    for (int i = 0; i < object_to_write.vars.size(); i++) {
        data += gso_output_variable(object_to_write.vars[i]) + "\n";
    }

    new_file.clear();
    new_file.set_data(data);
    
    gso_write_file_data(new_file);
}