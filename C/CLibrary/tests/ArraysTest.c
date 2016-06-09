#include <stdio.h>
#include <stdlib.h>

#include "test.h"
#include "Arrays.h"
#include "TestObject.h"

/*
 * Simple C Test Suite
 */

/**
 * Tests the binarySearch function with array of bytes.
 */

void binarySearchTest() {
    const int32_t length = 5;
    int8_t *a;
    int32_t b;
    a = malloc(length * sizeof(int8_t));
    a[0] = (int8_t) 3;
    a[1] = (int8_t) 2;
    a[2] = (int8_t) 8;
    a[3] = (int8_t) 7;
    a[4] = (int8_t) 6;
    Arrays_sortB(a, length);
    // existing element search
    b = Arrays_binarySearchB(a, length, (int8_t) 8);
    assertEqualsI(4, b);
    // non-existent element search
    b = Arrays_binarySearchB(a, length, (int8_t) 4);
    assertEqualsI(-3, b);
}

/**
 * Tests the binarySearch function with array of bytes and indexes as
 * parameters.
 */

void binarySearchTest2() {
    const int32_t length = 5;
    int8_t *a;
    int32_t b;
    a = malloc(length * sizeof(int8_t));
    a[0] = (int8_t) 3;
    a[1] = (int8_t) 2;
    a[2] = (int8_t) 8;
    a[3] = (int8_t) 7;
    a[4] = (int8_t) 6;
    Arrays_sortB(a, length);
    // existing element search
    b = Arrays_binarySearchRangeB(a, 1, 4, (int8_t) 8);
    assertEqualsI(-5, b);
    // non-existent element search in a part of array
    b = Arrays_binarySearchRangeB(a, 1, 4, (int8_t) 4);
    assertEqualsI(-3, b);
}

/**
 * Tests the binarySearch function with array of chars.
 */

void binarySearchTest3() {
    const int32_t length = 5;
    char *a;
    int32_t b;
    a = malloc(length * sizeof(char));
    a[0] = 'c';
    a[1] = 'b';
    a[2] = 'h';
    a[3] = 'g';
    a[4] = 'f';
    Arrays_sortC(a, length);
    b = Arrays_binarySearchC(a, length, 'h');
    assertEqualsI(4, b);
    b = Arrays_binarySearchC(a, length, 'd');
    assertEqualsI(-3, b);
}

/**
 * Tests the binarySearch function with array of chars and indexes as
 * parameters.
 */

void binarySearchTest4() {
    const int32_t length = 5;
    char *a;
    int32_t b;
    a = malloc(length * sizeof(char));
    a[0] = 'c';
    a[1] = 'b';
    a[2] = 'h';
    a[3] = 'g';
    a[4] = 'f';
    Arrays_sortC(a, length);
    b = Arrays_binarySearchRangeC(a, 1, 4, 'h');
    assertEqualsI(-5, b);
    b = Arrays_binarySearchRangeC(a, 1, 4, 'd');
    assertEqualsI(-3, b);
}

/**
 * Tests the binarySearch function with array of doubles.
 */

void binarySearchTest5() {
    const int32_t length = 5;
    double *a;
    int32_t b;
    a = malloc(length * sizeof(double));
    a[0] = 3.0;
    a[1] = 2.0;
    a[2] = 8.0;
    a[3] = 7.0;
    a[4] = 6.0;
    Arrays_sortD(a, length);
    b = Arrays_binarySearchD(a, length, 8.0);
    assertEqualsI(4, b);
    b = Arrays_binarySearchD(a, length, 4.0);
    assertEqualsI(-3, b);
}

/**
 * Tests the binarySearch function with array of doubles and indexes as
 * parameters.
 */

void binarySearchTest6() {
    const int32_t length = 5;
    double *a;
    int32_t b;
    a = malloc(length * sizeof(double));
    a[0] = 3.0;
    a[1] = 2.0;
    a[2] = 8.0;
    a[3] = 7.0;
    a[4] = 6.0;
    Arrays_sortD(a, length);
    b = Arrays_binarySearchRangeD(a, 1, 4, 8.0);
    assertEqualsI(-5, b);
    b = Arrays_binarySearchRangeD(a, 1, 4, 4.0);
    assertEqualsI(-3, b);
}

/**
 * Tests the binarySearch function with array of floats.
 */

void binarySearchTest7() {
    const int32_t length = 5;
    float *a;
    int32_t b;
    a = malloc(length * sizeof(float));
    a[0] = 3.0F;
    a[1] = 2.0F;
    a[2] = 8.0F;
    a[3] = 7.0F;
    a[4] = 6.0F;
    Arrays_sortF(a, length);
    b = Arrays_binarySearchF(a, length, 8.0F);
    assertEqualsI(4, b);
    b = Arrays_binarySearchF(a, length, 4.0F);
    assertEqualsI(-3, b);
}

/**
 * Tests the binarySearch function with array of floats and indexes as
 * parameters.
 */

void binarySearchTest8() {
    const int32_t length = 5;
    float *a;
    int32_t b;
    a = malloc(length * sizeof(float));
    a[0] = 3.0F;
    a[1] = 2.0F;
    a[2] = 8.0F;
    a[3] = 7.0F;
    a[4] = 6.0F;
    Arrays_sortF(a, length);
    b = Arrays_binarySearchRangeF(a, 1, 4, 8.0F);
    assertEqualsI(-5, b);
    b = Arrays_binarySearchRangeF(a, 1, 4, 4.0F);
    assertEqualsI(-3, b);
}

/**
 * Tests the binarySearch function with array of ints.
 */

void binarySearchTest9() {
    const int32_t length = 5;
    int32_t *a;
    int32_t b;
    a = malloc(length * sizeof(int32_t));
    a[0] = 3;
    a[1] = 2;
    a[2] = 8;
    a[3] = 7;
    a[4] = 6;
    Arrays_sortI(a, length);
    b = Arrays_binarySearchI(a, length, 8);
    assertEqualsI(4, b);
    b = Arrays_binarySearchI(a, length, 4);
    assertEqualsI(-3, b);
}

/**
 * Tests the binarySearch function with array of ints and indexes as
 * parameters.
 */

void binarySearchTest10() {
    const int32_t length = 5;
    int32_t *a;
    int32_t b;
    a = malloc(length * sizeof(int32_t));
    a[0] = 3;
    a[1] = 2;
    a[2] = 8;
    a[3] = 7;
    a[4] = 6;
    Arrays_sortI(a, length);
    b = Arrays_binarySearchRangeI(a, 1, 4, 8);
    assertEqualsI(-5, b);
    b = Arrays_binarySearchRangeI(a, 1, 4, 4);
    assertEqualsI(-3, b);
}

/**
 * Tests the binarySearch function with array of longs.
 */

void binarySearchTest11() {
    const int32_t length = 5;
    int64_t *a;
    int32_t b;
    a = malloc(length * sizeof(int64_t));
    a[0] = 3L;
    a[1] = 2L;
    a[2] = 8L;
    a[3] = 7L;
    a[4] = 6L;
    Arrays_sortL(a, length);
    b = Arrays_binarySearchL(a, length, 8L);
    assertEqualsI(4, b);
    b = Arrays_binarySearchL(a, length, 4L);
    assertEqualsI(-3, b);
}

/**
 * Tests the binarySearch function with array of longs and indexes as
 * parameters.
 */

void binarySearchTest12() {
    const int32_t length = 5;
    int64_t *a;
    int32_t b;
    a = malloc(length * sizeof(int64_t));
    a[0] = 3L;
    a[1] = 2L;
    a[2] = 8L;
    a[3] = 7L;
    a[4] = 6L;
    Arrays_sortL(a, length);
    b = Arrays_binarySearchRangeL(a, 1, 4, 8L);
    assertEqualsI(-5, b);
    b = Arrays_binarySearchRangeL(a, 1, 4, 4L);
    assertEqualsI(-3, b);
}

/**
 * Tests the binarySearch function with array of structures.
 */

void binarySearchTest13() {
    const int32_t length = 10;
    TestObject **a;
    int32_t b;
    a = malloc(length * sizeof(TestObject *));
    a[0] = new_TestObject(new_String("first"), 3);
    a[1] = new_TestObject(new_String("second"), 2);
    a[2] = new_TestObject(new_String("third"), 8);
    a[3] = new_TestObject(new_String("fourth"), 7);
    a[4] = new_TestObject(new_String("fifth"), 6);
    a[5] = new_TestObject(new_String("sixth"), 3);
    a[6] = new_TestObject(new_String("seventh"), 2);
    a[7] = new_TestObject(new_String("eighth"), 8);
    a[8] = new_TestObject(new_String("nineth"), 7);
    a[9] = new_TestObject(new_String("tenth"), 6);
    Arrays_sortObj(a, length, compareToTo);
    b = Arrays_binarySearchObj(a, length, new_TestObject(new_String("sixth"), 6), compareToTo);
    assertEqualsI(4, b);
    b = Arrays_binarySearchObj(a, length, new_TestObject(new_String("sixth"), 4), compareToTo);
    assertEqualsI(-5, b);
}

/**
 * Tests the binarySearch function with array of structures and indexes as
 * parameters.
 */

void binarySearchTest14() {
    const int32_t length = 10;
    TestObject **a;
    int32_t b;
    a = malloc(length * sizeof(TestObject *));
    a[0] = new_TestObject(new_String("first"), 3);
    a[1] = new_TestObject(new_String("second"), 2);
    a[2] = new_TestObject(new_String("third"), 8);
    a[3] = new_TestObject(new_String("fourth"), 7);
    a[4] = new_TestObject(new_String("fifth"), 6);
    a[5] = new_TestObject(new_String("sixth"), 3);
    a[6] = new_TestObject(new_String("seventh"), 2);
    a[7] = new_TestObject(new_String("eighth"), 8);
    a[8] = new_TestObject(new_String("nineth"), 7);
    a[9] = new_TestObject(new_String("tenth"), 6);
    Arrays_sortObj(a, length, compareToTo);
    b = Arrays_binarySearchRangeObj(a, 1, 4, new_TestObject(new_String("sixth"), 6), compareToTo);
    assertEqualsI(-5, b);
    b = Arrays_binarySearchRangeObj(a, 1, 4, new_TestObject(new_String("sixth"), 4), compareToTo);
    assertEqualsI(-5, b);
}

/**
 * Tests the binarySearch function with array of shorts.
 */

void binarySearchTest15() {
    const int32_t length = 5;
    int16_t *a;
    int32_t b;
    a = malloc(length * sizeof(int16_t));
    a[0] = (int16_t) 3;
    a[1] = (int16_t) 2;
    a[2] = (int16_t) 8;
    a[3] = (int16_t) 7;
    a[4] = (int16_t) 6;
    Arrays_sortS(a, length);
    b = Arrays_binarySearchS(a, length, (int16_t) 8);
    assertEqualsI(4, b);
    b = Arrays_binarySearchS(a, length, (int16_t) 4);
    assertEqualsI(-3, b);
}

