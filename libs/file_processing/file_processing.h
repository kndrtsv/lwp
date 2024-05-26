#ifndef LWBOP_FILE_PROCESSING_H
#define LWBOP_FILE_PROCESSING_H

#include <stdio.h>
#include <string.h>
#include "../data_structures/matrix/matrix.h"

void transposeMatrices(char *readFile, char *writeFile);

void fixedPointNumberToFloating(char *readFile, char *writeFile);

void writeCalculatedExpression(char *file);

void saveRightWords(char *readFile, char *writeFile, char *sequence);

void convertStringWithBiggestWord(char *readFile, char *writeFile);

void transposeMatrixIfNotSym(char *readFile, char *writeFile);

void formBestTeam(char *file, int athletes_n);

#endif //LWBOP_FILE_PROCESSING_H
