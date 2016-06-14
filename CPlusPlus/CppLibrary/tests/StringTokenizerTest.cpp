#include <cstdlib>
#include <iostream>

#include "test.h"
#include "StringTokenizer.h"
#include "String_.h"
#include "Arrays.h"

/*
 * Simple C++ Test Suite
 */

typedef struct {
    String **arr;
    int32_t len;
} StringArray;

/*
 Creates the array of tokens which are created the from tokenized string.
 */
StringArray toStringArray(StringTokenizer *a) {
    String **b;
    int32_t c;
    c = a->countTokens();
    b = new String *[c];
    
    for (int32_t i = 0; i < c; i++) {
        b[i] = a->nextToken();
    }

    StringArray strArr;
    strArr.arr = b;
    strArr.len = c;
    return strArr;
}

/**
 * Tests the constructor.
 */

void stringTokenizerTest() {
    const int32_t length = 4;
    const int32_t length2 = 1;
    const int32_t length3 = 0;
    StringTokenizer *a;
    StringArray b;
    String **c;
    bool d;
    // whitespaces inside the string
    a = new StringTokenizer(new String("This is a test."));
    b = toStringArray(a);
    c = new String *[length];
    c[0] = new String("This");
    c[1] = new String("is");
    c[2] = new String("a");
    c[3] = new String("test.");
    d = Arrays::equals((Object **)c, length, (Object **)b.arr, b.len);
    Test::assertEquals(true, d);
    // whitespaces inside and outside the string
    a = new StringTokenizer(new String(" This is   a test. "));
    b = toStringArray(a);
    c = new String *[length];
    c[0] = new String("This");
    c[1] = new String("is");
    c[2] = new String("a");
    c[3] = new String("test.");
    d = Arrays::equals((Object **)c, length, (Object **)b.arr, b.len);
    Test::assertEquals(true, d);
    // without whitespaces
    a = new StringTokenizer(new String("This_is_a_test."));
    b = toStringArray(a);
    c = new String *[length2];
    c[0] = new String("This_is_a_test.");
    d = Arrays::equals((Object **)c, length2, (Object **)b.arr, b.len);
    Test::assertEquals(true, d);
    // one character
    a = new StringTokenizer(new String("_"));
    b = toStringArray(a);
    c = new String *[length2];
    c[0] = new String("_");
    d = Arrays::equals((Object **)c, length2, (Object **)b.arr, b.len);
    Test::assertEquals(true, d);
    // empty string
    a = new StringTokenizer(new String(""));
    b = toStringArray(a);
    c = new String *[length3];
    d = Arrays::equals((Object **)c, length3, (Object **)b.arr, b.len);
    Test::assertEquals(true, d);
}

/**
 * Tests the constructor with a set of delimiters as a parameter.
 */

void stringTokenizerTest2() {
    const int32_t length = 1;
    const int32_t length2 = 4;
    StringTokenizer *a;
    StringArray b;
    String **c;
    bool d;
    // non-white delimiter (non-existent in string)
    a = new StringTokenizer(new String("This is a test."), new String("_"));
    b = toStringArray(a);
    c = new String *[length];
    c[0] = new String("This is a test.");
    d = Arrays::equals((Object **)c, length, (Object **)b.arr, b.len);
    Test::assertEquals(true, d);
    // non-white delimiter (inside the string)
    a = new StringTokenizer(new String("This_is_a_test."), new String("_"));
    b = toStringArray(a);
    c = new String *[length2];
    c[0] = new String("This");
    c[1] = new String("is");
    c[2] = new String("a");
    c[3] = new String("test.");
    d = Arrays::equals((Object **)c, length2, (Object **)b.arr, b.len);
    Test::assertEquals(true, d);
    // non-white delimiter (also the whitespaces inside the string)
    a = new StringTokenizer(new String("This_is_ a _test."), new String("_"));
    b = toStringArray(a);
    c = new String *[length2];
    c[0] = new String("This");
    c[1] = new String("is");
    c[2] = new String(" a ");
    c[3] = new String("test.");
    d = Arrays::equals((Object **)c, length2, (Object **)b.arr, b.len);
    Test::assertEquals(true, d);
    // non-white delimiter (also the whitespaces inside and outside the string)
    a = new StringTokenizer(new String("_This_is___a_test._"), new String("_"));
    b = toStringArray(a);
    c = new String *[length2];
    c[0] = new String("This");
    c[1] = new String("is");
    c[2] = new String("a");
    c[3] = new String("test.");
    d = Arrays::equals((Object **)c, length2, (Object **)b.arr, b.len);
    Test::assertEquals(true, d);
    // more delimiters (existing in the string)
    a = new StringTokenizer(new String("This is_a test."), new String(" _"));
    b = toStringArray(a);
    c = new String *[length2];
    c[0] = new String("This");
    c[1] = new String("is");
    c[2] = new String("a");
    c[3] = new String("test.");
    d = Arrays::equals((Object **)c, length2, (Object **)b.arr, b.len);
    Test::assertEquals(true, d);
    // more delimiters (non-existent in the string)
    a = new StringTokenizer(new String("Thisisatest."), new String(" _"));
    b = toStringArray(a);
    c = new String *[length];
    c[0] = new String("Thisisatest.");
    d = Arrays::equals((Object **)c, length, (Object **)b.arr, b.len);
    Test::assertEquals(true, d);
}