/**
 * Tests the binarySearch function with array of shorts and indexes as
 * parameters.
 */

void binarySearchTest16() {
    const int32_t length = 5;
    int16_t *a;
    int32_t b;
    a = malloc(length * sizeof(int16_t));
    a[0] = (int16_t) 3;
    a[1] = (int16_t) 2;
    a[2] = (int16_t) 8;
    a[3] = (int16_t) 7;
    a[4] = (int16_t) 6;
    Arrays_sortS(a, length);
    b = Arrays_binarySearchRangeS(a, 1, 4, (int16_t) 8);
    assertEqualsI(-5, b);
    b = Arrays_binarySearchRangeS(a, 1, 4, (int16_t) 4);
    assertEqualsI(-3, b);
}

/**
 * Tests the copyOf function with array of booleans.
 */

void copyOfTest() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    const int32_t length3 = 7;
    bool *a, *b, *d;
    bool c;
    a = malloc(length * sizeof(bool));
    a[0] = true;
    a[1] = false;
    a[2] = false;
    a[3] = false;
    a[4] = true;
    // new_array is smaller
    b = Arrays_copyOfBool(a, length, 3);
    d = malloc(length2 * sizeof(bool));
    d[0] = true;
    d[1] = false;
    d[2] = false;
    c = Arrays_equalsBool(b, length, d, length2);
    assertEqualsBool(true, c);
    // new_array has the same length
    b = Arrays_copyOfBool(a, length, 5);
    d = malloc(length * sizeof(bool));
    d[0] = true;
    d[1] = false;
    d[2] = false;
    d[3] = false;
    d[4] = true;
    c = Arrays_equalsBool(b, length, d, length);
    assertEqualsBool(true, c);
    // new_array is bigger
    b = Arrays_copyOfBool(a, length, 7);
    d = malloc(length3 * sizeof(bool));
    d[0] = true;
    d[1] = false;
    d[2] = false;
    d[3] = false;
    d[4] = true;
    d[5] = false;
    d[6] = false;
    c = Arrays_equalsBool(b, length, d, length3);
    assertEqualsBool(true, c);
}

/**
 * Tests the copyOf function with array of bytes.
 */

void copyOfTest2() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    const int32_t length3 = 7;
    int8_t *a, *b, *d;
    bool c;
    a = malloc(length * sizeof(int8_t));
    a[0] = (int8_t) 3;
    a[1] = (int8_t) 2;
    a[2] = (int8_t) 8;
    a[3] = (int8_t) 7;
    a[4] = (int8_t) 6;
    b = Arrays_copyOfB(a, length, 3);
    d = malloc(length2 * sizeof(int8_t));
    d[0] = (int8_t) 3;
    d[1] = (int8_t) 2;
    d[2] = (int8_t) 8;
    c = Arrays_equalsB(b, length, d, length2);
    assertEqualsBool(true, c);
    b = Arrays_copyOfB(a, length, 5);
    d = malloc(length * sizeof(int8_t));
    d[0] = (int8_t) 3;
    d[1] = (int8_t) 2;
    d[2] = (int8_t) 8;
    d[3] = (int8_t) 7;
    d[4] = (int8_t) 6;
    c = Arrays_equalsB(b, length, d, length);
    assertEqualsBool(true, c);
    b = Arrays_copyOfB(a, length, 7);
    d = malloc(length3 * sizeof(int8_t));
    d[0] = (int8_t) 3;
    d[1] = (int8_t) 2;
    d[2] = (int8_t) 8;
    d[3] = (int8_t) 7;
    d[4] = (int8_t) 6;
    d[5] = (int8_t) 0;
    d[6] = (int8_t) 0;
    c = Arrays_equalsB(b, length, d, length3);
    assertEqualsBool(true, c);
}

/**
 * Tests the copyOf function with array of chars.
 */

void copyOfTest3() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    const int32_t length3 = 7;
    char *a, *b, *d;
    bool c;
    a = malloc(length * sizeof(char));
    a[0] = 'c';
    a[1] = 'b';
    a[2] = 'h';
    a[3] = 'g';
    a[4] = 'f';
    b = Arrays_copyOfC(a, length, 3);
    d = malloc(length2 * sizeof(char));
    d[0] = 'c';
    d[1] = 'b';
    d[2] = 'h';
    c = Arrays_equalsC(b, length, d, length2);
    assertEqualsBool(true, c);
    b = Arrays_copyOfC(a, length, 5);
    d = malloc(length * sizeof(char));
    d[0] = 'c';
    d[1] = 'b';
    d[2] = 'h';
    d[3] = 'g';
    d[4] = 'f';
    c = Arrays_equalsC(b, length, d, length);
    assertEqualsBool(true, c);
    b = Arrays_copyOfC(a, length, 7);
    d = malloc(length3 * sizeof(char));
    d[0] = 'c';
    d[1] = 'b';
    d[2] = 'h';
    d[3] = 'g';
    d[4] = 'f';
    d[5] = '\0';
    d[6] = '\0';
    c = Arrays_equalsC(b, length, d, length3);
    assertEqualsBool(true, c);
}

/**
 * Tests the copyOf function with array of doubles.
 */

void copyOfTest4() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    const int32_t length3 = 7;
    double *a, *b, *d;
    bool c;
    a = malloc(length * sizeof(double));
    a[0] = 3.0;
    a[1] = 2.0;
    a[2] = 8.0;
    a[3] = 7.0;
    a[4] = 6.0;
    b = Arrays_copyOfD(a, length, 3);
    d = malloc(length2 * sizeof(double));
    d[0] = 3.0;
    d[1] = 2.0;
    d[2] = 8.0;
    c = Arrays_equalsD(b, length, d, length2);
    assertEqualsBool(true, c);
    b = Arrays_copyOfD(a, length, 5);
    d = malloc(length * sizeof(double));
    d[0] = 3.0;
    d[1] = 2.0;
    d[2] = 8.0;
    d[3] = 7.0;
    d[4] = 6.0;
    c = Arrays_equalsD(b, length, d, length);
    assertEqualsBool(true, c);
    b = Arrays_copyOfD(a, length, 7);
    d = malloc(length3 * sizeof(double));
    d[0] = 3.0;
    d[1] = 2.0;
    d[2] = 8.0;
    d[3] = 7.0;
    d[4] = 6.0;
    d[5] = 0.0;
    d[6] = 0.0;
    c = Arrays_equalsD(b, length, d, length3);
    assertEqualsBool(true, c);
}

/**
 * Tests the copyOf function with array of floats.
 */

void copyOfTest5() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    const int32_t length3 = 7;
    float *a, *b, *d;
    bool c;
    a = malloc(length * sizeof(float));
    a[0] = 3.0F;
    a[1] = 2.0F;
    a[2] = 8.0F;
    a[3] = 7.0F;
    a[4] = 6.0F;
    b = Arrays_copyOfF(a, length, 3);
    d = malloc(length2 * sizeof(float));
    d[0] = 3.0F;
    d[1] = 2.0F;
    d[2] = 8.0F;
    c = Arrays_equalsF(b, length, d, length2);
    assertEqualsBool(true, c);
    b = Arrays_copyOfF(a, length, 5);
    d = malloc(length * sizeof(float));
    d[0] = 3.0F;
    d[1] = 2.0F;
    d[2] = 8.0F;
    d[3] = 7.0F;
    d[4] = 6.0F;
    c = Arrays_equalsF(b, length, d, length);
    assertEqualsBool(true, c);
    b = Arrays_copyOfF(a, length, 7);
    d = malloc(length3 * sizeof(float));
    d[0] = 3.0F;
    d[1] = 2.0F;
    d[2] = 8.0F;
    d[3] = 7.0F;
    d[4] = 6.0F;
    d[5] = 0.0F;
    d[6] = 0.0F;
    c = Arrays_equalsF(b, length, d, length3);
    assertEqualsBool(true, c);
}

/**
 * Tests the copyOf function with array of ints.
 */

void copyOfTest6() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    const int32_t length3 = 7;
    int32_t *a, *b, *d;
    bool c;
    a = malloc(length * sizeof(int32_t));
    a[0] = 3;
    a[1] = 2;
    a[2] = 8;
    a[3] = 7;
    a[4] = 6;
    b = Arrays_copyOfI(a, length, 3);
    d = malloc(length2 * sizeof(int32_t));
    d[0] = 3;
    d[1] = 2;
    d[2] = 8;
    c = Arrays_equalsI(b, length, d, length2);
    assertEqualsBool(true, c);
    b = Arrays_copyOfI(a, length, 5);
    d = malloc(length * sizeof(int32_t));
    d[0] = 3;
    d[1] = 2;
    d[2] = 8;
    d[3] = 7;
    d[4] = 6;
    c = Arrays_equalsI(b, length, d, length);
    assertEqualsBool(true, c);
    b = Arrays_copyOfI(a, length, 7);
    d = malloc(length3 * sizeof(int32_t));
    d[0] = 3;
    d[1] = 2;
    d[2] = 8;
    d[3] = 7;
    d[4] = 6;
    d[5] = 0;
    d[6] = 0;
    c = Arrays_equalsI(b, length, d, length3);
    assertEqualsBool(true, c);
}

/**
 * Tests the copyOf function with array of longs.
 */

void copyOfTest7() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    const int32_t length3 = 7;
    int64_t *a, *b, *d;
    bool c;
    a = malloc(length * sizeof(int64_t));
    a[0] = 3L;
    a[1] = 2L;
    a[2] = 8L;
    a[3] = 7L;
    a[4] = 6L;
    b = Arrays_copyOfL(a, length, 3);
    d = malloc(length2 * sizeof(int64_t));
    d[0] = 3L;
    d[1] = 2L;
    d[2] = 8L;
    c = Arrays_equalsL(b, length, d, length2);
    assertEqualsBool(true, c);
    b = Arrays_copyOfL(a, length, 5);
    d = malloc(length * sizeof(int64_t));
    d[0] = 3L;
    d[1] = 2L;
    d[2] = 8L;
    d[3] = 7L;
    d[4] = 6L;
    c = Arrays_equalsL(b, length, d, length);
    assertEqualsBool(true, c);
    b = Arrays_copyOfL(a, length, 7);
    d = malloc(length3 * sizeof(int64_t));
    d[0] = 3L;
    d[1] = 2L;
    d[2] = 8L;
    d[3] = 7L;
    d[4] = 6L;
    d[5] = 0L;
    d[6] = 0L;
    c = Arrays_equalsL(b, length, d, length3);
    assertEqualsBool(true, c);
}

