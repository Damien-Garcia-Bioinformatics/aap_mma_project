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

#include "structures.hpp"
#include "write_results.hpp"


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