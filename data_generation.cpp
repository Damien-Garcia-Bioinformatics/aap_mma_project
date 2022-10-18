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
int main(int argc, char* argv[]) {
	Generator generator_object(argv[1], argv[3]);
	int nbr_trace = int(argv[2]);
	generator_object.generate(nbr_trace);
}
