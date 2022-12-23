// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


////////////////////////////////////////////////////////////////////////////////
//                           Functions definition                             //
////////////////////////////////////////////////////////////////////////////////


#include <fstream>
#include <iostream>
#include "read_traces.hpp"


void read_trace(std::string &line, traceFormat &trace) {
	std::string temp ;
	for (size_t i=0 ; i<line.size() ; i++) {
		if (line[i] == ' ') {
			trace.push_back(temp) ;
			temp.clear() ;
		} else {
			temp += line[i] ;
		}
	}
	// Last value push back in vector.
	if (!temp.empty()) {
		trace.push_back(temp) ;
		temp.clear() ;
	}
}


void read_file(std::string &path, vectors &traces) {
	std::ifstream file ;
	file.open(path) ;
	if (file.is_open()) {
		std::string line ;
		while (getline(file, line)) {
			if (line[0] != '#' && !line.empty()) {
				traceFormat trace ;
				read_trace(line, trace) ;
				traces.push_back(trace) ;
				trace.clear() ;
			} 
		}
	}
	file.close() ;
}