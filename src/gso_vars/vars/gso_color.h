#pragma once

#include "../gso_var.h"
#include "../../gso_utils.h"

class gso_color : public gso_var {
public:
    union 
    {
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
    virtual void ReadData(gso_token token) override { 
        red = gso_utils::gso_convert_string_to_int(token.get_subtoken(2).get_subtoken(0).token_text);
        green = gso_utils::gso_convert_string_to_int(token.get_subtoken(2).get_subtoken(1).token_text);
        blue = gso_utils::gso_convert_string_to_int(token.get_subtoken(2).get_subtoken(2).token_text);
        alpha = gso_utils::gso_convert_string_to_float(token.get_subtoken(2).get_subtoken(3).token_text);
    };
    virtual gso_var_data WriteData() override { 
        gso_var_data data = gso_var_data();
        data.variable_type = "color";

        data.items.add(gso_utils::gso_convert_int_to_string(r));
        data.items.add(gso_utils::gso_convert_int_to_string(g));
        data.items.add(gso_utils::gso_convert_int_to_string(b));
        data.items.add(gso_utils::gso_convert_float_to_string(a));

        return data; 
    }
};