#include <cstdlib>
#include <iostream>

#include "test.h"
#include "Arrays.h"
#include "TestObject.h"
#include "TestObjectComparator.h"

/*
 * Simple C++ Test Suite
 */

/**
 * Tests the binarySearch method with array of bytes.
 */

void binarySearchTest() {
    const int32_t length = 5;
    int8_t *a;
    int32_t b;
    a = new int8_t[length]{(int8_t) 3, (int8_t) 2, (int8_t) 8, (int8_t) 7, (int8_t) 6};
    Arrays::sort(a, length);
    // existing element search
    b = Arrays::binarySearch(a, length, (int8_t) 8);
    Test::assertEquals(4, b);
    // non-existent element search
    b = Arrays::binarySearch(a, length, (int8_t) 4);
    Test::assertEquals(-3, b);
}

/**
 * Tests the binarySearch method with array of bytes and indexes as
 * parameters.
 */

void binarySearchTest2() {
    const int32_t length = 5;
    int8_t *a;
    int32_t b;
    a = new int8_t[length]{(int8_t) 3, (int8_t) 2, (int8_t) 8, (int8_t) 7, (int8_t) 6};
    Arrays::sort(a, length);
    // existing element search
    b = Arrays::binarySearch(a, 1, 4, (int8_t) 8);
    Test::assertEquals(-5, b);
    // non-existent element search in a part of array
    b = Arrays::binarySearch(a, 1, 4, (int8_t) 4);
    Test::assertEquals(-3, b);
}

/**
 * Tests the binarySearch method with array of chars.
 */

void binarySearchTest3() {
    const int32_t length = 5;
    char *a;
    int32_t b;
    a = new char[length] {
        'c', 'b', 'h', 'g', 'f'
    };
    Arrays::sort(a, length);
    b = Arrays::binarySearch(a, length, 'h');
    Test::assertEquals(4, b);
    b = Arrays::binarySearch(a, length, 'd');
    Test::assertEquals(-3, b);
}

/**
 * Tests the binarySearch method with array of chars and indexes as
 * parameters.
 */

void binarySearchTest4() {
    const int32_t length = 5;
    char *a;
    int32_t b;
    a = new char[length] {
        'c', 'b', 'h', 'g', 'f'
    };
    Arrays::sort(a, length);
    b = Arrays::binarySearch(a, 1, 4, 'h');
    Test::assertEquals(-5, b);
    b = Arrays::binarySearch(a, 1, 4, 'd');
    Test::assertEquals(-3, b);
}

/**
 * Tests the binarySearch method with array of doubles.
 */

void binarySearchTest5() {
    const int32_t length = 5;
    double *a;
    int32_t b;
    a = new double[length] {
        3.0, 2.0, 8.0, 7.0, 6.0
    };
    Arrays::sort(a, length);
    b = Arrays::binarySearch(a, length, 8.0);
    Test::assertEquals(4, b);
    b = Arrays::binarySearch(a, length, 4.0);
    Test::assertEquals(-3, b);
}

/**
 * Tests the binarySearch method with array of doubles and indexes as
 * parameters.
 */

void binarySearchTest6() {
    const int32_t length = 5;
    double *a;
    int32_t b;
    a = new double[length] {
        3.0, 2.0, 8.0, 7.0, 6.0
    };
    Arrays::sort(a, length);
    b = Arrays::binarySearch(a, 1, 4, 8.0);
    Test::assertEquals(-5, b);
    b = Arrays::binarySearch(a, 1, 4, 4.0);
    Test::assertEquals(-3, b);
}

/**
 * Tests the binarySearch method with array of floats.
 */

void binarySearchTest7() {
    const int32_t length = 5;
    float *a;
    int32_t b;
    a = new float[length] {
        3.0F, 2.0F, 8.0F, 7.0F, 6.0F
    };
    Arrays::sort(a, length);
    b = Arrays::binarySearch(a, length, 8.0F);
    Test::assertEquals(4, b);
    b = Arrays::binarySearch(a, length, 4.0F);
    Test::assertEquals(-3, b);
}

/**
 * Tests the binarySearch method with array of floats and indexes as
 * parameters.
 */

void binarySearchTest8() {
    const int32_t length = 5;
    float *a;
    int32_t b;
    a = new float[length] {
        3.0F, 2.0F, 8.0F, 7.0F, 6.0F
    };
    Arrays::sort(a, length);
    b = Arrays::binarySearch(a, 1, 4, 8.0F);
    Test::assertEquals(-5, b);
    b = Arrays::binarySearch(a, 1, 4, 4.0F);
    Test::assertEquals(-3, b);
}

/**
 * Tests the binarySearch method with array of ints.
 */

void binarySearchTest9() {
    const int32_t length = 5;
    int32_t *a;
    int32_t b;
    a = new int32_t[length]{3, 2, 8, 7, 6};
    Arrays::sort(a, length);
    b = Arrays::binarySearch(a, length, 8);
    Test::assertEquals(4, b);
    b = Arrays::binarySearch(a, length, 4);
    Test::assertEquals(-3, b);
}

/**
 * Tests the binarySearch method with array of ints and indexes as
 * parameters.
 */

void binarySearchTest10() {
    const int32_t length = 5;
    int32_t *a;
    int32_t b;
    a = new int32_t[length]{3, 2, 8, 7, 6};
    Arrays::sort(a, length);
    b = Arrays::binarySearch(a, 1, 4, 8);
    Test::assertEquals(-5, b);
    b = Arrays::binarySearch(a, 1, 4, 4);
    Test::assertEquals(-3, b);
}

/**
 * Tests the binarySearch method with array of longs.
 */

void binarySearchTest11() {
    const int32_t length = 5;
    int64_t *a;
    int32_t b;
    a = new int64_t[length]{3L, 2L, 8L, 7L, 6L};
    Arrays::sort(a, length);
    b = Arrays::binarySearch(a, length, 8L);
    Test::assertEquals(4, b);
    b = Arrays::binarySearch(a, length, 4L);
    Test::assertEquals(-3, b);
}

/**
 * Tests the binarySearch method with array of longs and indexes as
 * parameters.
 */

void binarySearchTest12() {
    const int32_t length = 5;
    int64_t *a;
    int32_t b;
    a = new int64_t[length]{3L, 2L, 8L, 7L, 6L};
    Arrays::sort(a, length);
    b = Arrays::binarySearch(a, 1, 4, 8L);
    Test::assertEquals(-5, b);
    b = Arrays::binarySearch(a, 1, 4, 4L);
    Test::assertEquals(-3, b);
}

/**
 * Tests the binarySearch method with array of objects.
 */

void binarySearchTest13() {
    const int32_t length = 10;
    Object **a;
    int32_t b;
    a = new Object *[length];
    a[0] = new TestObject(new String("first"), 3);
    a[1] = new TestObject(new String("second"), 2);
    a[2] = new TestObject(new String("third"), 8);
    a[3] = new TestObject(new String("fourth"), 7);
    a[4] = new TestObject(new String("fifth"), 6);
    a[5] = new TestObject(new String("sixth"), 3);
    a[6] = new TestObject(new String("seventh"), 2);
    a[7] = new TestObject(new String("eighth"), 8);
    a[8] = new TestObject(new String("nineth"), 7);
    a[9] = new TestObject(new String("tenth"), 6);
    Arrays::sort(a, length);
    b = Arrays::binarySearch(a, length, new TestObject(new String("sixth"), 6));
    Test::assertEquals(4, b);
    b = Arrays::binarySearch(a, length, new TestObject(new String("sixth"), 4));
    Test::assertEquals(-5, b);
}

/**
 * Tests the binarySearch method with array of objects and indexes as
 * parameters.
 */

void binarySearchTest14() {
    const int32_t length = 10;
    Object **a;
    int32_t b;
    a = new Object *[length];
    a[0] = new TestObject(new String("first"), 3);
    a[1] = new TestObject(new String("second"), 2);
    a[2] = new TestObject(new String("third"), 8);
    a[3] = new TestObject(new String("fourth"), 7);
    a[4] = new TestObject(new String("fifth"), 6);
    a[5] = new TestObject(new String("sixth"), 3);
    a[6] = new TestObject(new String("seventh"), 2);
    a[7] = new TestObject(new String("eighth"), 8);
    a[8] = new TestObject(new String("nineth"), 7);
    a[9] = new TestObject(new String("tenth"), 6);
    Arrays::sort(a, length);
    b = Arrays::binarySearch(a, 1, 4, new TestObject(new String("sixth"), 6));
    Test::assertEquals(-5, b);
    b = Arrays::binarySearch(a, 1, 4, new TestObject(new String("sixth"), 4));
    Test::assertEquals(-5, b);
}

/**
 * Tests the binarySearch method with array of shorts.
 */

