#ifndef __JJC__DATA__SET__HPP__
#define __JJC__DATA__SET__HPP__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

typedef double RealValue;
typedef std::vector<RealValue> DataSet;

struct ConfInterval; // forward decl
typedef ConfInterval un_ConfInterval __attribute__((aligned(1)));
struct ConfInterval {
	double mean, range;

	// easy to print out now
	friend std::ostream& operator<<(std::ostream& os, const un_ConfInterval& ci) { // const aligned reference type
		os << ci.mean << " +- " << ci.range;
		return os;
	}
};

struct MaxMin; // forward decl
typedef MaxMin un_MaxMin __attribute__((aligned(1)));
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

// it is useful to be able to save data to files

void WriteDataToFileCsv(DataSet& ds, const std::string& filename) {
	std::cout << "Generating CSV file (" << filename << ")... ";
	std::ofstream fop(filename, std::ios::out);
	for(auto d : ds)
		fop << d << ',';
	fop.close();
	std::cout << "done\n";
}

void WriteDataToFileNewline(DataSet& ds, const std::string& filename) {
	std::ofstream fop(filename, std::ios::out);
	for(auto d : ds)
		fop << d << '\n';
	fop.close();
}

void WriteDataToFileBinary(DataSet& ds, const std::string& filename) {
	std::cout << "Generating binary file (" << filename << ")... ";
	std::ofstream fop(filename, std::ios::out | std::ios::binary);
	for(auto d : ds)
		fop.write((char*)&d, 8);
	fop.close();
	std::cout << "done\n";
}

#endif // __JJC__DATA__SET__HPP__