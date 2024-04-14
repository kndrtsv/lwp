#include <assert.h>
#include <stdio.h>
#include "matrixTasks.h"

void test_t1_swapRows() {
    matrix matrix1 = createMatrixFromArray((int []) {1,2,3,4,5,6}, 3, 2);
    t1_swapRows(matrix1);
    matrix expected_matrix = createMatrixFromArray((int []) {5,6,3,4,1,2}, 3, 2);
    assert(areTwoMatricesEqual(&matrix1, &expected_matrix));
}

void test_t2_sortRowsNotDecreasingMaxElem() {
    matrix matrix1 = createMatrixFromArray((int []) {7,1,2,1,8,1,3,2,3}, 3, 3);
    t2_sortRowsNotDecreasingMaxElem(matrix1);
    matrix expected_matrix = createMatrixFromArray((int []) {3,2,3,7,1,2,1,8,1}, 3, 3);
    assert(areTwoMatricesEqual(&matrix1, &expected_matrix));
}

void test_t3_sortColsNotDecreasingMinElem() {
    matrix matrix1 = createMatrixFromArray((int []) {3,5,2,2,5,1,6,1,4}, 3, 3);
    t3_sortColsNotDecreasingMinElem(matrix1);
    matrix expected_matrix = createMatrixFromArray((int []) {5,2,3,5,1,2,1,4,6}, 3, 3);
    assert(areTwoMatricesEqual(&matrix1, &expected_matrix));
}

void test_getSquareOfMatrixIfSymmetric_sym() {
    matrix matrix1 = createMatrixFromArray((int []) {2,3,3,2}, 2, 2);
    getSquareOfMatrixIfSymmetric(&matrix1);
    matrix expected_matrix = createMatrixFromArray((int []) {13,12,12,13}, 2, 2);
    assert(areTwoMatricesEqual(&matrix1, &expected_matrix));
}

void test_getSquareOfMatrixIfSymmetric_notSym() {
    matrix matrix1 = createMatrixFromArray((int []) {2,3,4,5}, 2, 2);
    getSquareOfMatrixIfSymmetric(&matrix1);
    matrix expected_matrix = createMatrixFromArray((int []) {16,21,28,37}, 2, 2);
    assert(!areTwoMatricesEqual(&matrix1, &expected_matrix));
}

void test_getSquareOfMatrixIfSymmetric() {
    test_getSquareOfMatrixIfSymmetric_sym();
    test_getSquareOfMatrixIfSymmetric_notSym();
}

void test_transposeIfMatrixHasNotEqualSumOfRows_notEqualSum() {
    matrix matrix1 = createMatrixFromArray((int []) {2,3,4,5}, 2, 2);
    transposeIfMatrixHasNotEqualSumOfRows(matrix1);
    matrix expected_matrix = createMatrixFromArray((int []) {2,4,3,5}, 2, 2);
    assert(areTwoMatricesEqual(&matrix1, &expected_matrix));
}

void test_transposeIfMatrixHasNotEqualSumOfRows_equalSum() {
    matrix matrix1 = createMatrixFromArray((int []) {2,3,1,4}, 2, 2);
    transposeIfMatrixHasNotEqualSumOfRows(matrix1);
    matrix expected_matrix = createMatrixFromArray((int []) {2,3,1,4}, 2, 2);
    assert(areTwoMatricesEqual(&matrix1, &expected_matrix));
}

void test_transposeIfMatrixHasNotEqualSumOfRows() {
    test_transposeIfMatrixHasNotEqualSumOfRows_notEqualSum();
    test_transposeIfMatrixHasNotEqualSumOfRows_equalSum();
}

void test_isMutuallyInverseMatrices_true() {
    matrix matrix1 = createMatrixFromArray((int []) {2,3,1,1}, 2, 2);
    matrix matrix2 = createMatrixFromArray((int []) {-1,3,1,-2}, 2, 2);
    int result = isMutuallyInverseMatrices(matrix1,matrix2);
    int expected_result = 1;
    assert(result == expected_result);
}

void test_isMutuallyInverseMatrices_false() {
    matrix matrix1 = createMatrixFromArray((int []) {2,3,1,1}, 2, 2);
    matrix matrix2 = createMatrixFromArray((int []) {2,2,2,2}, 2, 2);
    int result = isMutuallyInverseMatrices(matrix1,matrix2);
    int expected_result = 0;
    assert(result == expected_result);
}

void test_isMutuallyInverseMatrices() {
    test_isMutuallyInverseMatrices_true();
    test_isMutuallyInverseMatrices_false();
}

