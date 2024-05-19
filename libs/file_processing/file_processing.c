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

//task 3

int calculate(int n1, int n2, char op) {
    if (op == '+')
        return n1 + n2;
    else if (op == '-')
        return n1 - n2;
    else if (op == '*')
        return n1 * n2;
    else if (op == '/')
        return n1 / n2;
}

void writeCalculatedExpression(char *file) {
    FILE *read = fopen(file, "r");
    FILE *write = fopen(file, "a");

    int n1, n2, n3;
    char op1, op2;

    fscanf(read, "%d %c %d %c %d", &n1, &op1, &n2, &op2, &n3);

    int result = 0;

    if (op1 == '*' || op1 == '/') {
        result += calculate(n1, n2, op1);
        result = calculate(result, n3, op2);
    }
    else if (op2 == '*' || op2 == '/') {
        result += calculate(n2, n3, op2);
        result = calculate(n1, result, op1);
    }
    else {
        result += calculate(n1, n2, op1);
        result = calculate(result, n3, op2);
    }

    fprintf(write, " = %d", result);

    fclose(read);
    fclose(write);
}