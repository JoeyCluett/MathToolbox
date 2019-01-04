#ifndef __JJC__STANDARD__DEVIATION__HPP__
#define __JJC__STANDARD__DEVIATION__HPP__

#include <cmath>
#include "DataSet.hpp"
#include "StdOperations.hpp"

static RealValue inner_standard_deviation(DataSet& ds) {
	RealValue mean = __Mean(ds);

	RealValue sum = 0.0;
	for(auto d : ds) 
		sum += (d-mean)*(d-mean);

	return sum;
}

RealValue PopulationStandardDeviation(DataSet& ds) {
	RealValue numer = inner_standard_deviation(ds);
	RealValue denom = double(ds.size());
	return sqrt(numer/denom);
}

RealValue SampleStandardDeviation(DataSet& ds) {
	RealValue numer = inner_standard_deviation(ds);
	RealValue denom = double(ds.size()) - 1.0;
	return sqrt(numer/denom);
}

#endif // __JJC__STANDARD__DEVIATION__HPP__