#include <cstdlib>
#include <iostream>

#include "test.h"
#include "Byte.h"

/**
 * A Byte class test suite.
 *
 * @author Petr Kozler (A13B0359P)
 */

/**
 * Tests the byteValue method.
 */

void byteValueTest() {
    Byte *a;
    int8_t b;
    // minimal value
    a = new Byte(Byte::MIN_VALUE);
    b = a->byteValue();
    Test::assertEquals((int8_t)-128, b);
    // zero value
    a = new Byte((int8_t) 0);
    b = a->byteValue();
    Test::assertEquals((int8_t)0, b);
    // maximal value
    a = new Byte(Byte::MAX_VALUE);
    b = a->byteValue();
    Test::assertEquals((int8_t)127, b);
}

/**
 * Tests the compareTo method.
 */

void compareToTest() {
    Byte *a, *b;
    int32_t c;
    // minimal and bigger negative value
    a = new Byte(Byte::MIN_VALUE);
    b = new Byte((int8_t) - 1);
    c = a->compareTo(b);
    Test::assertEquals(-127, c);
    // maximal and smaller positive value
    a = new Byte(Byte::MAX_VALUE);
    b = new Byte((int8_t) 1);
    c = a->compareTo(b);
    Test::assertEquals(126, c);
    // zero and positive value
    a = new Byte((int8_t) 0);
    b = new Byte((int8_t) 1);
    c = a->compareTo(b);
    Test::assertEquals(-1, c);
    // zero and negative value
    a = new Byte((int8_t) 0);
    b = new Byte((int8_t) - 1);
    c = a->compareTo(b);
    Test::assertEquals(1, c);
    // both values are positive
    a = new Byte((int8_t) 1);
    b = new Byte((int8_t) 1);
    c = a->compareTo(b);
    Test::assertEquals(0, c);
    // both values are negative
    a = new Byte((int8_t) - 1);
    b = new Byte((int8_t) - 1);
    c = a->compareTo(b);
    Test::assertEquals(0, c);
}

/**
 * Tests the compare method.
 */

void compareTest() {
    int8_t a, b;
    int32_t c;
    a = Byte::MIN_VALUE;
    b = (int8_t) - 1;
    c = Byte::compare(a, b);
    Test::assertEquals(-127, c);
    a = Byte::MAX_VALUE;
    b = (int8_t) 1;
    c = Byte::compare(a, b);
    Test::assertEquals(126, c);
    a = (int8_t) 0;
    b = (int8_t) 1;
    c = Byte::compare(a, b);
    Test::assertEquals(-1, c);
    a = (int8_t) 0;
    b = (int8_t) - 1;
    c = Byte::compare(a, b);
    Test::assertEquals(1, c);
    a = (int8_t) 1;
    b = (int8_t) 1;
    c = Byte::compare(a, b);
    Test::assertEquals(0, c);
    a = (int8_t) - 1;
    b = (int8_t) - 1;
    c = Byte::compare(a, b);
    Test::assertEquals(0, c);
}

/**
 * Tests the equals method.
 */

void equalsTest() {
    Byte *a, *b;
    bool c;
    a = new Byte(Byte::MIN_VALUE);
    b = new Byte((int8_t) - 1);
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Byte(Byte::MAX_VALUE);
    b = new Byte((int8_t) 1);
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Byte((int8_t) 0);
    b = new Byte((int8_t) 1);
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Byte((int8_t) 0);
    b = new Byte((int8_t) - 1);
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new Byte((int8_t) 1);
    b = new Byte((int8_t) 1);
    c = a->equals(b);
    Test::assertEquals(true, c);
    a = new Byte((int8_t) - 1);
    b = new Byte((int8_t) - 1);
    c = a->equals(b);
    Test::assertEquals(true, c);
}

/**
 * Tests the toString method.
 */

void toStringTest() {
    Byte *a;
    String *b;
    // positive value text representation
    a = new Byte((int8_t) 100);
    b = a->toString();
    Test::assertEquals("100", b->_s());
    // zero value text representation
    a = new Byte((int8_t) 0);
    b = a->toString();
    Test::assertEquals("0", b->_s());
    // negative value text representation
    a = new Byte((int8_t) - 100);
    b = a->toString();
    Test::assertEquals("-100", b->_s());
}

/**
 * Tests the static toString method.
 */

void toStringTest2() {
    int8_t a;
    String *b;
    a = (int8_t) 100;
    b = Byte::toString(a);
    Test::assertEquals("100", b->_s());
    a = (int8_t) 0;
    b = Byte::toString(a);
    Test::assertEquals("0", b->_s());
    a = (int8_t) - 100;
    b = Byte::toString(a);
    Test::assertEquals("-100", b->_s());
}

/**
 * Tests the parseByte method.
 */

void parseByteTest() {
    int8_t a;
    // positive value parsing
    a = Byte::parseByte(new String("100"));
    Test::assertEquals((int8_t)100, a);
    // zero value parsing
    a = Byte::parseByte(new String("0"));
    Test::assertEquals((int8_t)0, a);
    // negative value parsing
    a = Byte::parseByte(new String("-100"));
    Test::assertEquals((int8_t)-100, a);
}

int main(int argc, char** argv) {
    Test::setUpTestModule("ByteTest");

    Test::registerTest(byteValueTest, "byteValueTest");
    Test::registerTest(compareToTest, "compareToTest");
    Test::registerTest(compareTest, "compareTest");
    Test::registerTest(equalsTest, "equalsTest");
    Test::registerTest(toStringTest, "toStringTest");
    Test::registerTest(toStringTest2, "toStringTest2");
    Test::registerTest(parseByteTest, "parseByteTest");
    
    Test::runTests();

    return (EXIT_SUCCESS);
}