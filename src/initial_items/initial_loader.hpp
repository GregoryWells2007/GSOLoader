#pragma once

#include "initial_loader/siron_token_loaders.hpp"
#include "initial_loader/siron_steps.hpp"

void set_file_path(siron_string_type file_path) {
    siron_vector_type<siron_string_type> file_components = siron_utils::siron_split(file_path, '/');
    file_path = "";
    for (int i = 0; i < file_components.size() - 1; i++) {
        file_path += file_components[i] + '/';
    }
    siron_loader_data::set_file_path(file_path);
}
siron_object siron_read_from_file(siron_string_type path) {
    set_file_path(path);

    siron_object new_object = siron_object();

    siron_file_type siron_file = siron_file_data(path);
    siron_string_type siron_string_type_to_read = siron_file;

    siron_string_type_to_read = siron_steps::siron_remove_comments(siron_string_type_to_read);
    siron_string_type_to_read = siron_steps::siron_remove_dead_lines(siron_string_type_to_read);
    siron_string_type_to_read = siron_steps::siron_remove_lines(siron_string_type_to_read);

    siron_vector_type<siron_token> siron_token_tree = siron_steps::siron_get_token_tree(siron_string_type_to_read);

    for (int i = 0; i < siron_token_tree.size(); i++) {
        if (siron_token_tree[i].token_type == siron_token_type::siron_def_token)
            siron_token_tree[i] = siron_token_loaders::siron_load_def_token(siron_token_tree[i]);
    }

    siron_token main_token = siron_token();
    siron_header header_class = siron_header();
    
    main_token.token_text = siron_string_type_to_read;
    main_token.token_type = siron_token_type::siron_master_token;

    for (int i = 0; i < siron_token_tree.size(); i++) {
        main_token.sub_tokens.add(siron_token_tree[i]);
        if (siron_token_tree[i].sub_tokens[0].token_text == "header")
            header_class.Read(siron_token_tree[i]);
    }

    new_object.token = main_token;
    new_object.header = header_class;

    siron_set_version(new_object.header.version);
    new_object = siron_load(new_object);

    return new_object;
}