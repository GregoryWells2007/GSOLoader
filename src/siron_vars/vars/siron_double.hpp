#pragma once

#include "../siron_var.hpp"
#include "../../siron_types/siron_tuple_type.hpp"
#include "../../siron_utils.hpp"

class siron_double : public siron_var {
private:
    siron_tuple_type<double, double, double, double> values = { 0.0, 0.0, 0.0, 0.0 };
    int double_count = 0;
public:
    operator double()                                         { return tuple_get<0>(values); }
    operator siron_tuple_type<double>()                         { return siron_tuple_type<double>(tuple_get<0>(values)); }
    operator siron_tuple_type<double, double>()                 { return siron_tuple_type<double, double>(tuple_get<0>(values), tuple_get<1>(values)); }
    operator siron_tuple_type<double, double, double>()         { return siron_tuple_type<double, double, double>(tuple_get<0>(values), tuple_get<1>(values), tuple_get<2>(values)); }
    operator siron_tuple_type<double, double, double, double>() { return values; }

    int get_count() { return double_count; }
    void set_data(double val) { 
        tuple_get<0>(values) = val; 
        double_count = 1; 
    };
    void set_data(double val, double val2) { 
        tuple_get<0>(values) = val; 
        tuple_get<1>(values) = val2; 
        double_count = 2; 
    };
    void set_data(double val, double val2, double val3) { 
        tuple_get<0>(values) = val; 
        tuple_get<1>(values) = val2; 
        tuple_get<2>(values) = val3; 
        double_count = 3;
    };
    void set_data(double val, double val2, double val3, double val4) { 
        tuple_get<0>(values) = val; 
        tuple_get<1>(values) = val2; 
        tuple_get<2>(values) = val3; 
        tuple_get<3>(values) = val4; 
        double_count = 4;
    };
public:
    virtual void ReadData(siron_token token) override {
        double_count = token.get_subtoken(2).sub_tokens.size();
        tuple_get<0>(values) = siron_utils::siron_convert_string_to_double(token.get_subtoken(2).get_subtoken(0).token_text);
        if (double_count > 1)
            tuple_get<1>(values) = siron_utils::siron_convert_string_to_double(token.get_subtoken(2).get_subtoken(1).token_text);
        if (double_count > 2)
            tuple_get<2>(values) = siron_utils::siron_convert_string_to_double(token.get_subtoken(2).get_subtoken(2).token_text);
        if (double_count > 3)
            tuple_get<3>(values) = siron_utils::siron_convert_string_to_double(token.get_subtoken(2).get_subtoken(3).token_text);
    };
    virtual siron_var_data WriteData() override { 
        siron_var_data data = siron_var_data();
        data.variable_type = "double";
        if (double_count > 1)
            data.variable_type += siron_utils::siron_convert_int_to_string(double_count);

        data.items.add(siron_utils::siron_convert_double_to_string(tuple_get<0>(values)));
        if (double_count > 1)
            data.items.add(siron_utils::siron_convert_double_to_string(tuple_get<1>(values)));
        if (double_count > 2)
            data.items.add(siron_utils::siron_convert_double_to_string(tuple_get<2>(values)));
        if (double_count > 3)
            data.items.add(siron_utils::siron_convert_double_to_string(tuple_get<3>(values)));

        return data; 
    }
public:
    virtual siron_string_type to_string() override {
        if (double_count == 1) {
            return siron_utils::siron_convert_double_to_string(tuple_get<0>(values));
        } else {
            siron_string_type return_value = "(";

            if (double_count == 2) {
                return_value += siron_utils::siron_convert_double_to_string(tuple_get<0>(values)) + ", ";
                return_value += siron_utils::siron_convert_double_to_string(tuple_get<1>(values));
            }
            if (double_count == 3) {
                return_value += siron_utils::siron_convert_double_to_string(tuple_get<0>(values)) + ", ";
                return_value += siron_utils::siron_convert_double_to_string(tuple_get<1>(values)) + ", ";
                return_value += siron_utils::siron_convert_double_to_string(tuple_get<2>(values));
            }
            if (double_count == 4) {
                return_value += siron_utils::siron_convert_double_to_string(tuple_get<0>(values)) + ", ";
                return_value += siron_utils::siron_convert_double_to_string(tuple_get<1>(values)) + ", ";
                return_value += siron_utils::siron_convert_double_to_string(tuple_get<2>(values)) + ", ";
                return_value += siron_utils::siron_convert_double_to_string(tuple_get<3>(values));
            }

            return_value += ")";
            return return_value;
        }
    };
};