void binarySearchTest15() {
    const int32_t length = 5;
    int16_t *a;
    int32_t b;
    a = new int16_t[length]{(int16_t) 3, (int16_t) 2, (int16_t) 8, (int16_t) 7, (int16_t) 6};
    Arrays::sort(a, length);
    b = Arrays::binarySearch(a, length, (int16_t) 8);
    Test::assertEquals(4, b);
    b = Arrays::binarySearch(a, length, (int16_t) 4);
    Test::assertEquals(-3, b);
}

/**
 * Tests the binarySearch method with array of shorts and indexes as
 * parameters.
 */

void binarySearchTest16() {
    const int32_t length = 5;
    int16_t *a;
    int32_t b;
    a = new int16_t[length]{(int16_t) 3, (int16_t) 2, (int16_t) 8, (int16_t) 7, (int16_t) 6};
    Arrays::sort(a, length);
    b = Arrays::binarySearch(a, 1, 4, (int16_t) 8);
    Test::assertEquals(-5, b);
    b = Arrays::binarySearch(a, 1, 4, (int16_t) 4);
    Test::assertEquals(-3, b);
}

/**
 * Tests the binarySearch method with array of objects and comparator as a
 * parameter.
 */

void binarySearchTest17() {
    const int32_t length = 10;
    TestObject **a;
    int32_t b;
    Comparator *c;
    a = new TestObject *[length];
    a[0] = new TestObject(new String("first"), 3);
    a[1] = new TestObject(new String("second"), 2);
    a[2] = new TestObject(new String("third"), 8);
    a[3] = new TestObject(new String("fourth"), 7);
    a[4] = new TestObject(new String("fifth"), 6);
    a[5] = new TestObject(new String("sixth"), 3);
    a[6] = new TestObject(new String("seventh"), 2);
    a[7] = new TestObject(new String("eighth"), 8);
    a[8] = new TestObject(new String("nineth"), 7);
    a[9] = new TestObject(new String("tenth"), 6);
    c = new TestObjectComparator();
    Arrays::sort((Object **)a, length, c);
    b = Arrays::binarySearch((Object **)a, length, new TestObject(new String("sixth"), 6), c);
    Test::assertEquals(4, b);
    b = Arrays::binarySearch((Object **)a, length, new TestObject(new String("sixth"), 4), c);
    Test::assertEquals(-5, b);
}

/**
 * Tests the binarySearch method with array of shorts and indexes and
 * comparator as parameters.
 */

void binarySearchTest18() {
    const int32_t length = 10;
    TestObject **a;
    int32_t b;
    Comparator *c;
    a = new TestObject *[length];
    a[0] = new TestObject(new String("first"), 3);
    a[1] = new TestObject(new String("second"), 2);
    a[2] = new TestObject(new String("third"), 8);
    a[3] = new TestObject(new String("fourth"), 7);
    a[4] = new TestObject(new String("fifth"), 6);
    a[5] = new TestObject(new String("sixth"), 3);
    a[6] = new TestObject(new String("seventh"), 2);
    a[7] = new TestObject(new String("eighth"), 8);
    a[8] = new TestObject(new String("nineth"), 7);
    a[9] = new TestObject(new String("tenth"), 6);
    c = new TestObjectComparator();
    Arrays::sort((Object **)a, length, c);
    b = Arrays::binarySearch((Object **)a, 1, 4, new TestObject(new String("sixth"), 6), c);
    Test::assertEquals(-5, b);
    b = Arrays::binarySearch((Object **)a, 1, 4, new TestObject(new String("sixth"), 4), c);
    Test::assertEquals(-5, b);
}

/**
 * Tests the copyOf method with array of booleans.
 */

void copyOfTest() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    const int32_t length3 = 7;
    bool *a, *b;
    bool c;
    a = new bool[length] {
        true, false, false, false, true
    };
    // new array is smaller
    b = Arrays::copyOf(a, length, 3);
    c = Arrays::equals(b, length2, new bool[length2] {
        true, false, false
    }, length2);
    Test::assertEquals(true, c);
    // new array has the same length
    b = Arrays::copyOf(a, length, 5);
    c = Arrays::equals(b, length, new bool[length] {
        true, false, false, false, true
    }, length);
    Test::assertEquals(true, c);
    // new array is bigger
    b = Arrays::copyOf(a, length, 7);
    c = Arrays::equals(b, length3, new bool[length3] {
        true, false, false, false, true, false, false
    }, length3);
    Test::assertEquals(true, c);
}

/**
 * Tests the copyOf method with array of bytes.
 */

void copyOfTest2() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    const int32_t length3 = 7;
    int8_t *a, *b;
    bool c;
    a = new int8_t[length]{(int8_t) 3, (int8_t) 2, (int8_t) 8, (int8_t) 7, (int8_t) 6};
    b = Arrays::copyOf(a, length, 3);
    c = Arrays::equals(b, length2, new int8_t[length2]{3, 2, 8}, length2);
    Test::assertEquals(true, c);
    b = Arrays::copyOf(a, length, 5);
    c = Arrays::equals(b, length, new int8_t[length]{3, 2, 8, 7, 6}, length);
    Test::assertEquals(true, c);
    b = Arrays::copyOf(a, length, 7);
    c = Arrays::equals(b, length3, new int8_t[length3]{3, 2, 8, 7, 6, 0, 0}, length3);
    Test::assertEquals(true, c);
}

/**
 * Tests the copyOf method with array of chars.
 */

void copyOfTest3() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    const int32_t length3 = 7;
    char *a, *b;
    bool c;
    a = new char[length] {
        'c', 'b', 'h', 'g', 'f'
    };
    b = Arrays::copyOf(a, length, 3);
    c = Arrays::equals(b, length2, new char[length2] {
        'c', 'b', 'h'
    }, length2);
    Test::assertEquals(true, c);
    b = Arrays::copyOf(a, length, 5);
    c = Arrays::equals(b, length, new char[length] {
        'c', 'b', 'h', 'g', 'f'
    }, length);
    Test::assertEquals(true, c);
    b = Arrays::copyOf(a, length, 7);
    c = Arrays::equals(b, length3, new char[length3] {
        'c', 'b', 'h', 'g', 'f', '\0', '\0' }, length3);
    Test::assertEquals(true, c);
}

/**
 * Tests the copyOf method with array of doubles.
 */

void copyOfTest4() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    const int32_t length3 = 7;
    double *a, *b;
    bool c;
    a = new double[length] {
        3.0, 2.0, 8.0, 7.0, 6.0
    };
    b = Arrays::copyOf(a, length, 3);
    c = Arrays::equals(b, length2, new double[length2] {
        3.0, 2.0, 8.0
    }, length2);
    Test::assertEquals(true, c);
    b = Arrays::copyOf(a, length, 5);
    c = Arrays::equals(b, length, new double[length] {
        3.0, 2.0, 8.0, 7.0, 6.0
    }, length);
    Test::assertEquals(true, c);
    b = Arrays::copyOf(a, length, 7);
    c = Arrays::equals(b, length3, new double[length3] {
        3.0, 2.0, 8.0, 7.0, 6.0, 0.0, 0.0
    }, length3);
    Test::assertEquals(true, c);
}

/**
 * Tests the copyOf method with array of floats.
 */

void copyOfTest5() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    const int32_t length3 = 7;
    float *a, *b;
    bool c;
    a = new float[length] {
        3.0F, 2.0F, 8.0F, 7.0F, 6.0F
    };
    b = Arrays::copyOf(a, length, 3);
    c = Arrays::equals(b, length2, new float[length2] {
        3.0F, 2.0F, 8.0F
    }, length2);
    Test::assertEquals(true, c);
    b = Arrays::copyOf(a, length, 5);
    c = Arrays::equals(b, length, new float[length] {
        3.0F, 2.0F, 8.0F, 7.0F, 6.0F
    }, length);
    Test::assertEquals(true, c);
    b = Arrays::copyOf(a, length, 7);
    c = Arrays::equals(b, length3, new float[length3] {
        3.0F, 2.0F, 8.0F, 7.0F, 6.0F, 0.0F, 0.0F
    }, length3);
    Test::assertEquals(true, c);
}

/**
 * Tests the copyOf method with array of ints.
 */

void copyOfTest6() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    const int32_t length3 = 7;
    int32_t *a, *b;
    bool c;
    a = new int32_t[length]{3, 2, 8, 7, 6};
    b = Arrays::copyOf(a, length, 3);
    c = Arrays::equals(b, length2, new int32_t[length2]{3, 2, 8}, length2);
    Test::assertEquals(true, c);
    b = Arrays::copyOf(a, length, 5);
    c = Arrays::equals(b, length, new int32_t[length]{3, 2, 8, 7, 6}, length);
    Test::assertEquals(true, c);
    b = Arrays::copyOf(a, length, 7);
    c = Arrays::equals(b, length3, new int32_t[length3]{3, 2, 8, 7, 6, 0, 0}, length3);
    Test::assertEquals(true, c);
}

/**
 * Tests the copyOf method with array of longs.
 */

