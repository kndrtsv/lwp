#ifndef LWBOP_VOIDVECTOR_H
#define LWBOP_VOIDVECTOR_H

#include <stdint.h>

typedef struct vectorVoid {
    void *data;             // указатель на нулевой элемент вектора
    size_t size;            // размер вектора
    size_t capacity;        // вместимость вектора
    size_t baseTypeSize;    // размер базового типа:
} vectorVoid;


#endif //LWBOP_VOIDVECTOR_H
