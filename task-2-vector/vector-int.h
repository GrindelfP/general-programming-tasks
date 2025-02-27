/*

   _____     __      __       _             
  / ____|    \ \    / /      | |            
 | |  __ _____\ \  / /__  ___| |_ ___  _ __ 
 | | |_ |______\ \/ / _ \/ __| __/ _ \| '__|
 | |__| |       \  /  __/ (__| || (_) | |   
  \_____|        \/ \___|\___|\__\___/|_|   
                                            
                                            
    Grindelf-Vector. An integer-storing vector data structure header file.
    Created by GrindelfP on 2025-02-24. 

*/
#ifndef vector_int
#define vector_int

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define IVectorInt void*
#define WRONG_SIZE_MESSAGE printf("%s\n", "Vector not initialized, size must be greater of equal than 0!")

/**
 * Initialize vector.
 * 
 * @param size size of the required vector.
 * 
 * @return IVectorInt pointer to the initialized vector.
 */
IVectorInt createVectorInt(int size);

/**
 * Gets data from the vector.
 * 
 * @param vector IVectorInt pointer to the vector.
 * 
 * @return integer pointer to the data.
 */
int* getDataVectorInt(IVectorInt vector);

/**
 * Resizes vector to fit in more data.
 * 
 * @param vector IVectorInt pointer to the vector.
 */
void resizeVectorInt(IVectorInt vector);

/**
 * Add data to the end of the filled part of the vector.
 * 
 * @param vector IVectorInt pointer to the vector.
 * @param value value element.
 */
void appendVectorInt(IVectorInt vector, int value);

/**
 * Deletes vector.
 * 
 * @param vector IVectorInt pointer to the vector.
 */
void disposeVectorInt(IVectorInt vector);

/**
 * Inserts data into the vector at particular index.
 * 
 * @param vector IVectorInt pointer to the vector.
 * @param position required index of the new added element.
 * @param value value element. 
 */
void insertVectorInt(IVectorInt vector, int position, int value);

#endif