void copyOfTest7() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    const int32_t length3 = 7;
    int64_t *a, *b;
    bool c;
    a = new int64_t[length]{3L, 2L, 8L, 7L, 6L};
    b = Arrays::copyOf(a, length, 3);
    c = Arrays::equals(b, length2, new int64_t[length2]{3, 2, 8}, length2);
    Test::assertEquals(true, c);
    b = Arrays::copyOf(a, length, 5);
    c = Arrays::equals(b, length, new int64_t[length]{3, 2, 8, 7, 6}, length);
    Test::assertEquals(true, c);
    b = Arrays::copyOf(a, length, 7);
    c = Arrays::equals(b, length3, new int64_t[length3]{3, 2, 8, 7, 6, 0, 0}, length3);
    Test::assertEquals(true, c);
}

/**
 * Tests the copyOf method with array of shorts.
 */

void copyOfTest8() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    const int32_t length3 = 7;
    int16_t *a, *b;
    bool c;
    a = new int16_t[length]{(int16_t) 3, (int16_t) 2, (int16_t) 8, (int16_t) 7, (int16_t) 6};
    b = Arrays::copyOf(a, length, 3);
    c = Arrays::equals(b, length2, new int16_t[length2]{3, 2, 8}, length2);
    Test::assertEquals(true, c);
    b = Arrays::copyOf(a, length, 5);
    c = Arrays::equals(b, length, new int16_t[length]{3, 2, 8, 7, 6}, length);
    Test::assertEquals(true, c);
    b = Arrays::copyOf(a, length, 7);
    c = Arrays::equals(b, length3, new int16_t[length3]{3, 2, 8, 7, 6, 0, 0}, length3);
    Test::assertEquals(true, c);
}

/**
 * Tests the copyOf method with array of objects.
 */

void copyOfTest9() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    const int32_t length3 = 7;
    TestObject **a, **b, **d;
    bool c;
    a = new TestObject *[length];
    a[0] = new TestObject(new String("first"), 3);
    a[1] = new TestObject(new String("second"), 2);
    a[2] = new TestObject(new String("third"), 8);
    a[3] = new TestObject(new String("fourth"), 7);
    a[4] = new TestObject(new String("fifth"), 6);
    b = (TestObject **)Arrays::copyOf((Object **)a, length, 3);
    d = new TestObject *[length2];
    d[0] = new TestObject(new String("first"), 3);
    d[1] = new TestObject(new String("second"), 2);
    d[2] = new TestObject(new String("third"), 8);
    c = Arrays::equals((Object **) b, length2, (Object **) d, length2);
    Test::assertEquals(true, c);
    b = (TestObject **)Arrays::copyOf((Object **)a, length, 5);
    d = new TestObject *[length];
    d[0] = new TestObject(new String("first"), 3);
    d[1] = new TestObject(new String("second"), 2);
    d[2] = new TestObject(new String("third"), 8);
    d[3] = new TestObject(new String("fourth"), 7);
    d[4] = new TestObject(new String("fifth"), 6);
    c = Arrays::equals((Object **) b, length, (Object **) d, length);
    Test::assertEquals(true, c);
    b = (TestObject **)Arrays::copyOf((Object **)a, length, 7);
    d = new TestObject *[length3];
    d[0] = new TestObject(new String("first"), 3);
    d[1] = new TestObject(new String("second"), 2);
    d[2] = new TestObject(new String("third"), 8);
    d[3] = new TestObject(new String("fourth"), 7);
    d[4] = new TestObject(new String("fifth"), 6);
    d[5] = NULL;
    d[6] = NULL;
    c = Arrays::equals((Object **) b, length3, (Object **) d, length3);
    Test::assertEquals(true, c);
}

/**
 * Tests the copyOfRange method with array of booleans.
 */

void copyOfRangeTest() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    bool *a, *b;
    bool c;
    a = new bool[length] {
        true, false, false, false, true
    };
    // copy from the beginning
    b = Arrays::copyOfRange(a, length, 0, 3);
    c = Arrays::equals(b, length2, new bool[length2] {
        true, false, false
    }, length2);
    Test::assertEquals(true, c);
    // copy from the middle
    b = Arrays::copyOfRange(a, length, 2, 5);
    c = Arrays::equals(b, length2, new bool[length2] {
        false, false, true
    }, length2);
    Test::assertEquals(true, c);
    // copy from the end
    b = Arrays::copyOfRange(a, length, 4, 7);
    c = Arrays::equals(b, length2, new bool[length2] {
        true, false, false
    }, length2);
    Test::assertEquals(true, c);
}

/**
 * Tests the copyOfRange method with array of bytes.
 */

void copyOfRangeTest2() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    int8_t *a, *b;
    bool c;
    a = new int8_t[length]{(int8_t) 3, (int8_t) 2, (int8_t) 8, (int8_t) 7, (int8_t) 6};
    b = Arrays::copyOfRange(a, length, 0, 3);
    c = Arrays::equals(b, length2, new int8_t[length2]{3, 2, 8}, length2);
    Test::assertEquals(true, c);
    b = Arrays::copyOfRange(a, length, 2, 5);
    c = Arrays::equals(b, length2, new int8_t[length2]{8, 7, 6}, length2);
    Test::assertEquals(true, c);
    b = Arrays::copyOfRange(a, length, 4, 7);
    c = Arrays::equals(b, length2, new int8_t[length2]{6, 0, 0}, length2);
    Test::assertEquals(true, c);
}

/**
 * Tests the copyOfRange method with array of chars.
 */

void copyOfRangeTest3() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    char *a, *b;
    bool c;
    a = new char[length] {
        'c', 'b', 'h', 'g', 'f'
    };
    b = Arrays::copyOfRange(a, length, 0, 3);
    c = Arrays::equals(b, length2, new char[length2] {
        'c', 'b', 'h'
    }, length2);
    Test::assertEquals(true, c);
    b = Arrays::copyOfRange(a, length, 2, 5);
    c = Arrays::equals(b, length2, new char[length2] {
        'h', 'g', 'f'
    }, length2);
    Test::assertEquals(true, c);
    b = Arrays::copyOfRange(a, length, 4, 7);
    c = Arrays::equals(b, length2, new char[length2] {
        'f', '\0', '\0' }, length2);
    Test::assertEquals(true, c);
}

/**
 * Tests the copyOfRange method with array of doubles.
 */

void copyOfRangeTest4() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    double *a, *b;
    bool c;
    a = new double[length] {
        3.0, 2.0, 8.0, 7.0, 6.0
    };
    b = Arrays::copyOfRange(a, length, 0, 3);
    c = Arrays::equals(b, length2, new double[length2] {
        3.0, 2.0, 8.0
    }, length2);
    Test::assertEquals(true, c);
    b = Arrays::copyOfRange(a, length, 2, 5);
    c = Arrays::equals(b, length2, new double[length2] {
        8.0, 7.0, 6.0
    }, length2);
    Test::assertEquals(true, c);
    b = Arrays::copyOfRange(a, length, 4, 7);
    c = Arrays::equals(b, length2, new double[length2] {
        6.0, 0.0, 0.0
    }, length2);
    Test::assertEquals(true, c);
}

/**
 * Tests the copyOfRange method with array of floats.
 */

void copyOfRangeTest5() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    float *a, *b;
    bool c;
    a = new float[length] {
        3.0F, 2.0F, 8.0F, 7.0F, 6.0F
    };
    b = Arrays::copyOfRange(a, length, 0, 3);
    c = Arrays::equals(b, length2, new float[length2] {
        3.0F, 2.0F, 8.0F
    }, length2);
    Test::assertEquals(true, c);
    b = Arrays::copyOfRange(a, length, 2, 5);
    c = Arrays::equals(b, length2, new float[length2] {
        8.0F, 7.0F, 6.0F
    }, length2);
    Test::assertEquals(true, c);
    b = Arrays::copyOfRange(a, length, 4, 7);
    c = Arrays::equals(b, length2, new float[length2] {
        6.0F, 0.0F, 0.0F
    }, length2);
    Test::assertEquals(true, c);
}

/**
 * Tests the copyOfRange method with array of ints.
 */

void copyOfRangeTest6() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    int32_t *a, *b;
    bool c;
    a = new int32_t[length]{3, 2, 8, 7, 6};
    b = Arrays::copyOfRange(a, length, 0, 3);
    c = Arrays::equals(b, length2, new int32_t[length2]{3, 2, 8}, length2);
    Test::assertEquals(true, c);
    b = Arrays::copyOfRange(a, length, 2, 5);
    c = Arrays::equals(b, length2, new int32_t[length2]{8, 7, 6}, length2);
    Test::assertEquals(true, c);
    b = Arrays::copyOfRange(a, length, 4, 7);
    c = Arrays::equals(b, length2, new int32_t[length2]{6, 0, 0}, length2);
    Test::assertEquals(true, c);
}

/**
 * Tests the copyOfRange method with array of longs.
 */

