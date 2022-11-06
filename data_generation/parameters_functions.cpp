// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


////////////////////////////////////////////////////////////////////////////////
//                           Functions definition                             //
////////////////////////////////////////////////////////////////////////////////


#include "parameters_functions.hpp"
#include "structures.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


// Extraction of parameters from generation_parameters.txt and creation of parameters structure.
void read_parameters_file(parameters &param) {
	std::ofstream file ;
	file.open("genertion_parameters.txt") ;
	if (file.is_open()) {
		std::string line ;
		while (getline(file, line)) {
			if (line.substr(0, line.find('=') == "expression") {
				// Extraction of expression.
				param.expression = line.substr(line.find('=')) ;
			} else if (line.substr(0, line.find('=') == "expression") {
				// Extraction of number of traces to generate.
				param.nbTraces = line.substr(line.find('=')) ;
			} else if (line.substr(0, line.find('=') == "expression") {
				// Extraction of maximum length of traces.
				param.maxLen = line.substr(line.find('=')) ;
			}
		}
	}
	file.close() ;
}
