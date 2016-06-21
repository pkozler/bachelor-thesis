#include <stdio.h>
#include <stdlib.h>

#include "test.h"
#include "String.h"

/**
 * A String module test suite.
 *
 * @author Petr Kozler (A13B0359P)
 */

/**
 * Tests the constructor with standard string as a parameter.
 */

void stringTest() {
    String *a;
    // a string with whitespaces
    a = new_String("This is a test.");
    assertEqualsStr("This is a test.", a->s);
    // letters
    a = new_String("test");
    assertEqualsStr("test", a->s);
    // digits
    a = new_String("1234");
    assertEqualsStr("1234", a->s);
    // one char
    a = new_String("a");
    assertEqualsStr("a", a->s);
    // empty string
    a = new_String("");
    assertEqualsStr("", a->s);
}

/**
 * Tests the constructor with array of bytes as a parameter.
 */

void stringTest2() {
    const int32_t length = 15;
    const int32_t length2 = 4;
    const int32_t length3 = 0;
    int8_t *a;
    String *b;
    // array with some whitespaces
    a = malloc(length * sizeof(int8_t));
    a[0] = (int8_t) 'T';
    a[1] = (int8_t) 'h';
    a[2] = (int8_t) 'i';
    a[3] = (int8_t) 's';
    a[4] = (int8_t) ' ';
    a[5] = (int8_t) 'i';
    a[6] = (int8_t) 's';
    a[7] = (int8_t) ' ';
    a[8] = (int8_t) 'a';
    a[9] = (int8_t) ' ';
    a[10] = (int8_t) 't';
    a[11] = (int8_t) 'e';
    a[12] = (int8_t) 's';
    a[13] = (int8_t) 't';
    a[14] = (int8_t) '.';
    b = new_StringB(a, length);
    assertEqualsStr("This is a test.", b->s);
    // array without whitespaces
    a = malloc(length2 * sizeof(int8_t));
    a[0] = (int8_t) '1';
    a[1] = (int8_t) '2';
    a[2] = (int8_t) '3';
    a[3] = (int8_t) '4';
    b = new_StringB(a, length2);
    assertEqualsStr("1234", b->s);
    // empty array
    a = malloc(length3 * sizeof(int8_t));
    b = new_StringB(a, length3);
    assertEqualsStr("", b->s);
}

/**
 * Tests the constructor with array of bytes and indexes as parameters.
 */

void stringTest3() {
    const int32_t length = 15;
    int8_t *a;
    String *b;
    // choosing a part of array with some chars
    a = malloc(length * sizeof(int8_t));
    a[0] = (int8_t) 'T';
    a[1] = (int8_t) 'h';
    a[2] = (int8_t) 'i';
    a[3] = (int8_t) 's';
    a[4] = (int8_t) ' ';
    a[5] = (int8_t) 'i';
    a[6] = (int8_t) 's';
    a[7] = (int8_t) ' ';
    a[8] = (int8_t) 'a';
    a[9] = (int8_t) ' ';
    a[10] = (int8_t) 't';
    a[11] = (int8_t) 'e';
    a[12] = (int8_t) 's';
    a[13] = (int8_t) 't';
    a[14] = (int8_t) '.';
    b = new_StringRangeB(a, 10, 4);
    assertEqualsStr("test", b->s);
}

/**
 * Tests the compareTo function.
 */

void compareToTest() {
    String *a, *b;
    int32_t c;
    // differens strings at the beginning
    a = new_String("aaa");
    b = new_String("bbb");
    c = compareToStr(a, b);
    assertEqualsI(-1, c);
    // different strings at the end
    a = new_String("aaaa");
    b = new_String("aaab");
    c = compareToStr(a, b);
    assertEqualsI(-1, c);
    // differens strings at the beginning (swapped)
    a = new_String("bbb");
    b = new_String("aaa");
    c = compareToStr(a, b);
    assertEqualsI(1, c);
    // different strings at the end (swapped)
    a = new_String("aaab");
    b = new_String("aaaa");
    c = compareToStr(a, b);
    assertEqualsI(1, c);
    // equal strings
    a = new_String("aaa");
    b = new_String("aaa");
    c = compareToStr(a, b);
    assertEqualsI(0, c);
}

/**
 * Tests the equals function.
 */

void equalsTest() {
    String *a, *b;
    bool c;
    a = new_String("aaa");
    b = new_String("bbb");
    c = equalsStr(a, b);
    assertEqualsBool(false, c);
    a = new_String("aaaa");
    b = new_String("aaab");
    c = equalsStr(a, b);
    assertEqualsBool(false, c);
    a = new_String("bbb");
    b = new_String("aaa");
    c = equalsStr(a, b);
    assertEqualsBool(false, c);
    a = new_String("aaab");
    b = new_String("aaaa");
    c = equalsStr(a, b);
    assertEqualsBool(false, c);
    a = new_String("aaa");
    b = new_String("aaa");
    c = equalsStr(a, b);
    assertEqualsBool(true, c);
}

