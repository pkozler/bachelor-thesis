#include <stdio.h>
#include <stdlib.h>

#include "test.h"
#include "ArrayList.h"
#include "TestObject.h"

/**
 * An ArrayList module test suite.
 *
 * @author Petr Kozler (A13B0359P)
 */

/*
    Creates the array list from array.
 */
ArrayList *toList(TestObject **array, int32_t length) {
    ArrayList *list = new_ArrayList();

    int32_t i;
    for (i = 0; i < length; i++) {
        addAl(list, array[i]);
    }
    
    return list;
}

/**
 * Tests the constructor.
 */

void arrayListTest() {
    const int32_t length = 0;
    ArrayList *a;
    bool b;
    TestObject **c;
    // empty list
    a = new_ArrayList();
    c = malloc(length * sizeof(TestObject *));
    b = equalsList(a, sizeAl, getAl, toList(c, length), sizeAl, getAl, equalsTo);
    assertEqualsBool(true, b);
}

/**
 * Tests the constructor with ArrayList as a parameter.
 */

void arrayListTest2() {
    const int32_t length = 0;
    const int32_t length2 = 1;
    const int32_t length3 = 3;
    ArrayList *a, *b;
    TestObject *c;
    bool d;
    TestObject **e;
    // creating the list from an empty list
    a = new_ArrayList();
    b = new_ArrayListAddAll(a);
    e = malloc(length * sizeof(TestObject *));
    d = equalsList(b, sizeAl, getAl, toList(e, length), sizeAl, getAl, equalsTo);
    assertEqualsBool(true, d);
    // creating the list from a list with one element
    a = new_ArrayList();
    c = new_TestObject(new_String("first"), 1);
    addAl(a, c);
    b = new_ArrayListAddAll(a);
    e = malloc(length2 * sizeof(TestObject *));
    e[0] = new_TestObject(new_String("first"), 1);
    d = equalsList(b, sizeAl, getAl, toList(e, length2), sizeAl, getAl, equalsTo);
    assertEqualsBool(true, d);
    // creating the list from a list with some elements
    a = new_ArrayList();
    e = malloc(length3 * sizeof(TestObject *));
    e[0] = new_TestObject(new_String("first"), 1);
    e[1] = new_TestObject(new_String("second"), 2);
    e[2] = new_TestObject(new_String("third"), 3);
    c = new_TestObject(new_String("first"), 1);
    addAl(a, c);
    c = new_TestObject(new_String("second"), 2);
    addAl(a, c);
    c = new_TestObject(new_String("third"), 3);
    addAl(a, c);
    b = new_ArrayListAddAll(a);
    d = equalsList(b, sizeAl, getAl, toList(e, length3), sizeAl, getAl, equalsTo);
    assertEqualsBool(true, d);
}

/**
 * Tests the addAl function.
 */

void addTest() {
    const int32_t length = 1;
    const int32_t length2 = 2;
    const int32_t length3 = 3;
    const int32_t length4 = 4;
    const int32_t length5 = 5;
    ArrayList *a;
    TestObject **d;
    TestObject *b;
    bool c;
    // adding some elements at the end of the list
    a = new_ArrayList();
    b = new_TestObject(new_String("first"), 1);
    addAl(a, b);
    d = malloc(length * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("first"), 1);
    c = equalsList(a, sizeAl, getAl, toList(d, length), sizeAl, getAl, equalsTo);
    assertEqualsBool(true, c);
    b = new_TestObject(new_String("second"), 2);
    addAl(a, b);
    d = malloc(length2 * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("first"), 1);
    d[1] = new_TestObject(new_String("second"), 2);
    c = equalsList(a, sizeAl, getAl, toList(d, length2), sizeAl, getAl, equalsTo);
    assertEqualsBool(true, c);
    b = new_TestObject(new_String("first"), 2);
    addAl(a, b);
    d = malloc(length3 * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("first"), 1);
    d[1] = new_TestObject(new_String("second"), 2);
    d[2] = new_TestObject(new_String("first"), 2);
    c = equalsList(a, sizeAl, getAl, toList(d, length3), sizeAl, getAl, equalsTo);
    assertEqualsBool(true, c);
    b = new_TestObject(new_String("second"), 1);
    addAl(a, b);
    d = malloc(length4 * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("first"), 1);
    d[1] = new_TestObject(new_String("second"), 2);
    d[2] = new_TestObject(new_String("first"), 2);
    d[3] = new_TestObject(new_String("second"), 1);
    c = equalsList(a, sizeAl, getAl, toList(d, length4), sizeAl, getAl, equalsTo);
    assertEqualsBool(true, c);
    b = new_TestObject(new_String("first"), 1);
    addAl(a, b);
    d = malloc(length5 * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("first"), 1);
    d[1] = new_TestObject(new_String("second"), 2);
    d[2] = new_TestObject(new_String("first"), 2);
    d[3] = new_TestObject(new_String("second"), 1);
    d[4] = new_TestObject(new_String("first"), 1);
    c = equalsList(a, sizeAl, getAl, toList(d, length5), sizeAl, getAl, equalsTo);
    assertEqualsBool(true, c);
}

