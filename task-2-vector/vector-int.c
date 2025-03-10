/*

   _____     __      __       _             
  / ____|    \ \    / /      | |            
 | |  __ _____\ \  / /__  ___| |_ ___  _ __ 
 | | |_ |______\ \/ / _ \/ __| __/ _ \| '__|
 | |__| |       \  /  __/ (__| || (_) | |   
  \_____|        \/ \___|\___|\__\___/|_|   
                                            
                                            
    Grindelf-Vector. An integer-storing vector data structure source-code file.
    Created by GrindelfP on 2025-02-24. 

*/

#include "vector-type.h"
#include "vector-int.h"
#include "vector-macros.h"

IVectorInt initVectorInt(int size) {

    VectorInt* vector = (VectorInt*)malloc(sizeof(VectorInt));

    if (size >= 0) {
        vector->buffer = (int*)malloc(size * sizeof(int));
        memset(vector->buffer, 0, size * sizeof(int));
        vector->capacity = size;
        vector->count = 0;
    } else {
        NEGATIVE_SIZE_ERROR_MESSAGE;
    }

    return vector;
}

int* getDataFromVectorInt(IVectorInt vector) {

    CAST_VECTOR_INT;

    return vectorPointer->buffer;
}

void appendToVectorInt(IVectorInt vector, int value) {

    CAST_VECTOR_INT;

    if (vectorPointer->capacity == vectorPointer->count + 1) RESIZE_VECTOR;
    
    vectorPointer->buffer[vectorPointer->count++] = value;
}

void remendFromVectorInt(IVectorInt vector) {

    CAST_VECTOR_INT;

    if (vectorPointer->count > 0) vectorPointer->buffer[vectorPointer->count--] = NULL_INT;
    else EMPTY_VECTOR_WARNING_MESSAGE;
}

int elem(IVectorInt vector, int position) {

    int value;
    CAST_VECTOR_INT;

    if (position >= 0 && position <= vectorPointer->count) {
        value = vectorPointer->buffer[position];
    } else if (position > vectorPointer->count) { TOOBIG_INDEX_SCENARIO(value); }
    else { NEGATIVE_INDEX_SCENARIO(value); }
    
    return value;
}

void insertIntoVectorInt(IVectorInt vector, int position, int value) {
	
	// NOT IMPLEMENTED

    CAST_VECTOR_INT;

    while (position >= vectorPointer->capacity) RESIZE_VECTOR;
    if (vectorPointer->capacity == vectorPointer->count + 1) RESIZE_VECTOR;
    
    vectorPointer->buffer[position];
}

void popFromVectorInt(IVectorInt vector, int position) {
	
	// NOT IMPLEMENTED
	
}

void resizeVectorInt(IVectorInt vector) {

    CAST_VECTOR_INT;

    if (vectorPointer->capacity == 0) vectorPointer->capacity = 1;
    else vectorPointer->capacity = vectorPointer->capacity * 2;
    
    vectorPointer->buffer = realloc(vectorPointer->buffer, vectorPointer->capacity);
    
	memset(vectorPointer->buffer + vectorPointer->capacity/2, 0, vectorPointer->capacity / 2 * sizeof(int));
}

void disposeVectorInt(IVectorInt vector) {

    CAST_VECTOR_INT;

    free(vectorPointer->buffer);
    free(vectorPointer);
}

