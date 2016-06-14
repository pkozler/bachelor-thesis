#include <cstdlib>
#include <iostream>
#include <algorithm>

#include "test.h"
#include "ArrayList.h"
#include "TestObject.h"
#include "TestObjectComparator.h"

/*
 * Simple C++ Test Suite
 */

/*
    Creates the array list from array.
 */
ArrayList<TestObject> *toList(TestObject **array, int32_t length) {
    ArrayList<TestObject> *list = new ArrayList<TestObject>();

    int32_t i;
    for (i = 0; i < length; i++) {
        list->add(array[i]);
    }
    
    return list;
}

/**
 * Tests the constructor.
 */

void arrayListTest() {
    const int32_t length = 0;
    ArrayList<TestObject> *a;
    bool b;
    TestObject **c;
    // empty list
    a = new ArrayList<TestObject>();
    c = new TestObject *[length];
    b = a->equals(toList(c, length));
    Test::assertEquals(true, b);
}

/**
 * Tests the constructor with ArrayList as a parameter.
 */

void arrayListTest2() {
    const int32_t length = 0;
    const int32_t length2 = 1;
    const int32_t length3 = 3;
    ArrayList<TestObject> *a, *b;
    TestObject *c;
    bool d;
    TestObject **e;
    // creating the list from an empty list
    a = new ArrayList<TestObject>();
    b = new ArrayList<TestObject>(a);
    e = new TestObject *[length];
    d = b->equals(toList(e, length));
    Test::assertEquals(true, d);
    // creating the list from a list with one element
    a = new ArrayList<TestObject>();
    c = new TestObject(new String("first"), 1);
    a->add(c);
    b = new ArrayList<TestObject>(a);
    e = new TestObject *[length2];
    e[0] = new TestObject(new String("first"), 1);
    d = b->equals(toList(e, length2));
    Test::assertEquals(true, d);
    // creating the list from a list with some elements
    a = new ArrayList<TestObject>();
    e = new TestObject *[length3];
    e[0] = new TestObject(new String("first"), 1);
    e[1] = new TestObject(new String("second"), 2);
    e[2] = new TestObject(new String("third"), 3);
    c = new TestObject(new String("first"), 1);
    a->add(c);
    c = new TestObject(new String("second"), 2);
    a->add(c);
    c = new TestObject(new String("third"), 3);
    a->add(c);
    b = new ArrayList<TestObject>(a);
    d = b->equals(toList(e, length3));
    Test::assertEquals(true, d);
}

/**
 * Tests the add method.
 */

void addTest() {
    const int32_t length = 1;
    const int32_t length2 = 2;
    const int32_t length3 = 3;
    const int32_t length4 = 4;
    const int32_t length5 = 5;
    ArrayList<TestObject> *a;
    TestObject **d;
    TestObject *b;
    bool c;
    // adding some elements at the end of the list
    a = new ArrayList<TestObject>();
    b = new TestObject(new String("first"), 1);
    a->add(b);
    d = new TestObject *[length];
    d[0] = new TestObject(new String("first"), 1);
    c = a->equals(toList(d, length));
    Test::assertEquals(true, c);
    b = new TestObject(new String("second"), 2);
    a->add(b);
    d = new TestObject *[length2];
    d[0] = new TestObject(new String("first"), 1);
    d[1] = new TestObject(new String("second"), 2);
    c = a->equals(toList(d, length2));
    Test::assertEquals(true, c);
    b = new TestObject(new String("first"), 2);
    a->add(b);
    d = new TestObject *[length3];
    d[0] = new TestObject(new String("first"), 1);
    d[1] = new TestObject(new String("second"), 2);
    d[2] = new TestObject(new String("first"), 2);
    c = a->equals(toList(d, length3));
    Test::assertEquals(true, c);
    b = new TestObject(new String("second"), 1);
    a->add(b);
    d = new TestObject *[length4];
    d[0] = new TestObject(new String("first"), 1);
    d[1] = new TestObject(new String("second"), 2);
    d[2] = new TestObject(new String("first"), 2);
    d[3] = new TestObject(new String("second"), 1);
    c = a->equals(toList(d, length4));
    Test::assertEquals(true, c);
    b = new TestObject(new String("first"), 1);
    a->add(b);
    d = new TestObject *[length5];
    d[0] = new TestObject(new String("first"), 1);
    d[1] = new TestObject(new String("second"), 2);
    d[2] = new TestObject(new String("first"), 2);
    d[3] = new TestObject(new String("second"), 1);
    d[4] = new TestObject(new String("first"), 1);
    c = a->equals(toList(d, length5));
    Test::assertEquals(true, c);
}

