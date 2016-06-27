#include <stdio.h>
#include <stdlib.h>

#include "test.h"
#include "LinkedList.h"
#include "TestObject.h"

/**
 * A LinkedList module test suite.
 *
 * @author Petr Kozler (A13B0359P)
 */

/*
    Creates the linked list from array.
 */
LinkedList *toList(TestObject **array, int32_t length) {
    LinkedList *list = new_LinkedList();

    int i;
    for (i = 0; i < length; i++) {
        addLl(list, array[i]);
    }
    
    return list;
}

/**
 * Tests the constructor.
 */

void linkedListTest() {
    const int32_t length = 0;
    LinkedList *a;
    bool b;
    TestObject **c;
    // empty list
    a = new_LinkedList();
    c = malloc(length * sizeof(TestObject *));
    b = equalsList(a, sizeLl, getLl, toList(c, length), sizeLl, getLl, equalsTo);
    assertEqualsBool(true, b);
}

/**
 * Tests the constructor with LinkedList as a parameter.
 */

void linkedListTest2() {
    const int32_t length = 0;
    const int32_t length2 = 1;
    const int32_t length3 = 3;
    LinkedList *a, *b;
    TestObject *c;
    bool d;
    TestObject **e;
    // creating the list from an empty list
    a = new_LinkedList();
    b = new_LinkedListAddAll(a);
    e = malloc(length * sizeof(TestObject *));
    d = equalsList(b, sizeLl, getLl, toList(e, length), sizeLl, getLl, equalsTo);
    assertEqualsBool(true, d);
    // creating the list from a list with one element
    a = new_LinkedList();
    c = new_TestObject(new_String("first"), 1);
    addLl(a, c);
    b = new_LinkedListAddAll(a);
    e = malloc(length2 * sizeof(TestObject *));
    e[0] = new_TestObject(new_String("first"), 1);
    d = equalsList(b, sizeLl, getLl, toList(e, length2), sizeLl, getLl, equalsTo);
    assertEqualsBool(true, d);
    // creating the list from a list with some elements
    a = new_LinkedList();
    e = malloc(length3 * sizeof(TestObject *));
    e[0] = new_TestObject(new_String("first"), 1);
    e[1] = new_TestObject(new_String("second"), 2);
    e[2] = new_TestObject(new_String("third"), 3);
    c = new_TestObject(new_String("first"), 1);
    addLl(a, c);
    c = new_TestObject(new_String("second"), 2);
    addLl(a, c);
    c = new_TestObject(new_String("third"), 3);
    addLl(a, c);
    b = new_LinkedListAddAll(a);
    d = equalsList(b, sizeLl, getLl, toList(e, length3), sizeLl, getLl, equalsTo);
    assertEqualsBool(true, d);
}

/**
 * Tests the add function.
 */

void addTest() {
    const int32_t length = 1;
    const int32_t length2 = 2;
    const int32_t length3 = 3;
    const int32_t length4 = 4;
    const int32_t length5 = 5;
    LinkedList *a;
    TestObject **d;
    TestObject *b;
    bool c;
    // adding some elements at the end of the list
    a = new_LinkedList();
    b = new_TestObject(new_String("first"), 1);
    addLl(a, b);
    d = malloc(length * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("first"), 1);
    c = equalsList(a, sizeLl, getLl, toList(d, length), sizeLl, getLl, equalsTo);
    assertEqualsBool(true, c);
    b = new_TestObject(new_String("second"), 2);
    addLl(a, b);
    d = malloc(length2 * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("first"), 1);
    d[1] = new_TestObject(new_String("second"), 2);
    c = equalsList(a, sizeLl, getLl, toList(d, length2), sizeLl, getLl, equalsTo);
    assertEqualsBool(true, c);
    b = new_TestObject(new_String("first"), 2);
    addLl(a, b);
    d = malloc(length3 * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("first"), 1);
    d[1] = new_TestObject(new_String("second"), 2);
    d[2] = new_TestObject(new_String("first"), 2);
    c = equalsList(a, sizeLl, getLl, toList(d, length3), sizeLl, getLl, equalsTo);
    assertEqualsBool(true, c);
    b = new_TestObject(new_String("second"), 1);
    addLl(a, b);
    d = malloc(length4 * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("first"), 1);
    d[1] = new_TestObject(new_String("second"), 2);
    d[2] = new_TestObject(new_String("first"), 2);
    d[3] = new_TestObject(new_String("second"), 1);
    c = equalsList(a, sizeLl, getLl, toList(d, length4), sizeLl, getLl, equalsTo);
    assertEqualsBool(true, c);
    b = new_TestObject(new_String("first"), 1);
    addLl(a, b);
    d = malloc(length5 * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("first"), 1);
    d[1] = new_TestObject(new_String("second"), 2);
    d[2] = new_TestObject(new_String("first"), 2);
    d[3] = new_TestObject(new_String("second"), 1);
    d[4] = new_TestObject(new_String("first"), 1);
    c = equalsList(a, sizeLl, getLl, toList(d, length5), sizeLl, getLl, equalsTo);
    assertEqualsBool(true, c);
}

