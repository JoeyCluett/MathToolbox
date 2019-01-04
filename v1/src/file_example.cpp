#define __USE__STD__LIBS__
#include <lib/MathToolbox.hpp> // now a single include for the entire library
NAMESPACE_RESOLUTION;

int main(int argc, char* argv[]) {
	DataSet ds = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	__Shuffle(ds);

	WriteDataToFileNewline(ds, "tmp/newline-data.txt");

	// sort the data
	__Sort(ds, SortMethod_Decreasing);
	WriteDataToFileNewline(ds, "tmp/sort-decrease.txt");

	// re-sort the data
	__Sort(ds, SortMethod_Increasing);
	WriteDataToFileNewline(ds, "tmp/sort-increase.txt");

	// print info about some functions
	PrintInfo(F_PTR(__Mean)); // function pointer cast
	PrintInfo(F_PTR(__Shuffle));
	PrintInfo(F_PTR(__Product));

	cout << endl << TO_STR(ds) << endl;

	return 0;
}