void copyOfRangeTest7() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    int64_t *a, *b;
    bool c;
    a = new int64_t[length]{3L, 2L, 8L, 7L, 6L};
    b = Arrays::copyOfRange(a, length, 0, 3);
    c = Arrays::equals(b, length2, new int64_t[length2]{3, 2, 8}, length2);
    Test::assertEquals(true, c);
    b = Arrays::copyOfRange(a, length, 2, 5);
    c = Arrays::equals(b, length2, new int64_t[length2]{8, 7, 6}, length2);
    Test::assertEquals(true, c);
    b = Arrays::copyOfRange(a, length, 4, 7);
    c = Arrays::equals(b, length2, new int64_t[length2]{6, 0, 0}, length2);
    Test::assertEquals(true, c);
}

/**
 * Tests the copyOfRange method with array of shorts.
 */

void copyOfRangeTest8() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    int16_t *a, *b;
    bool c;
    a = new int16_t[length]{(int16_t) 3, (int16_t) 2, (int16_t) 8, (int16_t) 7, (int16_t) 6};
    b = Arrays::copyOfRange(a, length, 0, 3);
    c = Arrays::equals(b, length2, new int16_t[length2]{3, 2, 8}, length2);
    Test::assertEquals(true, c);
    b = Arrays::copyOfRange(a, length, 2, 5);
    c = Arrays::equals(b, length2, new int16_t[length2]{8, 7, 6}, length2);
    Test::assertEquals(true, c);
    b = Arrays::copyOfRange(a, length, 4, 7);
    c = Arrays::equals(b, length2, new int16_t[length2]{6, 0, 0}, length2);
    Test::assertEquals(true, c);
}

/**
 * Tests the copyOfRange method with array of objects.
 */

void copyOfRangeTest9() {
    const int32_t length = 5;
    const int32_t length2 = 3;
    TestObject **a, **b, **d;
    bool c;
    a = new TestObject *[length];
    a[0] = new TestObject(new String("first"), 3);
    a[1] = new TestObject(new String("second"), 2);
    a[2] = new TestObject(new String("third"), 8);
    a[3] = new TestObject(new String("fourth"), 7);
    a[4] = new TestObject(new String("fifth"), 6);
    b = (TestObject **)Arrays::copyOfRange((Object **)a, length, 0, 3);
    d = new TestObject *[length2];
    d[0] = new TestObject(new String("first"), 3);
    d[1] = new TestObject(new String("second"), 2);
    d[2] = new TestObject(new String("third"), 8);
    c = Arrays::equals((Object **) b, length2, (Object **) d, length2);
    Test::assertEquals(true, c);
    b = (TestObject **)Arrays::copyOfRange((Object **)a, length, 2, 5);
    d = new TestObject *[length2];
    d[0] = new TestObject(new String("third"), 8);
    d[1] = new TestObject(new String("fourth"), 7);
    d[2] = new TestObject(new String("fifth"), 6);
    c = Arrays::equals((Object **) b, length2, (Object **) d, length2);
    Test::assertEquals(true, c);
    b = (TestObject **)Arrays::copyOfRange((Object **)a, length, 4, 7);
    d = new TestObject *[length2];
    d[0] = new TestObject(new String("fifth"), 6);
    d[1] = NULL;
    d[2] = NULL;
    c = Arrays::equals((Object **) b, length2, (Object **) d, length2);
    Test::assertEquals(true, c);
}

/**
 * Tests the equals method with array of booleans.
 */

void equalsTest() {
    const int32_t length = 5;
    const int32_t length2 = 1;
    bool *a, *b;
    bool c;
    a = new bool[length] {
        true, false, false, false, true
    };
    // reference to the second array is NULL
    b = NULL;
    c = Arrays::equals(a, length, b, 0);
    Test::assertEquals(false, c);
    // arrays do not have the same length
    b = new bool[length2] {
        true
    };
    c = Arrays::equals(a, length, b, length2);
    Test::assertEquals(false, c);
    // arrays have the same length but different elements
    b = new bool[length] {
        true, false, false, false, false
    };
    c = Arrays::equals(a, length, b, length);
    Test::assertEquals(false, c);
    // arrays have the same length and elements
    b = new bool[length] {
        true, false, false, false, true
    };
    c = Arrays::equals(a, length, b, length);
    Test::assertEquals(true, c);
    // references are equal
    b = a;
    c = Arrays::equals(a, length, b, length);
    Test::assertEquals(true, c);
}

/**
 * Tests the equals method with array of bytes.
 */

void equalsTest2() {
    const int32_t length = 5;
    const int32_t length2 = 1;
    int8_t *a, *b;
    bool c;
    a = new int8_t[length]{(int8_t) 3, (int8_t) 2, (int8_t) 8, (int8_t) 7, (int8_t) 6};
    b = NULL;
    c = Arrays::equals(a, length, b, 0);
    Test::assertEquals(false, c);
    b = new int8_t[length2]{(int8_t) 3};
    c = Arrays::equals(a, length, b, length2);
    Test::assertEquals(false, c);
    b = new int8_t[length]{(int8_t) 3, (int8_t) 2, (int8_t) 8, (int8_t) 7, (int8_t) 3};
    c = Arrays::equals(a, length, b, length);
    Test::assertEquals(false, c);
    b = new int8_t[length]{(int8_t) 3, (int8_t) 2, (int8_t) 8, (int8_t) 7, (int8_t) 6};
    c = Arrays::equals(a, length, b, length);
    Test::assertEquals(true, c);
    b = a;
    c = Arrays::equals(a, length, b, length);
    Test::assertEquals(true, c);
}

/**
 * Tests the equals method with array of chars.
 */

void equalsTest3() {
    const int32_t length = 5;
    const int32_t length2 = 1;
    char *a, *b;
    bool c;
    a = new char[length] {
        'c', 'b', 'h', 'g', 'f'
    };
    b = NULL;
    c = Arrays::equals(a, length, b, 0);
    Test::assertEquals(false, c);
    b = new char[length2] {
        'c'
    };
    c = Arrays::equals(a, length, b, length2);
    Test::assertEquals(false, c);
    b = new char[length] {
        'c', 'b', 'h', 'g', 'c'
    };
    c = Arrays::equals(a, length, b, length);
    Test::assertEquals(false, c);
    b = new char[length] {
        'c', 'b', 'h', 'g', 'f'
    };
    c = Arrays::equals(a, length, b, length);
    Test::assertEquals(true, c);
    b = a;
    c = Arrays::equals(a, length, b, length);
    Test::assertEquals(true, c);
}

/**
 * Tests the equals method with array of doubles.
 */

void equalsTest4() {
    const int32_t length = 5;
    const int32_t length2 = 1;
    double *a, *b;
    bool c;
    a = new double[length] {
        3.0, 2.0, 8.0, 7.0, 6.0
    };
    b = NULL;
    c = Arrays::equals(a, length, b, 0);
    Test::assertEquals(false, c);
    b = new double[length2] {
        3.0
    };
    c = Arrays::equals(a, length, b, length2);
    Test::assertEquals(false, c);
    b = new double[length] {
        3.0, 2.0, 8.0, 7.0, 3.0
    };
    c = Arrays::equals(a, length, b, length);
    Test::assertEquals(false, c);
    b = new double[length] {
        3.0, 2.0, 8.0, 7.0, 6.0
    };
    c = Arrays::equals(a, length, b, length);
    Test::assertEquals(true, c);
    b = a;
    c = Arrays::equals(a, length, b, length);
    Test::assertEquals(true, c);
}

/**
 * Tests the equals method with array of floats.
 */

void equalsTest5() {
    const int32_t length = 5;
    const int32_t length2 = 1;
    float *a, *b;
    bool c;
    a = new float[length] {
        3.0F, 2.0F, 8.0F, 7.0F, 6.0F
    };
    b = NULL;
    c = Arrays::equals(a, length, b, 0);
    Test::assertEquals(false, c);
    b = new float[length2] {
        3.0F
    };
    c = Arrays::equals(a, length, b, length2);
    Test::assertEquals(false, c);
    b = new float[length] {
        3.0F, 2.0F, 8.0F, 7.0F, 3.0F
    };
    c = Arrays::equals(a, length, b, length);
    Test::assertEquals(false, c);
    b = new float[length] {
        3.0F, 2.0F, 8.0F, 7.0F, 6.0F
    };
    c = Arrays::equals(a, length, b, length);
    Test::assertEquals(true, c);
    b = a;
    c = Arrays::equals(a, length, b, length);
    Test::assertEquals(true, c);
}

/**
 * Tests the equals method with array of ints.
 */

