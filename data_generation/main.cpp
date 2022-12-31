// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


////////////////////////////////////////////////////////////////////////////////
//                                     Main                                   //
////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include "file_handling_functions.hpp"
#include "parsing_functions.hpp"
#include "semantic_check_functions.hpp"
#include "generation_functions.hpp"
#include "miscellaneous.hpp"


int main(int argc, char *argv[]) {
	// Check if paths of parameter and result files are provided.
	if (argc == 1) {
		help() ;
		exit(1) ;
	}
	std::string pathToParameters {argv[1]}, pathToResults {argv[2]} ;

	// Reading generation parameters from file passed in program command line parameter.
	std::cout << "[main] Reading generation parameters from : " << pathToParameters << std::endl ;
	parameters tracesParameters ;
	read_parameters_file(tracesParameters, pathToParameters) ;

	// Initialisation of random function with time seed
	srand(time(NULL)) ;

	// Separation and categorisation of different regions in expression
	std::cout << "[main] Creating sections from expression" << std::endl ;
	data sections ;
	expression_divider(tracesParameters.expression, sections) ;

	// Extraction of generation parameters
	std::cout << "[main] Parsing of expression sections" << std::endl ;
	std::vector<genParam> generation(sections.type.size()) ;
	expression_parser(sections, generation) ;

	// Semantic check of generation parameters
	std::cout << "[main] Checking expression syntax and semantics" << std::endl ;
	check_length(generation, tracesParameters.maxLen) ;
	check_range(generation) ;
	check_anchors_and_events(generation) ;

	// Generation of traces
	std::cout << "[main] Generation of traces" << std::endl ;
	std::vector<std::vector<std::string>> traces(generation.size()) ;
	generate_traces(generation, traces, tracesParameters.nbTraces) ;

	std::cout << "[main] Writing traces to : " << pathToResults << std::endl ;
	write_results(pathToResults, traces, tracesParameters) ;
	
	return 0 ;
}