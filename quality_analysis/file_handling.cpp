// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


////////////////////////////////////////////////////////////////////////////////
//                           Functions definition                             //
////////////////////////////////////////////////////////////////////////////////


#include <string>
#include <vector>
#include <fstream>

#include "file_handling.hpp"


void read_align(std::string &path, vectors &msa) {
    std::ifstream file ;
    file.open(path) ;
    if (!file.is_open()) {
        exit(1) ;
    }
    std::string line ;
    std::string temp ;
    std::vector<std::string> trace ;
    while (getline(file, line)) {
        if (line[0] != '#' && !line.empty()) {
            for (size_t i=0 ; i<line.size() ; i++) {
                if (line[i] == ' ') {
                    trace.push_back(temp) ;
                    temp.clear() ;
                } else {
                    temp += line[i] ;
                }
            }
            if (!temp.empty()) {
                trace.push_back(temp) ;
                temp.clear() ;
            }
            msa.push_back(trace) ;
        }
    }
}


void write_csv(std::string &path) {
    std::ofstream file ;
    file.open(path) ;
    if (!file.is_open()) {
        exit(1) ;
    }
}