/*
   _____        _____ _             _    
  / ____|      / ____| |           | |   
 | |  __ _____| (___ | |_ __ _  ___| | __
 | | |_ |______\___ \| __/ _` |/ __| |/ /
 | |__| |      ____) | || (_| | (__|   < 
  \_____|     |_____/ \__\__,_|\___|_|\_\
                                         
    Grindelf-Stack. Integer dedicated stack source code file.

    Created by GrindelfP on 2025-02-17.                                        

*/

#include "grindelf-stack-int.h"

GrindelfStackInt* createGrindelfStack(int size) {

    GrindelfStackInt* stack = (GrindelfStackInt*)malloc(sizeof(GrindelfStackInt));

    if (size > 0) {
        stack->size = size;
        stack->buffer = (int *)malloc(size * sizeof(int));
        stack->count = 0;
        SUCCESS_STACK_CREATION_MESSAGE;
    } else {
        NULL_GRINDELF_STACK_INT;
        NULL_GRINDELF_STACK_INT_MESSAGE;
    }

    return stack;
}

int pushGrindelfStack(GrindelfStackInt* stack, int valueToPush) {

    int state = ERROR;

    if (stack->count != stack->size) {
        stack->count++;
        stack->buffer[stack->count] = valueToPush;
        state = OK;
    }
    
    return state;
};

int popGrindelfStack(GrindelfStackInt* stack) {
    int state = ERROR;

    if (stack->count > 0) {
        stack->count--;
        state = OK;
    } 

    return state;
}

int topGrindelfStack(GrindelfStackInt* stack, int* topValue) {

    int state = ERROR;

    if (stack->count > 0) {
        *topValue = stack->buffer[stack->count];
        state = OK;
    }

    return state;
}

int deleteGrindelfStack(GrindelfStackInt* stack) {

    int state = OK; // bad code

    free(stack->buffer);
    free(stack);

    return state;
}
