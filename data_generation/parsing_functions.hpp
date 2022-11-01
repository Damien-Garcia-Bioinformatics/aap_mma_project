#include <string>
#include <vector>
#include "structures.hpp"

////////////////////////////////////////////////////////////////////////////////
//                           Functions declaration                            //
////////////////////////////////////////////////////////////////////////////////


/// @brief Procedure that extracts minimum and maximum values from interval and stores these values in generation structure.
/// @param  string : Section of expression
/// @param  genParam_structure : Contains generative parameters extracted from expression section
void extract_interval(const std::string &, genParam &) ;


/// @brief Procedure that extracts the generation type and stores it in generation structure.
/// @param  string : Section of expression
/// @param  genParam_structure : Contains generative parameters extracted from expression section
void extract_type_gen(const std::string &, genParam &) ;


/// @brief Procedure that extracts potential events and attributes from complex generative regions and stores them in generation structure.
/// @param  string : Section of expression
/// @param  genParam_structure : Contains generative parameters extracted from expression section
void extract_events_and_attributes_v2(const std::string &, genParam &) ;

/*

*/
/// @brief 	Procedure used to create segments of the expression passed in parameter.
///			3 types of segments are created with respective type identifier :
///				- Anchor sections are outside of generative regions.
///				The type identifier is '0'.
///				- Simple generative sections are formed by an interval only.
///				The type identifier is '1'.
///				- Complex generative sections are formed by an interval, and are supplemented
///				with a generation type, events and attributes.
///				The type identifier is '2'.
/// @param  string : Expression to segment
/// @param  data_structure : Contains sections and type of sections of expression
void expression_divider(std::string &, data &) ;

/*
Procedure used to parse each segment, extract generation parameters and store
them in a structure.
*/
/// @brief Procedure used to parse each segment, extract generation parameters and store them in a structure.
/// @param  data_structure : Contains sections and type of sections of expression
/// @param  vector_genParam_structure : Contains generative parameters extracted from expression sections
void expression_parser(data &, std::vector<genParam> &) ;