#include <cstdlib>
#include <iostream>

#include "test.h"
#include "Double.h"

/*
 * Simple C++ Test Suite
 */

const double DEFAULT_EPSILON = 1E-10;

/**
 * Tests the doubleValue method.
 */

void doubleValueTest() {
    Double *a;
    double b;
    // minimal non-zero absolute value
    a = new Double(Double::MIN_VALUE);
    b = a->doubleValue();
    Test::assertEquals(4.9E-324, b, DEFAULT_EPSILON);
    // zero value
    a = new Double((double) 0);
    b = a->doubleValue();
    Test::assertEquals(0.0, b, DEFAULT_EPSILON);
    // maximal finite absolute value
    a = new Double(Double::MAX_VALUE);
    b = a->doubleValue();
    Test::assertEquals(1.7976931348623157E308, b, DEFAULT_EPSILON);
}

/**
 * Tests the compareTo method.
 */

void compareToTest() {
    Double *a, *b;
    int32_t c;
    // minimal non-zero absolute value and bigger fractional value
    a = new Double(Double::MIN_VALUE);
    b = new Double((double) 0.1);
    c = a->compareTo(b);
    Test::assertEquals(-1, c);
    // maximal finite absolute value and smaller integer value
    a = new Double(Double::MAX_VALUE);
    b = new Double((double) 1);
    c = a->compareTo(b);
    Test::assertEquals(1, c);
    // zero and positive value
    a = new Double((double) 0);
    b = new Double((double) 1);
    c = a->compareTo(b);
    Test::assertEquals(-1, c);
    // zero and negative value
    a = new Double((double) 0);
    b = new Double((double) - 1);
    c = a->compareTo(b);
    Test::assertEquals(1, c);
    // both values are positive
    a = new Double((double) 1);
    b = new Double((double) 1);
    c = a->compareTo(b);
    Test::assertEquals(0, c);
    // both values are negative
    a = new Double((double) - 1);
    b = new Double((double) - 1);
    c = a->compareTo(b);
    Test::assertEquals(0, c);
}

/**
 * Tests the compare method.
 */

void compareTest() {
    double a, b;
    int32_t c;
    a = Double::MIN_VALUE;
    b = (double) 0.1;
    c = Double::compare(a, b);
    Test::assertEquals(-1, c);
    a = Double::MAX_VALUE;
    b = (double) 1;
    c = Double::compare(a, b);
    Test::assertEquals(1, c);
    a = (double) 0;
    b = (double) 1;
    c = Double::compare(a, b);
    Test::assertEquals(-1, c);
    a = (double) 0;
    b = (double) - 1;
    c = Double::compare(a, b);
    Test::assertEquals(1, c);
    a = (double) 1;
    b = (double) 1;
    c = Double::compare(a, b);
    Test::assertEquals(0, c);
    a = (double) - 1;
    b = (double) - 1;
    c = Double::compare(a, b);
    Test::assertEquals(0, c);
}

/**
 * Tests the equals method.
 */

void equalsTest() {
    Double *a, *b;
    bool c;
    a = new Double(Double::MIN_VALUE);
    b = new Double((double) - 1);
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Double(Double::MAX_VALUE);
    b = new Double((double) 1);
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Double((double) 0);
    b = new Double((double) 1);
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Double((double) 0);
    b = new Double((double) - 1);
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Double((double) 1);
    b = new Double((double) 1);
    c = a->equals(b);
    Test::assertEquals(true, c);
    a = new Double((double) - 1);
    b = new Double((double) - 1);
    c = a->equals(b);
    Test::assertEquals(true, c);
}

/**
 * Tests the toString method.
 */

void toStringTest() {
    Double *a;
    String *b;
    // positive value text representation
    a = new Double((double) 0.0000000000000000000000000000000000000000000001);
    b = a->toString();
    Test::assertEquals("1.0E-46", b->_s());
    // zero value text representation
    a = new Double((double) 0);
    b = a->toString();
    Test::assertEquals("0.0", b->_s());
    // negative value text representation
    a = new Double((double) - 0.0000000000000000000000000000000000000000000001);
    b = a->toString();
    Test::assertEquals("-1.0E-46", b->_s());
}

/**
 * Tests the static toString method.
 */

void toStringTest2() {
    double a;
    String *b;
    a = (double) 0.0000000000000000000000000000000000000000000001;
    b = Double::toString(a);
    Test::assertEquals("1.0E-46", b->_s());
    a = (double) 0;
    b = Double::toString(a);
    Test::assertEquals("0.0", b->_s());
    a = (double) - 0.0000000000000000000000000000000000000000000001;
    b = Double::toString(a);
    Test::assertEquals("-1.0E-46", b->_s());
}

/**
 * Tests the parseDouble method.
 */

void parseDoubleTest() {
    double a;
    // positive value parsing
    a = Double::parseDouble(new String("0.0000000000000000000000000000000000000000000001"));
    Test::assertEquals(1.0E-46, a, DEFAULT_EPSILON);
    // zero value parsing
    a = Double::parseDouble(new String("0"));
    Test::assertEquals(0.0, a, DEFAULT_EPSILON);
    // negative value parsing
    a = Double::parseDouble(new String("-0.0000000000000000000000000000000000000000000001"));
    Test::assertEquals(-1.0E-46, a, DEFAULT_EPSILON);
}

int main(int argc, char** argv) {
    Test::setUpTestModule("DoubleTest");

    Test::registerTest(doubleValueTest, "doubleValueTest");
    Test::registerTest(compareToTest, "compareToTest");
    Test::registerTest(compareTest, "compareTest");
    Test::registerTest(equalsTest, "equalsTest");
    Test::registerTest(toStringTest, "toStringTest");
    Test::registerTest(toStringTest2, "toStringTest2");
    Test::registerTest(parseDoubleTest, "parseDoubleTest");
    
    Test::runTests();

    return (EXIT_SUCCESS);
}