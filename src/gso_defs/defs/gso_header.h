#pragma once

#include "../../gso_utils.h"

#include "../gso_def.h"
#include "../../gso_types/gso_vector_type.h"
#include "../../gso_types/gso_token.h"

struct gso_header : public gso_def {
public:
    float version = 0.0f;
public:
    virtual void Read(gso_token token) override {
        version = gso_utils::gso_convert_string_to_float(token.sub_tokens[1].sub_tokens[1].token_text);
    }

    // this funciton will need to be redone
    virtual gso_token Write() override {
        return gso_token();
    }
};