// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB



/* -------------------------------------------------------------------------- */
/*                            Functions declaration                           */
/* -------------------------------------------------------------------------- */


#ifndef __FILE_HANDLING__
#define __FILE_HANDLING__


#include <vector>
#include <string>
#include <fstream>

#include "structures.hpp"


/// @brief Function returning sampled time for an operation
/// @param  PathToFile : path to input file
long get_time(const std::string &) ;


/// @brief Function returning the alignment from a file where it is stocked
/// @param  PathToFile : path to input file
vectors read_align(const std::string &) ;


/// @brief Procedure to write the process' result to a CSV file
/// @param PathToFile : path to output file
/// @param ScoreStructure : structure containing all scores
void write_csv(std::string &, std::vector<scores> &) ;


#endif