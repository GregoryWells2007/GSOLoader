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
    int gso_convert_string_to_int(gso_string_type text) {
        int output = 0;
        for (int c = 0; c < text.size(); c++)
            output += ((text[c] - '0') * pow(10, (text.size() - 1) - c));
        return output;
    }
    float gso_convert_string_to_float(gso_string_type text) {
        float output = 0;
        float decimal = 0;
        gso_string_type str1 = text.substring(0, text.find('.'));
        gso_string_type str2 = text.substring(text.find('.') + 1, text.size());
        for (int c = 0; c < str1.size(); c++)
            output += ((str1[c] - '0') * pow(10, (str1.size() - 1) - c));
        for (int c = 0; c < str2.size(); c++)
            decimal += ((str2[c] - '0') * pow(10, (str2.size() - 1) - c));
        decimal /= pow(10, str2.size());
        output += decimal;
        return output;
    }
    double gso_convert_string_to_double(gso_string_type text) {
        double output = 0;
        double decimal = 0;

        int decimal_pos = text.find('.');
        if (decimal_pos == -1) {
            for (int c = 0; c < text.size(); c++)
                output += ((text[c] - '0') * pow(10, (text.size() - 1) - c));
        } else {
            gso_string_type str1 = text.substring(0, decimal_pos);
            gso_string_type str2 = text.substring(decimal_pos + 1, text.size());

            for (int c = 0; c < str1.size(); c++)
                output += ((str1[c] - '0') * pow(10, (str1.size() - 1) - c));
            for (int c = 0; c < str2.size(); c++)
                decimal += ((str2[c] - '0') * pow(10, (str2.size() - 1) - c));
            decimal /= pow(10, str2.size());
            output += decimal;
        }
        return output;
    }
}