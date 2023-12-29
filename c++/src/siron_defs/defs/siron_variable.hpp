#pragma once

#include "../../siron_utils.hpp"

#include "../siron_def.hpp"
#include "../../siron_types/siron_vector_type.hpp"
#include "../../siron_types/siron_token.hpp"

//  siron_def_token
//      siron_def_type_token
//      siron_def_variables_token
//          siron_def_variable_token
//              siron_def_variable_name_token
//              siron_def_variable_value_token

struct siron_variable : public siron_def {
public:
    
public:
    virtual void Read(siron_token token) override {
        
    }

    // this funciton will need to be redone
    virtual siron_def_data Write() override {
        siron_def_data data;
        data.define_type = "variable";

        

        return data;
    }
};