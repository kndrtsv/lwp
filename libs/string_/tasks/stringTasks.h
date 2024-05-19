#ifndef LWBOP_STRINGTASKS_H
#define LWBOP_STRINGTASKS_H

#include "C:\Users\user\CLionProjects\lwbop\libs\string_\string_.h"
#include <ctype.h>

int getWord(char *beginSearch, WordDescriptor *word);

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

void reverseWords(char *s);

int getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, WordDescriptor *w);

void printWordBeforeFirstWordWithA(char *s);

void wordDescriptorToString(WordDescriptor word, char *destination);

WordDescriptor getLastWordFromFirstStringIfInSecondString(char *s1, char *s2);

int isStringUniq(char *s);

int isWordsWithEqualLettersSet(char *s);

void getStringWithoutAllWordsEqualLast(char *s);

WordDescriptor findWordBeforeFirstWordInTwoStrings(char *s1, char *s2);

void deletePalindromes(char *s);

void addWordsToSmallString(char *s1, char *s2);

int isEveryWordLetterInString(char *s, char *word);

void assertString(const char *expected, char *got, char const *fileName, char const *funcName, int line);

#endif //LWBOP_STRINGTASKS_H