/*
*
*	Task 3: General algorythms for containers in C++. 
*	Created by GrindelfP on 2024-04-15.
*
*/

#include "container-utils.h"

template <typename Type, typename Iterator>
Iterator dremove(Iterator start, Iterator fin, Type value) {
    Iterator accumulator = start;

    for (; start != fin; ++start) {
        if (*start != value) {
            *accumulator++ = *start; // NOTE: maybe a bug: fix - add separate increment
        }
    }

    return accumulator;
}

template <typename Predicate, typename Iterator>
Iterator dremoveIf(Iterator start, Iterator fin, Predicate predicate) {
    Iterator accumulator = start;

    for (; start != fin; ++start) {
        if (predicate(*start)) {
            *accumulator++ = *start; // NOTE: maybe a bug: fix - add separate increment
        }
    }

    return accumulator;
}

template <typename Iterator, typename Function>
Iterator transform(Iterator start, Iterator fin, Function fucntion) {
    Iterator accumulator = start;

    for (; start != fin; ++start) {
        if (pred(*start)) {
            *accumulator++ = fucntion(*start); // NOTE: maybe a bug: fix - add separate increment
        }
    }

    return accumulator;
}
