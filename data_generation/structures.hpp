#include <string>
#include <vector>

////////////////////////////////////////////////////////////////////////////////
//                                 Data types                                 //
////////////////////////////////////////////////////////////////////////////////

struct genParam {
	int minSize ;						// Minimum in interval
	int maxSize ;						// Maximum in interval
	int typeSection ;					// '0', '1' or '2' depending on the section type
	std::string anchor ;				// Anchor name
	char typeGen ;						// '+', '*' or none
	std::vector<std::string> events ;	// List of possible events
	std::vector<int> attributes ;		// List of events attributes
} ;

struct data {
	std::vector<int> type ;				// '0', '1' or '2' depending on the section type
	std::vector<std::string> value ;	// Value of the expression by section
} ;