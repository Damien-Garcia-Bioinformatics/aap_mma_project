// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


/////////////////////////////////////////////////////////////////////////////////
//                           Functions declaration                             //
/////////////////////////////////////////////////////////////////////////////////


#ifndef __SCORING_FUNCTIONS__
#define __SCORING_FUNCTIONS__

#include <map>

#include "../alignment/structures.hpp"


using elemAtPos = std::map<std::string,size_t> ;


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


#endif