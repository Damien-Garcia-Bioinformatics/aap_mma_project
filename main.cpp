#include <iostream>
#include "data_generation/generation_functions.hpp"


////////////////////////////////////////////////////////////////////////////////
//                                     Main                                   //
////////////////////////////////////////////////////////////////////////////////

int main() {
	//Initialisation of random function with time seed
	srand(time(NULL)) ;

	// Example of expression passed in program parameters by user
	std::string expression {"E1<(2-6)E8%20|E7X3>E11(2-4)SP95E10"} ;
	// std::string expression {"E1<(2-6)+E8|E7|E9>E11(2-4)SP95E10"} ;

	// Separation and categorisation of different regions in expression
	data sections ;
	expression_divider(expression, sections) ;

	// Extraction of generation parameters
	std::vector<genParam> generation(sections.type.size()) ;
	expression_parser(sections, generation) ;

	// Begin debugging
	for (size_t i=0 ; i<sections.type.size() ; i++) {
		std::cout << "---------------------------" << std::endl ;
		std::cout << "typeSection : " << generation[i].typeSection 	<< std::endl ;
		std::cout << "typeGen     : " << generation[i].typeGen  	<< std::endl ;
		std::cout << "Anchor      : " << generation[i].anchor   	<< std::endl ;
		std::cout << "minSize     : " << generation[i].minSize  	<< std::endl ;
		std::cout << "maxSize     : " << generation[i].maxSize  	<< std::endl ;
		std::cout << "events      : " ;
		for (size_t j=0 ; j<generation[i].events.size() ; j++) {
			std::cout << generation[i].events.at(j) << " " ;
		}
		std::cout << std::endl ;
		std::cout << "attributes  : " ;
		for (size_t j=0 ; j<generation[i].attributes.size() ; j++) {
			std::cout << generation[i].attributes.at(j) << " " ;
		}
		std::cout << std::endl ;
	}
	// End debuggin

	// Generation of traces
	size_t nbTraces {10} ; //Number of traces to generate
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