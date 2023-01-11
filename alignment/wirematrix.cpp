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


//----------------------------------------------------------------------------//


float del(vectors &elem1, size_t pos) {
    float delCost {0} ;
    for (size_t i=0 ; i<elem1.size() ; i++) {
        if (elem1[i][pos] == ".") {
            delCost += 4 ;
        } else {
            delCost += 6 ;
        }
    }
    delCost = delCost / elem1.size() ;
    return delCost ;
}


//----------------------------------------------------------------------------//


float ins(vectors &elem2, size_t pos) {
    float insCost {0} ;
    for (size_t i=0 ; i<elem2.size() ; i++) {
        if (elem2[i][pos] == ".") {
            insCost += 4 ;
        } else {
            insCost += 6 ;
        }
    }
    insCost = insCost / elem2.size() ;
    return insCost ;
}


//----------------------------------------------------------------------------//


float sub(vectors &elem1, vectors &elem2, size_t pos1, size_t pos2) {
    float subCost {0} ;
    for (size_t i=0 ; i<elem1.size() ; i++) {
        for (size_t j=0 ; j<elem2.size() ; j++) {
            if (i <= j) {
                if (elem1[i][pos1] == elem2[j][pos2]) {
                    subCost += 0 ;
                } else if ((elem1[i][pos1] == "." && elem2[j][pos2] != ".") ||
                           (elem2[j][pos2] == "." && elem1[i][pos1] != ".")) {
                    subCost += 3 ;
                } else {
                    subCost += 1 ;
                }
            }
        }
    }
    subCost = subCost / ((elem1.size()+elem2.size())-1) ;
    return subCost ;
}


//----------------------------------------------------------------------------//


wireMatrix wireMatrix_scoring(vectors &elem1, vectors &elem2) {
    // wireMatrix definition with default value of 0
    wireMatrix matrix(elem1[0].size()+1, std::vector<float>(elem2[0].size()+1, 0)) ;

    // North frontier initialization
    for (size_t x=1 ; x<elem1[0].size()+1 ; x++) {
        matrix[x][0] = matrix[x-1][0] + del(elem1, x-1) ;
    }

    // West frontier initialization
    for (size_t y=1 ; y<elem2[0].size()+1 ; y++) {
        matrix[0][y] = matrix[0][y-1] + ins(elem2, y-1) ;

        // Scoring 
        for (size_t x=1 ; x<elem1[0].size()+1 ; x++) {
            float delCost {matrix[x-1][y] + del(elem1, x-1)} ;
            float insCost {matrix[x][y-1] + ins(elem2, y-1)} ;
            float subCost {matrix[x-1][y-1] + sub(elem1, elem2, x-1, y-1)} ;
            matrix[x][y] = std::min({delCost, insCost, subCost}) ;
        }
    }

    return matrix ;
}


//----------------------------------------------------------------------------//


vectors pairwiseAlign(wireMatrix &matrix, vectors &elem1, vectors &elem2) {

    std::cout << "matSize = " << matrix.size() << "   " << matrix[0].size() << "\n" ;
    std::cout << "vecSize1 = " ;
    for (size_t i=0 ; i<elem1.size() ; i++) {
        std::cout << elem1[i].size() << "  " ;
    } std::cout << "\n" ;
    std::cout << "vecSize2 = " ;
    for (size_t i=0 ; i<elem2.size() ; i++) {
        std::cout << elem2[i].size() << "  " ;
    }std::cout << "\n" ;
    
    // std::cout << "elem1\n" ;
    // for (size_t i=0 ; i<elem1.size() ; i++) {
    //     for (size_t j=0 ; j<elem1[i].size() ; j++) {
    //         std::cout << elem1[i][j] << " " ;
    //     }
    //     std::cout << "\n" ;
    // }
    // std::cout << "elem2\n" ;
    // for (size_t i=0 ; i<elem1.size() ; i++) {
    //     for (size_t j=0 ; j<elem2[i].size() ; j++) {
    //         std::cout << elem2[i][j] << " " ;
    //     }
    //     std::cout << "\n" ;
    // }
    
    alignment aligned ;
    for (size_t i=0 ; i<elem1.size() ; i++) {
        aligned.elem1.push_back(traceFormat()) ;
    }
    for (size_t i=0 ; i<elem2.size() ; i++) {
        aligned.elem2.push_back(traceFormat()) ;
    }
    size_t x {elem1[0].size()-1}, y {elem2[0].size()-1} ;
    // size_t x {elem1[0].size()}, y {elem2[0].size()} ;

    while (x != 0 && y != 0) {
        // std::cout << "test\n" ;
        float goUp {matrix[x][y-1]} ;
        // std::cout << "test0\n" ;
        float goLeft {matrix[x-1][y]} ;
        // std::cout << "test1\n" ;
        float goDiag {matrix[x-1][y-1]} ;
        // std::cout << "test2\n" ;

        if (goDiag <= goUp && goDiag <= goLeft) {
            for (size_t i=0 ; i<elem1.size() ; i++) {
                aligned.elem1[i].push_back(elem1[i][x]) ;
                // elem1[i].pop_back() ;
            }
            for (size_t i=0 ; i<elem2.size() ; i++) {
                aligned.elem2[i].push_back(elem2[i][y]) ;
                // elem2[i].pop_back() ;
            }
            x-- ; y-- ;
        } else if (goUp < goLeft) {
            for (size_t i=0 ; i<elem1.size() ; i++) {
                aligned.elem1[i].push_back("-") ;
            }
            for (size_t i=0 ; i<elem2.size() ; i++) {
                aligned.elem2[i].push_back(elem2[i][y]) ;
                // elem2[i].pop_back() ;
            }
            y-- ;
        } else {
            for (size_t i=0 ; i<elem1.size() ; i++) {
                aligned.elem1[i].push_back(elem1[i][x]) ;
                // elem1[i].pop_back() ;
            }
            for (size_t i=0 ; i<elem2.size() ; i++) {
                aligned.elem2[i].push_back("-") ;
            }
            x-- ;
        }
    }
    while (x != 0) {
        for (size_t i=0 ; i<elem1.size() ; i++) {
            aligned.elem1[i].push_back(elem1[i][x]) ;
            // elem1[i].pop_back() ;
        }
        for (size_t i=0 ; i<elem2.size() ; i++) {
            aligned.elem2[i].push_back("-") ;
        }
        x-- ;
    }
    while (y != 0) {
        for (size_t i=0 ; i<elem1.size() ; i++) {
            aligned.elem1[i].push_back("-") ;
        }
        for (size_t i=0 ; i<elem2.size() ; i++) {
            aligned.elem2[i].push_back(elem2[i][y]) ;
            // elem2[i].pop_back() ;
        }
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

    // std::cout << "newElem\n" ;
    // for (size_t i=0 ; i<newElem.size() ; i++) {
    //     for (size_t j=0 ; j<newElem[i].size() ; j++) {
    //         std::cout << newElem[i][j] << " " ;
    //     }
    //     std::cout << "\n" ;
    // }

    return newElem ;
}


//----------------------------------------------------------------------------//


void print_alignment(vectors &aligned) {
    // Print alignment
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


//----------------------------------------------------------------------------//


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