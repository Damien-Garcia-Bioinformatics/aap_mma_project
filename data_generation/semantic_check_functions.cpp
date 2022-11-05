// Advanced Algorithmics and Programming & Models, Methods and Programming Project
// Damien GARCIA, Florian ECHELARD
// M2BB


////////////////////////////////////////////////////////////////////////////////
//                           Functions definition                             //
////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include "semantic_check_functions.hpp" 


// Function checking if interval of generation is contained in maximum of length of traces to generate.
void check_length(std::vector<genParam> &generation, size_t maxLen) {
    size_t theoMin {0} ;
    size_t theoMax {0} ;
    for (size_t i=0 ; i< generation.size() ; i++) {
        theoMin += generation[i].minSize ;
        theoMax += generation[i].maxSize ;
    }
    if (theoMin > maxLen || theoMax > maxLen) {
        std::cout << "[semantic_check] Error code 3 :" << std::endl ;
        std::cout << "[semantic_check] Interval values allows sequence generation over maximum length defined limit." << std::endl ;
        exit(3) ;
    }
}


//----------------------------------------------------------------------------//


// Function checking if an element exists in a vector.
bool exists_in_vector(const std::vector<std::string> &vector, std::string &element) {
    for (size_t i=0 ; i<vector.size() ; i++) {
        if (element == vector.at(i)) {
            return true ;
        }
    }
    return false ;
}


//----------------------------------------------------------------------------//


// Function cheking availability of events or if it's already used as anchor.
bool is_available_event(genParam &generation, std::vector<std::string> &elements) {
    for (size_t i=0 ; i<generation.events.size() ; i++) {
        // Deletion of unavailable event and attribute from generation structure
        if (exists_in_vector(elements, generation.events[i])) {
            generation.events.erase(generation.events.begin()+i) ;
            generation.attributes.erase(generation.attributes.begin()+i) ;
        }
    }
    // Check if there are still available events for generation
    if (generation.events.size() == 0) {
        return false ;
    }
    return true ;
}


//----------------------------------------------------------------------------//


// Procedure cheking uniqueness of anchors and disponibility of events in generative regions.
void check_anchors_and_events(std::vector<genParam> &generation) {
    std::vector<std::string> anchors ; //Vector containing all anchors in expression

    // Checking anchors
    for (size_t i=0 ; i<generation.size() ; i++) {
        if (generation[i].typeSection == 0) {
            if (exists_in_vector(anchors, generation[i].anchor)) {
                std::cout << "[semantic_check] Error code 3 :" << std::endl ;
                std::cout << "[semantic_check] Multiple occurance of the same anchor : " << generation[i].anchor << std::endl ;
                exit(3) ;
            }
            anchors.push_back(generation[i].anchor) ;
        }
    }

    // Checking events
    for (size_t i=0 ; i<generation.size() ; i++) {
        if (generation[i].typeSection == 2) {
            if (!is_available_event(generation[i], anchors)) {
                std::cout << "[semantic_check] Error code 3 :" << std::endl ;
                std::cout << "[semantic_check] All possible events in generative region are already used as anchors." << std::endl ;
                exit(3) ;
            }
        }
    }
}