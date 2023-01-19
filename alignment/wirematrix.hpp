// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB



/* -------------------------------------------------------------------------- */
/*                            Function declaration                            */
/* -------------------------------------------------------------------------- */


#ifndef __WIREMATRIX__
#define __WIREMATRIX__


#include <string>
#include <vector>

#include "structures.hpp"

/// @brief Function returning the cost of a deletion for a given alignment
/// @param Traces_Vector : a reference to the format holding the first sequence
/// @param DelPosition : the position of the deletion in the first sequence
/// @return : the cost of the deletion
float del(vectors &, size_t) ;


/// @brief Function returning the cost of an insertion for a given alignment
/// @param Traces_Vector : a reference to the format holding the second sequence
/// @param InsPosition : the position of the deletion in the second sequence
/// @return : the cost of the insertion
float ins(vectors &, size_t) ;

/// @brief Function returning the cost of a substitution for a given alignment
/// @param Trace1_Vector : a reference to the format holding the first sequence
/// @param Trace2_Vector : a reference to the format holding the second sequence
/// @param Sub1Position : the position of the deletion in the first sequence
/// @param Sub2Position : the position of the deletion in the second sequence
/// @return : the cost of the substitution
float sub(vectors &, vectors &, size_t, size_t) ;

/// @brief Function computing and returning the scoring matrix
/// @param Trace1_Vector : a reference to the format holding the first sequence
/// @param Trace2_Vector : a reference to the format holding the second sequence
/// @return : the completed wire matrix with the cost of each decision
wireMatrix wireMatrix_scoring(vectors &, vectors &) ;

/// @brief Function cleaning the alignment based on the scoring matrix
/// @param WireMatrix : the scoring matrix being sorted through to find the best path
/// @param Trace1_Vector : a reference to the format holding the first sequence
/// @param Trace2_Vector : a reference to the format holding the second sequence
/// @return : the alignment in the right order
vectors pairwiseAlign(wireMatrix &, vectors &, vectors &) ;


#endif