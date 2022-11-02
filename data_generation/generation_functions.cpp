#include <iostream>
#include "generation_functions.hpp"
#include "miscellaneous.hpp"


////////////////////////////////////////////////////////////////////////////////
//                           Functions definition                             //
////////////////////////////////////////////////////////////////////////////////


void generate_events(genParam &generation, std::vector<std::string> &subtraces, size_t nbTraces) {
	for (size_t i=0 ; i<nbTraces ; i++) {
		std::string subtrace {generation.anchor + " "} ;
		subtraces.push_back(subtrace) ;
	}
}


////////////////////////////////////////////////////////////////////////////////


void generate_tops(genParam &generation, std::vector<std::string> &subtraces, size_t nbTraces) {
	size_t size ;

	// Generation of section
	std::string subtrace ;
	for (size_t i=0 ; i<nbTraces ; i++) {
		size = randint(generation.minSize, generation.maxSize) ;
		for (size_t j=0 ; j<size ; j++) {
			subtrace += ". " ;
		}
		subtraces.push_back(subtrace) ;
		subtrace.clear() ;
	}
}


////////////////////////////////////////////////////////////////////////////////


void number_of_event(genParam &generation, std::vector<std::string> &subtraces, size_t nbTraces, size_t eventChoice) {
	// Selection of min and max number of event in section depending on generation type '+' or '*'
	size_t min = (generation.typeGen == '+') ? 1 : 0 ;
	size_t max = (generation.attributes[eventChoice] == 0) ? generation.attributes[eventChoice]/100 : generation.maxSize ;
	
	// Generation of section
	std::vector<std::string> subtrace ;
	for (size_t i=0 ; i<nbTraces ; i++) {
		size_t size {randint(generation.minSize, generation.maxSize)} ;
		size_t random {randint(min, max)} ;
		for (size_t j=0 ; j<random ; j++) {
			subtrace.push_back(generation.events[eventChoice]) ;	
		}
		for (size_t j=0 ; j<(size-random) ; j++) {
			subtrace.push_back(".") ;
		}
		shuffle(subtrace) ; // Randomisation of event position in section using shuffle algorithm

		// Creation of single string section format 
		std::string trace ;
		for (size_t j=0 ; j<subtrace.size() ; j++) {
			trace += subtrace[j] + " " ;
		}
		subtraces.push_back(trace) ;
		subtrace.clear() ;
		trace.clear() ;
	}
}


////////////////////////////////////////////////////////////////////////////////


// Returns list of traces which n% of those contain the selected event
void percentage_of_event(genParam &generation, std::vector<std::string> &subtraces, size_t nbTraces, size_t eventChoice) {
	// Defines the number of traces that will contain the selected event
	size_t containsEvent {generation.attributes[eventChoice]*nbTraces/100} ;

	// Generation of section
	std::vector<std::string> subtrace ;
	for (size_t i=0 ; i<nbTraces ; i++) {
		size_t size {randint(generation.minSize, generation.maxSize)} ;
		size_t random {randint(1, size)} ;

		// Creation of n% of traces containing events
		if (i < containsEvent) {	
			for (size_t j=0 ; j<random ; j++) {
				subtrace.push_back(generation.events[eventChoice]) ;
			}
			for (size_t j=0 ; j<(size_t(size-random)) ; j++) {
				subtrace.push_back(".") ;
			}
			shuffle(subtrace) ;
		
		// Creation of 100-n% traces not containing events
		} else {
			for (size_t j=0 ; j<size ; j++) {
				subtrace.push_back(".") ;
			}
		}
		
		// Creation of single string section format 
		std::string trace ;
		for (size_t j=0 ; j<subtrace.size() ; j++) {
			trace += subtrace[j] + " " ;
		}
		subtraces.push_back(trace) ;
		subtrace.clear() ;
		trace.clear() ;
	}
}


////////////////////////////////////////////////////////////////////////////////


// Traces generator
void generate_traces(std::vector<genParam> &generation, vectors &traces, size_t nbTraces) {
	std::vector<std::string> trace ;
	for (size_t i=0 ; i<generation.size() ; i++) {
		switch (generation[i].typeSection) {
			case 0 : { // Generation of type 0 sections (anchors)
				generate_events(generation[i] , traces[i], nbTraces) ;
				break ;
			}
			case 1 : { // Generation of type 1 sections (simple generative regions)
				generate_tops(generation[i], traces[i], nbTraces) ;
				break ;
			}
			case 2 : { // Generation of type 2 sections (complex generative regions)
				size_t eventChoice {randint(0, generation[i].events.size())} ;
				if (generation[i].attributes[eventChoice] <= 100) {
					percentage_of_event(generation[i], traces[i], nbTraces, eventChoice) ;
				} else {
					number_of_event(generation[i], traces[i], nbTraces, eventChoice) ;
				}
				break ;
			}
			default : { // Error case (shouldn't happen at this point because of syntax/semantic checking)
				exit(2) ;
			}
		}
	}
}