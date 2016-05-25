#include <stdio.h>
#include <stdlib.h>

#include "test.h"
#include "Long.h"

/*
 * Simple C Test Suite
 */

/**
 * Tests the longValue function.
 */

void longValueTest() {
    Long *a;
    int64_t b;
    a = new_Long(Long_MIN_VALUE);
    b = longValue(a);
    assertEqualsL(-9223372036854775808, b);
    a = new_Long((int64_t) 0);
    b = longValue(a);
    assertEqualsL((int64_t)0, b);
    a = new_Long(Long_MAX_VALUE);
    b = longValue(a);
    assertEqualsL(9223372036854775807, b);
}

/**
 * Tests the compareTo function.
 */

void compareToTest() {
    Long *a, *b;
    int32_t c;
    a = new_Long(Long_MIN_VALUE);
    b = new_Long((int64_t) - 1);
    c = compareToL(a, b);
    assertEqualsI(-1, c);
    a = new_Long(Long_MAX_VALUE);
    b = new_Long((int64_t) 1);
    c = compareToL(a, b);
    assertEqualsI(1, c);
    a = new_Long((int64_t) 0);
    b = new_Long((int64_t) 1);
    c = compareToL(a, b);
    assertEqualsI(-1, c);
    a = new_Long((int64_t) 0);
    b = new_Long((int64_t) - 1);
    c = compareToL(a, b);
    assertEqualsI(1, c);
    a = new_Long((int64_t) 1);
    b = new_Long((int64_t) 1);
    c = compareToL(a, b);
    assertEqualsI(0, c);
    a = new_Long((int64_t) - 1);
    b = new_Long((int64_t) - 1);
    c = compareToL(a, b);
    assertEqualsI(0, c);
}

/**
 * Tests the compare function.
 */

void compareTest() {
    int64_t a, b;
    int32_t c;
    a = Long_MIN_VALUE;
    b = (int64_t) - 1;
    c = Long_compare(a, b);
    assertEqualsI(-1, c);
    a = Long_MAX_VALUE;
    b = (int64_t) 1;
    c = Long_compare(a, b);
    assertEqualsI(1, c);
    a = (int64_t) 0;
    b = (int64_t) 1;
    c = Long_compare(a, b);
    assertEqualsI(-1, c);
    a = (int64_t) 0;
    b = (int64_t) - 1;
    c = Long_compare(a, b);
    assertEqualsI(1, c);
    a = (int64_t) 1;
    b = (int64_t) 1;
    c = Long_compare(a, b);
    assertEqualsI(0, c);
    a = (int64_t) - 1;
    b = (int64_t) - 1;
    c = Long_compare(a, b);
    assertEqualsI(0, c);
}

/**
 * Tests the equals function.
 */

void equalsTest() {
    Long *a, *b;
    bool c;
    a = new_Long(Long_MIN_VALUE);
    b = new_Long((int64_t) - 1);
    c = equalsL(a, b);
    assertEqualsBool(false, c);
    a = new_Long(Long_MAX_VALUE);
    b = new_Long((int64_t) 1);
    c = equalsL(a, b);
    assertEqualsBool(false, c);
    a = new_Long((int64_t) 0);
    b = new_Long((int64_t) 1);
    c = equalsL(a, b);
    assertEqualsBool(false, c);
    a = new_Long((int64_t) 0);
    b = new_Long((int64_t) - 1);
    c = equalsL(a, b);
    assertEqualsBool(false, c);
    a = new_Long((int64_t) 1);
    b = new_Long((int64_t) 1);
    c = equalsL(a, b);
    assertEqualsBool(true, c);
    a = new_Long((int64_t) - 1);
    b = new_Long((int64_t) - 1);
    c = equalsL(a, b);
    assertEqualsBool(true, c);
}

/**
 * Tests the toString function.
 */

void toStringTest() {
    Long *a;
    String *b;
    a = new_Long((int64_t) 10000000000L);
    b = toStringL(a);
    assertEqualsStr("10000000000", b->s);
    a = new_Long((int64_t) 0);
    b = toStringL(a);
    assertEqualsStr("0", b->s);
    a = new_Long((int64_t) - 10000000000L);
    b = toStringL(a);
    assertEqualsStr("-10000000000", b->s);
}

/**
 * Tests the static toString function.
 */

void toStringTest2() {
    int64_t a;
    String *b;
    a = (int64_t) 10000000000L;
    b = Long_toString(a);
    assertEqualsStr("10000000000", b->s);
    a = (int64_t) 0;
    b = Long_toString(a);
    assertEqualsStr("0", b->s);
    a = (int64_t) - 10000000000L;
    b = Long_toString(a);
    assertEqualsStr("-10000000000", b->s);
}

/**
 * Tests the parseLong function.
 */

void parseLongTest() {
    int64_t a;
    a = Long_parseLong(new_String("10000000000"));
    assertEqualsL(10000000000, a);
    a = Long_parseLong(new_String("0"));
    assertEqualsL((int64_t)0, a);
    a = Long_parseLong(new_String("-10000000000"));
    assertEqualsL(-10000000000, a);
}

int main(int argc, char** argv) {
    const int testCount = 7;
    setUpTestModule("LongTest", testCount);

    registerTest(longValueTest, "longValueTest");
    registerTest(compareToTest, "compareToTest");
    registerTest(compareTest, "compareTest");
    registerTest(equalsTest, "equalsTest");
    registerTest(toStringTest, "toStringTest");
    registerTest(toStringTest2, "toStringTest2");
    registerTest(parseLongTest, "parseLongTest");
    
    runTests();

    return (EXIT_SUCCESS);
}
