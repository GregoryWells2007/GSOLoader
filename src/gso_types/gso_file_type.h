#pragma once

#include "gso_string_type.h"

class gso_file_type {
private:
    gso_string_type data;
public:
    operator gso_string_type() { return data; }
    void add_line(gso_string_type line) {
        data += line + "\n";
    }
};