/*

   _____     __      __       _             
  / ____|    \ \    / /      | |            
 | |  __ _____\ \  / /__  ___| |_ ___  _ __ 
 | | |_ |______\ \/ / _ \/ __| __/ _ \| '__|
 | |__| |       \  /  __/ (__| || (_) | |   
  \_____|        \/ \___|\___|\__\___/|_|   
                                            
                                            
    GVector: a data structure for generic types. 
    Public header file.
    Created by GrindelfP on 2025-04-27. 

*/

#ifndef gvector_h
#define gvector_h

#include <stddef.h>


/**
 * @brief Opaque pointer type for GVector.
 *
 * Users should use this type to declare instances of the GVector.
 * The actual structure definition is hidden from the user.
 */
#define IGVectorInt void*

/**
 * @brief Creates a new GVector with a specified initial capacity and element size.
 *
 * @param initial_capacity The initial number of elements the vector can hold.
 * @param element_size The size of each element in bytes that the vector will store.
 * @return An opaque pointer (IGVectorInt) to the newly created vector,
 * or NULL if memory allocation fails.
 */
IGVectorInt GVector_create(size_t initial_capacity, size_t element_size);

/**
 * @brief Destroys a GVector, freeing all associated memory.
 *
 * @param vec The opaque pointer (IGVectorInt) to the vector to be destroyed.
 * It is good practice to set the pointer to NULL after calling this function.
 */
void GVector_destroy(IGVectorInt vec);

/**
 * @brief Returns the current number of elements stored in the GVector.
 *
 * @param vec The opaque pointer (IGVectorInt) to the vector.
 * @return The number of elements currently in the vector. Returns 0 if the vector is NULL.
 */
size_t GVector_size(IGVectorInt vec);

/**
 * @brief Returns the current allocated capacity of the GVector.
 *
 * This is the total number of elements the vector can hold before a reallocation
 * might be necessary.
 *
 * @param vec The opaque pointer (IGVectorInt) to the vector.
 * @return The current capacity of the vector. Returns 0 if the vector is NULL.
 */
size_t GVector_capacity(IGVectorInt vec);

/**
 * @brief Adds a new element to the end of the GVector.
 *
 * The vector will automatically resize if the current capacity is not sufficient.
 *
 * @param vec The opaque pointer (IGVectorInt) to the vector.
 * @param element A pointer to the element to be added. The size of the data
 * pointed to must match the element size specified during creation.
 */
void GVector_push_back(IGVectorInt vec, const void* element);

/**
 * @brief Removes the last element from the GVector.
 *
 * This operation decreases the size of the vector but does not necessarily
 * reduce its capacity.
 *
 * @param vec The opaque pointer (IGVectorInt) to the vector.
 */
void GVector_pop_back(IGVectorInt vec);

/**
 * @brief Returns a pointer to the element at the specified index in the GVector.
 *
 * This function provides direct access to the stored element. It's crucial to
 * cast the returned `void*` to the appropriate data type.
 *
 * @param vec The opaque pointer (IGVectorInt) to the vector.
 * @param index The index of the element to access (0-based).
 * @return A pointer to the element at the specified index, or NULL if the
 * index is out of bounds or if the vector is NULL.
 */
void* GVector_at(IGVectorInt vec, size_t index);

/**
 * @brief Inserts a new element at a specified index in the GVector.
 *
 * Elements at and after the specified index are shifted to make space for the new element.
 * The vector will automatically resize if necessary.
 *
 * @param vec The opaque pointer (IGVectorInt) to the vector.
 * @param index The index at which the new element should be inserted (0-based).
 * Must be a valid index within the current size of the vector
 * (including the current size, which corresponds to appending).
 * @param element A pointer to the element to be inserted. The size of the data
 * pointed to must match the element size specified during creation.
 */
void GVector_insert(IGVectorInt vec, size_t index, const void* element);

/**
 * @brief Removes the element at a specified index in the GVector.
 *
 * Elements after the specified index are shifted to fill the gap.
 *
 * @param vec The opaque pointer (IGVectorInt) to the vector.
 * @param index The index of the element to remove (0-based).
 */
void GVector_erase(IGVectorInt vec, size_t index);

/**
 * @brief Removes all elements from the GVector, making it empty.
 *
 * This operation does not free the underlying allocated memory; the capacity
 * remains the same.
 *
 * @param vec The opaque pointer (IGVectorInt) to the vector.
 */
void GVector_clear(IGVectorInt vec);

/**
 * @brief Resizes the GVector to a new size.
 *
 * If the new size is larger than the current size, new (uninitialized) elements
 * are added to the end. If the new size is smaller than the current size,
 * elements are removed from the end. The capacity might be adjusted as needed.
 *
 * @param vec The opaque pointer (IGVectorInt) to the vector.
 * @param new_size The desired new size of the vector.
 */
void GVector_resize(IGVectorInt vec, size_t new_size);

#endif // gvector_h
