// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


/* -------------------------------------------------------------------------- */
/*                                 Data types                                 */
/* -------------------------------------------------------------------------- */


#ifndef __STRUCTURES__
#define __STRUCTURES__


#include <string>
#include <vector>
#include <map>

using elemAtPos = std::map<std::string,size_t> ;
using vectors = std::vector<std::vector<std::string>> ;


struct scores {
    std::string fileName ;
    long time ;
    size_t score_e ;
    size_t match_e ;
    size_t score_g ;
    size_t proj_length ;
    float general_score ;
} ;


#endif