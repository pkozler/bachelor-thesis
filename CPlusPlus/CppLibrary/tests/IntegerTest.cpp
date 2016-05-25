#include <cstdlib>
#include <iostream>

#include "test.h"
#include "Integer.h"

/*
 * Simple C++ Test Suite
 */

/**
 * Tests the intValue method.
 */

void intValueTest() {
    Integer *a;
    int32_t b;
    a = new Integer(Integer::MIN_VALUE);
    b = a->intValue();
    Test::assertEquals((int32_t)-2147483648, b);
    a = new Integer((int32_t) 0);
    b = a->intValue();
    Test::assertEquals(0, b);
    a = new Integer(Integer::MAX_VALUE);
    b = a->intValue();
    Test::assertEquals(2147483647, b);
}

/**
 * Tests the compareTo method.
 */

void compareToTest() {
    Integer *a, *b;
    int32_t c;
    a = new Integer(Integer::MIN_VALUE);
    b = new Integer((int32_t) - 1);
    c = a->compareTo(b);
    Test::assertEquals(-1, c);
    a = new Integer(Integer::MAX_VALUE);
    b = new Integer((int32_t) 1);
    c = a->compareTo(b);
    Test::assertEquals(1, c);
    a = new Integer((int32_t) 0);
    b = new Integer((int32_t) 1);
    c = a->compareTo(b);
    Test::assertEquals(-1, c);
    a = new Integer((int32_t) 0);
    b = new Integer((int32_t) - 1);
    c = a->compareTo(b);
    Test::assertEquals(1, c);
    a = new Integer((int32_t) 1);
    b = new Integer((int32_t) 1);
    c = a->compareTo(b);
    Test::assertEquals(0, c);
    a = new Integer((int32_t) - 1);
    b = new Integer((int32_t) - 1);
    c = a->compareTo(b);
    Test::assertEquals(0, c);
}

/**
 * Tests the compare method.
 */

void compareTest() {
    int32_t a, b;
    int32_t c;
    a = Integer::MIN_VALUE;
    b = (int32_t) - 1;
    c = Integer::compare(a, b);
    Test::assertEquals(-1, c);
    a = Integer::MAX_VALUE;
    b = (int32_t) 1;
    c = Integer::compare(a, b);
    Test::assertEquals(1, c);
    a = (int32_t) 0;
    b = (int32_t) 1;
    c = Integer::compare(a, b);
    Test::assertEquals(-1, c);
    a = (int32_t) 0;
    b = (int32_t) - 1;
    c = Integer::compare(a, b);
    Test::assertEquals(1, c);
    a = (int32_t) 1;
    b = (int32_t) 1;
    c = Integer::compare(a, b);
    Test::assertEquals(0, c);
    a = (int32_t) - 1;
    b = (int32_t) - 1;
    c = Integer::compare(a, b);
    Test::assertEquals(0, c);
}

/**
 * Tests the equals method.
 */

void equalsTest() {
    Integer *a, *b;
    bool c;
    a = new Integer(Integer::MIN_VALUE);
    b = new Integer((int32_t) - 1);
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Integer(Integer::MAX_VALUE);
    b = new Integer((int32_t) 1);
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Integer((int32_t) 0);
    b = new Integer((int32_t) 1);
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Integer((int32_t) 0);
    b = new Integer((int32_t) - 1);
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Integer((int32_t) 1);
    b = new Integer((int32_t) 1);
    c = a->equals(b);
    Test::assertEquals(true, c);
    a = new Integer((int32_t) - 1);
    b = new Integer((int32_t) - 1);
    c = a->equals(b);
    Test::assertEquals(true, c);
}

/**
 * Tests the toString method.
 */

void toStringTest() {
    Integer *a;
    String *b;
    a = new Integer((int32_t) 100000);
    b = a->toString();
    Test::assertEquals("100000", b->_s());
    a = new Integer((int32_t) 0);
    b = a->toString();
    Test::assertEquals("0", b->_s());
    a = new Integer((int32_t) - 100000);
    b = a->toString();
    Test::assertEquals("-100000", b->_s());
}

/**
 * Tests the static toString method.
 */

void toStringTest2() {
    int32_t a;
    String *b;
    a = (int32_t) 100000;
    b = Integer::toString(a);
    Test::assertEquals("100000", b->_s());
    a = (int32_t) 0;
    b = Integer::toString(a);
    Test::assertEquals("0", b->_s());
    a = (int32_t) - 100000;
    b = Integer::toString(a);
    Test::assertEquals("-100000", b->_s());
}

/**
 * Tests the parseInt method.
 */

void parseIntTest() {
    int32_t a;
    a = Integer::parseInt(new String("100000"));
    Test::assertEquals(100000, a);
    a = Integer::parseInt(new String("0"));
    Test::assertEquals(0, a);
    a = Integer::parseInt(new String("-100000"));
    Test::assertEquals(-100000, a);
}

int main(int argc, char** argv) {
    Test::setUpTestModule("IntegerTest");

    Test::registerTest(intValueTest, "intValueTest");
    Test::registerTest(compareToTest, "compareToTest");
    Test::registerTest(compareTest, "compareTest");
    Test::registerTest(equalsTest, "equalsTest");
    Test::registerTest(toStringTest, "toStringTest");
    Test::registerTest(toStringTest2, "toStringTest2");
    Test::registerTest(parseIntTest, "parseIntTest");
    
    Test::runTests();

    return (EXIT_SUCCESS);
}