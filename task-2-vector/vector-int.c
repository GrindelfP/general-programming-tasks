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

IVectorInt createVectorInt(int size) {

    VectorInt* vector = (VectorInt*)malloc(sizeof(VectorInt));

    if (size > 0 || size == 0) {
        vector->buffer = (int*)malloc(size * sizeof(int));
        memset(vector->buffer, 0, size);
        vector->capacity = size;
        vector->count = size;
    } else {
        WRONG_SIZE_MESSAGE;
    }

    return vector;
}

int* getDataVectorInt(IVectorInt vector) {

    VectorInt* vectorPointer = (VectorInt*)vector;

    return vectorPointer->buffer;
}

void resizeVectorInt(IVectorInt vector) {

    VectorInt* vectorPointer = (VectorInt*)vector;

    if (vectorPointer->capacity == 0) vectorPointer->capacity = 1;
    else vectorPointer->capacity = vectorPointer->capacity * 2;
    
    vectorPointer->buffer = realloc(vectorPointer->buffer, vectorPointer->capacity);
    
    for (size_t i = vectorPointer->capacity / 2; i < vectorPointer->capacity; ++i) {
        memset(vectorPointer->buffer[i], 0, sizeof(int));
    }
}

void appendVectorInt(IVectorInt vector, int value) {

    VectorInt* vectorPointer = (VectorInt*)vector;

    if (vectorPointer->capacity == vectorPointer->count) {
        resizeVectorInt(vector);
        vectorPointer = (VectorInt*)vector;
    } 
    vectorPointer->count++;
    memset(vectorPointer->buffer[vectorPointer->count], value, sizeof(int));
}

void disposeVectorInt(IVectorInt vector) {

    VectorInt* vectorPointer = (VectorInt*)vector;

    for (size_t i = 0; i < vectorPointer->capacity; ++i) {
        free(vectorPointer->buffer[i]);
    }
    free(vectorPointer->buffer);
    free(vectorPointer);
}

void insertVectorInt(IVectorInt vector, int position, int value) {

    VectorInt* vectorPointer = (VectorInt*)vector;

    if (vectorPointer->capacity == vectorPointer->count) {
        resizeVectorInt(vector);
        vectorPointer = (VectorInt*)vector;
    }

    while (position <= vectorPointer->capacity) {
        resizeVectorInt(vector);
        vectorPointer = (VectorInt*)vector;
    }
    
    vectorPointer->count = vectorPointer->capacity;
    vectorPointer->buffer[position];

    
}

