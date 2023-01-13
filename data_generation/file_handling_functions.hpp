// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB



/* -------------------------------------------------------------------------- */
/*                            Functions declaration                           */
/* -------------------------------------------------------------------------- */


#ifndef __FILE_HANDLING_FUNCTIONS__
#define __FILE_HANDLING_FUNCTIONS__


#include <string>
#include <vector>

#include "structures.hpp"


using vectors = std::vector<std::vector<std::string>> ;


/// @brief Allows to clean up the input file by not considering comments and removing spaces
/// @param  Line Line to clean
/// @return Cleaned line
std::string clean_values(std::string) ;


/// @brief Reads the parameter file and initiate the param structure that dictates the constraints for generation
/// @param  ParameterStructure The structure containing the parameters
/// @param  PathToParamFile Path to the parameter file
void read_parameters_file(parameters &, std::string) ;


/// @brief Uses the generated expressions stocked as vectors to write the results in a file
/// @param  PathToOutputFile Path to where the results are written
/// @param  TracesVector Generated traces that are iterated upon
/// @param  ParameterStructure Gives the order of generations and represents the input expression
void write_results(std::string, vectors &, parameters &) ;


#endif