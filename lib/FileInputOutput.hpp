#ifndef __JJC__FILE__INPUT__OUTPUT__HPP__
#define __JJC__FILE__INPUT__OUTPUT__HPP__

#include <iostream>
#include <fstream>
#include "DataSet.hpp"

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

void PrintRealData(DataSet& ds) {
	for(auto d : ds)
		std::cout << d << ' ';
	std::cout << std::endl;
}

void PrintRealData(DataSet& ds, std::string& data_name) {
	std::cout << data_name << std::endl << "    ";
	for(auto d : ds)
		std::cout << d << ' ';
	std::cout << std::endl;
}

#endif // __JJC__FILE__INPUT__OUTPUT__HPP__