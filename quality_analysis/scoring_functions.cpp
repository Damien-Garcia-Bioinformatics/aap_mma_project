// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB



/* -------------------------------------------------------------------------- */
/*                            Functions definition                            */
/* -------------------------------------------------------------------------- */


#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <map>

#include "scoring_functions.hpp"
#include "file_handling.hpp"


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
    // std::cout << msa.size() << "   " << msa[0].size() << "\n" ;
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


/* ------------------------------ GENERAL-SCORE ----------------------------- */


float general_score(const vectors &msa) {
    float nbPos {(float)(proj_length(msa)) * (float)(msa.size())} ;
    float percentageGap   {((float)(score_g(msa)) / nbPos)} ;
    float percentageMatch {((float)(score_e(msa)) / nbPos)} ;

    return ( (percentageGap * 0.2) + (percentageMatch * 0.8) ) ;
}


/* ----------------------------- MEASURE-SCORES ----------------------------- */

scores measure_scores(const std::string &path, const vectors &msa) {
    scores fileScores ;
    fileScores.fileName = path.substr(path.find_last_of('/')+1) ;
    fileScores.time = get_time(path) ;
    fileScores.score_e = score_e(msa) ;
    fileScores.match_e = match_e(msa) ;
    fileScores.score_g = score_g(msa) ;
    fileScores.proj_length = proj_length(msa) ;
    fileScores.general_score = general_score(msa) ;
    return fileScores ;
}