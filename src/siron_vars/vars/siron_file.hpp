#pragma once

#include "../siron_var.hpp"
#include "../../siron_loader_data.hpp"
#include "../../siron_file_reader.hpp"

class siron_file : public siron_var {
private:
    siron_string_type file_path;
    siron_file_type file;

    void read_from_disk() {
        file = siron_file_data(file_path);
    }
public:

    operator siron_string_type() { return file; }
    siron_string_type get_file_path() { return file_path; }
    void reload_file() { 
        read_from_disk();
    };

    void set_path(char* path) { file_path = path; }
    void set_path(const char* path) { file_path = path; }
    void set_path(siron_string_type path) { file_path = path; }
public: 
    virtual void ReadData(siron_token token) override { 
        file_path = siron_loader_data::file_path;
        file_path += token.get_subtoken(2).get_subtoken(0).token_text.substring(1, token.get_subtoken(2).get_subtoken(0).token_text.size() - 2);
        read_from_disk();
    };
    virtual siron_var_data WriteData() override { 
        siron_var_data data = siron_var_data();
        data.variable_type = "file";

        siron_string_type output = "\"";
        output += file_path;
        output += "\"";

        data.items.add(output);
        return data; 
    }
public:
    virtual siron_string_type to_string() override {
        return file.get_data();
    };
};