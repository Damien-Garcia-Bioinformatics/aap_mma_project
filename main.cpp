// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


////////////////////////////////////////////////////////////////////////////////
//                                     Main                                   //
////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include "data_generation/parsing_functions.hpp"
#include "data_generation/semantic_check_functions.hpp"
#include "data_generation/generation_functions.hpp"
#include "data_generation/miscellaneous.hpp"


int main() {
	// Initialisation of random function with time seed
	srand(time(NULL)) ;

	// Initialisation of maximum length
	size_t maxLen {30} ;

	// Example of expression passed in program parameters by user
	std::string expression {"(2-3)E1<(4-8)e2X10|E2%25>E2(2-4)E3<(2-5)e1%40>"} ;

	// Separation and categorisation of different regions in expression
	data sections ;
	expression_divider(expression, sections) ;

	// Extraction of generation parameters
	std::vector<genParam> generation(sections.type.size()) ;
	expression_parser(sections, generation) ;

	// Semantic check of generation parameters
	check_length(generation, maxLen) ;
	check_anchors_and_events(generation) ;

	// // Begin debugging
	// for (size_t i=0 ; i<sections.type.size() ; i++) {
	// 	std::cout << "---------------------------" << std::endl ;
	// 	std::cout << "typeSection : " << generation[i].typeSection 	<< std::endl ;
	// 	std::cout << "typeGen     : " << generation[i].typeGen  	<< std::endl ;
	// 	std::cout << "Anchor      : " << generation[i].anchor   	<< std::endl ;
	// 	std::cout << "minSize     : " << generation[i].minSize  	<< std::endl ;
	// 	std::cout << "maxSize     : " << generation[i].maxSize  	<< std::endl ;
	// 	std::cout << "events      : " ;
	// 	for (size_t j=0 ; j<generation[i].events.size() ; j++) {
	// 		std::cout << generation[i].events.at(j) << " " ;
	// 	}
	// 	std::cout << std::endl ;
	// 	std::cout << "attributes  : " ;
	// 	for (size_t j=0 ; j<generation[i].attributes.size() ; j++) {
	// 		std::cout << generation[i].attributes.at(j) << " " ;
	// 	}
	// 	std::cout << std::endl ;
	// }
	// // End debuggin

	// Generation of traces
	size_t nbTraces {20} ; //Number of traces to generate
	std::vector<std::vector<std::string>> traces(generation.size()) ;
	generate_traces(generation, traces, nbTraces) ;
	
	// Begin debugging
	for (size_t i=0 ; i<nbTraces ; i++) {
		for (size_t j=0 ; j<traces.size() ; j++) {
			std::cout << traces[j][i] ;
		}
		std::cout << std::endl ;
	}
	// End debugging
	
	return 0 ;
}