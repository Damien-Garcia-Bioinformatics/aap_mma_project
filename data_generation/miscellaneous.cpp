// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB



/* -------------------------------------------------------------------------- */
/*                            Functions definition                            */
/* -------------------------------------------------------------------------- */


#include <iostream>

#include "miscellaneous.hpp"


/* ---------------------------------- HELP ---------------------------------- */


void help() {
    std::cout << " +-----------------------------------------------------------------------------+\n" ;
    std::cout << " |                             PROGRAM EXECUTION                               |\n" ;
    std::cout << " |                                                                             |\n" ;
    std::cout << " |  Use : './main path_to_parameter_file path_to_result_file'                  |\n" ;
    std::cout << " |                                                                             |\n" ;
    std::cout << " +-----------------------------------------------------------------------------+\n" ;
    std::cout << " |                            PARAMETER FILE FORMAT                            |\n" ;
    std::cout << " |                                                                             |\n" ;
    std::cout << " |  Every parameter file must include :                                        |\n" ;
    std::cout << " |    - 'expression=[exampleExpression]'                                       |\n" ;
    std::cout << " |    - 'number_of_trace=[positiveInteger]'                                    |\n" ;
    std::cout << " |    - 'maximum_length=[positiveInteger]'                                     |\n" ;
    std::cout << " |                                                                             |\n" ;
    std::cout << " |  Do not include spaces on either side of the equal sign.                    |\n" ;
    std::cout << " |  You can comment the parameter file using '#'.                              |\n" ;
    std::cout << " |                                                                             |\n" ;
    std::cout << " +-----------------------------------------------------------------------------+\n" ;
}


/* --------------------------------- RANDINT -------------------------------- */


// Function that returns a positive random integer between min and max.
size_t randint(size_t min, size_t max) {
    return rand()%(max)+min ;
}


/* --------------------------------- SHUFFLE -------------------------------- */


// Procedure to shuffle values in a vector of strings.
void shuffle(std::vector<std::string> &trace) {
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