void equalsTest6() {
    const int32_t length = 5;
    const int32_t length2 = 1;
    int32_t *a, *b;
    bool c;
    a = new int32_t[length]{3, 2, 8, 7, 6};
    b = NULL;
    c = Arrays::equals(a, length, b, 0);
    Test::assertEquals(false, c);
    b = new int32_t[length2]{3};
    c = Arrays::equals(a, length, b, length2);
    Test::assertEquals(false, c);
    b = new int32_t[length]{3, 2, 8, 7, 3};
    c = Arrays::equals(a, length, b, length);
    Test::assertEquals(false, c);
    b = new int32_t[length]{3, 2, 8, 7, 6};
    c = Arrays::equals(a, length, b, length);
    Test::assertEquals(true, c);
    b = a;
    c = Arrays::equals(a, length, b, length);
    Test::assertEquals(true, c);
}

/**
 * Tests the equals method with array of longs.
 */

void equalsTest7() {
    const int32_t length = 5;
    const int32_t length2 = 1;
    int64_t *a, *b;
    bool c;
    a = new int64_t[length]{3L, 2L, 8L, 7L, 6L};
    b = NULL;
    c = Arrays::equals(a, length, b, 0);
    Test::assertEquals(false, c);
    b = new int64_t[length2]{3L};
    c = Arrays::equals(a, length, b, length2);
    Test::assertEquals(false, c);
    b = new int64_t[length]{3L, 2L, 8L, 7L, 3L};
    c = Arrays::equals(a, length, b, length);
    Test::assertEquals(false, c);
    b = new int64_t[length]{3L, 2L, 8L, 7L, 6L};
    c = Arrays::equals(a, length, b, length);
    Test::assertEquals(true, c);
    b = a;
    c = Arrays::equals(a, length, b, length);
    Test::assertEquals(true, c);
}

/**
 * Tests the equals method with array of objects.
 */

void equalsTest8() {
    const int32_t length = 5;
    const int32_t length2 = 1;
    Object **a, **b;
    bool c;
    a = new Object *[length];
    a[0] = new TestObject(new String("first"), 3);
    a[1] = new TestObject(new String("second"), 2);
    a[2] = new TestObject(new String("third"), 8);
    a[3] = new TestObject(new String("fourth"), 7);
    a[4] = new TestObject(new String("fifth"), 6);
    b = NULL;
    c = Arrays::equals(a, length, b, 0);
    Test::assertEquals(false, c);
    b = new Object *[length2];
    b[0] = new TestObject(new String("first"), 3);
    c = Arrays::equals(a, length, b, length2);
    Test::assertEquals(false, c);
    b = new Object *[length];
    b[0] = new TestObject(new String("first"), 3);
    b[1] = new TestObject(new String("second"), 2);
    b[2] = new TestObject(new String("third"), 8);
    b[3] = new TestObject(new String("fourth"), 7);
    b[4] = new TestObject(new String("fifth"), 3);
    c = Arrays::equals(a, length, b, length);
    Test::assertEquals(false, c);
    b = new Object *[length];
    b[0] = new TestObject(new String("sixth"), 3);
    b[1] = new TestObject(new String("seventh"), 2);
    b[2] = new TestObject(new String("eighth"), 8);
    b[3] = new TestObject(new String("nineth"), 7);
    b[4] = new TestObject(new String("tenth"), 6);
    c = Arrays::equals(a, length, b, length);
    Test::assertEquals(true, c);
    b = a;
    c = Arrays::equals(a, length, b, length);
    Test::assertEquals(true, c);
}

/**
 * Tests the equals method with array of shorts.
 */

void equalsTest9() {
    const int32_t length = 5;
    const int32_t length2 = 1;
    int16_t *a, *b;
    bool c;
    a = new int16_t[length]{(int16_t) 3, (int16_t) 2, (int16_t) 8, (int16_t) 7, (int16_t) 6};
    b = NULL;
    c = Arrays::equals(a, length, b, 0);
    Test::assertEquals(false, c);
    b = new int16_t[length2]{(int16_t) 3};
    c = Arrays::equals(a, length, b, length2);
    Test::assertEquals(false, c);
    b = new int16_t[length]{(int16_t) 3, (int16_t) 2, (int16_t) 8, (int16_t) 7, (int16_t) 3};
    c = Arrays::equals(a, length, b, length);
    Test::assertEquals(false, c);
    b = new int16_t[length]{(int16_t) 3, (int16_t) 2, (int16_t) 8, (int16_t) 7, (int16_t) 6};
    c = Arrays::equals(a, length, b, length);
    Test::assertEquals(true, c);
    b = a;
    c = Arrays::equals(a, length, b, length);
    Test::assertEquals(true, c);
}

/**
 * Tests the fill method with array of booleans.
 */

