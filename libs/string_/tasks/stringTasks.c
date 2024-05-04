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

//task 5

int strcmpSize(char *lhs, char *rhs, int size) {
    while (*lhs && *rhs && *lhs == *rhs) {
        lhs++;
        rhs++;
        size--;
    }

    if (!size)
        return 0;
    else {
        return *lhs - *rhs;;
    }
}

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};
    char *readPtr, *recPtr;

    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, getEndOfString(source), _stringBuffer);
        readPtr = _stringBuffer;
        recPtr = source;
    }

    while (*readPtr != '\0') {
        if (strcmpSize(readPtr, w1, w1Size) == 0) {
            copy(word2.begin, word2.end, recPtr);
            readPtr += w1Size;
            recPtr += w2Size;
        }
        else
            *recPtr++ = *readPtr++;
    }
    *recPtr = '\0';
}

//task 6

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    strcmpSize(w1.begin, w2.begin, w1.end - w1.begin);
}

int isOrderedLexicographically(char *s) {
    WordDescriptor word;
    WordDescriptor word2;

    while (getWord(s, &word)) {
        if (getWord(word.end, &word2))
            if (areWordsEqual(word, word2) && strcmpSize(word.begin, word2.begin, word.end - word.begin))
                return 0;

        s = word.end;
    }
    return 1;
}