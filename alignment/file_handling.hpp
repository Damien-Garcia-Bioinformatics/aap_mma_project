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


/// @brief Procedure to transform the line of a file into a trace in the correct format
/// @param Line_String : line that gets formatted
/// @param TraceFormat : a reference to the variable that will stock the info
void read_trace(std::string &, std::vector<std::string> &) ;


/// @brief Procedure that calls read_trace on every line of a file
/// @param PathToFile : path to access the traces
/// @param Expression : keeps the generated expression at hand
/// @param Trace_Vector : the traces are held under this format
void read_file(std::string &, std::string &, vectors &) ;


/// @brief Procedure that fotrmats and write the outpout to a chosen file
/// @param  string : Path to file where to store results.
/// @param  string : Expression used to generate the sequences.
/// @param  vector_vector_string : Mutiple Sequence Alignment result.
void write_results(std::string &, std::string &, vectors &, long) ;


#endif