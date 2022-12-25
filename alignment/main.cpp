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
    std::cout << "   +-------------------------------------+\n" ;
    std::cout << "   |  Multiple Sequence Alignement tool  |\n" ;
    std::cout << "   +-------------------------------------+\n\n" ;

    // Read and extract traces from data file
    std::string path {"../examples/test1_result.txt"} ;
    std::cout << "Reading data from file : '" << path << "'\n" ;
    vectors traces ;
    read_file(path, traces) ;

    // Dissimilarity matrix creation
    std::cout << "Generation of Multiple Sequence Alignment :\n" ;
    msaFormat msa {generate_msa(traces)} ;
    dissimMatrix dissimilarity {generate_dissimilarity_matrix(msa)} ;
    // print_dissimMatrix(dissimilarity) ;

    while (msa.size() > 1) {
        // std::cout << "\nFind lowest dissimilarity :\n" ;
        std::pair<size_t,size_t> lowest {find_lowest_dissim(dissimilarity)} ;

        // std::cout << "\nAligning sequences :\n" ;
        vectors align {pairwiseAlign(dissimilarity[lowest.first][lowest.second], msa[lowest.first], msa[lowest.second])} ;
        // print_alignment(align) ;

        // std::cout << "\nUpdating MSA\n" ;
        update_msa(msa, align, lowest) ;
        // std::cout << "\nUpdating dissimilarity matrix\n" ;
        update_dissimMatrix(dissimilarity, msa, align, lowest) ; //OPTIMIZED VERSION
        // dissimilarity = generate_dissimilarity_matrix(msa) ;
        // print_dissimMatrix(dissimilarity) ;
    }

    // std::cout << "MSA SIZE = " << msa.size() << "\n" ;
    // std::cout << "SEQ SIZE = " << msa[0].size() << "\n" ;
    print_alignment(msa[0]) ;

    std::cout << "\n\n\n" ;

    print_alignment_v2(msa[0]) ;

    return 0 ;
}