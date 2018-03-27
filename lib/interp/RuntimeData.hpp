#ifndef __JJC__RUNTIME__DATA__HPP__
#define __JJC__RUNTIME__DATA__HPP__

#include <vector>
#include <string>
#include "InterpreterLibs.hpp"

typedef std::vector<std::string> StringVec;

class StringCollection {
private:
	int current_index = 0;
	StringVec* svec = 0;

public:

	void setStringVec(StringVec& svec) { // ref
		this->svec = &svec;              // ptr
	}

	std::string& getNextString(void) {
		if(hasAvailableStrings())
			return svec->at(current_index++);
		std::cerr << "Interpreter out of tokens\n";
		exit(-1);
	}

	bool hasAvailableStrings(void) {
		return current_index < svec.size();
	}

};

#endif // __JJC__RUNTIME__DATA__HPP__