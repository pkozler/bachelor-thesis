#include <cstdlib>
#include <iostream>

#include "test.h"
#include "String_.h"

/**
 * A String class test suite.
 *
 * @author Petr Kozler (A13B0359P)
 */

/**
 * Tests the constructor with standard string as a parameter.
 */

void stringTest() {
    String *a;
    // a string with whitespaces
    a = new String("This is a test.");
    Test::assertEquals("This is a test.", a->_s());
    // letters
    a = new String("test");
    Test::assertEquals("test", a->_s());
    // digits
    a = new String("1234");
    Test::assertEquals("1234", a->_s());
    // one char
    a = new String("a");
    Test::assertEquals("a", a->_s());
    // empty string
    a = new String("");
    Test::assertEquals("", a->_s());
}

/**
 * Tests the constructor with array of bytes as a parameter.
 */

void stringTest2() {
    const int32_t length = 15;
    const int32_t length2 = 4;
    const int32_t length3 = 0;
    int8_t *a;
    String *b;
    // array with some whitespaces
    a = new int8_t[length]{(int8_t) 'T', (int8_t) 'h', (int8_t) 'i', (int8_t) 's', (int8_t) ' ', (int8_t) 'i', (int8_t) 's', (int8_t) ' ', (int8_t) 'a', (int8_t) ' ', (int8_t) 't', (int8_t) 'e', (int8_t) 's', (int8_t) 't', (int8_t) '.'};
    b = new String(a, length);
    Test::assertEquals("This is a test.", b->_s());
    // array without whitespaces
    a = new int8_t[length2]{(int8_t) '1', (int8_t) '2', (int8_t) '3', (int8_t) '4'};
    b = new String(a, length2);
    Test::assertEquals("1234", b->_s());
    // empty array
    a = new int8_t[length3]{};
    b = new String(a, length3);
    Test::assertEquals("", b->_s());
}

/**
 * Tests the constructor with array of bytes and indexes as parameters.
 */

void stringTest3() {
    const int32_t length = 15;
    int8_t *a;
    String *b;
    // choosing a part of array with some chars
    a = new int8_t[length]{(int8_t) 'T', (int8_t) 'h', (int8_t) 'i', (int8_t) 's', (int8_t) ' ', (int8_t) 'i', (int8_t) 's', (int8_t) ' ', (int8_t) 'a', (int8_t) ' ', (int8_t) 't', (int8_t) 'e', (int8_t) 's', (int8_t) 't', (int8_t) '.'};
    b = new String(a, 10, 4);
    Test::assertEquals("test", b->_s());
}

/**
 * Tests the compareTo method.
 */

void compareToTest() {
    String *a, *b;
    int32_t c;
    // differens strings at the beginning
    a = new String("aaa");
    b = new String("bbb");
    c = a->compareTo(b);
    Test::assertEquals(-1, c);
    // different strings at the end
    a = new String("aaaa");
    b = new String("aaab");
    c = a->compareTo(b);
    Test::assertEquals(-1, c);
    // differens strings at the beginning (swapped)
    a = new String("bbb");
    b = new String("aaa");
    c = a->compareTo(b);
    Test::assertEquals(1, c);
    // different strings at the end (swapped)
    a = new String("aaab");
    b = new String("aaaa");
    c = a->compareTo(b);
    Test::assertEquals(1, c);
    // equal strings
    a = new String("aaa");
    b = new String("aaa");
    c = a->compareTo(b);
    Test::assertEquals(0, c);
}

/**
 * Tests the equals method.
 */

void equalsTest() {
    String *a, *b;
    bool c;
    a = new String("aaa");
    b = new String("bbb");
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new String("aaaa");
    b = new String("aaab");
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new String("bbb");
    b = new String("aaa");
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new String("aaab");
    b = new String("aaaa");
    c = a->equals(b);
    Test::assertEquals(false, c);
    a = new String("aaa");
    b = new String("aaa");
    c = a->equals(b);
    Test::assertEquals(true, c);
}

/**
 * Tests the substring method.
 */

void substringTest() {
    String *a, *b;
    a = new String("This is a test.");
    // string from the beginning
    b = a->substring(0);
    Test::assertEquals("This is a test.", b->_s());
    // string from some other position
    b = a->substring(10);
    Test::assertEquals("test.", b->_s());
}

