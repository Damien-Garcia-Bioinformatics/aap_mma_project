// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


////////////////////////////////////////////////////////////////////////////////
//                           Functions definition                             //
////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include "miscellaneous.hpp"


//----------------------------------------------------------------------------//


void help() {
    std::cout << "This is the help function" << std::endl ;
}


//----------------------------------------------------------------------------//


// Function that returns a positive random integer between min and max.
size_t randint(size_t min, size_t max) {
    return rand()%(max)+min ;
}


//----------------------------------------------------------------------------//


// Procedure to shuffle values in a vector of strings.
void shuffle(std::vector<std::string> &trace) {
    // size_t nbShuffle {(trace.size())/2 + 1} ; //Number of shuffle turns
    size_t nbShuffle {trace.size()} ; //Number of shuffle turns
    size_t pos1, pos2 ;
    std::string temp ;
    for (size_t i=0 ; i<nbShuffle ; i++) {
        pos1 = randint(0, trace.size()) ;
        pos2 = randint(0, trace.size()) ;
        if (pos1 != pos2) {
            temp = trace[pos1] ;
            trace[pos1] = trace[pos2] ;
            trace[pos2] = temp ;
        }
    }
}