/**
 * Tests the substring function.
 */

void substringTest() {
    String *a, *b;
    a = new_String("This is a test.");
    // string from the beginning
    b = substring(a, 0);
    assertEqualsStr("This is a test.", b->s);
    // string from some other position
    b = substring(a, 10);
    assertEqualsStr("test.", b->s);
}

/**
 * Tests the substring function with end index as a parameter.
 */

void substringTest2() {
    String *a, *b;
    a = new_String("This is a test.");
    // string from the beginning to the position near the beginning
    b = substringTo(a, 0, 4);
    assertEqualsStr("This", b->s);
    // string from the beginning to the position far from the beginning
    b = substringTo(a, 10, 14);
    assertEqualsStr("test", b->s);
    // string from the end
    b = substringTo(a, 14, 15);
    assertEqualsStr(".", b->s);
    // equal indexes
    b = substringTo(a, 10, 10);
    assertEqualsStr("", b->s);
}

/**
 * Tests the indexOf function with a char value.
 */

void indexOfTest() {
    String *a;
    int32_t b;
    a = new_String("This is a test.");
    // char occurring once
    b = indexOfC(a, 'a');
    assertEqualsI(8, b);
    // char occuring more times
    b = indexOfC(a, 't');
    assertEqualsI(10, b);
    // char occurring once (at the beginning)
    b = indexOfC(a, 'T');
    assertEqualsI(0, b);
    // char occurring once (at the end)
    b = indexOfC(a, '.');
    assertEqualsI(14, b);
    // char not occurring
    b = indexOfC(a, '_');
    assertEqualsI(-1, b);
}

/**
 * Tests the indexOf function with a char value and end index as a parameter.
 */

void indexOfTest2() {
    String *a;
    int32_t b;
    a = new_String("This is a test.");
    b = indexOfFromC(a, 'a', 10);
    assertEqualsI(-1, b);
    b = indexOfFromC(a, 't', 10);
    assertEqualsI(10, b);
    b = indexOfFromC(a, 'i', 0);
    assertEqualsI(2, b);
    b = indexOfFromC(a, 'i', 4);
    assertEqualsI(5, b);
    b = indexOfFromC(a, 'i', 10);
    assertEqualsI(-1, b);
}

/**
 * Tests the indexOf function with a string.
 */

void indexOfTest3() {
    String *a;
    int32_t b;
    a = new_String("This is a test.");
    // occurring string (at the beginning)
    b = indexOfStr(a, new_String("This"));
    assertEqualsI(0, b);
    // occurring string (at the end)
    b = indexOfStr(a, new_String("test"));
    assertEqualsI(10, b);
    // non-occurring string
    b = indexOfStr(a, new_String("aaa"));
    assertEqualsI(-1, b);
}

/**
 * Tests the indexOf function with a string and end index as a parameter.
 */

void indexOfTest4() {
    String *a;
    int32_t b;
    a = new_String("This is a test.");
    b = indexOfFromStr(a, new_String("This"), 0);
    assertEqualsI(0, b);
    b = indexOfFromStr(a, new_String("test"), 4);
    assertEqualsI(10, b);
    b = indexOfFromStr(a, new_String("This"), 10);
    assertEqualsI(-1, b);
}

/**
 * Tests the length function.
 */

void lengthTest() {
    String *a;
    int32_t b;
    // string with multiple chars
    a = new_String("This is a test.");
    b = length(a);
    assertEqualsI(15, b);
    // string with one char
    a = new_String(".");
    b = length(a);
    assertEqualsI(1, b);
    // empty string
    a = new_String("");
    b = length(a);
    assertEqualsI(0, b);
}

/**
 * Tests the trim function.
 */

void trimTest() {
    String *a, *b;
    // string without whitespaces
    a = new_String("test");
    b = trim(a);
    assertEqualsStr("test", b->s);
    // whitespaces on the left side
    a = new_String("   test");
    b = trim(a);
    assertEqualsStr("test", b->s);
    // whitespaces on the right side
    a = new_String("test   ");
    b = trim(a);
    assertEqualsStr("test", b->s);
    // whitespaces on bots sides
    a = new_String(" test ");
    b = trim(a);
    assertEqualsStr("test", b->s);
    // whitespaces inside
    a = new_String("t e s t");
    b = trim(a);
    assertEqualsStr("t e s t", b->s);
}

