#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> parse_anchors(std::string sequence) {
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
	}
	return (anchors) ;
}

// Extracts parameters of generative region
void extract_generative_region(std::string sequence, bool isComplexGen) {
	bool test {true} ;
	std::string value ;
	size_t min ;
	size_t max ;
	size_t typeGen ; // '+' is 1, '*' is 2, '%' is 3 and 'ki' is '4' for example
	if (isComplexGen) {
		for (int i=0 ; i<sequence.size() ; i++) {
			if (sequence[i] == '(' || sequence[i] == ' '){
				continue ;
			}
		}
	}
}