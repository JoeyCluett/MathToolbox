#ifndef __JJC__DATA__SET__HPP__
#define __JJC__DATA__SET__HPP__

#include <fstream>
#include <string>
#include <vector>

typedef std::vector<double> DataSet;

struct ConfInterval {
	double mean, range;
};

union MultiType {
	ConfInterval conf_interval;
};

double RangeMap(double in, double in_min, double in_max, double out_min, double out_max) {
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