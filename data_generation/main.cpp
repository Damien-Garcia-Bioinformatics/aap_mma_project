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
	std::cout << "[dataGen] Reading generation parameters from : " << pathToParameters << "\n" ;
	parameters tracesParameters ;
	read_parameters_file(tracesParameters, pathToParameters) ;

	// Initialisation of random function with time seed
	srand(time(NULL)) ;

	// Separation and categorisation of different regions in expression
	std::cout << "[dataGen] Creating sections from expression\n" ;
	data sections ;
	expression_divider(tracesParameters.expression, sections) ;

	// Extraction of generation parameters
	std::cout << "[dataGen] Parsing of expression sections\n" ;
	std::vector<genParam> generation(sections.type.size()) ;
	expression_parser(sections, generation) ;

	// Semantic check of generation parameters
	std::cout << "[dataGen] Checking expression syntax and semantics\n" ;
	check_length(generation, tracesParameters.maxLen) ;
	check_range(generation) ;
	check_anchors_and_events(generation) ;

	// Generation of traces
	std::cout << "[dataGen] Generation of traces\n" ;
	std::vector<std::vector<std::string>> traces(generation.size()) ;
	generate_traces(generation, traces, tracesParameters.nbTraces) ;

	std::cout << "[dataGen] Writing traces to : " << pathToResults << "\n" ;
	write_results(pathToResults, traces, tracesParameters) ;
	
	return 0 ;
}