// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


////////////////////////////////////////////////////////////////////////////////
//                           Functions definition                             //
////////////////////////////////////////////////////////////////////////////////


#include "dissimilarity.hpp"
#include "wirematrix.hpp"


dissimMatrix generate_full_dissimilarity_matrix(vectors &traces) {
    dissimMatrix D {traces.size() , std::vector<wireMatrix>(traces.size())} ;
    for (size_t i=0 ; i<traces.size() ; i++) {
        for (size_t j=0 ; j<traces.size() ; j++) {
            if (i > j) {
                D[i][j] = wireMatrix_scoring(traces[i], traces[j]) ;
            }
        }
    }
    return D ;
}