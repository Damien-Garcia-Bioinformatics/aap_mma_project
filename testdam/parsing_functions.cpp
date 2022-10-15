#include <iostream>
#include <string>
#include <vector>

/*
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
*/
int extract_generative_region(std::string expression, int pos) {
	bool isMin {true} ;
	std::string strMin ;
	std::string strMax ;

	while (expression[pos] != ')') {
		if (expression[pos] == '-') {
			isMin = false ;
		}
		if (isMin) {
			strMin += expression[pos] ;
		} else {
			strMax += expression[pos] ;
		}
		pos++ ;
	}
	return int length[2] {(int)strMin, (int)strMax} ;
}

void extract_parameters(std::string expression, int pos) {
	switch (expression[pos]) {
		case '+' :
			// At least one event should appear on generation
			break ;
		case '*' :
			// 0 or more event should appear on generation
			break ;

		default :
			//code
	}
	while (expression[pos] != '>') {
	}
}

// Second version of parser
std::vector<std::string> expression_parser(std::string expression) {
	// Default boolean values
	bool isAnchor {true} ;
	bool isAnchorNext {false} ;
	bool isComplexGen {false} ;

	size_t regionPos {0} ; // To position the different generation in the right order

	std::string anchor ;
	std::vector<std::string> anchors ;

	for (int i=0 ; i<expression.size() ; i++) {
		if (isAnchorNext) {
			isAnchor = true ;
			isAnchorNext = false ;
		}
		if (isAnchor) {
			if (expression[i] == '(') {
				isAnchor = false ;
				isComplexGen = false ;
				extract_generative_region(expression, i) ;
			} else if (expression[i] == '<') {
				isAnchor = false ;
				isComplexGen = true ;
				extract_generative_region(expression, i) ;
				extract_generation_parameters(expression, i) ;
			} else if (expression[i] == ' ') {
				anchors.push_back(anchor) ;
				anchor.clear() ;
			} else if (expression.size() == i+1) {
				anchor += expression [i] ;
				anchors.push_back(anchor) ;
				anchor.clear() ;
			} else {
				anchor += expression[i] ;
			}
		} else { // isAnchor is false
			isAnchorNext = true ;
			anchors.push_back(anchor) ;
			anchor.clear() ;
		}
	}
}