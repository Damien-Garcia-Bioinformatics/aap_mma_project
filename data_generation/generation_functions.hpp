#include <vector>
#include <string>
#include "parsing_functions.hpp"

using vectors = std::vector<std::vector<std::string>> ;

/*
Generation of type 1 sections
*/
void generate_tops(genParam&, std::vector<std::string>&, size_t) ;

/*
General function for traces generation
*/
void generate_traces(std::vector<genParam>&, vectors&, size_t) ;

void complex_generation(genParam&, vectors&, size_t) ;