/**
 * Tests the add method with index as a parameter.
 */

void addTest2() {
    const int32_t length = 1;
    const int32_t length2 = 2;
    const int32_t length3 = 3;
    const int32_t length4 = 4;
    const int32_t length5 = 5;
    ArrayList<TestObject> *a;
    TestObject *b;
    bool c;
    TestObject **d;
    a = new ArrayList<TestObject>();
    // adding an element at the beginning
    b = new TestObject(new String("first"), 1);
    a->add(0, b);
    d = new TestObject *[length];
    d[0] = new TestObject(new String("first"), 1);
    c = a->equals(toList(d, length));
    Test::assertEquals(true, c);
    // adding an element at the end
    b = new TestObject(new String("second"), 2);
    a->add(1, b);
    d = new TestObject *[length2];
    d[0] = new TestObject(new String("first"), 1);
    d[1] = new TestObject(new String("second"), 2);
    c = a->equals(toList(d, length2));
    Test::assertEquals(true, c);
    // adding an element at the beginning
    b = new TestObject(new String("third"), 3);
    a->add(0, b);
    d = new TestObject *[length3];
    d[0] = new TestObject(new String("third"), 3);
    d[1] = new TestObject(new String("first"), 1);
    d[2] = new TestObject(new String("second"), 2);
    c = a->equals(toList(d, length3));
    Test::assertEquals(true, c);
    // adding an element in the middle
    b = new TestObject(new String("fourth"), 4);
    a->add(1, b);
    d = new TestObject *[length4];
    d[0] = new TestObject(new String("third"), 3);
    d[1] = new TestObject(new String("fourth"), 4);
    d[2] = new TestObject(new String("first"), 1);
    d[3] = new TestObject(new String("second"), 2);
    c = a->equals(toList(d, length4));
    Test::assertEquals(true, c);
    // adding an element in the middle
    b = new TestObject(new String("fifth"), 5);
    a->add(2, b);
    d = new TestObject *[length5];
    d[0] = new TestObject(new String("third"), 3);
    d[1] = new TestObject(new String("fourth"), 4);
    d[2] = new TestObject(new String("fifth"), 5);
    d[3] = new TestObject(new String("first"), 1);
    d[4] = new TestObject(new String("second"), 2);
    c = a->equals(toList(d, length5));
    Test::assertEquals(true, c);
}

/**
 * Tests the equals method.
 */

void equalsTest() {
    const int32_t length = 5;
    const int32_t length2 = 1;
    ArrayList<TestObject> *a, *b;
    bool c;
    TestObject **d;
    d = new TestObject *[length];
    d[0] = new TestObject(new String("first"), 3);
    d[1] = new TestObject(new String("second"), 2);
    d[2] = new TestObject(new String("third"), 8);
    d[3] = new TestObject(new String("fourth"), 7);
    d[4] = new TestObject(new String("fifth"), 6);
    a = toList(d, length);
    b = nullptr;
    c = a->equals(b);
    Test::assertEquals(false, c);
    d = new TestObject *[length2];
    d[0] = new TestObject(new String("first"), 3);
    b = toList(d, length2);
    c = a->equals(b);
    Test::assertEquals(false, c);
    d = new TestObject *[length];
    d[0] = new TestObject(new String("first"), 3);
    d[1] = new TestObject(new String("second"), 2);
    d[2] = new TestObject(new String("third"), 8);
    d[3] = new TestObject(new String("fourth"), 7);
    d[4] = new TestObject(new String("fifth"), 3);
    b = toList(d, length);
    c = a->equals(b);
    Test::assertEquals(false, c);
    d = new TestObject *[length];
    d[0] = new TestObject(new String("sixth"), 3);
    d[1] = new TestObject(new String("seventh"), 2);
    d[2] = new TestObject(new String("eighth"), 8);
    d[3] = new TestObject(new String("nineth"), 7);
    d[4] = new TestObject(new String("tenth"), 6);
    b = toList(d, length);
    c = a->equals(b);
    Test::assertEquals(true, c);
    b = a;
    c = a->equals(b);
    Test::assertEquals(true, c);
}

/**
 * Tests the get method.
 */

