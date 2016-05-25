#include <cstdlib>
#include <iostream>

#include "test.h"
#include "Short.h"

/*
 * Simple C++ Test Suite
 */

/**
 * Tests the shortValue method.
 */

void shortValueTest() {
    Short *a;
    int16_t b;
    a = new Short(Short::MIN_VALUE);
    b = a->shortValue();
    Test::assertEquals((int16_t)-32768, b);
    a = new Short((int16_t) 0);
    b = a->shortValue();
    Test::assertEquals((int16_t)0, b);
    a = new Short(Short::MAX_VALUE);
    b = a->shortValue();
    Test::assertEquals((int16_t)32767, b);
}

/**
 * Tests the compareTo method.
 */

void compareToTest() {
    Short *a, *b;
    int32_t c;
    a = new Short(Short::MIN_VALUE);
    b = new Short((int16_t) - 1);
    c = a->compareTo(b);
    Test::assertEquals(-32767, c);
    a = new Short(Short::MAX_VALUE);
    b = new Short((int16_t) 1);
    c = a->compareTo(b);
    Test::assertEquals(32766, c);
    a = new Short((int16_t) 0);
    b = new Short((int16_t) 1);
    c = a->compareTo(b);
    Test::assertEquals(-1, c);
    a = new Short((int16_t) 0);
    b = new Short((int16_t) - 1);
    c = a->compareTo(b);
    Test::assertEquals(1, c);
    a = new Short((int16_t) 1);
    b = new Short((int16_t) 1);
    c = a->compareTo(b);
    Test::assertEquals(0, c);
    a = new Short((int16_t) - 1);
    b = new Short((int16_t) - 1);
    c = a->compareTo(b);
    Test::assertEquals(0, c);
}

/**
 * Tests the compare method.
 */

void compareTest() {
    int16_t a, b;
    int32_t c;
    a = Short::MIN_VALUE;
    b = (int16_t) - 1;
    c = Short::compare(a, b);
    Test::assertEquals(-32767, c);
    a = Short::MAX_VALUE;
    b = (int16_t) 1;
    c = Short::compare(a, b);
    Test::assertEquals(32766, c);
    a = (int16_t) 0;
    b = (int16_t) 1;
    c = Short::compare(a, b);
    Test::assertEquals(-1, c);
    a = (int16_t) 0;
    b = (int16_t) - 1;
    c = Short::compare(a, b);
    Test::assertEquals(1, c);
    a = (int16_t) 1;
    b = (int16_t) 1;
    c = Short::compare(a, b);
    Test::assertEquals(0, c);
    a = (int16_t) - 1;
    b = (int16_t) - 1;
    c = Short::compare(a, b);
    Test::assertEquals(0, c);
}

/**
 * Tests the equals method.
 */

void equalsTest() {
    Short *a, *b;
    bool c;
    a = new Short(Short::MIN_VALUE);
    b = new Short((int16_t) - 1);
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Short(Short::MAX_VALUE);
    b = new Short((int16_t) 1);
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Short((int16_t) 0);
    b = new Short((int16_t) 1);
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Short((int16_t) 0);
    b = new Short((int16_t) - 1);
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Short((int16_t) 1);
    b = new Short((int16_t) 1);
    c = a->equals(b);
    Test::assertEquals(true, c);
    a = new Short((int16_t) - 1);
    b = new Short((int16_t) - 1);
    c = a->equals(b);
    Test::assertEquals(true, c);
}

/**
 * Tests the toString method.
 */

void toStringTest() {
    Short *a;
    String *b;
    a = new Short((int16_t) 1000);
    b = a->toString();
    Test::assertEquals("1000", b->_s());
    a = new Short((int16_t) 0);
    b = a->toString();
    Test::assertEquals("0", b->_s());
    a = new Short((int16_t) - 1000);
    b = a->toString();
    Test::assertEquals("-1000", b->_s());
}

/**
 * Tests the static toString method.
 */

void toStringTest2() {
    int16_t a;
    String *b;
    a = (int16_t) 1000;
    b = Short::toString(a);
    Test::assertEquals("1000", b->_s());
    a = (int16_t) 0;
    b = Short::toString(a);
    Test::assertEquals("0", b->_s());
    a = (int16_t) - 1000;
    b = Short::toString(a);
    Test::assertEquals("-1000", b->_s());
}

/**
 * Tests the parseShort method.
 */

void parseShortTest() {
    int16_t a;
    a = Short::parseShort(new String("1000"));
    Test::assertEquals((int16_t)1000, a);
    a = Short::parseShort(new String("0"));
    Test::assertEquals((int16_t)0, a);
    a = Short::parseShort(new String("-1000"));
    Test::assertEquals((int16_t)-1000, a);
}

int main(int argc, char** argv) {
    Test::setUpTestModule("ShortTest");

    Test::registerTest(shortValueTest, "shortValueTest");
    Test::registerTest(compareToTest, "compareToTest");
    Test::registerTest(compareTest, "compareTest");
    Test::registerTest(equalsTest, "equalsTest");
    Test::registerTest(toStringTest, "toStringTest");
    Test::registerTest(toStringTest2, "toStringTest2");
    Test::registerTest(parseShortTest, "parseShortTest");
    
    Test::runTests();

    return (EXIT_SUCCESS);
}