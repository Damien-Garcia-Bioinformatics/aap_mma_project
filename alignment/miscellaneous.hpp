// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB



/* -------------------------------------------------------------------------- */
/*                            Function declaration                            */
/* -------------------------------------------------------------------------- */


#ifndef __MISCELLANEOUS__
#define __MISCELLANEOUS__


#include <string>
#include <vector>

#include "structures.hpp"


/// @brief Procedure that prints the alignment to screen
/// @param Traces_Vector : a reference to the format holding the sequences
void print_alignment(vectors &) ;


/// @brief Enhanced procedure that shows alignments in a more orderly manner
/// @param Traces_Vector : a copy of the format holding the sequences
void print_alignment_v2(vectors) ;


/// @brief Procedure showing the content of a wire matrix on screen
/// @param  WireMatrix : referenced double vector format of floats
void print_wirematrix(wireMatrix &) ;


/// @brief Procedure that prints the dissimilarity matrix, of which only the last part of the wire matrix is shown
/// @param  DissimilarityMatrix : triangle matrix of alignments
void print_dissimMatrix(dissimMatrix &) ;


#endif