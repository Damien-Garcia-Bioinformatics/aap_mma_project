#include "miscellaneous.hpp"

size_t randint(size_t min, size_t max) {
    return rand()%(max)+min ;
}