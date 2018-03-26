#ifndef __JJC__INFO__HPP__
#define __JJC__INFO__HPP__

#include <string>
#include <iostream>
#include "MathToolbox.hpp"

#define COUT std::cout
#define F_PTR(s) ((unsigned long)s)

const std::string std_ops[] = {"__Mean", "__Max", "__Min", "__Median", "__Range", 
				"__Magnitude", "__Sum", "__Product", "__Clamp", 
				"__Shuffle", "__Sort"};

static void Info_StdOps(const std::string& str);

void PrintInfo(const std::string& str) {
	for(auto& ops: std_ops) {
		if(str == ops) {
			Info_StdOps(str);
			return;
		}
	}

	std::cout << str << " does not have an info entry... sorry" << std::endl;
}

void PrintInfo(unsigned long f_ptr) {
	if(f_ptr == F_PTR(__Mean))
		PrintInfo("__Mean");
	else if(f_ptr == F_PTR(__Max))
		PrintInfo("__Max");
	else if(f_ptr == F_PTR(__Min))
		PrintInfo("__Min");
	else if(f_ptr == F_PTR(__Median))
		PrintInfo("__Median");
	else if(f_ptr == F_PTR(__Range))
		PrintInfo("__Range");
	else if(f_ptr == F_PTR(__Magnitude))
		PrintInfo("__Magnitude");
	else if(f_ptr == F_PTR(__Sum))
		PrintInfo("__Sum");
	else if(f_ptr == F_PTR(__Product))
		PrintInfo("__Product");
	else if(f_ptr == F_PTR(__Clamp))
		PrintInfo("__Clamp");
	else if(f_ptr == F_PTR(__Shuffle))
		PrintInfo("__Shuffle");
	else if(f_ptr == F_PTR(__Sort))
		PrintInfo("__Sort");
}

void Info_StdOps(const std::string& str){
	std::cout << str << std::endl;
	if(str == "__Mean") {
		std::cout << "  Prints the average\n";
		std::cout << "  arguments:\n";
		std::cout << "    1) data vector to find the average of\n\n";
		return;

	} else if(str == "__Max") {
		std::cout << "  Find the largest element\n";
		COUT << "  arguments:\n";
		COUT << "    1) data vector to search through for largest element\n\n";
		return;

	} else if(str == "__Min") {
		COUT << "  Find the smallest element\n";
		COUT << "  arguments:\n";
		COUT << "    1) data vector to search through for smallest element\n\n";
		return;

	} else if(str == "__Median") {
		COUT << "  Find the median element\n";
		COUT << "  arguments:\n";
		COUT << "    1) data vector to search through for median value\n\n";
		return;

	} else if(str == "__Range") {
		COUT << "  Find the range of values\n";
		COUT << "  arguments:\n";
		COUT << "    1) data vector to find the range of\n\n";
		return;

	} else if(str == "__Magnitude") {
		COUT << "  Make every negative value positive, just like absolute value for real numbers\n";
		COUT << "  arguments:\n";
		COUT << "    1) data vector to operate on\n\n";
		return;

	} else if(str == "__Sum") {
		COUT << "  Find the sum of all elements\n";
		COUT << "  arguments:\n";
		COUT << "    1) data vector to operate on\n\n";
		return;

	} else if(str == "__Product") {
		COUT << "  Find the product of all elements\n";
		COUT << "  arguments:\n";
		COUT << "    1) data vector to operate on\n\n";
		return;

	} else if(str == "__Clamp") {
		COUT << "  Clamp every element between two extremes\n";
		COUT << "  arguments:\n";
		COUT << "    1) data vector to operate on\n";
		COUT << "    2) maximum value for data vector\n";
		COUT << "    3) minimum value for data vector\n\n";
		return;

	} else if(str == "__Shuffle") {
		COUT << "  Randomize elements\n";
		COUT << "  arguments:\n";
		COUT << "    1) data vector to operate on\n\n";
		return;

	} else if(str == "__Sort") {
		COUT << "  Sort elements in one of two ways\n";
		COUT << "  arguments:\n";
		COUT << "    1) data vector to operate on\n";
		COUT << "    2) sort method to use when sorting\n";
		COUT << "      a) SortMethod_Increasing: smallest element at the beginning\n";
		COUT << "      b) SortMethod_Decreasing: largest element at the beginning\n\n";
		return;
	}

	std::cout << "  THIS FUNCTION DOES NOT HAVE A DEFINITION\n";
}

#endif // __JJC__INFO__HPP__