/**
 * Tests the addAl function with index as a parameter.
 */

void addTest2() {
    const int32_t length = 1;
    const int32_t length2 = 2;
    const int32_t length3 = 3;
    const int32_t length4 = 4;
    const int32_t length5 = 5;
    ArrayList *a;
    TestObject *b;
    bool c;
    TestObject **d;
    a = new_ArrayList();
    // adding an element at the beginning
    b = new_TestObject(new_String("first"), 1);
    addAtAl(a, 0, b);
    d = malloc(length * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("first"), 1);
    c = equalsList(a, sizeAl, getAl, toList(d, length), sizeAl, getAl, equalsTo);
    assertEqualsBool(true, c);
    // adding an element at the end
    b = new_TestObject(new_String("second"), 2);
    addAtAl(a, 1, b);
    d = malloc(length2 * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("first"), 1);
    d[1] = new_TestObject(new_String("second"), 2);
    c = equalsList(a, sizeAl, getAl, toList(d, length2), sizeAl, getAl, equalsTo);
    assertEqualsBool(true, c);
    // adding an element at the beginning
    b = new_TestObject(new_String("third"), 3);
    addAtAl(a, 0, b);
    d = malloc(length3 * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("third"), 3);
    d[1] = new_TestObject(new_String("first"), 1);
    d[2] = new_TestObject(new_String("second"), 2);
    c = equalsList(a, sizeAl, getAl, toList(d, length3), sizeAl, getAl, equalsTo);
    assertEqualsBool(true, c);
    // adding an element in the middle
    b = new_TestObject(new_String("fourth"), 4);
    addAtAl(a, 1, b);
    d = malloc(length4 * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("third"), 3);
    d[1] = new_TestObject(new_String("fourth"), 4);
    d[2] = new_TestObject(new_String("first"), 1);
    d[3] = new_TestObject(new_String("second"), 2);
    c = equalsList(a, sizeAl, getAl, toList(d, length4), sizeAl, getAl, equalsTo);
    assertEqualsBool(true, c);
    // adding an element in the middle
    b = new_TestObject(new_String("fifth"), 5);
    addAtAl(a, 2, b);
    d = malloc(length5 * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("third"), 3);
    d[1] = new_TestObject(new_String("fourth"), 4);
    d[2] = new_TestObject(new_String("fifth"), 5);
    d[3] = new_TestObject(new_String("first"), 1);
    d[4] = new_TestObject(new_String("second"), 2);
    c = equalsList(a, sizeAl, getAl, toList(d, length5), sizeAl, getAl, equalsTo);
    assertEqualsBool(true, c);
}

/**
 * Tests the equalsList function.
 */

