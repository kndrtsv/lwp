#include <malloc.h>
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