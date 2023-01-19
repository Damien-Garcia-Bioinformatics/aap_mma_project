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


/// @brief Function that returns the elements at a stated position
/// @param AlignedTraces : scored traces
/// @param StartingPosition : position initializing the search
/// @return the elements at the specified position
elemAtPos map_position(const vectors &, size_t) ;


/// @brief Function that returns the event score
/// @param AlignedTraces : scored traces
/// @return ScoreEvent
size_t score_e(const vectors &) ;


/// @brief Function that returns the event matching score
/// @param AlignedTraces : scored traces
/// @return ScoreMatch
size_t match_e(const vectors &) ;


/// @brief Function that returns the gap score
/// @param AlignedTraces : scored traces
/// @return GapsScore
size_t score_g(const vectors &) ;


/// @brief Function that returns the length of the projection of an alignment
/// @param AlignedTraces : scored traces
/// @return legnth to be considered
size_t proj_length(const vectors &) ;


/// @brief Function that returns the general score using all precedents
/// @param AlignedTraces : scored traces
/// @return a score resuming all precedent
float general_score(const vectors &) ;


/// @brief it prints results
/// @param  unmodifiableScores
void print_results(const std::vector<scores> &) ;


/// @brief Function returning the structure holding all scores
/// @param FilePath : path to parameter file
/// @param AlignedTraces : scored traces
/// @return score format
scores measure_scores(const std::string &, const vectors &) ;


#endif