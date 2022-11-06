// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


////////////////////////////////////////////////////////////////////////////////
//                                 Data types                                 //
////////////////////////////////////////////////////////////////////////////////


#ifndef __STRUCTURES__
#define __STRUCTURES__


#include <string>
#include <vector>

/**
 * @brief Structure containing data extracted from parameter file. Used for traces generation.
 */
struct parameters {
	std::string expression ;			// Expression used for traces generation
	size_t nbTraces ;					// Number of traces to generate
	size_t maxLen ;						// Maximum length of traces
} ;


/**
 * @brief Structure containing generative parameters extracted from expression sections
 */
struct genParam {
	size_t minSize ;					// Minimum in interval
	size_t maxSize ;					// Maximum in interval
	size_t typeSection ;				// '0', '1' or '2' depending on the section type
	std::string anchor ;				// Anchor name
	char typeGen ;						// '+', '*' or none
	std::vector<std::string> events ;	// List of possible events
	std::vector<int> attributes ;		// List of events attributes
} ;


/**
 * @brief Structure containing sections and type of sections of expression
 */
struct data {
	std::vector<int> type ;				// '0', '1' or '2' depending on the section type
	std::vector<std::string> value ;	// Value of the expression by section
} ;


#endif