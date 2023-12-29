#pragma once
#include "string.h"

#include <stdbool.h>

#include "types/siron_linked_list.h"

char* siron_addchar(char* str1, char str2) {
    char* final = (char*)malloc((strlen(str1) + 2) * sizeof(char));
    strcpy(final, str1);
    final[strlen(str1)] = str2;
    final[strlen(str1) + 1] = '\0';
    return final;
}

char* siron_addstring(char* str1, char* str2) {
    size_t size_of_arr = strlen(str1) + strlen(str2) + 1;

    char* final = (char*)malloc(size_of_arr * sizeof(char));
    strcpy(final, str1);
    strcat(final, str2);
    final[size_of_arr - 1] = '\0';
    return final;
}


int siron_find_in_string(char* str, char value) {
    char *quotPtr = strchr(str, value);
    int position = quotPtr - str;
    return position;
}

bool siron_string_equal(char* str1, char* str2) { return strcmp(str1, str2) == 0; }

// char* siron_substring(char* str, int start, int end) {

//     printf("\n\n\nTaking a substring with the start of: %i, and the end of, %i\n", start, end);
//     int total_size = (end - start) + 1;

//     char* new_string = malloc(sizeof(char) * total_size);
//     for (int i = 0; i < (total_size - 1); i++)
//         new_string[i] = 'a';
//     new_string[(total_size - 1)] = '\0';

//     printf("The total size of the char array is: %i\n", total_size);
//     printf("The returned string is: %s\n", new_string);
    
//     printf("\n\n\n\n");
//     return new_string;
// }

char* siron_substring(char* str, int start, int end) {
    char* new_string = malloc(sizeof(char) * ((end - start) + 1));
    for (int i = start; i < end; i++)
        new_string[i - start] = str[i];
    new_string[strlen(new_string)] = '\0';
    return new_string;
}

siron_linked_list* siron_splitstring(char* str, char split) {

    bool first = true;
    siron_linked_list* linked_list;

    char* current = "";

    int sizeof_str = strlen(str);


    for (int i = 0; i < sizeof_str; i++) {
        if (str[i] == split) {
            if (strlen(current) > 0) {
                if (first == true) {
                    linked_list = siron_linked_list_create((void*)current);
                    first = false;
                }
                else
                    siron_linked_list_add(linked_list, (void*)current);
                current = "\0";
            }
        } else {
            current = siron_addchar(current, str[i]);
        }
    }

    if (str[strlen(str) - 1] != split)
        siron_linked_list_add(linked_list, current);

    return linked_list;
}

int siron_convert_string_to_int(char* text) {
    int value;
    sscanf(text, "%d", &value);
    return value;
}
float siron_convert_string_to_float(char* text) {
    float value;
    sscanf(text, "%f", &value);
    return value;
}
double siron_convert_string_to_double(char* text) {
    double value;
    sscanf(text, "%lf", &value);
    return value;
}