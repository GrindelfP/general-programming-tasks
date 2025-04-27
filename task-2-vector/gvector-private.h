/*

   _____     __      __       _             
  / ____|    \ \    / /      | |            
 | |  __ _____\ \  / /__  ___| |_ ___  _ __ 
 | | |_ |______\ \/ / _ \/ __| __/ _ \| '__|
 | |__| |       \  /  __/ (__| || (_) | |   
  \_____|        \/ \___|\___|\__\___/|_|   
                                            
                                            
    GVector: a data structure for generic types. 
    Private header file. NOT AVAILABLE IN USAGE.
    Created by GrindelfP on 2025-04-27. 

*/

#ifndef gvector_private_h
#define gvector_private_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct GVectorInternal {
    void* data;          // Pointer to the dynamically allocated array
    size_t size;         // Number of elements currently stored
    size_t capacity;     // Total allocated space
    size_t element_size; // Size of each element in bytes
} GVectorInternal;

#endif // gvector_private_h
