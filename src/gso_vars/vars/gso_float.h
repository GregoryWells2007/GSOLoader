#pragma once

#include "../gso_var.h"
#include "../../gso_types/gso_tuple_type.h"
#include "../../gso_utils.h"

class gso_float : public gso_var {
private:
    gso_tuple_type<float, float, float, float> values = { 0.0f, 0.0f, 0.0f, 0.0f };
public:
    operator float()                                      { return values.get(0); }
    operator gso_tuple_type<float>()                      { return gso_tuple_type<float>(values.get(0)); }
    operator gso_tuple_type<float, float>()               { return gso_tuple_type<float, float>(values.get(0), values.get(1)); }
    operator gso_tuple_type<float, float, float>()        { return gso_tuple_type<float, float, float>(values.get(0), values.get(1), values.get(2)); }
    operator gso_tuple_type<float, float, float, float>() { return values; }
public:
    virtual void ReadData(gso_token token) override {
        int size_of_float = token.get_subtoken(2).sub_tokens.size();
        for (int i = 0; i < size_of_float; i++) {
            values.set(i, gso_utils::gso_convert_string_to_float(token.get_subtoken(2).get_subtoken(i).token_text));
        }
    };
    virtual gso_token WriteData() override { return gso_token(); }
};