// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


////////////////////////////////////////////////////////////////////////////////
//                            Function declaration                            //
////////////////////////////////////////////////////////////////////////////////


#ifndef __DISSIMILARITY__
#define __DISSIMILARITY__


#include <iostream>
#include <string>
#include <vector>

#include "structures.hpp"


/// @brief
/// @param
/// @return 
dissimMatrix generate_dissimilarity_matrix(vectors &) ;


/// @brief 
/// @param  
/// @param 
/// @return
std::pair<size_t,size_t> find_lowest_dissim(dissimMatrix &, vectors &) ;


/// @brief 
/// @param  
/// @param  
void update_matrix(dissimMatrix &, std::pair<size_t,size_t>) ;



#endif