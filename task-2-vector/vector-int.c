#include "vector-type.h"
#include "vector-int.h"


IVectorInt createVectorInt(int size) {

    VectorInt* vector = (VectorInt*)malloc(sizeof(VectorInt));

    if (size > 0) {
        vector->buffer = (int*)malloc(size * sizeof(int));
        memset(vector->buffer, 0, size);
        vector->capacity = size;
        vector->count = size;
    } else {
        ZERO_SIZE_MESSAGE;
    }

    return vector;

}

int* getDataVectorInt(IVectorInt vector) {

    VectorInt* vectorPointer = (VectorInt*)vector;

    return vectorPointer->buffer;

}

void resizeVectorInt(IVectorInt vector) {

    VectorInt* vectorPointer = (VectorInt*)vector;

    vectorPointer->capacity = vectorPointer->capacity * 2;
    vectorPointer->buffer = realloc(vectorPointer->buffer, vectorPointer->capacity);

}

void appendVectorInt(IVectorInt vector, int value) {



}

void disposeVectorInt(IVectorInt vector) { // IS IT OKAY?

    VectorInt* vectorPointer = (VectorInt*)vector;

    free(vectorPointer->buffer);
    free(vectorPointer);

}

void insertVectorInt(IVectorInt vector, int position, int value) {

    VectorInt* vectorPointer = (VectorInt*)vector;

    // vectorPointer->buffer = memmove()

}

