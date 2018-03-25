// remember to compile with -std=c++11 or better

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "lib/DataSet.hpp"
#include "lib/StdOperations.hpp"
#include "lib/StandardDeviation.hpp"
#include "lib/ConfidenceInterval.hpp"

using namespace std; // for std::namespace, not StdOps/StdDev

int main(int argc, char* argv[]) {
	DataSet ds = {1.0, 2.0, 3.0, 4.0};

	cout << "Standard Deviation: " << SampleStandardDeviation(ds) << endl;
	cout << "Mean:    " << __Mean(ds) << endl;
	cout << "Sum:     " << __Sum(ds) << endl;
	cout << "Product: " << __Product(ds) << endl;

	// Confidence Interval
	MultiType mt = ConfidenceInterval(ds, zValue_99_999_Percent);
	cout << mt.conf_interval << endl;
	cout << ConfIntMaxMin(mt) << endl;

	return 0;
}
