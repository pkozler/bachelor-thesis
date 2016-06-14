#include <stdio.h>
#include <stdlib.h>

#include "test.h"
#include "Math_.h"
#include "Integer.h"
#include "Long.h"
#include "Float.h"
#include "Double.h"

/*
 * Simple C Test Suite
 */

const double DEFAULT_EPSILON = 1E-10;

/**
 * Tests the abs function with a double value.
 */

void absTest() {
    double a, b;
    // negative value
    a = Double_MIN_VALUE + 1;
    b = Math_absD(a);
    assertEqualsD(1.0, b, DEFAULT_EPSILON);
    // zero value
    a = 0;
    b = Math_absD(a);
    assertEqualsD(0.0, b, DEFAULT_EPSILON);
    // positive value
    a = Double_MAX_VALUE - 1;
    b = Math_absD(a);
    assertEqualsD(1.7976931348623157E308, b, DEFAULT_EPSILON);
}

/**
 * Tests the abs function with a float value.
 */

void absTest2() {
    float a, b;
    a = Float_MIN_VALUE + 1;
    b = Math_absF(a);
    assertEqualsF(1.0f, b, (float) DEFAULT_EPSILON);
    a = 0;
    b = Math_absF(a);
    assertEqualsF(0.0f, b, (float) DEFAULT_EPSILON);
    a = Float_MAX_VALUE - 1;
    b = Math_absF(a);
    assertEqualsF(3.4028235E38f, b, (float) DEFAULT_EPSILON);
}

/**
 * Tests the abs function with an int32_t value.
 */

void absTest3() {
    int32_t a, b;
    a = Integer_MIN_VALUE + 1;
    b = Math_absI(a);
    assertEqualsI(2147483647, b);
    a = 0;
    b = Math_absI(a);
    assertEqualsI(0, b);
    a = Integer_MAX_VALUE - 1;
    b = Math_absI(a);
    assertEqualsI(2147483646, b);
}

/**
 * Tests the abs function with a int64_t value.
 */

void absTest4() {
    int64_t a, b;
    a = Long_MIN_VALUE + 1LL;
    b = Math_absL(a);
    assertEqualsL(9223372036854775807LL, b);
    a = 0;
    b = Math_absL(a);
    assertEqualsL(0LL, b);
    a = Long_MAX_VALUE - 1LL;
    b = Math_absL(a);
    assertEqualsL(9223372036854775806LL, b);
}

/**
 * Tests the max function with a double value.
 */

void maxTest() {
    double a, b, c;
    // negative and positive value
    a = Double_MIN_VALUE;
    b = Double_MAX_VALUE;
    c = Math_maxD(a, b);
    assertEqualsD(1.7976931348623157E308, c, DEFAULT_EPSILON);
    // positive and negative value
    a = Double_MAX_VALUE;
    b = Double_MIN_VALUE;
    c = Math_maxD(a, b);
    assertEqualsD(1.7976931348623157E308, c, DEFAULT_EPSILON);
    // negative and positive value (smaller difference)
    a = -1;
    b = 1;
    c = Math_maxD(a, b);
    assertEqualsD(1.0, c, DEFAULT_EPSILON);
    // positive and negative value (bigger difference)
    a = 1;
    b = -1;
    c = Math_maxD(a, b);
    // equal values
    assertEqualsD(1.0, c, DEFAULT_EPSILON);
    a = 0;
    b = 0;
    c = Math_maxD(a, b);
    assertEqualsD(0.0, c, DEFAULT_EPSILON);
}

/**
 * Tests the max function with a float value.
 */

void maxTest2() {
    float a, b, c;
    a = Float_MIN_VALUE;
    b = Float_MAX_VALUE;
    c = Math_maxF(a, b);
    assertEqualsF(3.4028235E38f, c, (float) DEFAULT_EPSILON);
    a = Float_MAX_VALUE;
    b = Float_MIN_VALUE;
    c = Math_maxF(a, b);
    assertEqualsF(3.4028235E38f, c, (float) DEFAULT_EPSILON);
    a = -1;
    b = 1;
    c = Math_maxF(a, b);
    assertEqualsF(1.0f, c, (float) DEFAULT_EPSILON);
    a = 1;
    b = -1;
    c = Math_maxF(a, b);
    assertEqualsF(1.0f, c, (float) DEFAULT_EPSILON);
    a = 0;
    b = 0;
    c = Math_maxF(a, b);
    assertEqualsF(0.0f, c, (float) DEFAULT_EPSILON);
}

