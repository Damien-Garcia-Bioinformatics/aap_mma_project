// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


////////////////////////////////////////////////////////////////////////////////
//                           Functions declaration                            //
////////////////////////////////////////////////////////////////////////////////


#ifndef __SEMANTIC_CHECK_FUNCTIONS__
#define __SEMANTIC_CHECK_FUNCTIONS__


#include "parsing_functions.hpp"


/// @brief Function checking if interval of generation is contained in maximum of length of traces to generate.
/// @param  genParam_structure : Contains data extracted from expression used for traces generation.
/// @param  unsigned_int : Value of traces maximum length.
void check_length(std::vector<genParam> &, size_t) ;


/// @brief 
/// @param  
/// @param  
/// @return 
bool is_identical_anchors(const std::vector<std::string> &, std::string &) ;


/// @brief 
/// @param  
/// @param  
/// @return 
bool is_available_event(genParam &, std::vector<std::string> &) ;


/// @brief 
/// @param  
void check_anchors_and_events(std::vector<genParam> &) ;


/// @brief 
/// @param  
/// @param  
void execute_semantic_check(std::vector<genParam> &, size_t) ;


#endif