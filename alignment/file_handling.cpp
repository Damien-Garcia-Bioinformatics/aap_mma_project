// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB



/* -------------------------------------------------------------------------- */
/*                            Functions definition                            */
/* -------------------------------------------------------------------------- */


#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

#include "file_handling.hpp"


/* ------------------------------- READ-TRACE ------------------------------- */


void read_trace(std::string &line, traceFormat &trace) {
	std::string temp ;
	for (size_t i=0 ; i<line.size() ; i++) {
		if (line[i] == ' ' && !temp.empty()) {
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


/* -------------------------------- READ-FILE ------------------------------- */


void read_file(std::string &path, std::string &expression, vectors &traces) {
	std::ifstream file ;
	file.open(path) ;
	if (file.is_open()) {
		std::string line ;
		while (getline(file, line)) {
			// Extraction of generative expression
			if (expression.empty()) {
				expression = line.substr(line.find(':')+2) ;
			}

			// Extracting traces line by line
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


/* ------------------------------ WRITE-RESULTS ----------------------------- */


void write_results(std::string &pathToResults, std::string &expression, vectors &msa, long time) {
    std::ofstream file ;
    file.open(pathToResults) ;
    if (!file.is_open()) {
        exit(1) ;
    }
    file << "# Alignement parameters :\n" ;
    file << "# Expression = " << expression << "\n" ;
    file << "# Time = " << time << "\n\n" ;

    size_t maxLength {0} ;
    for (size_t i=0 ; i<msa.size() ; i++) {
        for (size_t j=0 ; j<msa[i].size() ; j++) {
            if (msa[i][j].size() > maxLength) {
                maxLength = msa[i][j].size() ;
            }
        }
        for (size_t j=0 ; j<msa[i].size() ; j++) {
            file << msa[i][j] << std::string((maxLength - msa[i][j].size())+1, ' ') ;
        }
        file << "\n" ;
    }
}