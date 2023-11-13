#pragma once

#include "gso_types/gso_vector_type.h"
#include "gso_types/gso_string_type.h"
#include "gso_types/gso_token.h"

#include "math.h"

namespace gso_utils {
    gso_vector_type<gso_string_type> gso_split(gso_string_type text, char value) {
        gso_vector_type<gso_string_type> lines = {};
        gso_string_type current_string;
        for (int i = 0; i < text.size(); i++) {
            if (text[i] == value) {
                lines.add(current_string);
                current_string = "";
            } else
                current_string += text[i];
        }
        lines.add(current_string);
        return lines;
    }

    gso_vector_type<gso_string_type> gso_get_lines(gso_string_type text) {
        return gso_split(text, '\n');
    }
    gso_vector_type<gso_string_type> gso_get_components(gso_string_type text) {
        gso_vector_type<gso_string_type> components = {};
        gso_string_type currentString = "";

        bool in_string = false;

        for (int i = 0; i < text.size(); i++) {
            if (text[i] == '"')
                in_string = !in_string;


            if (text[i] == ' ' && !in_string) {
                if (currentString.size() > 0) {
                    components.add(currentString);
                    currentString = "";
                }
            }
            else {
                char currentchar = text[i];
                currentString += currentchar;
            }
        }
        if (currentString.size() > 0)
            components.add(currentString);
        return components;
    } 

    gso_string_type gso_convert_float_to_string(float value) {
        char* buffer = new char[64];
        int ret = snprintf(buffer, sizeof(buffer), "%f", value);
        return gso_string_type(buffer);
    }

    gso_string_type gso_convert_int_to_string(int value) {
        char* buffer = new char[64];
        int ret = snprintf(buffer, sizeof(buffer), "%d", value);
        return gso_string_type(buffer);
    }

    gso_string_type gso_convert_double_to_string(double value) {
        char* buffer = new char[64];
        int ret = snprintf(buffer, sizeof(buffer), "%lf", value);
        return gso_string_type(buffer);
    }

    int gso_convert_string_to_int(gso_string_type text) {
        int value;
        char* array = text;
        sscanf(array, "%d", &value);
        return value;
    }
    float gso_convert_string_to_float(gso_string_type text) {
        float value;
        char* array = text;
        sscanf(array, "%f", &value);
        return value;
    }
    double gso_convert_string_to_double(gso_string_type text) {
        double value;
        char* array = text;
        sscanf(array, "%lf", &value);
        return value;
    }
}
