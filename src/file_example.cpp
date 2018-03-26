#include <lib/MathToolbox.hpp> // now a single include for the entire library

using namespace std;

int main(int argc, char* argv[]) {
	DataSet ds = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	WriteDataToFileNewline(ds, "tmp/newline-data.txt");

	// sort the data
	__Sort(ds, SortMethod_Decreasing);
	WriteDataToFileNewline(ds, "tmp/sort-decrease.txt");

	// re-sort the data
	__Sort(ds, SortMethod_Increasing);
	WriteDataToFileNewline(ds, "tmp/sort-increase.txt");

	return 0;
}
