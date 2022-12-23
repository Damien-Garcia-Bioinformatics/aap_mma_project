// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


////////////////////////////////////////////////////////////////////////////////
//                           Functions definition                             //
////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "wirematrix.hpp"
#include "structures.hpp"


float del(vectors &elem1, size_t pos) {
    float delCost {0} ;
    for (size_t i=0 ; i<elem1.size() ; i++) {
        if (elem1[i][pos] == ".") {
            delCost += 2 ;
        } else {
            delCost += 3 ;
        }
    }
    delCost = delCost / elem1.size() ;
    return delCost ;
}


float ins(vectors &elem2, size_t pos) {
    float insCost {0} ;
    for (size_t i=0 ; i<elem2.size() ; i++) {
        if (elem2[i][pos] == ".") {
            insCost += 2 ;
        } else {
            insCost += 3 ;
        }
    }
    insCost = insCost / elem2.size() ;
    return insCost ;
}


float sub(vectors &elem1, vectors &elem2, size_t pos1, size_t pos2) {
    float subCost {0} ;
    for (size_t i=0 ; i<elem1.size() ; i++) {
        for (size_t j=0 ; j<elem2.size() ; j++) {
            if (i <= j) {
                if (elem1[i][pos1] == elem2[j][pos2]) {
                    subCost += 0 ;
                } else if ((elem1[i][pos1] == "." && elem2[j][pos2] != ".") ||
                           (elem2[j][pos2] == "." && elem1[i][pos1] != ".")) {
                    subCost += 4 ;
                } else {
                    subCost += 2 ;
                }
            }
        }
    }
    subCost = subCost / ((elem1.size()+elem2.size())-1) ;
    return subCost ;
}


wireMatrix wireMatrix_scoring(vectors &elem1, vectors &elem2) {
    // wireMatrix definition with default value of 0
    wireMatrix matrix {elem1[0].size(), std::vector<float>(elem2[0].size(), 0)} ;

    // North frontier initialization
    for (size_t x=1 ; x<elem1[0].size() ; x++) {
        matrix[x][0] = matrix[x-1][0] + del(elem1, x) ;
    }

    // West frontier initialization
    for (size_t y=1 ; y<elem2[0].size() ; y++) {
        matrix[0][y] = matrix[0][y-1] + ins(elem2, y) ;

        // Scoring 
        for (size_t x=1 ; x<elem1[0].size() ; x++) {
            float delCost {matrix[x-1][y] + del(elem1, x)} ;
            float insCost {matrix[x][y-1] + ins(elem2, y)} ;
            float subCost {matrix[x-1][y-1] + sub(elem1, elem2, x, y)} ;
            matrix[x][y] = std::min({delCost, insCost, subCost}) ;
        }
    }

    return matrix ;
}


void pairwiseAlign(wireMatrix &matrix, vectors &elem1, vectors &elem2) {
    size_t x {elem1[0].size()-1} ;
    size_t y {elem2[0].size()-1} ;

    alignment aligned ;
    aligned.elem1.push_back(traceFormat(elem1.size())) ;
    aligned.elem2.push_back(traceFormat(elem2.size())) ;

    while (x!=0 && y!= 0) {
        float goUp {matrix[x][y-1]} ;
        float goLeft {matrix[x-1][y]} ;
        float goDiag {matrix[x-1][y-1]} ;
        if (goDiag <= goUp && goDiag <= goLeft) {
            for (size_t i=0 ; i<elem1.size() ; i++) {
                aligned.elem1[i].push_back(elem1[i][x]) ;
            }
            for (size_t i=0 ; i<elem2.size() ; i++) {
                aligned.elem2[i].push_back(elem2[i][y]) ;
            }
            x-- ; y-- ;
        } else if (goUp < goLeft) {
            for (size_t i=0 ; i<elem1.size() ; i++) {
                aligned.elem1[i].push_back("-") ;
            }
            for (size_t i=0 ; i<elem2.size() ; i++) {
                aligned.elem2[i].push_back(elem2[i][y]) ;
            }
            y-- ;
        } else {
            for (size_t i=0 ; i<elem1.size() ; i++) {
                aligned.elem1[i].push_back(elem1[i][x]) ;
            }
            for (size_t i=0 ; i<elem2.size() ; i++) {
                aligned.elem2[i].push_back("-") ;
            }
            x-- ;
        }
    }
    while (x!=0) {
        for (size_t i=0 ; i<elem1.size() ; i++) {
            aligned.elem1[i].push_back(elem1[i][x]) ;
        }
        for (size_t i=0 ; i<elem2.size() ; i++) {
            aligned.elem2[i].push_back("-") ;
        }
        x-- ;
    }
    while (y!=0) {
        for (size_t i=0 ; i<elem1.size() ; i++) {
            aligned.elem1[i].push_back("-") ;
        }
        for (size_t i=0 ; i<elem2.size() ; i++) {
            aligned.elem2[i].push_back(elem2[i][y]) ;
        }
        y-- ;
    }

    // Reverse the alignment
    for (size_t i=0 ; i<elem1.size() ; i++) {
        std::reverse(aligned.elem1[i].begin(), aligned.elem1[i].end()) ;
    }
    for (size_t i=0 ; i<elem2.size() ; i++) {
        std::reverse(aligned.elem2[i].begin(), aligned.elem2[i].end()) ;
    }

    // Print alignment
    for (size_t i=0 ; i<aligned.elem1.size() ; i++) {
        for (size_t j=0 ; j<aligned.elem1[i].size() ; j++) {
            std::cout << aligned.elem1[i][j] << " " ;
        } std::cout << "\n" ;
    }
    for (size_t i=0 ; i<aligned.elem2.size() ; i++) {
        for (size_t j=0 ; j<aligned.elem2[i].size() ; j++) {
            std::cout << aligned.elem2[i][j] << " " ;
        } std::cout << "\n" ;
    }
}