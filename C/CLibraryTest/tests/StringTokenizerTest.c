#include <stdio.h>
#include <stdlib.h>

#include "test.h"
#include "StringTokenizer.h"
#include "String_.h"
#include "Arrays.h"

/**
 * A StringTokenizer module test suite.
 *
 * @author Petr Kozler (A13B0359P)
 */

/*
    StringArray structure wraps the array of tokens with its length.
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
    c = countTokens(a);
    b = malloc(c * sizeof(String *));
    
    for (int32_t i = 0; i < c; i++) {
        b[i] = nextToken(a);
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
    a = new_StringTokenizer(new_String("This is a test."));
    b = toStringArray(a);
    c = malloc(length * sizeof(String *));
    c[0] = new_String("This");
    c[1] = new_String("is");
    c[2] = new_String("a");
    c[3] = new_String("test.");
    d = Arrays_equalsObj(c, length, b.arr, b.len, equalsStr);
    assertEqualsBool(true, d);
    // whitespaces inside and outside the string
    a = new_StringTokenizer(new_String(" This is   a test. "));
    b = toStringArray(a);
    c = malloc(length * sizeof(String *));
    c[0] = new_String("This");
    c[1] = new_String("is");
    c[2] = new_String("a");
    c[3] = new_String("test.");
    d = Arrays_equalsObj(c, length, b.arr, b.len, equalsStr);
    assertEqualsBool(true, d);
    // without whitespaces
    a = new_StringTokenizer(new_String("This_is_a_test."));
    b = toStringArray(a);
    c = malloc(length2 * sizeof(String *));
    c[0] = new_String("This_is_a_test.");
    d = Arrays_equalsObj(c, length2, b.arr, b.len, equalsStr);
    assertEqualsBool(true, d);
    // one character
    a = new_StringTokenizer(new_String("_"));
    b = toStringArray(a);
    c = malloc(length2 * sizeof(String *));
    c[0] = new_String("_");
    d = Arrays_equalsObj(c, length2, b.arr, b.len, equalsStr);
    assertEqualsBool(true, d);
    // empty string
    a = new_StringTokenizer(new_String(""));
    b = toStringArray(a);
    c = malloc(length3 * sizeof(String *));
    d = Arrays_equalsObj(c, length3, b.arr, b.len, equalsStr);
    assertEqualsBool(true, d);
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
    a = new_StringTokenizerDelim(new_String("This is a test."), new_String("_"));
    b = toStringArray(a);
    c = malloc(length * sizeof(String *));
    c[0] = new_String("This is a test.");
    d = Arrays_equalsObj(c, length, b.arr, b.len, equalsStr);
    assertEqualsBool(true, d);
    // non-white delimiter (inside the string)
    a = new_StringTokenizerDelim(new_String("This_is_a_test."), new_String("_"));
    b = toStringArray(a);
    c = malloc(length2 * sizeof(String *));
    c[0] = new_String("This");
    c[1] = new_String("is");
    c[2] = new_String("a");
    c[3] = new_String("test.");
    d = Arrays_equalsObj(c, length2, b.arr, b.len, equalsStr);
    assertEqualsBool(true, d);
    // non-white delimiter (also the whitespaces inside the string)
    a = new_StringTokenizerDelim(new_String("This_is_ a _test."), new_String("_"));
    b = toStringArray(a);
    c = malloc(length2 * sizeof(String *));
    c[0] = new_String("This");
    c[1] = new_String("is");
    c[2] = new_String(" a ");
    c[3] = new_String("test.");
    d = Arrays_equalsObj(c, length2, b.arr, b.len, equalsStr);
    assertEqualsBool(true, d);
    // non-white delimiter (also the whitespaces inside and outside the string)
    a = new_StringTokenizerDelim(new_String("_This_is___a_test._"), new_String("_"));
    b = toStringArray(a);
    c = malloc(length2 * sizeof(String *));
    c[0] = new_String("This");
    c[1] = new_String("is");
    c[2] = new_String("a");
    c[3] = new_String("test.");
    d = Arrays_equalsObj(c, length2, b.arr, b.len, equalsStr);
    assertEqualsBool(true, d);
    // more delimiters (existing in the string)
    a = new_StringTokenizerDelim(new_String("This is_a test."), new_String(" _"));
    b = toStringArray(a);
    c = malloc(length2 * sizeof(String *));
    c[0] = new_String("This");
    c[1] = new_String("is");
    c[2] = new_String("a");
    c[3] = new_String("test.");
    d = Arrays_equalsObj(c, length2, b.arr, b.len, equalsStr);
    assertEqualsBool(true, d);
    // more delimiters (non-existent in the string)
    a = new_StringTokenizerDelim(new_String("Thisisatest."), new_String(" _"));
    b = toStringArray(a);
    c = malloc(length * sizeof(String *));
    c[0] = new_String("Thisisatest.");
    d = Arrays_equalsObj(c, length, b.arr, b.len, equalsStr);
    assertEqualsBool(true, d);
}

/**
 * Tests the countTokens function.
 */

