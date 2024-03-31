#include "voidVector.h"
#include <memory.h>
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

bool isEmptyV(vectorVoid *v) {
    return !(v->size);
}

bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    if (v->size <= index) {
        fprintf(stderr, "IndexError: element is not exists");
        exit(1);
    }

    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    if (v->size <= index) {
        fprintf(stderr, "IndexError: element is not exists");
        exit(1);
    }

    char *destination = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void popBackV(vectorVoid *v) {
    if (isEmptyV(v)) {
        fprintf(stderr, "vector is empty");
        exit(1);
    }

    v->size--;
}

void pushBackV(vectorVoid *v, void *source) {
    if (isFullV(v)) {
        reserveV(v, v->capacity * 2);
    }
    else if (isEmptyV(v)) {
        reserveV(v, 1);
    }

    char *destination = (char *) v->data + v->size * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);

    v->size++;
}