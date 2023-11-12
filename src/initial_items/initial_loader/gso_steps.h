#pragma once

#include "../../gso_utils.h"

#include "../../gso_object.h"
#include "../../gso_defs/gso_def.h"
#include "../../gso_defs/defs/gso_header.h"
#include "../../gso_types/gso_vector_type.h"
#include "../../gso_types/gso_string_type.h"
#include "../../gso_types/gso_tuple_type.h"
#include "../../gso_types/gso_token.h"

#include "../../gso_file_reader.h"

// version loaders
#include "../../gso_version_loaders/gso_current_loader.h"

#include "../../gso_loader_data.h"

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