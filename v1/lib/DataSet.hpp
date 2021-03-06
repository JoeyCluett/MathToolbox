#ifndef __JJC__DATA__SET__HPP__
#define __JJC__DATA__SET__HPP__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

typedef double RealValue;
typedef std::vector<RealValue> DataSet;

struct ConfInterval {
	double mean, range;

	// easy to print out now
	friend std::ostream& operator<<(std::ostream& os, const ConfInterval& ci) { // const aligned (packed) reference type
		os << ci.mean << " +- " << ci.range;
		return os;
	}
};

struct MaxMin {
	double min, max;

	friend std::ostream& operator<<(std::ostream& os, const MaxMin& maxmin) { // ...
		os << maxmin.min << " --> " << maxmin.max;
		return os;
	}
};

// combination of all above type
union MultiType {
	ConfInterval conf_interval;
	MaxMin max_min;
};

RealValue RangeMap(double in, double in_min, double in_max, double out_min, double out_max) {
  return (in - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

#endif // __JJC__DATA__SET__HPP__