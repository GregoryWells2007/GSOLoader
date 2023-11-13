#pragma once

#include "../gso_var.h"
#include "../../gso_types/gso_tuple_type.h"
#include "../../gso_utils.h"

class gso_float : public gso_var {
private:
    gso_tuple_type<float, float, float, float> values = { 0.0f, 0.0f, 0.0f, 0.0f };
    int float_count = 0;
public:
    operator float()                                      { return values.get(0); }
    operator gso_tuple_type<float>()                      { return gso_tuple_type<float>(values.get(0)); }
    operator gso_tuple_type<float, float>()               { return gso_tuple_type<float, float>(values.get(0), values.get(1)); }
    operator gso_tuple_type<float, float, float>()        { return gso_tuple_type<float, float, float>(values.get(0), values.get(1), values.get(2)); }
    operator gso_tuple_type<float, float, float, float>() { return values; }

    int get_count() { return float_count; }

    void set_data(float val) { 
        values.set(0, val); 
        float_count = 1; 
    };
    void set_data(float val, float val2) { 
        values.set(0, val); 
        values.set(1, val2); 
        float_count = 2; 
    };
    void set_data(float val, float val2, float val3) { 
        values.set(0, val); 
        values.set(1, val2); 
        values.set(2, val3); 
        float_count = 3;
    };
    void set_data(float val, float val2, float val3, float val4) { 
        values.set(0, val); 
        values.set(1, val2); 
        values.set(2, val3); 
        values.set(3, val4); 
        float_count = 4;
    };
public:
    virtual void ReadData(gso_token token) override {
        float_count = token.get_subtoken(2).sub_tokens.size();
        for (int i = 0; i < float_count; i++) {
            values.set(i, gso_utils::gso_convert_string_to_float(token.get_subtoken(2).get_subtoken(i).token_text));
        }
    };
    virtual gso_var_data WriteData() override { return gso_var_data(); }
};