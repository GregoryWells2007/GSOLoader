#pragma once

#include "../siron_var.hpp"
#include "../../siron_types/siron_tuple_type.hpp"
#include "../../siron_utils.hpp"

class siron_int : public siron_var {
private:
    siron_tuple_type<int, int, int, int> values = { 0, 0, 0, 0 };
    int int_count = 0;
public:
    operator int()                                { return tuple_get<0>(values); }
    operator siron_tuple_type<int>()                { return siron_tuple_type<int>(tuple_get<0>(values)); }
    operator siron_tuple_type<int, int>()           { return siron_tuple_type<int, int>(tuple_get<0>(values), tuple_get<1>(values)); }
    operator siron_tuple_type<int, int, int>()      { return siron_tuple_type<int, int, int>(tuple_get<0>(values), tuple_get<1>(values), tuple_get<2>(values)); }
    operator siron_tuple_type<int, int, int, int>() { return values; }

    int get_count() { return int_count; };

    void set_data(int val) { 
        tuple_get<0>(values) = val; 
        int_count = 1; 
    };
    void set_data(int val, int val2) { 
        tuple_get<0>(values) = val;
        tuple_get<1>(values) = val2; 
        int_count = 2; 
    };
    void set_data(int val, int val2, int val3) { 
        tuple_get<0>(values) = val; 
        tuple_get<1>(values) = val2; 
        tuple_get<2>(values) = val3; 
        int_count = 3;
    };
    void set_data(int val, int val2, int val3, int val4) { 
        tuple_get<0>(values) = val; 
        tuple_get<1>(values) = val2; 
        tuple_get<2>(values) = val3; 
        tuple_get<3>(values) = val4; 
        int_count = 4;
    };
public:
    virtual void ReadData(siron_token token) override {
        int_count = token.get_subtoken(2).sub_tokens.size();
        tuple_get<0>(values) = siron_utils::siron_convert_string_to_int(token.get_subtoken(2).get_subtoken(0).token_text);
        if (int_count > 1)
            tuple_get<1>(values) = siron_utils::siron_convert_string_to_int(token.get_subtoken(2).get_subtoken(1).token_text);
        if (int_count > 2)
            tuple_get<2>(values) = siron_utils::siron_convert_string_to_int(token.get_subtoken(2).get_subtoken(2).token_text);
        if (int_count > 3)
            tuple_get<3>(values) = siron_utils::siron_convert_string_to_int(token.get_subtoken(2).get_subtoken(3).token_text);
    };
    virtual siron_var_data WriteData() override { 
        siron_var_data data = siron_var_data();
        data.variable_type = "int";
        if (int_count > 1)
            data.variable_type += siron_utils::siron_convert_int_to_string(int_count);

        data.items.add(siron_utils::siron_convert_int_to_string(tuple_get<0>(values)));
        if (int_count > 1)
            data.items.add(siron_utils::siron_convert_int_to_string(tuple_get<1>(values)));
        if (int_count > 2)
            data.items.add(siron_utils::siron_convert_int_to_string(tuple_get<2>(values)));
        if (int_count > 3)
            data.items.add(siron_utils::siron_convert_int_to_string(tuple_get<3>(values)));

        return data; 
    }
public:
    virtual siron_string_type to_string() override {
        if (int_count == 1) {
            return siron_utils::siron_convert_int_to_string(tuple_get<0>(values));
        } else {
            siron_string_type return_value = "(";

            if (int_count == 2) {
                return_value += siron_utils::siron_convert_int_to_string(tuple_get<0>(values)) + ", ";
                return_value += siron_utils::siron_convert_int_to_string(tuple_get<1>(values));
            }
            if (int_count == 3) {
                return_value += siron_utils::siron_convert_int_to_string(tuple_get<0>(values)) + ", ";
                return_value += siron_utils::siron_convert_int_to_string(tuple_get<1>(values)) + ", ";
                return_value += siron_utils::siron_convert_int_to_string(tuple_get<2>(values));
            }
            if (int_count == 4) {
                return_value += siron_utils::siron_convert_int_to_string(tuple_get<0>(values)) + ", ";
                return_value += siron_utils::siron_convert_int_to_string(tuple_get<1>(values)) + ", ";
                return_value += siron_utils::siron_convert_int_to_string(tuple_get<2>(values)) + ", ";
                return_value += siron_utils::siron_convert_int_to_string(tuple_get<3>(values));
            }

            return_value += ")";
            return return_value;
        }
    };
};