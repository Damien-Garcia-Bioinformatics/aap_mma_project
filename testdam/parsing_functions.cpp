#include <iostream>
#include <string>
#include <vector>

////////////////////////////////////////////////////////////////////
//                           Data types                           //
////////////////////////////////////////////////////////////////////

struct genParam {
	bool isAnchor ;
	std::string anchor ;
	int minSize ;
	int maxSize ;
	char typeGen ;
	// std::vector<bool> isXtimes ;
	std::vector<std::string> events ;
	std::vector<int> attributes ;
} ;

struct data {
	std::vector<int> type ;
	std::vector<std::string> value ;
} ;

////////////////////////////////////////////////////////////////////
//                           Functions                            //
////////////////////////////////////////////////////////////////////

void extract_simple_region_parameters(std::string &expression, genParam &generation) {
	// Extraction of min and max interval values
	size_t separator {expression.find('-')} ;
	generation.minSize = std::stoi(expression.substr(0,separator)) ; //Extraction of min length
	generation.maxSize = std::stoi(expression.substr(separator+1)) ;  //Extraction of max length
}

//--------------------------------------------------------------------------//

void extract_type_gen(std::string &expression, genParam &generation) {
	if (expression[0] == '+' || expression[0] == '*') {
		generation.typeGen = expression[0] ;
	} else {
		generation.typeGen = '-' ;
	}
}

//--------------------------------------------------------------------------//

void extract_events_and_attributes_v2(std::string &expression, genParam &generation) {
	bool isEvent {true} ;
	bool isXtimes {false} ;
	std::string event ;
	std::string attribute ;
	for (int i=0 ; i<expression.size() ; i++) {
		if (expression[i] == '%') {
			isEvent = false ;
			isXtimes = false ;
		} else if (expression[i] == 'X') {
			isEvent = false ;
			isXtimes = true ;
		} else {
			if (expression[i] != '|') {
				if (isEvent) {
					event += expression[i] ;
				} else {
					attribute += expression[i] ;
				}
			}
		}
		if (expression[i] == '|' || i==expression.size()-1) {
			isEvent = true ;
			generation.events.push_back(event) ;
			event.clear() ;
			if (isXtimes) {
				// generation.isXtimes.push_back(true) ;
				generation.attributes.push_back(std::stoi(attribute)*100) ;
				attribute.clear() ;
			} else {
				// generation.isXtimes.push_back(false) ;
				if (attribute.empty()) {
					generation.attributes.push_back(100) ;
				} else {
					generation.attributes.push_back(std::stoi(attribute)) ;
					attribute.clear() ;
				}
			}
		}
	}
}

//--------------------------------------------------------------------------//

void parse_complex_region(std::string &expression, genParam &generation) {
	// Extraction of min and max interval values
	std::string interval {expression.substr(1,(expression.find(')')-1))} ;
	extract_simple_region_parameters(interval, generation) ;
	
	// Extraction of typeGen parameter
	std::string substring {expression.substr(expression.find(')')+1)} ;
	extract_type_gen(substring, generation) ;
	// Reformating of the substring 
	if (substring[0] == '+' || substring[0] == '*'){
		substring = substring.substr(1) ; //Deleting first character
	}
	// Extraction of potential events and probabilities/number associated
	extract_events_and_attributes_v2(substring, generation) ;
}

//--------------------------------------------------------------------------//

void expression_divider(std::string &expression, data &sections) {
	bool isAnchor ;
	bool isSimpleGen ;
	std::string section ;

	for (int i=0 ; i<expression.size() ; i++) {
		if (expression[i] == '<') {
			isAnchor = false ;
			isSimpleGen = false ;
			sections.value.push_back(section) ;
			sections.type.push_back(0) ;
			section.clear() ;
		} else if (expression[i] == '(' && isAnchor) {
			isAnchor = false ;
			isSimpleGen = true ;
			sections.value.push_back(section) ;
			sections.type.push_back(0) ;
			section.clear() ;
		} else if (expression[i] == ')' && isSimpleGen) {
			isAnchor = true ;
			sections.value.push_back(section) ;
			sections.type.push_back(1) ;
			section.clear() ;
		} else if (expression[i] == '>') {
			isAnchor = true ;
			sections.value.push_back(section) ;
			sections.type.push_back(2) ;
			section.clear() ;
		} else {
			section += expression[i] ;
		}
	}
	// Last section push back
	if (isAnchor) {
		sections.type.push_back(0) ;
	} else if (!isAnchor && isSimpleGen) {
		sections.type.push_back(1) ;
	} else {
		sections.type.push_back(2) ;
	}
	sections.value.push_back(section) ;
}


////////////////////////////////////////////////////////////////////
//                             Main                               //
////////////////////////////////////////////////////////////////////

int main() {
	// Example of expression passed in program parameters by user
	std::string expression {"E1<(2-6)E8%20|E7X3>E11(2-4)SP95E10"} ;
	// std::string expression {"E1<(2-6)+E8|E7|E9>E11(2-4)SP95E10"} ;

	// Separation and categorisation of different regions in expression
	data sections ;
	expression_divider(expression, sections) ;

	// Extraction of generation parameters
	genParam generation[sections.type.size()] ;
	for (int i=0 ; i<sections.type.size() ; i++) {
		switch (sections.type.at(i)) {
			case 0 :
				generation[i].isAnchor = true ;
				generation[i].anchor = sections.value.at(i) ;
				generation[i].minSize = 1 ;
				generation[i].maxSize = 1 ;
				generation[i].typeGen = '-' ;
				// generation[i].events.push_back('none') ;
				// generation[i].attributes = 0 ;
				break ;
			case 1 :
				generation[i].isAnchor = false ;
				generation[i].typeGen = '-' ;
				extract_simple_region_parameters(sections.value.at(i), generation[i]) ;
				break ;
			case 2 :
				generation[i].isAnchor = false ;
				parse_complex_region(sections.value.at(i), generation[i]) ;
				break ;
			default :
				std::cout << "Mistakes were made..." << std::endl ;
				break ;
		}
	}

	// Debugging
	for (int i=0 ; i<sections.type.size() ; i++) {
		std::cout << "---------------------------" << std::endl ;
		std::cout << "isAnchor   : " << generation[i].isAnchor << std::endl ;
		std::cout << "typeGen    : " << generation[i].typeGen  << std::endl ;
		std::cout << "Anchor     : " << generation[i].anchor   << std::endl ;
		std::cout << "minSize    : " << generation[i].minSize  << std::endl ;
		std::cout << "maxSize    : " << generation[i].maxSize  << std::endl ;
		std::cout << "events     : " ;
		for (int j=0 ; j<generation[i].events.size() ; j++) {
			std::cout << generation[i].events.at(j) << " " ;
		}
		std::cout << std::endl ;
		std::cout << "attributes : " ;
		for (int j=0 ; j<generation[i].attributes.size() ; j++) {
			std::cout << generation[i].attributes.at(j) << " " ;
		}
		std::cout << std::endl ;
	}
	

	return 0 ;
}