#include <cstdlib>
#include <iostream>

#include "test.h"
#include "Boolean.h"

/*
 * Simple C++ Test Suite
 */

/**
 * Tests the booleanValue method.
 */

void booleanValueTest() {
    Boolean *a;
    bool b;
    // true value
    a = new Boolean(true);
    b = a->booleanValue();
    Test::assertEquals(true, b);
    // false falue
    a = new Boolean(false);
    b = a->booleanValue();
    Test::assertEquals(false, b);
}

/**
 * Tests the compareTo method.
 */

void compareToTest() {
    Boolean *a, *b;
    int32_t c;
    // true and false
    a = new Boolean(true);
    b = new Boolean(false);
    c = a->compareTo(b);
    Test::assertEquals(1, c);
    // false and true
    a = new Boolean(false);
    b = new Boolean(true);
    c = a->compareTo(b);
    Test::assertEquals(-1, c);
    // both values are true
    a = new Boolean(true);
    b = new Boolean(true);
    c = a->compareTo(b);
    Test::assertEquals(0, c);
    // both values are false
    a = new Boolean(false);
    b = new Boolean(false);
    c = a->compareTo(b);
    Test::assertEquals(0, c);
}

/**
 * Tests the compare method.
 */

void compareTest() {
    bool a, b;
    int32_t c;
    a = true;
    b = false;
    c = Boolean::compare(a, b);
    Test::assertEquals(1, c);
    a = false;
    b = true;
    c = Boolean::compare(a, b);
    Test::assertEquals(-1, c);
    a = true;
    b = true;
    c = Boolean::compare(a, b);
    Test::assertEquals(0, c);
    a = false;
    b = false;
    c = Boolean::compare(a, b);
    Test::assertEquals(0, c);
}

/**
 * Tests the equals method.
 */

void equalsTest() {
    Boolean *a, *b;
    bool c;
    a = new Boolean(true);
    b = new Boolean(false);
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Boolean(false);
    b = new Boolean(true);
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Boolean(true);
    b = new Boolean(true);
    c = a->equals(b);
    Test::assertEquals(true, c);
    a = new Boolean(false);
    b = new Boolean(false);
    c = a->equals(b);
    Test::assertEquals(true, c);
}

/**
 * Tests the toString method.
 */

void toStringTest() {
    Boolean *a;
    String *b;
    // true value text representation
    a = new Boolean(true);
    b = a->toString();
    Test::assertEquals("true", b->_s());
    // false value text representation
    a = new Boolean(false);
    b = a->toString();
    Test::assertEquals("false", b->_s());
}

/**
 * Tests the static toString method.
 */

void toStringTest2() {
    bool a;
    String *b;
    a = true;
    b = Boolean::toString(a);
    Test::assertEquals("true", b->_s());
    a = false;
    b = Boolean::toString(a);
    Test::assertEquals("false", b->_s());
}

/**
 * Tests the parseBoolean method.
 */

void parseBooleanTest() {
    bool a;
    // true value parsing
    a = Boolean::parseBoolean(new String("true"));
    Test::assertEquals(true, a);
    // false value parsing
    a = Boolean::parseBoolean(new String("false"));
    Test::assertEquals(false, a);
}

int main(int argc, char** argv) {
    Test::setUpTestModule("BooleanTest");

    Test::registerTest(booleanValueTest, "booleanValueTest");
    Test::registerTest(compareToTest, "compareToTest");
    Test::registerTest(compareTest, "compareTest");
    Test::registerTest(equalsTest, "equalsTest");
    Test::registerTest(toStringTest, "toStringTest");
    Test::registerTest(toStringTest2, "toStringTest2");
    Test::registerTest(parseBooleanTest, "parseBooleanTest");
    
    Test::runTests();

    return (EXIT_SUCCESS);
}