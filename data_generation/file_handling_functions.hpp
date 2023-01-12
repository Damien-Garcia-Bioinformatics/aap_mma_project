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
/// @param  Line takes the line to be cleaned
/// @return cleaned line
std::string clean_values(std::string) ;


/// @brief Reads the parameter file and initiate the pram structure that dictates the constraints for generation
/// @param  ParameterStructure the structure that represents the parameters
/// @param  PathToParamFile the path to the parameter file
void read_parameters_file(parameters &, std::string) ;


/// @brief Uses the generated expressions stocked as vectors to write the results in a file
/// @param  PathToOutputFile the path to where the results are written
/// @param  TracesVector generated traces that are iterated upon
/// @param  ParameterStructure gives the order of generations and represents the input expression
void write_results(std::string, vectors &, parameters &) ;


#endif