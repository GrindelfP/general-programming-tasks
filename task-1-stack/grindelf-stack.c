/*
   _____        _____ _             _    
  / ____|      / ____| |           | |   
 | |  __ _____| (___ | |_ __ _  ___| | __
 | | |_ |______\___ \| __/ _` |/ __| |/ /
 | |__| |      ____) | || (_| | (__|   < 
  \_____|     |_____/ \__\__,_|\___|_|\_\
                                         
    Grindelf-Stack. General-purposed stack source code file.

    Created by GrindelfP on 2025-02-17.                                        

*/

#include "grindelf-stack.h"

GrindelfStack* createGrindelfStack(int size, size_t elementSize) {
    GrindelfStack* stack = (GrindelfStack*)malloc(sizeof(GrindelfStack));

    if (size > 0) {
        stack->size = size;
        stack->elementSize = elementSize; // Store the element size
        stack->buffer = (void**)malloc(size * sizeof(void*)); // Allocate memory for pointers to elements
        stack->count = 0;
        SUCCESS_STACK_CREATION_MESSAGE;
    } else {
        NULL_GRINDELF_STACK;
        NULL_GRINDELF_STACK_MESSAGE;
    }

    return stack;
}

int pushGrindelfStack(GrindelfStack* stack, void* valueToPush) {
    int state = ERROR;

    if (stack->count < stack->size) {
        stack->buffer[stack->count] = malloc(stack->elementSize);  // Allocate memory for the element
        memcpy(stack->buffer[stack->count], valueToPush, stack->elementSize);  // Copy the value into the allocated space
        stack->count++;
        state = OK;
    }

    return state;
}

int popGrindelfStack(GrindelfStack* stack) {
    int state = ERROR;

    if (stack->count > 0) {
        free(stack->buffer[stack->count - 1]);  // Free the memory of the popped element
        stack->count--;
        state = OK;
    }

    return state;
}

int topGrindelfStack(GrindelfStack* stack, void** value) {
    int state = ERROR;

    if (stack->count > 0) {
        *value = malloc(stack->elementSize);  // Allocate memory for the top element
        memcpy(*value, stack->buffer[stack->count - 1], stack->elementSize);  // Copy the top element into the provided pointer
        state = OK;
    }

    return state;
}

int deleteGrindelfStack(GrindelfStack* stack) {
    int state = OK;

    for (int i = 0; i < stack->count; i++) {
        free(stack->buffer[i]);
    }

    free(stack->buffer);
    free(stack);

    SUCCESS_STACK_FREING_MESSAGE;

    return state;
}