/**
 * Tests the countTokens method.
 */

void countTokensTest() {
    StringTokenizer *a;
    int32_t b;
    // tokenize with whitespaces as delimiters
    a = new StringTokenizer(new String("This is a test."));
    b = a->countTokens();
    Test::assertEquals(4, b);
    // tokenize with whitespaces as delimiters (more whitespaces)
    a = new StringTokenizer(new String(" This is   a test. "));
    b = a->countTokens();
    Test::assertEquals(4, b);
    // tokenize with whitespaces as delimiters (no whitespaces)
    a = new StringTokenizer(new String("This_is_a_test."));
    b = a->countTokens();
    Test::assertEquals(1, b);
    // tokenize with non-white characters as delimiters
    a = new StringTokenizer(new String("This_is_a_test."), new String("_"));
    b = a->countTokens();
    Test::assertEquals(4, b);
    // tokenize an empty string
    a = new StringTokenizer(new String(""));
    b = a->countTokens();
    Test::assertEquals(0, b);
}

/**
 * Tests the hasMoreTokens method.
 */

void hasMoreTokensTest() {
    StringTokenizer *a;
    bool b;
    a = new StringTokenizer(new String("This is a test."));
    b = a->hasMoreTokens();
    Test::assertEquals(true, b);
    a = new StringTokenizer(new String(" This is   a test. "));
    b = a->hasMoreTokens();
    Test::assertEquals(true, b);
    a = new StringTokenizer(new String("This_is_a_test."));
    b = a->hasMoreTokens();
    Test::assertEquals(true, b);
    a = new StringTokenizer(new String("This_is_a_test."), new String("_"));
    b = a->hasMoreTokens();
    Test::assertEquals(true, b);
    a = new StringTokenizer(new String(""));
    b = a->hasMoreTokens();
    Test::assertEquals(false, b);
}

/**
 * Tests the nextToken method.
 */

void nextTokenTest() {
    StringTokenizer *a;
    String *b;
    // a test string
    a = new StringTokenizer(new String("This is a test."));
    b = a->nextToken();
    Test::assertEquals("This", b->_s());
    b = a->nextToken();
    Test::assertEquals("is", b->_s());
    b = a->nextToken();
    Test::assertEquals("a", b->_s());
    b = a->nextToken();
    Test::assertEquals("test.", b->_s());
}

int main(int argc, char** argv) {
    Test::setUpTestModule("StringTokenizerTest");

    Test::registerTest(stringTokenizerTest, "stringTokenizerTest");
    Test::registerTest(stringTokenizerTest2, "stringTokenizerTest2");
    Test::registerTest(countTokensTest, "countTokensTest");
    Test::registerTest(hasMoreTokensTest, "hasMoreTokensTest");
    Test::registerTest(nextTokenTest, "nextTokenTest");
    
    Test::runTests();

    return (EXIT_SUCCESS);
}