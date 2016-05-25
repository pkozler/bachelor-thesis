#include <cstdlib>
#include <iostream>

#include "test.h"
#include "StringBuilder.h"

/*
 * Simple C++ Test Suite
 */

/**
 * Tests the constructor.
 */

void stringBuilderTest() {
    StringBuilder *a;
    String *b;
    // new empty stringbuilder
    a = new StringBuilder();
    b = a->toString();
    Test::assertEquals("", b->_s());
}

/**
 * Tests the append method.
 */

void appendTest() {
    StringBuilder *a;
    String *b;
    // appending of empty string
    a = new StringBuilder();
    a->append(new String(""));
    b = a->toString();
    Test::assertEquals("", b->_s());
    // appending of one char
    a = new StringBuilder();
    a->append(new String("."));
    b = a->toString();
    Test::assertEquals(".", b->_s());
    // appending of more chars
    a = new StringBuilder();
    a->append(new String("test"));
    b = a->toString();
    Test::assertEquals("test", b->_s());
    // multiple appendings (empty string at the beginning)
    a = new StringBuilder();
    a->append(new String("test"));
    a->append(new String("."));
    a->append(new String(""));
    b = a->toString();
    Test::assertEquals("test.", b->_s());
    // multiple appendings (empty string in the middle)
    a = new StringBuilder();
    a->append(new String("."));
    a->append(new String(""));
    a->append(new String("test"));
    b = a->toString();
    Test::assertEquals(".test", b->_s());
    // multiple appendings (empty string at the end)
    a = new StringBuilder();
    a->append(new String(""));
    a->append(new String("test"));
    a->append(new String("."));
    b = a->toString();
    Test::assertEquals("test.", b->_s());
}

/**
 * Tests the toString method.
 */

void toStringTest() {
    StringBuilder *a;
    String *b;
    // appending a string at once
    a = new StringBuilder();
    a->append(new String("This is a test"));
    b = a->toString();
    Test::assertEquals("This is a test", b->_s());
    // appending a string piecewise
    a = new StringBuilder();
    a->append(new String("This"))->append(new String(" is"))->append(new String(" a"))->append(new String(" test."));
    b = a->toString();
    Test::assertEquals("This is a test.", b->_s());
    // appending a string piecewise (more pieces)
    a = new StringBuilder();
    a->append(new String("This"))->append(new String(" "))->append(new String("is"))->append(new String(" "))->append(new String("a"))->append(new String(" "))->append(new String("test"))->append(new String("."));
    b = a->toString();
    Test::assertEquals("This is a test.", b->_s());
}

int main(int argc, char** argv) {
    Test::setUpTestModule("StringBuilderTest");

    Test::registerTest(stringBuilderTest, "stringBuilderTest");
    Test::registerTest(appendTest, "appendTest");
    Test::registerTest(toStringTest, "toStringTest");
    
    Test::runTests();

    return (EXIT_SUCCESS);
}