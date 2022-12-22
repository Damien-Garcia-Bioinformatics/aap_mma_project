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
    std::string path {"../examples/result_complex.txt"} ;
    vectors traces ;
    read_file(path, traces) ;


    // Dissimilarity matrix creation
    dissimMatrix dissimilarity {generate_dissimilarity_matrix(traces)} ;

    // Begin debug

    for (size_t i=0 ; i<dissimilarity.size() ; i++) {
        for (size_t j=0 ; j<dissimilarity[i].size() ; j++) {
            //if (i > j) {
                if (dissimilarity[i][j][traces[i].size()-1][traces[j].size()-1] < 10) {
                    std::cout << dissimilarity[i][j][traces[i].size()-1][traces[j].size()-1] << "  " ;
                } else {
                    std::cout << dissimilarity[i][j][traces[i].size()-1][traces[j].size()-1] << " " ;
                }
            //}
        }
        std::cout << "\n" ;
    }

    std::pair<size_t,size_t> lowest {find_lowest_dissim(dissimilarity, traces)} ;
    std::cout << "\n" << lowest.first << " " << lowest.second << "\n\n" ;

    for (size_t i=0 ; i<dissimilarity[lowest.first][lowest.second].size() ; i++) {
        for (size_t j=0 ; j<dissimilarity[lowest.first][lowest.second][0].size() ; j++) {
            if (dissimilarity[lowest.first][lowest.second][i][j] < 10) {
                std::cout << dissimilarity[lowest.first][lowest.second][i][j] << "  " ;
            } else {
                std::cout << dissimilarity[lowest.first][lowest.second][i][j] << " " ;
            }
        }
        std::cout << "\n" ;
    }
    // End debug

    pairwiseAlign(dissimilarity[lowest.first][lowest.second], traces[lowest.first], traces[lowest.second]) ;

    // update_matrix(dissimilarity, lowest) ;

    // for (size_t i=0 ; i<dissimilarity.size() ; i++) {
    //     for (size_t j=0 ; j<dissimilarity[i].size() ; j++) {
    //         //if (i > j) {
    //             if (dissimilarity[i][j][traces[i].size()-1][traces[j].size()-1] < 10) {
    //                 std::cout << dissimilarity[i][j][traces[i].size()-1][traces[j].size()-1] << "  " ;
    //             } else {
    //                 std::cout << dissimilarity[i][j][traces[i].size()-1][traces[j].size()-1] << " " ;
    //             }
    //         //}
    //     }
    //     std::cout << "\n" ;
    // }

    return 0 ;
}