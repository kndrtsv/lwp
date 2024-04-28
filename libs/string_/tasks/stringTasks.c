#include <stdio.h>
#include "stringTasks.h"

char _stringBuffer[MAX_STRING_SIZE + 1];

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

//task 3

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,_stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1,_stringBuffer - 1,word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void reverseDigitsToStartLettersToEnd(char *s) {
    WordDescriptor word;
    while (getWord(s, &word)) {
        digitToStart(word);
        s = word.end;
    }
}

//additional task

void letterToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,_stringBuffer);
    char *recPosition = copyIf(_stringBuffer,endStringBuffer - 1,word.begin, isalpha);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isdigit);
}

void lettersToStartDigitsToEnd(char *s) {
    WordDescriptor word;
    while (getWord(s, &word)) {
        letterToStart(word);
        s = word.end;
    }
}

//additional task

int getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->begin = findSpaceReverse(rbegin, rend) + 1;
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

//task 4

void replaceDigitBySpaces(char *s) {
    char *readPtr = _stringBuffer;
    char *endStringBuffer = copy(s, s + strlen_(s), _stringBuffer);
    char *recPtr = s;

    while (readPtr != endStringBuffer) {
        if (isalpha(*readPtr))
            *recPtr++ = *readPtr;
        else
            for (int i = 0; i < *readPtr - ASCII_DIGIT_CONVERT; i++)
                *recPtr++ = ' ';
        readPtr++;
    }
    *recPtr = '\0';
}