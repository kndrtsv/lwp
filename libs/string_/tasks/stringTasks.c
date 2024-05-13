#include <stdio.h>
#include <stdlib.h>
#include "stringTasks.h"

char _stringBuffer[MAX_STRING_SIZE + 1];
BagOfWords _bag;
BagOfWords _bag2;

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
    word->end = findNonSpaceReverse(rbegin, rend) + 1;
    if (word->end - 1 == rend)
        return 0;

    word->begin = findSpaceReverse(word->end - 1, rend) + 1;

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
    while (*lhs && *rhs && *lhs == *rhs && size) {
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

//task 7

void getBagOfWords(BagOfWords *bag, char *s) {
    int i = 0;
    while (getWord(s, &bag->words[i])) {
        bag->size = i + 1;
        s = bag->words[i].end;
        i++;
    }
}

void reversePrintWords(char *s) {
    getBagOfWords(&_bag, s);

    for (int i = 0; i < _bag.size; i++) {
        for (int j = 0; j < _bag.words[i].end - _bag.words[i].begin; j++) {
            char *l = _bag.words[i].begin + j;
            printf("%c", *l);
        }
        printf("\n");
    }
}

//task 8

int isPalindrome(WordDescriptor word) {
    word.end--;

    while (word.begin < word.end) {
        if (*word.begin != *word.end)
            return 0;

        word.begin++;
        word.end--;
    }
    return 1;
}

int palindromesCounter(char *s) {
    int count = 0;
    WordDescriptor word;

    replace(s,","," ");

    while (getWord(s, &word)) {
        if (isPalindrome(word))
            count++;

        s = word.end;
    }
    return count;
}

//task 9

void mixWords(char *s1, char *s2, char *destination) {
    WordDescriptor word1, word2;
    int isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    char *endOfDestination = destination;
    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {

        if (isW1Found) {
            endOfDestination = copy(word1.begin, word1.end, endOfDestination);
            *endOfDestination = ' ';
            endOfDestination++;
            beginSearch1 = word1.end;
        }

        if (isW2Found) {
            endOfDestination = copy(word2.begin, word2.end, endOfDestination);
            *endOfDestination = ' ';
            endOfDestination++;
            beginSearch2 = word2.end;
        }
    }
    *endOfDestination = '\0';
}

//task 10

void reverseWords(char *s) {
    char *rend = _stringBuffer;
    char *rbegin = copy(s, s + strlen_(s), _stringBuffer);
    char *recPtr = s;
    WordDescriptor word;

    while (getWordReverse(rbegin - 1, rend - 1, &word)) {
        recPtr = copy(word.begin, word.end, recPtr);
        *recPtr = ' ';
        recPtr++;
        rbegin = word.begin - 1;
    }
    *recPtr = '\0';
}

//task 11

int isLetterIn(char *begin, char *end, char *letter) {
    while (begin != end && tolower(*begin) != tolower(*letter))
        begin++;

    return begin != end;
}

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, WordDescriptor *w) {
    char *begin = s;
    int isWordInString = isLetterIn(s, s + strlen_(s), "a");

    if (!strlen_(s))
        return EMPTY_STRING;
    else if (!isWordInString)
        return NOT_FOUND_A_WORD_WITH_A;

    while (getWord(begin, w)) {
        if (isLetterIn(w->begin, w->end, "a")) {
            int isWordFound = getWordReverse(w->begin - 1, s - 1, w);
            if (!isWordFound)
                return FIRST_WORD_WITH_A;
            else
                return WORD_FOUND;
        }
        begin = w->end;
    }
}

void printWordBeforeFirstWordWithA(char *s) {
    WordDescriptor word;
    WordBeforeFirstWordWithAReturnCode code = getWordBeforeFirstWordWithA(s, &word);

    if (code == EMPTY_STRING)
        printf("No words in string");
    else if (code == NOT_FOUND_A_WORD_WITH_A)
        printf(("No words with a in string"));
    else if (code == FIRST_WORD_WITH_A)
        printf("First word with a");
    else {
        for (char *l = word.begin; l != word.end; l++)
            printf("%c", *l);
    }
}

//task 12

void wordDescriptorToString(WordDescriptor word, char *destination) {
    char *endOfString = copy(word.begin, word.end, destination);
    *endOfString = '\0';
}

