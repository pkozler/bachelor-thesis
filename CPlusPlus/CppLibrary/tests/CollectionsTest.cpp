#include <cstdlib>
#include <iostream>

#include "test.h"
#include "Collections.h"
#include "TestObject.h"
#include "TestObjectComparator.h"

/*
 * Simple C++ Test Suite
 */

/**
 * Tests the binarySearch method.
 */

void binarySearchTest() {
    ArrayList<TestObject> *a;
    int32_t b;
    a = new ArrayList<TestObject>();
    a->add(new TestObject(new String("first"), 3));
    a->add(new TestObject(new String("second"), 2));
    a->add(new TestObject(new String("third"), 8));
    a->add(new TestObject(new String("fourth"), 7));
    a->add(new TestObject(new String("fifth"), 6));
    a->add(new TestObject(new String("sixth"), 3));
    a->add(new TestObject(new String("seventh"), 2));
    a->add(new TestObject(new String("eighth"), 8));
    a->add(new TestObject(new String("nineth"), 7));
    a->add(new TestObject(new String("tenth"), 6));
    Collections::sort(a);
    b = Collections::binarySearch(a, new TestObject(new String("sixth"), 6));
    Test::assertEquals(4, b);
    b = Collections::binarySearch(a, new TestObject(new String("sixth"), 4));
    Test::assertEquals(-5, b);
}

/**
 * Tests the binarySearch method with comparator as a parameter.
 */

void binarySearchTest2() {
    ArrayList<TestObject> *a;
    int32_t b;
    TestObjectComparator *c;
    a = new ArrayList<TestObject>();
    a->add(new TestObject(new String("first"), 3));
    a->add(new TestObject(new String("second"), 2));
    a->add(new TestObject(new String("third"), 8));
    a->add(new TestObject(new String("fourth"), 7));
    a->add(new TestObject(new String("fifth"), 6));
    a->add(new TestObject(new String("sixth"), 3));
    a->add(new TestObject(new String("seventh"), 2));
    a->add(new TestObject(new String("eighth"), 8));
    a->add(new TestObject(new String("nineth"), 7));
    a->add(new TestObject(new String("tenth"), 6));
    c = new TestObjectComparator();
    Collections::sort(a);
    b = Collections::binarySearch(a, new TestObject(new String("sixth"), 6), c);
    Test::assertEquals(4, b);
    b = Collections::binarySearch(a, new TestObject(new String("sixth"), 4), c);
    Test::assertEquals(-5, b);
}

/**
 * Tests the copy method.
 */

void copyTest() {
    ArrayList<TestObject> *a, *b, *c;
    bool d;
    // source list
    a = new ArrayList<TestObject>();
    a->add(new TestObject(new String("first"), 3));
    a->add(new TestObject(new String("second"), 2));
    a->add(new TestObject(new String("third"), 8));
    a->add(new TestObject(new String("fourth"), 7));
    a->add(new TestObject(new String("fifth"), 6));
    // destination list
    b = new ArrayList<TestObject>();
    b->add(new TestObject(new String("zeroth"), 0));
    b->add(new TestObject(new String("zeroth"), 0));
    b->add(new TestObject(new String("zeroth"), 0));
    b->add(new TestObject(new String("zeroth"), 0));
    b->add(new TestObject(new String("zeroth"), 0));
    b->add(new TestObject(new String("zeroth"), 0));
    Collections::copy(b, a);
    c = new ArrayList<TestObject>();
    c->add(new TestObject(new String("first"), 3));
    c->add(new TestObject(new String("second"), 2));
    c->add(new TestObject(new String("third"), 8));
    c->add(new TestObject(new String("fourth"), 7));
    c->add(new TestObject(new String("fifth"), 6));
    c->add(new TestObject(new String("zeroth"), 0));
    d = c->equals(b);
    Test::assertEquals(true, d);
}

/**
 * Tests the fill method.
 */

