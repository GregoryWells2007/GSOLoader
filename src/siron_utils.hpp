#pragma once

#include "siron_types/siron_vector_type.hpp"
#include "siron_types/siron_string_type.hpp"
#include "siron_types/siron_token.hpp"

#include "math.h"

namespace siron_utils {
    siron_vector_type<siron_string_type> siron_split(siron_string_type text, char value) {
        siron_vector_type<siron_string_type> lines = {};
        siron_string_type current_string;
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

    siron_vector_type<siron_string_type> siron_get_lines(siron_string_type text) {
        return siron_split(text, '\n');
    }
    siron_vector_type<siron_string_type> siron_get_components(siron_string_type text) {
        siron_vector_type<siron_string_type> components = {};
        siron_string_type currentString = "";

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

    siron_string_type siron_convert_float_to_string(float value) {
        char* buffer = new char[64];
        int ret = snprintf(buffer, sizeof(buffer), "%f", value);
        return siron_string_type(buffer);
    }

    siron_string_type siron_convert_int_to_string(int value) {
        char* buffer = new char[64];
        int ret = snprintf(buffer, sizeof(buffer), "%d", value);
        return siron_string_type(buffer);
    }

    siron_string_type siron_convert_double_to_string(double value) {
        char* buffer = new char[64];
        int ret = snprintf(buffer, sizeof(buffer), "%lf", value);
        return siron_string_type(buffer);
    }

    int siron_convert_string_to_int(siron_string_type text) {
        int value;
        char* array = text;
        sscanf(array, "%d", &value);
        return value;
    }
    float siron_convert_string_to_float(siron_string_type text) {
        float value;
        char* array = text;
        sscanf(array, "%f", &value);
        return value;
    }
    double siron_convert_string_to_double(siron_string_type text) {
        double value;
        char* array = text;
        sscanf(array, "%lf", &value);
        return value;
    }
}
