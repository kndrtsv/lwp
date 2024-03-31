#ifndef LWBOP_VECTOR_H
#define LWBOP_VECTOR_H
#include <stdint.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

vector createVector(size_t n);

#endif //LWBOP_VECTOR_H
