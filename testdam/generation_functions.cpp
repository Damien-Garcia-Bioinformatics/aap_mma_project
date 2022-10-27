#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "../parser/parsing_functions.hpp"

struct traces {
	// Longueur minimum et maximum
	// Valeur 
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


void generate_tops(size_t minSize, size_t maxSize) {
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
}


int main() {
	srand(time(NULL)) ;
	size_t i {10} ;
	size_t j {5} ;
	std::string trace[i][j] ;
	
	size_t min[5] {1,3,1,7,1} ;
	size_t max[5] {1,8,1,9,1} ;

	for (size_t i=0 ; i<10 ; i++) {
		for (size_t j=0 ; j<5 ; j++) {
			trace[i][j] = generate_tops(min[j],max[j]) ;
		}
	}
	generate_tops(5,10) ;
	return 0 ;
}