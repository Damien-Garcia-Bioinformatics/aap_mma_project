#include <iostream>
#include <string>
#include <vector>

/*
Some explications about the ideas behing the code :
The program is used to analyze the expression passed as parameter in order to execute the right generation function.
Anchors are special events that are systematicaly found in a sequence. These events are located outside of generative regions.
Generatives regions are located in between '(' and ')'. Parameters about the generative regions can be added on the right side of the ')' character.
*/

bool end_of_anchor(char c) {
	if (c == ' ' || c == '(' || c == '<'){
		return true;
	}
	return false ;
}

int main() {
	std::string tabEvent[10] {"E1","E2","E3","E4","E5","E6","E7","E8","E9","E10"} ;

	// Example of expression passed in program parameters by user
	std::string expression2 {"E4 <(2-5)E2|E8> E6"} ;
	std::string expression1 {"E4 (10-12) E11 E12 (12-13) E8"} ;

	// Default booleen values
	bool isAnchor {true} ; 
	bool isComplexGen {false} ; 

	std::string anchor ;
	std::vector<std::string> anchors ;

	// Loop checking each character in expression
	for (int i=0 ; i<expression1.length() ; i++) {
		// Checks throughout the expression1 if we are in or out of generative regions
		if (expression1[i] == '(' || expression1[i] == '<') {
			isAnchor = false ;
			if (expression1[i] == '<') {
				isComplexGen = true ;
			}
		} else if ((expression1[i] == ')' && isComplexGen == false) || expression1[i] == '>') {
			isAnchor = true ;
			isComplexGen = false ;
		}
		std::cout << i << "\t" << expression1[i] << "\t" << isAnchor << "\t"  << isComplexGen << "\n" ;

		// Extracts values of anchors
		if (isAnchor && !end_of_anchor(expression1[i])) {
			anchor += expression1[i] ;
		} else if ((!isAnchor && !anchor.empty()) ||
				   (isAnchor && end_of_anchor(expression1[i]))) {
			anchors.push_back(anchor) ;
			anchor.clear() ;
		}
	}

	// std::cout << anchors.size() << std::endl ;
	// std::cout << anchors.at(0) << "  " << anchors.at(1) << std::endl ;
	for (int i=0 ; i<anchors.size() ; i++) {
		std::cout << anchors.at(i) << std::endl ;
	}
}