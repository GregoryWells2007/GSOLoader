#pragma once

#include "gso_list_type.h"
#include "../../../gso_utils.h"

class gso_list_color : public gso_list_type {
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
    virtual void Read(gso_token value) override {
        red = gso_utils::gso_convert_string_to_int(value.get_subtoken(0).token_text);
        green = gso_utils::gso_convert_string_to_int(value.get_subtoken(1).token_text);
        blue = gso_utils::gso_convert_string_to_int(value.get_subtoken(2).token_text);
        alpha = gso_utils::gso_convert_string_to_float(value.get_subtoken(3).token_text);
    }
};