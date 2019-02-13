#pragma once

#include <cmath>
#include <assert.h>
#include "TypeRedefinitions.h"

// a collection of deriving functions

namespace Derive {

    real_set_t newton(NumericSequence ns) {
        real_set_t rs;
        real_t dx = ns.x_diff();

        for(int i = 0; i < ns.size()-1; i++) {
            // current value and next value 
            // used to calculate slope
            real_t result = (ns[i+1] - ns[i]) / dx;
            rs.push_back(result);
        }

        // derive the very last entry
        auto t = rs.back();
        rs.push_back(t);

        assert(rs.size() == ns.size());

        return rs;
    }

} // end namespace Derive