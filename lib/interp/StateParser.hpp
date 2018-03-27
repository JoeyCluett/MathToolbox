#ifndef __JJC__STATE__PARSER__HPP__
#define __JJC__STATE__PARSER__HPP__

#include <iostream>
#include <string>
#include "InterpreterLibs.hpp"

enum CurrentInterpState {
	State_StartExpression,
};

bool main_state_parser(int& current_state, StringCollection& sc) {
	switch(current_state) {
		case State_StartExpression:
			
	}

	std::cout << word << std::endl;
	return true;
}

#endif // __JJC__STATE__PARSER__HPP__