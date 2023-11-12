#pragma once

#include "gso_string_type.h"

class gso_file_type {
private:
    gso_string_type path;
    gso_string_type data;
public:
    gso_string_type get_path() { return path; }
    gso_string_type get_data() { return data; }
public:
    operator gso_string_type() { return data; }
    void set_path(gso_string_type vpath) { path = vpath; } 
    void set_data(gso_string_type vData) { data = vData; }
    void add_line(gso_string_type line) { data += line + "\n"; }
    void clear() { data = ""; }
};