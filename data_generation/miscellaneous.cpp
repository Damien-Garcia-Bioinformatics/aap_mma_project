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
    std::cout << " +-----------------------------------------------------------------------------+" << std::endl ;
    std::cout << " |                             PROGRAM EXECUTION                               |" << std::endl ;
    std::cout << " |                                                                             |" << std::endl ;
    std::cout << " |  Use : './main path_to_parameter_file path_to_result_file'                  |" << std::endl ;
    std::cout << " |                                                                             |" << std::endl ;
    std::cout << " +-----------------------------------------------------------------------------+" << std::endl ;
    std::cout << " |                            PARAMETER FILE FORMAT                            |" << std::endl ;
    std::cout << " |                                                                             |" << std::endl ;
    std::cout << " |  Every parameter file must include :                                        |" << std::endl ;
    std::cout << " |    - 'expression=[exampleExpression]'                                       |" << std::endl ;
    std::cout << " |    - 'number_of_trace=[positiveInteger]'                                    |" << std::endl ;
    std::cout << " |    - 'maximum_length=[positiveInteger]'                                     |" << std::endl ;
    std::cout << " |                                                                             |" << std::endl ;
    std::cout << " |  Do not include spaces on either side of the equal sign.                    |" << std::endl ;
    std::cout << " |  You can comment the parameter file using '#'.                              |" << std::endl ;
    std::cout << " |                                                                             |" << std::endl ;
    std::cout << " +-----------------------------------------------------------------------------+" << std::endl ;
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