#include <iostream>
#include <string>
#include <vector>

// Structure definition should go on main
struct generation {
	int minSize ;
	int maxSize ;
	char typeGen ;
	std::vector<std::string> events ;
	// union attribute {
	// 	std::vector<float> prob ;
	// 	std::vector<int> number ;
	// } att ;
	std::vector<float> prob ;
	std::vector<int> number ;
} ;

//--------------------------------------------------------------------------//

int extract_generative_region(std::string expression, int pos) {
	// Extraction of substring from expression
	size_t separator {expression.find(')')} ;
	std::string substring {expression.substr(0, separator)} ;
	
	// Extraction of min and max interval values
	int interval[2] ;
	separator = substring.find('-') ;
	interval[0] = std::stoi(substring.substr(0, separator)) ; //Extraction of min length
	interval[1] = std::stoi(substring.substr(separator)) ; //Extraction of max length
	std::cout<<interval[0]<<' '<<interval[1]<<std::endl ;

	return interval ;
}

//--------------------------------------------------------------------------//

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
		genParam.typeGen = expression[pos] ;
		pos++ ;
	} else {
		genParam.typeGen = '-' ;
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
				genParam.prob.push_back(std::stof(attribute)) ;
				attribute.clear() ;
				isProb = false ;
			} else if (isXtimes && expression[pos] == '|') {
				genParam.number.push_back(std::stoi(attribute)) ;
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
		genParam.prob.push_back(std::stof(attribute)) ;
		attribute.clear() ;
	} else if (isXtimes) {
		genParam.number.push_back(std::stoi(attribute)) ;
		attribute.clear() ;
	} else {
		genParam.events.push_back(event) ;
		event.clear() ;
	}

	return genParam ;
}

//--------------------------------------------------------------------------//

// Second version of parser
void expression_parser(std::string expression) {
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
				extract_parameters(expression, i) ;
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




// -----------------------------------Main----------------------------------//

int main() {
	// Example of expression passed in program parameters by user
	std::string expression {"E4<(2-5)E2|E8>E6"} ;

	

	return 0 ;
}