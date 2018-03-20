// remember to compile with -std=c++11

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "lib/DataSet.hpp"
#include "lib/StdOperations.hpp"
#include "lib/StdDeviation.hpp"
#include "lib/ConfidenceInterval.hpp"

using namespace std; // for std::namespace, not StdOps/StdDev

// only needed for specific file
void parseGlobalTemps(DataSet& ds);

int main(int argc, char* argv[]) {
	DataSet ds;
	parseGlobalTemps(ds); // get relevant data from file

	cout << "Standard Deviation: " << SampleStandardDeviation(ds) << endl;
	cout << "Mean: " << Op_Mean(ds) << endl;

	MultiType mt = ConfidenceInterval(ds, IL_90_percent); // 90% confidence interval
	cout << "90\% Confidence Interval: " << mt.conf_interval.mean 
			<< " +- " << mt.conf_interval.range << endl;

	cout << "Size of data set: " << ds.size() << " elements" << endl;
	WriteDataToFileCsv(ds, "tmp-csv.txt");
	WriteDataToFileBinary(ds, "tmp-bin.txt");

	return 0;
}

void parseGlobalTemps(DataSet& ds) {
	ds.clear();
	ifstream fin("data/global-temp.txt");
	string str;
	while(fin >> str) {
		fin >> str;
		ds.push_back(stod(str));
	}
	fin.close();

	for(int i = 0; i < 444; i++)
		ds.pop_back();
}
