#include <iostream>
#include <string>
#include <vector>
#include <map>
// #include <algorithm>

using wireMatrix = std::vector<std::vector<int>> ;

// Returns a wire matrix of size n+1, m+1 with all values set to 0
wireMatrix wireMatrix_initializer(const std::string &seq1, const std::string &seq2) {
    size_t northFront {seq1.size() + 1} ;
    size_t eastFront {seq2.size() + 1} ;
    wireMatrix matrix(northFront, std::vector<int>(eastFront, 0)) ;
    return matrix ;
}


int del(char aa) {
    switch (aa) {
        case 'A' :
            return 1 ;
            break ;
        case 'T' :
            return 2 ;
            break ;
        case 'C' :
            return 3 ;
            break ;
        case 'G' :
            return 4 ;
            break ;
        default :
            std::cout << "Err\n" ;
            exit(1) ;
    }
}


int ins(char aa) {
    switch (aa) {
        case 'A' :
            return 1 ;
            break ;
        case 'T' :
            return 2 ;
            break ;
        case 'C' :
            return 3 ;
            break ;
        case 'G' :
            return 4 ;
            break ;
        default :
            std::cout << "Err\n" ;
            exit(1) ;
    }
}


int sub(char aaSeq1, char aaSeq2) {
    std::map<char, int> aa2int ;
    aa2int['A'] = 0 ;
    aa2int['T'] = 1 ;
    aa2int['C'] = 2 ;
    aa2int['G'] = 3 ;

    int aa1 {aa2int[aaSeq1]} ;
    int aa2 {aa2int[aaSeq2]} ;

    int cost[4][4] {
        {0,2,3,4},
        {2,0,2,3},
        {3,2,0,2},
        {4,3,2,0}
    } ;

    return cost[aa1][aa2] ;
}


int min(int del, int ins, int sub) {
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
    for (size_t x=1 ; x<matrix.size() ; x++) {
        matrix[x][0] = matrix[x-1][0] + del(seq1[x-1]) ;
    }
    for (size_t y=1 ; y<matrix[0].size() ; y++) {
        matrix[0][y] = matrix[0][y-1] + ins(seq2[y-1]) ;
        for (size_t x=1 ; x<matrix.size() ; x++) {
            int delCost {matrix[x-1][y] + del(seq1[x-1])} ;
            int insCost {matrix[x][y-1] + ins(seq2[y-1])} ;
            int subCost {matrix[x-1][y-1] + sub(seq1[x-1], seq2[y-1])} ;
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
    size_t i {seq1.size()} ;
    size_t j {seq2.size()} ;

    std::string alSeq1 ;
    std::string alLink ;
    std::string alSeq2 ;

    while (i!=0 && j!= 0) {
        size_t goUp {matrix[j-1][i]} ;
        size_t goLeft {matrix[j][i-1]} ;
        size_t goDiag {matrix[j-1][i-1]} ;
        if (goDiag <= goUp && goDiag <= goLeft) {
            alSeq1 += seq1[i-1] ;
            if (seq1[i-1] == seq2[j-1]) {
                alLink += '|' ;
            } else {
                alLink += '*' ;
            }
            alSeq2 += seq2[j-1] ;
            i-- ;
            j-- ;
        } else if (goUp < goDiag && goUp < goLeft) {
            alSeq1 += '-' ;
            alLink += 'i' ;
            alSeq2 += seq2[j-1] ;
            j-- ;
        } else {
            alSeq1 += seq1[i-1] ;
            alLink += 'd' ;
            alSeq2 += '-' ;
            i-- ;
        }
    }
    while (i!=0) {
        alSeq1 += seq1[i-1] ;
        alLink += 'd' ;
        alSeq2 += '-' ;
        i-- ;
    }
    while (j!=0) {
        alSeq1 += '-' ;
        alLink += 'i' ;
        alSeq2 += seq2[j-1] ;
        j-- ;
    }

    reverse_string(alSeq1) ;
    reverse_string(alLink) ;
    reverse_string(alSeq2) ;

    std::cout << alSeq1 << "\n" ;
    std::cout << alLink << "\n" ;
    std::cout << alSeq2 << "\n" ;
}

int main() {
    // std::string seq1 {"ATCGATGCATGCGGCTTAGC"} ;
    // std::string seq2 {"GCGAATGGGCTAGGATCGAT"} ;
    std::string seq1 {"ATCGGATCGATGCCCCCATGTTATATT"} ;
    std::string seq2 {"ATCGGATCGATGATGGCATTGTGTTAT"} ;

    wireMatrix matrix {wireMatrix_initializer(seq1, seq2)} ;
    wireMatrix_scoring(matrix, seq1, seq2) ;

    for (int i=0 ; i<matrix.size() ; i++) {
        for (int j=0 ; j<matrix[i].size() ; j++) {
            if (matrix[j][i] < 10) {
                std::cout << matrix[j][i] << "  " ;
            } else {
                std::cout << matrix[j][i] << " " ;
            }
        }
        std::cout << "\n" ;
    }

    std::cout << "\n" ;
    
    print_result(matrix, seq1, seq2) ;

    return 0 ;
}