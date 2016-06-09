#include <stdio.h>
#include <stdlib.h>

#include "test.h"
#include "Collections.h"
#include "TestObject.h"
/*
 * Simple C Test Suite
 */

/**
 * Tests the binarySearch function.
 */

void binarySearchTest() {
    ArrayList *a;
    int32_t b;
    a = new_ArrayList();
    addAl(a, new_TestObject(new_String("first"), 3));
    addAl(a, new_TestObject(new_String("second"), 2));
    addAl(a, new_TestObject(new_String("third"), 8));
    addAl(a, new_TestObject(new_String("fourth"), 7));
    addAl(a, new_TestObject(new_String("fifth"), 6));
    addAl(a, new_TestObject(new_String("sixth"), 3));
    addAl(a, new_TestObject(new_String("seventh"), 2));
    addAl(a, new_TestObject(new_String("eighth"), 8));
    addAl(a, new_TestObject(new_String("nineth"), 7));
    addAl(a, new_TestObject(new_String("tenth"), 6));
    Collections_sort(a, compareToTo);
    b = Collections_binarySearch(a, new_TestObject(new_String("sixth"), 6), compareToTo);
    assertEqualsI(4, b);
    b = Collections_binarySearch(a, new_TestObject(new_String("sixth"), 4), compareToTo);
    assertEqualsI(-5, b);
}

/**
 * Tests the copy function.
 */

void copyTest() {
    ArrayList *a, *b, *c;
    bool d;
    // source list
    a = new_ArrayList();
    addAl(a, new_TestObject(new_String("first"), 3));
    addAl(a, new_TestObject(new_String("second"), 2));
    addAl(a, new_TestObject(new_String("third"), 8));
    addAl(a, new_TestObject(new_String("fourth"), 7));
    addAl(a, new_TestObject(new_String("fifth"), 6));
    // destination list
    b = new_ArrayList();
    addAl(b, new_TestObject(new_String("zeroth"), 0));
    addAl(b, new_TestObject(new_String("zeroth"), 0));
    addAl(b, new_TestObject(new_String("zeroth"), 0));
    addAl(b, new_TestObject(new_String("zeroth"), 0));
    addAl(b, new_TestObject(new_String("zeroth"), 0));
    addAl(b, new_TestObject(new_String("zeroth"), 0));
    Collections_copy(b, a, sizeAl, setAl, getAl);
    c = new_ArrayList();
    addAl(c, new_TestObject(new_String("first"), 3));
    addAl(c, new_TestObject(new_String("second"), 2));
    addAl(c, new_TestObject(new_String("third"), 8));
    addAl(c, new_TestObject(new_String("fourth"), 7));
    addAl(c, new_TestObject(new_String("fifth"), 6));
    addAl(c, new_TestObject(new_String("zeroth"), 0));
    d = equalsList(c, sizeAl, getAl, b, sizeAl, getAl, equalsTo);
    assertEqualsBool(true, d);
}

/**
 * Tests the fill function.
 */

void fillTest() {
    ArrayList *a, *b;
    bool d;
    a = new_ArrayList();
    addAl(a, new_TestObject(new_String("first"), 3));
    addAl(a, new_TestObject(new_String("second"), 2));
    addAl(a, new_TestObject(new_String("third"), 8));
    addAl(a, new_TestObject(new_String("fourth"), 7));
    addAl(a, new_TestObject(new_String("fifth"), 6));
    Collections_fill(a, new_TestObject(new_String("sixth"), 6), sizeAl, setAl);
    b = new_ArrayList();
    addAl(b, new_TestObject(new_String("sixth"), 6));
    addAl(b, new_TestObject(new_String("sixth"), 6));
    addAl(b, new_TestObject(new_String("sixth"), 6));
    addAl(b, new_TestObject(new_String("sixth"), 6));
    addAl(b, new_TestObject(new_String("sixth"), 6));
    d = equalsList(b, sizeAl, getAl, a, sizeAl, getAl, equalsTo);
    assertEqualsBool(true, d);
}

/**
 * Tests the sort function.
 */

void sortTest() {
    ArrayList *a, *b;
    bool d;
    a = new_ArrayList();
    addAl(a, new_TestObject(new_String("first"), 3));
    addAl(a, new_TestObject(new_String("second"), 2));
    addAl(a, new_TestObject(new_String("third"), 8));
    addAl(a, new_TestObject(new_String("fourth"), 7));
    addAl(a, new_TestObject(new_String("fifth"), 6));
    addAl(a, new_TestObject(new_String("sixth"), 3));
    addAl(a, new_TestObject(new_String("seventh"), 2));
    addAl(a, new_TestObject(new_String("eighth"), 8));
    addAl(a, new_TestObject(new_String("nineth"), 7));
    addAl(a, new_TestObject(new_String("tenth"), 6));
    Collections_sort(a, compareToTo);
    b = new_ArrayList();
    addAl(b, new_TestObject(new_String("second"), 2));
    addAl(b, new_TestObject(new_String("seventh"), 2));
    addAl(b, new_TestObject(new_String("first"), 3));
    addAl(b, new_TestObject(new_String("sixth"), 3));
    addAl(b, new_TestObject(new_String("fifth"), 6));
    addAl(b, new_TestObject(new_String("tenth"), 6));
    addAl(b, new_TestObject(new_String("fourth"), 7));
    addAl(b, new_TestObject(new_String("nineth"), 7));
    addAl(b, new_TestObject(new_String("third"), 8));
    addAl(b, new_TestObject(new_String("eighth"), 8));
    d = equalsList(b, sizeAl, getAl, a, sizeAl, getAl, equalsTo);
    assertEqualsBool(true, d);
}

int main(int argc, char** argv) {
    const int testCount = 4;
    setUpTestModule("CollectionsTest", testCount);

    registerTest(binarySearchTest, "binarySearchTest");
    registerTest(copyTest, "copyTest");
    registerTest(fillTest, "fillTest");
    registerTest(sortTest, "sortTest");
    
    runTests();

    return (EXIT_SUCCESS);
}