void getTest() {
    ArrayList<TestObject> *a;
    TestObject *b;
    bool c;
    a = new ArrayList<TestObject>();
    // getting an element from the beginning
    b = new TestObject(new String("first"), 1);
    a->add(b);
    b = a->get(0);
    c = b->equals(new TestObject(new String("first"), 1));
    Test::assertEquals(true, c);
    // getting an element from the beginning (more elements in the list)
    b = new TestObject(new String("second"), 2);
    a->add(b);
    b = a->get(0);
    c = b->equals(new TestObject(new String("first"), 1));
    Test::assertEquals(true, c);
    // getting an element from the end
    b = a->get(1);
    c = b->equals(new TestObject(new String("second"), 2));
    Test::assertEquals(true, c);
    b = new TestObject(new String("third"), 3);
    a->add(b);
    b = new TestObject(new String("fourth"), 4);
    a->add(b);
    b = new TestObject(new String("fifth"), 5);
    a->add(b);
    // getting an element from the beginning
    b = a->get(0);
    c = b->equals(new TestObject(new String("first"), 1));
    Test::assertEquals(true, c);
    // getting an element from the end
    b = a->get(4);
    c = b->equals(new TestObject(new String("fifth"), 5));
    Test::assertEquals(true, c);
}

/**
 * Tests the set method.
 */

void setTest() {
    const int32_t length = 5;
    ArrayList<TestObject> *a;
    TestObject *b;
    bool c;
    TestObject **d;
    a = new ArrayList<TestObject>();
    b = new TestObject(new String("first"), 1);
    a->add(b);
    b = new TestObject(new String("second"), 2);
    a->add(b);
    b = new TestObject(new String("third"), 3);
    a->add(b);
    b = new TestObject(new String("fourth"), 4);
    a->add(b);
    b = new TestObject(new String("fifth"), 5);
    a->add(b);
    b = new TestObject(new String("sixth"), 6);
    // replacing an element at the beginning
    a->set(0, b);
    d = new TestObject *[length];
    d[0] = new TestObject(new String("sixth"), 6);
    d[1] = new TestObject(new String("second"), 2);
    d[2] = new TestObject(new String("third"), 3);
    d[3] = new TestObject(new String("fourth"), 4);
    d[4] = new TestObject(new String("fifth"), 5);
    c = a->equals(toList(d, length));
    Test::assertEquals(true, c);
    // replacing an element in the middle
    b = new TestObject(new String("seventh"), 7);
    a->set(2, b);
    d = new TestObject *[length];
    d[0] = new TestObject(new String("sixth"), 6);
    d[1] = new TestObject(new String("second"), 2);
    d[2] = new TestObject(new String("seventh"), 7);
    d[3] = new TestObject(new String("fourth"), 4);
    d[4] = new TestObject(new String("fifth"), 5);
    c = a->equals(toList(d, length));
    Test::assertEquals(true, c);
    // replacing an element at the end
    b = new TestObject(new String("eighth"), 8);
    a->set(4, b);
    d = new TestObject *[length];
    d[0] = new TestObject(new String("sixth"), 6);
    d[1] = new TestObject(new String("second"), 2);
    d[2] = new TestObject(new String("seventh"), 7);
    d[3] = new TestObject(new String("fourth"), 4);
    d[4] = new TestObject(new String("eighth"), 8);
    c = a->equals(toList(d, length));
    Test::assertEquals(true, c);
}

/**
 * Tests the remove method.
 */

void removeTest() {
    const int32_t length = 4;
    const int32_t length2 = 3;
    const int32_t length3 = 2;
    ArrayList<TestObject> *a;
    TestObject *b;
    bool c;
    TestObject **d;
    a = new ArrayList<TestObject>();
    b = new TestObject(new String("first"), 1);
    a->add(b);
    b = new TestObject(new String("second"), 2);
    a->add(b);
    b = new TestObject(new String("third"), 3);
    a->add(b);
    b = new TestObject(new String("fourth"), 4);
    a->add(b);
    b = new TestObject(new String("fifth"), 5);
    // removing an element from the beginning
    a->add(b);
    a->remove(0);
    d = new TestObject *[length];
    d[0] = new TestObject(new String("second"), 2);
    d[1] = new TestObject(new String("third"), 3);
    d[2] = new TestObject(new String("fourth"), 4);
    d[3] = new TestObject(new String("fifth"), 5);
    c = a->equals(toList(d, length));
    Test::assertEquals(true, c);
    // removing the element from the middle
    a->remove(1);
    d = new TestObject *[length2];
    d[0] = new TestObject(new String("second"), 2);
    d[1] = new TestObject(new String("fourth"), 4);
    d[2] = new TestObject(new String("fifth"), 5);
    c = a->equals(toList(d, length2));
    Test::assertEquals(true, c);
    // removing an element from the end
    a->remove(2);
    d = new TestObject *[length3];
    d[0] = new TestObject(new String("second"), 2);
    d[1] = new TestObject(new String("fourth"), 4);
    c = a->equals(toList(d, length3));
    Test::assertEquals(true, c);
}

