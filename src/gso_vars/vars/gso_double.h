#pragma once

#include "../gso_var.h"
#include "../../gso_types/gso_tuple_type.h"
#include "../../gso_utils.h"

class gso_double : public gso_var {
private:
    gso_tuple_type<double, double, double, double> values = { 0.0, 0.0, 0.0, 0.0 };
public:
    operator double()                                         { return values.get(0); }
    operator gso_tuple_type<double>()                         { return gso_tuple_type<double>(values.get(0)); }
    operator gso_tuple_type<double, double>()                 { return gso_tuple_type<double, double>(values.get(0), values.get(1)); }
    operator gso_tuple_type<double, double, double>()         { return gso_tuple_type<double, double, double>(values.get(0), values.get(1), values.get(2)); }
    operator gso_tuple_type<double, double, double, double>() { return values; }
public:
    virtual void ReadData(gso_token token) override {
        int size_of_double = token.get_subtoken(2).sub_tokens.size();
        for (int i = 0; i < size_of_double; i++) {
            values.set(i, gso_utils::gso_convert_string_to_double(token.get_subtoken(2).get_subtoken(i).token_text));
        }
    };
    virtual gso_token WriteData() override { return gso_token(); }
};