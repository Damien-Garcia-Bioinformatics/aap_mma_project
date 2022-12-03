// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


////////////////////////////////////////////////////////////////////////////////
//                                 Data types                                 //
////////////////////////////////////////////////////////////////////////////////


#ifndef __OBJECTS__
#define __OBJECTS__


#include <string>
#include <vector>


/// @brief Structure containing generative parameters extracted from expression sections
class Generator {
	size_t minSize ;					// Minimum in interval
	size_t maxSize ;					// Maximum in interval
	size_t typeSection ;				// '0', '1' or '2' depending on the section type
	std::string anchor ;				// Anchor name
	char typeGen ;						// '+', '*' or none
	std::vector<std::string> events ;	// List of possible events
	std::vector<int> attributes ;		// List of events attributes
	std::string gen_result;			// returned generated sequence that'll be accumulated					

	// keep the parsing methods private to have a light interface
	// the main methods will be akin to the main in function oriented
	
	
	

} ;


////////////////////////////////////////////////////////////////////////////////


/// @brief Structure containing sections and type of sections of expression
class  Request {
	std::vector<int> type ;				// '0', '1' or '2' depending on the section type
	std::vector<std::string> value ;	// Value of the expression by section 
	std::vector<Generator> Generations; //manque taille?
	std::string expression;

	// début de l'interface, utilisant les méthodes pour créer la list de générateur 
	public :

	// besoin du constructeur pour avoir accès à l'expression initialisée
		Request(std::string userinput){
			expression = userinput;
		}
		
		void expression_divider(std::string &, data &) ;
		void expression_parser(data &, std::vector<genParam> &) ;
		void generate_traces(std::vector<genParam> &, std::vector<std::vector<std::string>> &, size_t) ;

	
} ;


#endif
