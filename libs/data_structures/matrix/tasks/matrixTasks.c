#include <malloc.h>
#include <assert.h>
#include "matrixTasks.h"

void t1_swapRows(matrix a) {
    int max_i = getMaxValuePos(a).rowIndex;
    int min_i = getMinValuePos(a).rowIndex;
    swapRows(a, max_i, min_i);
}

int getMax(int *a, int n) {
    int max_elem = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max_elem)
            max_elem = a[i];

    return max_elem;
}

void t2_sortRowsNotDecreasingMaxElem(matrix a) {
    insertionSortRowsMatrixByRowCriteria(a, &getMax);
}

int getMin(int *a, int n) {
    int min_elem = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < min_elem)
            min_elem = a[i];

    return min_elem;
}

void t3_sortColsNotDecreasingMinElem(matrix a) {
    selectionSortColsMatrixByColCriteria(a, &getMin);
}

matrix mulMatrices(matrix a1, matrix a2) {
    assert(a1.nCols == a2.nRows);
    matrix b = getMemMatrix(a1.nRows, a2.nCols);
    for (int i = 0; i < a1.nRows; i++)
        for (int j = 0; j < a2.nCols; j++) {
            b.values[i][j] = 0;
            for (int k = 0; k < a1.nRows; k++)
                b.values[i][j] += a1.values[i][k] * a2.values[k][j];
        }

    return b;
}

void getSquareOfMatrixIfSymmetric(matrix *a) {
    if (isSymmetricMatrix(a) && isSquareMatrix(a))
        freeMemMatrix(a);
        *a = mulMatrices(*a,*a);
}