/**
 * Tests the substring method with end index as a parameter.
 */

void substringTest2() {
    String *a, *b;
    a = new String("This is a test.");
    // string from the beginning to the position near the beginning
    b = a->substring(0, 4);
    Test::assertEquals("This", b->_s());
    // string from the beginning to the position far from the beginning
    b = a->substring(10, 14);
    Test::assertEquals("test", b->_s());
    // string from the end
    b = a->substring(14, 15);
    Test::assertEquals(".", b->_s());
    // equal indexes
    b = a->substring(10, 10);
    Test::assertEquals("", b->_s());
}

/**
 * Tests the indexOf method with a char value.
 */

void indexOfTest() {
    String *a;
    int32_t b;
    a = new String("This is a test.");
    // char occurring once
    b = a->indexOf('a');
    Test::assertEquals(8, b);
    // char occuring more times
    b = a->indexOf('t');
    Test::assertEquals(10, b);
    // char occurring once (at the beginning)
    b = a->indexOf('T');
    Test::assertEquals(0, b);
    // char occurring once (at the end)
    b = a->indexOf('.');
    Test::assertEquals(14, b);
    // char not occurring
    b = a->indexOf('_');
    Test::assertEquals(-1, b);
}

/**
 * Tests the indexOf method with a char value and end index as a parameter.
 */

void indexOfTest2() {
    String *a;
    int32_t b;
    a = new String("This is a test.");
    b = a->indexOf('a', 10);
    Test::assertEquals(-1, b);
    b = a->indexOf('t', 10);
    Test::assertEquals(10, b);
    b = a->indexOf('i', 0);
    Test::assertEquals(2, b);
    b = a->indexOf('i', 4);
    Test::assertEquals(5, b);
    b = a->indexOf('i', 10);
    Test::assertEquals(-1, b);
}

/**
 * Tests the indexOf method with a string.
 */

void indexOfTest3() {
    String *a;
    int32_t b;
    a = new String("This is a test.");
    // occurring string (at the beginning)
    b = a->indexOf(new String("This"));
    Test::assertEquals(0, b);
    // occurring string (at the end)
    b = a->indexOf(new String("test"));
    Test::assertEquals(10, b);
    // non-occurring string
    b = a->indexOf(new String("aaa"));
    Test::assertEquals(-1, b);
}

/**
 * Tests the indexOf method with a string and end index as a parameter.
 */

void indexOfTest4() {
    String *a;
    int32_t b;
    a = new String("This is a test.");
    b = a->indexOf(new String("This"), 0);
    Test::assertEquals(0, b);
    b = a->indexOf(new String("test"), 4);
    Test::assertEquals(10, b);
    b = a->indexOf(new String("This"), 10);
    Test::assertEquals(-1, b);
}

/**
 * Tests the length method.
 */

void lengthTest() {
    String *a;
    int32_t b;
    // string with multiple chars
    a = new String("This is a test.");
    b = a->length();
    Test::assertEquals(15, b);
    // string with one char
    a = new String(".");
    b = a->length();
    Test::assertEquals(1, b);
    // empty string
    a = new String("");
    b = a->length();
    Test::assertEquals(0, b);
}

/**
 * Tests the trim method.
 */

void trimTest() {
    String *a, *b;
    // string without whitespaces
    a = new String("test");
    b = a->trim();
    Test::assertEquals("test", b->_s());
    // whitespaces on the left side
    a = new String("   test");
    b = a->trim();
    Test::assertEquals("test", b->_s());
    // whitespaces on the right side
    a = new String("test   ");
    b = a->trim();
    Test::assertEquals("test", b->_s());
    // whitespaces on bots sides
    a = new String(" test ");
    b = a->trim();
    Test::assertEquals("test", b->_s());
    // whitespaces inside
    a = new String("t e s t");
    b = a->trim();
    Test::assertEquals("t e s t", b->_s());
}

/**
 * Tests the toLower method.
 */

void toLowerCaseTest() {
    String *a, *b;
    // all letters lowercase
    a = new String("test");
    b = a->toLowerCase();
    Test::assertEquals("test", b->_s());
    // all letters uppercase
    a = new String("TEST");
    b = a->toLowerCase();
    Test::assertEquals("test", b->_s());
    // different cases
    a = new String("TesT");
    b = a->toLowerCase();
    Test::assertEquals("test", b->_s());
}

