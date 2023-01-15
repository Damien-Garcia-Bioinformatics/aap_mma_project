// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


/* -------------------------------------------------------------------------- */
/*                                 Data types                                 */
/* -------------------------------------------------------------------------- */


#ifndef __STRUCTURES__
#define __STRUCTURES__


#include <string>

using traceFormat = std::vector<std::string> ;
using vectors = std::vector<traceFormat> ;
using msaFormat = std::vector<vectors> ;
using wireMatrix = std::vector<std::vector<float>> ;
using dissimMatrix = std::vector<std::vector<wireMatrix>> ;

// As stated above, "vectors" is a reference to several sequences at once.
// This allow for computation of an average when the dissimilarity matrix is purged.
struct alignment {
    vectors elem1 ;
    vectors elem2 ;
} ;


#endif 