#ifndef LWBOP_STRINGTASKS_H
#define LWBOP_STRINGTASKS_H

#include "C:\Users\user\CLionProjects\lwbop\libs\string_\string_.h"
#include <ctype.h>

void removeNonLetters(char *s);

void removeAdjacentEqualLetters(char *s);

void reverseDigitsToStartLettersToEnd(char *s);

void lettersToStartDigitsToEnd(char *s);

void replaceDigitBySpaces(char *s);

void replace(char *source, char *w1, char *w2);

int isOrderedLexicographically(char *s);

void reversePrintWords(char *s);

int palindromesCounter(char *s);

void mixWords(char *s1, char *s2, char *destination);

#endif //LWBOP_STRINGTASKS_H