// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB



/* -------------------------------------------------------------------------- */
/*                            Functions definition                            */
/* -------------------------------------------------------------------------- */


#include <string>
#include <vector>
#include <fstream>

#include "file_handling.hpp"


/* -------------------------------- GET-TIME -------------------------------- */

// Function returning sampled time for an operation
long get_time(const std::string &path) {
    std::ifstream file ;
    file.open(path) ;
    if (!file.is_open()) {
        exit(1) ;
    }
    std::string line ;
    while (getline(file, line)) {
        if (line.find("Time") != std::string::npos) {
            return std::stol(line.substr(line.find('=')+2)) ;
        }
    }
    return -1 ;
}


/* ------------------------------- READ-ALIGN ------------------------------- */

// Function returning the alignment from a file where it is stocked
vectors read_align(const std::string &path) {
    vectors msa ;
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
                    if (!temp.empty()) {
                        trace.push_back(temp) ;
                        temp.clear() ;
                    }
                } else {
                    temp += line[i] ;
                }
            }
            if (!temp.empty()) {
                trace.push_back(temp) ;
                temp.clear() ;
            }
            msa.push_back(trace) ;
            trace.clear() ;
        }
    }
    return msa ;
}


/* -------------------------------- WRITE-CSV ------------------------------- */

// Procedure to write the process' result to a CSV file
void write_csv(std::string &path, std::vector<scores> &allScores) {
    std::ofstream file ;
    file.open(path) ;
    if (!file.is_open()) {
        exit(1) ;
    }
    file << "file_name;exec_time;score_e;match_e;score_g;proj_length;general_score\n" ;
    for (size_t i=0 ; i<allScores.size() ; i++) {
        file << allScores[i].fileName << ";"
             << allScores[i].time << ";"
             << allScores[i].score_e << ";"
             << allScores[i].match_e << ";"
             << allScores[i].score_g << ";"
             << allScores[i].proj_length << ";"
             << allScores[i].general_score << "\n" ;
    }
}