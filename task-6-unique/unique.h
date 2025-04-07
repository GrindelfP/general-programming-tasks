/*
*
*	Task 6: Unique algotythm. 
*	Created by GrindelfP on 2024-04-07.
*
*/

#ifndef unique_h
#define unique_h

namespace guique {

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
    OutIt unique(InIt it1, InIt it2, OutIt itOut);

}

#endif // unique_h
