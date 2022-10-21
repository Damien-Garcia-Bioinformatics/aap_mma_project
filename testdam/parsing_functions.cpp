#include <iostream>
#include <string>
#include <vector>

// Structure definition should go on main
struct generation {
	int minSize ;
	int maxSize ;
	char typeGen ;
	std::vector<std::string> events ;
	union attribute {
		std::vector<float> prob ;
		std::vector<int> number ;
	} att ;
} ;


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

// Extracts possible events and probabilities linked in complex generative expression
generation extract_parameters(std::string expression, int pos) {
	std::string event ;
	std::string attribute ;
	bool isProb {false} ;
	bool isXtimes {false} ;
	bool isAttribute {false} ;

	generation genParam ;

	// Extraction of first character to see if 
	if (expression[pos] == '+' || expression[pos] == '*') {
		genParam.type = expression[pos] ;
		pos++ ;
	} else {
		genParam.type = '-' ;
		pos++ ;
	}
	while (expression[pos] != '>') {
		if (!isProb && !isXtimes) {
			if (expression[pos] == '|') {
				genParam.events.push_back(event) ;
				event.clear() ;
			} else if (expression[pos] == '%') {
				isProb = true ;
			} else if (expression[pos] == 'X') {
				isXtimes = true ;
			} else {
				event += expression[pos] ;
			}
		} else {
			if (isProb && expression[pos] == '|') {
				genParam.prob.push_back((float)attribute) ;
				attribute.clear() ;
				isProb = false ;
			} else if (isXtimes && expression[pos] == '|') {
				genParam.number.push_back((int)attribute) ;
				attribute.clear() ;			
				isXtimes = false ;
			} else {
				attribute += expression[pos] ;
			}
		}
		pos++ ;
	}
	// Pushing back in vector last value of generative expression when detecting '>' symbol
	if (isProb) {
		genParam.prob.push_back((float)attribute) ;
		attribute.clear() ;
	} else if (isXtimes) {
		genParam.number.push_back((int)attribute) ;
		attribute.clear() ;
	} else {
		genParam.events.push_back(event) ;
		event.clear() ;
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
		} else { // Entering generative region
			isAnchorNext = true ;
			anchors.push_back(anchor) ;
			anchor.clear() ;
		}
	}
}