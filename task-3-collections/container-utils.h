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
/// Takes three arguments: first two are start and finish defining the range 
/// in a given container from which values equal to provided value (third agrgument)
/// is removed. Than the iterator, pointing to the end of a new container
/// with updated values is returned.
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

/// @brief Removes value which not fit the condition predicate.
///
/// Takes three arguments: first two are start and finish defining the range 
/// in a given container from which values which do not fit given 
/// predicate (third agrgument) is removed. Than the iterator, 
/// pointing to the end of a new container with updated values is returned.
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

/// @brief Transforms container using given function.
///
/// @tparam Function function type.
/// @tparam Iterator iterator type.
///
/// Takes three arguments: first two are start and finish defining the range 
/// in a given container from which values should be updated using given 
/// function (third agrgument). Than the iterator, pointing to the end of a new 
/// container with updated values is returned.
///
/// @param start lower bound of the range.
/// @param fin upper bound of the range.
/// @param fucntion function to transform the collection.
///
/// @return iterator for updated container.
template<typename Iterator, typename Function>
Iterator transform(Iterator start, Iterator fin, Function fucntion);

#endif // container_utils
