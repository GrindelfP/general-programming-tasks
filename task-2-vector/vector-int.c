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
        memset(vector->buffer, 0, size);
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
    
    memset(vectorPointer->buffer[vectorPointer->count++], value, sizeof(int));
}

void remendFromVectorInt(IVectorInt vector) {

    CAST_VECTOR_INT;

    if (vectorPointer->count > 0) vectorPointer->buffer[vectorPointer->count--] = NULL;
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

    // TODO: wrong logic

    CAST_VECTOR_INT;

    if (vectorPointer->capacity == vectorPointer->count + 1) RESIZE_VECTOR;
    while (position <= vectorPointer->capacity) RESIZE_VECTOR;
    
    vectorPointer->count = vectorPointer->capacity;
    vectorPointer->buffer[position];
}

void resizeVectorInt(IVectorInt vector) {

    CAST_VECTOR_INT;

    if (vectorPointer->capacity == 0) vectorPointer->capacity = 1;
    else vectorPointer->capacity = vectorPointer->capacity * 2;
    
    vectorPointer->buffer = realloc(vectorPointer->buffer, vectorPointer->capacity);
    
    for (size_t i = vectorPointer->capacity / 2; i < vectorPointer->capacity; ++i) {
        memset(vectorPointer->buffer[i], 0, sizeof(int));
    }
}

void disposeVectorInt(IVectorInt vector) {

    CAST_VECTOR_INT;

    for (size_t i = 0; i < vectorPointer->capacity; ++i) {
        free(vectorPointer->buffer[i]);
    }
    free(vectorPointer->buffer);
    free(vectorPointer);
}
