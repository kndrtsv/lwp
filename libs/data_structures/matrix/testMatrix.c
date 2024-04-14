#include <assert.h>
#include <stdio.h>
#include "matrix.h"

void test_getMemMatrix() {
    int rows = 2;
    int cols = 2;

    matrix matrix1 = getMemMatrix(rows, cols);

    assert(matrix1.nRows == rows);
    assert(matrix1.nCols == cols);
}

void test_getMemArrayOfMatrices() {
    int rows = 2;
    int cols = 2;
    int nMatrices = 2;

    matrix *ms = getMemArrayOfMatrices(nMatrices, rows, cols);

    for (int i = 0; i < nMatrices; i++) {
        assert(ms[i].nRows == rows);
        assert(ms[i].nCols == cols);
    }
}

void test_swapRows() {
    matrix matrix1 = createMatrixFromArray((int []) {1,2,3,4}, 2, 2);
    swapRows(matrix1, 0, 1);
    assert(matrix1.values[0][0] == 3 && matrix1.values[0][1] == 4 && matrix1.values[1][0] == 1 && matrix1.values[1][1] == 2);
}

void test_swapColumns() {
    matrix matrix1 = createMatrixFromArray((int []) {1,2,3,4}, 2, 2);
    swapColumns(matrix1, 0, 1);
    assert(matrix1.values[0][0] == 2 && matrix1.values[0][1] == 1 && matrix1.values[1][0] == 4 && matrix1.values[1][1] == 3);
}

void test_areTwoMatricesEqual_equal() {
    matrix matrix1 = createMatrixFromArray((int []) {1,2,3,4}, 2, 2);
    matrix matrix2 = createMatrixFromArray((int []) {1,2,3,4}, 2, 2);

    int result = areTwoMatricesEqual(&matrix1, &matrix2);
    int expected_result = 1;
    assert(result == expected_result);
}

void test_areTwoMatricesEqual_notEqual() {
    matrix matrix1 = createMatrixFromArray((int []) {1,2,3,4}, 2, 2);
    matrix matrix2 = createMatrixFromArray((int []) {1,2,3,5}, 2, 2);

    int result = areTwoMatricesEqual(&matrix1, &matrix2);
    int expected_result = 0;
    assert(result == expected_result);
}

void test_areTwoMatricesEqual() {
    test_areTwoMatricesEqual_equal();
    test_areTwoMatricesEqual_notEqual();
}

void test_insertionSortRowsMatrixByRowCriteria() {
    matrix matrix1 = createMatrixFromArray((int []) {3,4,1,2}, 2, 2);
    insertionSortRowsMatrixByRowCriteria(matrix1, &getSum);
    matrix expected_matrix = createMatrixFromArray((int []) {1,2,3,4}, 2, 2);
    assert(areTwoMatricesEqual(&matrix1, &expected_matrix));
}

void test_selectionSortColsMatrixByColCriteria() {
    matrix matrix1 = createMatrixFromArray((int []) {1,2,6,3}, 2, 2);
    selectionSortColsMatrixByColCriteria(matrix1, &getSum);
    matrix expected_matrix = createMatrixFromArray((int []) {2,1,3,6}, 2, 2);
    assert(areTwoMatricesEqual(&matrix1, &expected_matrix));
}

void test_isSquareMatrix_square() {
    matrix matrix1 = createMatrixFromArray((int []) {1,2,3,4}, 2, 2);
    int result = isSquareMatrix(&matrix1);
    int expected_result = 1;
    assert(result == expected_result);

}

void test_isSquareMatrix_notSquare() {
    matrix matrix1 = createMatrixFromArray((int []) {1,2,3,4, 5, 6}, 2, 3);
    int result = isSquareMatrix(&matrix1);
    int expected_result = 0;
    assert(result == expected_result);

}

void test_isSquareMatrix() {
    test_isSquareMatrix_square();
    test_isSquareMatrix_notSquare();
}

void test_isEMatrix_EMatrix() {
    matrix matrix1 = createMatrixFromArray((int []) {1,0,0,1}, 2, 2);
    int result = isEMatrix(&matrix1);
    int expected_result = 1;
    assert(result == expected_result);
}

void test_isEMatrix_notEMatrix() {
    matrix matrix1 = createMatrixFromArray((int []) {1,0,1,0}, 2, 2);
    int result = isEMatrix(&matrix1);
    int expected_result = 0;
    assert(result == expected_result);
}

void test_isEMatrix() {
    test_isEMatrix_EMatrix();
    test_isEMatrix_notEMatrix();
}

void test_isSymmetricMatrix_symMatrix() {
    matrix matrix1 = createMatrixFromArray((int []) {1,2,2,1}, 2, 2);
    int result = isSymmetricMatrix(&matrix1);
    int expected_result = 1;
    assert(result == expected_result);
}

void test_isSymmetricMatrix_notSymMatrix() {
    matrix matrix1 = createMatrixFromArray((int []) {1,2,1,1}, 2, 2);
    int result = isSymmetricMatrix(&matrix1);
    int expected_result = 0;
    assert(result == expected_result);
}

void test_isSymmetricMatrix() {
    test_isSymmetricMatrix_symMatrix();
    test_isSymmetricMatrix_notSymMatrix();
}

void test_transposeSquareMatrix() {
    matrix matrix1 = createMatrixFromArray((int []) {1,2,3,4}, 2, 2);
    transposeSquareMatrix(&matrix1);
    matrix expected_matrix = createMatrixFromArray((int []) {1,3,2,4}, 2, 2);
    assert(areTwoMatricesEqual(&matrix1, &expected_matrix));
}

void test_transposeMatrix() {
    matrix matrix1 = createMatrixFromArray((int []) {1,2,3,4, 5, 6}, 3, 2);
    transposeMatrix(&matrix1);
    matrix expected_matrix = createMatrixFromArray((int []) {1,3,5,2, 4, 6}, 2, 3);
    assert(areTwoMatricesEqual(&matrix1, &expected_matrix));
}

void test_getMinValuePos() {
    matrix matrix1 = createMatrixFromArray((int []) {1,2,3,4}, 2, 2);
    position result = getMinValuePos(matrix1);
    position expected_result = {0, 0};
    assert(result.rowIndex == expected_result.rowIndex && result.colIndex == expected_result.colIndex);
}

void test_getMaxValuePos() {
    matrix matrix1 = createMatrixFromArray((int []) {1,2,3,4}, 2, 2);
    position result = getMaxValuePos(matrix1);
    position expected_result = {1, 1};
    assert(result.rowIndex == expected_result.rowIndex && result.colIndex == expected_result.colIndex);
}

void testMatrix() {
    test_getMemMatrix();
    test_getMemArrayOfMatrices();
    test_swapRows();
    test_swapColumns();
    test_areTwoMatricesEqual();
    test_insertionSortRowsMatrixByRowCriteria();
    test_selectionSortColsMatrixByColCriteria();
    test_isSquareMatrix();
    test_isEMatrix();
    test_isSymmetricMatrix();
    test_transposeSquareMatrix();
    test_transposeMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
    printf("all tests ok");
}