/**
 * Tests the copyOf function with array of shorts.
 */

void copyOfTest8() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    const int32_t length3 = 7;
    int16_t *a, *b, *d;
    bool c;
    a = malloc(length * sizeof(int16_t));
    a[0] = (int16_t) 3;
    a[1] = (int16_t) 2;
    a[2] = (int16_t) 8;
    a[3] = (int16_t) 7;
    a[4] = (int16_t) 6;
    b = Arrays_copyOfS(a, length, 3);
    d = malloc(length2 * sizeof(int16_t));
    d[0] = (int16_t) 3;
    d[1] = (int16_t) 2;
    d[2] = (int16_t) 8;
    c = Arrays_equalsS(b, length, d, length2);
    assertEqualsBool(true, c);
    b = Arrays_copyOfS(a, length, 5);
    d = malloc(length * sizeof(int16_t));
    d[0] = (int16_t) 3;
    d[1] = (int16_t) 2;
    d[2] = (int16_t) 8;
    d[3] = (int16_t) 7;
    d[4] = (int16_t) 6;
    c = Arrays_equalsS(b, length, d, length);
    assertEqualsBool(true, c);
    b = Arrays_copyOfS(a, length, 7);
    d = malloc(length3 * sizeof(int16_t));
    d[0] = (int16_t) 3;
    d[1] = (int16_t) 2;
    d[2] = (int16_t) 8;
    d[3] = (int16_t) 7;
    d[4] = (int16_t) 6;
    d[5] = (int16_t) 0;
    d[6] = (int16_t) 0;
    c = Arrays_equalsS(b, length, d, length3);
    assertEqualsBool(true, c);
}

/**
 * Tests the copyOf function with array of structures.
 */

void copyOfTest9() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    const int32_t length3 = 7;
    TestObject **a, **b, **d;
    bool c;
    a = malloc(length * sizeof(char));
    a[0] = new_TestObject(new_String("first"), 3);
    a[1] = new_TestObject(new_String("second"), 2);
    a[2] = new_TestObject(new_String("third"), 8);
    a[3] = new_TestObject(new_String("fourth"), 7);
    a[4] = new_TestObject(new_String("fifth"), 6);
    b = Arrays_copyOfObj(a, length, 3);
    d = malloc(length2 * sizeof(char));
    d[0] = new_TestObject(new_String("first"), 3);
    d[1] = new_TestObject(new_String("second"), 2);
    d[2] = new_TestObject(new_String("third"), 8);
    c = Arrays_equalsObj((TestObject **) b, length, (TestObject **) d, length2, equalsTo);
    assertEqualsBool(true, c);
    b = Arrays_copyOfObj(a, length, 5);
    d = malloc(length * sizeof(char));
    d[0] = new_TestObject(new_String("first"), 3);
    d[1] = new_TestObject(new_String("second"), 2);
    d[2] = new_TestObject(new_String("third"), 8);
    d[3] = new_TestObject(new_String("fourth"), 7);
    d[4] = new_TestObject(new_String("fifth"), 6);
    c = Arrays_equalsObj((TestObject **) b, length, (TestObject **) d, length, equalsTo);
    assertEqualsBool(true, c);
    b = Arrays_copyOfObj(a, length, 7);
    d = malloc(length3 * sizeof(char));
    d[0] = new_TestObject(new_String("first"), 3);
    d[1] = new_TestObject(new_String("second"), 2);
    d[2] = new_TestObject(new_String("third"), 8);
    d[3] = new_TestObject(new_String("fourth"), 7);
    d[4] = new_TestObject(new_String("fifth"), 6);
    d[5] = NULL;
    d[6] = NULL;
    c = Arrays_equalsObj((TestObject **) b, length, (TestObject **) d, length3, equalsTo);
    assertEqualsBool(true, c);
}

/**
 * Tests the copyOfRange function with array of booleans.
 */

void copyOfRangeTest1() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    bool *a, *b, *d;
    bool c;
    a = malloc(length * sizeof(bool));
    a[0] = true;
    a[1] = false;
    a[2] = false;
    a[3] = false;
    a[4] = true;
    // copy from the beginning
    b = Arrays_copyOfRangeBool(a, length, 0, 3);
    d = malloc(length2 * sizeof(bool));
    d[0] = true;
    d[1] = false;
    d[2] = false;
    c = Arrays_equalsBool(b, length, d, length2);
    assertEqualsBool(true, c);
    // copy from the middle
    b = Arrays_copyOfRangeBool(a, length, 2, 5);
    d = malloc(length2 * sizeof(bool));
    d[0] = false;
    d[1] = false;
    d[2] = true;
    c = Arrays_equalsBool(b, length, d, length2);
    assertEqualsBool(true, c);
    // copy from the end
    b = Arrays_copyOfRangeBool(a, length, 4, 7);
    d = malloc(length2 * sizeof(bool));
    d[0] = true;
    d[1] = false;
    d[2] = false;
    c = Arrays_equalsBool(b, length, d, length2);
    assertEqualsBool(true, c);
}

/**
 * Tests the copyOfRange function with array of bytes.
 */

void copyOfRangeTest2() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    int8_t *a, *b, *d;
    bool c;
    a = malloc(length * sizeof(int8_t));
    a[0] = (int8_t) 3;
    a[1] = (int8_t) 2;
    a[2] = (int8_t) 8;
    a[3] = (int8_t) 7;
    a[4] = (int8_t) 6;
    b = Arrays_copyOfRangeB(a, length, 0, 3);
    d = malloc(length2 * sizeof(int8_t));
    d[0] = (int8_t) 3;
    d[1] = (int8_t) 2;
    d[2] = (int8_t) 8;
    c = Arrays_equalsB(b, length, d, length2);
    assertEqualsBool(true, c);
    b = Arrays_copyOfRangeB(a, length, 2, 5);
    d = malloc(length2 * sizeof(int8_t));
    d[0] = (int8_t) 8;
    d[1] = (int8_t) 7;
    d[2] = (int8_t) 6;
    c = Arrays_equalsB(b, length, d, length2);
    assertEqualsBool(true, c);
    b = Arrays_copyOfRangeB(a, length, 4, 7);
    d = malloc(length2 * sizeof(int8_t));
    d[0] = (int8_t) 6;
    d[1] = (int8_t) 0;
    d[2] = (int8_t) 0;
    c = Arrays_equalsB(b, length, d, length2);
    assertEqualsBool(true, c);
}

/**
 * Tests the copyOfRange function with array of chars.
 */

void copyOfRangeTest3() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    char *a, *b, *d;
    bool c;
    a = malloc(length * sizeof(char));
    a[0] = 'c';
    a[1] = 'b';
    a[2] = 'h';
    a[3] = 'g';
    a[4] = 'f';
    b = Arrays_copyOfRangeC(a, length, 0, 3);
    d = malloc(length2 * sizeof(char));
    d[0] = 'c';
    d[1] = 'b';
    d[2] = 'h';
    c = Arrays_equalsC(b, length, d, length2);
    assertEqualsBool(true, c);
    b = Arrays_copyOfRangeC(a, length, 2, 5);
    d = malloc(length2 * sizeof(char));
    d[0] = 'h';
    d[1] = 'g';
    d[2] = 'f';
    c = Arrays_equalsC(b, length, d, length2);
    assertEqualsBool(true, c);
    b = Arrays_copyOfRangeC(a, length, 4, 7);
    d = malloc(length2 * sizeof(char));
    d[0] = 'f';
    d[1] = '\0';
    d[2] = '\0';
    c = Arrays_equalsC(b, length, d, length2);
    assertEqualsBool(true, c);
}

/**
 * Tests the copyOfRange function with array of doubles.
 */

void copyOfRangeTest4() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    double *a, *b, *d;
    bool c;
    a = malloc(length * sizeof(double));
    a[0] = 3.0;
    a[1] = 2.0;
    a[2] = 8.0;
    a[3] = 7.0;
    a[4] = 6.0;
    b = Arrays_copyOfRangeD(a, length, 0, 3);
    d = malloc(length2 * sizeof(double));
    d[0] = 3.0;
    d[1] = 2.0;
    d[2] = 8.0;
    c = Arrays_equalsD(b, length, d, length2);
    assertEqualsBool(true, c);
    b = Arrays_copyOfRangeD(a, length, 2, 5);
    d = malloc(length2 * sizeof(double));
    d[0] = 8.0;
    d[1] = 7.0;
    d[2] = 6.0;
    c = Arrays_equalsD(b, length, d, length2);
    assertEqualsBool(true, c);
    b = Arrays_copyOfRangeD(a, length, 4, 7);
    d = malloc(length2 * sizeof(double));
    d[0] = 6.0;
    d[1] = 0.0;
    d[2] = 0.0;
    c = Arrays_equalsD(b, length, d, length2);
    assertEqualsBool(true, c);
}

/**
 * Tests the copyOfRange function with array of floats.
 */

void copyOfRangeTest5() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    float *a, *b, *d;
    bool c;
    a = malloc(length * sizeof(float));
    a[0] = 3.0F;
    a[1] = 2.0F;
    a[2] = 8.0F;
    a[3] = 7.0F;
    a[4] = 6.0F;
    b = Arrays_copyOfRangeF(a, length, 0, 3);
    d = malloc(length2 * sizeof(float));
    d[0] = 3.0F;
    d[1] = 2.0F;
    d[2] = 8.0F;
    c = Arrays_equalsF(b, length, d, length2);
    assertEqualsBool(true, c);
    b = Arrays_copyOfRangeF(a, length, 2, 5);
    d = malloc(length2 * sizeof(float));
    d[0] = 8.0F;
    d[1] = 7.0F;
    d[2] = 6.0F;
    c = Arrays_equalsF(b, length, d, length2);
    assertEqualsBool(true, c);
    b = Arrays_copyOfRangeF(a, length, 4, 7);
    d = malloc(length2 * sizeof(float));
    d[0] = 6.0F;
    d[1] = 0.0F;
    d[2] = 0.0F;
    c = Arrays_equalsF(b, length, d, length2);
    assertEqualsBool(true, c);
}

/**
 * Tests the copyOfRange function with array of ints.
 */