WordDescriptor getLastWordFromFirstStringIfInSecondString(char *s1, char *s2) {
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);
    WordDescriptor word = {NULL, NULL};

    for (int i = _bag.size - 1; i >= 0; i--)
        for (int j = _bag2.size - 1; j >= 0; j--)
            if (!strcmpSize(_bag.words[i].begin, _bag2.words[j].begin, _bag.words[i].end - _bag.words[i].begin))
                return _bag.words[i];

    return word;
}

//task 13

int isStringUniq(char *s) {
    getBagOfWords(&_bag, s);

    for (int i = 0; i < _bag.size; i++)
        for (int j = i + 1; j < _bag.size; j++)
            if (strcmpSize(_bag.words[i].begin, _bag.words[j].begin, _bag.words[i].end - _bag.words[i].begin))
                return 0;

    return 1;
}

//task 14

int compareChar(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

int isWordsWithEqualLettersSet(char *s) {
    char *endOfString = copy(s, s + strlen_(s), _stringBuffer);
    getBagOfWords(&_bag, _stringBuffer);

    for (int i = 0; i < _bag.size; i++)
        qsort(_bag.words[i].begin, _bag.words[i].end - _bag.words[i].begin, sizeof(char), compareChar);

    return isStringUniq(_stringBuffer);
}

//task 15

void getStringWithoutAllWordsEqualLast(char *s) {
    WordDescriptor last_word;
    getWordReverse(s + strlen_(s), s, &last_word);

    char *buffer = copy(s, s + strlen_(s), _stringBuffer);
    buffer = _stringBuffer;
    WordDescriptor word;
    char *write = s;

    while (getWord(buffer, &word)) {
        if (strcmpSize(word.begin, last_word.begin, last_word.end - last_word.begin - 1) != 0) {
            write = copy(word.begin, word.end, write);
            *write = ' ';
            write++;
        }
        buffer = word.end + 1;
    }

    write--;
    *write = '\0';
}

//task 16

WordDescriptor findWordBeforeFirstWordInTwoStrings(char *s1, char *s2) {
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);

    for (int i = 0; i < _bag.size; i++)
        for (int j = 0; j < _bag2.size; j++)
            if (!areWordsEqual(_bag.words[i], _bag2.words[j]))
                return _bag.words[i - 1];
}

//task 17

void deletePalindromes(char *s) {
    char *buffer = copy(s, s + strlen_(s), _stringBuffer);
    buffer = _stringBuffer;
    WordDescriptor word;
    char *write = s;

    while (getWord(buffer, &word)) {
        if (!isPalindrome(word)) {
            write = copy(word.begin, word.end, write);
            *write = ' ';
            write++;
        }
        buffer = word.end + 1;
    }

    write--;
    *write = '\0';
}

//task 18

void addWordsToSmallString(char *s1, char *s2) {
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);
    char *write;
    int isFirstStringLarger = _bag.size > _bag2.size ? 1 : 0;
    int difference = abs(_bag.size - _bag2.size);

    if (isFirstStringLarger) {
        write = _bag2.words[_bag2.size - 1].end;
        *write = ' ';
        write++;
        for (int i = 0; i < difference; i++) {
            write = copy(_bag.words[_bag2.size + i].begin, _bag.words[_bag2.size + i].end, write);
            *write = ' ';
            write++;
        }
    }
    else {
        write = _bag.words[_bag.size - 1].end;
        *write = ' ';
        write++;
        for (int i = 0; i < difference; i++) {
            write = copy(_bag2.words[_bag.size + i].begin, _bag2.words[_bag.size + i].end, write);
            *write = ' ';
            write++;
        }
    }
    *write = '\0';
}

//task 19

int isEveryWordLetterInString(char *s, char *word) {
    int letters[ALPHABET] = {0};

    for (int i = 0; i < strlen_(word); i++) {
        char elem = word[i];
        if (isalpha(elem))
            letters[elem - ASCII_LETTER_CONVERT] = 1;
    }

    int count = 0;

    for (int i = 0; i < strlen_(s); i++) {
        char elem = s[i];
        if (isalpha(elem) && letters[elem - ASCII_LETTER_CONVERT]) {
            count++;
            letters[elem - ASCII_LETTER_CONVERT] = 0;
        }
    }

    if (count == strlen_(word))
        return 1;

    return 0;
}