#include <assert.h>
#include <stdio.h>
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/voidVector.h"

void test_createVector_emptyVector() {
    vector v = createVector(0);
}

void test_isEmpty_emptyVector() {
    vector v = createVector(0);
    int expected_result = 1;
    assert(isEmpty(&v) == expected_result);
}

void test_isEmpty_notEmptyVector() {
    vector v = createVector(1);
    v.data[0] = 1;
    v.size++;
    int expected_result = 0;
    assert(isEmpty(&v) == expected_result);
}

void test_isEmpty() {
    test_isEmpty_emptyVector();
    test_isEmpty_notEmptyVector();
}

void test_isFull_fullVector() {
    vector v = createVector(1);
    v.data[0] = 1;
    v.size++;
    int expected_result = 1;
    assert(isFull(&v) == expected_result);
}

void test_isFull_notFullVector() {
    vector v = createVector(1);
    int expected_result = 0;
    assert(isFull(&v) == expected_result);
}

void test_isFull() {
    test_isFull_fullVector();
    test_isFull_notFullVector();
}

void test_getVectorValue_getValue() {
    vector v = createVector(1);
    v.data[0] = 2;
    v.size++;
    int expected_result = 2;
    assert(getVectorValue(&v, 0) == expected_result);
}

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 2);
    int result = v.data[v.size - 1];
    int expected_result = 2;
    assert(result == expected_result);
}

void test_pushBack_fullVector() {
    vector v = createVector(1);
    v.data[0] = 4;
    v.size++;
    pushBack(&v, 6);
    int result = v.data[v.size - 1];
    int expected_result = 6;
    assert(result == expected_result);
}

void test_pushBack() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 7);

    int *result = atVector(&v, 0);
    int expected_result = 7;
    assert(*result == expected_result);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(0);
    pushBack(&v, 8);
    pushBack(&v, 9);
    int *result = atVector(&v, 1);
    int expected_result = 9;
    assert(*result == expected_result);
}

void test_atVector() {
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
}

void test_back_oneElementInVector() {
    vector v = createVector(0);
    pushBack(&v, 11);
    int *result = back(&v);
    int expected_result = 11;
    assert(*result == expected_result);
}

void test_back_fewElementInVector() {
    vector v = createVector(0);
    pushBack(&v, 11);
    pushBack(&v, 12);
    int *result = back(&v);
    int expected_result = 12;
    assert(*result == expected_result);
}

void test_back() {
    test_back_oneElementInVector();
    test_back_fewElementInVector();
}

void test_front_oneElementInVector() {
    vector v = createVector(0);
    pushBack(&v, 14);
    int *result = front(&v);
    int expected_result = 14;
    assert(*result = expected_result);
}

void test_front_fewElementInVector() {
    vector v = createVector(0);
    pushBack(&v, 14);
    pushBack(&v, 15);
    int *result = front(&v);
    int expected_result = 14;
    assert(*result = expected_result);
}

void test_front() {
    test_front_oneElementInVector();
    test_front_fewElementInVector();
}

void test() {
    test_createVector_emptyVector();
    test_isEmpty();
    test_isFull();
    test_getVectorValue_getValue();
    test_pushBack();
    test_popBack_notEmptyVector();
    test_atVector();
    test_back();
    test_front();
    printf("all tests ok");
}

int main() {
    test();
    return 0;
}