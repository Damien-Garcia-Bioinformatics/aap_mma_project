#include <iostream>
#include <string>
#include <vector>

struct compGen {
	char typeGen ;
	std::vector<std::string> events ;
	std::vector<int> prob ;
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
void extract_event(std::string expression, int pos) {
	std::string event ;
	std::vector<std::string> events ;
	std::string strProb ;
	std::vector<int> intProb ;
	bool isProb {false} ;
	
	// Extraction of first character to see if 
	if (expression[pos] == '+') {
		//Code
		pos++ ;
	} else if (expression[pos] == '*') {
		//Code
		pos++ ;
	} else if (expression[pos] == 'X')

	while (expression[pos] != '>') {
		if (!isProb) {
			if (expression[pos] == ' ') {
				continue ;
			} else if (expression[pos] == '|') {
				events.push_back(event) ;
				event.clear() ;
				intProb.push_back(100) ; // Case where no stat is specified
			} else if (expression[pos] == '%') {
				isProb = true ;
			} else {
				event += expression[pos] ;
			}
		} else {
			if (expression[pos] == '|') {
				intProb.push_back((int)strProb) ;
				strProb.clear() ;
				isProb = false ;
			} else {
				strProb += expression[pos] ;
			}
		}
		pos ++ ;
	}
	// Pushing back in vector last value of generative expression when detecting '>' symbol
	if (isProb) {
		intProb.push_back((int)strProb) ;
		strProb.clear() ;
	} else {
		events.push_back(event) ;
		event.clear() ;
		intPorb.push_back(100) ;
	}
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
		} else { // Entering generative region
			isAnchorNext = true ;
			anchors.push_back(anchor) ;
			anchor.clear() ;
		}
	}
}