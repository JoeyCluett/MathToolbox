#ifndef __JJC__CONFIDENCE__INTERVAL__HPP__
#define __JJC__CONFIDENCE__INTERVAL__HPP__

#include <cmath>
#include "DataSet.hpp"
#include "StdOperations.hpp"

typedef double Z_Value;

#define zValue_70_Percent 1.04
#define zValue_75_Percent 1.15
#define zValue_80_Percent 1.28
#define zValue_85_Percent 1.44
#define zValue_90_Percent 1.645
#define zValue_95_Percent 1.96
#define zValue_96_Percent 2.05
#define zValue_98_Percent 2.326
#define zValue_99_Percent 2.576

MultiType ConfidenceInterval(DataSet& ds, RealValue std_deviation, RealValue mean, Z_Value z) {
	z *= std_deviation; // dont need std_dev after this anyway
	z /= sqrt((double)ds.size());

	MultiType mt;
	mt.conf_interval.mean  = mean;
	mt.conf_interval.range = z;	

	return mt;
}

MultiType ConfidenceInterval(DataSet& ds, Z_Value z) {
	return ConfidenceInterval(ds, SampleStandardDeviation(ds), __Mean(ds), z);
}

#endif // __JJC__CONFIDENCE__INTERVAL__HPP__