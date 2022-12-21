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


using wireMatrix = std::vector<std::vector<size_t>> ;


// Returns a wire matrix of size n+1, m+1 with all values set to 0
wireMatrix wireMatrix_initializer(const std::string &seq1, const std::string &seq2) {
    size_t northFront {seq1.size() + 1} ;
    size_t eastFront {seq2.size() + 1} ;
    wireMatrix matrix(northFront, std::vector<size_t>(eastFront, 0)) ;
    return matrix ;
}


size_t del(char aa) {
    return 3 ;
    // switch (aa) {
    //     case 'A' :
    //         return 1 ;
    //         break ;
    //     case 'T' :
    //         return 2 ;
    //         break ;
    //     case 'C' :
    //         return 3 ;
    //         break ;
    //     case 'G' :
    //         return 4 ;
    //         break ;
    //     default :
    //         std::cout << "Err\n" ;
    //         exit(1) ;
    // }
}


size_t ins(char aa) {
    return 3 ;
    // switch (aa) {
    //     case 'A' :
    //         return 1 ;
    //         break ;
    //     case 'T' :
    //         return 2 ;
    //         break ;
    //     case 'C' :
    //         return 3 ;
    //         break ;
    //     case 'G' :
    //         return 4 ;
    //         break ;
    //     default :
    //         std::cout << "Err\n" ;
    //         exit(1) ;
    // }
}


size_t sub(char aaSeq1, char aaSeq2) {
    std::map<char, size_t> aa2int ;
    aa2int['A'] = 0 ;
    aa2int['T'] = 1 ;
    aa2int['C'] = 2 ;
    aa2int['G'] = 3 ;

    size_t aa1 {aa2int[aaSeq1]} ;
    size_t aa2 {aa2int[aaSeq2]} ;

    size_t cost[4][4] {
        {0,2,3,4},
        {2,0,2,3},
        {3,2,0,2},
        {4,3,2,0}
    } ;

    return cost[aa1][aa2] ;
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


void wireMatrix_scoring(wireMatrix &matrix, const std::string &seq1, const std::string &seq2) {
    matrix[0][0] = 0 ;
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
    std::string seq1 {"ATCGGATCGATGCCCCCATGTTATATTT"} ;
    std::string seq2 {"ATCGGATCGATGATGGCATTGTGTTAT"} ;

    wireMatrix matrix {wireMatrix_initializer(seq1, seq2)} ;
    wireMatrix_scoring(matrix, seq1, seq2) ;

    for (size_t y=0 ; y<seq2.size() ; y++) {
        for (size_t x=0 ; x<seq1.size() ; x++) {
            if (matrix[x][y] < 10) {
                std::cout << matrix[x][y] << "  " ;
            } else {
                std::cout << matrix[x][y] << " " ;
            }
        }
        std::cout << "\n" ;
    }

    std::cout << "\n" ;
    
    print_result(matrix, seq1, seq2) ;

    return 0 ;
}


#endif