#include "PrintStreamTest.h"

#include <stdio.h>
#include <stdlib.h>

#include "System.h"
#include "Double.h"
#include "Float.h"
#include "Integer.h"
#include "Long.h"
#include "TestObject.h"
#include "String.h"

/**
 * A PrintStream module test suite.
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
    printBool(System_out, a);
    printStr(System_out, new_String("\n"));
    a = false;
    printBool(System_out, a);
    printStr(System_out, new_String("\n"));
}

/**
 * Tests the print method with a char value.
 */

void printTest2() {
    char a;
    // print of lowercase letters
    a = 'a';
    printC(System_out, a);
    printStr(System_out, new_String("\n"));
    a = 'z';
    printC(System_out, a);
    printStr(System_out, new_String("\n"));
    // print of uppercase letters
    a = 'A';
    printC(System_out, a);
    printStr(System_out, new_String("\n"));
    a = 'Z';
    printC(System_out, a);
    printStr(System_out, new_String("\n"));
    // print of digits
    a = '0';
    printC(System_out, a);
    printStr(System_out, new_String("\n"));
    a = '9';
    printC(System_out, a);
    printStr(System_out, new_String("\n"));
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
    a = malloc(length * sizeof(char));
    printS(System_out, a, length);
    printStr(System_out, new_String("\n"));
    // char array with one char
    a = malloc(length2 * sizeof(char));
    a[0] = 'a';
    printS(System_out, a, length2);
    printStr(System_out, new_String("\n"));
    // char array with some chars
    a = malloc(length3 * sizeof(char));
    a[0] = 'a';
    a[1] = 'z';
    a[2] = 'A';
    a[3] = 'Z';
    a[4] = '0';
    a[5] = '9';
    printS(System_out, a, length3);
    printStr(System_out, new_String("\n"));
}

/**
 * Tests the print method with a double value.
 */

void printTest4() {
    double a;
    // zeros with and without sign
    a = 0;
    printD(System_out, a);
    printStr(System_out, new_String("\n"));
    a = -0;
    printD(System_out, a);
    printStr(System_out, new_String("\n"));
    // ones with and without sign
    a = 1;
    printD(System_out, a);
    printStr(System_out, new_String("\n"));
    a = -1;
    printD(System_out, a);
    printStr(System_out, new_String("\n"));
    // maximal absolute value with and without sign
    a = Double_MAX_VALUE;
    printD(System_out, a);
    printStr(System_out, new_String("\n"));
    a = -Double_MAX_VALUE;
    printD(System_out, a);
    printStr(System_out, new_String("\n"));
    // minimal absolute value with and without sign
    a = Double_MIN_VALUE;
    printD(System_out, a);
    printStr(System_out, new_String("\n"));
    a = -Double_MIN_VALUE;
    printD(System_out, a);
    printStr(System_out, new_String("\n"));
}

/**
 * Tests the print method with a float value.
 */

void printTest5() {
    float a;
    a = 0;
    printF(System_out, a);
    printStr(System_out, new_String("\n"));
    a = -0;
    printF(System_out, a);
    printStr(System_out, new_String("\n"));
    a = 1;
    printF(System_out, a);
    printStr(System_out, new_String("\n"));
    a = -1;
    printF(System_out, a);
    printStr(System_out, new_String("\n"));
    a = Float_MAX_VALUE;
    printF(System_out, a);
    printStr(System_out, new_String("\n"));
    a = -Float_MAX_VALUE;
    printF(System_out, a);
    printStr(System_out, new_String("\n"));
    a = Float_MIN_VALUE;
    printF(System_out, a);
    printStr(System_out, new_String("\n"));
    a = -Float_MIN_VALUE;
    printF(System_out, a);
    printStr(System_out, new_String("\n"));
}

/**
 * Tests the print method with an int32_t value.
 */

void printTest6() {
    int32_t a;
    // zero
    a = 0;
    printI(System_out, a);
    printStr(System_out, new_String("\n"));
    // ones with and without sign
    a = 1;
    printI(System_out, a);
    printStr(System_out, new_String("\n"));
    a = -1;
    printI(System_out, a);
    printStr(System_out, new_String("\n"));
    // maximal and minimal value
    a = Integer_MAX_VALUE;
    printI(System_out, a);
    printStr(System_out, new_String("\n"));
    a = Integer_MIN_VALUE;
    printI(System_out, a);
    printStr(System_out, new_String("\n"));
}

/**
 * Tests the print method with a int64_t value.
 */

void printTest7() {
    int64_t a;
    a = 0;
    printL(System_out, a);
    printStr(System_out, new_String("\n"));
    a = 1;
    printL(System_out, a);
    printStr(System_out, new_String("\n"));
    a = -1;
    printL(System_out, a);
    printStr(System_out, new_String("\n"));
    a = Long_MAX_VALUE;
    printL(System_out, a);
    printStr(System_out, new_String("\n"));
    a = Long_MIN_VALUE;
    printL(System_out, a);
    printStr(System_out, new_String("\n"));
}

/**
 * Tests the print method with an object.
 */

