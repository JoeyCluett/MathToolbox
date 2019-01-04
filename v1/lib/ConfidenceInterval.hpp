#ifndef __JJC__CONFIDENCE__INTERVAL__HPP__
#define __JJC__CONFIDENCE__INTERVAL__HPP__

#include <cmath>
#include "DataSet.hpp"
#include "StdOperations.hpp"

typedef double Z_Value;

#define zValue_70_Percent 1.04
#define zValue_75_Percent 1.15
#define zValue_80_Percent 1.281552
#define zValue_85_Percent 1.44
#define zValue_90_Percent 1.644854
#define zValue_95_Percent 1.959964
#define zValue_96_Percent 2.05
#define zValue_98_Percent 2.326
#define zValue_99_Percent 2.575829

// high precision zValues
#define zValue_99_5_Percent   2.807034
#define zValue_99_9_Percent   3.290527
#define zValue_99_99_Percent  3.890592
#define zValue_99_999_Percent 4.417173

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

MaxMin& ConfIntMaxMin(MultiType& mt) {
	double mean  = mt.conf_interval.mean;
	double range = mt.conf_interval.range;

	double min = mean - range;
	double max = mean + range;

	if(min > max) {
		double tmp = min;
		min = max;
		max = tmp;
	}

	mt.max_min.max = max;
	mt.max_min.min = min;

	return mt.max_min;
}

#endif // __JJC__CONFIDENCE__INTERVAL__HPP__