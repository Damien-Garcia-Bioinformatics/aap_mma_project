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


size_t del(std::string top) {
    return 3 ;
}


size_t ins(std::string top) {
    return 3 ;
}


size_t sub(std::string top1, std::string top2) {
    if (top1 == top2) {
        return 0 ;
    } else if ((top1 == "." && top2 != ".") || (top2 == "." && top1 != ".")) {
        return 4 ;
    } else {
        return 2 ;
    }
}


size_t min(size_t del, size_t ins, size_t sub) {
    if (del < ins && del < sub) {
        return del ;
    } else if (ins < del && ins < sub) {
        return ins ;
    } else {
        return sub ;
    }
}


wireMatrix wireMatrix_scoring(traceFormat &seq1, traceFormat &seq2) {
    // wireMatrix definition with default value of 0
    wireMatrix matrix {seq1.size(), std::vector<size_t>(seq2.size(), 0)} ;

    // Calculation of wireMatrix scores
    for (size_t x=1 ; x<seq1.size() ; x++) {
        matrix[x][0] = matrix[x-1][0] + del(seq1[x-1]) ;
    }
    for (size_t y=1 ; y<seq2.size() ; y++) {
        matrix[0][y] = matrix[0][y-1] + ins(seq2[y-1]) ;
        for (size_t x=1 ; x<seq1.size() ; x++) {
            size_t delCost {matrix[x-1][y] + del(seq1[x-1])} ;
            size_t insCost {matrix[x][y-1] + ins(seq2[y-1])} ;
            size_t subCost {matrix[x-1][y-1] + sub(seq1[x-1], seq2[y-1])} ;
            matrix[x][y] = min(delCost, insCost, subCost) ;
        }
    }
    return matrix ;
}


void pairwiseAlign(wireMatrix &matrix, traceFormat &seq1, traceFormat &seq2) {
    size_t x {seq1.size()-1} ;
    size_t y {seq2.size()-1} ;

    alignment aligned ;

    while (x!=0 && y!= 0) {
        size_t goUp {matrix[x][y-1]} ;
        size_t goLeft {matrix[x-1][y]} ;
        size_t goDiag {matrix[x-1][y-1]} ;
        if (goDiag <= goUp && goDiag <= goLeft) {
            aligned.seq1.push_back(seq1[x-1]) ;
            aligned.seq2.push_back(seq2[y-1]) ;
            x-- ; y-- ;
        } else if (goUp < goLeft) {
            aligned.seq1.push_back("-") ;
            aligned.seq2.push_back(seq2[y-1]) ;
            y-- ;
        } else {
            aligned.seq1.push_back(seq1[x-1]) ;
            aligned.seq2.push_back("-") ;
            x-- ;
        }
    }
    while (x!=0) {
        aligned.seq1.push_back(seq1[x-1]) ;
        aligned.seq2.push_back("-") ;
        x-- ;
    }
    while (y!=0) {
        aligned.seq1.push_back("-") ;
        aligned.seq2.push_back(seq2[y-1]) ;
        y-- ;
    }

    std::reverse(aligned.seq1.begin(), aligned.seq1.end()) ;
    std::reverse(aligned.seq2.begin(), aligned.seq2.end()) ;

    seq1 = aligned.seq1 ;
    seq2 = aligned.seq2 ;

    for (size_t i=0 ; i<aligned.seq1.size() ; i++) {
        std::cout << aligned.seq1[i] << " " ;
    } std::cout << "\n" ;
    for (size_t i=0 ; i<aligned.seq2.size() ; i++) {
        std::cout << aligned.seq2[i] << " " ;
    } std::cout << "\n" ;
}