/**
 * Tests the toLower function.
 */

void toLowerCaseTest() {
    String *a, *b;
    // all letters lowercase
    a = new_String("test");
    b = toLowerCase(a);
    assertEqualsStr("test", b->s);
    // all letters uppercase
    a = new_String("TEST");
    b = toLowerCase(a);
    assertEqualsStr("test", b->s);
    // different cases
    a = new_String("TesT");
    b = toLowerCase(a);
    assertEqualsStr("test", b->s);
}

/**
 * Tests the toUpper function.
 */

void toUpperCaseTest() {
    String *a, *b;
    a = new_String("test");
    b = toUpperCase(a);
    assertEqualsStr("TEST", b->s);
    a = new_String("TEST");
    b = toUpperCase(a);
    assertEqualsStr("TEST", b->s);
    a = new_String("TesT");
    b = toUpperCase(a);
    assertEqualsStr("TEST", b->s);
}

/**
 * Tests the charAt function.
 */

void charAtTest() {
    String *a;
    char b;
    a = new_String("This is a test.");
    // at the beginning
    b = charAt(a, 0);
    assertEqualsC('T', b);
    // in the middle
    b = charAt(a, 10);
    assertEqualsC('t', b);
    // at the end
    b = charAt(a, 14);
    assertEqualsC('.', b);
}

/**
 * Tests the replace function.
 */

void replaceTest() {
    String *a, *b;
    a = new_String("This is a test.");
    // replacing chars inside the string
    b = replace(a, ' ', '_');
    assertEqualsStr("This_is_a_test.", b->s);
    // replacing chars in the beginning of the string
    b = replace(a, 'T', 't');
    assertEqualsStr("this is a test.", b->s);
    // replacing chars in the end of the string
    b = replace(a, '.', '!');
    assertEqualsStr("This is a test!", b->s);
    // replacing of the non-existent chars
    b = replace(a, '?', ':');
    assertEqualsStr("This is a test.", b->s);
}

/**
 * Tests the startsWith function.
 */

void startsWithTest() {
    String *a, *b;
    bool c;
    a = new_String("This is a test.");
    // string at the beginning
    b = new_String("This ");
    c = startsWith(a, b);
    assertEqualsBool(true, c);
    // string inside
    b = new_String("is");
    c = startsWith(a, b);
    assertEqualsBool(false, c);
    // string at the end
    b = new_String("test.");
    c = startsWith(a, b);
    assertEqualsBool(false, c);
}

/**
 * Tests the endsWith function.
 */

void endsWithTest() {
    String *a, *b;
    bool c;
    a = new_String("This is a test.");
    b = new_String("This ");
    c = endsWith(a, b);
    assertEqualsBool(false, c);
    b = new_String("is");
    c = endsWith(a, b);
    assertEqualsBool(false, c);
    b = new_String("test.");
    c = endsWith(a, b);
    assertEqualsBool(true, c);
}

/**
 * Tests the isEmpty function.
 */

void isEmptyTest() {
    String *a;
    bool b;
    // non-empty string
    a = new_String("This is a test.");
    b = isEmptyStr(a);
    assertEqualsBool(false, b);
    // non-empty string with a single char
    a = new_String(".");
    b = isEmptyStr(a);
    assertEqualsBool(false, b);
    // empty string
    a = new_String("");
    b = isEmptyStr(a);
    assertEqualsBool(true, b);
}

int main(int argc, char** argv) {
    const int testCount = 20;
    setUpTestModule("StringTest", testCount);

    registerTest(stringTest, "stringTest");
    registerTest(stringTest2, "stringTest2");
    registerTest(stringTest3, "stringTest3");
    registerTest(compareToTest, "compareToTest");
    registerTest(equalsTest, "equalsTest");
    registerTest(substringTest, "substringTest");
    registerTest(substringTest2, "substringTest2");
    registerTest(indexOfTest, "indexOfTest");
    registerTest(indexOfTest2, "indexOfTest2");
    registerTest(indexOfTest3, "indexOfTest3");
    registerTest(indexOfTest4, "indexOfTest4");
    registerTest(lengthTest, "lengthTest");
    registerTest(trimTest, "trimTest");
    registerTest(toLowerCaseTest, "toLowerCaseTest");
    registerTest(toUpperCaseTest, "toUpperCaseTest");
    registerTest(charAtTest, "charAtTest");
    registerTest(replaceTest, "replaceTest");
    registerTest(startsWithTest, "startsWithTest");
    registerTest(endsWithTest, "endsWithTest");
    registerTest(isEmptyTest, "isEmptyTest");
    
    runTests();

    return (EXIT_SUCCESS);
}
