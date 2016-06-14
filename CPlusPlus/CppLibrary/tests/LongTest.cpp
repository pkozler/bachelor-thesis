#include <cstdlib>
#include <iostream>

#include "test.h"
#include "Long.h"

/*
 * Simple C++ Test Suite
 */

/**
 * Tests the longValue method.
 */

void longValueTest() {
    Long *a;
    int64_t b;
    a = new Long(Long::MIN_VALUE);
    b = a->longValue();
    Test::assertEquals(-9223372036854775808, b);
    a = new Long((int64_t) 0);
    b = a->longValue();
    Test::assertEquals((int64_t)0, b);
    a = new Long(Long::MAX_VALUE);
    b = a->longValue();
    Test::assertEquals(9223372036854775807, b);
}

/**
 * Tests the compareTo method.
 */

void compareToTest() {
    Long *a, *b;
    int32_t c;
    a = new Long(Long::MIN_VALUE);
    b = new Long((int64_t) - 1);
    c = a->compareTo(b);
    Test::assertEquals(-1, c);
    a = new Long(Long::MAX_VALUE);
    b = new Long((int64_t) 1);
    c = a->compareTo(b);
    Test::assertEquals(1, c);
    a = new Long((int64_t) 0);
    b = new Long((int64_t) 1);
    c = a->compareTo(b);
    Test::assertEquals(-1, c);
    a = new Long((int64_t) 0);
    b = new Long((int64_t) - 1);
    c = a->compareTo(b);
    Test::assertEquals(1, c);
    a = new Long((int64_t) 1);
    b = new Long((int64_t) 1);
    c = a->compareTo(b);
    Test::assertEquals(0, c);
    a = new Long((int64_t) - 1);
    b = new Long((int64_t) - 1);
    c = a->compareTo(b);
    Test::assertEquals(0, c);
}

/**
 * Tests the compare method.
 */

void compareTest() {
    int64_t a, b;
    int32_t c;
    a = Long::MIN_VALUE;
    b = (int64_t) - 1;
    c = Long::compare(a, b);
    Test::assertEquals(-1, c);
    a = Long::MAX_VALUE;
    b = (int64_t) 1;
    c = Long::compare(a, b);
    Test::assertEquals(1, c);
    a = (int64_t) 0;
    b = (int64_t) 1;
    c = Long::compare(a, b);
    Test::assertEquals(-1, c);
    a = (int64_t) 0;
    b = (int64_t) - 1;
    c = Long::compare(a, b);
    Test::assertEquals(1, c);
    a = (int64_t) 1;
    b = (int64_t) 1;
    c = Long::compare(a, b);
    Test::assertEquals(0, c);
    a = (int64_t) - 1;
    b = (int64_t) - 1;
    c = Long::compare(a, b);
    Test::assertEquals(0, c);
}

/**
 * Tests the equals method.
 */

void equalsTest() {
    Long *a, *b;
    bool c;
    a = new Long(Long::MIN_VALUE);
    b = new Long((int64_t) - 1);
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Long(Long::MAX_VALUE);
    b = new Long((int64_t) 1);
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Long((int64_t) 0);
    b = new Long((int64_t) 1);
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Long((int64_t) 0);
    b = new Long((int64_t) - 1);
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Long((int64_t) 1);
    b = new Long((int64_t) 1);
    c = a->equals(b);
    Test::assertEquals(true, c);
    a = new Long((int64_t) - 1);
    b = new Long((int64_t) - 1);
    c = a->equals(b);
    Test::assertEquals(true, c);
}

/**
 * Tests the toString method.
 */

void toStringTest() {
    Long *a;
    String *b;
    a = new Long((int64_t) 10000000000LL);
    b = a->toString();
    Test::assertEquals("10000000000", b->_s());
    a = new Long((int64_t) 0);
    b = a->toString();
    Test::assertEquals("0", b->_s());
    a = new Long((int64_t) - 10000000000LL);
    b = a->toString();
    Test::assertEquals("-10000000000", b->_s());
}

/**
 * Tests the static toString method.
 */

void toStringTest2() {
    int64_t a;
    String *b;
    a = (int64_t) 10000000000LL;
    b = Long::toString(a);
    Test::assertEquals("10000000000", b->_s());
    a = (int64_t) 0;
    b = Long::toString(a);
    Test::assertEquals("0", b->_s());
    a = (int64_t) - 10000000000LL;
    b = Long::toString(a);
    Test::assertEquals("-10000000000", b->_s());
}

/**
 * Tests the parseLong method.
 */

void parseLongTest() {
    int64_t a;
    a = Long::parseLong(new String("10000000000"));
    Test::assertEquals(10000000000LL, a);
    a = Long::parseLong(new String("0"));
    Test::assertEquals((int64_t)0LL, a);
    a = Long::parseLong(new String("-10000000000"));
    Test::assertEquals(-10000000000LL, a);
}

int main(int argc, char** argv) {
    Test::setUpTestModule("LongTest");

    Test::registerTest(longValueTest, "longValueTest");
    Test::registerTest(compareToTest, "compareToTest");
    Test::registerTest(compareTest, "compareTest");
    Test::registerTest(equalsTest, "equalsTest");
    Test::registerTest(toStringTest, "toStringTest");
    Test::registerTest(toStringTest2, "toStringTest2");
    Test::registerTest(parseLongTest, "parseLongTest");
    
    Test::runTests();

    return (EXIT_SUCCESS);
}