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


/// @brief Function that returns the sequences in the format necessary for alignment
/// @param  Sequence_List a vector of traces to be transformed into the right data format
/// @return MSA_Structure to be completed upon further iterations
msaFormat generate_msa(vectors &) ;


/// @brief Function that builds the dissimilarity matrix from the sequences in the given structure
/// @param MSA_Structure structure comprising the sequences and allowing for alignment
/// @return DissimilarityMatrix accounting for all remaining alignments
dissimMatrix generate_dissimilarity_matrix(msaFormat &) ;


/// @brief Function that returns the position of the lowest score in the dissimilarity matrix
/// @param  DissimilarityMatrix accounting for all remaining alignments
/// @return X/Ycoordinates of lowest score in the triangular matrix
std::pair<size_t,size_t> find_lowest_dissim(dissimMatrix &) ;


/// @brief Placeholder function replaced by update_dissiMatrix
/// @param  DissimilarityMatrix accounting for all remaining alignments
/// @param  Coordinates of lowest score in the triangular matrix
void update_matrix(dissimMatrix &, std::pair<size_t,size_t>) ;


/// @brief Procedure to update the MSA structure by removing the aggregated traces
/// @param MSA_Structure to be updated
/// @param Aligned_sequence that replaces the position below
/// @param Coordinates of lowest score
void update_msa(msaFormat &, vectors &, std::pair<size_t,size_t> &) ;

/// @brief Procedure that removes the lines and columns of the dissimilarity matrix
/// @param DissimilarityMatrix accounting for all remaining alignments
/// @param MSA_Structure of the current alignment
/// @param Aligned_sequence that replaces the position below
/// @param Coordinates of lowest score in the triangular matrix 
void update_dissimMatrix(dissimMatrix &, msaFormat &, vectors &, std::pair<size_t,size_t> &) ;


#endif