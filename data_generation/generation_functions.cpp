#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
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


// Returns list of traces with between 0 and n events on each trace.
void number_of_event(genParam &generation, std::vector<std::string> &subtraces, size_t nbTraces, size_t eventChoice) {
	size_t min = (generation.typeGen == '+') ? 1 : 0 ;
	size_t max = (generation.attributes[eventChoice] == 0) ? generation.attributes[eventChoice]/100 : generation.maxSize ;
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
		shuffle(subtrace) ; // Randomisation of event position in section
		std::string trace ;
		for (size_t i=0 ; i<subtrace.size() ; i++) {
			trace += subtrace[i] + " " ;
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
	std::vector<std::string> subtrace ;
	for (size_t i=0 ; i<nbTraces ; i++) {
		size_t size {randint(generation.minSize, generation.maxSize)} ;
		if (i < containsEvent) {
			size_t random {randint(1, size)} ;
			std::cout << size << "  " << random << std::endl ;
			for (size_t j=0 ; j<random ; j++) {
				subtrace.push_back(generation.events[eventChoice]) ;
			}
			for (size_t j=0 ; j<(size-random) ; j++) {
				subtrace.push_back(".") ;
			}
		} else {
			std::cout << "test" << std::endl ;
			for (size_t j=0 ; j<size ; j++) {
				subtrace.push_back(".") ;
			}
		}
		std::string trace ;
		for (size_t j=0 ; j<subtrace.size() ; j++) {
			trace += subtrace[i] + " " ;
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
			case 0 :
				generate_events(generation[i] , traces[i], nbTraces) ;
				break ;
			case 1 :
				generate_tops(generation[i], traces[i], nbTraces) ;
				break ;
			case 2 : {
				size_t eventChoice {randint(0, generation[i].events.size())} ;
				if (generation[i].attributes[eventChoice] <= 100) {
					percentage_of_event(generation[i], traces[i], nbTraces, eventChoice) ;
				} else {
					number_of_event(generation[i], traces[i], nbTraces, eventChoice) ;
				}
				break ;
			}
			default :
				exit(2) ;
		}
	}
}