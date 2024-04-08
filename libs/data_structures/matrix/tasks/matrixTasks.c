#include <malloc.h>
#include <assert.h>
#include "matrixTasks.h"

void t1_swapRows(matrix m) {
    int max_i = getMaxValuePos(m).rowIndex;
    int min_i = getMinValuePos(m).rowIndex;
    swapRows(m, max_i, min_i);
}

int getMax(int *a, int n) {
    int max_elem = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max_elem)
            max_elem = a[i];

    return max_elem;
}

void t2_sortRowsNotDecreasingMaxElem(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, &getMax);
}

int getMin(int *a, int n) {
    int min_elem = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < min_elem)
            min_elem = a[i];

    return min_elem;
}

void t3_sortColsNotDecreasingMinElem(matrix m) {
    selectionSortColsMatrixByColCriteria(m, &getMin);
}

matrix mulMatrices(matrix m1, matrix m2) {
    assert(m1.nCols == m2.nRows);
    matrix b = getMemMatrix(m1.nRows, m2.nCols);
    for (int i = 0; i < m1.nRows; i++)
        for (int j = 0; j < m2.nCols; j++) {
            b.values[i][j] = 0;
            for (int k = 0; k < m1.nRows; k++)
                b.values[i][j] += m1.values[i][k] * m2.values[k][j];
        }

    return b;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(m) && isSquareMatrix(m))
        freeMemMatrix(m);
        *m = mulMatrices(*m,*m);
}

bool isUnique(long long *a, int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] == a[j])
                return 0;

    return 1;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long ms[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        ms[i] = getSum(m.values[i], m.nCols);

    if (isUnique(ms, m.nRows))
        transposeMatrix(&m);
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    if (!isSquareMatrix(&m1) || !isSquareMatrix(&m2))
        return 0;

    matrix m = mulMatrices(m1, m2);
    int result = 1;
    if (!isEMatrix(&m))
        result = 0;

    freeMemMatrix(&m);

    return result;
}

int max(int a, int b) {
    return a > b ? a : b;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    long long *ms = (long long*) calloc(m.nRows + m.nCols - 1, sizeof(long long));

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            ms[m.nCols - 1 + i - j] = max(ms[m.nCols - 1 + i - j], m.values[i][j]);

    long long sum = 0;
    for (int i = 0; i < m.nRows + m.nCols - 1; i++)
        sum += ms[i];

    return sum;
}