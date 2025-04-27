/*

   _____     __      __       _             
  / ____|    \ \    / /      | |            
 | |  __ _____\ \  / /__  ___| |_ ___  _ __ 
 | | |_ |______\ \/ / _ \/ __| __/ _ \| '__|
 | |__| |       \  /  __/ (__| || (_) | |   
  \_____|        \/ \___|\___|\__\___/|_|   
                                            
                                            
    GVector: a data structure for generic types. 
    Functionality test file.
    Created by GrindelfP on 2025-04-27. 

*/
#include <stdio.h>
#include <stdlib.h>
#include "gvector.h"

// Helper function to print integer vector elements
void print_int_vector(IGVectorInt vec) {
    size_t size = GVector_size(vec);
    printf("[");
    for (size_t i = 0; i < size; ++i) {
        int* val = (int*)GVector_at(vec, i);
        if (val) {
            printf("%d", *val);
            if (i < size - 1) {
                printf(", ");
            }
        }
    }
    printf("]\n");
}

// Helper function to print float vector elements
void print_float_vector(IGVectorInt vec) {
    size_t size = GVector_size(vec);
    printf("[");
    for (size_t i = 0; i < size; ++i) {
        float* val = (float*)GVector_at(vec, i);
        if (val) {
            printf("%.2f", *val);
            if (i < size - 1) {
                printf(", ");
            }
        }
    }
    printf("]\n");
}

int main() {
    // ============= //
    // INTEGERS TEST //
    // ============= //
    printf("--- Testing Integer Vector ---\n");
    IGVectorInt int_vec = GVector_create(2, sizeof(int));
    printf("Initial size: %zu, capacity: %zu\n", GVector_size(int_vec), GVector_capacity(int_vec));

    int i1 = 10, i2 = 20, i3 = 30, i4 = 40;
    GVector_push_back(int_vec, &i1);
    GVector_push_back(int_vec, &i2);
    printf("After pushing two elements - size: %zu, capacity: %zu, elements: ", GVector_size(int_vec), GVector_capacity(int_vec));
    print_int_vector(int_vec);

    GVector_push_back(int_vec, &i3);
    printf("After pushing a third element - size: %zu, capacity: %zu, elements: ", GVector_size(int_vec), GVector_capacity(int_vec));
    print_int_vector(int_vec);

    int i_insert = 15;
    GVector_insert(int_vec, 1, &i_insert);
    printf("After inserting 15 at index 1 - size: %zu, capacity: %zu, elements: ", GVector_size(int_vec), GVector_capacity(int_vec));
    print_int_vector(int_vec);

    int* at_index_2 = (int*)GVector_at(int_vec, 2);
    if (at_index_2) {
        printf("Element at index 2: %d\n", *at_index_2);
    }

    GVector_pop_back(int_vec);
    printf("After pop_back - size: %zu, capacity: %zu, elements: ", GVector_size(int_vec), GVector_capacity(int_vec));
    print_int_vector(int_vec);

    GVector_erase(int_vec, 0);
    printf("After erasing element at index 0 - size: %zu, capacity: %zu, elements: ", GVector_size(int_vec), GVector_capacity(int_vec));
    print_int_vector(int_vec);

    GVector_resize(int_vec, 5);
    printf("After resizing to 5 - size: %zu, capacity: %zu, elements: ", GVector_size(int_vec), GVector_capacity(int_vec));
    print_int_vector(int_vec);

    GVector_resize(int_vec, 2);
    printf("After resizing to 2 - size: %zu, capacity: %zu, elements: ", GVector_size(int_vec), GVector_capacity(int_vec));
    print_int_vector(int_vec);

    GVector_clear(int_vec);
    printf("After clear - size: %zu, capacity: %zu, elements: ", GVector_size(int_vec), GVector_capacity(int_vec));
    print_int_vector(int_vec);

    GVector_destroy(int_vec);
    printf("Integer vector destroyed.\n\n");

    // Test with floats
    printf("--- Testing Float Vector ---\n");
    IGVectorInt float_vec = GVector_create(3, sizeof(float));
    printf("Initial size: %zu, capacity: %zu\n", GVector_size(float_vec), GVector_capacity(float_vec));

    float f1 = 1.1f, f2 = 2.2f, f3 = 3.3f, f_insert = 2.7f;
    GVector_push_back(float_vec, &f1);
    GVector_push_back(float_vec, &f2);
    printf("After pushing two elements - size: %zu, capacity: %zu, elements: ", GVector_size(float_vec), GVector_capacity(float_vec));
    print_float_vector(float_vec);

    GVector_insert(float_vec, 1, &f_insert);
    printf("After inserting 2.7 at index 1 - size: %zu, capacity: %zu, elements: ", GVector_size(float_vec), GVector_capacity(float_vec));
    print_float_vector(float_vec);

    float* at_index_0_float = (float*)GVector_at(float_vec, 0);
    if (at_index_0_float) {
        printf("Element at index 0: %.2f\n", *at_index_0_float);
    }

    GVector_pop_back(float_vec);
    printf("After pop_back - size: %zu, capacity: %zu, elements: ", GVector_size(float_vec), GVector_capacity(float_vec));
    print_float_vector(float_vec);

    GVector_erase(float_vec, 1);
    printf("After erasing element at index 1 - size: %zu, capacity: %zu, elements: ", GVector_size(float_vec), GVector_capacity(float_vec));
    print_float_vector(float_vec);

    GVector_resize(float_vec, 1);
    printf("After resizing to 1 - size: %zu, capacity: %zu, elements: ", GVector_size(float_vec), GVector_capacity(float_vec));
    print_float_vector(float_vec);

    GVector_destroy(float_vec);
    printf("Float vector destroyed.\n\n");

    // Test edge cases
    printf("--- Testing Edge Cases ---\n");
    IGVectorInt empty_vec = GVector_create(0, sizeof(int));
    printf("Empty vector created - size: %zu, capacity: %zu\n", GVector_size(empty_vec), GVector_capacity(empty_vec));

    int val = 5;
    GVector_push_back(empty_vec, &val);
    printf("Pushed to empty vector - size: %zu, capacity: %zu, elements: ", GVector_size(empty_vec), GVector_capacity(empty_vec));
    print_int_vector(empty_vec);

    GVector_pop_back(empty_vec);
    printf("Popped from vector with one element - size: %zu, capacity: %zu\n", GVector_size(empty_vec), GVector_capacity(empty_vec));

    printf("Trying to access out-of-bounds index: %p\n", GVector_at(empty_vec, 0));
    GVector_erase(empty_vec, 0); // Should handle gracefully
    printf("After erasing from empty (or size 0) vector - size: %zu\n", GVector_size(empty_vec));

    GVector_destroy(empty_vec);
    printf("Empty vector destroyed.\n");

    return 0;
}
