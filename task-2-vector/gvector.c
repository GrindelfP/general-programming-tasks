/*

   _____     __      __       _             
  / ____|    \ \    / /      | |            
 | |  __ _____\ \  / /__  ___| |_ ___  _ __ 
 | | |_ |______\ \/ / _ \/ __| __/ _ \| '__|
 | |__| |       \  /  __/ (__| || (_) | |   
  \_____|        \/ \___|\___|\__\___/|_|   
                                            
                                            
    GVector: a data structure for generic types. 
    Source code file. NOT AVAILABLE IN USAGE.
    Created by GrindelfP on 2025-04-27. 

*/
#include "gvector-private.h"
#include "gvector.h" // Include the public header for the opaque type

IGVectorInt GVector_create(size_t initial_capacity, size_t element_size) {
    GVectorInternal* vec = (GVectorInternal*)malloc(sizeof(GVectorInternal));
    if (!vec) {
        perror("Failed to allocate GVector");
        return NULL;
    }

    vec->data = malloc(initial_capacity * element_size);
    if (!vec->data) {
        perror("Failed to allocate initial data for GVector");
        free(vec);
        return NULL;
    }

    vec->size = 0;
    vec->capacity = initial_capacity;
    vec->element_size = element_size;
    return (IGVectorInt)vec;
}

void GVector_destroy(IGVectorInt vec_ptr) {
    GVectorInternal* vec = (GVectorInternal*)vec_ptr;
    if (vec) {
        free(vec->data);
        free(vec);
    }
}

size_t GVector_size(IGVectorInt vec_ptr) {
    GVectorInternal* vec = (GVectorInternal*)vec_ptr;
    return vec ? vec->size : 0;
}

size_t GVector_capacity(IGVectorInt vec_ptr) {
    GVectorInternal* vec = (GVectorInternal*)vec_ptr;
    return vec ? vec->capacity : 0;
}

void GVector_push_back(IGVectorInt vec_ptr, const void* element) {
    GVectorInternal* vec = (GVectorInternal*)vec_ptr;
    if (!vec || !element) return;

    if (vec->size == vec->capacity) {
        vec->capacity = (vec->capacity == 0) ? 1 : vec->capacity * 2;
        void* new_data = realloc(vec->data, vec->capacity * vec->element_size);
        if (!new_data) {
            perror("Failed to reallocate memory for GVector");
            return;
        }
        vec->data = new_data;
    }

    memcpy((char*)vec->data + vec->size * vec->element_size, element, vec->element_size);
    vec->size++;
}

void GVector_pop_back(IGVectorInt vec_ptr) {
    GVectorInternal* vec = (GVectorInternal*)vec_ptr;
    if (vec && vec->size > 0) {
        vec->size--;
    }
}

void* GVector_at(IGVectorInt vec_ptr, size_t index) {
    GVectorInternal* vec = (GVectorInternal*)vec_ptr;
    if (vec && index < vec->size) {
        return (char*)vec->data + index * vec->element_size;
    }
    fprintf(stderr, "Error: Index out of bounds in GVector_at\n");
    return NULL;
}

void GVector_insert(IGVectorInt vec_ptr, size_t index, const void* element) {
    GVectorInternal* vec = (GVectorInternal*)vec_ptr;
    if (!vec || !element || index > vec->size) {
        fprintf(stderr, "Error: Invalid index in GVector_insert\n");
        return;
    }

    if (vec->size == vec->capacity) {
        vec->capacity = (vec->capacity == 0) ? 1 : vec->capacity * 2;
        void* new_data = realloc(vec->data, vec->capacity * vec->element_size);
        if (!new_data) {
            perror("Failed to reallocate memory for GVector");
            return;
        }
        vec->data = new_data;
    }

    // Shift elements to make space
    memmove((char*)vec->data + (index + 1) * vec->element_size,
            (char*)vec->data + index * vec->element_size,
            (vec->size - index) * vec->element_size);

    // Copy the new element
    memcpy((char*)vec->data + index * vec->element_size, element, vec->element_size);
    vec->size++;
}

void GVector_erase(IGVectorInt vec_ptr, size_t index) {
    GVectorInternal* vec = (GVectorInternal*)vec_ptr;
    if (vec && index < vec->size) {
        // Shift elements to overwrite the one being erased
        memmove((char*)vec->data + index * vec->element_size,
                (char*)vec->data + (index + 1) * vec->element_size,
                (vec->size - 1 - index) * vec->element_size);
        vec->size--;
    } else {
        fprintf(stderr, "Error: Index out of bounds in GVector_erase\n");
    }
}

void GVector_clear(IGVectorInt vec_ptr) {
    GVectorInternal* vec = (GVectorInternal*)vec_ptr;
    if (vec) {
        vec->size = 0; // Simply reset the size, the allocated memory remains
    }
}

void GVector_resize(IGVectorInt vec_ptr, size_t new_size) {
    GVectorInternal* vec = (GVectorInternal*)vec_ptr;
    if (!vec) return;

    if (new_size > vec->capacity) {
        size_t new_capacity = new_size * 2; // Allocate more than needed to reduce reallocations
        void* new_data = realloc(vec->data, new_capacity * vec->element_size);
        if (!new_data) {
            perror("Failed to reallocate memory for GVector_resize");
            return;
        }
        vec->data = new_data;
        vec->capacity = new_capacity;
    }
    vec->size = new_size;
}
