#include "testStringTasks.h"
#include <stdio.h>
#include <assert.h>

void test_removeNonLetters() {
    char s[] = "A B  C    ";
    removeNonLetters(s);
    char exp_s[] = "ABC";
    ASSERT_STRING(exp_s, s);
}

void test_removeAdjacentEqualLetters() {
    char s[] = "abbcccdddd";
    removeAdjacentEqualLetters(s);
    char exp_s[] = "abcd";
    ASSERT_STRING(exp_s, s);
}

void test_reverseDigitsToStartLettersToEnd() {
    char s[] = "a1 b2";
    reverseDigitsToStartLettersToEnd(s);
    char exp_s[] = "1a 2b";
    ASSERT_STRING(exp_s, s);
}

void test_replaceDigitBySpaces() {
    char s[] = "a1b2c3";
    replaceDigitBySpaces(s);
    char exp_s[] = "a b  c   ";
    ASSERT_STRING(exp_s, s);
}

void test_replace() {
    char s[] = "a b a b";
    replace(s, "a", "b");
    char exp_s[] = "b b b b";
    ASSERT_STRING(exp_s, s);
}

void test_isOrderedLexicographically() {
    char s[] = "a c b";
    int res = isOrderedLexicographically(s);
    int exp_res = 0;
    if (res == exp_res)
        fprintf(stderr, "%s - OK\n", "test_isOrderedLexicographically");
}

void test_palindromesCounter() {
    char s[] = "eye first bob three";
    int res = palindromesCounter(s);
    int exp_res = 2;
    if (res == exp_res)
        fprintf(stderr, "%s - OK\n", "test_palindromesCounter");
}

void test_mixWords() {
    char s[] = "one two";
    char s2[] = "three four";
    char res[MAX_STRING_SIZE];
    mixWords(s, s2, res);
    char exp_s[] = "one three two four";
    ASSERT_STRING(exp_s, res);
}

void test_reverseWords() {
    char s[] = "one two three four";
    reverseWords(s);
    char exp_s[] = "four three two one";
    ASSERT_STRING(exp_s, s);
}

void test_getWordBeforeFirstWordWithA() {
    WordDescriptor word;

    char s1[] = "";
    assert(getWordBeforeFirstWordWithA(s1, &word) == EMPTY_STRING);
    char s2[] = "a";
    assert(getWordBeforeFirstWordWithA(s2, &word) == FIRST_WORD_WITH_A);
    char s3[] = "b a";
    assert(getWordBeforeFirstWordWithA(s3, &word) == WORD_FOUND);
    char s4[] = "b c d";
    assert(getWordBeforeFirstWordWithA(s4, &word) == NOT_FOUND_A_WORD_WITH_A);

    fprintf(stderr, "%s - OK\n", "test_getWordBeforeFirstWordWithA");
}

void test_getLastWordFromFirstStringIfInSecondString() {
    char s1[] = "a b c d";
    char s2[] = "h n c";
    WordDescriptor word = getLastWordFromFirstStringIfInSecondString(s1, s2);
    char word_to_string[MAX_STRING_SIZE];
    wordDescriptorToString(word, word_to_string);
    ASSERT_STRING("c", word_to_string);
}

void test_isStringUniq() {
    char s[] = "a b c";
    int res = isStringUniq(s);
    int exp_res = 1;
    if (res == exp_res)
        fprintf(stderr, "%s - OK\n", "test_isStringUniq");
}

void test_isWordsWithEqualLettersSet() {
    char s[] = "code deco de";
    int res = isWordsWithEqualLettersSet(s);
    int exp_res = 1;
    if (res == exp_res)
        fprintf(stderr, "%s - OK\n", "test_isWordsWithEqualLettersSet");
}

void test_getStringWithoutAllWordsEqualLast() {
    char s[] = "one two three one five one";
    getStringWithoutAllWordsEqualLast(s);
    char exp_s[] = "two three five";
    ASSERT_STRING(exp_s, s);
}

void test_findWordBeforeFirstWordInTwoStrings() {
    char s1[] = "a b c d";
    char s2[] = "h n c";
    WordDescriptor word = findWordBeforeFirstWordInTwoStrings(s1, s2);
    char word_to_string[MAX_STRING_SIZE];
    wordDescriptorToString(word, word_to_string);
    ASSERT_STRING("b", word_to_string);
}

void test_deletePalindromes() {
    char s[] = "eye bob cop rock duck mouse sos";
    deletePalindromes(s);
    char exp_s[] = "cop rock duck mouse";
    ASSERT_STRING(exp_s, s);
}

void test_isEveryWordLetterInString() {
    char s[] = "apple but cold";
    char word[] = "abc";
    int res = isEveryWordLetterInString(s, word);
    int exp_res = 1;
    if (res == exp_res)
        fprintf(stderr, "%s - OK\n", "test_isEveryWordLetterInString");
}

void test() {
    test_removeNonLetters();
    test_removeAdjacentEqualLetters();
    test_reverseDigitsToStartLettersToEnd();
    test_replaceDigitBySpaces();
    test_replace();
    test_isOrderedLexicographically();
    test_palindromesCounter();
    test_mixWords();
    test_reverseWords();
    test_getWordBeforeFirstWordWithA();
    test_getLastWordFromFirstStringIfInSecondString();
    test_isStringUniq();
    test_isWordsWithEqualLettersSet();
    test_getStringWithoutAllWordsEqualLast();
    test_findWordBeforeFirstWordInTwoStrings();
    test_deletePalindromes();
    test_isEveryWordLetterInString();
}