void copyOfRangeTest6() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    int32_t *a, *b, *d;
    bool c;
    a = malloc(length * sizeof(int32_t));
    a[0] = 3;
    a[1] = 2;
    a[2] = 8;
    a[3] = 7;
    a[4] = 6;
    b = Arrays_copyOfRangeI(a, length, 0, 3);
    d = malloc(length2 * sizeof(int32_t));
    d[0] = 3;
    d[1] = 2;
    d[2] = 8;
    c = Arrays_equalsI(b, length, d, length2);
    assertEqualsBool(true, c);
    b = Arrays_copyOfRangeI(a, length, 2, 5);
    d = malloc(length2 * sizeof(int32_t));
    d[0] = 8;
    d[1] = 7;
    d[2] = 6;
    c = Arrays_equalsI(b, length, d, length2);
    assertEqualsBool(true, c);
    b = Arrays_copyOfRangeI(a, length, 4, 7);
    d = malloc(length2 * sizeof(int32_t));
    d[0] = 6;
    d[1] = 0;
    d[2] = 0;
    c = Arrays_equalsI(b, length, d, length2);
    assertEqualsBool(true, c);
}

/**
 * Tests the copyOfRange function with array of longs.
 */

void copyOfRangeTest7() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    int64_t *a, *b, *d;
    bool c;
    a = malloc(length * sizeof(int64_t));
    a[0] = 3L;
    a[1] = 2L;
    a[2] = 8L;
    a[3] = 7L;
    a[4] = 6L;
    b = Arrays_copyOfRangeL(a, length, 0, 3);
    d = malloc(length2 * sizeof(int64_t));
    d[0] = 3L;
    d[1] = 2L;
    d[2] = 8L;
    c = Arrays_equalsL(b, length, d, length2);
    assertEqualsBool(true, c);
    b = Arrays_copyOfRangeL(a, length, 2, 5);
    d = malloc(length2 * sizeof(int64_t));
    d[0] = 8L;
    d[1] = 7L;
    d[2] = 6L;
    c = Arrays_equalsL(b, length, d, length2);
    assertEqualsBool(true, c);
    b = Arrays_copyOfRangeL(a, length, 4, 7);
    d = malloc(length2 * sizeof(int64_t));
    d[0] = 6L;
    d[1] = 0L;
    d[2] = 0L;
    c = Arrays_equalsL(b, length, d, length2);
    assertEqualsBool(true, c);
}

/**
 * Tests the copyOfRange function with array of shorts.
 */

void copyOfRangeTest8() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    int16_t *a, *b, *d;
    bool c;
    a = malloc(length * sizeof(int16_t));
    a[0] = (int16_t) 3;
    a[1] = (int16_t) 2;
    a[2] = (int16_t) 8;
    a[3] = (int16_t) 7;
    a[4] = (int16_t) 6;
    b = Arrays_copyOfRangeS(a, length, 0, 3);
    d = malloc(length2 * sizeof(int16_t));
    d[0] = (int16_t) 3;
    d[1] = (int16_t) 2;
    d[2] = (int16_t) 8;
    c = Arrays_equalsS(b, length, d, length2);
    assertEqualsBool(true, c);
    b = Arrays_copyOfRangeS(a, length, 2, 5);
    d = malloc(length2 * sizeof(int16_t));
    d[0] = (int16_t) 8;
    d[1] = (int16_t) 7;
    d[2] = (int16_t) 6;
    c = Arrays_equalsS(b, length, d, length2);
    assertEqualsBool(true, c);
    b = Arrays_copyOfRangeS(a, length, 4, 7);
    d = malloc(length2 * sizeof(int16_t));
    d[0] = (int16_t) 6;
    d[1] = (int16_t) 0;
    d[2] = (int16_t) 0;
    c = Arrays_equalsS(b, length, d, length2);
    assertEqualsBool(true, c);
}

/**
 * Tests the copyOfRange function with array of structures.
 */

void copyOfRangeTest9() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    TestObject **a, **b, **d;
    bool c;
    a = malloc(length * sizeof(char));
    a[0] = new_TestObject(new_String("first"), 3);
    a[1] = new_TestObject(new_String("second"), 2);
    a[2] = new_TestObject(new_String("third"), 8);
    a[3] = new_TestObject(new_String("fourth"), 7);
    a[4] = new_TestObject(new_String("fifth"), 6);
    b = Arrays_copyOfRangeObj(a, length, 0, 3);
    d = malloc(length2 * sizeof(char));
    d[0] = new_TestObject(new_String("first"), 3);
    d[1] = new_TestObject(new_String("second"), 2);
    d[2] = new_TestObject(new_String("third"), 8);
    c = Arrays_equalsObj((TestObject **) b, length, (TestObject **) d, length2, equalsTo);
    assertEqualsBool(true, c);
    b = Arrays_copyOfRangeObj(a, length, 2, 5);
    d = malloc(length2 * sizeof(char));
    d[0] = new_TestObject(new_String("third"), 8);
    d[1] = new_TestObject(new_String("fourth"), 7);
    d[2] = new_TestObject(new_String("fifth"), 6);
    c = Arrays_equalsObj((TestObject **) b, length, (TestObject **) d, length2, equalsTo);
    assertEqualsBool(true, c);
    b = Arrays_copyOfRangeObj(a, length, 4, 7);
    d = malloc(length2 * sizeof(char));
    d[0] = new_TestObject(new_String("fifth"), 6);
    d[1] = NULL;
    d[2] = NULL;
    c = Arrays_equalsObj((TestObject **) b, length, (TestObject **) d, length2, equalsTo);
    assertEqualsBool(true, c);
}

/**
 * Tests the equals function with array of booleans.
 */

void equalsTest() {
    const int32_t length = 5;
    const int32_t length2 = 1;
    bool *a, *b;
    bool c;
    a = malloc(length * sizeof(bool));
    a[0] = true;
    a[1] = false;
    a[2] = false;
    a[3] = false;
    a[4] = true;
    // reference to the second array is NULL
    b = NULL;
    c = Arrays_equalsBool(a, length, b, 0);
    assertEqualsBool(false, c);
    // arrays do not have the same length
    b = malloc(length2 * sizeof(bool));
    b[0] = true;
    c = Arrays_equalsBool(a, length, b, length2);
    assertEqualsBool(false, c);
    // arrays have the same length but different elements
    b = malloc(length * sizeof(bool));
    b[0] = true;
    b[1] = false;
    b[2] = false;
    b[3] = false;
    b[4] = false;
    c = Arrays_equalsBool(a, length, b, length);
    assertEqualsBool(false, c);
    // arrays have the same length and elements
    b = malloc(length * sizeof(bool));
    b[0] = true;
    b[1] = false;
    b[2] = false;
    b[3] = false;
    b[4] = true;
    c = Arrays_equalsBool(a, length, b, length);
    assertEqualsBool(true, c);
    // references are equal
    b = a;
    c = Arrays_equalsBool(a, length, b, length);
    assertEqualsBool(true, c);
}

/**
 * Tests the equals function with array of bytes.
 */

void equalsTest2() {
    const int32_t length = 5;
    const int32_t length2 = 1;
    int8_t *a, *b;
    bool c;
    a = malloc(length * sizeof(int8_t));
    a[0] = (int8_t) 3;
    a[1] = (int8_t) 2;
    a[2] = (int8_t) 8;
    a[3] = (int8_t) 7;
    a[4] = (int8_t) 6;
    b = NULL;
    c = Arrays_equalsB(a, length, b, 0);
    assertEqualsBool(false, c);
    b = malloc(length2 * sizeof(int8_t));
    b[0] = (int8_t) 3;
    c = Arrays_equalsB(a, length, b, length2);
    assertEqualsBool(false, c);
    b = malloc(length * sizeof(int8_t));
    b[0] = (int8_t) 3;
    b[1] = (int8_t) 2;
    b[2] = (int8_t) 8;
    b[3] = (int8_t) 7;
    b[4] = (int8_t) 3;
    c = Arrays_equalsB(a, length, b, length);
    assertEqualsBool(false, c);
    b = malloc(length * sizeof(int8_t));
    b[0] = (int8_t) 3;
    b[1] = (int8_t) 2;
    b[2] = (int8_t) 8;
    b[3] = (int8_t) 7;
    b[4] = (int8_t) 6;
    c = Arrays_equalsB(a, length, b, length);
    assertEqualsBool(true, c);
    b = a;
    c = Arrays_equalsB(a, length, b, length);
    assertEqualsBool(true, c);
}

/**
 * Tests the equals function with array of chars.
 */

void equalsTest3() {
    const int32_t length = 5;
    const int32_t length2 = 1;
    char *a, *b;
    bool c;
    a = malloc(length * sizeof(char));
    a[0] = 'c';
    a[1] = 'b';
    a[2] = 'h';
    a[3] = 'g';
    a[4] = 'f';
    b = NULL;
    c = Arrays_equalsC(a, length, b, 0);
    assertEqualsBool(false, c);
    b = malloc(length2 * sizeof(char));
    b[0] = 'c';
    c = Arrays_equalsC(a, length, b, length2);
    assertEqualsBool(false, c);
    b = malloc(length * sizeof(char));
    b[0] = 'c';
    b[1] = 'b';
    b[2] = 'h';
    b[3] = 'g';
    b[4] = 'c';
    c = Arrays_equalsC(a, length, b, length);
    assertEqualsBool(false, c);
    b = malloc(length * sizeof(char));
    b[0] = 'c';
    b[1] = 'b';
    b[2] = 'h';
    b[3] = 'g';
    b[4] = 'f';
    c = Arrays_equalsC(a, length, b, length);
    assertEqualsBool(true, c);
    b = a;
    c = Arrays_equalsC(a, length, b, length);
    assertEqualsBool(true, c);
}

/**
 * Tests the equals function with array of doubles.
 */

void equalsTest4() {
    const int32_t length = 5;
    const int32_t length2 = 1;
    double *a, *b;
    bool c;
    a = malloc(length * sizeof(float));
    a[0] = 3.0;
    a[1] = 2.0;
    a[2] = 8.0;
    a[3] = 7.0;
    a[4] = 6.0;
    b = NULL;
    c = Arrays_equalsD(a, length, b, 0);
    assertEqualsBool(false, c);
    b = malloc(length2 * sizeof(float));
    b[0] = 3.0;
    c = Arrays_equalsD(a, length, b, length2);
    assertEqualsBool(false, c);
    b = malloc(length * sizeof(float));
    b[0] = 3.0;
    b[1] = 2.0;
    b[2] = 8.0;
    b[3] = 7.0;
    b[4] = 3.0;
    c = Arrays_equalsD(a, length, b, length);
    assertEqualsBool(false, c);
    b = malloc(length * sizeof(float));
    b[0] = 3.0;
    b[1] = 2.0;
    b[2] = 8.0;
    b[3] = 7.0;
    b[4] = 6.0;
    c = Arrays_equalsD(a, length, b, length);
    assertEqualsBool(true, c);
    b = a;
    c = Arrays_equalsD(a, length, b, length);
    assertEqualsBool(true, c);
}

/**
 * Tests the equals function with array of floats.
 */

