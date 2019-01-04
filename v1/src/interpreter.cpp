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
	ifstream fis(filename, ios::in);
	int current_state = State_StartExpression;

	VariableMap vm;

	StringCollection sc;
	StringVec sv;
	sc.setStringVec(sv);

	string tmp;

	while(fis >> tmp)
		sv.push_back(tmp);

	while(ProgRunning) {
		ProgRunning = main_state_parser(current_state, sc, vm); // state, StringCollection, VariableMap

		// debug stuff
		switch(current_state) {
			case State_StartExpression:
				cout << "State: StartExpression" << endl;
				break;
			case State_VariableDeclarationList:
				cout << "State: VariableDeclarationList" << endl;
				break;
			default:
				cout << "State: UNKNOWN" << endl;
				break;
		}

	}

	return 0;
}