/**
 * Tests the max function with an int32_t value.
 */

void maxTest3() {
    int32_t a, b, c;
    a = Integer_MIN_VALUE;
    b = Integer_MAX_VALUE;
    c = Math_maxI(a, b);
    assertEqualsI(2147483647, c);
    a = Integer_MAX_VALUE;
    b = Integer_MIN_VALUE;
    c = Math_maxI(a, b);
    assertEqualsI(2147483647, c);
    a = -1;
    b = 1;
    c = Math_maxI(a, b);
    assertEqualsI(1, c);
    a = 1;
    b = -1;
    c = Math_maxI(a, b);
    assertEqualsI(1, c);
    a = 0;
    b = 0;
    c = Math_maxI(a, b);
    assertEqualsI(0, c);
}

/**
 * Tests the max function with a int64_t value.
 */

void maxTest4() {
    int64_t a, b, c;
    a = Long_MIN_VALUE;
    b = Long_MAX_VALUE;
    c = Math_maxL(a, b);
    assertEqualsL(9223372036854775807, c);
    a = Long_MAX_VALUE;
    b = Long_MIN_VALUE;
    c = Math_maxL(a, b);
    assertEqualsL(9223372036854775807, c);
    a = -1;
    b = 1;
    c = Math_maxL(a, b);
    assertEqualsL(1L, c);
    a = 1;
    b = -1;
    c = Math_maxL(a, b);
    assertEqualsL(1L, c);
    a = 0;
    b = 0;
    c = Math_maxL(a, b);
    assertEqualsL(0L, c);
}

/**
 * Tests the min function with a double value.
 */

void minTest() {
    double a, b, c;
    a = Double_MIN_VALUE;
    b = Double_MAX_VALUE;
    c = Math_minD(a, b);
    assertEqualsD(4.9E-324, c, DEFAULT_EPSILON);
    a = Double_MAX_VALUE;
    b = Double_MIN_VALUE;
    c = Math_minD(a, b);
    assertEqualsD(4.9E-324, c, DEFAULT_EPSILON);
    a = -1;
    b = 1;
    c = Math_minD(a, b);
    assertEqualsD(-1.0, c, DEFAULT_EPSILON);
    a = 1;
    b = -1;
    c = Math_minD(a, b);
    assertEqualsD(-1.0, c, DEFAULT_EPSILON);
    a = 0;
    b = 0;
    c = Math_minD(a, b);
    assertEqualsD(0.0, c, DEFAULT_EPSILON);
}

/**
 * Tests the min function with a float value.
 */

void minTest2() {
    float a, b, c;
    a = Float_MIN_VALUE;
    b = Float_MAX_VALUE;
    c = Math_minF(a, b);
    assertEqualsF(1.4E-45f, c, (float) DEFAULT_EPSILON);
    a = Float_MAX_VALUE;
    b = Float_MIN_VALUE;
    c = Math_minF(a, b);
    assertEqualsF(1.4E-45f, c, (float) DEFAULT_EPSILON);
    a = -1;
    b = 1;
    c = Math_minF(a, b);
    assertEqualsF(-1.0f, c, (float) DEFAULT_EPSILON);
    a = 1;
    b = -1;
    c = Math_minF(a, b);
    assertEqualsF(-1.0f, c, (float) DEFAULT_EPSILON);
    a = 0;
    b = 0;
    c = Math_minF(a, b);
    assertEqualsF(0.0f, c, (float) DEFAULT_EPSILON);
}

/**
 * Tests the min function with an int32_t value.
 */

void minTest3() {
    int32_t a, b, c;
    a = Integer_MIN_VALUE;
    b = Integer_MAX_VALUE;
    c = Math_minI(a, b);
    assertEqualsI((int32_t) - 2147483648, c);
    a = Integer_MAX_VALUE;
    b = Integer_MIN_VALUE;
    c = Math_minI(a, b);
    assertEqualsI((int32_t) - 2147483648, c);
    a = -1;
    b = 1;
    c = Math_minI(a, b);
    assertEqualsI(-1, c);
    a = 1;
    b = -1;
    c = Math_minI(a, b);
    assertEqualsI(-1, c);
    a = 0;
    b = 0;
    c = Math_minI(a, b);
    assertEqualsI(0, c);
}

