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
	std::string expression {"E4<(2-5)E2|E8>E6"} ;
	// std::string expression {"E4(10-12)E11 E12(12-13)E8"} ;

	// Default booleen values
	bool isAnchor {true} ; 
	bool isComplexGen {false} ; 
	bool isAnchorNext {false} ;

	std::string anchor ;
	std::vector<std::string> anchors ;

	// Loop checking each character in expression to define what section it is part.
	// The values returned will be formated as boolean and will define what genarative function to be used.
	for (int i=0 ; i<expression.length() ; i++) {
		if (isAnchorNext) {
			isAnchor = true ;
			isAnchorNext = false ;
		}
		if (isAnchor) {
			if (expression[i] == '(') {
				isAnchor = false ;
				isComplexGen = false ;
			} else if (expression[i] == '<') {
				isAnchor = false ;
				isComplexGen = true ;
			} else if (expression[i] == ' ') {
				anchors.push_back(anchor) ;
				anchor.clear() ;
			} else if (expression.length() == i+1) {
				anchor += expression[i] ;
				anchors.push_back(anchor) ;
				anchor.clear() ;
			} else {
				anchor += expression[i] ;
			}
		} else { // isAnchor is false
			if ((isComplexGen && expression[i] == '>') || (!isComplexGen && expression[i] == ')')) {
				isAnchorNext = true ;
				anchors.push_back(anchor) ;
				anchor.clear() ;
			}
		}

		// Extractions of anchor values and creation of bool arrays
	}

	// std::cout << anchors.size() << std::endl ;
	// std::cout << anchors.at(0) << "  " << anchors.at(1) << std::endl ;
	for (int i=0 ; i<anchors.size() ; i++) {
		std::cout << anchors.at(i) << std::endl ;
	}
}