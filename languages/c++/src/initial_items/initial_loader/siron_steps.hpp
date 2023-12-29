#pragma once

#include "../../siron_utils.hpp"

#include "../../siron_object.hpp"
#include "../../siron_defs/siron_def.hpp"
#include "../../siron_defs/defs/siron_header.hpp"
#include "../../siron_types/siron_vector_type.hpp"
#include "../../siron_types/siron_string_type.hpp"
#include "../../siron_types/siron_tuple_type.hpp"
#include "../../siron_types/siron_token.hpp"

#include "../../siron_file_reader.hpp"

// version loaders
#include "../../siron_version_loaders/siron_current_loader.hpp"

#include "../../siron_loader_data.hpp"

namespace siron_steps {
    siron_string_type siron_remove_comments(siron_string_type text) {
        siron_vector_type<siron_string_type> lines = siron_utils::siron_get_lines(text);

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

        siron_string_type final_pass;
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
    siron_string_type siron_remove_dead_lines(siron_string_type text) {
        siron_vector_type<siron_string_type> lines = siron_utils::siron_get_lines(text);
        siron_string_type final_text;
        for (int i = 0; i < lines.size(); i++) {
            if (lines[i].size() > 0) {
                final_text += lines[i];
                final_text += "\n";
            }
        }
        return final_text;
    }
    siron_string_type siron_remove_lines(siron_string_type text) {
        siron_vector_type<siron_string_type> lines = siron_utils::siron_get_lines(text);
        siron_string_type output = "";
        for (int i = 0; i < lines.size(); i++) {
            siron_vector_type<siron_string_type> components = siron_utils::siron_get_components(lines[i]);
            for (int c = 0; c < components.size(); c++) {
                output += components[c];
                output += ' ';
            }
        }
        return output;
    }
    siron_vector_type<siron_token> siron_get_token_tree(siron_string_type text) {
        siron_vector_type<siron_token> tokens = {};

        siron_token current_token = siron_token();
        siron_string_type token_text = "";

        bool loading_token = false;
        int cbrackers_index = 0;

        siron_vector_type<siron_string_type> components = siron_utils::siron_get_components(text);
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
                        current_token = siron_token();
                    }
                }  
            } else {
                if (components[i].find("def") != -1) {
                    current_token.token_type = siron_token_type::siron_def_token;
                    loading_token = true;
                    cbrackers_index = 0;
                    token_text = components[i];
                }
            }
        }
        return tokens;
    }
}