void fillTest() {
    const int32_t length = 5;
    bool *a;
    bool b;
    // the array for filling
    a = new bool[5]();
    Arrays::fill(a, length, true);
    b = Arrays::equals(a, length, new bool[length] {
        true, true, true, true, true
    }, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the fill method with array of booleans and indexes as parameters.
 */

void fillTest2() {
    const int32_t length = 5;
    bool *a;
    bool b;
    // the array for partial filling
    a = new bool[5]();
    Arrays::fill(a, 1, 4, true);
    b = Arrays::equals(a, length, new bool[length] {
        false, true, true, true, false
    }, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the fill method with array of bytes.
 */

void fillTest3() {
    const int32_t length = 5;
    int8_t *a;
    bool b;
    a = new int8_t[5]();
    Arrays::fill(a, length, (int8_t) 8);
    b = Arrays::equals(a, length, new int8_t[length]{8, 8, 8, 8, 8}, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the fill method with array of bytes and indexes as parameters.
 */

void fillTest4() {
    const int32_t length = 5;
    int8_t *a;
    bool b;
    a = new int8_t[5]();
    Arrays::fill(a, 1, 4, (int8_t) 8);
    b = Arrays::equals(a, length, new int8_t[length]{0, 8, 8, 8, 0}, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the fill method with array of chars.
 */

void fillTest5() {
    const int32_t length = 5;
    char *a;
    bool b;
    a = new char[5]();
    Arrays::fill(a, length, 'h');
    b = Arrays::equals(a, length, new char[length] {
        'h', 'h', 'h', 'h', 'h'
    }, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the fill method with array of chars and indexes as parameters.
 */

void fillTest6() {
    const int32_t length = 5;
    char *a;
    bool b;
    a = new char[5]();
    Arrays::fill(a, 1, 4, 'h');
    b = Arrays::equals(a, length, new char[length] {
        '\0', 'h', 'h', 'h', '\0'
    }, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the fill method with array of doubles.
 */

void fillTest7() {
    const int32_t length = 5;
    double *a;
    bool b;
    a = new double[5]();
    Arrays::fill(a, length, 8.0);
    b = Arrays::equals(a, length, new double[length] {
        8.0, 8.0, 8.0, 8.0, 8.0
    }, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the fill method with array of doubles and indexes as parameters.
 */

void fillTest8() {
    const int32_t length = 5;
    double *a;
    bool b;
    a = new double[5]();
    Arrays::fill(a, 1, 4, 8.0);
    b = Arrays::equals(a, length, new double[length] {
        0.0, 8.0, 8.0, 8.0, 0.0
    }, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the fill method with array of floats.
 */

void fillTest9() {
    const int32_t length = 5;
    float *a;
    bool b;
    a = new float[5]();
    Arrays::fill(a, length, 8.0F);
    b = Arrays::equals(a, length, new float[length] {
        8.0F, 8.0F, 8.0F, 8.0F, 8.0F
    }, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the fill method with array of floats and indexes as parameters.
 */

void fillTest10() {
    const int32_t length = 5;
    float *a;
    bool b;
    a = new float[5]();
    Arrays::fill(a, 1, 4, 8.0F);
    b = Arrays::equals(a, length, new float[length] {
        0.0F, 8.0F, 8.0F, 8.0F, 0.0F
    }, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the fill method with array of ints.
 */

void fillTest11() {
    const int32_t length = 5;
    int32_t *a;
    bool b;
    a = new int32_t[5]();
    Arrays::fill(a, length, 8);
    b = Arrays::equals(a, length, new int32_t[length]{8, 8, 8, 8, 8}, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the fill method with array of ints and indexes as parameters.
 */

void fillTest12() {
    const int32_t length = 5;
    int32_t *a;
    bool b;
    a = new int32_t[5]();
    Arrays::fill(a, 1, 4, 8);
    b = Arrays::equals(a, length, new int32_t[length]{0, 8, 8, 8, 0}, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the fill method with array of longs.
 */

void fillTest13() {
    const int32_t length = 5;
    int64_t *a;
    bool b;
    a = new int64_t[5]();
    Arrays::fill(a, length, 8L);
    b = Arrays::equals(a, length, new int64_t[length]{8, 8, 8, 8, 8}, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the fill method with array of longs and indexes as parameters.
 */

void fillTest14() {
    const int32_t length = 5;
    int64_t *a;
    bool b;
    a = new int64_t[5]();
    Arrays::fill(a, 1, 4, 8L);
    b = Arrays::equals(a, length, new int64_t[length]{0, 8, 8, 8, 0}, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the fill method with array of objects.
 */

void fillTest15() {
    const int32_t length = 5;
    TestObject **a, **c;
    bool b;
    a = new TestObject *[5]();
    Arrays::fill((Object **) a, length, new TestObject(new String("sixth"), 6));
    c = new TestObject *[length];
    c[0] = new TestObject(new String("sixth"), 6);
    c[1] = new TestObject(new String("sixth"), 6);
    c[2] = new TestObject(new String("sixth"), 6);
    c[3] = new TestObject(new String("sixth"), 6);
    c[4] = new TestObject(new String("sixth"), 6);
    b = Arrays::equals((Object **) a, length, (Object **) c, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the fill method with array of objects and indexes as parameters.
 */

void fillTest16() {
    const int32_t length = 5;
    TestObject **a, **c;
    bool b;
    a = new TestObject *[5]();
    Arrays::fill((Object **) a, 1, 4, new TestObject(new String("sixth"), 6));
    c = new TestObject *[length];
    c[0] = nullptr;
    c[1] = new TestObject(new String("sixth"), 6);
    c[2] = new TestObject(new String("sixth"), 6);
    c[3] = new TestObject(new String("sixth"), 6);
    c[4] = nullptr;
    b = Arrays::equals((Object **) a, length, (Object **) c, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the fill method with array of shorts.
 */

void fillTest17() {
    const int32_t length = 5;
    int16_t *a;
    bool b;
    a = new int16_t[5]();
    Arrays::fill(a, length, (int16_t) 8);
    b = Arrays::equals(a, length, new int16_t[length]{8, 8, 8, 8, 8}, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the fill method with array of shorts and indexes as parameters.
 */

void fillTest18() {
    const int32_t length = 5;
    int16_t *a;
    bool b;
    a = new int16_t[5]();
    Arrays::fill(a, 1, 4, (int16_t) 8);
    b = Arrays::equals(a, length, new int16_t[length]{0, 8, 8, 8, 0}, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the sort method with array of bytes.
 */

void sortTest() {
    const int32_t length = 5;
    int8_t *a;
    bool b;
    // the array for sorting
    a = new int8_t[length]{(int8_t) 3, (int8_t) 2, (int8_t) 8, (int8_t) 7, (int8_t) 6};
    Arrays::sort(a, length);
    b = Arrays::equals(a, length, new int8_t[length]{2, 3, 6, 7, 8}, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the sort method with array of bytes and indexes as parameters.
 */

void sortTest2() {
    const int32_t length = 5;
    int8_t *a;
    bool b;
    // the array for partial sorting
    a = new int8_t[length]{(int8_t) 3, (int8_t) 2, (int8_t) 8, (int8_t) 7, (int8_t) 6};
    Arrays::sort(a, 1, 4);
    b = Arrays::equals(a, length, new int8_t[length]{3, 2, 7, 8, 6}, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the sort method with array of chars.
 */

void sortTest3() {
    const int32_t length = 5;
    char *a;
    bool b;
    a = new char[length] {
        'c', 'b', 'h', 'g', 'f'
    };
    Arrays::sort(a, length);
    b = Arrays::equals(a, length, new char[length] {
        'b', 'c', 'f', 'g', 'h'
    }, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the sort method with array of chars and indexes as parameters.
 */

void sortTest4() {
    const int32_t length = 5;
    char *a;
    bool b;
    a = new char[length] {
        'c', 'b', 'h', 'g', 'f'
    };
    Arrays::sort(a, 1, 4);
    b = Arrays::equals(a, length, new char[length] {
        'c', 'b', 'g', 'h', 'f'
    }, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the sort method with array of doubles.
 */

void sortTest5() {
    const int32_t length = 5;
    double *a;
    bool b;
    a = new double[length] {
        3.0, 2.0, 8.0, 7.0, 6.0
    };
    Arrays::sort(a, length);
    b = Arrays::equals(a, length, new double[length] {
        2.0, 3.0, 6.0, 7.0, 8.0
    }, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the sort method with array of doubles and indexes as parameters.
 */

void sortTest6() {
    const int32_t length = 5;
    double *a;
    bool b;
    a = new double[length] {
        3.0, 2.0, 8.0, 7.0, 6.0
    };
    Arrays::sort(a, 1, 4);
    b = Arrays::equals(a, length, new double[length] {
        3.0, 2.0, 7.0, 8.0, 6.0
    }, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the sort method with array of floats.
 */

void sortTest7() {
    const int32_t length = 5;
    float *a;
    bool b;
    a = new float[length] {
        3.0F, 2.0F, 8.0F, 7.0F, 6.0F
    };
    Arrays::sort(a, length);
    b = Arrays::equals(a, length, new float[length] {
        2.0F, 3.0F, 6.0F, 7.0F, 8.0F
    }, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the sort method with array of floats and indexes as parameters.
 */

void sortTest8() {
    const int32_t length = 5;
    float *a;
    bool b;
    a = new float[length] {
        3.0F, 2.0F, 8.0F, 7.0F, 6.0F
    };
    Arrays::sort(a, 1, 4);
    b = Arrays::equals(a, length, new float[length] {
        3.0F, 2.0F, 7.0F, 8.0F, 6.0F
    }, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the sort method with array of ints.
 */

void sortTest9() {
    const int32_t length = 5;
    int32_t *a;
    bool b;
    a = new int32_t[length]{3, 2, 8, 7, 6};
    Arrays::sort(a, length);
    b = Arrays::equals(a, length, new int32_t[length]{2, 3, 6, 7, 8}, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the sort method with array of ints and indexes as parameters.
 */

void sortTest10() {
    const int32_t length = 5;
    int32_t *a;
    bool b;
    a = new int32_t[length]{3, 2, 8, 7, 6};
    Arrays::sort(a, 1, 4);
    b = Arrays::equals(a, length, new int32_t[length]{3, 2, 7, 8, 6}, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the sort method with array of longs.
 */

void sortTest11() {
    const int32_t length = 5;
    int64_t *a;
    bool b;
    a = new int64_t[length]{3L, 2L, 8L, 7L, 6L};
    Arrays::sort(a, length);
    b = Arrays::equals(a, length, new int64_t[length]{2, 3, 6, 7, 8}, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the sort method with array of longs and indexes as parameters.
 */

void sortTest12() {
    const int32_t length = 5;
    int64_t *a;
    bool b;
    a = new int64_t[length]{3L, 2L, 8L, 7L, 6L};
    Arrays::sort(a, 1, 4);
    b = Arrays::equals(a, length, new int64_t[length]{3, 2, 7, 8, 6}, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the sort method with array of objects.
 */

void sortTest13() {
    const int32_t length = 10;
    Object **a, **c;
    bool b;
    a = new Object *[length];
    a[0] = new TestObject(new String("first"), 3);
    a[1] = new TestObject(new String("second"), 2);
    a[2] = new TestObject(new String("third"), 8);
    a[3] = new TestObject(new String("fourth"), 7);
    a[4] = new TestObject(new String("fifth"), 6);
    a[5] = new TestObject(new String("sixth"), 3);
    a[6] = new TestObject(new String("seventh"), 2);
    a[7] = new TestObject(new String("eighth"), 8);
    a[8] = new TestObject(new String("nineth"), 7);
    a[9] = new TestObject(new String("tenth"), 6);
    Arrays::sort(a, length);
    c = new Object *[length];
    c[0] = new TestObject(new String("second"), 2);
    c[1] = new TestObject(new String("seventh"), 2);
    c[2] = new TestObject(new String("first"), 3);
    c[3] = new TestObject(new String("sixth"), 3);
    c[4] = new TestObject(new String("fifth"), 6);
    c[5] = new TestObject(new String("tenth"), 6);
    c[6] = new TestObject(new String("fourth"), 7);
    c[7] = new TestObject(new String("nineth"), 7);
    c[8] = new TestObject(new String("third"), 8);
    c[9] = new TestObject(new String("eighth"), 8);
    b = Arrays::equals(a, length, c, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the sort method with array of objects and indexes as parameters.
 */

void sortTest14() {
    const int32_t length = 10;
    Object **a, **c;
    bool b;
    a = new Object *[length];
    a[0] = new TestObject(new String("first"), 3);
    a[1] = new TestObject(new String("second"), 2);
    a[2] = new TestObject(new String("third"), 8);
    a[3] = new TestObject(new String("fourth"), 7);
    a[4] = new TestObject(new String("fifth"), 6);
    a[5] = new TestObject(new String("sixth"), 3);
    a[6] = new TestObject(new String("seventh"), 2);
    a[7] = new TestObject(new String("eighth"), 8);
    a[8] = new TestObject(new String("nineth"), 7);
    a[9] = new TestObject(new String("tenth"), 6);
    Arrays::sort(a, 1, 4);
    c = new Object *[length];
    c[0] = new TestObject(new String("first"), 3);
    c[1] = new TestObject(new String("second"), 2);
    c[2] = new TestObject(new String("fourth"), 7);
    c[3] = new TestObject(new String("third"), 8);
    c[4] = new TestObject(new String("fifth"), 6);
    c[5] = new TestObject(new String("sixth"), 3);
    c[6] = new TestObject(new String("seventh"), 2);
    c[7] = new TestObject(new String("eighth"), 8);
    c[8] = new TestObject(new String("nineth"), 7);
    c[9] = new TestObject(new String("tenth"), 6);
    b = Arrays::equals(a, length, c, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the sort method with array of shorts.
 */

void sortTest15() {
    const int32_t length = 5;
    int16_t *a;
    bool b;
    a = new int16_t[length]{(int16_t) 3, (int16_t) 2, (int16_t) 8, (int16_t) 7, (int16_t) 6};
    Arrays::sort(a, length);
    b = Arrays::equals(a, length, new int16_t[length]{2, 3, 6, 7, 8}, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the sort method with array of shorts and indexes as parameters.
 */

void sortTest16() {
    const int32_t length = 5;
    int16_t *a;
    bool b;
    a = new int16_t[length]{(int16_t) 3, (int16_t) 2, (int16_t) 8, (int16_t) 7, (int16_t) 6};
    Arrays::sort(a, 1, 4);
    b = Arrays::equals(a, length, new int16_t[length]{3, 2, 7, 8, 6}, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the sort method with array of objects and comparator as a
 * parameter.
 */

void sortTest17() {
    const int32_t length = 10;
    TestObject **a, **d;
    bool b;
    Comparator *c;
    a = new TestObject *[length];
    a[0] = new TestObject(new String("first"), 3);
    a[1] = new TestObject(new String("second"), 2);
    a[2] = new TestObject(new String("third"), 8);
    a[3] = new TestObject(new String("fourth"), 7);
    a[4] = new TestObject(new String("fifth"), 6);
    a[5] = new TestObject(new String("sixth"), 3);
    a[6] = new TestObject(new String("seventh"), 2);
    a[7] = new TestObject(new String("eighth"), 8);
    a[8] = new TestObject(new String("nineth"), 7);
    a[9] = new TestObject(new String("tenth"), 6);
    c = new TestObjectComparator();
    Arrays::sort((Object **)a, length, c);
    d = new TestObject *[length];
    d[0] = new TestObject(new String("second"), 2);
    d[1] = new TestObject(new String("seventh"), 2);
    d[2] = new TestObject(new String("first"), 3);
    d[3] = new TestObject(new String("sixth"), 3);
    d[4] = new TestObject(new String("fifth"), 6);
    d[5] = new TestObject(new String("tenth"), 6);
    d[6] = new TestObject(new String("fourth"), 7);
    d[7] = new TestObject(new String("nineth"), 7);
    d[8] = new TestObject(new String("third"), 8);
    d[9] = new TestObject(new String("eighth"), 8);
    b = Arrays::equals((Object **) a, length, (Object **) d, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the sort method with array of objects and indexes and comparator as
 * parameters.
 */

void sortTest18() {
    const int32_t length = 10;
    TestObject **a, **d;
    bool b;
    Comparator *c;
    a = new TestObject *[length];
    a[0] = new TestObject(new String("first"), 3);
    a[1] = new TestObject(new String("second"), 2);
    a[2] = new TestObject(new String("third"), 8);
    a[3] = new TestObject(new String("fourth"), 7);
    a[4] = new TestObject(new String("fifth"), 6);
    a[5] = new TestObject(new String("sixth"), 3);
    a[6] = new TestObject(new String("seventh"), 2);
    a[7] = new TestObject(new String("eighth"), 8);
    a[8] = new TestObject(new String("nineth"), 7);
    a[9] = new TestObject(new String("tenth"), 6);
    c = new TestObjectComparator();
    Arrays::sort((Object **)a, 1, 4, c);
    d = new TestObject *[length];
    d[0] = new TestObject(new String("first"), 3);
    d[1] = new TestObject(new String("second"), 2);
    d[2] = new TestObject(new String("fourth"), 7);
    d[3] = new TestObject(new String("third"), 8);
    d[4] = new TestObject(new String("fifth"), 6);
    d[5] = new TestObject(new String("sixth"), 3);
    d[6] = new TestObject(new String("seventh"), 2);
    d[7] = new TestObject(new String("eighth"), 8);
    d[8] = new TestObject(new String("nineth"), 7);
    d[9] = new TestObject(new String("tenth"), 6);
    b = Arrays::equals((Object **) a, length, (Object **) d, length);
    Test::assertEquals(true, b);
}

/**
 * Tests the toString method with array of booleans.
 */

void toStringTest() {
    const int32_t length = 0;
    const int32_t length2 = 1;
    const int32_t length3 = 5;
    bool *a;
    String *b;
    // the text represenation of an empty array
    a = new bool[length] {
    };
    b = Arrays::toString(a, length);
    Test::assertEquals("[]", b->_s());
    // the text represenation of an array with one element
    a = new bool[length2] {
        true
    };
    b = Arrays::toString(a, length2);
    Test::assertEquals("[true]", b->_s());
    // the text represenation of an array with some elements
    a = new bool[length3] {
        true, false, false, false, true
    };
    b = Arrays::toString(a, length3);
    Test::assertEquals("[true, false, false, false, true]", b->_s());
}

/**
 * Tests the toString method with array of bytes.
 */

void toStringTest2() {
    const int32_t length = 0;
    const int32_t length2 = 1;
    const int32_t length3 = 5;
    int8_t *a;
    String *b;
    a = new int8_t[length]{};
    b = Arrays::toString(a, length);
    Test::assertEquals("[]", b->_s());
    a = new int8_t[length2]{(int8_t) 3};
    b = Arrays::toString(a, length2);
    Test::assertEquals("[3]", b->_s());
    a = new int8_t[length3]{(int8_t) 3, (int8_t) 2, (int8_t) 8, (int8_t) 7, (int8_t) 6};
    b = Arrays::toString(a, length3);
    Test::assertEquals("[3, 2, 8, 7, 6]", b->_s());
}

/**
 * Tests the toString method with array of chars.
 */

void toStringTest3() {
    const int32_t length = 0;
    const int32_t length2 = 1;
    const int32_t length3 = 5;
    char *a;
    String *b;
    a = new char[length] {
    };
    b = Arrays::toString(a, length);
    Test::assertEquals("[]", b->_s());
    a = new char[length2] {
        'c'
    };
    b = Arrays::toString(a, length2);
    Test::assertEquals("[c]", b->_s());
    a = new char[length3] {
        'c', 'b', 'h', 'g', 'f'
    };
    b = Arrays::toString(a, length3);
    Test::assertEquals("[c, b, h, g, f]", b->_s());
}

/**
 * Tests the toString method with array of doubles.
 */

void toStringTest4() {
    const int32_t length = 0;
    const int32_t length2 = 1;
    const int32_t length3 = 5;
    double *a;
    String *b;
    a = new double[length] {
    };
    b = Arrays::toString(a, length);
    Test::assertEquals("[]", b->_s());
    a = new double[length2] {
        3.0
    };
    b = Arrays::toString(a, length2);
    Test::assertEquals("[3.0]", b->_s());
    a = new double[length3] {
        3.0, 2.0, 8.0, 7.0, 6.0
    };
    b = Arrays::toString(a, length3);
    Test::assertEquals("[3.0, 2.0, 8.0, 7.0, 6.0]", b->_s());
}

/**
 * Tests the toString method with array of floats.
 */

void toStringTest5() {
    const int32_t length = 0;
    const int32_t length2 = 1;
    const int32_t length3 = 5;
    float *a;
    String *b;
    a = new float[length] {
    };
    b = Arrays::toString(a, length);
    Test::assertEquals("[]", b->_s());
    a = new float[length2] {
        3.0F
    };
    b = Arrays::toString(a, length2);
    Test::assertEquals("[3.0]", b->_s());
    a = new float[length3] {
        3.0F, 2.0F, 8.0F, 7.0F, 6.0F
    };
    b = Arrays::toString(a, length3);
    Test::assertEquals("[3.0, 2.0, 8.0, 7.0, 6.0]", b->_s());
}

/**
 * Tests the toString method with array of ints.
 */

void toStringTest6() {
    const int32_t length = 0;
    const int32_t length2 = 1;
    const int32_t length3 = 5;
    int32_t *a;
    String *b;
    a = new int32_t[length]{};
    b = Arrays::toString(a, length);
    Test::assertEquals("[]", b->_s());
    a = new int32_t[length2]{3};
    b = Arrays::toString(a, length2);
    Test::assertEquals("[3]", b->_s());
    a = new int32_t[length3]{3, 2, 8, 7, 6};
    b = Arrays::toString(a, length3);
    Test::assertEquals("[3, 2, 8, 7, 6]", b->_s());
}

/**
 * Tests the toString method with array of longs.
 */

void toStringTest7() {
    const int32_t length = 0;
    const int32_t length2 = 1;
    const int32_t length3 = 5;
    int64_t *a;
    String *b;
    a = new int64_t[length]{};
    b = Arrays::toString(a, length);
    Test::assertEquals("[]", b->_s());
    a = new int64_t[length2]{3L};
    b = Arrays::toString(a, length2);
    Test::assertEquals("[3]", b->_s());
    a = new int64_t[length3]{3L, 2L, 8L, 7L, 6L};
    b = Arrays::toString(a, length3);
    Test::assertEquals("[3, 2, 8, 7, 6]", b->_s());
}

/**
 * Tests the toString method with array of objects.
 */

void toStringTest8() {
    const int32_t length = 0;
    const int32_t length2 = 1;
    const int32_t length3 = 3;
    Object **a;
    String *b;
    a = new Object *[length];
    b = Arrays::toString(a, length);
    Test::assertEquals("[]", b->_s());
    a = new Object *[length2];
    a[0] = new TestObject(new String("first"), 1);
    b = Arrays::toString(a, length2);
    Test::assertEquals("[TestObject [str=first, i=1]]", b->_s());
    a = new Object *[length2];
    a[0] = NULL;
    b = Arrays::toString(a, length2);
    Test::assertEquals("[null]", b->_s());
    a = new Object *[length3];
    a[0] = new TestObject(new String("first"), 1);
    a[1] = new TestObject(new String("second"), 2);
    a[2] = new TestObject(new String("third"), 3);
    b = Arrays::toString(a, length3);
    Test::assertEquals("[TestObject [str=first, i=1], TestObject [str=second, i=2], TestObject [str=third, i=3]]", b->_s());
    a = new Object *[length3];
    a[0] = new TestObject(new String("first"), 1);
    a[1] = NULL;
    a[2] = new TestObject(new String("third"), 3);
    b = Arrays::toString(a, length3);
    Test::assertEquals("[TestObject [str=first, i=1], null, TestObject [str=third, i=3]]", b->_s());
    a = new Object *[length3];
    a[0] = NULL;
    a[1] = NULL;
    a[2] = NULL;
    b = Arrays::toString(a, length3);
    Test::assertEquals("[null, null, null]", b->_s());
}

/**
 * Tests the toString method with array of shorts.
 */

void toStringTest9() {
    const int32_t length = 0;
    const int32_t length2 = 1;
    const int32_t length3 = 5;
    int16_t *a;
    String *b;
    a = new int16_t[length]{};
    b = Arrays::toString(a, length);
    Test::assertEquals("[]", b->_s());
    a = new int16_t[length2]{(int16_t) 3};
    b = Arrays::toString(a, length2);
    Test::assertEquals("[3]", b->_s());
    a = new int16_t[length3]{(int16_t) 3, (int16_t) 2, (int16_t) 8, (int16_t) 7, (int16_t) 6};
    b = Arrays::toString(a, length3);
    Test::assertEquals("[3, 2, 8, 7, 6]", b->_s());
}

int main(int argc, char** argv) {
    Test::setUpTestModule("ArraysTest");

    Test::registerTest(binarySearchTest, "binarySearchTest");
    Test::registerTest(binarySearchTest2, "binarySearchTest2");
    Test::registerTest(binarySearchTest3, "binarySearchTest3");
    Test::registerTest(binarySearchTest4, "binarySearchTest4");
    Test::registerTest(binarySearchTest5, "binarySearchTest5");
    Test::registerTest(binarySearchTest6, "binarySearchTest6");
    Test::registerTest(binarySearchTest7, "binarySearchTest7");
    Test::registerTest(binarySearchTest8, "binarySearchTest8");
    Test::registerTest(binarySearchTest9, "binarySearchTest9");
    Test::registerTest(binarySearchTest10, "binarySearchTest10");
    Test::registerTest(binarySearchTest11, "binarySearchTest11");
    Test::registerTest(binarySearchTest12, "binarySearchTest12");
    Test::registerTest(binarySearchTest13, "binarySearchTest13");
    Test::registerTest(binarySearchTest14, "binarySearchTest14");
    Test::registerTest(binarySearchTest15, "binarySearchTest15");
    Test::registerTest(binarySearchTest16, "binarySearchTest16");
    Test::registerTest(binarySearchTest17, "binarySearchTest17");
    Test::registerTest(binarySearchTest18, "binarySearchTest18");
    Test::registerTest(copyOfTest, "copyOfTest");
    Test::registerTest(copyOfTest2, "copyOfTest2");
    Test::registerTest(copyOfTest3, "copyOfTest3");
    Test::registerTest(copyOfTest4, "copyOfTest4");
    Test::registerTest(copyOfTest5, "copyOfTest5");
    Test::registerTest(copyOfTest6, "copyOfTest6");
    Test::registerTest(copyOfTest7, "copyOfTest7");
    Test::registerTest(copyOfTest8, "copyOfTest8");
    Test::registerTest(copyOfTest9, "copyOfTest9");
    Test::registerTest(copyOfRangeTest, "copyOfRangeTest");
    Test::registerTest(copyOfRangeTest2, "copyOfRangeTest2");
    Test::registerTest(copyOfRangeTest3, "copyOfRangeTest3");
    Test::registerTest(copyOfRangeTest4, "copyOfRangeTest4");
    Test::registerTest(copyOfRangeTest5, "copyOfRangeTest5");
    Test::registerTest(copyOfRangeTest6, "copyOfRangeTest6");
    Test::registerTest(copyOfRangeTest7, "copyOfRangeTest7");
    Test::registerTest(copyOfRangeTest8, "copyOfRangeTest8");
    Test::registerTest(copyOfRangeTest9, "copyOfRangeTest9");
    Test::registerTest(equalsTest, "equalsTest");
    Test::registerTest(equalsTest2, "equalsTest2");
    Test::registerTest(equalsTest3, "equalsTest3");
    Test::registerTest(equalsTest4, "equalsTest4");
    Test::registerTest(equalsTest5, "equalsTest5");
    Test::registerTest(equalsTest6, "equalsTest6");
    Test::registerTest(equalsTest7, "equalsTest7");
    Test::registerTest(equalsTest8, "equalsTest8");
    Test::registerTest(equalsTest9, "equalsTest9");
    Test::registerTest(fillTest, "fillTest");
    Test::registerTest(fillTest2, "fillTest2");
    Test::registerTest(fillTest3, "fillTest3");
    Test::registerTest(fillTest4, "fillTest4");
    Test::registerTest(fillTest5, "fillTest5");
    Test::registerTest(fillTest6, "fillTest6");
    Test::registerTest(fillTest7, "fillTest7");
    Test::registerTest(fillTest8, "fillTest8");
    Test::registerTest(fillTest9, "fillTest9");
    Test::registerTest(fillTest10, "fillTest10");
    Test::registerTest(fillTest11, "fillTest11");
    Test::registerTest(fillTest12, "fillTest12");
    Test::registerTest(fillTest13, "fillTest13");
    Test::registerTest(fillTest14, "fillTest14");
    Test::registerTest(fillTest15, "fillTest15");
    Test::registerTest(fillTest16, "fillTest16");
    Test::registerTest(fillTest17, "fillTest17");
    Test::registerTest(fillTest18, "fillTest18");
    Test::registerTest(sortTest, "sortTest");
    Test::registerTest(sortTest2, "sortTest2");
    Test::registerTest(sortTest3, "sortTest3");
    Test::registerTest(sortTest4, "sortTest4");
    Test::registerTest(sortTest5, "sortTest5");
    Test::registerTest(sortTest6, "sortTest6");
    Test::registerTest(sortTest7, "sortTest7");
    Test::registerTest(sortTest8, "sortTest8");
    Test::registerTest(sortTest9, "sortTest9");
    Test::registerTest(sortTest10, "sortTest10");
    Test::registerTest(sortTest11, "sortTest11");
    Test::registerTest(sortTest12, "sortTest12");
    Test::registerTest(sortTest13, "sortTest13");
    Test::registerTest(sortTest14, "sortTest14");
    Test::registerTest(sortTest15, "sortTest15");
    Test::registerTest(sortTest16, "sortTest16");
    Test::registerTest(sortTest17, "sortTest17");
    Test::registerTest(sortTest18, "sortTest18");
    Test::registerTest(toStringTest, "toStringTest");
    Test::registerTest(toStringTest2, "toStringTest2");
    Test::registerTest(toStringTest3, "toStringTest3");
    Test::registerTest(toStringTest4, "toStringTest4");
    Test::registerTest(toStringTest5, "toStringTest5");
    Test::registerTest(toStringTest6, "toStringTest6");
    Test::registerTest(toStringTest7, "toStringTest7");
    Test::registerTest(toStringTest8, "toStringTest8");
    Test::registerTest(toStringTest9, "toStringTest9");

    Test::runTests();

    return (EXIT_SUCCESS);
}