#pragma once
#define nullptr 0

// idk i wrote this but I dont currently use it cuz I dont have much of a use for it
#define loop_list(var_name, list) for (int var_name = 0; var_name < siron_linked_list_size(list); var_name++)


typedef struct siron_linked_list {
    void* data;
    struct siron_linked_list* next;
} siron_linked_list;

siron_linked_list* siron_linked_list_create_empty() {
    siron_linked_list* list = malloc(sizeof(siron_linked_list));
    list->data = nullptr;
    list->next = nullptr;
    return list;
}

siron_linked_list* siron_linked_list_create(void* data) {
    siron_linked_list* list = malloc(sizeof(siron_linked_list));
    list->data = data;
    list->next = NULL;
    return list;
}

void siron_linked_list_add(siron_linked_list* list, void* data) {
    while (list->next != NULL)
        list = list->next;

    siron_linked_list* next_node = malloc(sizeof(siron_linked_list));
    next_node->data = data;
    next_node->next = 0;
    list->next = next_node;
}

void* siron_linked_list_get(siron_linked_list* list, int index) {

    while (index > 0) {
        list = list->next;
        index--;
    }

    return list->data;
}

int siron_linked_list_size(siron_linked_list* list) {
    int total = 0;
    if (list->data != NULL)
        total++;

    if (list->next != 0)
        total += siron_linked_list_size(list->next);
    return total;
}

void siron_linked_list_set(siron_linked_list* list, int index, void* data) {
    while (index > 0) {
        list->next = list->next;
        index--;
    }
    list->data = data;
}

void siron_linked_list_remove_at(siron_linked_list* list, int index) {
    if (index == 0) {
        if (list->next == NULL)
            free(list);
        else
            list = list->next;
    } {
        siron_linked_list_remove_at(list->next, index - 1);
    }
}

void siron_linked_list_insert(siron_linked_list* list, int index, void* data) {
    if (index == 0) {
        siron_linked_list* new_list_item = malloc(sizeof(siron_linked_list));
        new_list_item->data = data;
        new_list_item->next = list->next;
        list->next = new_list_item;
    } else {
        siron_linked_list_insert(list->next, index - 1, data);
    }
}

// frees the entired stack
void siron_linked_list_delete(siron_linked_list* list) {
    if (list->next != NULL)
        siron_linked_list_delete(list->next);
    free(list);
}
