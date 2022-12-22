// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


////////////////////////////////////////////////////////////////////////////////
//                                 Data types                                 //
////////////////////////////////////////////////////////////////////////////////


#ifndef __STRUCTURES__
#define __STRUCTURES__


#include <string>

using traceFormat = std::vector<std::string> ;
using vectors = std::vector<traceFormat> ;
using alignTrace = std::vector<vectors> ;
using wireMatrix = std::vector<std::vector<size_t>> ;
using dissimMatrix = std::vector<std::vector<wireMatrix>> ;


struct alignment {
    traceFormat seq1 ;
    traceFormat seq2 ;
} ;


#endif 