#pragma once

#include "../gso_var.h"
#include "../../gso_types/gso_tuple_type.h"
#include "../../gso_utils.h"

class gso_float : public gso_var {
private:
    gso_tuple_type<float, float, float, float> values = { 0.0f, 0.0f, 0.0f, 0.0f };
    int float_count = 0;
public:
    operator float()                                      { return tuple_get<0>(values); }
    operator gso_tuple_type<float>()                      { return gso_tuple_type<float>(tuple_get<0>(values)); }
    operator gso_tuple_type<float, float>()               { return gso_tuple_type<float, float>(tuple_get<0>(values), tuple_get<1>(values)); }
    operator gso_tuple_type<float, float, float>()        { return gso_tuple_type<float, float, float>(tuple_get<0>(values), tuple_get<1>(values), tuple_get<2>(values)); }
    operator gso_tuple_type<float, float, float, float>() { return values; }

    int get_count() { return float_count; }

    void set_data(float val) { 
        tuple_get<0>(values) = val; 
        float_count = 1; 
    };
    void set_data(float val, float val2) { 
        tuple_get<0>(values) = val; 
        tuple_get<1>(values) = val2; 
        float_count = 2; 
    };
    void set_data(float val, float val2, float val3) { 
        tuple_get<0>(values) = val;
        tuple_get<1>(values) = val2; 
        tuple_get<2>(values) = val3; 
        float_count = 3;
    };
    void set_data(float val, float val2, float val3, float val4) { 
        tuple_get<0>(values) = val;
        tuple_get<1>(values) = val2; 
        tuple_get<2>(values) = val3; 
        tuple_get<3>(values) = val4; 
        float_count = 4;
    };
public:
    virtual void ReadData(gso_token token) override {
        float_count = token.get_subtoken(2).sub_tokens.size();
        tuple_get<0>(values) = gso_utils::gso_convert_string_to_float(token.get_subtoken(2).get_subtoken(0).token_text);
        if (float_count > 1)
            tuple_get<1>(values) = gso_utils::gso_convert_string_to_float(token.get_subtoken(2).get_subtoken(1).token_text);
        if (float_count > 2)
            tuple_get<2>(values) = gso_utils::gso_convert_string_to_float(token.get_subtoken(2).get_subtoken(2).token_text);
        if (float_count > 3)
            tuple_get<3>(values) = gso_utils::gso_convert_string_to_float(token.get_subtoken(2).get_subtoken(3).token_text);
    };
    virtual gso_var_data WriteData() override { 
        gso_var_data data = gso_var_data();
        data.variable_type = "float";
        if (float_count > 1)
            data.variable_type += gso_utils::gso_convert_int_to_string(float_count);

        data.items.add(gso_utils::gso_convert_float_to_string(tuple_get<0>(values)));
        if (float_count > 1)
            data.items.add(gso_utils::gso_convert_float_to_string(tuple_get<1>(values)));
        if (float_count > 2)
            data.items.add(gso_utils::gso_convert_float_to_string(tuple_get<2>(values)));
        if (float_count > 3)
            data.items.add(gso_utils::gso_convert_float_to_string(tuple_get<3>(values)));

        return data; 
    }
public:
    virtual gso_string_type to_string() override {
        if (float_count == 1) {
            return gso_utils::gso_convert_float_to_string(tuple_get<0>(values));
        } else {
            gso_string_type return_value = "(";

            if (float_count == 2) {
                return_value += gso_utils::gso_convert_float_to_string(tuple_get<0>(values)) + ", ";
                return_value += gso_utils::gso_convert_float_to_string(tuple_get<1>(values));
            }
            if (float_count == 3) {
                return_value += gso_utils::gso_convert_float_to_string(tuple_get<0>(values)) + ", ";
                return_value += gso_utils::gso_convert_float_to_string(tuple_get<1>(values)) + ", ";
                return_value += gso_utils::gso_convert_float_to_string(tuple_get<2>(values));
            }
            if (float_count == 4) {
                return_value += gso_utils::gso_convert_float_to_string(tuple_get<0>(values)) + ", ";
                return_value += gso_utils::gso_convert_float_to_string(tuple_get<1>(values)) + ", ";
                return_value += gso_utils::gso_convert_float_to_string(tuple_get<2>(values)) + ", ";
                return_value += gso_utils::gso_convert_float_to_string(tuple_get<3>(values));
            }

            return_value += ")";
            return return_value;
        }
    };
};