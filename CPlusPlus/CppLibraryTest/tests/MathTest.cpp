#include <cstdlib>
#include <iostream>

#include "test.h"
#include "Math_.h"
#include "Integer.h"
#include "Long.h"
#include "Float.h"
#include "Double.h"

/**
 * A Math class test suite.
 *
 * @author Petr Kozler (A13B0359P)
 */

// maximal difference between expected and actual value
const double DEFAULT_EPSILON = 1E-0;

/**
 * Tests the abs method with a double value.
 */

void absTest() {
    double a, b;
    // negative value
    a = Double::MIN_VALUE + 1;
    b = Math::abs(a);
    Test::assertEquals(1.0, b, DEFAULT_EPSILON);
    // zero value
    a = 0;
    b = Math::abs(a);
    Test::assertEquals(0.0, b, DEFAULT_EPSILON);
    // positive value
    a = Double::MAX_VALUE - 1;
    b = Math::abs(a);
    Test::assertEquals(1.7976931348623157E308, b, DEFAULT_EPSILON);
}

/**
 * Tests the abs method with a float value.
 */

void absTest2() {
    float a, b;
    a = Float::MIN_VALUE + 1;
    b = Math::abs(a);
    Test::assertEquals(1.0f, b, (float) DEFAULT_EPSILON);
    a = 0;
    b = Math::abs(a);
    Test::assertEquals(0.0f, b, (float) DEFAULT_EPSILON);
    a = Float::MAX_VALUE - 1;
    b = Math::abs(a);
    Test::assertEquals(3.4028235E38f, b, (float) DEFAULT_EPSILON);
}

/**
 * Tests the abs method with an int32_t value.
 */

void absTest3() {
    int32_t a, b;
    a = Integer::MIN_VALUE + 1;
    b = Math::abs(a);
    Test::assertEquals(2147483647, b);
    a = 0;
    b = Math::abs(a);
    Test::assertEquals(0, b);
    a = Integer::MAX_VALUE - 1;
    b = Math::abs(a);
    Test::assertEquals(2147483646, b);
}

/**
 * Tests the abs method with a int64_t value.
 */

void absTest4() {
    int64_t a, b;
    a = Long::MIN_VALUE + 1LL;
    b = Math::abs(a);
    Test::assertEquals(9223372036854775807LL, b);
    a = 0;
    b = Math::abs(a);
    Test::assertEquals(0LL, b);
    a = Long::MAX_VALUE - 1LL;
    b = Math::abs(a);
    Test::assertEquals(9223372036854775806LL, b);
}

/**
 * Tests the max method with a double value.
 */

void maxTest() {
    double a, b, c;
    // negative and positive value
    a = Double::MIN_VALUE;
    b = Double::MAX_VALUE;
    c = Math::max(a, b);
    Test::assertEquals(1.7976931348623157E308, c, DEFAULT_EPSILON);
    // positive and negative value
    a = Double::MAX_VALUE;
    b = Double::MIN_VALUE;
    c = Math::max(a, b);
    Test::assertEquals(1.7976931348623157E308, c, DEFAULT_EPSILON);
    // negative and positive value (smaller difference)
    a = -1;
    b = 1;
    c = Math::max(a, b);
    Test::assertEquals(1.0, c, DEFAULT_EPSILON);
    // positive and negative value (bigger difference)
    a = 1;
    b = -1;
    c = Math::max(a, b);
    // equal values
    Test::assertEquals(1.0, c, DEFAULT_EPSILON);
    a = 0;
    b = 0;
    c = Math::max(a, b);
    Test::assertEquals(0.0, c, DEFAULT_EPSILON);
}

/**
 * Tests the max method with a float value.
 */

void maxTest2() {
    float a, b, c;
    a = Float::MIN_VALUE;
    b = Float::MAX_VALUE;
    c = Math::max(a, b);
    Test::assertEquals(3.4028235E38f, c, (float) DEFAULT_EPSILON);
    a = Float::MAX_VALUE;
    b = Float::MIN_VALUE;
    c = Math::max(a, b);
    Test::assertEquals(3.4028235E38f, c, (float) DEFAULT_EPSILON);
    a = -1;
    b = 1;
    c = Math::max(a, b);
    Test::assertEquals(1.0f, c, (float) DEFAULT_EPSILON);
    a = 1;
    b = -1;
    c = Math::max(a, b);
    Test::assertEquals(1.0f, c, (float) DEFAULT_EPSILON);
    a = 0;
    b = 0;
    c = Math::max(a, b);
    Test::assertEquals(0.0f, c, (float) DEFAULT_EPSILON);
}

