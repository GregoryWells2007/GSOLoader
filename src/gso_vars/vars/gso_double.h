#pragma once

#include "../gso_var.h"
#include "../../gso_types/gso_tuple_type.h"
#include "../../gso_utils.h"

class gso_double : public gso_var {
private:
    gso_tuple_type<double, double, double, double> values = { 0.0, 0.0, 0.0, 0.0 };
    int double_count = 0;
public:
    operator double()                                         { return values.get(0); }
    operator gso_tuple_type<double>()                         { return gso_tuple_type<double>(values.get(0)); }
    operator gso_tuple_type<double, double>()                 { return gso_tuple_type<double, double>(values.get(0), values.get(1)); }
    operator gso_tuple_type<double, double, double>()         { return gso_tuple_type<double, double, double>(values.get(0), values.get(1), values.get(2)); }
    operator gso_tuple_type<double, double, double, double>() { return values; }

    int get_count() { return double_count; }
    void set_data(double val) { 
        values.set(0, val); 
        double_count = 1; 
    };
    void set_data(double val, double val2) { 
        values.set(0, val); 
        values.set(1, val2); 
        double_count = 2; 
    };
    void set_data(double val, double val2, double val3) { 
        values.set(0, val); 
        values.set(1, val2); 
        values.set(2, val3); 
         double_count = 3;
    };
    void set_data(double val, double val2, double val3, double val4) { 
        values.set(0, val); 
        values.set(1, val2); 
        values.set(2, val3); 
        values.set(3, val4); 
        double_count = 4;
    };
public:
    virtual void ReadData(gso_token token) override {
        double_count = token.get_subtoken(2).sub_tokens.size();
        for (int i = 0; i < double_count; i++) {
            values.set(i, gso_utils::gso_convert_string_to_double(token.get_subtoken(2).get_subtoken(i).token_text));
        }
    };
    virtual gso_var_data WriteData() override { return gso_var_data(); }
};