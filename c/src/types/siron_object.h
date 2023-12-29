#pragma once
#include "siron_token.h"
#include "../siron_defs.h"

typedef struct siron_object {
    siron_token main_token;
    siron_header header;
} siron_object;

siron_object siron_create_object() {
    siron_object object = {};
    return object;
}

void siron_object_set_header(siron_object* object, siron_header header) { object->header = header; }