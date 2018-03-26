#ifndef __JJC__FILE__INPUT__OUTPUT__HPP__
#define __JJC__FILE__INPUT__OUTPUT__HPP__

#include <iostream>
#include <fstream>
#include "DataSet.hpp"
#include "ComplexSet.hpp"

void WriteDataToFileCsv(DataSet& ds, const std::string& filename) {
	std::cout << "Generating CSV file (" << filename << ")... ";
	std::ofstream fop(filename, std::ios::out);
	for(auto d : ds)
		fop << d << ',';
	fop.close();
	std::cout << "done\n";
}

void WriteDataToFileNewline(DataSet& ds, const std::string& filename) {
	std::ofstream fop(filename, std::ios::out);
	for(auto d : ds)
		fop << d << '\n';
	fop.close();
}

void WriteDataToFileBinary(DataSet& ds, const std::string& filename) {
	std::cout << "Generating binary file (" << filename << ")... ";
	std::ofstream fop(filename, std::ios::out | std::ios::binary);
	for(auto d : ds)
		fop.write((char*)&d, 8);
	fop.close();
	std::cout << "done\n";
}

static void PrintRealData(DataSet& ds) {
	for(auto d : ds)
		std::cout << d << ' ';
	std::cout << std::endl;
}

static void PrintRealData(DataSet& ds, std::string& data_name) {
	std::cout << data_name << std::endl << "    ";
	PrintRealData(ds);
}

static void PrintComplexData(ComplexSet& cs) {
	for(auto c : cs) 
		std::cout << c << ' ';
	std::cout << std::endl;
}

static void PrintComplexData(ComplexSet& cs, std::string& data_name) {
	std::cout << data_name << std::endl << "    ";
	PrintComplexData(cs);
}

// overloaded print functions for all vector/named types
void PrintVector(DataSet& ds) { PrintRealData(ds); }
void PrintVector(DataSet& ds, std::string& data_name) { PrintRealData(ds, data_name); }
void PrintVector(ComplexSet& cs) { PrintComplexData(cs); }
void PrintVector(ComplexSet& cs, std::string& data_name) { PrintComplexData(cs, data_name); }

// for using inline with (cout << VECTOR/SCALAR_TYPE)

std::string& TO_STR(DataSet& ds) {
	static std::string output = "";
	output.clear();
	for(auto d : ds)
		output += std::to_string(d) + ' ';
	return output;
}

std::string& TO_STR(ComplexSet& cs) {
	static std::string output = "";
	output.clear();
	for(auto d : cs) {
		output += "(";
		output += std::to_string(d.real());
		output += ",";
		output += std::to_string(d.imag());
		output += ")";
	}
	return output;
}

#endif // __JJC__FILE__INPUT__OUTPUT__HPP__