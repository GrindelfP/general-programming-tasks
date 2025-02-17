/*
   _____        _____ _             _    
  / ____|      / ____| |           | |   
 | |  __ _____| (___ | |_ __ _  ___| | __
 | | |_ |______\___ \| __/ _` |/ __| |/ /
 | |__| |      ____) | || (_| | (__|   < 
  \_____|     |_____/ \__\__,_|\___|_|\_\
                                         
    Grindelf-Stack. Integer dedicated stack header file.

    Created by GrindelfP on 2025-02-17.                                        

*/

#ifndef GRINDELF_QUEUE_QUEUE_H
#define GRINDELF_QUEUE_QUEUE_H

#define ERROR 1
#define OK 0

#define null_buffer_ stack->buffer = NULL;
#define null_size_ stack->size = -1;
#define null_count_ stack->count = -1;
#define NULL_GRINDELF_STACK_INT null_buffer_ null_count_ null_size_

#define SUCCESS_STACK_CREATION_MESSAGE printf("%s\n", "GrindelfStackInt initialized successfully")
#define NULL_GRINDELF_STACK_INT_MESSAGE printf("%s\n", "GrindelfStackInt initialized as NULL")
#include <stdlib.h>
#include <stdio.h>

/**
 * Struct for storing integer numbers in a stack data structure.
 * 
 * @param size number of the stack's 'slots' for integers
 * @param buffer integers in the stack
 * @param count number of integers stored in the stack 
 */
struct GrindelfStackInt {
    int size;
    int* buffer;
    int count;
} typedef GrindelfStackInt;

/**
 * Function to create a stack. Allocates memory for it, based on provided parameters.
 * count param of the GrindelfStackInt structure by default equals 0 
 * and buffer param is empty.
 * 
 * @param size required number of the stack's 'slots' for integers
 * 
 * @return pointer to the created stack.
 */
GrindelfStackInt* createGrindelfStack(int size);

/**
 * Function to push (add) integer to the stack. 
 * 
 * @param stack stack pointer to which the integer will be pushed
 * @param valueToPush variable, where the initial integer is stored
 * 
 * @return 0 if pushed sucessfully, 1 if stack full.
 */
int pushGrindelfStack(GrindelfStackInt* stack, int valueToPush);

/**
 * Function to pop (remove) integer from the stack. 
 * 
 * @param stack stack pointer from which the integer will be popped
 * 
 * @return 0 if popped sucessfully, 1 if stack was empty.
 */
int popGrindelfStack(GrindelfStackInt* stack);

/**
 * Function to check the top (the last added) integer from the stack. 
 * 
 * @param stack stack pointer from which the top integer is required
 * @param value variable, where the top integer value should be stored 
 * 
 * @return 0 if top integer value obttained sucessfully, 1 if stack was empty.
 */
int topGrindelfStack(GrindelfStackInt* stack, int* topValue);

/**
 * Function to free the memory allocated for the stack. 
 * 
 * @param stack stack to be deleted.
 * 
 * @return 0 if memory freed, 1 if some error during memory freeing occured.
 */
int deleteGrindelfStack(GrindelfStackInt* stack);

#endif
