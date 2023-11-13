#pragma once

#include "../gso_var.h"
#include "../../gso_types/gso_tuple_type.h"
#include "../../gso_utils.h"

class gso_int : public gso_var {
private:
    gso_tuple_type<int, int, int, int> values = { 0, 0, 0, 0 };
    int int_count = 0;
public:
    operator int()                                { return values.get(0); }
    operator gso_tuple_type<int>()                { return gso_tuple_type<int>(values.get(0)); }
    operator gso_tuple_type<int, int>()           { return gso_tuple_type<int, int>(values.get(0), values.get(1)); }
    operator gso_tuple_type<int, int, int>()      { return gso_tuple_type<int, int, int>(values.get(0), values.get(1), values.get(2)); }
    operator gso_tuple_type<int, int, int, int>() { return values; }

    int get_count() { return int_count; };

    void set_data(int val) { 
        values.set(0, val); 
        int_count = 1; 
    };
    void set_data(int val, int val2) { 
        values.set(0, val); 
        values.set(1, val2); 
        int_count = 2; 
    };
    void set_data(int val, int val2, int val3) { 
        values.set(0, val); 
        values.set(1, val2); 
        values.set(2, val3); 
        int_count = 3;
    };
    void set_data(int val, int val2, int val3, int val4) { 
        values.set(0, val); 
        values.set(1, val2); 
        values.set(2, val3); 
        values.set(3, val4); 
        int_count = 4;
    };
public:
    virtual void ReadData(gso_token token) override {
        int_count = token.get_subtoken(2).sub_tokens.size();
        for (int i = 0; i < int_count; i++) {
            values.set(i, gso_utils::gso_convert_string_to_int(token.get_subtoken(2).get_subtoken(i).token_text));
        }
    };
    virtual gso_var_data WriteData() override { return gso_var_data(); }
};