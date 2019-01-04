#ifndef __JJC__VERIFICATION__HPP__
#define __JJC__VERIFICATION__HPP__

#include <lib/MathToolbox.hpp>

const std::string keywords[] = 
	{"@!", "!@", "<=V", "<=R". "-->", "+="};

const char var_no_chars[] = 
	{',', '.', ';', '/', '\\', '\'', '"', '=', '+', '-'};

bool verify_var_name(std::string& var) { // is this a valid variable name?
	for(auto s : keywords)
		if(var == s)
			return false;

	for(auto ch1 : var)
		for(auto ch2 : var_no_chars) // i think im in love
			if(ch1 == ch2)
				return false;

	return true;
}

bool verify_keyword(std::string& var) { // is this a keyword?
	for(auto s : keywords)
		if(var == s)
			return true;
	return false;
}

#endif // __JJC__VERIFICATION__HPP__