void equalsTest() {
    const int32_t length = 5;
    const int32_t length2 = 1;
    ArrayList *a, *b;
    bool c;
    TestObject **d;
    d = malloc(length * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("first"), 3);
    d[1] = new_TestObject(new_String("second"), 2);
    d[2] = new_TestObject(new_String("third"), 8);
    d[3] = new_TestObject(new_String("fourth"), 7);
    d[4] = new_TestObject(new_String("fifth"), 6);
    a = toList(d, length);
    b = NULL;
    c = equalsList(a, sizeAl, getAl, b, sizeAl, getAl, equalsTo);
    assertEqualsBool(false, c);
    d = malloc(length2 * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("first"), 3);
    b = toList(d, length2);
    c = equalsList(a, sizeAl, getAl, b, sizeAl, getAl, equalsTo);
    assertEqualsBool(false, c);
    d = malloc(length * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("first"), 3);
    d[1] = new_TestObject(new_String("second"), 2);
    d[2] = new_TestObject(new_String("third"), 8);
    d[3] = new_TestObject(new_String("fourth"), 7);
    d[4] = new_TestObject(new_String("fifth"), 3);
    b = toList(d, length);
    c = equalsList(a, sizeAl, getAl, b, sizeAl, getAl, equalsTo);
    assertEqualsBool(false, c);
    d = malloc(length * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("sixth"), 3);
    d[1] = new_TestObject(new_String("seventh"), 2);
    d[2] = new_TestObject(new_String("eighth"), 8);
    d[3] = new_TestObject(new_String("nineth"), 7);
    d[4] = new_TestObject(new_String("tenth"), 6);
    b = toList(d, length);
    c = equalsList(a, sizeAl, getAl, b, sizeAl, getAl, equalsTo);
    assertEqualsBool(true, c);
    b = a;
    c = equalsList(a, sizeAl, getAl, b, sizeAl, getAl, equalsTo);
    assertEqualsBool(true, c);
}

/**
 * Tests the getAl function.
 */

void getTest() {
    ArrayList *a;
    TestObject *b;
    bool c;
    a = new_ArrayList();
    // getting an element from the beginning
    b = new_TestObject(new_String("first"), 1);
    addAl(a, b);
    b = getAl(a, 0);
    c = equalsTo(b, new_TestObject(new_String("first"), 1));
    assertEqualsBool(true, c);
    // getting an element from the beginning (more elements in the list)
    b = new_TestObject(new_String("second"), 2);
    addAl(a, b);
    b = getAl(a, 0);
    c = equalsTo(b, new_TestObject(new_String("first"), 1));
    assertEqualsBool(true, c);
    // getting an element from the end
    b = getAl(a, 1);
    c = equalsTo(b, new_TestObject(new_String("second"), 2));
    assertEqualsBool(true, c);
    b = new_TestObject(new_String("third"), 3);
    addAl(a, b);
    b = new_TestObject(new_String("fourth"), 4);
    addAl(a, b);
    b = new_TestObject(new_String("fifth"), 5);
    addAl(a, b);
    // getting an element from the beginning
    b = getAl(a, 0);
    c = equalsTo(b, new_TestObject(new_String("first"), 1));
    assertEqualsBool(true, c);
    // getting an element from the end
    b = getAl(a, 4);
    c = equalsTo(b, new_TestObject(new_String("fifth"), 5));
    assertEqualsBool(true, c);
}

/**
 * Tests the setAl function.
 */

