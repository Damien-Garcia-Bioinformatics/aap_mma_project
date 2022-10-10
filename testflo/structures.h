#include <string>


// string composition for parsing
struct input_parse 
{
	// to explain what this does, let's take an input example :" E1<(2-5)+E3|E4>E2" 
	// either += as in python to concatenate or make a table

	// this extracts the anchors, main components driving the genes, here E1,E2
	std::string element_anchors[tableau?];

	// this extracts intervals of entities to repeat motifs
	std::string query_intervals;

	// this extracts the condition of expansion, + or * 
	std::string expansion_sign;

	// this extracts the elements to repeats inbetween anchors
	std::string expansion_component;

	// the lenght of expansion_sign should be the same as the number of <queries>, with a placeholder
	// "." for example
}

// the struct might not be the best choice for this task, as internal methods will be called
// directly on the data. An object might make it easier
//


// Let's try an object
//

class Generator
{
	// here the parent parses the input into different boolean profiles and stocks the query
	private :
		std::string query;
		bool profile_anchor[100];
		bool profile_lv2_exp[100];
		bool profile_lv1_exp[100];
		int exp_instance {0};
		bool profile_diff_lv3exp[100];
		
	// the methods here serve to initialise the private variables
	public :
		void init(std::string);
		void get_anchors(std::string);
		void get_lv2_profile();
		void get_lv1_profile();
		void get_diff_exp();
		// this will 
		//int get_exp_number(); not to go through the input a high number of time,
		//we can get the expansion number in the profile_lv1 method
	
		// the public variables aims to be transitted to each child for them
		// to treat the information and generate tops with events in them	
	
		//the two anchors that dictate top intervals
		std::string anchor_child[2];
		//expansion instructions, 1st element is (), second is <> (can be empty or 0)
		std::string exp_child[2];
		


		// instances as much childs as ther e are expansions
		Expansion instance_child();
	
}


// the child receives the two anchors it needs, and the two expansion instructions
// (one if no <>)
class Expansion : Generator
{
	
}
