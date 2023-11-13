#pragma once

#include "../gso_var.h"
#include "../../gso_loader_data.h"
#include "../../gso_file_reader.h"

class gso_file : public gso_var {
private:
    gso_string_type file_path;
    gso_file_type file;

    void read_from_disk() {
        file = gso_file_data(file_path);
    }
public:

    operator gso_string_type() { return file; }
    gso_string_type get_file_path() { return file_path; }
    void reload_file() { 
        read_from_disk();
    };

    void set_path(char* path) { file_path = path; }
    void set_path(const char* path) { file_path = path; }
    void set_path(gso_string_type path) { file_path = path; }
public: 
    virtual void ReadData(gso_token token) override { 
        file_path = gso_loader_data::file_path;
        file_path += token.get_subtoken(2).get_subtoken(0).token_text.substring(1, token.get_subtoken(2).get_subtoken(0).token_text.size() - 2);
        read_from_disk();
    };
    virtual gso_var_data WriteData() override { return gso_var_data(); }
};