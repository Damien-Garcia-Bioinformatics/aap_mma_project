// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB



/* -------------------------------------------------------------------------- */
/*                            Functions definition                            */
/* -------------------------------------------------------------------------- */


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

#include "scoring_functions.hpp"


/* ------------------------------ MAP-POSITION ------------------------------ */


elemAtPos map_position(const vectors &msa, size_t pos) {
    std::map<std::string,size_t> elements ;
    for (size_t i=0 ; i<msa.size() ; i++) {
        if (elements.find(msa[i][pos]) == elements.end()) {
            elements.insert({msa[i][pos], 1}) ;
        } else {
            elements.find(msa[i][pos])->second++ ;
        }
    }
    return elements ;
}


/* --------------------------------- SCORE-E -------------------------------- */


size_t score_e(const vectors &msa) {
    size_t score {0} ;

    for (size_t i=0 ; i<msa[0].size() ; i++) {
        elemAtPos map {map_position(msa, i)} ;
        std::map<std::string,size_t>::iterator it ;
        for (it=map.begin() ; it!=map.end() ; it++) {
            if (it->first != "-" && it->second >= 2) {
                score += it->second ;
            }
        }
    }
    
    return score ;
}


/* --------------------------------- MATCH-E -------------------------------- */


size_t match_e(const vectors &msa) {
    size_t score {0} ;

    for (size_t i=0 ; i<msa[0].size() ; i++) {
        elemAtPos map {map_position(msa, i)} ;
        std::map<std::string,size_t>::iterator it ;
        for (it=map.begin() ; it!=map.end() ; it++) {
            if ((it->first != "-" && it->first != ".") && it->second >= 2) {
                score += it->second ;
            }
        }
    }
    
    return score ;
}


/* --------------------------------- SCORE-G -------------------------------- */


size_t score_g(const vectors &msa) {
    size_t score {0} ;
    std::cout << msa.size() << "   " << msa[0].size() << "\n" ;
    for (size_t i=0 ; i<msa.size() ; i++) {
        for (size_t j=0 ; j<msa[i].size() ; j++) {
            if (msa[i][j].find("-") != std::string::npos) {
                score++ ;
            }
        }
    }
    return score ;
}


/* ------------------------------- PROJ-LENGTH ------------------------------ */


size_t proj_length(const vectors &msa) {
    return (msa[0].size()) ;
}