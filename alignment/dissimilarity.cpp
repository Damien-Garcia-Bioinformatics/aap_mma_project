// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


////////////////////////////////////////////////////////////////////////////////
//                           Functions definition                             //
////////////////////////////////////////////////////////////////////////////////


#include "dissimilarity.hpp"
#include "wirematrix.hpp"


msaFormat generate_msa(vectors &traces) {
    msaFormat msa ;
    vectors temp ;
    for (size_t i=0 ; i<traces.size() ; i++) {
        temp.push_back(traces[i]) ;
        msa.push_back(temp) ;
        temp.clear() ;
    }
    return msa ;
}


dissimMatrix generate_dissimilarity_matrix(msaFormat &msa) {
    dissimMatrix D ;
    std::vector<wireMatrix> temp ;
    for (size_t i=0 ; i<msa.size() ; i++) {
        for (size_t j=0 ; j<msa.size() ; j++) {
            if (i > j) {
                temp.push_back(wireMatrix_scoring(msa[i], msa[j])) ;
            }
        }
        D.push_back(temp) ;
        temp.clear() ;
    }
    return D ;
}
 
std::pair<size_t,size_t> find_lowest_dissim(dissimMatrix &D) {
    float lowestScore {D[1][0][D[1][0].size()-1][D[1][0][0].size()-1]} ;
    std::pair<size_t, size_t> lowestPos(1,0) ;
    for (size_t i=0 ; i<D.size() ; i++) {
        for (size_t j=0 ; j<D[i].size() ; j++) {
            if (D[i][j][D[i][j].size()-1][D[i][j][0].size()-1] < lowestScore) {
                lowestScore = D[i][j][D[i][j].size()-1][D[i][j][0].size()-1] ;
                lowestPos.first = i ;
                lowestPos.second = j ;
            }
        }
    }
    return lowestPos ;
}


// Prints the dissimilarity matrix
void print_dissimMatrix(dissimMatrix &D) {
    for (size_t i=0 ; i<D.size() ; i++) {
        for (size_t j=0 ; j<D[i].size() ; j++) {
            std::cout << D[i][j][D[i][j].size()-1][D[i][j][0].size()-1] << "  " ;
        }
        std::cout << "\n" ;
    }
}


void update_dissimMatrix(dissimMatrix &D, msaFormat &msa) {
    
}