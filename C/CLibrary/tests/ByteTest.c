#include <stdio.h>
#include <stdlib.h>

#include "test.h"
#include "Byte.h"

/*
 * Simple C Test Suite
 */

/**
 * Tests the byteValue function.
 */

void byteValueTest() {
    Byte *a;
    int8_t b;
    // minimal value
    a = new_Byte(Byte_MIN_VALUE);
    b = byteValue(a);
    assertEqualsB((int8_t)-128, b);
    // zero value
    a = new_Byte((int8_t) 0);
    b = byteValue(a);
    assertEqualsB((int8_t)0, b);
    // maximal value
    a = new_Byte(Byte_MAX_VALUE);
    b = byteValue(a);
    assertEqualsB((int8_t)127, b);
}

/**
 * Tests the compareTo function.
 */

void compareToTest() {
    Byte *a, *b;
    int32_t c;
    // minimal and bigger negative value
    a = new_Byte(Byte_MIN_VALUE);
    b = new_Byte((int8_t) - 1);
    c = compareToB(a, b);
    assertEqualsI(-127, c);
    // maximal and smaller positive value
    a = new_Byte(Byte_MAX_VALUE);
    b = new_Byte((int8_t) 1);
    c = compareToB(a, b);
    assertEqualsI(126, c);
    // zero and positive value
    a = new_Byte((int8_t) 0);
    b = new_Byte((int8_t) 1);
    c = compareToB(a, b);
    assertEqualsI(-1, c);
    // zero and negative value
    a = new_Byte((int8_t) 0);
    b = new_Byte((int8_t) - 1);
    c = compareToB(a, b);
    assertEqualsI(1, c);
    // both values are positive
    a = new_Byte((int8_t) 1);
    b = new_Byte((int8_t) 1);
    c = compareToB(a, b);
    assertEqualsI(0, c);
    // both values are negative
    a = new_Byte((int8_t) - 1);
    b = new_Byte((int8_t) - 1);
    c = compareToB(a, b);
    assertEqualsI(0, c);
}

/**
 * Tests the compare function.
 */

void compareTest() {
    int8_t a, b;
    int32_t c;
    a = Byte_MIN_VALUE;
    b = (int8_t) - 1;
    c = Byte_compare(a, b);
    assertEqualsI(-127, c);
    a = Byte_MAX_VALUE;
    b = (int8_t) 1;
    c = Byte_compare(a, b);
    assertEqualsI(126, c);
    a = (int8_t) 0;
    b = (int8_t) 1;
    c = Byte_compare(a, b);
    assertEqualsI(-1, c);
    a = (int8_t) 0;
    b = (int8_t) - 1;
    c = Byte_compare(a, b);
    assertEqualsI(1, c);
    a = (int8_t) 1;
    b = (int8_t) 1;
    c = Byte_compare(a, b);
    assertEqualsI(0, c);
    a = (int8_t) - 1;
    b = (int8_t) - 1;
    c = Byte_compare(a, b);
    assertEqualsI(0, c);
}

/**
 * Tests the equals function.
 */

void equalsTest() {
    Byte *a, *b;
    bool c;
    a = new_Byte(Byte_MIN_VALUE);
    b = new_Byte((int8_t) - 1);
    c = equalsB(a, b);
    assertEqualsBool(false, c);
    a = new_Byte(Byte_MAX_VALUE);
    b = new_Byte((int8_t) 1);
    c = equalsB(a, b);
    assertEqualsBool(false, c);
    a = new_Byte((int8_t) 0);
    b = new_Byte((int8_t) 1);
    c = equalsB(a, b);
    assertEqualsBool(false, c);
    a = new_Byte((int8_t) 0);
    b = new_Byte((int8_t) - 1);
    c = equalsB(a, b);
    assertEqualsBool(false, c);
    a = new_Byte((int8_t) 1);
    b = new_Byte((int8_t) 1);
    c = equalsB(a, b);
    assertEqualsBool(true, c);
    a = new_Byte((int8_t) - 1);
    b = new_Byte((int8_t) - 1);
    c = equalsB(a, b);
    assertEqualsBool(true, c);
}

/**
 * Tests the toString function.
 */

void toStringTest() {
    Byte *a;
    String *b;
    // positive value text representation
    a = new_Byte((int8_t) 100);
    b = toStringB(a);
    assertEqualsStr("100", b->s);
    // zero value text representation
    a = new_Byte((int8_t) 0);
    b = toStringB(a);
    assertEqualsStr("0", b->s);
    // negative value text representation
    a = new_Byte((int8_t) - 100);
    b = toStringB(a);
    assertEqualsStr("-100", b->s);
}

/**
 * Tests the static toString function.
 */

void toStringTest2() {
    int8_t a;
    String *b;
    a = (int8_t) 100;
    b = Byte_toString(a);
    assertEqualsStr("100", b->s);
    a = (int8_t) 0;
    b = Byte_toString(a);
    assertEqualsStr("0", b->s);
    a = (int8_t) - 100;
    b = Byte_toString(a);
    assertEqualsStr("-100", b->s);
}

/**
 * Tests the parseByte function.
 */

void parseByteTest() {
    int8_t a;
    // positive value parsing
    a = Byte_parseByte(new_String("100"));
    assertEqualsB((int8_t)100, a);
    // zero value parsing
    a = Byte_parseByte(new_String("0"));
    assertEqualsB((int8_t)0, a);
    // negative value parsing
    a = Byte_parseByte(new_String("-100"));
    assertEqualsB((int8_t)-100, a);
}

int main(int argc, char** argv) {
    const int testCount = 7;
    setUpTestModule("ByteTest", testCount);

    registerTest(byteValueTest, "byteValueTest");
    registerTest(compareToTest, "compareToTest");
    registerTest(compareTest, "compareTest");
    registerTest(equalsTest, "equalsTest");
    registerTest(toStringTest, "toStringTest");
    registerTest(toStringTest2, "toStringTest2");
    registerTest(parseByteTest, "parseByteTest");
    
    runTests();

    return (EXIT_SUCCESS);
}
