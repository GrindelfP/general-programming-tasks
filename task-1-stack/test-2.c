#include "grindelf-stack.h"

int main() {
    // Create a stack for doubles (sizeof(double))
    GrindelfStack* stackDouble = createGrindelfStack(10, sizeof(double));

    // Push doubles onto the stack
    for (int i = 0; i < 10; i++) {
        double* val = (double*)malloc(sizeof(double));
        *val = 3.14 * i;  // Assign a value
        pushGrindelfStack(stackDouble, val);
    }

    // Access and print values from the double stack
    for (int i = 0; i < 10; i++) {
        double* topValue = NULL;
        topGrindelfStack(stackDouble, (void**)&topValue);
        printf("Top value (double): %f\n", *topValue);
        free(topValue);  // Free memory after use
        popGrindelfStack(stackDouble);
    }

    // Delete stack after use
    deleteGrindelfStack(stackDouble);

    // Create a stack for characters (sizeof(char))
    GrindelfStack* stackChar = createGrindelfStack(10, sizeof(char));

    // Push characters onto the stack
    for (int i = 0; i < 10; i++) {
        char* val = (char*)malloc(sizeof(char));
        *val = 'A' + i;  // Assign a value
        pushGrindelfStack(stackChar, val);
    }

    // Access and print values from the char stack
    for (int i = 0; i < 10; i++) {
        char* topValue = NULL;
        topGrindelfStack(stackChar, (void**)&topValue);
        printf("Top value (char): %c\n", *topValue);
        free(topValue);  // Free memory after use
        popGrindelfStack(stackChar);
    }

    // Delete stack after use
    deleteGrindelfStack(stackChar);

    return 0;
}