/**
 * Tests the toUpper method.
 */

void toUpperCaseTest() {
    String *a, *b;
    a = new String("test");
    b = a->toUpperCase();
    Test::assertEquals("TEST", b->_s());
    a = new String("TEST");
    b = a->toUpperCase();
    Test::assertEquals("TEST", b->_s());
    a = new String("TesT");
    b = a->toUpperCase();
    Test::assertEquals("TEST", b->_s());
}

/**
 * Tests the charAt method.
 */

void charAtTest() {
    String *a;
    char b;
    a = new String("This is a test.");
    // at the beginning
    b = a->charAt(0);
    Test::assertEquals('T', b);
    // in the middle
    b = a->charAt(10);
    Test::assertEquals('t', b);
    // at the end
    b = a->charAt(14);
    Test::assertEquals('.', b);
}

/**
 * Tests the replace method.
 */

void replaceTest() {
    String *a, *b;
    a = new String("This is a test.");
    // replacing chars inside the string
    b = a->replace(' ', '_');
    Test::assertEquals("This_is_a_test.", b->_s());
    // replacing chars in the beginning of the string
    b = a->replace('T', 't');
    Test::assertEquals("this is a test.", b->_s());
    // replacing chars in the end of the string
    b = a->replace('.', '!');
    Test::assertEquals("This is a test!", b->_s());
    // replacing of the non-existent chars
    b = a->replace('?', ':');
    Test::assertEquals("This is a test.", b->_s());
}

/**
 * Tests the startsWith method.
 */

void startsWithTest() {
    String *a, *b;
    bool c;
    a = new String("This is a test.");
    // string at the beginning
    b = new String("This ");
    c = a->startsWith(b);
    Test::assertEquals(true, c);
    // string inside
    b = new String("is");
    c = a->startsWith(b);
    Test::assertEquals(false, c);
    // string at the end
    b = new String("test.");
    c = a->startsWith(b);
    Test::assertEquals(false, c);
}

/**
 * Tests the endsWith method.
 */

void endsWithTest() {
    String *a, *b;
    bool c;
    a = new String("This is a test.");
    b = new String("This ");
    c = a->endsWith(b);
    Test::assertEquals(false, c);
    b = new String("is");
    c = a->endsWith(b);
    Test::assertEquals(false, c);
    b = new String("test.");
    c = a->endsWith(b);
    Test::assertEquals(true, c);
}

/**
 * Tests the isEmpty method.
 */

void isEmptyTest() {
    String *a;
    bool b;
    // non-empty string
    a = new String("This is a test.");
    b = a->isEmpty();
    Test::assertEquals(false, b);
    // non-empty string with a single char
    a = new String(".");
    b = a->isEmpty();
    Test::assertEquals(false, b);
    // empty string
    a = new String("");
    b = a->isEmpty();
    Test::assertEquals(true, b);
}

int main(int argc, char** argv) {
    Test::setUpTestModule("StringTest");

    Test::registerTest(stringTest, "stringTest");
    Test::registerTest(stringTest2, "stringTest2");
    Test::registerTest(stringTest3, "stringTest3");
    Test::registerTest(compareToTest, "compareToTest");
    Test::registerTest(equalsTest, "equalsTest");
    Test::registerTest(substringTest, "substringTest");
    Test::registerTest(substringTest2, "substringTest2");
    Test::registerTest(indexOfTest, "indexOfTest");
    Test::registerTest(indexOfTest2, "indexOfTest2");
    Test::registerTest(indexOfTest3, "indexOfTest3");
    Test::registerTest(indexOfTest4, "indexOfTest4");
    Test::registerTest(lengthTest, "lengthTest");
    Test::registerTest(trimTest, "trimTest");
    Test::registerTest(toLowerCaseTest, "toLowerCaseTest");
    Test::registerTest(toUpperCaseTest, "toUpperCaseTest");
    Test::registerTest(charAtTest, "charAtTest");
    Test::registerTest(replaceTest, "replaceTest");
    Test::registerTest(startsWithTest, "startsWithTest");
    Test::registerTest(endsWithTest, "endsWithTest");
    Test::registerTest(isEmptyTest, "isEmptyTest");
    
    Test::runTests();

    return (EXIT_SUCCESS);
}