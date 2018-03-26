#include <lib/DataSet.hpp>
#include <lib/FileInputOutput.hpp>

using namespace std;

int main(int argc, char* argv[]) {
	DataSet ds = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	WriteDataToFileNewline(ds, "tmp/newline-data.txt");

	return 0;
}