/**
 * Tests the max method with an int32_t value.
 */

void maxTest3() {
    int32_t a, b, c;
    a = Integer::MIN_VALUE;
    b = Integer::MAX_VALUE;
    c = Math::max(a, b);
    Test::assertEquals(2147483647, c);
    a = Integer::MAX_VALUE;
    b = Integer::MIN_VALUE;
    c = Math::max(a, b);
    Test::assertEquals(2147483647, c);
    a = -1;
    b = 1;
    c = Math::max(a, b);
    Test::assertEquals(1, c);
    a = 1;
    b = -1;
    c = Math::max(a, b);
    Test::assertEquals(1, c);
    a = 0;
    b = 0;
    c = Math::max(a, b);
    Test::assertEquals(0, c);
}

/**
 * Tests the max method with a int64_t value.
 */

void maxTest4() {
    int64_t a, b, c;
    a = Long::MIN_VALUE;
    b = Long::MAX_VALUE;
    c = Math::max(a, b);
    Test::assertEquals(9223372036854775807, c);
    a = Long::MAX_VALUE;
    b = Long::MIN_VALUE;
    c = Math::max(a, b);
    Test::assertEquals(9223372036854775807, c);
    a = -1;
    b = 1;
    c = Math::max(a, b);
    Test::assertEquals(1L, c);
    a = 1;
    b = -1;
    c = Math::max(a, b);
    Test::assertEquals(1L, c);
    a = 0;
    b = 0;
    c = Math::max(a, b);
    Test::assertEquals(0L, c);
}

/**
 * Tests the min method with a double value.
 */

void minTest() {
    double a, b, c;
    a = Double::MIN_VALUE;
    b = Double::MAX_VALUE;
    c = Math::min(a, b);
    Test::assertEquals(4.9E-324, c, DEFAULT_EPSILON);
    a = Double::MAX_VALUE;
    b = Double::MIN_VALUE;
    c = Math::min(a, b);
    Test::assertEquals(4.9E-324, c, DEFAULT_EPSILON);
    a = -1;
    b = 1;
    c = Math::min(a, b);
    Test::assertEquals(-1.0, c, DEFAULT_EPSILON);
    a = 1;
    b = -1;
    c = Math::min(a, b);
    Test::assertEquals(-1.0, c, DEFAULT_EPSILON);
    a = 0;
    b = 0;
    c = Math::min(a, b);
    Test::assertEquals(0.0, c, DEFAULT_EPSILON);
}

/**
 * Tests the min method with a float value.
 */

void minTest2() {
    float a, b, c;
    a = Float::MIN_VALUE;
    b = Float::MAX_VALUE;
    c = Math::min(a, b);
    Test::assertEquals(1.4E-45f, c, (float) DEFAULT_EPSILON);
    a = Float::MAX_VALUE;
    b = Float::MIN_VALUE;
    c = Math::min(a, b);
    Test::assertEquals(1.4E-45f, c, (float) DEFAULT_EPSILON);
    a = -1;
    b = 1;
    c = Math::min(a, b);
    Test::assertEquals(-1.0f, c, (float) DEFAULT_EPSILON);
    a = 1;
    b = -1;
    c = Math::min(a, b);
    Test::assertEquals(-1.0f, c, (float) DEFAULT_EPSILON);
    a = 0;
    b = 0;
    c = Math::min(a, b);
    Test::assertEquals(0.0f, c, (float) DEFAULT_EPSILON);
}

/**
 * Tests the min method with an int32_t value.
 */

void minTest3() {
    int32_t a, b, c;
    a = Integer::MIN_VALUE;
    b = Integer::MAX_VALUE;
    c = Math::min(a, b);
    Test::assertEquals((int32_t) - 2147483648, c);
    a = Integer::MAX_VALUE;
    b = Integer::MIN_VALUE;
    c = Math::min(a, b);
    Test::assertEquals((int32_t) - 2147483648, c);
    a = -1;
    b = 1;
    c = Math::min(a, b);
    Test::assertEquals(-1, c);
    a = 1;
    b = -1;
    c = Math::min(a, b);
    Test::assertEquals(-1, c);
    a = 0;
    b = 0;
    c = Math::min(a, b);
    Test::assertEquals(0, c);
}

/**
 * Tests the min method with a int64_t value.
 */

