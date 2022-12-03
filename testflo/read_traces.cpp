// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


////////////////////////////////////////////////////////////////////////////////
//                           Functions definition                             //
////////////////////////////////////////////////////////////////////////////////


#include "read_traces.hpp"
#include <fstream>


void read_trace(std::string &line, std::vector<std::string> &trace) {
	std::string temp ;
	for (size_t i=0 ; i<line.size() ; i++) {
		if (line[i] == ' ') {
			trace.push_back(temp) ;
		} else {
			temp += trace[i] ;
		}
	}
	// Last value push back in vector.
	if (!temp.empty()) {
		trace.push_back(temp) ;
	}
}


void read_file(std::string &path, vectors &traces) {
	std::ifstream file ;
	file.open(path) ;
	if (file.is_open()) {
		std::string line ;
		while (getline(file, line)) {
			std::vector<std::string> trace ;
			read_trace(line, trace) ;
			traces.push_back(trace) ;
			trace.clear() ;
		}
	}
	file.close() ;
}