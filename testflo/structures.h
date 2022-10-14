#include <string>
#include <vector>


// string composition for parsing
struct input_parse 
{
	// to explain what this does, let's take an input example :" E1<(2-5)+E3|E4>E2" 
	// either += as in python to concatenate or make a table

	// this extracts the anchors, main components driving the genes, here E1,E2
	std::string element_anchors;

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

struct expansion_interval
{
	int beginninging;
	int endedenend;
};

struct non_anchors
{
	std::vector<std::string> non_anchor;
};

// Let's try an object
//

class Generator
{
	// here the parent parses the input into different boolean profiles and stocks the query
	private :
		std::string query;
		std::vector<std::string> anchors;
		std::vector<std::string> profile_lv2_exp;
		std::vector<std::string> profile_lv1_exp;
		//int exp_instance {0};
		std::vector<std::string> profile_diff_lv3exp;
		
	// the methods here serve to initialise the private variables
	public :
		void init(std::string);
		void parse_anchors(std::string sequence);
		void parse_lv1_profile(std::string sequence);
		void parse_lv2_profile(std::string sequence);
		void set_diff_exp_lv3();

		//int get_exp_number(); not to go through the input a high number of time,
		//we can get the expansion number in the profile_lv1 method
	
		// the public variables aims to be transitted to each child for them
		// to treat the information and generate tops with events in them	
		

	private :
		// the two numbers encapsualting top generation
		std::vector<expansion_interval> generation_interval;	
		
		// random explicited events
		std::vector<non_anchors> non_anchor_ptr;
		
		// this part should be in conflict, if there is one the other should be empty
		//
		// expansion character * or +
		char special_expansion_character;
		// %p explicited
		std::vector<int> proportion; // verification that the sum is 100
		// Xk times explicited
		std::vector<int> k_times; // verification sum(k) < lenght top generated

	public :
		get_generation_interval(string exp_child[1]); // renvoie vers generation_interval
		get_special_exp_character(string exp_child[2]); 
		get_non_anchors(string exp_child[2]);
		get_proportion(string exp_child[2]);
		get_k_times(string exp_child[2]);
		
}

Generator::Generator(std::string querinput){
	this->query = querinput;

}
