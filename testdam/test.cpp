#include <iostream>
#include <vector>
#include <string>

int main() {
	std::string expression {"E4<(4-6)E2%12|E5X2>E6"} ;
	std::vector<std::string> anchors ;
	std::vector<std::string> generativeRegion ;
	std::vector<std::string> parameters ;

	for (int i=0 ; i<expression.size() ; i++) {
		if (expression[i] == 'E') {
			
		}
	}

	return 0 ;
}