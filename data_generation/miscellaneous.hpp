// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


////////////////////////////////////////////////////////////////////////////////
//                           Functions declaration                            //
////////////////////////////////////////////////////////////////////////////////


#include <cstdlib>
#include <vector>
#include <string>


/// @brief Function that returns a positive random integer between min and max.
/// @param  unsigned_int : Minimum of interval
/// @param  unsigned_int : Maximum of interval
/// @return unsigned_int : Selected value from interval
size_t randint(size_t, size_t) ;


/// @brief Procedure to shuffle values in a vector of strings.
/// @param  vector_string : Vector which values are shuffled
void shuffle(std::vector<std::string> &) ;