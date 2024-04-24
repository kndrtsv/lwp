#include "stringTasks.h"

//task 1

char *getEndOfString(char *s) {
    return s + strlen_(s) - 1;
}

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

//task 2

void removeAdjacentEqualLetters(char *s) {
    char *begin = s;
    char *element = s + 1;

    while (*begin != '\0') {
        if (*element == *begin) {
            element++;
        }
        begin++;
        *begin = *element;
    }
    begin++;
    *begin = '\0';
}