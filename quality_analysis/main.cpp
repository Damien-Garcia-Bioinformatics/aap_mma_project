// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


////////////////////////////////////////////////////////////////////////////////
//                                     Main                                   //
////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

#include "structures.hpp"
#include "file_handling.hpp"
#include "scoring_functions.hpp"


int main(int argc, char* argv[]) {
    // Cheking command line arguments
    if (argc == 1) {
		// help() ;
		exit(1) ;
	}
	std::string pathInput {argv[1]}, pathOutput {argv[2]} ;

    std::vector<scores> allScores ;
    for (const auto& dirEntry : std::filesystem::directory_iterator(pathInput)) {
        std::string path {dirEntry.path()} ;
        vectors msa {read_align(path)} ;
        scores fileScores ;
        fileScores.fileName = path.substr(path.find_last_of('/')+1) ;
        fileScores.score_e = score_e(msa) ;
        fileScores.match_e = match_e(msa) ;
        fileScores.score_g = score_g(msa) ;
        fileScores.proj_length = proj_length(msa) ;
        allScores.push_back(fileScores) ;
    }

    write_csv(pathOutput, allScores) ;

    return 0 ;
}