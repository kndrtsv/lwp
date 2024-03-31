#include "vector.h"
#include <malloc.h>
#include "stdio.h"

vector createVector(size_t n) {
    vector vector;
    vector.data = NULL;
    vector.size = 0;
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
        v->data = (int*) realloc(v->data, newCapacity * sizeof(int));

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

bool isEmpty(vector *v) {
    return !(v->size);
}

bool isFull(vector *v) {
    return v->size == v->capacity && v->size != 0;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (isFull(v)) {
        reserve(v, v->capacity * 2);
    }
    else if (isEmpty(v)) {
        reserve(v, 1);
    }

    v->data[v->size] = x;
    v->size++;
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "vector is empty");
        exit(1);
    }

    v->size--;
}

int* atVector(vector *v, size_t index) {
    if (v->size <= index) {
        fprintf(stderr, "IndexError: a[%u] is not exists", index);
        exit(1);
    }

    return &(v->data[index]);
}

int* back(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "vector is empty");
        exit(1);
    }

    return &(v->data[v->size - 1]);
}

int* front(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "vector is empty");
        exit(1);
    }

    return &(v->data[0]);
}