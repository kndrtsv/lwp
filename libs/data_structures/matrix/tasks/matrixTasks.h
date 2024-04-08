#ifndef LWBOP_MATRIXTASKS_H
#define LWBOP_MATRIXTASKS_H

#include "C:\Users\user\CLionProjects\lwbop\libs\data_structures\matrix\matrix.h"

void t1_swapRows(matrix a);

void t2_sortRowsNotDecreasingMaxElem(matrix a);

void t3_sortColsNotDecreasingMinElem(matrix a);

void getSquareOfMatrixIfSymmetric(matrix *a);

matrix mulMatrices(matrix a1, matrix a2);

bool isUnique(long long *a, int n);

void transposeIfMatrixHasNotEqualSumOfRows(matrix a);

#endif //LWBOP_MATRIXTASKS_H
