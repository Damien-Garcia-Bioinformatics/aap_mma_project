// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB



/* -------------------------------------------------------------------------- */
/*                                  Alignment                                 */
/* -------------------------------------------------------------------------- */


#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "structures.hpp"
#include "file_handling.hpp"
#include "dissimilarity.hpp"
#include "wirematrix.hpp"


int main(int argc, char* argv[]) {
   	// Check if paths of parameter and result files are provided
	if (argc == 1) {
		// help() ;
		exit(1) ;
	}
	std::string pathToParameters {argv[1]}, pathToResults {argv[2]} ;

    // Read and extract traces from data file
    std::cout << "[MSA] Reading traces from : " << pathToParameters << "\n" ;
    std::string expression ;
    vectors traces ;
    read_file(pathToParameters, expression, traces) ;

    // Begin execution time calculation
    std::clock_t cpuTimeStart {std::clock()} ;

    // Dissimilarity matrix and MSA initialization
    std::cout << "[MSA] Generation of Multiple Sequence Alignment\n" ;
    msaFormat msa {generate_msa(traces)} ;
    dissimMatrix dissimilarity {generate_dissimilarity_matrix(msa)} ;

    // Performing MSA (step by step aggreagation of sequences)
    while (msa.size() > 1) {
        std::pair<size_t,size_t> lowest {find_lowest_dissim(dissimilarity)} ;
        vectors align {pairwiseAlign(dissimilarity[lowest.first][lowest.second], msa[lowest.first], msa[lowest.second])} ;
        update_msa(msa, align, lowest) ;
        update_dissimMatrix(dissimilarity, msa, align, lowest) ;
    }

    // Ending execution time calculation
    std::clock_t cpuTimeStop {std::clock()} ;
    long cpuTimeElapse {1000 * (cpuTimeStop - cpuTimeStart) / CLOCKS_PER_SEC} ;

    // Saving alignment results to output file
    std::cout << "[MSA] Writing results to : " << pathToResults << "\n" ;
    write_results(pathToResults, expression, msa[0], cpuTimeElapse) ;

    return 0 ;
}