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
/// @tparam Type type of values in container.
/// @tparam Iterator iterator type.
/// 
/// @param start lower bound of the range.
/// @param fin upper bound of the range.
/// @param value value to be removed
/// 
/// @return iterator for updated container.
template<typename Type, typename Iterator>
Iterator dremove(Iterator start, Iterator fin, Type value);

/// @brief 
///
/// @tparam Predicate predicate type.
/// @tparam Iterator iterator type. 
///
/// @param start lower bound of the range.
/// @param fin upper bound of the range.
/// @param pred predicate for condition.
///
/// @return iterator for updated container.
template<typename Predicate, typename Iterator>
Iterator dremoveIf(Iterator start, Iterator fin, Predicate pred);

/// @brief 
///
/// @tparam Function function type.
/// @tparam Iterator iterator type.
///
/// @param start lower bound of the range.
/// @param fin upper bound of the range.
/// @param fucntion function to transform the collection.
///
/// @return iterator for updated container.
template<typename Iterator, typename Function>
Iterator transform(Iterator start, Iterator fin, Function fucntion);

#endif // container_utils