/**
 * Tests the min function with a int64_t value.
 */

void minTest4() {
    int64_t a, b, c;
    a = Long_MIN_VALUE;
    b = Long_MAX_VALUE;
    c = Math_minL(a, b);
    assertEqualsL(-9223372036854775808L, c);
    a = Long_MAX_VALUE;
    b = Long_MIN_VALUE;
    c = Math_minL(a, b);
    assertEqualsL(-9223372036854775808L, c);
    a = -1;
    b = 1;
    c = Math_minL(a, b);
    assertEqualsL(-1L, c);
    a = 1;
    b = -1;
    c = Math_minL(a, b);
    assertEqualsL(-1L, c);
    a = 0;
    b = 0;
    c = Math_minL(a, b);
    assertEqualsL(0L, c);
}

/**
 * Test the pow function.
 */

void powTest() {
    double a, b, c;
    // positive power of positive value
    a = 10;
    b = 2;
    c = Math_pow(a, b);
    assertEqualsD(100.0, c, DEFAULT_EPSILON);
    // positive power of negative value
    a = -10;
    b = 2;
    c = Math_pow(a, b);
    assertEqualsD(100.0, c, DEFAULT_EPSILON);
    // negative power of positive value
    a = 10;
    b = -2;
    c = Math_pow(a, b);
    // zore power
    assertEqualsD(0.01, c, DEFAULT_EPSILON);
    a = 10;
    b = 0;
    c = Math_pow(a, b);
    assertEqualsD(1.0, c, DEFAULT_EPSILON);
    // power of zero
    a = 0;
    b = 10;
    c = Math_pow(a, b);
    assertEqualsD(0.0, c, DEFAULT_EPSILON);
}

/**
 * Tests the sqrt function.
 */

void sqrtTest() {
    double a, b;
    // square root of bigger value
    a = 100;
    b = Math_sqrt(a);
    assertEqualsD(10.0, b, DEFAULT_EPSILON);
    // square root of one
    a = 1;
    b = Math_sqrt(a);
    assertEqualsD(1.0, b, DEFAULT_EPSILON);
    // square root of zero
    a = 0;
    b = Math_sqrt(a);
    assertEqualsD(0.0, b, DEFAULT_EPSILON);
}

/**
 * Tests the log function.
 */

void logTest() {
    double a, b;
    // logarithm of the square of E
    a = Math_E * Math_E;
    b = Math_log(a);
    assertEqualsD(2.0, b, DEFAULT_EPSILON);
    // logarithm of E
    a = Math_E;
    b = Math_log(a);
    assertEqualsD(1.0, b, DEFAULT_EPSILON);
    // logarithm of one
    a = 1;
    b = Math_log(a);
    assertEqualsD(0.0, b, DEFAULT_EPSILON);
}

/**
 * Tests the log10 function.
 */

void log10Test() {
    double a, b;
    // logarithm of the square of ten
    a = 100;
    b = Math_log10(a);
    assertEqualsD(2.0, b, DEFAULT_EPSILON);
    // logarithm of ten
    a = 10;
    b = Math_log10(a);
    assertEqualsD(1.0, b, DEFAULT_EPSILON);
    // logarithm of one
    a = 1;
    b = Math_log10(a);
    assertEqualsD(0.0, b, DEFAULT_EPSILON);
}

/**
 * Tests the sin function.
 */

void sinTest() {
    double a, b;
    // sine of PI
    a = Math_PI;
    b = Math_sin(a);
    assertEqualsD(1.2246467991473532E-16, b, DEFAULT_EPSILON);
    // sine of minus PI
    a = -Math_PI;
    b = Math_sin(a);
    assertEqualsD(-1.2246467991473532E-16, b, DEFAULT_EPSILON);
    // sine of zero
    a = 0;
    b = Math_sin(a);
    assertEqualsD(0.0, b, DEFAULT_EPSILON);
}

/**
 * Tests the cos function.
 */

void cosTest() {
    double a, b;
    // cosine of PI
    a = Math_PI;
    b = Math_cos(a);
    assertEqualsD(-1.0, b, DEFAULT_EPSILON);
    // cosine of minus PI
    a = -Math_PI;
    b = Math_cos(a);
    assertEqualsD(-1.0, b, DEFAULT_EPSILON);
    // cosine of zero
    a = 0;
    b = Math_cos(a);
    assertEqualsD(1.0, b, DEFAULT_EPSILON);
}

