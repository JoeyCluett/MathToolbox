#ifndef __JJC__STD__OPERATIONS__H__
#define __JJC__STD__OPERATIONS__H__

#include <algorithm>
#include "DataSet.hpp"

RealValue Op_Mean(DataSet& data) {
	double sum = 0.0;
	for(auto d : data)
		sum += d;
	sum /= data.size();
	return sum;
}

RealValue Op_Median(DataSet& data) {
	DataSet tmp = data;
	std::sort(tmp.begin(), tmp.end());
	return data[(data.size()+1)/2]; // take into account 0-indexing
}

RealValue Op_Range(DataSet& data) {
	double min__ = *std::min_element(std::begin(data), std::end(data));
	double max__ = *std::max_element(std::begin(data), std::end(data));
	return max__ - min__;
}

void Op_Magnitude(DataSet& data) {
	for(auto& d : data)
		if(d < 0.0)
			d *= -1.0;
}

#endif // __JJC__STD__OPERATIONS__H__