// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB



/* -------------------------------------------------------------------------- */
/*                            Functions declaration                           */
/* -------------------------------------------------------------------------- */


#ifndef __READ_TRACES__
#define __READ_TRACES__


#include <string>
#include <vector>
#include <string>
#include <vector>

#include "structures.hpp"


/// @brief 
/// @param  
/// @param  
void read_trace(std::string &, std::vector<std::string> &) ;


/// @brief 
/// @param  
/// @param  
/// @param  
void read_file(std::string &, std::string &, vectors &) ;


/// @brief 
/// @param  string : Path to file where to store results.
/// @param  string : Expression used to generate the sequences.
/// @param  vector_vector_string : Mutiple Sequence Alignment result.
void write_results(std::string &, std::string &, vectors &, long) ;


#endif