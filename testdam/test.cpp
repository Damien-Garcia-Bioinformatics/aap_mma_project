#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

/*
Some explications about the ideas behing the code :
The program is used to analyze the expression passed as parameter in order to execute the right generation function.
Anchors are special events that are systematicaly found in a sequence. These events are located outside of generative regions.
Generatives regions are located in between '(' and ')'. Parameters about the generative regions can be added on the right side of the ')' character.
*/

// void extract_anchor(std::string anchor, &std::vector<std::string> *anchors) {
// 	anchors.push_back(anchor) ;
// 	anchor.clear() ;
// }

// --------------------------------Functions--------------------------------//

// Returns int between 0 and nb
int random_int(int nb) {
	int proba {rand()%nb} ;
	return proba ;
}


// Returns maxLen of sequence
int sequence_length(int maxLen) {
	int seqLen {rand()%maxLen+1} ;
	return seqLen ;
}


// Toy function to generate a simple sequence 
std::string simple_gen(int min, int max) {
	int seqLen {sequence_length(20)} ; 
	std::string sequence(seqLen, '.') ;
	return sequence ;
}


// Returns a valid event (not in anchor)
std::string add_event(std::vector<std::string> tabEvent, std::vector<std::string> anchors) {
	size_t countInvalid ;
	std::string event ;
	do {
		countInvalid = 0 ;
		event = tabEvent.at(random_int(tabEvent.size())) ;
		for (int i=0 ; i<anchors.size() ; i++) {
			if (event == anchors.at(i)) {
				countInvalid++ ;
			}
		}
	} while (countInvalid != 0) ;
	return event ;
}


// Toy function to generated a complex sequence
std::string complex_gen(std::vector<std::string> tabEvent, std::vector<std::string> anchors) {
	std::string sequence ;
	std::string event ;
	bool isValid {false} ;
	for (int i=0 ; i<20 ; i++) {
		int value {random_int(4)} ;
		std::cout << value << std::endl ;
		if (value == 0) {
			sequence += add_event(tabEvent, anchors) ;
		} else {
			sequence += '.' ;
		}
		sequence += ' ' ;
	}
	std::cout << sequence << std::endl ;

	return sequence ;
}


// -----------------------------------Main----------------------------------//

int main() {
	// Initialization of seed for random_int() function
	srand(time(NULL));

	// Definition of events that can occur in sequence
	std::vector<std::string> tabEvent {"E1","E2","E3","E4","E5","E6","E7","E8","E9","E10"} ;

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
	}

	// Génération complexe
	std::string sequence{complex_gen(tabEvent, anchors)};
	std::cout << sequence << std::endl;
}