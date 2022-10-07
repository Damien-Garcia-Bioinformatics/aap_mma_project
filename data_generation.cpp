#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
// #include <vector>

/*
We will define
*/

// --- Functions --- //

//Random number generator for traces length
int trace_len(){
	return (rand() % 15) + 10 ;
}

//Function to fill "top" values in sequences


// --- Main --- //
int main() {
	srand((unsigned)time(0));
	int nb {20} ;
	int lstLen[nb] ;
	for (int i=0 ; i<nb ; i++) {
		lstLen[i] = trace_len() ;
	}
	// for (int i=0 ; i<nb ; i++) {
	// 	std::cout << lstLen[i] << std::endl ;
	// }

	std::string tamere {"tonpere"} ;
	std::cout << tamere.substr(2,2) << std::endl ;
}
