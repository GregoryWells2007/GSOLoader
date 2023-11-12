#pragma once
#include "fstream"
#include "gso_types/gso_file_type.h"

gso_file_type gso_file_data(gso_string_type path) {
    gso_file_type file_data = gso_file_type();
    std::ifstream file(path);
    std::string line;
    while (std::getline(file, line)) {
        gso_string_type value(line.c_str());
        file_data.add_line(value);
    }

    gso_string_type final_file_data = file_data;
    return file_data;
}