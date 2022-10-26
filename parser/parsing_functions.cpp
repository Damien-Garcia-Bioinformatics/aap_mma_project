#include "parsing_functions.hpp"


////////////////////////////////////////////////////////////////////////////////
//                           Functions definition                             //
////////////////////////////////////////////////////////////////////////////////


/*
Procedure that extracts minimum and maximum values from interval and stores
these values in generation structure.
*/
void extract_interval(const std::string &expression, genParam &generation) {
	// Extraction of min and max interval values
	size_t separator {expression.find('-')} ;
	generation.minSize = std::stoi(expression.substr(0,separator)) ; //Extraction of min length
	generation.maxSize = std::stoi(expression.substr(separator+1)) ;  //Extraction of max length
}


////////////////////////////////////////////////////////////////////////////////


/*
Procedure that extracts the generation type and stores it in generation
structure.
*/
void extract_type_gen(const std::string &expression, genParam &generation) {
	if (expression[0] == '+' || expression[0] == '*') {
		generation.typeGen = expression[0] ;
	} else {
		generation.typeGen = '-' ;
	}
}


////////////////////////////////////////////////////////////////////////////////


/*
Procedure that extracts potential events and attributes from complex generative
regions and stores them in generation structure.
*/
void extract_events_and_attributes_v2(const std::string &expression, genParam &generation) {
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


////////////////////////////////////////////////////////////////////////////////

/*
Procedure used to create segments of the expression passed in parameter.
3 types of segments are created with respective type identifier :
	- Anchor sections are outside of generative regions.
	  The type identifier is '0'.
	- Simple generative sections are formed by an interval only.
	  The type identifier is '1'.
	- Complex generative sections are formed by an interval, and are supplemented
	  with a generation type, events and attributes.
	  The type identifier is '2'.
*/
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


////////////////////////////////////////////////////////////////////////////////


/*
Procedure used to parse each segment, extract generation parameters and store
them in a structure.
*/
void expression_parser(data &sections, std::vector<genParam> &generation) {
	std::string section ;
	for (int i=0 ; i<sections.type.size() ; i++) {
		section = sections.value.at(i) ;
		switch (sections.type.at(i)) {
			case 0 : { //If the section is an anchor
				generation[i].isAnchor = true ;
				generation[i].anchor = section ;
				generation[i].minSize = 1 ;
				generation[i].maxSize = 1 ;
				generation[i].typeGen = '-' ;
				break ;
			}

			case 1 : { //If the section is a simple generation
				generation[i].isAnchor = false ;
				generation[i].typeGen = '-' ;
				extract_interval(section, generation[i]) ;
				break ;
			}

			case 2 : { //If the section is a complex generation
				generation[i].isAnchor = false ;;
				// Extraction of min and max interval values
				std::string interval {section.substr(1,(section.find(')')-1))} ;
				extract_interval(interval, generation[i]) ;
				
				// Extraction of typeGen parameter
				std::string substring {section.substr(section.find(')')+1)} ;
				extract_type_gen(substring, generation[i]) ;
				// Reformating of the substring 
				if (substring[0] == '+' || substring[0] == '*'){
					substring = substring.substr(1) ; //Deleting first character
				}
				
				// Extraction of potential events and probabilities/number associated
				extract_events_and_attributes_v2(substring, generation[i]) ;
				break ;
			}

			default : {
				exit(1) ;
				break ;
			}
		}
	}	
}