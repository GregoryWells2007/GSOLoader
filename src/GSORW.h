#pragma once

#include "gso_utils.h"

#include "gso_object.h"
#include "gso_defs/gso_def.h"
#include "gso_defs/defs/gso_header.h"
#include "gso_types/gso_vector_type.h"
#include "gso_types/gso_string_type.h"
#include "gso_types/gso_tuple_type.h"
#include "gso_types/gso_token.h"

#include "gso_file_reader.h"

// version loaders
#include "gso_version_loaders/gso_current_loader.h"

#include "gso_loader_data.h"

namespace gso_steps {
    gso_string_type gso_remove_comments(gso_string_type text) {
        gso_vector_type<gso_string_type> lines = gso_utils::gso_get_lines(text);

        for (int i = 0; i < lines.size(); i++) {
            int comment_index = lines[i].find('#');
            if (comment_index != -1) {
                char before = ' ';
                char after = lines[i][comment_index + 1];
                if (comment_index > 0)
                    before = lines[i][comment_index - 1];

                if (after == '>')
                    break;
                if (before == '<')
                    break;

                lines[i] = lines[i].substring(comment_index, comment_index);
            }
        }

        gso_string_type final_pass;
        for (int i = 0; i < lines.size(); i++) {
            final_pass += lines[i];
            final_pass += "\n";
        }

        while (final_pass.find("<#") != -1) {

            int startOf = final_pass.find("<#");
            int index = 1;

            for (int i = startOf + 1; i < final_pass.size(); i++) {
                if (final_pass[i] == '<' && final_pass[i + 1] == '#') {
                    index++;
                } else if (final_pass[i] == '#' && final_pass[i + 1] == '>') {
                    index--;
                    if (index == 0) {
                        final_pass = final_pass.substring(0, startOf) + final_pass.substring(i + 2, final_pass.size());
                        break;
                    }
                }
            }
        }

        return final_pass;
    }
    gso_string_type gso_remove_dead_lines(gso_string_type text) {
        gso_vector_type<gso_string_type> lines = gso_utils::gso_get_lines(text);
        gso_string_type final_text;
        for (int i = 0; i < lines.size(); i++) {
            if (lines[i].size() > 0) {
                final_text += lines[i];
                final_text += "\n";
            }
        }
        return final_text;
    }
    gso_string_type gso_remove_lines(gso_string_type text) {
        gso_vector_type<gso_string_type> lines = gso_utils::gso_get_lines(text);
        gso_string_type output = "";
        for (int i = 0; i < lines.size(); i++) {
            gso_vector_type<gso_string_type> components = gso_utils::gso_get_components(lines[i]);
            for (int c = 0; c < components.size(); c++) {
                output += components[c];
                output += ' ';
            }
        }
        return output;
    }
    gso_vector_type<gso_token> gso_get_token_tree(gso_string_type text) {
        gso_vector_type<gso_token> tokens = {};

        gso_token current_token = gso_token();
        gso_string_type token_text = "";

        bool loading_token = false;
        int cbrackers_index = 0;

        gso_vector_type<gso_string_type> components = gso_utils::gso_get_components(text);
        for (int i = 0; i < components.size(); i++) {
            if (loading_token) {
                token_text += " ";
                token_text += components[i];
                if (components[i].find('{') != -1) {
                    cbrackers_index++;
                }
                else if (components[i].find('}') != -1) {
                    cbrackers_index--;
                    if (cbrackers_index == 0) {
                        loading_token = false;
                        current_token.token_text = token_text;
                        tokens.add(current_token);
                        current_token = gso_token();
                    }
                }  
            } else {
                if (components[i].find("def") != -1) {
                    current_token.token_type = gso_token_type::gso_def_token;
                    loading_token = true;
                    cbrackers_index = 0;
                    token_text = components[i];
                }
                // else if (components[i].find("var") != -1) {
                //     current_token.token_type = gso_token_type::gso_var_token;
                //     loading_token = true;
                //     cbrackers_index = 0;
                //     token_text = components[i];
                // }
            }
        }
        return tokens;
    }
}
namespace gso_token_loaders {
    gso_token gso_load_def_token(gso_token def_token) {
        gso_vector_type<gso_string_type> components = gso_utils::gso_get_components(def_token.token_text);

        // load type
        gso_token define_type_token = gso_token();
        define_type_token.token_type = gso_token_type::gso_def_type_token;
        define_type_token.token_text = components[0].substring(4, components[0].size() - 1);;

        def_token.sub_tokens.add(define_type_token);

        // load vars

        for (int i = 2; i < components.size() - 1; i += 2) {
            gso_string_type variable_token_text = components[i] + " " + components[i + 1];

            gso_token variable_token = gso_token();
            variable_token.token_type = gso_token_type::gso_def_variable_token;
            variable_token.token_text = variable_token_text;

            gso_token variable_name_token = gso_token();
            variable_name_token.token_type = gso_token_type::gso_def_variable_name_token;
            variable_name_token.token_text = components[i].substring(0, components[i].size() - 1);
            variable_token.sub_tokens.add(variable_name_token);

            gso_token variable_value_token = gso_token();
            variable_value_token.token_type = gso_token_type::gso_def_variable_value_token;
            variable_value_token.token_text = components[i + 1];
            variable_token.sub_tokens.add(variable_value_token);

            def_token.sub_tokens.add(variable_token);
        }

        return def_token;
    }
    gso_token gso_load_var_token(gso_token var_token) {
        gso_vector_type<gso_string_type> components = gso_utils::gso_get_components(var_token.token_text);
        
        gso_token variable_type_token = gso_token();
        variable_type_token.token_type = gso_token_type::gso_var_type_token;
        variable_type_token.token_text = components[0].substring(4, components[0].size() - 1);
        var_token.sub_tokens.add(variable_type_token);
        
        gso_token variable_name_token = gso_token();
        variable_name_token.token_type = gso_token_type::gso_var_name_token;
        variable_type_token.token_text = components[2];

        gso_string_type variable_data_token_text = gso_string_type();

        for (int i = 4; i < components.size(); i++) {
            variable_data_token_text += components[i] + ' ';
        }

        gso_token variable_data_token = gso_token();
        variable_data_token.token_type = gso_token_type::gso_var_data_token;
        variable_data_token.token_text = variable_data_token_text;

        std::cout << variable_data_token_text << "\n";

        return var_token;
    }
}

