#include "PrintStreamTest.h"

#include <cstdlib>
#include <iostream>

#include "System.h"
#include "Double.h"
#include "Float.h"
#include "Integer.h"
#include "Long.h"
#include "TestObject.h"
#include "String_.h"

/**
 * A PrintStream class test suite.
 *
 * @author Petr Kozler (A13B0359P)
 */

/**
 * Tests the print method with a bool value.
 */

void printTest() {
    bool a;
    // print of bool values
    a = true;
    System::out->print(a);
    System::out->print(new String("\n"));
    a = false;
    System::out->print(a);
    System::out->print(new String("\n"));
}

/**
 * Tests the print method with a char value.
 */

void printTest2() {
    char a;
    // print of lowercase letters
    a = 'a';
    System::out->print(a);
    System::out->print(new String("\n"));
    a = 'z';
    System::out->print(a);
    System::out->print(new String("\n"));
    // print of uppercase letters
    a = 'A';
    System::out->print(a);
    System::out->print(new String("\n"));
    a = 'Z';
    System::out->print(a);
    System::out->print(new String("\n"));
    // print of digits
    a = '0';
    System::out->print(a);
    System::out->print(new String("\n"));
    a = '9';
    System::out->print(a);
    System::out->print(new String("\n"));
}

/**
 * Tests the print method with array of chars.
 */

void printTest3() {
    const int32_t length = 0;
    const int32_t length2 = 1;
    const int32_t length3 = 6;
    char *a;
    // empty char array
    a = new char[length] {
    };
    System::out->print(a, length);
    System::out->print(new String("\n"));
    // char array with one char
    a = new char[length2] {
        'a'
    };
    System::out->print(a, length2);
    System::out->print(new String("\n"));
    // char array with some chars
    a = new char[length3] {
        'a', 'z', 'A', 'Z', '0', '9'
    };
    System::out->print(a, length3);
    System::out->print(new String("\n"));
}

/**
 * Tests the print method with a double value.
 */

void printTest4() {
    double a;
    // zeros with and without sign
    a = 0;
    System::out->print(a);
    System::out->print(new String("\n"));
    a = -0;
    System::out->print(a);
    System::out->print(new String("\n"));
    // ones with and without sign
    a = 1;
    System::out->print(a);
    System::out->print(new String("\n"));
    a = -1;
    System::out->print(a);
    System::out->print(new String("\n"));
    // maximal absolute value with and without sign
    a = Double::MAX_VALUE;
    System::out->print(a);
    System::out->print(new String("\n"));
    a = -Double::MAX_VALUE;
    System::out->print(a);
    System::out->print(new String("\n"));
    // minimal absolute value with and without sign
    a = Double::MIN_VALUE;
    System::out->print(a);
    System::out->print(new String("\n"));
    a = -Double::MIN_VALUE;
    System::out->print(a);
    System::out->print(new String("\n"));
}

/**
 * Tests the print method with a float value.
 */

void printTest5() {
    float a;
    a = 0;
    System::out->print(a);
    System::out->print(new String("\n"));
    a = -0;
    System::out->print(a);
    System::out->print(new String("\n"));
    a = 1;
    System::out->print(a);
    System::out->print(new String("\n"));
    a = -1;
    System::out->print(a);
    System::out->print(new String("\n"));
    a = Float::MAX_VALUE;
    System::out->print(a);
    System::out->print(new String("\n"));
    a = -Float::MAX_VALUE;
    System::out->print(a);
    System::out->print(new String("\n"));
    a = Float::MIN_VALUE;
    System::out->print(a);
    System::out->print(new String("\n"));
    a = -Float::MIN_VALUE;
    System::out->print(a);
    System::out->print(new String("\n"));
}

/**
 * Tests the print method with an int32_t value.
 */

void printTest6() {
    int32_t a;
    // zero
    a = 0;
    System::out->print(a);
    System::out->print(new String("\n"));
    // ones with and without sign
    a = 1;
    System::out->print(a);
    System::out->print(new String("\n"));
    a = -1;
    System::out->print(a);
    System::out->print(new String("\n"));
    // maximal and minimal value
    a = Integer::MAX_VALUE;
    System::out->print(a);
    System::out->print(new String("\n"));
    a = Integer::MIN_VALUE;
    System::out->print(a);
    System::out->print(new String("\n"));
}

/**
 * Tests the print method with a int64_t value.
 */

void printTest7() {
    int64_t a;
    a = 0;
    System::out->print(a);
    System::out->print(new String("\n"));
    a = 1;
    System::out->print(a);
    System::out->print(new String("\n"));
    a = -1;
    System::out->print(a);
    System::out->print(new String("\n"));
    a = Long::MAX_VALUE;
    System::out->print(a);
    System::out->print(new String("\n"));
    a = Long::MIN_VALUE;
    System::out->print(a);
    System::out->print(new String("\n"));
}