void minTest4() {
    int64_t a, b, c;
    a = Long::MIN_VALUE;
    b = Long::MAX_VALUE;
    c = Math::min(a, b);
    Test::assertEquals(-9223372036854775808LL, c);
    a = Long::MAX_VALUE;
    b = Long::MIN_VALUE;
    c = Math::min(a, b);
    Test::assertEquals(-9223372036854775808LL, c);
    a = -1;
    b = 1;
    c = Math::min(a, b);
    Test::assertEquals(-1L, c);
    a = 1;
    b = -1;
    c = Math::min(a, b);
    Test::assertEquals(-1L, c);
    a = 0;
    b = 0;
    c = Math::min(a, b);
    Test::assertEquals(0L, c);
}

/**
 * Test the pow method.
 */

void powTest() {
    double a, b, c;
    // positive power of positive value
    a = 10;
    b = 2;
    c = Math::pow(a, b);
    Test::assertEquals(100.0, c, DEFAULT_EPSILON);
    // positive power of negative value
    a = -10;
    b = 2;
    c = Math::pow(a, b);
    Test::assertEquals(100.0, c, DEFAULT_EPSILON);
    // negative power of positive value
    a = 10;
    b = -2;
    c = Math::pow(a, b);
    // zore power
    Test::assertEquals(0.01, c, DEFAULT_EPSILON);
    a = 10;
    b = 0;
    c = Math::pow(a, b);
    Test::assertEquals(1.0, c, DEFAULT_EPSILON);
    // power of zero
    a = 0;
    b = 10;
    c = Math::pow(a, b);
    Test::assertEquals(0.0, c, DEFAULT_EPSILON);
}

/**
 * Tests the sqrt method.
 */

void sqrtTest() {
    double a, b;
    // square root of bigger value
    a = 100;
    b = Math::sqrt(a);
    Test::assertEquals(10.0, b, DEFAULT_EPSILON);
    // square root of one
    a = 1;
    b = Math::sqrt(a);
    Test::assertEquals(1.0, b, DEFAULT_EPSILON);
    // square root of zero
    a = 0;
    b = Math::sqrt(a);
    Test::assertEquals(0.0, b, DEFAULT_EPSILON);
}

/**
 * Tests the log method.
 */

void logTest() {
    double a, b;
    // logarithm of the square of E
    a = Math::E * Math::E;
    b = Math::log(a);
    Test::assertEquals(2.0, b, DEFAULT_EPSILON);
    // logarithm of E
    a = Math::E;
    b = Math::log(a);
    Test::assertEquals(1.0, b, DEFAULT_EPSILON);
    // logarithm of one
    a = 1;
    b = Math::log(a);
    Test::assertEquals(0.0, b, DEFAULT_EPSILON);
}

/**
 * Tests the log10 method.
 */

void log10Test() {
    double a, b;
    // logarithm of the square of ten
    a = 100;
    b = Math::log10(a);
    Test::assertEquals(2.0, b, DEFAULT_EPSILON);
    // logarithm of ten
    a = 10;
    b = Math::log10(a);
    Test::assertEquals(1.0, b, DEFAULT_EPSILON);
    // logarithm of one
    a = 1;
    b = Math::log10(a);
    Test::assertEquals(0.0, b, DEFAULT_EPSILON);
}

/**
 * Tests the sin method.
 */

void sinTest() {
    double a, b;
    // sine of PI
    a = Math::PI;
    b = Math::sin(a);
    Test::assertEquals(1.2246467991473532E-16, b, DEFAULT_EPSILON);
    // sine of minus PI
    a = -Math::PI;
    b = Math::sin(a);
    Test::assertEquals(-1.2246467991473532E-16, b, DEFAULT_EPSILON);
    // sine of zero
    a = 0;
    b = Math::sin(a);
    Test::assertEquals(0.0, b, DEFAULT_EPSILON);
}

/**
 * Tests the cos method.
 */

void cosTest() {
    double a, b;
    // cosine of PI
    a = Math::PI;
    b = Math::cos(a);
    Test::assertEquals(-1.0, b, DEFAULT_EPSILON);
    // cosine of minus PI
    a = -Math::PI;
    b = Math::cos(a);
    Test::assertEquals(-1.0, b, DEFAULT_EPSILON);
    // cosine of zero
    a = 0;
    b = Math::cos(a);
    Test::assertEquals(1.0, b, DEFAULT_EPSILON);
}

/**
 * Tests the tan method.
 */

