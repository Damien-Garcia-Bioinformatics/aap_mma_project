// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB



/* -------------------------------------------------------------------------- */
/*                            Functions definition                            */
/* -------------------------------------------------------------------------- */


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

#include "wirematrix.hpp"
#include "structures.hpp"


/* ---------------------------- GLOBAL-VARIABLES ---------------------------- */

// Note to the reader :
// Global variables are almost always a bad practice. Here, for the purpose of testing
// many different scoring parameters, they allow easier manipulation and limit the search
// in the many lines of the following functions and procedures.

const float     INDEL_TOP {1} ;
const float     INDEL_GAP {2} ;
const float    INDEL_ELSE {6} ;

const float   SUBST_MATCH {0} ;
const float SUBST_GAP_TOP {2} ;
const float    SUBST_ELSE {2} ;


/* ----------------------------------- DEL ---------------------------------- */


float del(vectors &elem1, size_t pos) {
    float delCost {0} ;
    for (size_t i=0 ; i<elem1.size() ; i++) {
        if (elem1[i][pos] == ".") {
            delCost += INDEL_TOP ;
        } else if (elem1[i][pos] == "-") {
            delCost += INDEL_GAP ;
        } else {
            delCost += INDEL_ELSE ;
        }
    }
    delCost = delCost / elem1.size() ;
    return delCost ;
}


/* ----------------------------------- INS ---------------------------------- */


float ins(vectors &elem2, size_t pos) {
    float insCost {0} ;
    for (size_t i=0 ; i<elem2.size() ; i++) {
        if (elem2[i][pos] == ".") {
            insCost += INDEL_TOP ;
        } else if (elem2[i][pos] == "-") {
            insCost += INDEL_GAP ;
        } else {
            insCost += INDEL_ELSE ;
        }
    }
    insCost = insCost / elem2.size() ;
    return insCost ;
}


/* ----------------------------------- SUB ---------------------------------- */


float sub(vectors &elem1, vectors &elem2, size_t pos1, size_t pos2) {
    float subCost {0} ;
    for (size_t i=0 ; i<elem1.size() ; i++) {
        for (size_t j=0 ; j<elem2.size() ; j++) {
            if (i <= j) {
                if (elem1[i][pos1] == elem2[j][pos2]) {
                    subCost += SUBST_MATCH ;
                } else if ((elem1[i][pos1] == "." && elem2[j][pos2] != "-") ||
                           (elem2[j][pos2] == "." && elem1[i][pos1] != "-")) {
                    subCost += SUBST_GAP_TOP ;
                } else {
                    subCost += SUBST_ELSE ;
                }
            }
        }
    }
    subCost = subCost / ((elem1.size()+elem2.size())-1) ;
    return subCost ;
}


/* --------------------------- WIREMATRIX-SCORING --------------------------- */


wireMatrix wireMatrix_scoring(vectors &elem1, vectors &elem2) {
    // wireMatrix definition with default value of 0
    wireMatrix matrix(elem1[0].size()+1, std::vector<float>(elem2[0].size()+1, 0)) ;

    // North frontier initialization
    for (size_t x=1 ; x<matrix.size() ; x++) {
        matrix[x][0] = matrix[x-1][0] + del(elem1, x-1) ;
    }

    // West frontier initialization
    for (size_t y=1 ; y<matrix[0].size() ; y++) {
        matrix[0][y] = matrix[0][y-1] + ins(elem2, y-1) ;
    }
    
    // Scoring 
    for (size_t x=1 ; x<matrix.size() ; x++) {
        for (size_t y=1 ; y<matrix[0].size() ; y++) {
            float delCost {matrix[x-1][y] + del(elem1, x-1)} ;
            float insCost {matrix[x][y-1] + ins(elem2, y-1)} ;
            float subCost {matrix[x-1][y-1] + sub(elem1, elem2, x-1, y-1)} ;
            matrix[x][y] = std::min({delCost, insCost, subCost}) ;
        }
    }

    return matrix ;
}


/* ----------------------------- PAIRWISE-ALIGN ----------------------------- */


vectors pairwiseAlign(wireMatrix &matrix, vectors &elem1, vectors &elem2) {
    alignment aligned ;
    for (size_t i=0 ; i<elem1.size() ; i++) aligned.elem1.push_back(traceFormat()) ;
    for (size_t i=0 ; i<elem2.size() ; i++) aligned.elem2.push_back(traceFormat()) ;

    size_t x {matrix.size()-1}, y {matrix[0].size()-1} ;
    while (x != 0 && y != 0) {
        float goUp {matrix[x][y-1]} ;
        float goLeft {matrix[x-1][y]} ;
        float goDiag {matrix[x-1][y-1]} ;

        if (goDiag <= goUp && goDiag <= goLeft) {
            for (size_t i=0 ; i<elem1.size() ; i++) aligned.elem1[i].push_back(elem1[i][x-1]) ;
            for (size_t i=0 ; i<elem2.size() ; i++) aligned.elem2[i].push_back(elem2[i][y-1]) ;
            x-- ; y-- ;
        } else if (goUp < goLeft) {
            for (size_t i=0 ; i<elem1.size() ; i++) aligned.elem1[i].push_back("-") ;
            for (size_t i=0 ; i<elem2.size() ; i++) aligned.elem2[i].push_back(elem2[i][y-1]) ;
            y-- ;
        } else {
            for (size_t i=0 ; i<elem1.size() ; i++) aligned.elem1[i].push_back(elem1[i][x-1]) ;
            for (size_t i=0 ; i<elem2.size() ; i++) aligned.elem2[i].push_back("-") ;
            x-- ;
        }
    }
    while (x != 0) {
        for (size_t i=0 ; i<elem1.size() ; i++) aligned.elem1[i].push_back(elem1[i][x-1]) ;
        for (size_t i=0 ; i<elem2.size() ; i++) aligned.elem2[i].push_back("-") ;
        x-- ;
    }
    while (y != 0) {
        for (size_t i=0 ; i<elem1.size() ; i++) aligned.elem1[i].push_back("-") ;
        for (size_t i=0 ; i<elem2.size() ; i++) aligned.elem2[i].push_back(elem2[i][y-1]) ;
        y-- ;
    }
    
    // Reverse the alignment
    vectors newElem ;
    for (size_t i=0 ; i<aligned.elem1.size() ; i++) {
        std::reverse(aligned.elem1[i].begin(), aligned.elem1[i].end()) ;
        newElem.push_back(aligned.elem1[i]) ;
    }
    for (size_t i=0 ; i<aligned.elem2.size() ; i++) {
        std::reverse(aligned.elem2[i].begin(), aligned.elem2[i].end()) ;
        newElem.push_back(aligned.elem2[i]) ;
    }

    return newElem ;
}