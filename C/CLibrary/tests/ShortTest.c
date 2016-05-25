#include <stdio.h>
#include <stdlib.h>

#include "test.h"
#include "Short.h"

/*
 * Simple C Test Suite
 */

/**
 * Tests the shortValue function.
 */

void shortValueTest() {
    Short *a;
    int16_t b;
    a = new_Short(Short_MIN_VALUE);
    b = shortValue(a);
    assertEqualsS((int16_t)-32768, b);
    a = new_Short((int16_t) 0);
    b = shortValue(a);
    assertEqualsS((int16_t)0, b);
    a = new_Short(Short_MAX_VALUE);
    b = shortValue(a);
    assertEqualsS((int16_t)32767, b);
}

/**
 * Tests the compareTo function.
 */

void compareToTest() {
    Short *a, *b;
    int32_t c;
    a = new_Short(Short_MIN_VALUE);
    b = new_Short((int16_t) - 1);
    c = compareToS(a, b);
    assertEqualsI(-32767, c);
    a = new_Short(Short_MAX_VALUE);
    b = new_Short((int16_t) 1);
    c = compareToS(a, b);
    assertEqualsI(32766, c);
    a = new_Short((int16_t) 0);
    b = new_Short((int16_t) 1);
    c = compareToS(a, b);
    assertEqualsI(-1, c);
    a = new_Short((int16_t) 0);
    b = new_Short((int16_t) - 1);
    c = compareToS(a, b);
    assertEqualsI(1, c);
    a = new_Short((int16_t) 1);
    b = new_Short((int16_t) 1);
    c = compareToS(a, b);
    assertEqualsI(0, c);
    a = new_Short((int16_t) - 1);
    b = new_Short((int16_t) - 1);
    c = compareToS(a, b);
    assertEqualsI(0, c);
}

/**
 * Tests the compare function.
 */

void compareTest() {
    int16_t a, b;
    int32_t c;
    a = Short_MIN_VALUE;
    b = (int16_t) - 1;
    c = Short_compare(a, b);
    assertEqualsI(-32767, c);
    a = Short_MAX_VALUE;
    b = (int16_t) 1;
    c = Short_compare(a, b);
    assertEqualsI(32766, c);
    a = (int16_t) 0;
    b = (int16_t) 1;
    c = Short_compare(a, b);
    assertEqualsI(-1, c);
    a = (int16_t) 0;
    b = (int16_t) - 1;
    c = Short_compare(a, b);
    assertEqualsI(1, c);
    a = (int16_t) 1;
    b = (int16_t) 1;
    c = Short_compare(a, b);
    assertEqualsI(0, c);
    a = (int16_t) - 1;
    b = (int16_t) - 1;
    c = Short_compare(a, b);
    assertEqualsI(0, c);
}

/**
 * Tests the equals function.
 */

void equalsTest() {
    Short *a, *b;
    bool c;
    a = new_Short(Short_MIN_VALUE);
    b = new_Short((int16_t) - 1);
    c = equalsS(a, b);
    assertEqualsBool(false, c);
    a = new_Short(Short_MAX_VALUE);
    b = new_Short((int16_t) 1);
    c = equalsS(a, b);
    assertEqualsBool(false, c);
    a = new_Short((int16_t) 0);
    b = new_Short((int16_t) 1);
    c = equalsS(a, b);
    assertEqualsBool(false, c);
    a = new_Short((int16_t) 0);
    b = new_Short((int16_t) - 1);
    c = equalsS(a, b);
    assertEqualsBool(false, c);
    a = new_Short((int16_t) 1);
    b = new_Short((int16_t) 1);
    c = equalsS(a, b);
    assertEqualsBool(true, c);
    a = new_Short((int16_t) - 1);
    b = new_Short((int16_t) - 1);
    c = equalsS(a, b);
    assertEqualsBool(true, c);
}

/**
 * Tests the toString function.
 */

void toStringTest() {
    Short *a;
    String *b;
    a = new_Short((int16_t) 1000);
    b = toStringS(a);
    assertEqualsStr("1000", b->s);
    a = new_Short((int16_t) 0);
    b = toStringS(a);
    assertEqualsStr("0", b->s);
    a = new_Short((int16_t) - 1000);
    b = toStringS(a);
    assertEqualsStr("-1000", b->s);
}

/**
 * Tests the static toString function.
 */

void toStringTest2() {
    int16_t a;
    String *b;
    a = (int16_t) 1000;
    b = Short_toString(a);
    assertEqualsStr("1000", b->s);
    a = (int16_t) 0;
    b = Short_toString(a);
    assertEqualsStr("0", b->s);
    a = (int16_t) - 1000;
    b = Short_toString(a);
    assertEqualsStr("-1000", b->s);
}

/**
 * Tests the parseShort function.
 */

void parseShortTest() {
    int16_t a;
    a = Short_parseShort(new_String("1000"));
    assertEqualsS((int16_t)1000, a);
    a = Short_parseShort(new_String("0"));
    assertEqualsS((int16_t)0, a);
    a = Short_parseShort(new_String("-1000"));
    assertEqualsS((int16_t)-1000, a);
}

int main(int argc, char** argv) {
    const int testCount = 7;
    setUpTestModule("ShortTest", testCount);

    registerTest(shortValueTest, "shortValueTest");
    registerTest(compareToTest, "compareToTest");
    registerTest(compareTest, "compareTest");
    registerTest(equalsTest, "equalsTest");
    registerTest(toStringTest, "toStringTest");
    registerTest(toStringTest2, "toStringTest2");
    registerTest(parseShortTest, "parseShortTest");
    
    runTests();

    return (EXIT_SUCCESS);
}
