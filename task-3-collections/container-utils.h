/*
*
*	Task 3: General algorythms for containers in C++. 
*	Created by GrindelfP on 2024-04-15.
*
*/
#ifndef container_utils
#define container_utils

/// @brief Removes specific values within given range.
/// 
/// @tparam T type of values in container.
/// @tparam I iterator type.
/// 
/// @param start lower bound of the range.
/// @param fin upper bound of the range.
/// @param value value to be removed
/// 
/// @return iterator for updated container.
template<typename T, typename I>
I dremove(I start, I fin, T value);

/// @brief 
///
/// @tparam P predicate type.
/// @tparam I iterator type. 
///
/// @param start lower bound of the range.
/// @param fin upper bound of the range.
/// @param pred predicate for condition.
///
/// @return iterator for updated container.
template<typename P, typename I>
I dremoveIf(I start, I fin, P pred);

/// @brief 
///
/// @tparam F function type.
/// @tparam I iterator type.
///
/// @param start lower bound of the range.
/// @param fin upper bound of the range.
/// @param fucnt function to transform the collection.
///
/// @return iterator for updated container.
template<typename I, typename F>
I transform(I start, I fin, F fucnt);

#endif // container_utils
