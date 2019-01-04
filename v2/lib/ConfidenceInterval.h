#pragma once

#include <cmath>
#include "TypeRedefinitions.h"
#include "StandardDeviation.h"

auto ConfidenceInterval(
        real_set_t& ds,  
        real_t std_deviation, 
        real_t mean, 
        real_t z) 
            -> confidence_interval_t {

	z *= std_deviation; // dont need std_dev after this anyway
	z /= sqrt((double)ds.size());

    confidence_interval_t ci;
    ci.mean = mean;
    ci.range = z;	

    return ci;
}

auto ConfidenceInterval(
        real_set_t& ds, 
        const real_t z) 
            -> confidence_interval_t {
	return ConfidenceInterval(ds, StandardDeviation(ds, SD::sample), Mean(ds), z);
}
