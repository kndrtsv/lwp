#ifndef LWBOP_FILE_PROCESSING_H
#define LWBOP_FILE_PROCESSING_H

#include <stdio.h>
#include "../data_structures/matrix/matrix.h"

void transposeMatrices(char *readFile, char *writeFile);

void fixedPointNumberToFloating(char *readFile, char *writeFile);

#endif //LWBOP_FILE_PROCESSING_H
