#ifndef vector_macros
#define vector_macros

#define RESIZE_VECTOR resizeVectorInt(vector); vectorPointer = (VectorInt*)vector
#define CAST_VECTOR_INT VectorInt* vectorPointer = (VectorInt*)vector
#define negative_size_error_text_ "Vector not initialized, size must be greater of equal than 0!"
#define NEGATIVE_SIZE_ERROR_MESSAGE fprintf(stderr, "%s\n", negative_size_error_text_)
#define negative_index_error_text_ "Index cannot be negative!"
#define negative_index_error_message_ fprintf(stderr, "%s\n", negative_index_error_text_)
#define NEGATIVE_INDEX_SCENARIO(value) negative_index_error_message_; value = NULL
#define toobig_index_error_text_ "Index exeeds capacity of vector!"
#define toobig_index_error_message_ fprintf(stderr, "%s\n", toobig_index_error_text_)
#define TOOBIG_INDEX_SCENARIO(value) toobig_index_error_message_; value = NULL
#define empty_vector_warning_text_ "Vector is empty. NULL is returned!"
#define EMPTY_VECTOR_WARNING_MESSAGE fprintf(stderr, "%s\n", empty_vector_warning_text_)

#endif