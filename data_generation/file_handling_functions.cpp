// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


////////////////////////////////////////////////////////////////////////////////
//                           Functions definition                             //
////////////////////////////////////////////////////////////////////////////////


#include "structures.hpp"
#include "file_handling_functions.hpp"
#include <iostream>
#include <fstream>


//----------------------------------------------------------------------------//


std::string clean_values(std::string line) {
	std::string cleanedLine ;
	for (size_t i=0 ; i<line.size() ; i++) {
		if (line[i] == '#') {
			break ;
		}
		if (line[i] != ' ' && line[i] != ';') {
			cleanedLine += line[i] ;
		} 
	}
	return cleanedLine ;
}


//----------------------------------------------------------------------------//


// Extraction of parameters from generation_parameters.txt and creation of parameters structure.
void read_parameters_file(parameters &param, std::string path) {
	std::ifstream file ;
	file.open(path) ;
	if (file.is_open()) {
		std::string line ;
		while (getline(file, line)) {
			size_t separator {line.find('=')} ;
			std::string cleanedLine {clean_values(line.substr(separator+1))} ;
			if (line.substr(0, separator) == "expression") {
				// Extraction of expression.
				param.expression = cleanedLine ;
			} else if (line.substr(0, separator) == "number_of_traces") {
				// Extraction of number of traces to generate.
				param.nbTraces = std::stoi(cleanedLine) ;
			} else if (line.substr(0, separator) == "maximum_length") {
				// Extraction of maximum length of traces.
				param.maxLen = std::stoi(cleanedLine) ;
			}
		}
	}
	file.close() ;
}


//----------------------------------------------------------------------------//


void write_results(std::string pathToResults, vectors &traces, parameters &param) {
	std::ofstream file ;
	file.open(pathToResults) ;
	file << "# Generated from expression : " << param.expression << "\n" << std::endl ;
	for (size_t i=0 ; i<traces[0].size() ; i++) {
		for (size_t j=0 ; j<traces.size() ; j++) {
			file << traces[j][i] ;
		}
		file << "\n" ;
	}
	file.close() ;
}