void tanTest() {
    double a, b;
    // tangent of PI
    a = Math::PI;
    b = Math::tan(a);
    Test::assertEquals(-1.2246467991473532E-16, b, DEFAULT_EPSILON);
    // tangent of minus PI
    a = -Math::PI;
    b = Math::tan(a);
    Test::assertEquals(1.2246467991473532E-16, b, DEFAULT_EPSILON);
    // tangent of zero
    a = 0;
    b = Math::tan(a);
    Test::assertEquals(0.0, b, DEFAULT_EPSILON);
}

/**
 * Tests the asin method.
 */

void asinTest() {
    double a, b;
    // arcsine of one
    a = 1;
    b = Math::asin(a);
    Test::assertEquals(1.5707963267948966, b, DEFAULT_EPSILON);
    // arcsine of minus one
    a = -1;
    b = Math::asin(a);
    Test::assertEquals(-1.5707963267948966, b, DEFAULT_EPSILON);
    // arcsine of zero
    a = 0;
    b = Math::asin(a);
    Test::assertEquals(0.0, b, DEFAULT_EPSILON);
}

/**
 * Tests the acos method.
 */

void acosTest() {
    double a, b;
    // arccosine of one
    a = 1;
    b = Math::acos(a);
    Test::assertEquals(0.0, b, DEFAULT_EPSILON);
    // arccosine of minus one
    a = -1;
    b = Math::acos(a);
    Test::assertEquals(3.141592653589793, b, DEFAULT_EPSILON);
    // arccosine of zero
    a = 0;
    b = Math::acos(a);
    Test::assertEquals(1.5707963267948966, b, DEFAULT_EPSILON);
}

/**
 * Tests the atan method.
 */

void atanTest() {
    double a, b;
    // arctangent of one
    a = 1;
    b = Math::atan(a);
    Test::assertEquals(0.7853981633974483, b, DEFAULT_EPSILON);
    // arctangent of minus one
    a = -1;
    b = Math::atan(a);
    Test::assertEquals(-0.7853981633974483, b, DEFAULT_EPSILON);
    // arctangent of zero
    a = 0;
    b = Math::atan(a);
    Test::assertEquals(0.0, b, DEFAULT_EPSILON);
}

/**
 * Tests the round method with a double value.
 */

void roundTest() {
    double a;
    int64_t b;
    // rounding to even value
    a = 1.5;
    b = Math::round(a);
    Test::assertEquals((int64_t)2, b);
    // rounding to odd value
    a = 0.5;
    b = Math::round(a);
    Test::assertEquals((int64_t)1, b);
    // rounding of negative value
    a = -0.5;
    b = Math::round(a);
    Test::assertEquals((int64_t)0, b);
}

/**
 * Tests the round method with a float value.
 */

void roundTest2() {
    float a;
    int32_t b;
    a = 1.5f;
    b = Math::round(a);
    Test::assertEquals(2, b);
    a = 0.5f;
    b = Math::round(a);
    Test::assertEquals(1, b);
    a = -0.5f;
    b = Math::round(a);
    Test::assertEquals(0, b);
}

int main(int argc, char** argv) {
    Test::setUpTestModule("MathTest");

    Test::registerTest(absTest, "absTest");
    Test::registerTest(absTest2, "absTest2");
    Test::registerTest(absTest3, "absTest3");
    Test::registerTest(absTest4, "absTest4");
    Test::registerTest(maxTest, "maxTest");
    Test::registerTest(maxTest2, "maxTest2");
    Test::registerTest(maxTest3, "maxTest3");
    Test::registerTest(maxTest4, "maxTest4");
    Test::registerTest(minTest, "minTest");
    Test::registerTest(minTest2, "minTest2");
    Test::registerTest(minTest3, "minTest3");
    Test::registerTest(minTest4, "minTest4");
    Test::registerTest(powTest, "powTest");
    Test::registerTest(sqrtTest, "sqrtTest");
    Test::registerTest(logTest, "logTest");
    Test::registerTest(log10Test, "log10Test");
    Test::registerTest(sinTest, "sinTest");
    Test::registerTest(cosTest, "cosTest");
    Test::registerTest(tanTest, "tanTest");
    Test::registerTest(asinTest, "asinTest");
    Test::registerTest(acosTest, "acosTest");
    Test::registerTest(atanTest, "atanTest");
    Test::registerTest(roundTest, "roundTest");
    Test::registerTest(roundTest2, "roundTest2");

    Test::runTests();

    return (EXIT_SUCCESS);
}