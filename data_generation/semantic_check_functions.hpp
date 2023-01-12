// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB



/* -------------------------------------------------------------------------- */
/*                            Functions declaration                           */
/* -------------------------------------------------------------------------- */


#ifndef __SEMANTIC_CHECK_FUNCTIONS__
#define __SEMANTIC_CHECK_FUNCTIONS__


#include "parsing_functions.hpp"


/**
 * @brief Function checking if an element exists in a vector.
 * @param  vector_string the elements to be analysed
 * @param  string element to be found
 * @return Boolean value transcribing existence of string in vector.
*/
bool exists_in_vector(const std::vector<std::string> &, std::string &) ;


/**
 * @brief Function cheking availability of events or if it's already used as anchor.
 * @param genParam_structure Contains data extracted from expression used for traces generation.
 * @param vector_string compared elemends in regards to the anchors
 * @return Boolean value transcribing existence of element in vector of element.
 */
bool is_available_event(genParam &, std::vector<std::string> &) ;


/**
 * @brief Procedure checking if range is in min-max format and not inverted, allows to avoid an error
 * @param GeneratorStructure interval that is checked
 */
void check_range(std::vector<genParam> &) ;


/**
 * @brief Procedure checking if interval of generation is contained in maximum of length of traces to generate.
 * @param  genParam_structure Contains data extracted from expression used for traces generation.
 * @param  unsigned_int Value of traces maximum length.
 */
void check_length(std::vector<genParam> &, size_t) ;


/**
 * @brief Procedure cheking uniqueness of anchors and disponibility of events in generative regions.
 * @param  genParam_structure Contains data extracted from expression used for traces generation.
 */
void check_anchors_and_events(std::vector<genParam> &) ;


#endif