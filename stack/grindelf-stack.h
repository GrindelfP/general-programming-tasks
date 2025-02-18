/*
   _____        _____ _             _    
  / ____|      / ____| |           | |   
 | |  __ _____| (___ | |_ __ _  ___| | __
 | | |_ |______\___ \| __/ _` |/ __| |/ /
 | |__| |      ____) | || (_| | (__|   < 
  \_____|     |_____/ \__\__,_|\___|_|\_\
                                         
    Grindelf-Stack. General-purposed stack header file.

    Created by GrindelfP on 2025-02-17.                                        

*/

#ifndef GRINDELF_QUEUE_QUEUE_H
#define GRINDELF_QUEUE_QUEUE_H

#define ERROR 1
#define OK 0

#define null_buffer_ stack->buffer = NULL;
#define null_size_ stack->size = -1;
#define null_count_ stack->count = -1;
#define NULL_GRINDELF_STACK null_buffer_ null_count_ null_size_

#define SUCCESS_STACK_CREATION_MESSAGE printf("%s\n", "GrindelfStack initialized successfully")
#define SUCCESS_STACK_FREING_MESSAGE printf("%s\n", "GrindelfStack deleted successfully")
#define NULL_GRINDELF_STACK_MESSAGE printf("%s\n", "GrindelfStack initialized as NULL")
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct GrindelfStack {
    size_t size;       // number of slots
    void** buffer;     // pointer to void pointers, can store any type
    int count;         // number of elements in the stack
    size_t elementSize; // size of each element type
} typedef GrindelfStack;

/**
 * Function to create a stack. Allocates memory for it, based on provided parameters.
 * 
 * @param size required number of the stack's 'slots'
 * @param elementSize size of the element type to be stored in the stack
 * 
 * @return pointer to the created stack.
 */
GrindelfStack* createGrindelfStack(int size, size_t elementSize);

/**
 * Function to push (add) an element to the stack. 
 * 
 * @param stack stack pointer to which the element will be pushed
 * @param valueToPush pointer to the data to be pushed
 * 
 * @return 0 if pushed successfully, 1 if stack is full.
 */
int pushGrindelfStack(GrindelfStack* stack, void* valueToPush);

/**
 * Function to pop (remove) an element from the stack. 
 * 
 * @param stack stack pointer from which the element will be popped
 * 
 * @return 0 if popped successfully, 1 if stack was empty.
 */
int popGrindelfStack(GrindelfStack* stack);

/**
 * Function to check the top (the last added) element from the stack. 
 * 
 * @param stack stack pointer from which the top element is required
 * @param value pointer to the variable where the top element value will be stored
 * 
 * @return 0 if top element value obtained successfully, 1 if stack was empty.
 */
int topGrindelfStack(GrindelfStack* stack, void** value);

/**
 * Function to free the memory allocated for the stack. 
 * 
 * @param stack stack to be deleted.
 * 
 * @return 0 if memory freed, 1 if some error during memory freeing occurred.
 */
int deleteGrindelfStack(GrindelfStack* stack);

#endif
