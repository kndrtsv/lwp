#ifndef LWBOP_MATRIXTASKS_H
#define LWBOP_MATRIXTASKS_H

#include "C:\Users\user\CLionProjects\lwbop\libs\data_structures\matrix\matrix.h"

void t1_swapRows(matrix m);

void t2_sortRowsNotDecreasingMaxElem(matrix m);

void t3_sortColsNotDecreasingMinElem(matrix m);

void getSquareOfMatrixIfSymmetric(matrix *m);

matrix mulMatrices(matrix m1, matrix m2);

bool isUnique(long long *a, int n);

void transposeIfMatrixHasNotEqualSumOfRows(matrix m);

bool isMutuallyInverseMatrices(matrix m1, matrix m2);

int max(int a, int b);

long long findSumOfMaxesOfPseudoDiagonal(matrix m);

int getMinInArea(matrix m);

float getDistance(int *a, int n);

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int));

void sortByDistances(matrix m);

#endif //LWBOP_MATRIXTASKS_H
