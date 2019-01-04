#ifndef __JJC__RUNTIME__DATA__HPP__
#define __JJC__RUNTIME__DATA__HPP__

#include <vector>
#include <string>
#include <map>
#include "InterpreterLibs.hpp"
#include <lib/MathToolbox.hpp>

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

enum VarType {
	Type_Undefined,
	Type_Real,
	Type_RealVec,
	Type_Complex,
	Type_ComplexVec
};

// 4 pts = 32 bytes before an object is allocated
struct VarData {
	RealValue*    real     = 0;
	DataSet*      real_set = 0;
	ComplexValue* comp     = 0;
	ComplexSet*   comp_set = 0;
};

struct InterpVariable {
	VarType v_type = Type_Undefined;
	VarData v_data;
};

typedef std::map<std::string, InterpVariable> VariableMap;

#endif // __JJC__RUNTIME__DATA__HPP__