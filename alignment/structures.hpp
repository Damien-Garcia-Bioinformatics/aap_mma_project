// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


////////////////////////////////////////////////////////////////////////////////
//                                 Data types                                 //
////////////////////////////////////////////////////////////////////////////////


#ifndef __STRUCTURES__
#define __STRUCTURES__


#include <string>


using vectors = std::vector<std::vector<std::string>> ;
using wireMatrix = std::vector<std::vector<size_t>> ;
using dissimMatrix = std::vector<std::vector<size_t>> ;


struct alignment {
    std::string seq1 ;
    std::string link ;
    std::string seq2 ;
} ;


#endif 