/**
 * Tests the add function with index as a parameter.
 */

void addTest2() {
    const int32_t length = 1;
    const int32_t length2 = 2;
    const int32_t length3 = 3;
    const int32_t length4 = 4;
    const int32_t length5 = 5;
    LinkedList *a;
    TestObject *b;
    bool c;
    TestObject **d;
    a = new_LinkedList();
    // adding an element at the beginning
    b = new_TestObject(new_String("first"), 1);
    addAtLl(a, 0, b);
    d = malloc(length * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("first"), 1);
    c = equalsList(a, sizeLl, getLl, toList(d, length), sizeLl, getLl, equalsTo);
    assertEqualsBool(true, c);
    // adding an element at the end
    b = new_TestObject(new_String("second"), 2);
    addAtLl(a, 1, b);
    d = malloc(length2 * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("first"), 1);
    d[1] = new_TestObject(new_String("second"), 2);
    c = equalsList(a, sizeLl, getLl, toList(d, length2), sizeLl, getLl, equalsTo);
    assertEqualsBool(true, c);
    // adding an element at the beginning
    b = new_TestObject(new_String("third"), 3);
    addAtLl(a, 0, b);
    d = malloc(length3 * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("third"), 3);
    d[1] = new_TestObject(new_String("first"), 1);
    d[2] = new_TestObject(new_String("second"), 2);
    c = equalsList(a, sizeLl, getLl, toList(d, length3), sizeLl, getLl, equalsTo);
    assertEqualsBool(true, c);
    // adding an element in the middle
    b = new_TestObject(new_String("fourth"), 4);
    addAtLl(a, 1, b);
    d = malloc(length4 * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("third"), 3);
    d[1] = new_TestObject(new_String("fourth"), 4);
    d[2] = new_TestObject(new_String("first"), 1);
    d[3] = new_TestObject(new_String("second"), 2);
    c = equalsList(a, sizeLl, getLl, toList(d, length4), sizeLl, getLl, equalsTo);
    assertEqualsBool(true, c);
    // adding an element in the middle
    b = new_TestObject(new_String("fifth"), 5);
    addAtLl(a, 2, b);
    d = malloc(length5 * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("third"), 3);
    d[1] = new_TestObject(new_String("fourth"), 4);
    d[2] = new_TestObject(new_String("fifth"), 5);
    d[3] = new_TestObject(new_String("first"), 1);
    d[4] = new_TestObject(new_String("second"), 2);
    c = equalsList(a, sizeLl, getLl, toList(d, length5), sizeLl, getLl, equalsTo);
    assertEqualsBool(true, c);
}

/**
 * Tests the equals function.
 */

void equalsTest() {
    const int32_t length = 5;
    const int32_t length2 = 1;
    LinkedList *a, *b;
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
    c = equalsList(a, sizeLl, getLl, b, sizeLl, getLl, equalsTo);
    assertEqualsBool(false, c);
    d = malloc(length2 * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("first"), 3);
    b = toList(d, length2);
    c = equalsList(a, sizeLl, getLl, b, sizeLl, getLl, equalsTo);
    assertEqualsBool(false, c);
    d = malloc(length * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("first"), 3);
    d[1] = new_TestObject(new_String("second"), 2);
    d[2] = new_TestObject(new_String("third"), 8);
    d[3] = new_TestObject(new_String("fourth"), 7);
    d[4] = new_TestObject(new_String("fifth"), 3);
    b = toList(d, length);
    c = equalsList(a, sizeLl, getLl, b, sizeLl, getLl, equalsTo);
    assertEqualsBool(false, c);
    d = malloc(length * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("sixth"), 3);
    d[1] = new_TestObject(new_String("seventh"), 2);
    d[2] = new_TestObject(new_String("eighth"), 8);
    d[3] = new_TestObject(new_String("nineth"), 7);
    d[4] = new_TestObject(new_String("tenth"), 6);
    b = toList(d, length);
    c = equalsList(a, sizeLl, getLl, b, sizeLl, getLl, equalsTo);
    assertEqualsBool(true, c);
    b = a;
    c = equalsList(a, sizeLl, getLl, b, sizeLl, getLl, equalsTo);
    assertEqualsBool(true, c);
}

/**
 * Tests the get function.
 */