void test_findSumOfMaxesOfPseudoDiagonal() {
    matrix matrix1 = createMatrixFromArray((int []) {1,2,3,4,5,6,7,8,9}, 3, 3);
    long long result = findSumOfMaxesOfPseudoDiagonal(matrix1);
    int expected_result = 33;
    assert(result == expected_result);
}

void test_getMinInArea() {
    matrix matrix1 = createMatrixFromArray((int []) {1,2,3,4,5,6,7,8,9}, 3, 3);
    int result = getMinInArea(matrix1);
    int expected_result = 1;
    assert(result == expected_result);
}

void test_sortByDistances() {
    matrix matrix1 = createMatrixFromArray((int []) {3,3,3,2,2,2,1,1,1}, 3, 3);
    sortByDistances(matrix1);
    matrix expected_matrix = createMatrixFromArray((int []) {1,1,1,2,2,2,3,3,3}, 3, 3);
    assert(areTwoMatricesEqual(&matrix1, &expected_matrix));
}

void test_countEqClassesByRowsSum() {
    matrix matrix1 = createMatrixFromArray((int []) {1,2,3,4,5,6}, 3, 2);
    int result = countEqClassesByRowsSum(matrix1);
    int expected_result = 3;
    assert(result == expected_result);
}

void test_getNSpecialElement() {
    matrix matrix1 = createMatrixFromArray((int []) {1,2,3,1,5,4}, 3, 2);
    int result = getNSpecialElement(matrix1);
    int expected_result = 2;
    assert(result == expected_result);
}

void test_swapPenultimateRow() {
    matrix matrix1 = createMatrixFromArray((int []) {1,2,3,4,5,6,7,8,9}, 3, 3);
    swapPenultimateRow(matrix1, matrix1.nRows);
    matrix expected_matrix = createMatrixFromArray((int []) {1,2,3,1,4,7,7,8,9}, 3, 3);
    assert(areTwoMatricesEqual(&matrix1, &expected_matrix));
}

void test_countNonDescendingRowsMatrices() {
    int elems[] = {1,2,3,4,2,1,4,3,4,5,7,6};
    matrix *matrices = createArrayOfMatrixFromArray(elems, 3, 2,2);
    int result = countNonDescendingRowsMatrices(matrices, 3);
    int expected_result = 1;
    assert(result == expected_result);
}

void test_countZeroRows() {
    matrix matrix1 = createMatrixFromArray((int []) {0,0,0,1,1,1,0,0,0}, 3, 3);
    int result = countZeroRows(matrix1);
    int expected_result = 2;
    assert(result == expected_result);
}

void test_getAbsMax() {
    matrix matrix1 = createMatrixFromArray((int []) {-1,2,-3,4,-5,6,-7,0,0}, 3, 3);
    int result = getAbsMax(matrix1);
    int expected_result = 7;
    assert(result == expected_result);
}

void test_getNSpecialElement2() {
    matrix matrix1 = createMatrixFromArray((int []) {1,2,3,6,5,4,9,8,7}, 3, 3);
    int result = getNSpecialElement2(matrix1);
    int expected_result = 3;
    assert(result == expected_result);
}

void test_getVectorIndexWithMaxAngle() {
    matrix matrix1 = createMatrixFromArray((int []) {1,1,1,2,2,2,3,3,3}, 3, 3);
    int b[] = {1,1,1};
    int result = getVectorIndexWithMaxAngle(matrix1, b);
    int expected_result = 2;
    assert(result == expected_result);
}

void test_getSpecialScalarProduct() {
    matrix matrix1 = createMatrixFromArray((int []) {9,2,3,4,5,6,7,8,1}, 3, 3);
    long long result = getSpecialScalarProduct(matrix1, matrix1.nRows);
    long long expected_result = 42;
    assert(result == expected_result);
}

void testMatrixTasks() {
    test_t1_swapRows();
    test_t2_sortRowsNotDecreasingMaxElem();
    test_t3_sortColsNotDecreasingMinElem();
    test_getSquareOfMatrixIfSymmetric();
    test_transposeIfMatrixHasNotEqualSumOfRows();
    test_isMutuallyInverseMatrices();
    test_findSumOfMaxesOfPseudoDiagonal();
    test_getMinInArea();
    test_sortByDistances();
    test_countEqClassesByRowsSum();
    test_getNSpecialElement();
    test_swapPenultimateRow();
    test_countNonDescendingRowsMatrices();
    test_countZeroRows();
    test_getAbsMax();
    test_getNSpecialElement2();
    test_getVectorIndexWithMaxAngle();
    test_getSpecialScalarProduct();
    printf("all tests ok");
}