// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB



/* -------------------------------------------------------------------------- */
/*                            Functions definition                            */
/* -------------------------------------------------------------------------- */


#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "structures.hpp"
#include "miscellaneous.hpp"


/* ---------------------------------- HELP ---------------------------------- */


void help() {
    std::cout << "  ╔═══════════════════════════════════════════════════════════════════════════════╗\n" ;
    std::cout << "  ║                             PROGRAM EXECUTION                                 ║\n" ;
    std::cout << "  ║                                                                               ║\n" ;
    std::cout << "  ║  Use : './main [path_to_alignment] [path_to_output]'                          ║\n" ;
    std::cout << "  ║                                                                               ║\n" ;
    std::cout << "  ║  [path_to_parameter_file] can either be a single file, or a directory which   ║\n" ;
    std::cout << "  ║  contains multiple files to score. If you select to score a single file, the  ║\n" ;
    std::cout << "  ║  [path_to_output] is not necessary, results will only be shown on command     ║\n" ;
    std::cout << "  ║  line output.                                                                 ║\n" ;
    std::cout << "  ║                                                                               ║\n" ;
    std::cout << "  ║  [path_to_output] is the path where a csv file format will be created and     ║\n" ;
    std::cout << "  ║  and it will contain the scores of multiple alignment files.                  ║\n" ;
    std::cout << "  ║                                                                               ║\n" ;
    std::cout << "  ╚═══════════════════════════════════════════════════════════════════════════════╝\n" ;
}


/* ------------------------------ PRINT-SCORES ------------------------------ */

// header !
void header() {
    std::cout << "  ╔═══════════════════════════════════════════════════════════════════════════════╗\n" ;
    std::cout << "  ║                           ███╗   ███╗███████╗ █████╗                          ║\n" ;
    std::cout << "  ║                           ████╗ ████║██╔════╝██╔══██╗                         ║\n" ;
    std::cout << "  ║                           ██╔████╔██║███████╗███████║                         ║\n" ;
    std::cout << "  ║                           ██║╚██╔╝██║╚════██║██╔══██║                         ║\n" ;
    std::cout << "  ║                           ██║ ╚═╝ ██║███████║██║  ██║                         ║\n" ;
    std::cout << "  ║                           ╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝                         ║\n" ;
    std::cout << "  ╚═══════════════════════════════════════════════════════════════════════════════╝\n" ;
}


// Procedure to print the traces from the datastes properly, as well as the scores
void print_results(const scores fs, vectors msa) {
    size_t nameSize {std::to_string(msa.size()-1).size()+3} ;
    size_t maximalSize {80 - nameSize - 4} ; // Width of print
    size_t elemSize {0} ;

    std::string tab       {"  ║ "} ;
    std::string top       {"  ╔═══════════════════════════════════════════════════════════════════════════════╗\n"} ;
    std::string strAlign  {"  ║                      --- Multiple Sequence Alignment ---                      ║\n"} ;
    std::string strScore  {"  ║                                --- Scores ---                                 ║\n"} ;
    std::string lineBreak {"  ║                                                                               ║\n"} ;
    std::string end       {"  ╚═══════════════════════════════════════════════════════════════════════════════╝\n"} ;

    vectors print ;
    std::string temp ;
    for (size_t i=0 ; i<msa.size() ; i++) {
        elemSize = 0 ;
        print.push_back(std::vector<std::string>()) ;
        for (size_t j=0 ; j<msa[i].size() ; j++) {
            if (msa[i][j].size() > elemSize) {
                elemSize = msa[i][j].size() ;
            }
        }
        for (size_t j=0 ; j<msa[i].size() ; j++) {
            if ((temp.size() + elemSize + 2) >= maximalSize) {
                print[i].push_back(temp) ;
                temp.clear() ;
            } else if (j == msa[i].size()-1) {
                temp += msa[i][j] + std::string(" ", elemSize - msa[i][j].size()) + " " ;
                print[i].push_back(temp) ;
                temp.clear() ;
            } else {
                temp += msa[i][j] + std::string(" ", elemSize - msa[i][j].size()) + " " ;
            }
        }
    }
    std::cout << top << lineBreak << strAlign << lineBreak ;
    for (size_t j=0 ; j<print[0].size() ; j++) {
        for (size_t i=0 ; i<print.size() ; i++) {
            std::string name {"[s" + std::to_string(i) + "]"} ;
            std::cout << tab ;
            std::cout << std::left << std::setw(nameSize+1) << name ;
            std::cout << std::left << std::setw(maximalSize) << print[i][j] ;
            std::cout << " ║\n" ;
        }
        std::cout << lineBreak ;
    }
    std::cout << strScore << lineBreak ;
    std::cout << tab << "file_name      = " << std::left << std::setw(61) << fs.fileName      << "║\n" ;
    std::cout << tab << "exec_time (ms) = " << std::left << std::setw(61) << fs.time          << "║\n" ;
    std::cout << tab << "score_e        = " << std::left << std::setw(61) << fs.score_e       << "║\n" ;
    std::cout << tab << "match_e        = " << std::left << std::setw(61) << fs.match_e       << "║\n" ;
    std::cout << tab << "score_g        = " << std::left << std::setw(61) << fs.score_g       << "║\n" ;
    std::cout << tab << "proj_length    = " << std::left << std::setw(61) << fs.proj_length   << "║\n" ;
    std::cout << tab << "gen_score      = " << std::left << std::setw(61) << fs.general_score << "║\n" ;

    std::cout << lineBreak ;
    std::cout << end ;
}