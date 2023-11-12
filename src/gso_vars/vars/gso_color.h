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
    virtual void ReadData(gso_token token) override { 
        red = gso_utils::gso_convert_string_to_int(token.get_subtoken(2).get_subtoken(0).token_text);
        green = gso_utils::gso_convert_string_to_int(token.get_subtoken(2).get_subtoken(1).token_text);
        blue = gso_utils::gso_convert_string_to_int(token.get_subtoken(2).get_subtoken(2).token_text);
        alpha = gso_utils::gso_convert_string_to_float(token.get_subtoken(2).get_subtoken(3).token_text);
    };
    virtual gso_token WriteData() override { return gso_token(); }
};