/**
 * Tests the print method with an object.
 */

void printTest8() {
    TestObject *a;
    // object with an empty string
    a = new TestObject(new String(""), 0);
    System::out->print(a);
    System::out->print(new String("\n"));
    // object with digits
    a = new TestObject(new String("0"), 1);
    System::out->print(a);
    System::out->print(new String("\n"));
    a = new TestObject(new String("9"), -1);
    System::out->print(a);
    System::out->print(new String("\n"));
    // object with letters
    a = new TestObject(new String("Aa"), Integer::MAX_VALUE);
    System::out->print(a);
    System::out->print(new String("\n"));
    a = new TestObject(new String("Zz"), Integer::MIN_VALUE);
    System::out->print(a);
    System::out->print(new String("\n"));
}

/**
 * Tests the print method with a string.
 */

void printTest9() {
    String *a;
    // empty string
    a = new String("");
    System::out->print(a);
    System::out->print(new String("\n"));
    // string with one char
    a = new String("a");
    System::out->print(a);
    System::out->print(new String("\n"));
    // string with some chars
    a = new String("azAZ09");
    System::out->print(a);
    System::out->print(new String("\n"));
}

/**
 * Tests the println method.
 */

void printlnTest() {
    // print of an empty line
    System::out->println();
}

/**
 * Tests the println method with a bool value.
 */

void printlnTest2() {
    bool a;
    a = true;
    System::out->println(a);
    a = false;
    System::out->println(a);
}

/**
 * Tests the println method with a char value.
 */

void printlnTest3() {
    char a;
    a = 'a';
    System::out->println(a);
    a = 'z';
    System::out->println(a);
    a = 'A';
    System::out->println(a);
    a = 'Z';
    System::out->println(a);
    a = '0';
    System::out->println(a);
    a = '9';
    System::out->println(a);
}

/**
 * Tests the println method with array of chars.
 */

void printlnTest4() {
    const int32_t length = 0;
    const int32_t length2 = 1;
    const int32_t length3 = 6;
    char *a;
    a = new char[length] {
    };
    System::out->println(a, length);
    a = new char[length2] {
        'a'
    };
    System::out->println(a, length2);
    a = new char[length3] {
        'a', 'z', 'A', 'Z', '0', '9'
    };
    System::out->println(a, length3);
}

/**
 * Tests the println method with a double value.
 */

void printlnTest5() {
    double a;
    a = 0;
    System::out->println(a);
    a = -0;
    System::out->println(a);
    a = 1;
    System::out->println(a);
    a = -1;
    System::out->println(a);
    a = Double::MAX_VALUE;
    System::out->println(a);
    a = -Double::MAX_VALUE;
    System::out->println(a);
    a = Double::MIN_VALUE;
    System::out->println(a);
    a = -Double::MIN_VALUE;
    System::out->println(a);
}

/**
 * Tests the println method with a float value.
 */

void printlnTest6() {
    float a;
    a = 0;
    System::out->println(a);
    a = -0;
    System::out->println(a);
    a = 1;
    System::out->println(a);
    a = -1;
    System::out->println(a);
    a = Float::MAX_VALUE;
    System::out->println(a);
    a = -Float::MAX_VALUE;
    System::out->println(a);
    a = Float::MIN_VALUE;
    System::out->println(a);
    a = -Float::MIN_VALUE;
    System::out->println(a);
}

/**
 * Tests the println method with an int32_t value.
 */

void printlnTest7() {
    int32_t a;
    a = 0;
    System::out->println(a);
    a = 1;
    System::out->println(a);
    a = -1;
    System::out->println(a);
    a = Integer::MAX_VALUE;
    System::out->println(a);
    a = Integer::MIN_VALUE;
    System::out->println(a);
}

/**
 * Tests the println method with a int64_t value.
 */

void printlnTest8() {
    int64_t a;
    a = 0;
    System::out->println(a);
    a = 1;
    System::out->println(a);
    a = -1;
    System::out->println(a);
    a = Long::MAX_VALUE;
    System::out->println(a);
    a = Long::MIN_VALUE;
    System::out->println(a);
}

/**
 * Tests the println method with an object.
 */

void printlnTest9() {
    TestObject *a;
    a = new TestObject(new String(""), 0);
    System::out->println(a);
    a = new TestObject(new String("0"), 1);
    System::out->println(a);
    a = new TestObject(new String("9"), -1);
    System::out->println(a);
    a = new TestObject(new String("Aa"), Integer::MAX_VALUE);
    System::out->println(a);
    a = new TestObject(new String("Zz"), Integer::MIN_VALUE);
    System::out->println(a);
}

/**
 * Tests the println method with a string.
 */

void printlnTest10() {
    String *a;
    a = new String("");
    System::out->println(a);
    a = new String("a");
    System::out->println(a);
    a = new String("azAZ09");
    System::out->println(a);
}
