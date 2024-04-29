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

#endif //LWBOP_STRINGTASKS_H