#include "voidVector.h"
#include <malloc.h>
#include <stdio.h>

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    vectorVoid vectorVoid;
    vectorVoid.data = NULL;
    vectorVoid.size = n;
    vectorVoid.capacity = n;
    vectorVoid.baseTypeSize = baseTypeSize;

    vectorVoid.data = (int*) malloc(n * baseTypeSize);

    if (vectorVoid.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return vectorVoid;
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (!newCapacity) {
        free(v->data);
        v->data = NULL;
        v->size = 0;
        v->capacity = 0;
        v->baseTypeSize = 0;
    }
    else if (newCapacity > v->capacity) {
        v->data = (int*) realloc(v, newCapacity * v->baseTypeSize);

        if (v->data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    }
    else {
        v->size = newCapacity;
    }

    v->capacity = newCapacity;
}

void shrinkToFitV(vectorVoid *v) {
    v->data = (int*) realloc(v, v->size * v->baseTypeSize);
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
    v->baseTypeSize = 0;
}