/**
 * Tests the tan function.
 */

void tanTest() {
    double a, b;
    // tangent of PI
    a = Math_PI;
    b = Math_tan(a);
    assertEqualsD(-1.2246467991473532E-16, b, DEFAULT_EPSILON);
    // tangent of minus PI
    a = -Math_PI;
    b = Math_tan(a);
    assertEqualsD(1.2246467991473532E-16, b, DEFAULT_EPSILON);
    // tangent of zero
    a = 0;
    b = Math_tan(a);
    assertEqualsD(0.0, b, DEFAULT_EPSILON);
}

/**
 * Tests the asin function.
 */

void asinTest() {
    double a, b;
    // arcsine of one
    a = 1;
    b = Math_asin(a);
    assertEqualsD(1.5707963267948966, b, DEFAULT_EPSILON);
    // arcsine of minus one
    a = -1;
    b = Math_asin(a);
    assertEqualsD(-1.5707963267948966, b, DEFAULT_EPSILON);
    // arcsine of zero
    a = 0;
    b = Math_asin(a);
    assertEqualsD(0.0, b, DEFAULT_EPSILON);
}

/**
 * Tests the acos function.
 */

void acosTest() {
    double a, b;
    // arccosine of one
    a = 1;
    b = Math_acos(a);
    assertEqualsD(0.0, b, DEFAULT_EPSILON);
    // arccosine of minus one
    a = -1;
    b = Math_acos(a);
    assertEqualsD(3.141592653589793, b, DEFAULT_EPSILON);
    // arccosine of zero
    a = 0;
    b = Math_acos(a);
    assertEqualsD(1.5707963267948966, b, DEFAULT_EPSILON);
}

/**
 * Tests the atan function.
 */

void atanTest() {
    double a, b;
    // arctangent of one
    a = 1;
    b = Math_atan(a);
    assertEqualsD(0.7853981633974483, b, DEFAULT_EPSILON);
    // arctangent of minus one
    a = -1;
    b = Math_atan(a);
    assertEqualsD(-0.7853981633974483, b, DEFAULT_EPSILON);
    // arctangent of zero
    a = 0;
    b = Math_atan(a);
    assertEqualsD(0.0, b, DEFAULT_EPSILON);
}

/**
 * Tests the round function with a double value.
 */

void roundTest() {
    double a;
    int64_t b;
    // rounding to even value
    a = 1.5;
    b = Math_roundD(a);
    assertEqualsL((int64_t)2, b);
    // rounding to odd value
    a = 0.5;
    b = Math_roundD(a);
    assertEqualsL((int64_t)1, b);
    // rounding of negative value
    a = -0.5;
    b = Math_roundD(a);
    assertEqualsL((int64_t)0, b);
}

/**
 * Tests the round function with a float value.
 */

void roundTest2() {
    float a;
    int32_t b;
    a = 1.5f;
    b = Math_roundF(a);
    assertEqualsI(2, b);
    a = 0.5f;
    b = Math_roundF(a);
    assertEqualsI(1, b);
    a = -0.5f;
    b = Math_roundF(a);
    assertEqualsI(0, b);
}

int main(int argc, char** argv) {
    const int testCount = 24;
    setUpTestModule("MathTest", testCount);
    
    registerTest(absTest, "absTest");
    registerTest(absTest2, "absTest2");
    registerTest(absTest3, "absTest3");
    registerTest(absTest4, "absTest4");
    registerTest(maxTest, "maxTest");
    registerTest(maxTest2, "maxTest2");
    registerTest(maxTest3, "maxTest3");
    registerTest(maxTest4, "maxTest4");
    registerTest(minTest, "minTest");
    registerTest(minTest2, "minTest2");
    registerTest(minTest3, "minTest3");
    registerTest(minTest4, "minTest4");
    registerTest(powTest, "powTest");
    registerTest(sqrtTest, "sqrtTest");
    registerTest(logTest, "logTest");
    registerTest(log10Test, "log10Test");
    registerTest(sinTest, "sinTest");
    registerTest(cosTest, "cosTest");
    registerTest(tanTest, "tanTest");
    registerTest(asinTest, "asinTest");
    registerTest(acosTest, "acosTest");
    registerTest(atanTest, "atanTest");
    registerTest(roundTest, "roundTest");
    registerTest(roundTest2, "roundTest2");
    
    runTests();

    return (EXIT_SUCCESS);
}
