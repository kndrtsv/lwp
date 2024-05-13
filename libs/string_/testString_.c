#include <assert.h>
#include <stdio.h>
#include "testString_.h"

void test_strlen() {
    char test_string[] = "twoPlusEleven";
    int result = strlen_(test_string);
    int expected_result = 13;
    assert(result == expected_result);
}

void test_find() {
    char test_string[] = "abc";
    char *result = find(test_string, test_string + strlen_(test_string), 'b');
    assert(*result == 'b');
}

void test_findNonSpace() {
    char test_string[] = "    cba";
    char *result = findNonSpace(test_string);
    assert(*result == 'c');
}

void test_findSpace() {
    char test_string[] = "ab c";
    char *result = findSpace(test_string);
    assert(*result == ' ');
}

void test_findNonSpaceReverse() {
    char test_string[] = "abc     ";
    char *result = findNonSpaceReverse(test_string + strlen_(test_string) - 1, test_string - 1);
    assert(*result == 'c');
}

void test_findSpaceReverse() {
    char test_string[] = " abc";
    char *result = findSpaceReverse(test_string + strlen_(test_string) - 1, test_string - 1);
    assert(*result == ' ');
}

void test_strcmp() {
    char test_string[] = "abc";
    char test_string2[] = "abc";
    int result = strcmp_(test_string, test_string2);
    int expected_result = 0;
    assert(result == expected_result);
}

void test_copy() {
    char test_string[] = "bca";
    char test_string2[3];
    copy(test_string, test_string + strlen_(test_string), test_string2);
    assert(strcmp_(test_string, test_string2));
}

int is_not_a(int x) {
    return x != 'a';
}

void test_copyIf() {
    char test_string[] = "haealalao";
    char test_string2[5];
    copyIf(test_string, test_string + strlen_(test_string), test_string2, is_not_a);
    char expected_string[] = "hello";
    assert(strcmp_(test_string2, expected_string));
}

void test_copyIfReverse() {
    char test_string[] = "oaalalaaeaah";
    char test_string2[5];
    copyIfReverse(test_string + strlen_(test_string) - 1, test_string - 1, test_string2, is_not_a);
    char expected_string[] = "hello";
    assert(strcmp_(test_string2, expected_string));
}

void testString_() {
    test_strlen();
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp();
    test_copy();
    test_copyIf();
    test_copyIfReverse();
    printf("all tests ok");
}