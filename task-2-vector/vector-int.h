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

/**
 * Initialize vector.
 * 
 * @param size size of the required vector.
 * 
 * @return IVectorInt pointer to the initialized vector.
 */
IVectorInt initVectorInt(int size);

/**
 * Gets data from the vector.
 * 
 * @param vector IVectorInt pointer to the vector.
 * 
 * @return integer pointer to the data.
 */
int* getDataFromVectorInt(IVectorInt vector);

/** 
 * Add data to the end of the vector.
 * 
 * @param vector IVectorInt pointer to the vector.
 * @param value value element.
 */
void appendToVectorInt(IVectorInt vector, int value);

/**
 * Removes data at the end of the vector.
 * 
 * @param vector IVectorInt pointer to the vector.
 */
void remendFromVectorInt(IVectorInt vector);

/**
 * Gets value at specified index.
 * 
 * @param vector IVectorInt pointer to the vector.
 * @param position index of required element.
 * 
 * @return element at the position. 
 */
int elem(IVectorInt vector, int position);

/**
 * Inserts data into the vector at particular index.
 * 
 * @param vector IVectorInt pointer to the vector.
 * @param position required index of the new added element.
 * @param value value element. 
 */
void insertIntoVectorInt(IVectorInt vector, int position, int value);

/**
 * Removes data from the vector at particular index.
 * 
 * @param vector IVectorInt pointer to the vector.
 * @param position required index of element to be removed.
 */
void popFromVectorInt(IVectorInt vector, int position);

/**
 * Resizes vector to fit in more data.
 * 
 * @param vector IVectorInt pointer to the vector.
 */
void resizeVectorInt(IVectorInt vector);

/**
 * Deletes vector.
 * 
 * @param vector IVectorInt pointer to the vector.
 */
void disposeVectorInt(IVectorInt vector);

#endif
