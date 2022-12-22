// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


////////////////////////////////////////////////////////////////////////////////
//                            Function declaration                            //
////////////////////////////////////////////////////////////////////////////////


#ifndef __WIREMATRIX__
#define __WIREMATRIX__


#include <string>
#include <vector>

#include "structures.hpp"


/// @brief 
/// @param  
/// @return 
size_t del(std::string) ;


/// @brief 
/// @param  
/// @return 
size_t ins(std::string) ;


/// @brief 
/// @param  
/// @param  
/// @return 
size_t sub(std::string, std::string ) ;


/// @brief
/// @param
/// @param
/// @param
/// @return
size_t min(size_t, size_t, size_t) ;


/// @brief 
/// @param  
/// @param  
/// @return 
wireMatrix wireMatrix_scoring(traceFormat &, traceFormat &) ;


void pairwiseAlign(wireMatrix &, traceFormat &, traceFormat &) ;

#endif