#pragma once

#include "initial_writer/siron_gen_define.hpp"
#include "initial_writer/siron_gen_variable.hpp"

void siron_write_to_file(siron_object object_to_write, siron_string_type path) {
    siron_file_type new_file = siron_file_data(path);

    siron_string_type data = "";
    
    data += siron_output_define(&object_to_write.header) + "\n";
    for (int i = 0; i < object_to_write.vars.size(); i++) {
        data += siron_output_variable(object_to_write.vars[i]) + "\n";
    }

    new_file.clear();
    new_file.set_data(data);
    
    siron_write_file_data(new_file);
}