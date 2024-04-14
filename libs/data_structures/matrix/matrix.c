#include <malloc.h>
#include <stdio.h>
#include <assert.h>
#include <memory.h>
#include "matrix.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int*) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix){values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices,
                              int nRows, int nCols) {
    matrix *ms = (matrix*) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++)
        free(m->values[i]);
    free(m->values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(&ms[i]);
    free(ms);
}

void inputMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++)
        for (int j = 0; j < m->nCols; j++)
            scanf("%d", &m->values[i][j]);
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrix(&ms[i]);
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++)
            printf("%d ", m.values[i][j]);
        printf("\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        outputMatrix(ms[i]);
}

void swapRows(matrix m, int i1, int i2) {
    assert(i1 < m.nRows && i2 < m.nRows);
    int *temp = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = temp;
}

void swapColumns(matrix m, int j1, int j2) {
    assert(j1 < m.nCols && j2 < m.nCols);
    for (int i = 0; i < m.nRows; i++) {
        int temp = m.values[i][j1];
        m.values[i][j1] = m.values[i][j2];
        m.values[i][j2] = temp;
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

long long getSum(int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int*, int)) {
    int *mc = (int*) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nRows; i++)
        mc[i] = criteria(m.values[i], m.nCols);

    for (int i = 1; i < m.nRows; i++) {
        int temp = mc[i];
        int j = i;
        while (j > 0 && mc[j - 1] > temp) {
            mc[j] = mc[j - 1];
            swapRows(m, j, j - 1);
            j--;
        }
        mc[j] = temp;
    }
}

void selectionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int*, int)) {
    int *mc = (int *) malloc(sizeof(int) * m.nCols);
    int *column = (int *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nCols; i++) {
        for (int j = 0; j < m.nRows; j++)
            column[j] = m.values[j][i];
        mc[i] = criteria(column, m.nRows);
    }

    for (int i = 0; i < m.nCols - 1; i++) {
        int min_pos = i;
        for (int j = i + 1; j < m.nCols; j++)
            if (mc[j] < mc[min_pos])
                min_pos = j;
        swap(&mc[i], &mc[min_pos]);
        swapColumns(m, i, min_pos);
    }
}

bool isSquareMatrix(matrix *m) {
    return m->nRows == m->nCols;
}

bool areTwoMatricesEqual(matrix *m1, matrix *m2) {
    if (m1->nRows != m2->nRows || m1->nCols != m2->nCols)
        return 0;

    for (int i = 0; i < m1->nRows; i++)
        if (memcmp(m1->values[i], m2->values[i], sizeof(int) * m1->nCols) != 0)
            return 0;

    return 1;
}

bool isEMatrix(matrix *m) {
    if (!isSquareMatrix(m))
        return 0;

    for (int i = 0; i < m->nRows; i++)
        if (m->values[i][i] != 1 || getSum(m->values[i], m->nCols) > 1)
            return 0;

    return 1;
}

bool isSymmetricMatrix(matrix *m) {
    if (!isSquareMatrix(m))
        return 0;

    for (int i = 1; i < m->nRows; i++)
        for (int j = 0; j < i; j++)
            if (m->values[i][j] != m->values[j][i])
                return 0;

    return 1;
}

void transposeSquareMatrix(matrix *m) {
    for (int i = 1; i < m->nRows; i++)
        for (int j = 0; j < i; j++)
            swap(&m->values[i][j], &m->values[j][i]);
}

void transposeMatrix(matrix *m) {
    swap(&m->nRows, &m->nCols);
    for (int i = 0; i < m->nRows; i++)
        for (int j = 1; j < m->nCols; j++)
            swap(&m->values[i][j], &m->values[j][i]);
}

position getMinValuePos(matrix m) {
    int row_i = 0;
    int col_i = 0;
    int min_elem = m.values[0][0];

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] < min_elem) {
                min_elem = m.values[i][j];
                row_i = i;
                col_i = j;
            }

    return (position) {row_i, col_i};
}

position getMaxValuePos(matrix m) {
    int row_i = 0;
    int col_i = 0;
    int max_elem = m.values[0][0];

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] > max_elem) {
                max_elem = m.values[i][j];
                row_i = i;
                col_i = j;
            }

    return (position) {row_i, col_i};
}

matrix createMatrixFromArray(const int *a, size_t nRows, size_t nCols) {
    matrix m = getMemMatrix(nRows, nCols);
    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}