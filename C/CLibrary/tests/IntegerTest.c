#include <stdio.h>
#include <stdlib.h>

#include "test.h"
#include "Integer.h"

/*
 * Simple C Test Suite
 */

/**
 * Tests the intValue function.
 */

void intValueTest() {
    Integer *a;
    int32_t b;
    a = new_Integer(Integer_MIN_VALUE);
    b = intValue(a);
    assertEqualsI((int32_t)-2147483648, b);
    a = new_Integer((int32_t) 0);
    b = intValue(a);
    assertEqualsI(0, b);
    a = new_Integer(Integer_MAX_VALUE);
    b = intValue(a);
    assertEqualsI(2147483647, b);
}

/**
 * Tests the compareTo function.
 */

void compareToTest() {
    Integer *a, *b;
    int32_t c;
    a = new_Integer(Integer_MIN_VALUE);
    b = new_Integer((int32_t) - 1);
    c = compareToI(a, b);
    assertEqualsI(-1, c);
    a = new_Integer(Integer_MAX_VALUE);
    b = new_Integer((int32_t) 1);
    c = compareToI(a, b);
    assertEqualsI(1, c);
    a = new_Integer((int32_t) 0);
    b = new_Integer((int32_t) 1);
    c = compareToI(a, b);
    assertEqualsI(-1, c);
    a = new_Integer((int32_t) 0);
    b = new_Integer((int32_t) - 1);
    c = compareToI(a, b);
    assertEqualsI(1, c);
    a = new_Integer((int32_t) 1);
    b = new_Integer((int32_t) 1);
    c = compareToI(a, b);
    assertEqualsI(0, c);
    a = new_Integer((int32_t) - 1);
    b = new_Integer((int32_t) - 1);
    c = compareToI(a, b);
    assertEqualsI(0, c);
}

/**
 * Tests the compare function.
 */

void compareTest() {
    int32_t a, b;
    int32_t c;
    a = Integer_MIN_VALUE;
    b = (int32_t) - 1;
    c = Integer_compare(a, b);
    assertEqualsI(-1, c);
    a = Integer_MAX_VALUE;
    b = (int32_t) 1;
    c = Integer_compare(a, b);
    assertEqualsI(1, c);
    a = (int32_t) 0;
    b = (int32_t) 1;
    c = Integer_compare(a, b);
    assertEqualsI(-1, c);
    a = (int32_t) 0;
    b = (int32_t) - 1;
    c = Integer_compare(a, b);
    assertEqualsI(1, c);
    a = (int32_t) 1;
    b = (int32_t) 1;
    c = Integer_compare(a, b);
    assertEqualsI(0, c);
    a = (int32_t) - 1;
    b = (int32_t) - 1;
    c = Integer_compare(a, b);
    assertEqualsI(0, c);
}

/**
 * Tests the equals function.
 */

void equalsTest() {
    Integer *a, *b;
    bool c;
    a = new_Integer(Integer_MIN_VALUE);
    b = new_Integer((int32_t) - 1);
    c = equalsI(a, b);
    assertEqualsBool(false, c);
    a = new_Integer(Integer_MAX_VALUE);
    b = new_Integer((int32_t) 1);
    c = equalsI(a, b);
    assertEqualsBool(false, c);
    a = new_Integer((int32_t) 0);
    b = new_Integer((int32_t) 1);
    c = equalsI(a, b);
    assertEqualsBool(false, c);
    a = new_Integer((int32_t) 0);
    b = new_Integer((int32_t) - 1);
    c = equalsI(a, b);
    assertEqualsBool(false, c);
    a = new_Integer((int32_t) 1);
    b = new_Integer((int32_t) 1);
    c = equalsI(a, b);
    assertEqualsBool(true, c);
    a = new_Integer((int32_t) - 1);
    b = new_Integer((int32_t) - 1);
    c = equalsI(a, b);
    assertEqualsBool(true, c);
}

/**
 * Tests the toString function.
 */

void toStringTest() {
    Integer *a;
    String *b;
    a = new_Integer((int32_t) 100000);
    b = toStringI(a);
    assertEqualsStr("100000", b->s);
    a = new_Integer((int32_t) 0);
    b = toStringI(a);
    assertEqualsStr("0", b->s);
    a = new_Integer((int32_t) - 100000);
    b = toStringI(a);
    assertEqualsStr("-100000", b->s);
}

/**
 * Tests the static toString function.
 */

void toStringTest2() {
    int32_t a;
    String *b;
    a = (int32_t) 100000;
    b = Integer_toString(a);
    assertEqualsStr("100000", b->s);
    a = (int32_t) 0;
    b = Integer_toString(a);
    assertEqualsStr("0", b->s);
    a = (int32_t) - 100000;
    b = Integer_toString(a);
    assertEqualsStr("-100000", b->s);
}

/**
 * Tests the parseInt function.
 */

void parseIntTest() {
    int32_t a;
    a = Integer_parseInt(new_String("100000"));
    assertEqualsI(100000, a);
    a = Integer_parseInt(new_String("0"));
    assertEqualsI(0, a);
    a = Integer_parseInt(new_String("-100000"));
    assertEqualsI(-100000, a);
}

int main(int argc, char** argv) {
    const int testCount = 7;
    setUpTestModule("IntegerTest", testCount);

    registerTest(intValueTest, "intValueTest");
    registerTest(compareToTest, "compareToTest");
    registerTest(compareTest, "compareTest");
    registerTest(equalsTest, "equalsTest");
    registerTest(toStringTest, "toStringTest");
    registerTest(toStringTest2, "toStringTest2");
    registerTest(parseIntTest, "parseIntTest");
    
    runTests();

    return (EXIT_SUCCESS);
}
