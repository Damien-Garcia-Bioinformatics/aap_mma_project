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


void complex_generation(genParam &generation) {
	size_t eventChoice {randint(1,generation.events.size())} ;
	std::cout << eventChoice << std::endl ;

}


/*
Function to generate traces 
*/
void generate_traces(std::vector<genParam> &generation, std::vector<std::vector<std::string>> &traces, size_t nbTraces) {
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