/**
 * Tests the size method.
 */

void sizeTest() {
    ArrayList<TestObject> *a;
    TestObject *b;
    int32_t c;
    a = new ArrayList<TestObject>();
    // size in the beginning
    c = a->size();
    Test::assertEquals(0, c);
    b = new TestObject(new String("first"), 1);
    // size after adding one element
    a->add(b);
    c = a->size();
    Test::assertEquals(1, c);
    // size after adding more elements
    b = new TestObject(new String("second"), 2);
    a->add(b);
    b = new TestObject(new String("third"), 3);
    a->add(b);
    c = a->size();
    Test::assertEquals(3, c);
    // size after removing one element
    a->remove(0);
    c = a->size();
    Test::assertEquals(2, c);
    // size after removing more elements
    a->remove(0);
    a->remove(0);
    c = a->size();
    Test::assertEquals(0, c);
}

/**
 * Tests the isEmpty method.
 */

void isEmptyTest() {
    ArrayList<TestObject> *a;
    TestObject *b;
    bool c;
    a = new ArrayList<TestObject>();
    c = a->isEmpty();
    Test::assertEquals(true, c);
    b = new TestObject(new String("first"), 1);
    a->add(b);
    c = a->isEmpty();
    Test::assertEquals(false, c);
    b = new TestObject(new String("second"), 2);
    a->add(b);
    b = new TestObject(new String("third"), 3);
    a->add(b);
    c = a->isEmpty();
    Test::assertEquals(false, c);
    a->remove(0);
    c = a->isEmpty();
    Test::assertEquals(false, c);
    a->remove(0);
    a->remove(0);
    c = a->isEmpty();
    Test::assertEquals(true, c);
}

/**
 * Tests the clear method.
 */

void clearTest() {
    const int32_t length = 0;
    ArrayList<TestObject> *a;
    TestObject *b;
    bool c;
    TestObject **d;
    d = new TestObject *[length];
    a = new ArrayList<TestObject>();
    // clear in the beginning
    a->clear();
    c = a->equals(toList(d, length));
    Test::assertEquals(true, c);
    // clear after adding one element
    b = new TestObject(new String("first"), 1);
    a->add(b);
    a->clear();
    c = a->equals(toList(d, length));
    Test::assertEquals(true, c);
    // clear after adding more elements
    b = new TestObject(new String("first"), 1);
    a->add(b);
    b = new TestObject(new String("second"), 2);
    a->add(b);
    b = new TestObject(new String("third"), 3);
    a->add(b);
    a->clear();
    c = a->equals(toList(d, length));
    Test::assertEquals(true, c);
}

/**
 * Tests the toString method.
 */

void toStringTest() {
    ArrayList<TestObject> *a;
    TestObject *b;
    String *c;
    // the text representation of an empty list
    a = new ArrayList<TestObject>();
    c = a->toString();
    Test::assertEquals("[]", c->_s());
    // the text representation of a list with one element
    b = new TestObject(new String("first"), 1);
    a->add(b);
    c = a->toString();
    Test::assertEquals("[TestObject [str=first, i=1]]", c->_s());
    // the text representation of a list with some elements
    b = new TestObject(new String("second"), 2);
    a->add(b);
    b = new TestObject(new String("third"), 3);
    a->add(b);
    c = a->toString();
    Test::assertEquals("[TestObject [str=first, i=1], TestObject [str=second, i=2], TestObject [str=third, i=3]]", c->_s());
}

int main(int argc, char** argv) {
    Test::setUpTestModule("ArrayListTest");

    Test::registerTest(arrayListTest, "arrayListTest");
    Test::registerTest(arrayListTest2, "arrayListTest2");
    Test::registerTest(addTest, "addTest");
    Test::registerTest(addTest2, "addTest2");
    Test::registerTest(equalsTest, "equalsTest");
    Test::registerTest(getTest, "getTest");
    Test::registerTest(setTest, "setTest");
    Test::registerTest(removeTest, "removeTest");
    Test::registerTest(sizeTest, "sizeTest");
    Test::registerTest(isEmptyTest, "isEmptyTest");
    Test::registerTest(clearTest, "clearTest");
    Test::registerTest(toStringTest, "toStringTest");
    
    Test::runTests();

    return (EXIT_SUCCESS);
}