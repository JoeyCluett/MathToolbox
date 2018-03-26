#define __USE__STD__LIBS__
#include <lib/MathToolbox.hpp>
#include <lib/interp/InterpreterLibs.hpp>
NAMESPACE_RESOLUTION;

static bool ProgRunning = true;

int main(int argc, char* argv[]) {
	if(argc < 2) {
		cerr << "Usage: " << argv[0] << " <filename>\n";
		return 1;
	}

	string filename = argv[1];

	

	return 0;
}