// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


////////////////////////////////////////////////////////////////////////////////
//                             Pairwise alignment                             //
////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#include "structures.hpp"
#include "read_traces.hpp"
#include "dissimilarity.hpp"
#include "wirematrix.hpp"


int main() {
    // Read and extract traces from data file
    std::string path {"../examples/result_complex.txt"} ;
    vectors traces ;
    read_file(path, traces) ;


    // Dissimilarity matrix creation
    msaFormat msa {generate_msa(traces)} ;
    dissimMatrix dissimilarity {generate_dissimilarity_matrix(msa)} ;
    print_dissimMatrix(dissimilarity) ;

    while (msa.size() > 1) {
        std::cout << "\nFind lowest dissimilarity :\n" ;
        std::pair<size_t,size_t> lowest {find_lowest_dissim(dissimilarity)} ;
        std::cout << lowest.first << " - " << lowest.second << "\n" ;

        std::cout << "\nAligning sequences :\n" ;
        vectors align {pairwiseAlign(dissimilarity[lowest.first][lowest.second], msa[lowest.first], msa[lowest.second])} ;
        print_alignment(align) ;

        std::cout << "\nUpdating MSA\n" ;
        update_msa(msa, align, lowest) ;
        std::cout << "\nUpdating dissimilarity matrix\n" ;
        update_dissimMatrix(dissimilarity, msa, align, lowest) ;
        std::cout << "test\n" ;
        print_dissimMatrix(dissimilarity) ;
    }


    // // Prints all wireMatrix in dissimMatrix
    // for (size_t i=0 ; i<dissimilarity.size() ; i++) {
    //     for (size_t j=0 ; j<dissimilarity[i].size() ; j++) {
    //         wireMatrix matrix {dissimilarity[i][j]} ;
    //         for (size_t x=0 ; x<matrix.size() ; x++) {
    //             for (size_t y=0 ; y<matrix[x].size() ; y++) {
    //                 std::cout << matrix[x][y] << "  " ;
    //             }
    //             std::cout << "\n" ;
    //         }
    //         std::cout << "\n\n" ;
    //     }
    // }


    return 0 ;
}