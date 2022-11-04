// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


////////////////////////////////////////////////////////////////////////////////
//                           Functions declaration                            //
////////////////////////////////////////////////////////////////////////////////


#ifndef __GENERATION_FUNCTIONS__
#define __GENERATION_FUNCTIONS__


#include <vector>
#include <string>
#include "parsing_functions.hpp"

using vectors = std::vector<std::vector<std::string>> ;


/// @brief Procedure that generates anchors subtraces of n traces (type 0 sections).
/// @param  genParam_structure : Contains data extracted from expression used for traces generation
/// @param  vector_of_strings : Stores traces in sections
/// @param  unsigned_int : number of subtraces to generate
void generate_events(genParam &, std::vector<std::string> &, size_t) ;


/// @brief Procedure that generates simple generative regions (types 1 sections).
/// @param  genParam_structure : Contains data extracted from expression used for traces generation
/// @param  vector_of_strings : Stores traces in sections
/// @param  unsigned_int : number of subtraces to generate
void generate_tops(genParam &, std::vector<std::string> &, size_t) ;


/// @brief Subprocedure that generates complex generative regions (types 2 sections) in typeGen "X" cases.
/// @param  genParam_structure : Contains data extracted from expression used for traces generation
/// @param  vector_of_strings : Stores traces in sections
/// @param  unsigned_int : Number of subtraces to generate
/// @param  unsigned_int : Event and attribute selected for generation
void number_of_event(genParam &, std::vector<std::string> &, size_t, size_t) ;


/// @brief Subprocedure that generates complex generative regions (types 2 sections) in typeGen "%" cases.
/// @param  genParam_structure : Contains data extracted from expression used for traces generation
/// @param  vector_of_strings : Stores traces in sections
/// @param  unsigned_int : Number of subtraces to generate
/// @param  unsigned_int : Event and attribute selected for generation
void percentage_of_event(genParam &, std::vector<std::string> &, size_t, size_t) ;


/// @brief General procedure that generates traces.
/// @param  genParam_structure : Contains data extracted from expression used for traces generation
/// @param  vector_of_strings : Stores traces in sections
/// @param  unsigned_int : number of subtraces to generate
void generate_traces(std::vector<genParam> &, vectors &, size_t) ;


#endif