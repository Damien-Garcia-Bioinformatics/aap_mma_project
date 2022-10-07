#include <string>


// string composition for parsing
struct input_parse 
{
	// to explain what this does, let's take an input example :" E1<(2-5)+E3|E4>E2" 
	
	// this extracts the anchors, main components driving the genes, here E1,E2
	std::string element_anchors;

	// this extracts intervals of entities to repeat motifs
	std::string query_intervals;

	// this extracts the condition of expansion, + or * 
	std::string expansion_sign;

	// this extracts the elements to repeats inbetween anchors
	std::string expansion_component;

	// the lenght of expansion_sign should be the same as the number of <queries>, with a placeholder
	// "." for example
}

// the struct might not be the best choice for this task, as internal methods will be called
// directly on the data. An object might make it easier
