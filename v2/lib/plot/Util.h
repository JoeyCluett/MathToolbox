#pragma once

#include "../TypeRedefinitions.h"

real_t map_real(
        real_t input,
        real_t input_start,  real_t input_end,
        real_t output_start, real_t output_end) {

    return output_start 
            + ((output_end - output_start) 
            / (input_end - input_start)) 
            * (input - input_start);
}

