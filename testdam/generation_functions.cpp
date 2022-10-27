#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "../parser/parsing_functions.hpp"

struct traces {
	
} ;

/*
Extracted data from generation structure :
isAnchor,
anchor,
minSize,
maxSize,
events,
attributes
*/


std::vector<std::string> generate_tops(size_t minSize, size_t maxSize) {
	// Creation of initial vector
    size_t size {random()%(maxSize-minSize)+minSize} ;
	std::vector<std::string> traceSection(size) ;

	// Filling vector with "tops"
	for (int i=0 ; i<traceSection.size() ; i++) {
		traceSection.at(i).push_back('.') ;
	}
	
// 	for (int i=0 ; i<traceSection.size() ; i++) {
// 		std::cout << traceSection.at(i) ;
// 	}
// 	std::cout << std::endl ;
	return traceSection ;
}


int main() {
	srand(time(NULL)) ;
	std::vector<std::string> result {generate_tops(10,20)} ;
	for (int i=0 ; i<result.size() ; i++) {
		std::cout << result.at(i) ;
	}
	std::cout << std::endl ;
	return 0 ;
}