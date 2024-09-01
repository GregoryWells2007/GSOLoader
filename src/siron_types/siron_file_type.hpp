#pragma once

#include "siron_string_type.hpp"

class siron_file_type {
private:
    siron_string_type path;
    siron_string_type data;
public:
    siron_string_type get_path() { return path; }
    siron_string_type get_data() { return data; }
public:
    operator siron_string_type() { return data; }
    void set_path(siron_string_type vpath) { path = vpath; } 
    void set_data(siron_string_type vData) { data = vData; }
    void add_line(siron_string_type line) { data += line + "\n"; }
    void clear() { data = ""; }
};