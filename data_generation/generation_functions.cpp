#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include "generation_functions.hpp"
#include "miscellaneous.hpp"

/*
Function 
*/
std::string generate_tops(size_t minSize, size_t maxSize) {
	size_t size {randint(minSize, maxSize)} ;
	std::string subtrace(size,'.') ;
	return subtrace ;
}


// typeSection : 2
// typeGen     : -
// Anchor      : 
// minSize     : 2
// maxSize     : 6
// events      : E8 E7 
// attributes  : 20 300 

// Returns the choosen event and attribute index
int event_choice(genParam &generation) {
	return(randint(1, generation.events.size()) ;
}

void percentage_of_traces() {

}

void number_of_event(std::vector<std::vector<std::string>> &traces, size_t nbTraces, std::string event, int attribute) {
	for (int i=0 ; i<nbTraces ; i++) {
		
	}
}

void complex_generation(const genParam &generation, std::vector<std::vector<std::string>> &traces, size_t nbTraces) {
	int eventChoice {event_choice(generation)} ;
	std::string event {generation.event.at(eventChoice)} ;
	int attribute {generation.attributes.at(eventChoice)} ;

	//Creation of the n traces using the event and attribute selected randomly
	

	// if (generation.typeGen == '-') {
	// 	if (generation.attributes[eventChoice] <= 100) {
	// 		percentage_of_traces() ;
	// 	}
	// 	number_of_event() ;
	// } else if (generation.typeGen == '+') {
	// 	//Code
	// } else {
	// 	//Code
	// }
}



/*
Function to generate traces 
*/
void generate_traces(const std::vector<genParam> &generation, std::vector<std::vector<std::string>> &traces, size_t nbTraces) {
	std::vector<std::string> trace ;
	for (size_t i=0 ; i<generation.size() ; i++) {
		for (size_t j=0 ; j<nbTraces ; j++) {
			if (generation[i].typeSection == 0 ) {
				traces[i].push_back(generation[i].anchor) ;
			} else if (generation[i].typeSection == 1) {
				traces[i].push_back(generate_tops(generation[i].minSize, generation[i].maxSize)) ;
			} else if (generation[i].typeSection == 2) {
				traces[i].push_back(generate_tops(generation[i].minSize, generation[i].maxSize)) ;
				complex_generation(generation[i]) ;
			}
		}
	}
}