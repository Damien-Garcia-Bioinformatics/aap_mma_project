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
 
std::pair<size_t,size_t> find_lowest_dissim(dissimMatrix &D, vectors &traces) {
    float lowestScore {D[1][0][traces[1].size()-1][traces[0].size()-1]} ;
    std::pair<size_t, size_t> lowestPos(1,0) ;
    for (size_t i=0 ; i<D.size() ; i++) {
        for (size_t j=0 ; j<D.size() ; j++) {
            if (i>j && D[i][j][traces[i].size()-1][traces[j].size()-1]<lowestScore) {
                lowestScore = D[i][j][traces[i].size()-1][traces[j].size()-1] ;
                lowestPos.first = i ;
                lowestPos.second = j ;
            }
        }
    }
    return lowestPos ;
}


void update_matrix(dissimMatrix &D, std::pair<size_t,size_t> lowest) {
    

}