void equalsTest5() {
    const int32_t length = 5;
    const int32_t length2 = 1;
    float *a, *b;
    bool c;
    a = malloc(length * sizeof(float));
    a[0] = 3.0F;
    a[1] = 2.0F;
    a[2] = 8.0F;
    a[3] = 7.0F;
    a[4] = 6.0F;
    b = NULL;
    c = Arrays_equalsF(a, length, b, 0);
    assertEqualsBool(false, c);
    b = malloc(length2 * sizeof(float));
    b[0] = 3.0F;
    c = Arrays_equalsF(a, length, b, length2);
    assertEqualsBool(false, c);
    b = malloc(length * sizeof(float));
    b[0] = 3.0F;
    b[1] = 2.0F;
    b[2] = 8.0F;
    b[3] = 7.0F;
    b[4] = 3.0F;
    c = Arrays_equalsF(a, length, b, length);
    assertEqualsBool(false, c);
    b = malloc(length * sizeof(float));
    b[0] = 3.0F;
    b[1] = 2.0F;
    b[2] = 8.0F;
    b[3] = 7.0F;
    b[4] = 6.0F;
    c = Arrays_equalsF(a, length, b, length);
    assertEqualsBool(true, c);
    b = a;
    c = Arrays_equalsF(a, length, b, length);
    assertEqualsBool(true, c);
}

/**
 * Tests the equals function with array of ints.
 */

void equalsTest6() {
    const int32_t length = 5;
    const int32_t length2 = 1;
    int32_t *a, *b;
    bool c;
    a = malloc(length * sizeof(int32_t));
    a[0] = 3;
    a[1] = 2;
    a[2] = 8;
    a[3] = 7;
    a[4] = 6;
    b = NULL;
    c = Arrays_equalsI(a, length, b, 0);
    assertEqualsBool(false, c);
    b = malloc(length2 * sizeof(int32_t));
    b[0] = 3;
    c = Arrays_equalsI(a, length, b, length2);
    assertEqualsBool(false, c);
    b = malloc(length * sizeof(int32_t));
    b[0] = 3;
    b[1] = 2;
    b[2] = 8;
    b[3] = 7;
    b[4] = 3;
    c = Arrays_equalsI(a, length, b, length);
    assertEqualsBool(false, c);
    b = malloc(length * sizeof(int32_t));
    b[0] = 3;
    b[1] = 2;
    b[2] = 8;
    b[3] = 7;
    b[4] = 6;
    c = Arrays_equalsI(a, length, b, length);
    assertEqualsBool(true, c);
    b = a;
    c = Arrays_equalsI(a, length, b, length);
    assertEqualsBool(true, c);
}

/**
 * Tests the equals function with array of longs.
 */

void equalsTest7() {
    const int32_t length = 5;
    const int32_t length2 = 1;
    int64_t *a, *b;
    bool c;
    a = malloc(length * sizeof(int64_t));
    a[0] = 3L;
    a[1] = 2L;
    a[2] = 8L;
    a[3] = 7L;
    a[4] = 6L;
    b = NULL;
    c = Arrays_equalsL(a, length, b, 0);
    assertEqualsBool(false, c);
    b = malloc(length2 * sizeof(int64_t));
    b[0] = 3L;
    c = Arrays_equalsL(a, length, b, length2);
    assertEqualsBool(false, c);
    b = malloc(length * sizeof(int64_t));
    b[0] = 3L;
    b[1] = 2L;
    b[2] = 8L;
    b[3] = 7L;
    b[4] = 3L;
    c = Arrays_equalsL(a, length, b, length);
    assertEqualsBool(false, c);
    b = malloc(length * sizeof(int64_t));
    b[0] = 3L;
    b[1] = 2L;
    b[2] = 8L;
    b[3] = 7L;
    b[4] = 6L;
    c = Arrays_equalsL(a, length, b, length);
    assertEqualsBool(true, c);
    b = a;
    c = Arrays_equalsL(a, length, b, length);
    assertEqualsBool(true, c);
}

/**
 * Tests the equals function with array of structures.
 */

void equalsTest8() {
    const int32_t length = 5;
    const int32_t length2 = 1;
    TestObject **a, **b;
    bool c;
    a = malloc(length * sizeof(TestObject *));
    a[0] = new_TestObject(new_String("first"), 3);
    a[1] = new_TestObject(new_String("second"), 2);
    a[2] = new_TestObject(new_String("third"), 8);
    a[3] = new_TestObject(new_String("fourth"), 7);
    a[4] = new_TestObject(new_String("fifth"), 6);
    b = NULL;
    c = Arrays_equalsObj(a, length, b, 0, equalsTo);
    assertEqualsBool(false, c);
    b = malloc(length2 * sizeof(TestObject *));
    b[0] = new_TestObject(new_String("first"), 3);
    c = Arrays_equalsObj(a, length, b, length2, equalsTo);
    assertEqualsBool(false, c);
    b = malloc(length * sizeof(TestObject *));
    b[0] = new_TestObject(new_String("first"), 3);
    b[1] = new_TestObject(new_String("second"), 2);
    b[2] = new_TestObject(new_String("third"), 8);
    b[3] = new_TestObject(new_String("fourth"), 7);
    b[4] = new_TestObject(new_String("fifth"), 3);
    c = Arrays_equalsObj(a, length, b, length, equalsTo);
    assertEqualsBool(false, c);
    b = malloc(length * sizeof(TestObject *));
    b[0] = new_TestObject(new_String("sixth"), 3);
    b[1] = new_TestObject(new_String("seventh"), 2);
    b[2] = new_TestObject(new_String("eighth"), 8);
    b[3] = new_TestObject(new_String("nineth"), 7);
    b[4] = new_TestObject(new_String("tenth"), 6);
    c = Arrays_equalsObj(a, length, b, length, equalsTo);
    assertEqualsBool(false, c);
    b = a;
    c = Arrays_equalsObj(a, length, b, length, equalsTo);
    assertEqualsBool(true, c);
}

/**
 * Tests the equals function with array of shorts.
 */

void equalsTest9() {
    const int32_t length = 5;
    const int32_t length2 = 1;
    int16_t *a, *b;
    bool c;
    a = malloc(length * sizeof(int16_t));
    a[0] = (int16_t) 3;
    a[1] = (int16_t) 2;
    a[2] = (int16_t) 8;
    a[3] = (int16_t) 7;
    a[4] = (int16_t) 6;
    b = NULL;
    c = Arrays_equalsS(a, length, b, 0);
    assertEqualsBool(false, c);
    b = malloc(length2 * sizeof(int16_t));
    b[0] = (int16_t) 3;
    c = Arrays_equalsS(a, length, b, length2);
    assertEqualsBool(false, c);
    b = malloc(length * sizeof(int16_t));
    b[0] = (int16_t) 3;
    b[1] = (int16_t) 2;
    b[2] = (int16_t) 8;
    b[3] = (int16_t) 7;
    b[4] = (int16_t) 3;
    c = Arrays_equalsS(a, length, b, length);
    assertEqualsBool(false, c);
    b = malloc(length * sizeof(int16_t));
    b[0] = (int16_t) 3;
    b[1] = (int16_t) 2;
    b[2] = (int16_t) 8;
    b[3] = (int16_t) 7;
    b[4] = (int16_t) 6;
    c = Arrays_equalsS(a, length, b, length);
    assertEqualsBool(true, c);
    b = a;
    c = Arrays_equalsS(a, length, b, length);
    assertEqualsBool(true, c);
}

/**
 * Tests the fill function with array of booleans.
 */

