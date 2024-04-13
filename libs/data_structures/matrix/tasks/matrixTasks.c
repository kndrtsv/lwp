#include <malloc.h>
#include <assert.h>
#include <math.h>
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

int getMinInArea(matrix m) {
    position max_pos = getMaxValuePos(m);
    int min_elem = m.values[0][0];

    for (int i = 0; i < m.nCols; i++)
        for (int j = 0; j < max_pos.rowIndex - abs(max_pos.colIndex - i); j++)
            if (min_elem > m.values[j][i])
                min_elem = m.values[j][i];

    return min_elem;
}

float getDistance(int *a, int n) {
    float sum_of_squares = 0;
    for (int i = 0; i < n; i++)
        sum_of_squares += a[i] * a[i];

    return sqrt(sum_of_squares);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    float *mc = (float*) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nRows; i++)
        mc[i] = criteria(m.values[i], m.nCols);

    for (int i = 1; i < m.nRows; i++) {
        float temp = mc[i];
        int j = i;
        while (j > 0 && mc[j - 1] > temp) {
            mc[j] = mc[j - 1];
            swapRows(m, j, j - 1);
            j--;
        }
        mc[j] = temp;
    }
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, &getDistance);
}

int cmp_long_long(const void *pa, const void *pb) {
    return (*(long long*)pa - *(long long*)pb);
}

int countNUnique(long long *a, int n) {
    if (!n)
        return 0;

    qsort(a,n, sizeof(long long),cmp_long_long);

    int unique_num = 1;
    for (int i = 0; i < n - 1; i++)
        if (a[i] != a[i + 1])
            unique_num++;

    return unique_num;
}

int countEqClassesByRowsSum(matrix m) {
    long long ms[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        ms[i] = getSum(m.values[i], m.nCols);

    return countNUnique(ms, m.nRows);
}

int getNSpecialElement(matrix m) {
    int unique_elems = 0;

    int *column = (int *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nCols; i++) {
        for (int j = 0; j < m.nRows; j++)
            column[j] = m.values[j][i];

        int max_elem = getMax(column, m.nRows);
        if (getSum(column, m.nRows) - max_elem < max_elem)
            unique_elems++;
    }

    return unique_elems;
}

position getLeftMin(matrix m) {
    position min_left_elem = {0, 0};

    int min_elem = m.values[0][0];
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] < min_elem) {
                min_elem = m.values[i][j];
                min_left_elem.rowIndex = i;
                min_left_elem.colIndex = j;
            }

    return min_left_elem;
}

void swapPenultimateRow(matrix m, int n) {
    int left_min_col_i = getLeftMin(m).colIndex;

    int *column = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        column[i] = m.values[i][left_min_col_i];

    for (int i = 0; i < n; i++)
        m.values[n - 2][i] = column[i];
}

bool isNonDescendingSorted(int *a, int n) {
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1])
            return 0;

    return 1;
}

bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        if (!isNonDescendingSorted(m.values[i], m.nCols))
            return 0;

    return 1;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int count = 0;

    for (int i = 0; i < nMatrix; i++)
        if (hasAllNonDescendingRows(ms[i]))
            count++;

    return count;
}