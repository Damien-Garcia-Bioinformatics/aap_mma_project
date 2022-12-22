// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


////////////////////////////////////////////////////////////////////////////////
//                             Pairwise alignment                             //
////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <vector>

#include "structures.hpp"
#include "read_traces.hpp"
#include "dissimilarity.hpp"
#include "wirematrix.hpp"


int main() {
    // Read and extract traces from data file
    std::string path {"../examples/result_simple.txt"} ;
    vectors traces ;
    read_file(path, traces) ;


    // Dissimilarity matrix creation
    dissimMatrix dissimilarity {generate_full_dissimilarity_matrix(traces)} ;

    // Begin debug
    for (size_t i=0 ; i<dissimilarity.size() ; i++) {
        for (size_t j=0 ; j<dissimilarity.size() ; j++) {
            if (i > j) {
                if (dissimilarity[i][j][traces[i].size()-1][traces[j].size()-1] < 10) {
                    std::cout << dissimilarity[i][j][traces[i].size()-1][traces[j].size()-1] << "  " ;
                } else {
                    std::cout << dissimilarity[i][j][traces[i].size()-1][traces[j].size()-1] << " " ;
                }
            }
        }
        std::cout << "\n" ;
    }
    // End debug

    return 0 ;
}