void setTest() {
    const int32_t length = 5;
    ArrayList *a;
    TestObject *b;
    bool c;
    TestObject **d;
    a = new_ArrayList();
    b = new_TestObject(new_String("first"), 1);
    addAl(a, b);
    b = new_TestObject(new_String("second"), 2);
    addAl(a, b);
    b = new_TestObject(new_String("third"), 3);
    addAl(a, b);
    b = new_TestObject(new_String("fourth"), 4);
    addAl(a, b);
    b = new_TestObject(new_String("fifth"), 5);
    addAl(a, b);
    b = new_TestObject(new_String("sixth"), 6);
    // replacing an element at the beginning
    setAl(a, 0, b);
    d = malloc(length * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("sixth"), 6);
    d[1] = new_TestObject(new_String("second"), 2);
    d[2] = new_TestObject(new_String("third"), 3);
    d[3] = new_TestObject(new_String("fourth"), 4);
    d[4] = new_TestObject(new_String("fifth"), 5);
    c = equalsList(a, sizeAl, getAl, toList(d, length), sizeAl, getAl, equalsTo);
    assertEqualsBool(true, c);
    // replacing an element in the middle
    b = new_TestObject(new_String("seventh"), 7);
    setAl(a, 2, b);
    d = malloc(length * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("sixth"), 6);
    d[1] = new_TestObject(new_String("second"), 2);
    d[2] = new_TestObject(new_String("seventh"), 7);
    d[3] = new_TestObject(new_String("fourth"), 4);
    d[4] = new_TestObject(new_String("fifth"), 5);
    c = equalsList(a, sizeAl, getAl, toList(d, length), sizeAl, getAl, equalsTo);
    assertEqualsBool(true, c);
    // replacing an element at the end
    b = new_TestObject(new_String("eighth"), 8);
    setAl(a, 4, b);
    d = malloc(length * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("sixth"), 6);
    d[1] = new_TestObject(new_String("second"), 2);
    d[2] = new_TestObject(new_String("seventh"), 7);
    d[3] = new_TestObject(new_String("fourth"), 4);
    d[4] = new_TestObject(new_String("eighth"), 8);
    c = equalsList(a, sizeAl, getAl, toList(d, length), sizeAl, getAl, equalsTo);
    assertEqualsBool(true, c);
}

/**
 * Tests the remove function.
 */

void removeTest() {
    const int32_t length = 4;
    const int32_t length2 = 3;
    const int32_t length3 = 2;
    ArrayList *a;
    TestObject *b;
    bool c;
    TestObject **d;
    a = new_ArrayList();
    b = new_TestObject(new_String("first"), 1);
    addAl(a, b);
    b = new_TestObject(new_String("second"), 2);
    addAl(a, b);
    b = new_TestObject(new_String("third"), 3);
    addAl(a, b);
    b = new_TestObject(new_String("fourth"), 4);
    addAl(a, b);
    b = new_TestObject(new_String("fifth"), 5);
    // removing an element from the beginning
    addAl(a, b);
    removeAl(a, 0);
    d = malloc(length * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("second"), 2);
    d[1] = new_TestObject(new_String("third"), 3);
    d[2] = new_TestObject(new_String("fourth"), 4);
    d[3] = new_TestObject(new_String("fifth"), 5);
    c = equalsList(a, sizeAl, getAl, toList(d, length), sizeAl, getAl, equalsTo);
    assertEqualsBool(true, c);
    // removing the element from the middle
    removeAl(a, 1);
    d = malloc(length2 * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("second"), 2);
    d[1] = new_TestObject(new_String("fourth"), 4);
    d[2] = new_TestObject(new_String("fifth"), 5);
    c = equalsList(a, sizeAl, getAl, toList(d, length2), sizeAl, getAl, equalsTo);
    assertEqualsBool(true, c);
    // removing an element from the end
    removeAl(a, 2);
    d = malloc(length3 * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("second"), 2);
    d[1] = new_TestObject(new_String("fourth"), 4);
    c = equalsList(a, sizeAl, getAl, toList(d, length3), sizeAl, getAl, equalsTo);
    assertEqualsBool(true, c);
}

/**
 * Tests the size function.
 */

void sizeTest() {
    ArrayList *a;
    TestObject *b;
    int32_t c;
    a = new_ArrayList();
    // size in the beginning
    c = sizeAl(a);
    assertEqualsI(0, c);
    b = new_TestObject(new_String("first"), 1);
    // size after adding one element
    addAl(a, b);
    c = sizeAl(a);
    assertEqualsI(1, c);
    // size after adding more elements
    b = new_TestObject(new_String("second"), 2);
    addAl(a, b);
    b = new_TestObject(new_String("third"), 3);
    addAl(a, b);
    c = sizeAl(a);
    assertEqualsI(3, c);
    // size after removing one element
    removeAl(a, 0);
    c = sizeAl(a);
    assertEqualsI(2, c);
    // size after removing more elements
    removeAl(a, 0);
    removeAl(a, 0);
    c = sizeAl(a);
    assertEqualsI(0, c);
}

