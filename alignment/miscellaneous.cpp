// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB



/* -------------------------------------------------------------------------- */
/*                            Functions definition                            */
/* -------------------------------------------------------------------------- */



#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "structures.hpp"
#include "miscellaneous.hpp"


/* ----------------------------- PRINT-ALIGNMENT ---------------------------- */

// Procedure that prints the alignment to screen
void print_alignment(vectors &aligned) {
    size_t maxLength {0} ;
    for (size_t i=0 ; i<aligned.size() ; i++) {
        for (size_t j=0 ; j<aligned[i].size() ; j++) {
            if (aligned[i][j].size() > maxLength) {
                maxLength = aligned[i][j].size() ;
            }
        }
        for (size_t j=0 ; j<aligned[i].size() ; j++) {
            std::cout << aligned[i][j] << std::string((maxLength - aligned[i][j].size())+1, ' ') ;
        }
        std::cout << "\n" ;
    }
}


/* --------------------------- PRINT-ALIGNMENT-V2 --------------------------- */

// Enhanced procedure that shows alignments in a more orderly manner
void print_alignment_v2(vectors aligned) {
    for (size_t i=0 ; i<aligned.size() ; i++) {
        bool again {true} ;
        while (again) {
            if (aligned[i][aligned[i].size()-1] == "-") {
                aligned[i].pop_back() ;
            } else {
                again = false ;
            }
        }
    }
    size_t maxLength {0} ;
    for (size_t i=0 ; i<aligned.size() ; i++) {
        for (size_t j=0 ; j<aligned[i].size() ; j++) {
            if (aligned[i][j].size() > maxLength) {
                maxLength = aligned[i][j].size() ;
            }
        }
        bool begin {true} ;
        for (size_t j=0 ; j<aligned[i].size() ; j++) {
            if (aligned[i][j] != "-") {
                begin = false ;
            }
            if (begin && aligned[i][j] == "-") {
                std::cout << ' ' << std::string((maxLength - aligned[i][j].size())+1, ' ') ;
            } else {
                std::cout << aligned[i][j] << std::string((maxLength - aligned[i][j].size())+1, ' ') ;
            }
        }
        std::cout << "\n" ;
    }
}


/* ---------------------------- PRINT-WIREMATRIX ---------------------------- */

// Procedure showing the content of a wire matrix on screen
void print_wirematrix(wireMatrix &matrix) {
    for (size_t x=0 ; x<matrix.size() ; x++) {
        for (size_t y=0 ; y<matrix[0].size() ; y++) {
            std::cout << std::setprecision(0) << std::fixed << std::setw(3) << std::right << matrix[x][y] ;
        }
        std::cout << "\n" ;
    }
    std::cout << "\n\n" ;
}


/* --------------------------- PRINT-DISSIMMATRIX --------------------------- */


// Procedure that prints the dissimilarity matrix, of which only the last part of the wire matrix is shown
void print_dissimMatrix(dissimMatrix &D) {
    std::cout << std::setprecision(1) << std::fixed ;
    for (size_t i=0 ; i<D.size() ; i++) {
        for (size_t j=0 ; j<D[i].size() ; j++) {
            float val {D[i][j][D[i][j].size()-1][D[i][j][0].size()-1]} ;
            // .back() method must be avoided because of undefined behavior on empty vectors
            std::cout << std::right << std::setw(6) << val ;
        }
        std::cout << "\n" ;
    }
}