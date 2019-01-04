#ifndef __JJC__STATE__PARSER__HPP__
#define __JJC__STATE__PARSER__HPP__

#include <iostream>
#include <string>
#include "InterpreterLibs.hpp"

enum CurrentInterpState {
	State_StartExpression,
	State_VariableDeclarationList,
};

bool main_state_parser(int& current_state, StringCollection& sc, VariableMap& vm) {
	std::string token;
	switch(current_state) {
		case State_StartExpression: {
			token = sc.getNextString();
			if(token == "@!") { // variable declaration
				current_state = State_VariableDeclarationList;
				return true;
			}
		}

		case State_VariableDeclarationList: {
			token = sc.getNextString();
			if(verify_var_name(token)) {
				
			}
		}

		default:
			return false;
	}
}

#endif // __JJC__STATE__PARSER__HPP__