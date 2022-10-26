#include <string>
#include <vector>

////////////////////////////////////////////////////////////////////////////////
//                                 Data types                                 //
////////////////////////////////////////////////////////////////////////////////

struct genParam {
	int minSize ;
	int maxSize ;
	bool isAnchor ;
	std::string anchor ;
	char typeGen ;
	std::vector<std::string> events ;
	std::vector<int> attributes ;
} ;

struct data {
	std::vector<int> type ;
	std::vector<std::string> value ;
} ;

////////////////////////////////////////////////////////////////////////////////
//                           Functions declaration                            //
////////////////////////////////////////////////////////////////////////////////

/*
Procedure that extracts minimum and maximum values from interval and stores
these values in generation structure.
*/
void extract_interval(const std::string &expression, genParam &generation) ;

/*
Procedure that extracts the generation type and stores it in generation
structure.
*/
void extract_type_gen(const std::string &expression, genParam &generation) ;

/*
Procedure that extracts potential events and attributes from complex generative
regions and stores them in generation structure.
*/
void extract_events_and_attributes_v2(const std::string &expression, genParam &generation) ;

/*
Procedure used to parse each segment, extract generation parameters and store
them in a structure.
*/
void expression_parser(data &sections, std::vector<genParam> &generation) ;

/*
Procedure used to create segments of the expression passed in parameter.
3 types of segments are created with respective type identifier :
	- Anchor sections are outside of generative regions.
	  The type identifier is '0'.
	- Simple generative sections are formed by an interval only.
	  The type identifier is '1'.
	- Complex generative sections are formed by an interval, and are supplemented
	  with a generation type, events and attributes.
	  The type identifier is '2'.
*/
void expression_divider(std::string &expression, data &sections) ;