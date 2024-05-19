#include <stdio.h>
#include "../data_structures/matrix/matrix.h"

//task 1

matrix readSquareMatrixFromFile(FILE *file, int n) {
    matrix m = getMemMatrix(n, n);

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++) {
            fscanf(file, "%d", &m.values[i][j]);
        }

    return m;
}

void writeSquareMatrixToFile(FILE *f, matrix m) {
    fprintf(f, "%d\n", m.nRows);
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++)
            fprintf(f, "%d ", m.values[i][j]);
        fprintf(f, "\n");
    }
}

void transposeMatrices(char *readFile, char *writeFile) {
    FILE *read = fopen(readFile, "r");
    FILE *write = fopen(writeFile, "w");

    int n;
    while (fscanf(read, "%d", &n) != EOF) {
        matrix m = readSquareMatrixFromFile(read, n);
        transposeMatrix(&m);
        writeSquareMatrixToFile(write, m);
    }

    fclose(read);
    fclose(write);
}

//task 2

void fixedPointNumberToFloating(char *readFile, char *writeFile) {
    FILE *read = fopen(readFile, "r");
    FILE *write = fopen(writeFile, "w");

    float x;
    while (fscanf(read, "%f", &x) != EOF)
        fprintf(write, "%.2f\n", x);

    fclose(read);
    fclose(write);
}