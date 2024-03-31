#include "vector.h"
#include <malloc.h>
#include "stdio.h"

vector createVector(size_t n) {
    vector vector;
    vector.data = NULL;
    vector.size = n;
    vector.capacity = n;

    vector.data = (int*) malloc(n * sizeof(int));

    if (vector.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return vector;
}

void reserve(vector *v, size_t newCapacity) {
    if (!newCapacity) {
        free(v->data);
        v->data = NULL;
        v->size = 0;
        v->capacity = 0;
    }
    else if (newCapacity > v->capacity) {
        v->data = (int*) realloc(v, newCapacity * sizeof(int));
        v->capacity = newCapacity;

        if (v->data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    }
    else {
        v->size = newCapacity;
        v->capacity = newCapacity;
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->data = (int*) realloc(v, v->size * sizeof(int));
}

void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}