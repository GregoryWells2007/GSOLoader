#pragma once

#include "siron_list_type.hpp"
#include "../../../siron_utils.hpp"

class siron_list_color : public siron_list_type {
public:
    union {
        struct {
            int red;
            int green;
            int blue;
            float alpha;
        };
        struct {
            int r;
            int g;
            int b;
            float a;
        };
    };
public:
    void set_data(int vr, int vg, int vb, float va) { red = vr; green = vg; blue = vb; alpha = va; }
    void set_data(int vall, float va) { r = vall; g = vall; b = vall; a = va; }

    void set_data(int vr, int vg, int vb) { red = vr; green = vg; blue = vb; alpha = 1.0f; }
    void set_data(int vall) { r = vall; g = vall; b = vall; a = 1.0f; }
public:
    virtual void Read(siron_token value) override {
        red = siron_utils::siron_convert_string_to_int(value.get_subtoken(0).token_text);
        green = siron_utils::siron_convert_string_to_int(value.get_subtoken(1).token_text);
        blue = siron_utils::siron_convert_string_to_int(value.get_subtoken(2).token_text);
        alpha = siron_utils::siron_convert_string_to_float(value.get_subtoken(3).token_text);
    }

    virtual siron_string_type Write() override {
        return to_string();
    }
public:
    virtual siron_string_type to_string() override {
        siron_string_type output = "(";
        output += siron_utils::siron_convert_int_to_string(red) + " ";
        output += siron_utils::siron_convert_int_to_string(green) + " ";
        output += siron_utils::siron_convert_int_to_string(blue) + " ";
        output += siron_utils::siron_convert_float_to_string(alpha);
        output += ")";
        return output;
    }
};