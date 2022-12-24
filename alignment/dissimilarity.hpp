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


msaFormat generate_msa(vectors &) ;


/// @brief
/// @param
/// @return 
dissimMatrix generate_dissimilarity_matrix(msaFormat &) ;

/// @brief 
/// @param  
/// @param 
/// @return
std::pair<size_t,size_t> find_lowest_dissim(dissimMatrix &) ;


/// @brief 
/// @param  
/// @param  
void update_matrix(dissimMatrix &, std::pair<size_t,size_t>) ;


void print_dissimMatrix(dissimMatrix &) ;


#endif