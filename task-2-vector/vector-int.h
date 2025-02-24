#ifndef vector_int
#define vector_int

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define IVectorInt void*
#define ZERO_SIZE_MESSAGE printf("%s\n", "Vector not initialized, size must be greater than 0!")

IVectorInt createVectorInt(int size);

int* getDataVectorInt(IVectorInt vector);

void resizeVectorInt(IVectorInt vector);

void appendVectorInt(IVectorInt vector, int value);

void disposeVectorInt(IVectorInt vector);

void insertVectorInt(IVectorInt vector, int position, int value);


#endif