void fillTest() {
    const int32_t length = 5;
    bool *a, *c;
    bool b;
    // the array for filling
    a = malloc(5 * sizeof(bool));
    Arrays_fillBool(a, length, true);
    c = malloc(length * sizeof(bool));
    c[0] = true;
    c[1] = true;
    c[2] = true;
    c[3] = true;
    c[4] = true;
    b = Arrays_equalsBool(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the fill function with array of booleans and indexes as parameters.
 */

void fillTest2() {
    const int32_t length = 5;
    bool *a, *c;
    bool b;
    // the array for partial filling
    a = malloc(5 * sizeof(bool));
    Arrays_fillRangeBool(a, 1, 4, true);
    c = malloc(length * sizeof(bool));
    c[0] = false;
    c[1] = true;
    c[2] = true;
    c[3] = true;
    c[4] = false;
    b = Arrays_equalsBool(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the fill function with array of bytes.
 */

void fillTest3() {
    const int32_t length = 5;
    int8_t *a, *c;
    bool b;
    a = malloc(5 * sizeof(int8_t));
    Arrays_fillB(a, length, (int8_t) 8);
    c = malloc(length * sizeof(int8_t));
    c[0] = (int8_t) 8;
    c[1] = (int8_t) 8;
    c[2] = (int8_t) 8;
    c[3] = (int8_t) 8;
    c[4] = (int8_t) 8;
    b = Arrays_equalsB(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the fill function with array of bytes and indexes as parameters.
 */

void fillTest4() {
    const int32_t length = 5;
    int8_t *a, *c;
    bool b;
    a = malloc(5 * sizeof(int8_t));
    Arrays_fillRangeB(a, 1, 4, (int8_t) 8);
    c = malloc(length * sizeof(int8_t));
    c[0] = (int8_t) 0;
    c[1] = (int8_t) 8;
    c[2] = (int8_t) 8;
    c[3] = (int8_t) 8;
    c[4] = (int8_t) 0;
    b = Arrays_equalsB(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the fill function with array of chars.
 */

void fillTest5() {
    const int32_t length = 5;
    char *a, *c;
    bool b;
    a = malloc(5 * sizeof(char));
    Arrays_fillC(a, length, 'h');
    c = malloc(length * sizeof(char));
    c[0] = 'h';
    c[1] = 'h';
    c[2] = 'h';
    c[3] = 'h';
    c[4] = 'h';
    b = Arrays_equalsC(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the fill function with array of chars and indexes as parameters.
 */

void fillTest6() {
    const int32_t length = 5;
    char *a, *c;
    bool b;
    a = malloc(5 * sizeof(char));
    Arrays_fillRangeC(a, 1, 4, 'h');
    c = malloc(length * sizeof(char));
    c[0] = '\0';
    c[1] = 'h';
    c[2] = 'h';
    c[3] = 'h';
    c[4] = '\0';
    b = Arrays_equalsC(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the fill function with array of doubles.
 */

void fillTest7() {
    const int32_t length = 5;
    double *a, *c;
    bool b;
    a = malloc(5 * sizeof(double));
    Arrays_fillD(a, length, 8.0);
    c = malloc(length * sizeof(double));
    c[0] = 8.0;
    c[1] = 8.0;
    c[2] = 8.0;
    c[3] = 8.0;
    c[4] = 8.0;
    b = Arrays_equalsD(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the fill function with array of doubles and indexes as parameters.
 */

void fillTest8() {
    const int32_t length = 5;
    double *a, *c;
    bool b;
    a = malloc(5 * sizeof(double));
    Arrays_fillRangeD(a, 1, 4, 8.0);
    c = malloc(length * sizeof(double));
    c[0] = 0.0;
    c[1] = 8.0;
    c[2] = 8.0;
    c[3] = 8.0;
    c[4] = 0.0;
    b = Arrays_equalsD(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the fill function with array of floats.
 */

void fillTest9() {
    const int32_t length = 5;
    float *a, *c;
    bool b;
    a = malloc(5 * sizeof(float));
    Arrays_fillF(a, length, 8.0F);
    c = malloc(length * sizeof(float));
    c[0] = 8.0F;
    c[1] = 8.0F;
    c[2] = 8.0F;
    c[3] = 8.0F;
    c[4] = 8.0F;
    b = Arrays_equalsF(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the fill function with array of floats and indexes as parameters.
 */

void fillTest10() {
    const int32_t length = 5;
    float *a, *c;
    bool b;
    a = malloc(5 * sizeof(float));
    Arrays_fillRangeF(a, 1, 4, 8.0F);
    c = malloc(length * sizeof(float));
    c[0] = 0.0F;
    c[1] = 8.0F;
    c[2] = 8.0F;
    c[3] = 8.0F;
    c[4] = 0.0F;
    b = Arrays_equalsF(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the fill function with array of ints.
 */

void fillTest11() {
    const int32_t length = 5;
    int32_t *a, *c;
    bool b;
    a = malloc(5 * sizeof(int32_t));
    Arrays_fillI(a, length, 8);
    c = malloc(length * sizeof(int32_t));
    c[0] = 8;
    c[1] = 8;
    c[2] = 8;
    c[3] = 8;
    c[4] = 8;
    b = Arrays_equalsI(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the fill function with array of ints and indexes as parameters.
 */

void fillTest12() {
    const int32_t length = 5;
    int32_t *a, *c;
    bool b;
    a = malloc(5 * sizeof(int32_t));
    Arrays_fillRangeI(a, 1, 4, 8);
    c = malloc(length * sizeof(int32_t));
    c[0] = 0;
    c[1] = 8;
    c[2] = 8;
    c[3] = 8;
    c[4] = 0;
    b = Arrays_equalsI(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the fill function with array of longs.
 */

void fillTest13() {
    const int32_t length = 5;
    int64_t *a, *c;
    bool b;
    a = malloc(5 * sizeof(int64_t));
    Arrays_fillL(a, length, 8L);
    c = malloc(length * sizeof(int64_t));
    c[0] = 8L;
    c[1] = 8L;
    c[2] = 8L;
    c[3] = 8L;
    c[4] = 8L;
    b = Arrays_equalsL(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the fill function with array of longs and indexes as parameters.
 */

void fillTest14() {
    const int32_t length = 5;
    int64_t *a, *c;
    bool b;
    a = malloc(5 * sizeof(int64_t));
    Arrays_fillRangeL(a, 1, 4, 8L);
    c = malloc(length * sizeof(int64_t));
    c[0] = 0L;
    c[1] = 8L;
    c[2] = 8L;
    c[3] = 8L;
    c[4] = 0L;
    b = Arrays_equalsL(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the fill function with array of structures.
 */

void fillTest15() {
    const int32_t length = 5;
    TestObject **a, **c;
    bool b;
    a = malloc(5 * sizeof(char));
    Arrays_fillObj((TestObject **) a, length, new_TestObject(new_String("sixth"), 6));
    c = malloc(length * sizeof(char));
    c[0] = new_TestObject(new_String("sixth"), 6);
    c[1] = new_TestObject(new_String("sixth"), 6);
    c[2] = new_TestObject(new_String("sixth"), 6);
    c[3] = new_TestObject(new_String("sixth"), 6);
    c[4] = new_TestObject(new_String("sixth"), 6);
    b = Arrays_equalsObj((TestObject **) a, length, (TestObject **) c, length, equalsTo);
    assertEqualsBool(true, b);
}

/**
 * Tests the fill function with array of structures and indexes as parameters.
 */

void fillTest16() {
    const int32_t length = 5;
    TestObject **a, **c;
    bool b;
    a = malloc(5 * sizeof(char));
    Arrays_fillRangeObj((TestObject **) a, 1, 4, new_TestObject(new_String("sixth"), 6));
    c = malloc(length * sizeof(char));
    c[0] = NULL;
    c[1] = new_TestObject(new_String("sixth"), 6);
    c[2] = new_TestObject(new_String("sixth"), 6);
    c[3] = new_TestObject(new_String("sixth"), 6);
    c[4] = NULL;
    b = Arrays_equalsObj((TestObject **) a, length, (TestObject **) c, length, equalsTo);
    assertEqualsBool(true, b);
}

/**
 * Tests the fill function with array of shorts.
 */

void fillTest17() {
    const int32_t length = 5;
    int16_t *a, *c;
    bool b;
    a = malloc(5 * sizeof(int16_t));
    Arrays_fillS(a, length, (int16_t) 8);
    c = malloc(length * sizeof(int16_t));
    c[0] = (int16_t) 8;
    c[1] = (int16_t) 8;
    c[2] = (int16_t) 8;
    c[3] = (int16_t) 8;
    c[4] = (int16_t) 8;
    b = Arrays_equalsS(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the fill function with array of shorts and indexes as parameters.
 */

void fillTest18() {
    const int32_t length = 5;
    int16_t *a, *c;
    bool b;
    a = malloc(5 * sizeof(int16_t));
    Arrays_fillRangeS(a, 1, 4, (int16_t) 8);
    c = malloc(length * sizeof(int16_t));
    c[0] = (int16_t) 0;
    c[1] = (int16_t) 8;
    c[2] = (int16_t) 8;
    c[3] = (int16_t) 8;
    c[4] = (int16_t) 0;
    b = Arrays_equalsS(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the sort function with array of bytes.
 */

void sortTest() {
    const int32_t length = 5;
    int8_t *a, *c;
    bool b;
    // the array for sorting
    a = malloc(length * sizeof(int8_t));
    a[0] = (int8_t) 3;
    a[1] = (int8_t) 2;
    a[2] = (int8_t) 8;
    a[3] = (int8_t) 7;
    a[4] = (int8_t) 6;
    Arrays_sortB(a, length);
    c = malloc(length * sizeof(int8_t));
    c[0] = (int8_t) 2;
    c[1] = (int8_t) 3;
    c[2] = (int8_t) 6;
    c[3] = (int8_t) 7;
    c[4] = (int8_t) 8;
    b = Arrays_equalsB(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the sort function with array of bytes and indexes as parameters.
 */

void sortTest2() {
    const int32_t length = 5;
    int8_t *a, *c;
    bool b;
    // the array for partial sorting
    a = malloc(length * sizeof(int8_t));
    a[0] = (int8_t) 3;
    a[1] = (int8_t) 2;
    a[2] = (int8_t) 8;
    a[3] = (int8_t) 7;
    a[4] = (int8_t) 6;
    Arrays_sortRangeB(a, 1, 4);
    c = malloc(length * sizeof(int8_t));
    c[0] = (int8_t) 3;
    c[1] = (int8_t) 2;
    c[2] = (int8_t) 7;
    c[3] = (int8_t) 8;
    c[4] = (int8_t) 6;
    b = Arrays_equalsB(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the sort function with array of chars.
 */

void sortTest3() {
    const int32_t length = 5;
    char *a, *c;
    bool b;
    a = malloc(length * sizeof(char));
    a[0] = 'c';
    a[1] = 'b';
    a[2] = 'h';
    a[3] = 'g';
    a[4] = 'f';
    Arrays_sortC(a, length);
    c = malloc(length * sizeof(char));
    c[0] = 'b';
    c[1] = 'c';
    c[2] = 'f';
    c[3] = 'g';
    c[4] = 'h';
    b = Arrays_equalsC(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the sort function with array of chars and indexes as parameters.
 */

void sortTest4() {
    const int32_t length = 5;
    char *a, *c;
    bool b;
    a = malloc(length * sizeof(char));
    a[0] = 'c';
    a[1] = 'b';
    a[2] = 'h';
    a[3] = 'g';
    a[4] = 'f';
    Arrays_sortRangeC(a, 1, 4);
    c = malloc(length * sizeof(char));
    c[0] = 'c';
    c[1] = 'b';
    c[2] = 'g';
    c[3] = 'h';
    c[4] = 'f';
    b = Arrays_equalsC(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the sort function with array of doubles.
 */

void sortTest5() {
    const int32_t length = 5;
    double *a, *c;
    bool b;
    a = malloc(length * sizeof(double));
    a[0] = 3.0;
    a[1] = 2.0;
    a[2] = 8.0;
    a[3] = 7.0;
    a[4] = 6.0;
    Arrays_sortD(a, length);
    c = malloc(length * sizeof(double));
    c[0] = 2.0;
    c[1] = 3.0;
    c[2] = 6.0;
    c[3] = 7.0;
    c[4] = 8.0;
    b = Arrays_equalsD(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the sort function with array of doubles and indexes as parameters.
 */

void sortTest6() {
    const int32_t length = 5;
    double *a, *c;
    bool b;
    a = malloc(length * sizeof(double));
    a[0] = 3.0;
    a[1] = 2.0;
    a[2] = 8.0;
    a[3] = 7.0;
    a[4] = 6.0;
    Arrays_sortRangeD(a, 1, 4);
    c = malloc(length * sizeof(double));
    c[0] = 3.0;
    c[1] = 2.0;
    c[2] = 7.0;
    c[3] = 8.0;
    c[4] = 6.0;
    b = Arrays_equalsD(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the sort function with array of floats.
 */

void sortTest7() {
    const int32_t length = 5;
    float *a, *c;
    bool b;
    a = malloc(length * sizeof(float));
    a[0] = 3.0F;
    a[1] = 2.0F;
    a[2] = 8.0F;
    a[3] = 7.0F;
    a[4] = 6.0F;
    Arrays_sortF(a, length);
    c = malloc(length * sizeof(float));
    c[0] = 2.0F;
    c[1] = 3.0F;
    c[2] = 6.0F;
    c[3] = 7.0F;
    c[4] = 8.0F;
    b = Arrays_equalsF(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the sort function with array of floats and indexes as parameters.
 */

void sortTest8() {
    const int32_t length = 5;
    float *a, *c;
    bool b;
    a = malloc(length * sizeof(float));
    a[0] = 3.0F;
    a[1] = 2.0F;
    a[2] = 8.0F;
    a[3] = 7.0F;
    a[4] = 6.0F;
    Arrays_sortRangeF(a, 1, 4);
    c = malloc(length * sizeof(float));
    c[0] = 3.0F;
    c[1] = 2.0F;
    c[2] = 7.0F;
    c[3] = 8.0F;
    c[4] = 6.0F;
    b = Arrays_equalsF(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the sort function with array of ints.
 */

void sortTest9() {
    const int32_t length = 5;
    int32_t *a, *c;
    bool b;
    a = malloc(length * sizeof(int32_t));
    a[0] = 3;
    a[1] = 2;
    a[2] = 8;
    a[3] = 7;
    a[4] = 6;
    Arrays_sortI(a, length);
    c = malloc(length * sizeof(int32_t));
    c[0] = 2;
    c[1] = 3;
    c[2] = 6;
    c[3] = 7;
    c[4] = 8;
    b = Arrays_equalsI(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the sort function with array of ints and indexes as parameters.
 */

void sortTest10() {
    const int32_t length = 5;
    int32_t *a, *c;
    bool b;
    a = malloc(length * sizeof(int32_t));
    a[0] = 3;
    a[1] = 2;
    a[2] = 8;
    a[3] = 7;
    a[4] = 6;
    Arrays_sortRangeI(a, 1, 4);
    c = malloc(length * sizeof(int32_t));
    c[0] = 3;
    c[1] = 2;
    c[2] = 7;
    c[3] = 8;
    c[4] = 6;
    b = Arrays_equalsI(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the sort function with array of longs.
 */

void sortTest11() {
    const int32_t length = 5;
    int64_t *a, *c;
    bool b;
    a = malloc(length * sizeof(int64_t));
    a[0] = 3L;
    a[1] = 2L;
    a[2] = 8L;
    a[3] = 7L;
    a[4] = 6L;
    Arrays_sortL(a, length);
    c = malloc(length * sizeof(int64_t));
    c[0] = 2L;
    c[1] = 3L;
    c[2] = 6L;
    c[3] = 7L;
    c[4] = 8L;
    b = Arrays_equalsL(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the sort function with array of longs and indexes as parameters.
 */

void sortTest12() {
    const int32_t length = 5;
    int64_t *a, *c;
    bool b;
    a = malloc(length * sizeof(int64_t));
    a[0] = 3L;
    a[1] = 2L;
    a[2] = 8L;
    a[3] = 7L;
    a[4] = 6L;
    Arrays_sortRangeL(a, 1, 4);
    c = malloc(length * sizeof(int64_t));
    c[0] = 3L;
    c[1] = 2L;
    c[2] = 7L;
    c[3] = 8L;
    c[4] = 6L;
    b = Arrays_equalsL(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the sort function with array of structures.
 */

void sortTest13() {
    const int32_t length = 10;
    TestObject **a, **c;
    bool b;
    a = malloc(length * sizeof(TestObject *));
    a[0] = new_TestObject(new_String("first"), 3);
    a[1] = new_TestObject(new_String("second"), 2);
    a[2] = new_TestObject(new_String("third"), 8);
    a[3] = new_TestObject(new_String("fourth"), 7);
    a[4] = new_TestObject(new_String("fifth"), 6);
    a[5] = new_TestObject(new_String("sixth"), 3);
    a[6] = new_TestObject(new_String("seventh"), 2);
    a[7] = new_TestObject(new_String("eighth"), 8);
    a[8] = new_TestObject(new_String("nineth"), 7);
    a[9] = new_TestObject(new_String("tenth"), 6);
    Arrays_sortObj(a, length, compareToTo);
    c = malloc(length * sizeof(TestObject *));
    c[0] = new_TestObject(new_String("second"), 2);
    c[1] = new_TestObject(new_String("seventh"), 2);
    c[2] = new_TestObject(new_String("first"), 3);
    c[3] = new_TestObject(new_String("sixth"), 3);
    c[4] = new_TestObject(new_String("fifth"), 6);
    c[5] = new_TestObject(new_String("tenth"), 6);
    c[6] = new_TestObject(new_String("fourth"), 7);
    c[7] = new_TestObject(new_String("nineth"), 7);
    c[8] = new_TestObject(new_String("third"), 8);
    c[9] = new_TestObject(new_String("eighth"), 8);
    b = Arrays_equalsObj(a, length, c, length, equalsTo);
    assertEqualsBool(true, b);
}

/**
 * Tests the sort function with array of structures and indexes as parameters.
 */

void sortTest14() {
    const int32_t length = 10;
    TestObject **a, **c;
    bool b;
    a = malloc(length * sizeof(TestObject *));
    a[0] = new_TestObject(new_String("first"), 3);
    a[1] = new_TestObject(new_String("second"), 2);
    a[2] = new_TestObject(new_String("third"), 8);
    a[3] = new_TestObject(new_String("fourth"), 7);
    a[4] = new_TestObject(new_String("fifth"), 6);
    a[5] = new_TestObject(new_String("sixth"), 3);
    a[6] = new_TestObject(new_String("seventh"), 2);
    a[7] = new_TestObject(new_String("eighth"), 8);
    a[8] = new_TestObject(new_String("nineth"), 7);
    a[9] = new_TestObject(new_String("tenth"), 6);
    Arrays_sortRangeObj(a, 1, 4, compareToTo);
    c = malloc(length * sizeof(TestObject *));
    c[0] = new_TestObject(new_String("first"), 3);
    c[1] = new_TestObject(new_String("second"), 2);
    c[2] = new_TestObject(new_String("fourth"), 7);
    c[3] = new_TestObject(new_String("third"), 8);
    c[4] = new_TestObject(new_String("fifth"), 6);
    c[5] = new_TestObject(new_String("sixth"), 3);
    c[6] = new_TestObject(new_String("seventh"), 2);
    c[7] = new_TestObject(new_String("eighth"), 8);
    c[8] = new_TestObject(new_String("nineth"), 7);
    c[9] = new_TestObject(new_String("tenth"), 6);
    b = Arrays_equalsObj(a, length, c, length, equalsTo);
    assertEqualsBool(true, b);
}

/**
 * Tests the sort function with array of shorts.
 */

void sortTest15() {
    const int32_t length = 5;
    int16_t *a, *c;
    bool b;
    a = malloc(length * sizeof(int16_t));
    a[0] = (int16_t) 3;
    a[1] = (int16_t) 2;
    a[2] = (int16_t) 8;
    a[3] = (int16_t) 7;
    a[4] = (int16_t) 6;
    Arrays_sortS(a, length);
    c = malloc(length * sizeof(int16_t));
    c[0] = (int16_t) 2;
    c[1] = (int16_t) 3;
    c[2] = (int16_t) 6;
    c[3] = (int16_t) 7;
    c[4] = (int16_t) 8;
    b = Arrays_equalsS(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the sort function with array of shorts and indexes as parameters.
 */

void sortTest16() {
    const int32_t length = 5;
    int16_t *a, *c;
    bool b;
    a = malloc(length * sizeof(int16_t));
    a[0] = (int16_t) 3;
    a[1] = (int16_t) 2;
    a[2] = (int16_t) 8;
    a[3] = (int16_t) 7;
    a[4] = (int16_t) 6;
    Arrays_sortRangeS(a, 1, 4);
    c = malloc(length * sizeof(int16_t));
    c[0] = (int16_t) 3;
    c[1] = (int16_t) 2;
    c[2] = (int16_t) 7;
    c[3] = (int16_t) 8;
    c[4] = (int16_t) 6;
    b = Arrays_equalsS(a, length, c, length);
    assertEqualsBool(true, b);
}

/**
 * Tests the toString function with array of booleans.
 */

void toStringTest() {
    const int32_t length = 0;
    const int32_t length2 = 1;
    const int32_t length3 = 5;
    bool *a;
    String *b;
    // the text represenation of an empty array
    a = malloc(length * sizeof(bool));
    b = Arrays_toStringBool(a, length);
    assertEqualsStr("[]", b->s);
    // the text represenation of an array with one element
    a = malloc(length2 * sizeof(bool));
    a[0] = true;
    b = Arrays_toStringBool(a, length2);
    assertEqualsStr("[true]", b->s);
    // the text represenation of an array with some elements
    a = malloc(length3 * sizeof(bool));
    a[0] = true;
    a[1] = false;
    a[2] = false;
    a[3] = false;
    a[4] = true;
    b = Arrays_toStringBool(a, length3);
    assertEqualsStr("[true, false, false, false, true]", b->s);
}

/**
 * Tests the toString function with array of bytes.
 */

void toStringTest2() {
    const int32_t length = 0;
    const int32_t length2 = 1;
    const int32_t length3 = 5;
    int8_t *a;
    String *b;
    a = malloc(length * sizeof(int8_t));
    b = Arrays_toStringB(a, length);
    assertEqualsStr("[]", b->s);
    a = malloc(length2 * sizeof(int8_t));
    a[0] = (int8_t) 3;
    b = Arrays_toStringB(a, length2);
    assertEqualsStr("[3]", b->s);
    a = malloc(length3 * sizeof(int8_t));
    a[0] = (int8_t) 3;
    a[1] = (int8_t) 2;
    a[2] = (int8_t) 8;
    a[3] = (int8_t) 7;
    a[4] = (int8_t) 6;
    b = Arrays_toStringB(a, length3);
    assertEqualsStr("[3, 2, 8, 7, 6]", b->s);
}

/**
 * Tests the toString function with array of chars.
 */

void toStringTest3() {
    const int32_t length = 0;
    const int32_t length2 = 1;
    const int32_t length3 = 5;
    char *a;
    String *b;
    a = malloc(length * sizeof(char));
    b = Arrays_toStringC(a, length);
    assertEqualsStr("[]", b->s);
    a = malloc(length2 * sizeof(char));
    a[0] = 'c';
    b = Arrays_toStringC(a, length2);
    assertEqualsStr("[c]", b->s);
    a = malloc(length3 * sizeof(char));
    a[0] = 'c';
    a[1] = 'b';
    a[2] = 'h';
    a[3] = 'g';
    a[4] = 'f';
    b = Arrays_toStringC(a, length3);
    assertEqualsStr("[c, b, h, g, f]", b->s);
}

/**
 * Tests the toString function with array of doubles.
 */

void toStringTest4() {
    const int32_t length = 0;
    const int32_t length2 = 1;
    const int32_t length3 = 5;
    double *a;
    String *b;
    a = malloc(length * sizeof(double));
    b = Arrays_toStringD(a, length);
    assertEqualsStr("[]", b->s);
    a = malloc(length2 * sizeof(double));
    a[0] = 3.0;
    b = Arrays_toStringD(a, length2);
    assertEqualsStr("[3.0]", b->s);
    a = malloc(length3 * sizeof(double));
    a[0] = 3.0;
    a[1] = 2.0;
    a[2] = 8.0;
    a[3] = 7.0;
    a[4] = 6.0;
    b = Arrays_toStringD(a, length3);
    assertEqualsStr("[3.0, 2.0, 8.0, 7.0, 6.0]", b->s);
}

/**
 * Tests the toString function with array of floats.
 */

void toStringTest5() {
    const int32_t length = 0;
    const int32_t length2 = 1;
    const int32_t length3 = 5;
    float *a;
    String *b;
    a = malloc(length * sizeof(float));
    b = Arrays_toStringF(a, length);
    assertEqualsStr("[]", b->s);
    a = malloc(length2 * sizeof(float));
    a[0] = 3.0F;
    b = Arrays_toStringF(a, length2);
    assertEqualsStr("[3.0]", b->s);
    a = malloc(length3 * sizeof(float));
    a[0] = 3.0F;
    a[1] = 2.0F;
    a[2] = 8.0F;
    a[3] = 7.0F;
    a[4] = 6.0F;
    b = Arrays_toStringF(a, length3);
    assertEqualsStr("[3.0, 2.0, 8.0, 7.0, 6.0]", b->s);
}

/**
 * Tests the toString function with array of ints.
 */

void toStringTest6() {
    const int32_t length = 0;
    const int32_t length2 = 1;
    const int32_t length3 = 5;
    int32_t *a;
    String *b;
    a = malloc(length * sizeof(int32_t));
    b = Arrays_toStringI(a, length);
    assertEqualsStr("[]", b->s);
    a = malloc(length2 * sizeof(int32_t));
    a[0] = 3;
    b = Arrays_toStringI(a, length2);
    assertEqualsStr("[3]", b->s);
    a = malloc(length3 * sizeof(int32_t));
    a[0] = 3;
    a[1] = 2;
    a[2] = 8;
    a[3] = 7;
    a[4] = 6;
    b = Arrays_toStringI(a, length3);
    assertEqualsStr("[3, 2, 8, 7, 6]", b->s);
}

/**
 * Tests the toString function with array of longs.
 */

void toStringTest7() {
    const int32_t length = 0;
    const int32_t length2 = 1;
    const int32_t length3 = 5;
    int64_t *a;
    String *b;
    a = malloc(length * sizeof(int64_t));
    b = Arrays_toStringL(a, length);
    assertEqualsStr("[]", b->s);
    a = malloc(length2 * sizeof(int64_t));
    a[0] = 3L;
    b = Arrays_toStringL(a, length2);
    assertEqualsStr("[3]", b->s);
    a = malloc(length3 * sizeof(int64_t));
    a[0] = 3L;
    a[1] = 2L;
    a[2] = 8L;
    a[3] = 7L;
    a[4] = 6L;
    b = Arrays_toStringL(a, length3);
    assertEqualsStr("[3, 2, 8, 7, 6]", b->s);
}

/**
 * Tests the toString function with array of structures.
 */

void toStringTest8() {
    const int32_t length = 0;
    const int32_t length2 = 1;
    const int32_t length3 = 3;
    TestObject **a;
    String *b;
    a = malloc(length * sizeof(TestObject *));
    b = Arrays_toStringObj(a, length, toStringTo);
    assertEqualsStr("[]", b->s);
    a = malloc(length2 * sizeof(TestObject *));
    a[0] = new_TestObject(new_String("first"), 1);
    b = Arrays_toStringObj(a, length2, toStringTo);
    assertEqualsStr("[TestObject[str = first, i = 1]]", b->s);
    a = malloc(length2 * sizeof(TestObject *));
    a[0] = NULL;
    b = Arrays_toStringObj(a, length2, toStringTo);
    assertEqualsStr("[NULL]", b->s);
    a = malloc(length3 * sizeof(TestObject *));
    a[0] = new_TestObject(new_String("first"), 1);
    a[1] = new_TestObject(new_String("second"), 2);
    a[2] = new_TestObject(new_String("third"), 3);
    b = Arrays_toStringObj(a, length3, toStringTo);
    assertEqualsStr("[TestObject[str = first, i = 1], TestObject[str = second, i = 2], TestObject[str = third, i = 3]]", b->s);
    a = malloc(length3 * sizeof(TestObject *));
    a[0] = new_TestObject(new_String("first"), 1);
    a[1] = NULL;
    a[2] = new_TestObject(new_String("third"), 3);
    b = Arrays_toStringObj(a, length3, toStringTo);
    assertEqualsStr("[TestObject[str = first, i = 1], NULL, TestObject[str = third, i = 3]]", b->s);
    a = malloc(length3 * sizeof(TestObject *));
    a[0] = NULL;
    a[1] = NULL;
    a[2] = NULL;
    b = Arrays_toStringObj(a, length3, toStringTo);
    assertEqualsStr("[NULL, NULL, NULL]", b->s);
}

/**
 * Tests the toString function with array of shorts.
 */

void toStringTest9() {
    const int32_t length = 0;
    const int32_t length2 = 1;
    const int32_t length3 = 5;
    int16_t *a;
    String *b;
    a = malloc(length * sizeof(int16_t));
    b = Arrays_toStringS(a, length);
    assertEqualsStr("[]", b->s);
    a = malloc(length2 * sizeof(int16_t));
    a[0] = (int16_t) 3;
    b = Arrays_toStringS(a, length2);
    assertEqualsStr("[3]", b->s);
    a = malloc(length3 * sizeof(int16_t));
    a[0] = (int16_t) 3;
    a[1] = (int16_t) 2;
    a[2] = (int16_t) 8;
    a[3] = (int16_t) 7;
    a[4] = (int16_t) 6;
    b = Arrays_toStringS(a, length3);
    assertEqualsStr("[3, 2, 8, 7, 6]", b->s);
}

int main(int argc, char** argv) {
    const int testCount = 86;
    setUpTestModule("ArraysTest", testCount);

    registerTest(binarySearchTest, "binarySearchTest");
    registerTest(binarySearchTest2, "binarySearchTest2");
    registerTest(binarySearchTest3, "binarySearchTest3");
    registerTest(binarySearchTest4, "binarySearchTest4");
    registerTest(binarySearchTest5, "binarySearchTest5");
    registerTest(binarySearchTest6, "binarySearchTest6");
    registerTest(binarySearchTest7, "binarySearchTest7");
    registerTest(binarySearchTest8, "binarySearchTest8");
    registerTest(binarySearchTest9, "binarySearchTest9");
    registerTest(binarySearchTest10, "binarySearchTest10");
    registerTest(binarySearchTest11, "binarySearchTest11");
    registerTest(binarySearchTest12, "binarySearchTest12");
    registerTest(binarySearchTest13, "binarySearchTest13");
    registerTest(binarySearchTest14, "binarySearchTest14");
    registerTest(binarySearchTest15, "binarySearchTest15");
    registerTest(binarySearchTest16, "binarySearchTest16");
    registerTest(copyOfTest, "copyOfTest");
    registerTest(copyOfTest2, "copyOfTest2");
    registerTest(copyOfTest3, "copyOfTest3");
    registerTest(copyOfTest4, "copyOfTest4");
    registerTest(copyOfTest5, "copyOfTest5");
    registerTest(copyOfTest6, "copyOfTest6");
    registerTest(copyOfTest7, "copyOfTest7");
    registerTest(copyOfTest8, "copyOfTest8");
    registerTest(copyOfTest9, "copyOfTest9");
    registerTest(copyOfRangeTest1, "copyOfRangeTest1");
    registerTest(copyOfRangeTest2, "copyOfRangeTest2");
    registerTest(copyOfRangeTest3, "copyOfRangeTest3");
    registerTest(copyOfRangeTest4, "copyOfRangeTest4");
    registerTest(copyOfRangeTest5, "copyOfRangeTest5");
    registerTest(copyOfRangeTest6, "copyOfRangeTest6");
    registerTest(copyOfRangeTest7, "copyOfRangeTest7");
    registerTest(copyOfRangeTest8, "copyOfRangeTest8");
    registerTest(copyOfRangeTest9, "copyOfRangeTest9");
    registerTest(equalsTest, "equalsTest");
    registerTest(equalsTest2, "equalsTest2");
    registerTest(equalsTest3, "equalsTest3");
    registerTest(equalsTest4, "equalsTest4");
    registerTest(equalsTest5, "equalsTest5");
    registerTest(equalsTest6, "equalsTest6");
    registerTest(equalsTest7, "equalsTest7");
    registerTest(equalsTest8, "equalsTest8");
    registerTest(equalsTest9, "equalsTest9");
    registerTest(fillTest, "fillTest");
    registerTest(fillTest2, "fillTest2");
    registerTest(fillTest3, "fillTest3");
    registerTest(fillTest4, "fillTest4");
    registerTest(fillTest5, "fillTest5");
    registerTest(fillTest6, "fillTest6");
    registerTest(fillTest7, "fillTest7");
    registerTest(fillTest8, "fillTest8");
    registerTest(fillTest9, "fillTest9");
    registerTest(fillTest10, "fillTest10");
    registerTest(fillTest11, "fillTest11");
    registerTest(fillTest12, "fillTest12");
    registerTest(fillTest13, "fillTest13");
    registerTest(fillTest14, "fillTest14");
    registerTest(fillTest15, "fillTest15");
    registerTest(fillTest16, "fillTest16");
    registerTest(fillTest17, "fillTest17");
    registerTest(fillTest18, "fillTest18");
    registerTest(sortTest, "sortTest");
    registerTest(sortTest2, "sortTest2");
    registerTest(sortTest3, "sortTest3");
    registerTest(sortTest4, "sortTest4");
    registerTest(sortTest5, "sortTest5");
    registerTest(sortTest6, "sortTest6");
    registerTest(sortTest7, "sortTest7");
    registerTest(sortTest8, "sortTest8");
    registerTest(sortTest9, "sortTest9");
    registerTest(sortTest10, "sortTest10");
    registerTest(sortTest11, "sortTest11");
    registerTest(sortTest12, "sortTest12");
    registerTest(sortTest13, "sortTest13");
    registerTest(sortTest14, "sortTest14");
    registerTest(sortTest15, "sortTest15");
    registerTest(sortTest16, "sortTest16");
    registerTest(toStringTest, "toStringTest");
    registerTest(toStringTest2, "toStringTest2");
    registerTest(toStringTest3, "toStringTest3");
    registerTest(toStringTest4, "toStringTest4");
    registerTest(toStringTest5, "toStringTest5");
    registerTest(toStringTest6, "toStringTest6");
    registerTest(toStringTest7, "toStringTest7");
    registerTest(toStringTest8, "toStringTest8");
    registerTest(toStringTest9, "toStringTest9");

    runTests();

    return (EXIT_SUCCESS);
}
