#include <stdio.h>
#include <stdlib.h>

#include "test.h"
#include "Float.h"

/*
 * Simple C Test Suite
 */

const float DEFAULT_EPSILON = 1E-20;

/**
 * Tests the floatValue function.
 */

void floatValueTest() {
    Float *a;
    float b;
    a = new_Float(Float_MIN_VALUE);
    b = floatValue(a);
    assertEqualsF(1.4E-45f, b, DEFAULT_EPSILON);
    a = new_Float((float) 0);
    b = floatValue(a);
    assertEqualsF(0.0f, b, DEFAULT_EPSILON);
    a = new_Float(Float_MAX_VALUE);
    b = floatValue(a);
    assertEqualsF(3.4028235E38f, b, DEFAULT_EPSILON);
}

/**
 * Tests the compareTo function.
 */

void compareToTest() {
    Float *a, *b;
    int32_t c;
    a = new_Float(Float_MIN_VALUE);
    b = new_Float((float) - 1);
    c = compareToF(a, b);
    assertEqualsI(1, c);
    a = new_Float(Float_MAX_VALUE);
    b = new_Float((float) 1);
    c = compareToF(a, b);
    assertEqualsI(1, c);
    a = new_Float((float) 0);
    b = new_Float((float) 1);
    c = compareToF(a, b);
    assertEqualsI(-1, c);
    a = new_Float((float) 0);
    b = new_Float((float) - 1);
    c = compareToF(a, b);
    assertEqualsI(1, c);
    a = new_Float((float) 1);
    b = new_Float((float) 1);
    c = compareToF(a, b);
    assertEqualsI(0, c);
    a = new_Float((float) - 1);
    b = new_Float((float) - 1);
    c = compareToF(a, b);
    assertEqualsI(0, c);
}

/**
 * Tests the compare function.
 */

void compareTest() {
    float a, b;
    int32_t c;
    a = Float_MIN_VALUE;
    b = (float) - 1;
    c = Float_compare(a, b);
    assertEqualsI(1, c);
    a = Float_MAX_VALUE;
    b = (float) 1;
    c = Float_compare(a, b);
    assertEqualsI(1, c);
    a = (float) 0;
    b = (float) 1;
    c = Float_compare(a, b);
    assertEqualsI(-1, c);
    a = (float) 0;
    b = (float) - 1;
    c = Float_compare(a, b);
    assertEqualsI(1, c);
    a = (float) 1;
    b = (float) 1;
    c = Float_compare(a, b);
    assertEqualsI(0, c);
    a = (float) - 1;
    b = (float) - 1;
    c = Float_compare(a, b);
    assertEqualsI(0, c);
}

/**
 * Tests the equals function.
 */

void equalsTest() {
    Float *a, *b;
    bool c;
    a = new_Float(Float_MIN_VALUE);
    b = new_Float((float) - 1);
    c = equalsF(a, b);
    assertEqualsBool(false, c);
    a = new_Float(Float_MAX_VALUE);
    b = new_Float((float) 1);
    c = equalsF(a, b);
    assertEqualsBool(false, c);
    a = new_Float((float) 0);
    b = new_Float((float) 1);
    c = equalsF(a, b);
    assertEqualsBool(false, c);
    a = new_Float((float) 0);
    b = new_Float((float) - 1);
    c = equalsF(a, b);
    assertEqualsBool(false, c);
    a = new_Float((float) 1);
    b = new_Float((float) 1);
    c = equalsF(a, b);
    assertEqualsBool(true, c);
    a = new_Float((float) - 1);
    b = new_Float((float) - 1);
    c = equalsF(a, b);
    assertEqualsBool(true, c);
}

/**
 * Tests the toString function.
 */

void toStringTest() {
    Float *a;
    String *b;
    a = new_Float((float) 0.1);
    b = toStringF(a);
    assertEqualsStr("0.1", b->s);
    a = new_Float((float) 0);
    b = toStringF(a);
    assertEqualsStr("0.0", b->s);
    a = new_Float((float) - 0.1);
    b = toStringF(a);
    assertEqualsStr("-0.1", b->s);
}

/**
 * Tests the static toString function.
 */

void toStringTest2() {
    float a;
    String *b;
    a = (float) 0.1;
    b = Float_toString(a);
    assertEqualsStr("0.1", b->s);
    a = (float) 0;
    b = Float_toString(a);
    assertEqualsStr("0.0", b->s);
    a = (float) - 0.1;
    b = Float_toString(a);
    assertEqualsStr("-0.1", b->s);
}

/**
 * Tests the parseFloat function.
 */

void parseFloatTest() {
    float a;
    a = Float_parseFloat(new_String("0.1"));
    assertEqualsF(0.1f, a, DEFAULT_EPSILON);
    a = Float_parseFloat(new_String("0"));
    assertEqualsF(0.0f, a, DEFAULT_EPSILON);
    a = Float_parseFloat(new_String("-0.1"));
    assertEqualsF(-0.1f, a, DEFAULT_EPSILON);
}

int main(int argc, char** argv) {
    const int testCount = 7;
    setUpTestModule("FloatTest", testCount);

    registerTest(floatValueTest, "floatValueTest");
    registerTest(compareToTest, "compareToTest");
    registerTest(compareTest, "compareTest");
    registerTest(equalsTest, "equalsTest");
    registerTest(toStringTest, "toStringTest");
    registerTest(toStringTest2, "toStringTest2");
    registerTest(parseFloatTest, "parseFloatTest");
    
    runTests();

    return (EXIT_SUCCESS);
}
