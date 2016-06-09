#include <stdio.h>
#include <stdlib.h>

#include "test.h"
#include "Double.h"

/*
 * Simple C Test Suite
 */

const double DEFAULT_EPSILON = 1E-20;

/**
 * Tests the doubleValue function.
 */

void doubleValueTest() {
    Double *a;
    double b;
    // minimal non-zero absolute value
    a = new_Double(Double_MIN_VALUE);
    b = doubleValue(a);
    assertEqualsD(4.9E-324, b, DEFAULT_EPSILON);
    // zero value
    a = new_Double((double) 0);
    b = doubleValue(a);
    assertEqualsD(0.0, b, DEFAULT_EPSILON);
    // maximal finite absolute value
    a = new_Double(Double_MAX_VALUE);
    b = doubleValue(a);
    assertEqualsD(1.7976931348623157E308, b, DEFAULT_EPSILON);
}

/**
 * Tests the compareTo function.
 */

void compareToTest() {
    Double *a, *b;
    int32_t c;
    // minimal non-zero absolute value and bigger fractional value
    a = new_Double(Double_MIN_VALUE);
    b = new_Double((double) 0.1);
    c = compareToD(a, b);
    assertEqualsI(-1, c);
    // maximal finite absolute value and smaller integer value
    a = new_Double(Double_MAX_VALUE);
    b = new_Double((double) 1);
    c = compareToD(a, b);
    assertEqualsI(1, c);
    // zero and positive value
    a = new_Double((double) 0);
    b = new_Double((double) 1);
    c = compareToD(a, b);
    assertEqualsI(-1, c);
    // zero and negative value
    a = new_Double((double) 0);
    b = new_Double((double) - 1);
    c = compareToD(a, b);
    assertEqualsI(1, c);
    // both values are positive
    a = new_Double((double) 1);
    b = new_Double((double) 1);
    c = compareToD(a, b);
    assertEqualsI(0, c);
    // both values are negative
    a = new_Double((double) - 1);
    b = new_Double((double) - 1);
    c = compareToD(a, b);
    assertEqualsI(0, c);
}

/**
 * Tests the compare function.
 */

void compareTest() {
    double a, b;
    int32_t c;
    a = Double_MIN_VALUE;
    b = (double) 0.1;
    c = Double_compare(a, b);
    assertEqualsI(-1, c);
    a = Double_MAX_VALUE;
    b = (double) 1;
    c = Double_compare(a, b);
    assertEqualsI(1, c);
    a = (double) 0;
    b = (double) 1;
    c = Double_compare(a, b);
    assertEqualsI(-1, c);
    a = (double) 0;
    b = (double) - 1;
    c = Double_compare(a, b);
    assertEqualsI(1, c);
    a = (double) 1;
    b = (double) 1;
    c = Double_compare(a, b);
    assertEqualsI(0, c);
    a = (double) - 1;
    b = (double) - 1;
    c = Double_compare(a, b);
    assertEqualsI(0, c);
}

/**
 * Tests the equals function.
 */

void equalsTest() {
    Double *a, *b;
    bool c;
    a = new_Double(Double_MIN_VALUE);
    b = new_Double((double) - 1);
    c = equalsD(a, b);
    assertEqualsBool(false, c);
    a = new_Double(Double_MAX_VALUE);
    b = new_Double((double) 1);
    c = equalsD(a, b);
    assertEqualsBool(false, c);
    a = new_Double((double) 0);
    b = new_Double((double) 1);
    c = equalsD(a, b);
    assertEqualsBool(false, c);
    a = new_Double((double) 0);
    b = new_Double((double) - 1);
    c = equalsD(a, b);
    assertEqualsBool(false, c);
    a = new_Double((double) 1);
    b = new_Double((double) 1);
    c = equalsD(a, b);
    assertEqualsBool(true, c);
    a = new_Double((double) - 1);
    b = new_Double((double) - 1);
    c = equalsD(a, b);
    assertEqualsBool(true, c);
}

/**
 * Tests the toString function.
 */

void toStringTest() {
    Double *a;
    String *b;
    // positive value text representation
    a = new_Double((double) 0.0000000000000000000000000000000000000000000001);
    b = toStringD(a);
    assertEqualsStr("1.0E-46", b->s);
    // zero value text representation
    a = new_Double((double) 0);
    b = toStringD(a);
    assertEqualsStr("0.0", b->s);
    // negative value text representation
    a = new_Double((double) - 0.0000000000000000000000000000000000000000000001);
    b = toStringD(a);
    assertEqualsStr("-1.0E-46", b->s);
}

/**
 * Tests the static toString function.
 */

void toStringTest2() {
    double a;
    String *b;
    a = (double) 0.0000000000000000000000000000000000000000000001;
    b = Double_toString(a);
    assertEqualsStr("1.0E-46", b->s);
    a = (double) 0;
    b = Double_toString(a);
    assertEqualsStr("0.0", b->s);
    a = (double) - 0.0000000000000000000000000000000000000000000001;
    b = Double_toString(a);
    assertEqualsStr("-1.0E-46", b->s);
}

/**
 * Tests the parseDouble function.
 */

void parseDoubleTest() {
    double a;
    // positive value parsing
    a = Double_parseDouble(new_String("0.0000000000000000000000000000000000000000000001"));
    assertEqualsD(1.0E-46, a, DEFAULT_EPSILON);
    // zero value parsing
    a = Double_parseDouble(new_String("0"));
    assertEqualsD(0.0, a, DEFAULT_EPSILON);
    // negative value parsing
    a = Double_parseDouble(new_String("-0.0000000000000000000000000000000000000000000001"));
    assertEqualsD(-1.0E-46, a, DEFAULT_EPSILON);
}

int main(int argc, char** argv) {
    const int testCount = 7;
    setUpTestModule("DoubleTest", testCount);

    registerTest(doubleValueTest, "doubleValueTest");
    registerTest(compareToTest, "compareToTest");
    registerTest(compareTest, "compareTest");
    registerTest(equalsTest, "equalsTest");
    registerTest(toStringTest, "toStringTest");
    registerTest(toStringTest2, "toStringTest2");
    registerTest(parseDoubleTest, "parseDoubleTest");
    
    runTests();

    return (EXIT_SUCCESS);
}
