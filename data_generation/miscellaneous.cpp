#include <vector>
#include <string>
#include "miscellaneous.hpp"

// Returns a positive integer between min and max
size_t randint(size_t min, size_t max) {
    return rand()%(max)+min ;
}

// Shuffles a vector 
void shuffle(std::vector<std::string> &trace) {
    size_t nbShuffle {(trace.size())/2 + 1} ; //Number of shuffle turns
    size_t pos1, pos2 ;
    std::string temp ;
    for (size_t i=0 ; i<nbShuffle ; i++) {
        pos1 = randint(0, trace.size()-1) ;
        pos2 = randint(0, trace.size()-1) ;
        if (pos1 != pos2) {
            temp = trace[pos1] ;
            trace[pos1] = trace[pos2] ;
            trace[pos2] = temp ;
        }
    }
}