#pragma one

#include "steps/siron_create_header.h"

#include "types/siron_object.h"
#include "siron_defs.h"

siron_object siron_read_file(char* path) {
    siron_object siron_object = siron_create_object();

    char* header_data = "def<header> { version: 1.0 }";


    siron_token header_token = siron_create_header_token(header_data);
    siron_header header_object = siron_create_header(header_token);

    siron_object_set_header(&siron_object, header_object);
    printf("Loading a version %f siron file\n", header_object.version);


    //free(header_data);
    return siron_object;
}