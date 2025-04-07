/*
*
*	Task 6: Unique algotythm. 
*	Created by GrindelfP on 2024-04-07.
*
*/

#include "unique.h"
#include <vector>
#include <set>

template <typename InIt, typename OutIt>
OutIt guique::unique(InIt it1, InIt it2, OutIt itOut) {
    std::set<typename std::iterator_traits<InIt>::value_type> seen;
    
    for (; it1 != it2; ++it1) {
        if (seen.find(*it1) == seen.end()) {
            *itOut++ = *it1;
            seen.insert(*it1);
        }
    }
    
    return itOut;
}
