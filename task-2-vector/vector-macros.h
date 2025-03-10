#ifndef vector_macros
#define vector_macros

#include <limits.h>

#define NULL_VAL INT_MIN
#define RESIZE_VECTOR resizeVectorInt(vector); vectorPointer = (VectorInt*)vector
#define CAST_VECTOR_INT VectorInt* vectorPointer = (VectorInt*)vector
#define negative_size_error_text_ "Vector not initialized, size must be greater of equal than 0!"
#define NEGATIVE_SIZE_ERROR_MESSAGE fprintf(stderr, "%s\n", negative_size_error_text_)
#define negative_index_error_text_ "Index cannot be negative!"
#define negative_index_error_message_ fprintf(stderr, "%s\n", negative_index_error_text_)
#define NEGATIVE_INDEX_SCENARIO(value) negative_index_error_message_; value = NULL_VAL
#define NEGATIVE_INDEX_WARNING negative_index_error_message_
#define toobig_index_error_text_ "Index exeeds capacity of vector!"
#define toobig_index_error_message_ fprintf(stderr, "%s\n", toobig_index_error_text_)
#define TOOBIG_INDEX_SCENARIO(value) toobig_index_error_message_; value = NULL_VAL
#define empty_vector_warning_text_ "Vector is empty. NULL is returned!"
#define EMPTY_VECTOR_WARNING_MESSAGE fprintf(stderr, "%s\n", empty_vector_warning_text_)
#define insert_after_data_text_ "Attempt to insert beyond data row. Use append functionality to expand the data row!"
#define INSERT_AFTER_DATA_MESSAGE fprintf(stderr, "%s\n", insert_after_data_text_)
#define pop_after_data_text_ "Attempt to pop data beyond data row!"
#define POP_AFTER_DATA_MESSAGE fprintf(stderr, "%s\n", insert_after_data_text_)

#endif