void set_file_path(gso_string_type file_path) {
    gso_vector_type<gso_string_type> file_components = gso_utils::gso_split(file_path, '/');
    file_path = "";
    for (int i = 0; i < file_components.size() - 1; i++) {
        file_path += file_components[i] + '/';
    }
    gso_loader_data::set_file_path(file_path);
}
gso_object gso_read_from_file(gso_string_type path) {
    set_file_path(path);

    gso_object new_object = gso_object();

    gso_file_type gso_file = gso_file_data(path);
    gso_string_type gso_string_type_to_read = gso_file;

    gso_string_type_to_read = gso_steps::gso_remove_comments(gso_string_type_to_read);
    gso_string_type_to_read = gso_steps::gso_remove_dead_lines(gso_string_type_to_read);
    gso_string_type_to_read = gso_steps::gso_remove_lines(gso_string_type_to_read);

    gso_vector_type<gso_token> gso_token_tree = gso_steps::gso_get_token_tree(gso_string_type_to_read);

    for (int i = 0; i < gso_token_tree.size(); i++) {
        if (gso_token_tree[i].token_type == gso_token_type::gso_def_token)
            gso_token_tree[i] = gso_token_loaders::gso_load_def_token(gso_token_tree[i]);
    }

    gso_token main_token = gso_token();
    gso_header header_class = gso_header();
    
    main_token.token_text = gso_string_type_to_read;
    main_token.token_type = gso_token_type::gso_master_token;

    for (int i = 0; i < gso_token_tree.size(); i++) {
        main_token.sub_tokens.add(gso_token_tree[i]);
        if (gso_token_tree[i].sub_tokens[0].token_text == "header")
            header_class.Read(gso_token_tree[i]);
    }

    new_object.token = main_token;
    new_object.header = header_class;

    gso_set_version(new_object.header.version);
    new_object = gso_load(new_object);

    return new_object;
}

void gso_write_to_file(gso_object file, gso_string_type path) {

}