// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB



/* -------------------------------------------------------------------------- */
/*                              QUALITY ANALYSYS                              */
/* -------------------------------------------------------------------------- */


#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

#include "structures.hpp"
#include "file_handling.hpp"
#include "scoring_functions.hpp"
#include "miscellaneous.hpp"


int main(int argc, char* argv[]) {
    // Cheking command line arguments
    if (argc == 1) {
		// help() ;
		exit(1) ;
	}
	std::string pathInput {argv[1]} ;
    std::string pathOutput ;
    if (std::filesystem::is_directory(pathInput)) {
        pathOutput = argv[2] ;
    }

    // Reading all files in pathInput and calculating alignement scores.
    header() ;
    std::vector<scores> allScores ;
    if (std::filesystem::is_directory(pathInput)) {
        for (const auto& dirEntry : std::filesystem::directory_iterator(pathInput)) {
            std::string path {dirEntry.path()} ;
            vectors msa {read_align(path)} ;
            scores fileScores {measure_scores(path, msa)} ;
            allScores.push_back(fileScores) ;
            print_results(fileScores, msa) ;
        }
    } else if (std::filesystem::is_regular_file(pathInput)) {
        vectors msa {read_align(pathInput)} ;
        scores fileScores {measure_scores(pathInput, msa)} ;
        print_results(fileScores, msa) ;
    }
    
    
    // Writing results to csv file at pathOutput.
    if (std::filesystem::is_directory(pathInput)) {
        write_csv(pathOutput, allScores) ;
    }

    return 0 ;
}