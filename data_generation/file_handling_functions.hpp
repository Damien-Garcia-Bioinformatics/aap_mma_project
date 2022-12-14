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


/// @brief 
/// @param  
/// @return 
std::string clean_values(std::string) ;


/// @brief 
/// @param  
/// @param  
void read_parameters_file(parameters &, std::string) ;


/// @brief 
/// @param  
/// @param  
/// @param  
void write_results(std::string, vectors &, parameters &) ;


#endif