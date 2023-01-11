// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


////////////////////////////////////////////////////////////////////////////////
//                            Function declaration                            //
////////////////////////////////////////////////////////////////////////////////


#ifndef __WIREMATRIX__
#define __WIREMATRIX__


#include <string>
#include <vector>

#include "structures.hpp"


float del(vectors &, size_t) ;


float ins(vectors &, size_t) ;


float sub(vectors &, vectors &, size_t, size_t) ;


wireMatrix wireMatrix_scoring(vectors &, vectors &) ;


vectors pairwiseAlign(wireMatrix &, vectors &, vectors &) ;


void print_alignment(vectors &) ;


void print_alignment_v2(vectors) ;

void print_wirematrix(wireMatrix &) ;


#endif