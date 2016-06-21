#include <stdio.h>
#include <stdlib.h>

#include "test.h"
#include "Boolean.h"

/**
 * A Boolean module test suite.
 *
 * @author Petr Kozler (A13B0359P)
 */

/**
 * Tests the booleanValue function.
 */

void booleanValueTest() {
    Boolean *a;
    bool b;
    // true value
    a = new_Boolean(true);
    b = booleanValue(a);
    assertEqualsBool(true, b);
    // false falue
    a = new_Boolean(false);
    b = booleanValue(a);
    assertEqualsBool(false, b);
}

/**
 * Tests the compareTo function.
 */

void compareToTest() {
    Boolean *a, *b;
    int32_t c;
    // true and false
    a = new_Boolean(true);
    b = new_Boolean(false);
    c = compareToBool(a, b);
    assertEqualsI(1, c);
    // false and true
    a = new_Boolean(false);
    b = new_Boolean(true);
    c = compareToBool(a, b);
    assertEqualsI(-1, c);
    // both values are true
    a = new_Boolean(true);
    b = new_Boolean(true);
    c = compareToBool(a, b);
    assertEqualsI(0, c);
    // both values are false
    a = new_Boolean(false);
    b = new_Boolean(false);
    c = compareToBool(a, b);
    assertEqualsI(0, c);
}

/**
 * Tests the compare function.
 */

void compareTest() {
    bool a, b;
    int32_t c;
    a = true;
    b = false;
    c = Boolean_compare(a, b);
    assertEqualsI(1, c);
    a = false;
    b = true;
    c = Boolean_compare(a, b);
    assertEqualsI(-1, c);
    a = true;
    b = true;
    c = Boolean_compare(a, b);
    assertEqualsI(0, c);
    a = false;
    b = false;
    c = Boolean_compare(a, b);
    assertEqualsI(0, c);
}

/**
 * Tests the equals function.
 */

void equalsTest() {
    Boolean *a, *b;
    bool c;
    a = new_Boolean(true);
    b = new_Boolean(false);
    c = equalsBool(a, b);
    assertEqualsBool(false, c);
    a = new_Boolean(false);
    b = new_Boolean(true);
    c = equalsBool(a, b);
    assertEqualsBool(false, c);
    a = new_Boolean(true);
    b = new_Boolean(true);
    c = equalsBool(a, b);
    assertEqualsBool(true, c);
    a = new_Boolean(false);
    b = new_Boolean(false);
    c = equalsBool(a, b);
    assertEqualsBool(true, c);
}

/**
 * Tests the toString function.
 */

void toStringTest() {
    Boolean *a;
    String *b;
    // true value text representation
    a = new_Boolean(true);
    b = toStringBool(a);
    assertEqualsStr("true", b->s);
    // false value text representation
    a = new_Boolean(false);
    b = toStringBool(a);
    assertEqualsStr("false", b->s);
}

/**
 * Tests the static toString function.
 */

void toStringTest2() {
    bool a;
    String *b;
    a = true;
    b = Boolean_toString(a);
    assertEqualsStr("true", b->s);
    a = false;
    b = Boolean_toString(a);
    assertEqualsStr("false", b->s);
}

/**
 * Tests the parseBoolean function.
 */

void parseBooleanTest() {
    bool a;
    // true value parsing
    a = Boolean_parseBoolean(new_String("true"));
    assertEqualsBool(true, a);
    // false value parsing
    a = Boolean_parseBoolean(new_String("false"));
    assertEqualsBool(false, a);
}

int main(int argc, char** argv) {
    const int testCount = 7;
    setUpTestModule("BooleanTest", testCount);

    registerTest(booleanValueTest, "booleanValueTest");
    registerTest(compareToTest, "compareToTest");
    registerTest(compareTest, "compareTest");
    registerTest(equalsTest, "equalsTest");
    registerTest(toStringTest, "toStringTest");
    registerTest(toStringTest2, "toStringTest2");
    registerTest(parseBooleanTest, "parseBooleanTest");
    
    runTests();

    return (EXIT_SUCCESS);
}