/**
 * Tests the isEmpty function.
 */

void isEmptyTest() {
    ArrayList *a;
    TestObject *b;
    bool c;
    a = new_ArrayList();
    c = isEmptyAl(a);
    assertEqualsBool(true, c);
    b = new_TestObject(new_String("first"), 1);
    addAl(a, b);
    c = isEmptyAl(a);
    assertEqualsBool(false, c);
    b = new_TestObject(new_String("second"), 2);
    addAl(a, b);
    b = new_TestObject(new_String("third"), 3);
    addAl(a, b);
    c = isEmptyAl(a);
    assertEqualsBool(false, c);
    removeAl(a, 0);
    c = isEmptyAl(a);
    assertEqualsBool(false, c);
    removeAl(a, 0);
    removeAl(a, 0);
    c = isEmptyAl(a);
    assertEqualsBool(true, c);
}

/**
 * Tests the clear function.
 */

void clearTest() {
    const int32_t length = 0;
    ArrayList *a;
    TestObject *b;
    bool c;
    TestObject **d;
    d = malloc(length * sizeof(TestObject *));
    a = new_ArrayList();
    // clear in the beginning
    clearAl(a);
    c = equalsList(a, sizeAl, getAl, toList(d, length), sizeAl, getAl, equalsTo);
    assertEqualsBool(true, c);
    // clear after adding one element
    b = new_TestObject(new_String("first"), 1);
    addAl(a, b);
    clearAl(a);
    c = equalsList(a, sizeAl, getAl, toList(d, length), sizeAl, getAl, equalsTo);
    assertEqualsBool(true, c);
    // clear after adding more elements
    b = new_TestObject(new_String("first"), 1);
    addAl(a, b);
    b = new_TestObject(new_String("second"), 2);
    addAl(a, b);
    b = new_TestObject(new_String("third"), 3);
    addAl(a, b);
    clearAl(a);
    c = equalsList(a, sizeAl, getAl, toList(d, length), sizeAl, getAl, equalsTo);
    assertEqualsBool(true, c);
}

/**
 * Tests the toString function.
 */

void toStringTest() {
    ArrayList *a;
    TestObject *b;
    String *c;
    // the text representation of an empty list
    a = new_ArrayList();
    c = toStringAl(a, toStringTo);
    assertEqualsStr("[]", c->s);
    // the text representation of a list with one element
    b = new_TestObject(new_String("first"), 1);
    addAl(a, b);
    c = toStringAl(a, toStringTo);
    assertEqualsStr("[TestObject [str=first, i=1]]", c->s);
    // the text representation of a list with some elements
    b = new_TestObject(new_String("second"), 2);
    addAl(a, b);
    b = new_TestObject(new_String("third"), 3);
    addAl(a, b);
    c = toStringAl(a, toStringTo);
    assertEqualsStr("[TestObject [str=first, i=1], TestObject [str=second, i=2], TestObject [str=third, i=3]]", c->s);
}

int main(int argc, char** argv) {
    const int testCount = 12;
    setUpTestModule("ArrayListTest", testCount);

    registerTest(arrayListTest, "arrayListTest");
    registerTest(arrayListTest2, "arrayListTest2");
    registerTest(addTest, "addTest");
    registerTest(addTest2, "addTest2");
    registerTest(equalsTest, "equalsTest");
    registerTest(getTest, "getTest");
    registerTest(setTest, "setTest");
    registerTest(removeTest, "removeTest");
    registerTest(sizeTest, "sizeTest");
    registerTest(isEmptyTest, "isEmptyTest");
    registerTest(clearTest, "clearTest");
    registerTest(toStringTest, "toStringTest");
    
    runTests();

    return (EXIT_SUCCESS);
}
