#pragma once

#include <cmath>
#include <stdexcept>
#include "TypeRedefinitions.h"
#include "StandardOperations.h"

static real_t inner_sd(real_set_t& rs) {
	real_t mean = Mean(rs);
	real_t sum = 0.0;
	for(auto d : rs) 
		sum += (d-mean)*(d-mean);
	return sum;    
}

real_t StandardDeviation(real_set_t& rs, const int sd_type) {
    real_t numer = inner_sd(rs);
	real_t denom = double(rs.size());

    if(sd_type == SD::population) {
        return std::sqrt(numer / denom);
    }
    else if(sd_type == SD::sample) {
        return std::sqrt(numer / (denom - 1.0));
    }
    else {
        throw std::runtime_error("StandardDeviation -> unknown deviation type");
    }
}
