#include "matrixTasks.h"

void t1_swapRows(matrix a) {
    int max_i = getMaxValuePos(a).rowIndex;
    int min_i = getMinValuePos(a).rowIndex;
    swapRows(a, max_i, min_i);
}