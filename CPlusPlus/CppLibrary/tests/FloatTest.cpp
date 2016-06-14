#include <cstdlib>
#include <iostream>

#include "test.h"
#include "Float.h"

/*
 * Simple C++ Test Suite
 */

const float DEFAULT_EPSILON = 1E-10;

/**
 * Tests the floatValue method.
 */

void floatValueTest() {
    Float *a;
    float b;
    a = new Float(Float::MIN_VALUE);
    b = a->floatValue();
    Test::assertEquals(1.4E-45f, b, DEFAULT_EPSILON);
    a = new Float((float) 0);
    b = a->floatValue();
    Test::assertEquals(0.0f, b, DEFAULT_EPSILON);
    a = new Float(Float::MAX_VALUE);
    b = a->floatValue();
    Test::assertEquals(3.4028235E38f, b, DEFAULT_EPSILON);
}

/**
 * Tests the compareTo method.
 */

void compareToTest() {
    Float *a, *b;
    int32_t c;
    a = new Float(Float::MIN_VALUE);
    b = new Float((float) - 1);
    c = a->compareTo(b);
    Test::assertEquals(1, c);
    a = new Float(Float::MAX_VALUE);
    b = new Float((float) 1);
    c = a->compareTo(b);
    Test::assertEquals(1, c);
    a = new Float((float) 0);
    b = new Float((float) 1);
    c = a->compareTo(b);
    Test::assertEquals(-1, c);
    a = new Float((float) 0);
    b = new Float((float) - 1);
    c = a->compareTo(b);
    Test::assertEquals(1, c);
    a = new Float((float) 1);
    b = new Float((float) 1);
    c = a->compareTo(b);
    Test::assertEquals(0, c);
    a = new Float((float) - 1);
    b = new Float((float) - 1);
    c = a->compareTo(b);
    Test::assertEquals(0, c);
}

/**
 * Tests the compare method.
 */

void compareTest() {
    float a, b;
    int32_t c;
    a = Float::MIN_VALUE;
    b = (float) - 1;
    c = Float::compare(a, b);
    Test::assertEquals(1, c);
    a = Float::MAX_VALUE;
    b = (float) 1;
    c = Float::compare(a, b);
    Test::assertEquals(1, c);
    a = (float) 0;
    b = (float) 1;
    c = Float::compare(a, b);
    Test::assertEquals(-1, c);
    a = (float) 0;
    b = (float) - 1;
    c = Float::compare(a, b);
    Test::assertEquals(1, c);
    a = (float) 1;
    b = (float) 1;
    c = Float::compare(a, b);
    Test::assertEquals(0, c);
    a = (float) - 1;
    b = (float) - 1;
    c = Float::compare(a, b);
    Test::assertEquals(0, c);
}

/**
 * Tests the equals method.
 */

void equalsTest() {
    Float *a, *b;
    bool c;
    a = new Float(Float::MIN_VALUE);
    b = new Float((float) - 1);
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Float(Float::MAX_VALUE);
    b = new Float((float) 1);
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Float((float) 0);
    b = new Float((float) 1);
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Float((float) 0);
    b = new Float((float) - 1);
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Float((float) 1);
    b = new Float((float) 1);
    c = a->equals(b);
    Test::assertEquals(true, c);
    a = new Float((float) - 1);
    b = new Float((float) - 1);
    c = a->equals(b);
    Test::assertEquals(true, c);
}

/**
 * Tests the toString method.
 */

void toStringTest() {
    Float *a;
    String *b;
    a = new Float((float) 0.1);
    b = a->toString();
    Test::assertEquals("0.1", b->_s());
    a = new Float((float) 0);
    b = a->toString();
    Test::assertEquals("0.0", b->_s());
    a = new Float((float) - 0.1);
    b = a->toString();
    Test::assertEquals("-0.1", b->_s());
}

/**
 * Tests the static toString method.
 */

void toStringTest2() {
    float a;
    String *b;
    a = (float) 0.1;
    b = Float::toString(a);
    Test::assertEquals("0.1", b->_s());
    a = (float) 0;
    b = Float::toString(a);
    Test::assertEquals("0.0", b->_s());
    a = (float) - 0.1;
    b = Float::toString(a);
    Test::assertEquals("-0.1", b->_s());
}

/**
 * Tests the parseFloat method.
 */

void parseFloatTest() {
    float a;
    a = Float::parseFloat(new String("0.1"));
    Test::assertEquals(0.1f, a, DEFAULT_EPSILON);
    a = Float::parseFloat(new String("0"));
    Test::assertEquals(0.0f, a, DEFAULT_EPSILON);
    a = Float::parseFloat(new String("-0.1"));
    Test::assertEquals(-0.1f, a, DEFAULT_EPSILON);
}

int main(int argc, char** argv) {
    Test::setUpTestModule("FloatTest");

    Test::registerTest(floatValueTest, "floatValueTest");
    Test::registerTest(compareToTest, "compareToTest");
    Test::registerTest(compareTest, "compareTest");
    Test::registerTest(equalsTest, "equalsTest");
    Test::registerTest(toStringTest, "toStringTest");
    Test::registerTest(toStringTest2, "toStringTest2");
    Test::registerTest(parseFloatTest, "parseFloatTest");
    
    Test::runTests();

    return (EXIT_SUCCESS);
}