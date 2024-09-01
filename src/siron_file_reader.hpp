#pragma once
#include "fstream"
#include "siron_types/siron_file_type.hpp"

siron_file_type siron_file_data(siron_string_type path) {
    siron_file_type file_data = siron_file_type();
    file_data.set_path(path);
    std::ifstream file(path);
    std::string line;
    while (std::getline(file, line)) {
        siron_string_type value(line.c_str());
        file_data.add_line(value);
    }

    siron_string_type final_file_data = file_data;
    return file_data;
}

void siron_write_file_data(siron_file_type file) {
    std::ofstream file_output = std::ofstream(file.get_path());
    file_output << file.get_data();
}