void fillTest() {
    List<TestObject> *a, *b;
    bool d;
    a = new ArrayList<TestObject>();
    a->add(new TestObject(new String("first"), 3));
    a->add(new TestObject(new String("second"), 2));
    a->add(new TestObject(new String("third"), 8));
    a->add(new TestObject(new String("fourth"), 7));
    a->add(new TestObject(new String("fifth"), 6));
    Collections::fill(a, new TestObject(new String("sixth"), 6));
    b = new ArrayList<TestObject>();
    b->add(new TestObject(new String("sixth"), 6));
    b->add(new TestObject(new String("sixth"), 6));
    b->add(new TestObject(new String("sixth"), 6));
    b->add(new TestObject(new String("sixth"), 6));
    b->add(new TestObject(new String("sixth"), 6));
    d = b->equals(a);
    Test::assertEquals(true, d);
}

/**
 * Tests the sort method.
 */

void sortTest() {
    ArrayList<TestObject> *a, *b;
    bool d;
    a = new ArrayList<TestObject>();
    a->add(new TestObject(new String("first"), 3));
    a->add(new TestObject(new String("second"), 2));
    a->add(new TestObject(new String("third"), 8));
    a->add(new TestObject(new String("fourth"), 7));
    a->add(new TestObject(new String("fifth"), 6));
    a->add(new TestObject(new String("sixth"), 3));
    a->add(new TestObject(new String("seventh"), 2));
    a->add(new TestObject(new String("eighth"), 8));
    a->add(new TestObject(new String("nineth"), 7));
    a->add(new TestObject(new String("tenth"), 6));
    Collections::sort(a);
    b = new ArrayList<TestObject>();
    b->add(new TestObject(new String("second"), 2));
    b->add(new TestObject(new String("seventh"), 2));
    b->add(new TestObject(new String("first"), 3));
    b->add(new TestObject(new String("sixth"), 3));
    b->add(new TestObject(new String("fifth"), 6));
    b->add(new TestObject(new String("tenth"), 6));
    b->add(new TestObject(new String("fourth"), 7));
    b->add(new TestObject(new String("nineth"), 7));
    b->add(new TestObject(new String("third"), 8));
    b->add(new TestObject(new String("eighth"), 8));
    d = b->equals(a);
    Test::assertEquals(true, d);
}

/**
 * Tests the sort method with comparator as a parameter.
 */

void sortTest2() {
    ArrayList<TestObject> *a, *b;
    TestObjectComparator *c;
    bool d;
    a = new ArrayList<TestObject>();
    a->add(new TestObject(new String("first"), 3));
    a->add(new TestObject(new String("second"), 2));
    a->add(new TestObject(new String("third"), 8));
    a->add(new TestObject(new String("fourth"), 7));
    a->add(new TestObject(new String("fifth"), 6));
    a->add(new TestObject(new String("sixth"), 3));
    a->add(new TestObject(new String("seventh"), 2));
    a->add(new TestObject(new String("eighth"), 8));
    a->add(new TestObject(new String("nineth"), 7));
    a->add(new TestObject(new String("tenth"), 6));
    c = new TestObjectComparator();
    Collections::sort(a, c);
    b = new ArrayList<TestObject>();
    b->add(new TestObject(new String("second"), 2));
    b->add(new TestObject(new String("seventh"), 2));
    b->add(new TestObject(new String("first"), 3));
    b->add(new TestObject(new String("sixth"), 3));
    b->add(new TestObject(new String("fifth"), 6));
    b->add(new TestObject(new String("tenth"), 6));
    b->add(new TestObject(new String("fourth"), 7));
    b->add(new TestObject(new String("nineth"), 7));
    b->add(new TestObject(new String("third"), 8));
    b->add(new TestObject(new String("eighth"), 8));
    d = b->equals(a);
    Test::assertEquals(true, d);
}

int main(int argc, char** argv) {
    Test::setUpTestModule("CollectionsTest");

    Test::registerTest(binarySearchTest, "binarySearchTest");
    Test::registerTest(binarySearchTest2, "binarySearchTest2");
    Test::registerTest(copyTest, "copyTest");
    Test::registerTest(fillTest, "fillTest");
    Test::registerTest(sortTest, "sortTest");
    Test::registerTest(sortTest2, "sortTest2");
    
    Test::runTests();

    return (EXIT_SUCCESS);
}