#ifndef vector_type
#define vector_type

struct VectorInt {
    int capacity;
    int count;
    int* buffer;
} typedef VectorInt;

struct Vector {
    int capacity;
    int count;
    void** buffer;

} typedef GrindelfVector;

#endif
