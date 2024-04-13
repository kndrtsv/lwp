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

int countValues(const int *a, int n, int value) {
    int count = 0;

    for (int i = 0; i < n; i++)
        if (a[i] == count)
            count++;

    return count;
}

int countZeroRows(matrix m) {
    int count = 0;

    for (int i = 0; i < m.nRows; i++)
        if (countValues(m.values[i], m.nCols, 0) == m.nCols)
            count++;

    return count;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int max_zero_rows = 0;

    for (int i = 0; i < nMatrix; i++)
        if (countZeroRows(ms[i]) > max_zero_rows)
            max_zero_rows = countZeroRows(ms[i]);

    for (int i = 0; i < nMatrix; i++)
        if (countZeroRows(ms[i]) == max_zero_rows)
            outputMatrix(ms[i]);
}

int getAbsMax(matrix m) {
    int abs_max_elem = m.values[0][0];

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (abs(m.values[i][j]) > abs_max_elem)
                abs_max_elem = m.values[i][j];

    return abs_max_elem;
}

void outputMatrixWithMinNorma(matrix *ms, int nMatrix) {
    int min_norma = getAbsMax(ms[0]);

    for (int i = 0; i < nMatrix; i++)
        if (getAbsMax(ms[i]) < min_norma)
            min_norma = getAbsMax(ms[i]);

    for (int i = 0; i < nMatrix; i++)
        if (getAbsMax(ms[i]) == min_norma)
            outputMatrix(ms[i]);
}

int min2(int a, int b) {
    return a > b ? b : a;
}

int getNSpecialElement2(matrix m) {
    int count = 0;

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++) {
            int is_spec = 1;

            for (int k = j - 1; k >= 0; k--)
                if (min2(m.values[i][k], m.values[i][j]) == m.values[i][j])
                    is_spec = 0;

            for (int l = j + 1; l < m.nCols; l++)
                if (min2(m.values[i][l], m.values[i][j]) == m.values[i][l])
                    is_spec = 0;

            if (is_spec)
                count++;
        }

    return count;
}

double getScalarProduct(int *a, int *b, int n) {
    double scalar_product = 0;
    for (int i = 0; i < n; i++)
        scalar_product += a[i] * b[i];

    return scalar_product;
}

double getVectorLength(int *a, int n) {
    double sum_of_squares = 0;
    for (int i = 0; i < n; i++)
        sum_of_squares += a[i] * a[i];

    return sqrt(sum_of_squares);
}

double getCosine(int *a, int *b, int n) {
    return getScalarProduct(a,b,n) / (getVectorLength(a, n) + getVectorLength(b, n));
}

int getVectorIndexWithMaxAngle(matrix m, int *b) {
    int max_angle_i = 0;
    int max_angle = 0;

    for (int i = 0; i < m.nRows; i++)
        if (getCosine(m.values[i], b, m.nCols) > max_angle) {
            max_angle = getCosine(m.values[i], b, m.nCols);
            max_angle_i = i;
        }

    return max_angle_i;
}

long long getScalarProductRowAndCol(matrix m, int i, int j) {
    long long scalar_product = 0;

    for (int k = 0; k < m.nRows; k++)
        scalar_product += m.values[i][k] * m.values[k][j];

    return scalar_product;
}

long long getSpecialScalarProduct(matrix m, int n) {
    position max_elem = getMaxValuePos(m);
    position min_elem = getMinValuePos(m);

    return getScalarProductRowAndCol(m, max_elem.rowIndex, min_elem.colIndex);
}