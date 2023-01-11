// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB



/* -------------------------------------------------------------------------- */
/*                            Function declaration                            */
/* -------------------------------------------------------------------------- */



#ifndef __DISSIMILARITY__
#define __DISSIMILARITY__


#include <string>
#include <vector>

#include "structures.hpp"


/// @brief 
/// @param  
/// @return 
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


/// @brief 
/// @param  
/// @param  
/// @param  
void update_msa(msaFormat &, vectors &, std::pair<size_t,size_t> &) ;

/// @brief 
/// @param  
/// @param  
/// @param  
/// @param  
void update_dissimMatrix(dissimMatrix &, msaFormat &, vectors &, std::pair<size_t,size_t> &) ;


#endif