#ifndef __JJC__STD__OPERATIONS__H__
#define __JJC__STD__OPERATIONS__H__

#include <algorithm>
#include <random>
#include <chrono>
#include "DataSet.hpp"

RealValue __Mean(DataSet& data) {
	double sum = 0.0;
	for(auto d : data)
		sum += d;
	sum /= data.size();
	return sum;
}

RealValue __Max(DataSet& data) {
	return *std::max_element(std::begin(data), std::end(data));
}

RealValue __Min(DataSet& data) {
	return *std::min_element(std::begin(data), std::end(data));
}

RealValue __Median(DataSet& data) {
	DataSet tmp = data;
	std::sort(tmp.begin(), tmp.end());
	return tmp[(tmp.size()+1)/2]; // take into account 0-indexing
}

RealValue __Range(DataSet& data) {
	return __Max(data) - __Min(data);
}

void __Magnitude(DataSet& data) { // abs() on every element
	for(auto& d : data)
		if(d < 0.0)
			d *= -1.0;
}

RealValue __Sum(DataSet& data) {
	RealValue sum = 0.0;
	for(auto d : data)
		sum += d;
	return sum;
}

RealValue __Product(DataSet& data) {
	RealValue product = 1.0;
	for(auto d : data)
		product *= d;
	return product;
}

void __Clamp(DataSet& data, RealValue max, RealValue min) {
	for(auto& d : data) {
		if(d < min)
			d = min;
		if(d > max)
			d = max;
	}

}

void __Shuffle(DataSet& data) {
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(data.begin(), data.end(), std::default_random_engine(seed));
}

enum SortMethod {
	SortMethod_Increasing,
	SortMethod_Decreasing
};

void __Sort(DataSet& data, SortMethod sm) {
	switch(sm) {
		case SortMethod_Increasing:
			std::sort(data.begin(), data.end());
			return;
		case SortMethod_Decreasing:
			std::sort(data.begin(), data.end(), std::greater<double>());
	}
}

#endif // __JJC__STD__OPERATIONS__H__