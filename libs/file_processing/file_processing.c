#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <assert.h>
#include "file_processing.h"
#include "../data_structures/matrix/matrix.h"
#include "../string_/tasks/stringTasks.h"

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

//task 4

void saveRightWords(char *readFile, char *writeFile, char *sequence) {
    FILE *read = fopen(readFile, "r");
    FILE *write = fopen(writeFile, "w");

    char word[100];

    while (fscanf(read, "%s", word) != EOF)
        if (strstr(&word, sequence))
            fprintf(write, "%s\n", word);

    fclose(read);
    fclose(write);
}

//task 5

void convertStringWithBiggestWord(char *readFile, char *writeFile) {
    FILE *read = fopen(readFile, "r");
    FILE *write = fopen(writeFile, "w");

    char string[100];
    char biggest_word[100];
    WordDescriptor word;

    while (fgets(string, sizeof(string), read)) {
        char *begin = string;
        int word_size = 0;
        while (getWord(begin, &word)) {
            if ((word.end - word.begin) > word_size) {
                wordDescriptorToString(word, biggest_word);
                word_size = word.end - word.begin;
            }
            begin = word.end;
        }
        fprintf(write, "%s\n", biggest_word);
    }
    fclose(read);
    fclose(write);
}

//task 6

typedef struct Polynomial {
    int pow;
    int coef;
} Polynomial;

void removePolynomialsWithRootX(char *readFile, char *writeFile, int x) {
    FILE *read = fopen(readFile, "rb");
    FILE *write = fopen(writeFile, "wb");

    while (!feof(read)) {
        int terms;
        if (fread(&terms, sizeof(int), 1, read) != 1)
            break;

        Polynomial *polynomials = (Polynomial *) malloc(terms * sizeof(Polynomial));
        fread(polynomials, sizeof(Polynomial), terms, read);

        int result = 0;
        for (int i = 0; i < terms; ++i) {
            result += polynomials[i].coef * pow(x, polynomials[i].pow);
        }

        if (result) {
            fwrite(&terms, sizeof(int), 1, write);
            fwrite(polynomials, sizeof(Polynomial), terms, write);
        }
    }

    fclose(read);
    fclose(write);
}

//task 7

void sortFirstPosThenNeg(char *file) {
    FILE *read = fopen(file, "rb");

    fseek(read, 0, SEEK_END);
    int size = ftell(read);
    fseek(read, 0, SEEK_SET);
    int num_amount =  size / sizeof(int);

    int numbers[num_amount];

    fread(numbers, sizeof(int), num_amount, read);
    fclose(read);

    int positive[num_amount / 2];
    int negative[num_amount / 2];
    int pos_i = 0;
    int neg_i = 0;

    for (int i = 0; i < num_amount; i++) {
        if (numbers[i] > 0) {
            positive[pos_i] = numbers[i];
            pos_i++;
        }
        else {
            negative[neg_i] = numbers[i];
            neg_i++;
        }
    }

    FILE *write = fopen(file, "wb");
    fwrite(positive, sizeof(int), pos_i, write);
    fwrite(negative, sizeof(int), neg_i, write);
    fclose(write);
}

//task 8

void transposeMatrixIfNotSym(char *readFile, char *writeFile) {
    FILE *read = fopen(readFile, "rb");
    FILE *write = fopen(writeFile, "wb");

    int n;
    fread(&n, sizeof(int), 1, read);

    matrix m = getMemMatrix(n, n);

    while (fread(&m, sizeof(int), n * n, read) == n * n) {
        if (!isSymmetricMatrix(&m))
            transposeMatrix(&m);

        fwrite(&m, sizeof (int), n * n, write);
    }

    fclose(read);
    fclose(write);
}