void printTest8() {
    TestObject *a;
    // object with an empty string
    a = new_TestObject(new_String(""), 0);
    printObj(System_out, a, toStringTo);
    printStr(System_out, new_String("\n"));
    // object with digits
    a = new_TestObject(new_String("0"), 1);
    printObj(System_out, a, toStringTo);
    printStr(System_out, new_String("\n"));
    a = new_TestObject(new_String("9"), -1);
    printObj(System_out, a, toStringTo);
    printStr(System_out, new_String("\n"));
    // object with letters
    a = new_TestObject(new_String("Aa"), Integer_MAX_VALUE);
    printObj(System_out, a, toStringTo);
    printStr(System_out, new_String("\n"));
    a = new_TestObject(new_String("Zz"), Integer_MIN_VALUE);
    printObj(System_out, a, toStringTo);
    printStr(System_out, new_String("\n"));
}

/**
 * Tests the print method with a string.
 */

void printTest9() {
    String *a;
    // empty string
    a = new_String("");
    printStr(System_out, a);
    printStr(System_out, new_String("\n"));
    // string with one char
    a = new_String("a");
    printStr(System_out, a);
    printStr(System_out, new_String("\n"));
    // string with some chars
    a = new_String("azAZ09");
    printStr(System_out, a);
    printStr(System_out, new_String("\n"));
}

/**
 * Tests the println method.
 */

void printlnTest() {
    // print of an empty line
    println(System_out);
}

/**
 * Tests the println method with a bool value.
 */

void printlnTest2() {
    bool a;
    a = true;
    printlnBool(System_out, a);
    a = false;
    printlnBool(System_out, a);
}

/**
 * Tests the println method with a char value.
 */

void printlnTest3() {
    char a;
    a = 'a';
    printlnC(System_out, a);
    a = 'z';
    printlnC(System_out, a);
    a = 'A';
    printlnC(System_out, a);
    a = 'Z';
    printlnC(System_out, a);
    a = '0';
    printlnC(System_out, a);
    a = '9';
    printlnC(System_out, a);
}

/**
 * Tests the println method with array of chars.
 */

void printlnTest4() {
    const int32_t length = 0;
    const int32_t length2 = 1;
    const int32_t length3 = 6;
    char *a;
    a = malloc(length * sizeof(char));
    printlnS(System_out, a, length);
    a = malloc(length2 * sizeof(char));
    a[0] = 'a';
    printlnS(System_out, a, length2);
    a = malloc(length3 * sizeof(char));
    a[0] = 'a';
    a[1] = 'z';
    a[2] = 'A';
    a[3] = 'Z';
    a[4] = '0';
    a[5] = '9';
    printlnS(System_out, a, length3);
}

/**
 * Tests the println method with a double value.
 */

void printlnTest5() {
    double a;
    a = 0;
    printlnD(System_out, a);
    a = -0;
    printlnD(System_out, a);
    a = 1;
    printlnD(System_out, a);
    a = -1;
    printlnD(System_out, a);
    a = Double_MAX_VALUE;
    printlnD(System_out, a);
    a = -Double_MAX_VALUE;
    printlnD(System_out, a);
    a = Double_MIN_VALUE;
    printlnD(System_out, a);
    a = -Double_MIN_VALUE;
    printlnD(System_out, a);
}

/**
 * Tests the println method with a float value.
 */

void printlnTest6() {
    float a;
    a = 0;
    printlnF(System_out, a);
    a = -0;
    printlnF(System_out, a);
    a = 1;
    printlnF(System_out, a);
    a = -1;
    printlnF(System_out, a);
    a = Float_MAX_VALUE;
    printlnF(System_out, a);
    a = -Float_MAX_VALUE;
    printlnF(System_out, a);
    a = Float_MIN_VALUE;
    printlnF(System_out, a);
    a = -Float_MIN_VALUE;
    printlnF(System_out, a);
}

/**
 * Tests the println method with an int32_t value.
 */

void printlnTest7() {
    int32_t a;
    a = 0;
    printlnI(System_out, a);
    a = 1;
    printlnI(System_out, a);
    a = -1;
    printlnI(System_out, a);
    a = Integer_MAX_VALUE;
    printlnI(System_out, a);
    a = Integer_MIN_VALUE;
    printlnI(System_out, a);
}

/**
 * Tests the println method with a int64_t value.
 */

void printlnTest8() {
    int64_t a;
    a = 0;
    printlnL(System_out, a);
    a = 1;
    printlnL(System_out, a);
    a = -1;
    printlnL(System_out, a);
    a = Long_MAX_VALUE;
    printlnL(System_out, a);
    a = Long_MIN_VALUE;
    printlnL(System_out, a);
}

/**
 * Tests the println method with an object.
 */

void printlnTest9() {
    TestObject *a;
    a = new_TestObject(new_String(""), 0);
    printlnObj(System_out, a, toStringTo);
    a = new_TestObject(new_String("0"), 1);
    printlnObj(System_out, a, toStringTo);
    a = new_TestObject(new_String("9"), -1);
    printlnObj(System_out, a, toStringTo);
    a = new_TestObject(new_String("Aa"), Integer_MAX_VALUE);
    printlnObj(System_out, a, toStringTo);
    a = new_TestObject(new_String("Zz"), Integer_MIN_VALUE);
    printlnObj(System_out, a, toStringTo);
}

/**
 * Tests the println method with a string.
 */

void printlnTest10() {
    String *a;
    a = new_String("");
    printlnStr(System_out, a);
    a = new_String("a");
    printlnStr(System_out, a);
    a = new_String("azAZ09");
    printlnStr(System_out, a);
}
