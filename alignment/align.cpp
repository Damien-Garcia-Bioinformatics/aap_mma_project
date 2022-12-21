// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


////////////////////////////////////////////////////////////////////////////////
//                             Pairwise alignment                             //
////////////////////////////////////////////////////////////////////////////////


#ifndef __PAIRWISE__
#define __PAIRWISE__


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "structures.hpp"
#include "read_traces.hpp"


size_t del(std::string top) {
    return 3 ;
}


size_t ins(std::string top) {
    return 3 ;
}


size_t sub(std::string top1, std::string top2) {
    if (top1 == top2) {
        return 0 ;
    } else if (top1 == "." && top2 != ".") {
        return 1 ;
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


wireMatrix wireMatrix_scoring(std::vector<std::string> &seq1, std::vector<std::string> &seq2) {
    // wireMatrix definition with default value of 0
    wireMatrix matrix {seq1.size()+1, std::vector<size_t>(seq2.size()+1, 0)} ;

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


void reverse_string(std::string &str) {
    size_t len {str.size()} ;
    size_t n {len-1} ;
    size_t i {0} ;
    while (i<=n) {
        std::swap(str[i], str[n]) ;
        n-- ;
        i++ ;
    }
}


void print_result(wireMatrix &matrix, const std::string &seq1, const std::string &seq2) {
    size_t x {seq1.size()-1} ;
    size_t y {seq2.size()-1} ;

    alignment al ;

    while (x!=0 && y!= 0) {
        size_t goUp {matrix[x][y-1]} ;
        size_t goLeft {matrix[x-1][y]} ;
        size_t goDiag {matrix[x-1][y-1]} ;
        if (goDiag <= goUp && goDiag <= goLeft) {
            al.seq1 += seq1[x-1] ;
            (seq1[x-1] == seq2[y-1]) ? al.link += '|' : al.link += '*' ;
            al.seq2 += seq2[y-1] ;
            x-- ; y-- ;
        } else if (goUp < goLeft) {
            al.seq1 += '-' ;
            al.link += 'i' ;
            al.seq2 += seq2[y-1] ;
            y-- ;
        } else {
            al.seq1 += seq1[x-1] ;
            al.link += 'd' ;
            al.seq2 += '-' ;
            x-- ;
        }
    }
    while (x!=0) {
        al.seq1 += seq1[x-1] ;
        al.link += 'd' ;
        al.seq2 += '-' ;
        x-- ;
    }
    while (y!=0) {
        al.seq1 += '-' ;
        al.link += 'i' ;
        al.seq2 += seq2[y-1] ;
        y-- ;
    }

    reverse_string(al.seq1) ;
    reverse_string(al.link) ;
    reverse_string(al.seq2) ;

    std::cout << al.seq1 << "\n" ;
    std::cout << al.link << "\n" ;
    std::cout << al.seq2 << "\n" ;
}


int main() {
    // std::string seq1 {". . E1 . . . . . . . . . . . . . . . . . . . E9 . E3 "} ;
    // std::string seq2 {". . . . E1 . . . . . . . . . . . . . . . . . . . E9 . . E3 "} ;
    // wireMatrix matrix {wireMatrix_scoring(seq1, seq2)} ;


    // Read and extract traces from data file
    std::string path {"../examples/result_simple.txt"} ;
    std::vector<std::vector<std::string>> traces ;
    read_file(path, traces) ;


    // Dissimilarity matrix creation
    dissimMatrix dissimilarity {traces.size(), std::vector<size_t>(traces.size(), 0)} ;

    for (size_t i=0 ; i<traces.size() ; i++) {
        for (size_t j=0 ; j<traces.size() ; j++) {
            if (i != j) {
                dissimilarity[i][j] = wireMatrix_scoring(traces[i], traces[j])[traces[i].size()-1][traces[j].size()-1] ;
            }
        }
    }

    for (size_t i=0 ; i<dissimilarity.size() ; i++) {
        for (size_t j=0 ; j<dissimilarity.size() ; j++) {
            if (dissimilarity[i][j] < 10) {
                std::cout << dissimilarity[i][j] << "  " ;
            } else {
                std::cout << dissimilarity[i][j] << " " ;
            }
        }
        std::cout << "\n" ;
    }

    return 0 ;
}


#endif