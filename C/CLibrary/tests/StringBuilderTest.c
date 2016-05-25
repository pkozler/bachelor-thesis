#include <stdio.h>
#include <stdlib.h>

#include "test.h"
#include "StringBuilder.h"

/*
 * Simple C Test Suite
 */

/**
 * Tests the constructor.
 */

void stringBuilderTest() {
    StringBuilder *a;
    String *b;
    // new_empty stringbuilder
    a = new_StringBuilder();
    b = toStringSb(a);
    assertEqualsStr("", b->s);
}

/**
 * Tests the append function.
 */

void appendTest() {
    StringBuilder *a;
    String *b;
    // appending of empty string
    a = new_StringBuilder();
    append(a, new_String(""));
    b = toStringSb(a);
    assertEqualsStr("", b->s);
    // appending of one char
    a = new_StringBuilder();
    append(a, new_String("."));
    b = toStringSb(a);
    assertEqualsStr(".", b->s);
    // appending of more chars
    a = new_StringBuilder();
    append(a, new_String("test"));
    b = toStringSb(a);
    assertEqualsStr("test", b->s);
    // multiple appendings (empty string at the beginning)
    a = new_StringBuilder();
    append(a, new_String("test"));
    append(a, new_String("."));
    append(a, new_String(""));
    b = toStringSb(a);
    assertEqualsStr("test.", b->s);
    // multiple appendings (empty string in the middle)
    a = new_StringBuilder();
    append(a, new_String("."));
    append(a, new_String(""));
    append(a, new_String("test"));
    b = toStringSb(a);
    assertEqualsStr(".test", b->s);
    // multiple appendings (empty string at the end)
    a = new_StringBuilder();
    append(a, new_String(""));
    append(a, new_String("test"));
    append(a, new_String("."));
    b = toStringSb(a);
    assertEqualsStr("test.", b->s);
}

/**
 * Tests the toString function.
 */

void toStringTest() {
    StringBuilder *a;
    String *b;
    // appending a string at once
    a = new_StringBuilder();
    append(a, new_String("This is a test"));
    b = toStringSb(a);
    assertEqualsStr("This is a test", b->s);
    // appending a string piecewise
    a = new_StringBuilder();
    append(append(append(append(a, 
            new_String("This")), 
            new_String(" is")), 
            new_String(" a")), 
            new_String(" test."));
    b = toStringSb(a);
    assertEqualsStr("This is a test.", b->s);
    // appending a string piecewise (more pieces)
    a = new_StringBuilder();
    append(append(append(append(append(append(append(append(a, 
            new_String("This")), 
            new_String(" ")), 
            new_String("is")), 
            new_String(" ")), 
            new_String("a")), 
            new_String(" ")), 
            new_String("test")), 
            new_String("."));
    b = toStringSb(a);
    assertEqualsStr("This is a test.", b->s);
}

int main(int argc, char** argv) {
    const int testCount = 3;
    setUpTestModule("StringBuilderTest", testCount);

    registerTest(stringBuilderTest, "stringBuilderTest");
    registerTest(appendTest, "appendTest");
    registerTest(toStringTest, "toStringTest");
    
    runTests();

    return (EXIT_SUCCESS);
}