void countTokensTest() {
    StringTokenizer *a;
    int32_t b;
    // tokenize with whitespaces as delimiters
    a = new_StringTokenizer(new_String("This is a test."));
    b = countTokens(a);
    assertEqualsI(4, b);
    // tokenize with whitespaces as delimiters (more whitespaces)
    a = new_StringTokenizer(new_String(" This is   a test. "));
    b = countTokens(a);
    assertEqualsI(4, b);
    // tokenize with whitespaces as delimiters (no whitespaces)
    a = new_StringTokenizer(new_String("This_is_a_test."));
    b = countTokens(a);
    assertEqualsI(1, b);
    // tokenize with non-white characters as delimiters
    a = new_StringTokenizerDelim(new_String("This_is_a_test."), new_String("_"));
    b = countTokens(a);
    assertEqualsI(4, b);
    // tokenize an empty string
    a = new_StringTokenizer(new_String(""));
    b = countTokens(a);
    assertEqualsI(0, b);
}

/**
 * Tests the hasMoreTokens function.
 */

void hasMoreTokensTest() {
    StringTokenizer *a;
    bool b;
    a = new_StringTokenizer(new_String("This is a test."));
    b = hasMoreTokens(a);
    assertEqualsBool(true, b);
    a = new_StringTokenizer(new_String(" This is   a test. "));
    b = hasMoreTokens(a);
    assertEqualsBool(true, b);
    a = new_StringTokenizer(new_String("This_is_a_test."));
    b = hasMoreTokens(a);
    assertEqualsBool(true, b);
    a = new_StringTokenizerDelim(new_String("This_is_a_test."), new_String("_"));
    b = hasMoreTokens(a);
    assertEqualsBool(true, b);
    a = new_StringTokenizer(new_String(""));
    b = hasMoreTokens(a);
    assertEqualsBool(false, b);
}

/**
 * Tests the nextToken function.
 */

void nextTokenTest() {
    StringTokenizer *a;
    String *b;
    // a test string
    a = new_StringTokenizer(new_String("This is a test."));
    b = nextToken(a);
    assertEqualsStr("This", b->s);
    b = nextToken(a);
    assertEqualsStr("is", b->s);
    b = nextToken(a);
    assertEqualsStr("a", b->s);
    b = nextToken(a);
    assertEqualsStr("test.", b->s);
}

int main(int argc, char** argv) {
    const int testCount = 5;
    setUpTestModule("StringTokenizerTest", testCount);

    registerTest(stringTokenizerTest, "stringTokenizerTest");
    registerTest(stringTokenizerTest2, "stringTokenizerTest2");
    registerTest(countTokensTest, "countTokensTest");
    registerTest(hasMoreTokensTest, "hasMoreTokensTest");
    registerTest(nextTokenTest, "nextTokenTest");
    
    runTests();

    return (EXIT_SUCCESS);
}
