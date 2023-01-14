// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB



/* -------------------------------------------------------------------------- */
/*                            Functions declaration                           */
/* -------------------------------------------------------------------------- */


#ifndef __SCORING_FUNCTIONS__
#define __SCORING_FUNCTIONS__


#include <map>

#include "structures.hpp"


/// @brief 
/// @param  
/// @param  
/// @return 
elemAtPos map_position(const vectors &, size_t) ;


/// @brief 
/// @param  
/// @return 
size_t score_e(const vectors &) ;


/// @brief 
/// @param  
/// @return 
size_t match_e(const vectors &) ;


/// @brief 
/// @param  
/// @return 
size_t score_g(const vectors &) ;


/// @brief 
/// @param  
/// @return 
size_t proj_length(const vectors &) ;


/// @brief 
/// @param  
/// @return 
float general_score(const vectors &) ;


/// @brief 
/// @param  
void print_results(const std::vector<scores> &) ;


/// @brief 
/// @param  
/// @param  
/// @return 
scores measure_scores(const std::string &, const vectors &) ;


#endif