void getTest() {
    LinkedList *a;
    TestObject *b;
    bool c;
    a = new_LinkedList();
    // getting an element from the beginning
    b = new_TestObject(new_String("first"), 1);
    addLl(a, b);
    b = getLl(a, 0);
    c = equalsTo(b, new_TestObject(new_String("first"), 1));
    assertEqualsBool(true, c);
    // getting an element from the beginning (more elements in the list)
    b = new_TestObject(new_String("second"), 2);
    addLl(a, b);
    b = getLl(a, 0);
    c = equalsTo(b, new_TestObject(new_String("first"), 1));
    assertEqualsBool(true, c);
    // getting an element from the end
    b = getLl(a, 1);
    c = equalsTo(b, new_TestObject(new_String("second"), 2));
    assertEqualsBool(true, c);
    b = new_TestObject(new_String("third"), 3);
    addLl(a, b);
    b = new_TestObject(new_String("fourth"), 4);
    addLl(a, b);
    b = new_TestObject(new_String("fifth"), 5);
    addLl(a, b);
    // getting an element from the beginning
    b = getLl(a, 0);
    c = equalsTo(b, new_TestObject(new_String("first"), 1));
    assertEqualsBool(true, c);
    // getting an element from the end
    b = getLl(a, 4);
    c = equalsTo(b, new_TestObject(new_String("fifth"), 5));
    assertEqualsBool(true, c);
}

/**
 * Tests the set function.
 */

void setTest() {
    const int32_t length = 5;
    LinkedList *a;
    TestObject *b;
    bool c;
    TestObject **d;
    a = new_LinkedList();
    b = new_TestObject(new_String("first"), 1);
    addLl(a, b);
    b = new_TestObject(new_String("second"), 2);
    addLl(a, b);
    b = new_TestObject(new_String("third"), 3);
    addLl(a, b);
    b = new_TestObject(new_String("fourth"), 4);
    addLl(a, b);
    b = new_TestObject(new_String("fifth"), 5);
    addLl(a, b);
    b = new_TestObject(new_String("sixth"), 6);
    // replacing an element at the beginning
    setLl(a, 0, b);
    d = malloc(length * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("sixth"), 6);
    d[1] = new_TestObject(new_String("second"), 2);
    d[2] = new_TestObject(new_String("third"), 3);
    d[3] = new_TestObject(new_String("fourth"), 4);
    d[4] = new_TestObject(new_String("fifth"), 5);
    c = equalsList(a, sizeLl, getLl, toList(d, length), sizeLl, getLl, equalsTo);
    assertEqualsBool(true, c);
    // replacing an element in the middle
    b = new_TestObject(new_String("seventh"), 7);
    setLl(a, 2, b);
    d = malloc(length * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("sixth"), 6);
    d[1] = new_TestObject(new_String("second"), 2);
    d[2] = new_TestObject(new_String("seventh"), 7);
    d[3] = new_TestObject(new_String("fourth"), 4);
    d[4] = new_TestObject(new_String("fifth"), 5);
    c = equalsList(a, sizeLl, getLl, toList(d, length), sizeLl, getLl, equalsTo);
    assertEqualsBool(true, c);
    // replacing an element at the end
    b = new_TestObject(new_String("eighth"), 8);
    setLl(a, 4, b);
    d = malloc(length * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("sixth"), 6);
    d[1] = new_TestObject(new_String("second"), 2);
    d[2] = new_TestObject(new_String("seventh"), 7);
    d[3] = new_TestObject(new_String("fourth"), 4);
    d[4] = new_TestObject(new_String("eighth"), 8);
    c = equalsList(a, sizeLl, getLl, toList(d, length), sizeLl, getLl, equalsTo);
    assertEqualsBool(true, c);
}

/**
 * Tests the remove function.
 */

void removeTest() {
    const int32_t length = 4;
    const int32_t length2 = 3;
    const int32_t length3 = 2;
    LinkedList *a;
    TestObject *b;
    bool c;
    TestObject **d;
    a = new_LinkedList();
    b = new_TestObject(new_String("first"), 1);
    addLl(a, b);
    b = new_TestObject(new_String("second"), 2);
    addLl(a, b);
    b = new_TestObject(new_String("third"), 3);
    addLl(a, b);
    b = new_TestObject(new_String("fourth"), 4);
    addLl(a, b);
    b = new_TestObject(new_String("fifth"), 5);
    // removing an element from the beginning
    addLl(a, b);
    removeLl(a, 0);
    d = malloc(length * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("second"), 2);
    d[1] = new_TestObject(new_String("third"), 3);
    d[2] = new_TestObject(new_String("fourth"), 4);
    d[3] = new_TestObject(new_String("fifth"), 5);
    c = equalsList(a, sizeLl, getLl, toList(d, length), sizeLl, getLl, equalsTo);
    assertEqualsBool(true, c);
    // removing the element from the middle
    removeLl(a, 1);
    d = malloc(length2 * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("second"), 2);
    d[1] = new_TestObject(new_String("fourth"), 4);
    d[2] = new_TestObject(new_String("fifth"), 5);
    c = equalsList(a, sizeLl, getLl, toList(d, length2), sizeLl, getLl, equalsTo);
    assertEqualsBool(true, c);
    // removing an element from the end
    removeLl(a, 2);
    d = malloc(length3 * sizeof(TestObject *));
    d[0] = new_TestObject(new_String("second"), 2);
    d[1] = new_TestObject(new_String("fourth"), 4);
    c = equalsList(a, sizeLl, getLl, toList(d, length3), sizeLl, getLl, equalsTo);
    assertEqualsBool(true, c);
}

