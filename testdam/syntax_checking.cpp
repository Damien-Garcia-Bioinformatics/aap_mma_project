#include <iostream>
#include <string>

// Cleans generation expression for easier syntax and semantic verification
std::string remove_spaces(std::string sequence) {
	std::string cleanedSequence ;
	for (int i=0 ; i<sequence.size()) {
		if (sequence[i] != ' ') {
			cleanedSequence += sequence[i] ;
		}
	}
	return (cleanedSequence) ;
}

// Checks for unwanted character in generation expression
bool syntax_check(std::string sequence) {
	bool isValid {true} ;
	for (int i=0 ; i<sequence.size() ; i++){
		if (sequence[i] == ')') {
			if (sequence[i+1] != '*' || sequence[i+1] != '+' || sequence[i+1] != 'E' {
				isValid == false ;
				break ;
			} else if () {
				// Condition where possible events are all in anchors
			}
		}
	}

	return isValid ;
}