#include "grindelf-stack-int.h"

int main() {

    GrindelfStackInt* stack = createGrindelfStack(10);
    int* topValue = (int*)malloc(sizeof(int));

    printf("%s\n", "==== Empty stack top and pop tests ====");
    printf("%s: %d\n", "Top exit code" , topGrindelfStack(stack, topValue));
    printf("%s: %d\n", "Pop exit code" , popGrindelfStack(stack));

    printf("%s\n", "==== Stack pushed with values ====");

    for (int i = 0; i < 10; i++) {
        printf("%s %d %s %d\n", "Push exit code::" , pushGrindelfStack(stack, i), "with value", i);
    }

    printf("%s\n", "==== Full stack push test ====");

    printf("%s: %d\n", "Push exit code" , pushGrindelfStack(stack, 11));

    printf("%s\n", "==== Full stack top and pop test with output ====");

    for (int i = 0; i < 10; i++) {
        // int* topValue;
        
        printf("%s %d %s %d\n", "Top exit code::", topGrindelfStack(stack, topValue), "with value", *topValue);
        printf("%s %d\n", "Pop exit code::" , popGrindelfStack(stack));
    }

    deleteGrindelfStack(stack);

    free(topValue);
    
    return 0;
}