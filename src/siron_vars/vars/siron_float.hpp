#pragma once

#include "../siron_var.hpp"
#include "../../siron_types/siron_tuple_type.hpp"
#include "../../siron_utils.hpp"

class siron_float : public siron_var {
private:
    siron_tuple_type<float, float, float, float> values = { 0.0f, 0.0f, 0.0f, 0.0f };
    int float_count = 0;
public:
    operator float()                                      { return tuple_get<0>(values); }
    operator siron_tuple_type<float>()                      { return siron_tuple_type<float>(tuple_get<0>(values)); }
    operator siron_tuple_type<float, float>()               { return siron_tuple_type<float, float>(tuple_get<0>(values), tuple_get<1>(values)); }
    operator siron_tuple_type<float, float, float>()        { return siron_tuple_type<float, float, float>(tuple_get<0>(values), tuple_get<1>(values), tuple_get<2>(values)); }
    operator siron_tuple_type<float, float, float, float>() { return values; }

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
    virtual void ReadData(siron_token token) override {
        float_count = token.get_subtoken(2).sub_tokens.size();
        tuple_get<0>(values) = siron_utils::siron_convert_string_to_float(token.get_subtoken(2).get_subtoken(0).token_text);
        if (float_count > 1)
            tuple_get<1>(values) = siron_utils::siron_convert_string_to_float(token.get_subtoken(2).get_subtoken(1).token_text);
        if (float_count > 2)
            tuple_get<2>(values) = siron_utils::siron_convert_string_to_float(token.get_subtoken(2).get_subtoken(2).token_text);
        if (float_count > 3)
            tuple_get<3>(values) = siron_utils::siron_convert_string_to_float(token.get_subtoken(2).get_subtoken(3).token_text);
    };
    virtual siron_var_data WriteData() override { 
        siron_var_data data = siron_var_data();
        data.variable_type = "float";
        if (float_count > 1)
            data.variable_type += siron_utils::siron_convert_int_to_string(float_count);

        data.items.add(siron_utils::siron_convert_float_to_string(tuple_get<0>(values)));
        if (float_count > 1)
            data.items.add(siron_utils::siron_convert_float_to_string(tuple_get<1>(values)));
        if (float_count > 2)
            data.items.add(siron_utils::siron_convert_float_to_string(tuple_get<2>(values)));
        if (float_count > 3)
            data.items.add(siron_utils::siron_convert_float_to_string(tuple_get<3>(values)));

        return data; 
    }
public:
    virtual siron_string_type to_string() override {
        if (float_count == 1) {
            return siron_utils::siron_convert_float_to_string(tuple_get<0>(values));
        } else {
            siron_string_type return_value = "(";

            if (float_count == 2) {
                return_value += siron_utils::siron_convert_float_to_string(tuple_get<0>(values)) + ", ";
                return_value += siron_utils::siron_convert_float_to_string(tuple_get<1>(values));
            }
            if (float_count == 3) {
                return_value += siron_utils::siron_convert_float_to_string(tuple_get<0>(values)) + ", ";
                return_value += siron_utils::siron_convert_float_to_string(tuple_get<1>(values)) + ", ";
                return_value += siron_utils::siron_convert_float_to_string(tuple_get<2>(values));
            }
            if (float_count == 4) {
                return_value += siron_utils::siron_convert_float_to_string(tuple_get<0>(values)) + ", ";
                return_value += siron_utils::siron_convert_float_to_string(tuple_get<1>(values)) + ", ";
                return_value += siron_utils::siron_convert_float_to_string(tuple_get<2>(values)) + ", ";
                return_value += siron_utils::siron_convert_float_to_string(tuple_get<3>(values));
            }

            return_value += ")";
            return return_value;
        }
    };
};