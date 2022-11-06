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
	file.open("genertion_parameters.txt",ios::out) ;
	if (file.is_open()) {
		while (get_line(file, line) {
			if (line[0] == '#') {
				continue ;
			}
			// Extraction of expression.
			if (line.substr(0, line.find('=') == "expression") {
				param.expression = line.substr(line.find('=')) ;
				continue ;
			}
			// Extraction of number of traces to generate.
			if (line.substr(0, line.find('=') == "expression") {
				param.nbTraces = line.substr(line.find('=')) ;
				continue ;
			}
			// Extraction of number of traces to generate.
			if (line.substr(0, line.find('=') == "expression") {
				param.maxLen = line.substr(line.find('=')) ;
				continue ;
			}
	}
}