/**
 * Tests the size function.
 */

void sizeTest() {
    LinkedList *a;
    TestObject *b;
    int32_t c;
    a = new_LinkedList();
    // size in the beginning
    c = sizeLl(a);
    assertEqualsI(0, c);
    b = new_TestObject(new_String("first"), 1);
    // size after adding one element
    addLl(a, b);
    c = sizeLl(a);
    assertEqualsI(1, c);
    // size after adding more elements
    b = new_TestObject(new_String("second"), 2);
    addLl(a, b);
    b = new_TestObject(new_String("third"), 3);
    addLl(a, b);
    c = sizeLl(a);
    assertEqualsI(3, c);
    // size after removing one element
    removeLl(a, 0);
    c = sizeLl(a);
    assertEqualsI(2, c);
    // size after removing more elements
    removeLl(a, 0);
    removeLl(a, 0);
    c = sizeLl(a);
    assertEqualsI(0, c);
}

/**
 * Tests the isEmpty function.
 */

void isEmptyTest() {
    LinkedList *a;
    TestObject *b;
    bool c;
    a = new_LinkedList();
    c = isEmptyLl(a);
    assertEqualsBool(true, c);
    b = new_TestObject(new_String("first"), 1);
    addLl(a, b);
    c = isEmptyLl(a);
    assertEqualsBool(false, c);
    b = new_TestObject(new_String("second"), 2);
    addLl(a, b);
    b = new_TestObject(new_String("third"), 3);
    addLl(a, b);
    c = isEmptyLl(a);
    assertEqualsBool(false, c);
    removeLl(a, 0);
    c = isEmptyLl(a);
    assertEqualsBool(false, c);
    removeLl(a, 0);
    removeLl(a, 0);
    c = isEmptyLl(a);
    assertEqualsBool(true, c);
}

/**
 * Tests the clear function.
 */

void clearTest() {
    const int32_t length = 0;
    LinkedList *a;
    TestObject *b;
    bool c;
    TestObject **d;
    d = malloc(length * sizeof(TestObject *));
    a = new_LinkedList();
    // clear in the beginning
    clearLl(a);
    c = equalsList(a, sizeLl, getLl, toList(d, length), sizeLl, getLl, equalsTo);
    assertEqualsBool(true, c);
    // clear after adding one element
    b = new_TestObject(new_String("first"), 1);
    addLl(a, b);
    clearLl(a);
    c = equalsList(a, sizeLl, getLl, toList(d, length), sizeLl, getLl, equalsTo);
    assertEqualsBool(true, c);
    // clear after adding more elements
    b = new_TestObject(new_String("first"), 1);
    addLl(a, b);
    b = new_TestObject(new_String("second"), 2);
    addLl(a, b);
    b = new_TestObject(new_String("third"), 3);
    addLl(a, b);
    clearLl(a);
    c = equalsList(a, sizeLl, getLl, toList(d, length), sizeLl, getLl, equalsTo);
    assertEqualsBool(true, c);
}

/**
 * Tests the toString function.
 */

void toStringTest() {
    LinkedList *a;
    TestObject *b;
    String *c;
    // the text representation of an empty list
    a = new_LinkedList();
    c = toStringLl(a, toStringTo);
    assertEqualsStr("[]", c->s);
    // the text representation of a list with one element
    b = new_TestObject(new_String("first"), 1);
    addLl(a, b);
    c = toStringLl(a, toStringTo);
    assertEqualsStr("[TestObject [str=first, i=1]]", c->s);
    // the text representation of a list with some elements
    b = new_TestObject(new_String("second"), 2);
    addLl(a, b);
    b = new_TestObject(new_String("third"), 3);
    addLl(a, b);
    c = toStringLl(a, toStringTo);
    assertEqualsStr("[TestObject [str=first, i=1], TestObject [str=second, i=2], TestObject [str=third, i=3]]", c->s);
}

int main(int argc, char** argv) {
    const int testCount = 12;
    setUpTestModule("LinkedListTest", testCount);

    registerTest(linkedListTest, "linkedListTest");
    registerTest(linkedListTest2, "linkedListTest2");
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
