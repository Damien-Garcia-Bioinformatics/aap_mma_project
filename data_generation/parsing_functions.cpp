// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB



/* -------------------------------------------------------------------------- */
/*                            Functions definition                            */
/* -------------------------------------------------------------------------- */


#include <iostream>

#include "parsing_functions.hpp"


/* ---------------------------- EXTRACT-INTERVAL ---------------------------- */


// Procedure that extracts minimum and maximum values from interval and stores these values in generation structure.
void extract_interval(const std::string &expression, genParam &generation) {
	// Extraction of min and max interval values
	size_t separator {expression.find('-')} ;
	generation.minSize = std::stoi(expression.substr(0,separator)) ; //Extraction of min length
	generation.maxSize = std::stoi(expression.substr(separator+1)) ; //Extraction of max length
}


/* ---------------------------- EXTRACT-TYPE-GEN ---------------------------- */


// Procedure that extracts the generation type and stores it in generation structure.
void extract_type_gen(const std::string &expression, genParam &generation) {
	if (expression[0] == '+' || expression[0] == '*') {
		generation.typeGen = expression[0] ;
	} else {
		generation.typeGen = '-' ;
	}
}


/* ---------------------- EXTRACT-EVENTS-AND-ATTRIBUTES --------------------- */


// Procedure that extracts potential events and attributes from complex generative
// regions and stores them in generation structure.
void extract_events_and_attributes(const std::string &expression, genParam &generation) {
	bool isEvent {true} ;
	bool isXtimes {false} ;
	std::string event ;
	std::string attribute ;
	for (size_t i=0 ; i<expression.size() ; i++) {
		if (expression[i] == '%') {
			isEvent = false ;
			isXtimes = false ;
		} else if (expression[i] == 'X') {
			isEvent = false ;
			isXtimes = true ;
		} else {
			if (expression[i] != '|') {
				(isEvent) ? event += expression[i] : attribute += expression[i] ;
			}
		}
		if (expression[i] == '|' || i==expression.size()-1) {
			isEvent = true ;
			generation.events.push_back(event) ;
			event.clear() ;
			if (isXtimes) {
				generation.attributes.push_back(std::stoi(attribute)*100) ;
				attribute.clear() ;
			} else {
				if (attribute.empty()) {
					generation.attributes.push_back(0) ;
				} else {
					generation.attributes.push_back(std::stoi(attribute)) ;
					attribute.clear() ;
				}
			}
		}
	}
}


/* ------------------------------- ADD-SECTION ------------------------------ */


// A simple procedure to add data to the sections structure
void add_section(data &sections, std::string &section, size_t type) {
	if (!section.empty()) {
		sections.value.push_back(section) ;
		sections.type.push_back(type) ;
		section.clear() ;
	}
}


/* --------------------------- EXPRESSION-DIVIDER --------------------------- */


// Procedure used to create segments of the expression passed in parameter.
void expression_divider(std::string &expression, data &sections) {
	bool isAnchor {true} ;
	bool isSimpleGen {false} ;

	std::string section ;

	// Checking of position in string and section and setting of boolean variables.
	// Depending on boolean states, sections of expression will be pushed in different containers.
	for (size_t i=0 ; i<expression.size() ; i++) {
		if (expression[i] == '<') {
			isAnchor = false ;
			isSimpleGen = false ;
			add_section(sections, section, 0) ;
		} else if (expression[i] == '(' && isAnchor) {
			isAnchor = false ;
			isSimpleGen = true ;
			add_section(sections, section, 0) ;
		} else if (expression[i] == ')' && isSimpleGen) {
			isAnchor = true ;
			add_section(sections, section, 1) ;
		} else if (expression[i] == '>') {
			isAnchor = true ;
			add_section(sections, section, 2) ;
		} else {
			section += expression[i] ;
		}
	}
	// Last section push back
	if (isAnchor) {
		add_section(sections, section, 0) ;
	} else if (!isAnchor && isSimpleGen) {
		add_section(sections, section, 1) ;
	} else {
		add_section(sections, section, 2) ;
	}
}


/* ---------------------------- EXPRESSION-PARSER --------------------------- */


//Procedure used to parse each segment, extract generation parameters and store them in a structure.
void expression_parser(data &sections, std::vector<genParam> &generation) {
	for (size_t i=0 ; i<sections.type.size() ; i++) {
		std::string section {sections.value.at(i)} ;
		switch (sections.type.at(i)) {
			case 0 : { //If the section is an anchor
				generation[i].typeSection = 0 ;	
				generation[i].typeGen = '-' ;
				generation[i].minSize = 1 ;	
				generation[i].maxSize = 1 ;
				generation[i].anchor = section ;
				break ;
			}
			case 1 : { //If the section is a simple generation
				generation[i].typeSection = 1 ;
				generation[i].typeGen     = '-' ;
				extract_interval(section, generation[i]) ;
				break ;
			}
			case 2 : { //If the section is a complex generation
				generation[i].typeSection = 2 ;

				// Extraction of min and max interval values
				std::string interval {section.substr(1,(section.find(')')-1))} ;
				extract_interval(interval, generation[i]) ;
				
				// Extraction of typeGen parameter
				std::string substring {section.substr(section.find(')')+1)} ;
				extract_type_gen(substring, generation[i]) ;

				// Reformating of the substring 
				if (substring[0] == '+' || substring[0] == '*') {
					substring = substring.substr(1) ; //Deleting first character
				}
				
				// Extraction of potential events and probabilities/number associated
				extract_events_and_attributes(substring, generation[i]) ;
				break ;
			}
			default : {
				std::cout << "[parser] Neutrino error :" << std::endl ;
				std::cout << "[parser] Error occured in expression partitioning." << std::endl ;
				exit(1) ;
				break ;
			}
		}
	}	
}