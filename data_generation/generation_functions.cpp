#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include "generation_functions.hpp"
#include "miscellaneous.hpp"

// typeSection : 2
// typeGen     : -
// Anchor      : 
// minSize     : 2
// maxSize     : 6
// events      : E8 E7 
// attributes  : 20 300 


////////////////////////////////////////////////////////////////////////////////
//                                 Functions                                  //
////////////////////////////////////////////////////////////////////////////////

//DONE
void generate_events(genParam &generation, std::vector<std::string> &traces, size_t nbTraces) {
	for (size_t i=0 ; i<nbTraces ; i++) {
		traces.push_back(generation.anchor) ;
	}
}

//DONE
void generate_tops(genParam &generation, std::vector<std::string> &traces, size_t nbTraces) {
	size_t size ;
	std::string subtrace ;
	for (size_t i=0 ; i<nbTraces ; i++) {
		size = randint(generation.minSize, generation.maxSize) ;
		for (size_t j=0 ; j<size ; j++) {
			subtrace += "." ;
		}
		traces.push_back(subtrace) ;
		subtrace.clear() ;
	}
}

// Returns list of traces with between 0 and n events on each trace.
void number_of_event(genParam &generation, vectors &traces, size_t nbTraces, size_t eventChoice) {
	size_t random ;
	size_t size {randint(generation.minSize, generation.maxSize)} ;
	std::vector<std::string> subtrace ;
	for (size_t i=0 ; i<nbTraces ; i++) {
		random = randint(0, generation.attributes[eventChoice]/100) ;
		for (size_t j=0 ; j<random ; j++) {
			subtrace[i].push_back(generation.attributes[eventChoice]) ;
		}
		for (size_t j=0 ; j<(size-random) ; j++) {
			subtrace[i].push_back('.') ;
		}
		shuffle(subtrace) ;
		subtrace.clear() ;
	}
}

// Returns list of traces which n% of those contain the selected event
void percentage_of_event() {

}

// Traces generator
void generate_traces(std::vector<genParam> &generation, vectors &traces, size_t nbTraces) {
	std::vector<std::string> trace ;
	for (size_t i=0 ; i<generation.size() ; i++) {
		switch (generation[i].typeSection) {
			case 0 :
				generate_events(generation[i] , traces[i], nbTraces) ;
				break ;
			case 1 :
				generate_tops(generation[i], traces[i], nbTraces) ;
				break ;
			case 2 : {
				size_t eventChoice  {randint(1, generation[i].events.size())} ;
				if (generation[i].attributes[eventChoice] <= 100) {
					//Percentage of traces
				} else {
					number_of_event(generation[i], traces, nbTraces, eventChoice) ;
				}
				break ;
			}
			default :
				std::cout << "Error" << std::endl ;
		}

		// if (generation[i].typeGen == '-') {
		// 	if (generation[i].attributes[eventChoice] <= 100) {
		// 		//Percentage of traces
		// 		continue ;
		// 	}
		// 	//number_of_events
		// 	continue ;
		// }
		// if (generation[i].typeGen == '*') {
		// 	continue ;
		// }
		// //If typeGen == '+'
	}
}