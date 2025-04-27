/*
*
*	Task 6: Unique algotythm. 
*	Created by GrindelfP on 2024-04-07.
*
*/

#ifndef unique_h
#define unique_h

#include <vector>
#include <set>

namespace gunique {

    /// @brief Creates set over container.
    ///
    /// Takes container with values and fills a new one 
    /// (itOut is the iterator for the output container)
    /// only with unique values out of range [it1, it2]. 
    ///
    /// @tparam InIt type of input container iterator.
    /// @tparam OutIt type of output container iterator.
    /// @param it1 iterator, left bound of the initial container.
    /// @param it2 iterator, right bound of the initial container.
    /// @param itOut iterator, output container.
    /// @return iterator to the output container with unique values only.
    template <typename InIt, typename OutIt>
    OutIt unique(InIt it1, InIt it2, OutIt itOut) {
        std::set<typename std::iterator_traits<InIt>::value_type> seen;
        
        for (; it1 != it2; ++it1) {
            if (seen.find(*it1) == seen.end()) {
                *itOut++ = *it1;
                seen.insert(*it1);
            }
        }
        
        return itOut;
    }

    /// @brief Creates set over container.
    ///
    /// Takes container with values and fills a new one 
    /// (itOut is the iterator for the output container)
    /// only with unique values out of range [it1, it2]. 
    /// Works with unordered containers.
    ///
    /// @tparam InIt type of input container iterator.
    /// @tparam OutIt type of output container iterator.
    /// @param it1 iterator, left bound of the initial container.
    /// @param it2 iterator, right bound of the initial container.
    /// @param itOut iterator, output container.
    /// @return iterator to the output container with unique values only.
    template <typename InIt, typename OutIt>
    OutIt unique2(InIt it1, InIt it2, OutIt itOut) {
        std::unordered_set<typename std::iterator_traits<InIt>::value_type> seen;

        for (; it1 != it2; ++it1) {
            if (seen.find(*it1) == seen.end()) {
                *itOut++ = *it1;
                seen.insert(*it1);
            }
        }
        return itOut;
    }

}

#endif // unique_h
