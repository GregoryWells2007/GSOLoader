#pragma once

#include "initial_loader/gso_token_loaders.h"
#include "initial_loader/gso_steps.h"

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