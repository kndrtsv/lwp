#ifndef LWBOP_STRINGTASKS_H
#define LWBOP_STRINGTASKS_H

#include "C:\Users\user\CLionProjects\lwbop\libs\string_\string_.h"
#include <ctype.h>

void removeNonLetters(char *s);

void removeAdjacentEqualLetters(char *s);

void reverseDigitsToStartLettersToEnd(char *s);

void lettersToStartDigitsToEnd(char *s);
int getWordReverse(char *rbegin, char *rend, WordDescriptor *word);
#endif //LWBOP_STRINGTASKS_H