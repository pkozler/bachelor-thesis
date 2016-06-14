#include "Math_.h"

#include <cmath>
#include <stdlib.h>
#include "Integer.h"
#include "Long.h"
#include "Float.h"
#include "Double.h"

/**
 * The double value that is closer than any other to e, the base of the natural logarithms.
 */
const double Math::E = 2.7182818284590452354;
/**
 * The double value that is closer than any other to pi, the ratio of the circumference of a circle to its diameter.
 */
const double Math::PI = 3.14159265358979323846;

/**
 * Returns the absolute value of a double value.
 *
 * @param a the argument whose absolute value is to be determined
 * @return the absolute value of the argument.
 */
double Math::abs(double a) {
    return std::fabs(a);
}

/**
 * Returns the absolute value of a float value.
 *
 * @param a the argument whose absolute value is to be determined
 * @return the absolute value of the argument.
 */
float Math::abs(float a) {
    return std::fabs(a);
}

/**
 * Returns the absolute value of an int value.
 *
 * @param a the argument whose absolute value is to be determined
 * @return the absolute value of the argument.
 */
int32_t Math::abs(int32_t a) {
    return std::abs(a);
}

/**
 * Returns the absolute value of a long value.
 *
 * @param a the argument whose absolute value is to be determined
 * @return the absolute value of the argument.
 */
int64_t Math::abs(int64_t a) {
    return ::llabs(a);
}

/**
 * Returns the greater of two double values.
 *
 * @param a an argument.
 * @param b another argument.
 * @return the larger of a and b.
 */
double Math::max(double a, double b) {
    return std::max(a, b);
}

/**
 * Returns the greater of two float values.
 *
 * @param a an argument.
 * @param b another argument.
 * @return the larger of a and b.
 */
float Math::max(float a, float b) {
    return std::max(a, b);
}

/**
 * Returns the greater of two int values.
 *
 * @param a an argument.
 * @param b another argument.
 * @return the larger of a and b.
 */
int32_t Math::max(int32_t a, int32_t b) {
    return std::max(a, b);
}

/**
 * Returns the greater of two long values.
 *
 * @param a an argument.
 * @param b another argument.
 * @return the larger of a and b.
 */
int64_t Math::max(int64_t a, int64_t b) {
    return std::max(a, b);
}

/**
 * Returns the smaller of two double values.
 *
 * @param a an argument.
 * @param b another argument.
 * @return the smaller of a and b.
 */
double Math::min(double a, double b) {
    return std::min(a, b);
}

/**
 * Returns the smaller of two float values.
 *
 * @param a an argument.
 * @param b another argument.
 * @return the smaller of a and b.
 */
float Math::min(float a, float b) {
    return std::min(a, b);
}

/**
 * Returns the smaller of two int values.
 *
 * @param a an argument.
 * @param b another argument.
 * @return the smaller of a and b.
 */
int32_t Math::min(int32_t a, int32_t b) {
    return std::min(a, b);
}

/**
 * Returns the smaller of two long values.
 *
 * @param a an argument.
 * @param b another argument.
 * @return the smaller of a and b.
 */
int64_t Math::min(int64_t a, int64_t b) {
    return std::min(a, b);
}

/**
 * Returns the value of the first argument raised to the power of the second
 * argument.
 *
 * @param a the base.
 * @param b the exponent.
 * @return the value a^b.
 */
double Math::pow(double a, double b) {
    return std::pow(a, b);
}

/**
 * Returns the correctly rounded positive square root of a double value.
 *
 * @param a a value.
 * @return the positive square root of a. If the argument is NaN or less
 * than zero, the result is NaN.
 */
double Math::sqrt(double a) {
    return std::sqrt(a);
}

/**
 * Returns the natural logarithm (base e) of a double value.
 *
 * @param a a value
 * @return the value ln a, the natural logarithm of a.
 */
double Math::log(double a) {
    return std::log(a);
}

/**
 * Returns the base 10 logarithm of a double value.
 *
 * @param a a value
 * @return the base 10 logarithm of a.
 */
double Math::log10(double a) {
    return std::log10(a);
}

/**
 * Returns the trigonometric sine of an angle.
 *
 * @param a an angle, in radians.
 * @return the sine of the argument.
 */
double Math::sin(double a) {
    return std::sin(a);
}

/**
 * Returns the trigonometric cosine of an angle.
 *
 * @param a an angle, in radians.
 * @return the cosine of the argument.
 */
double Math::cos(double a) {
    return std::cos(a);
}

/**
 * Returns the trigonometric tangent of an angle.
 *
 * @param a an angle, in radians.
 * @return the tangent of the argument.
 */
double Math::tan(double a) {
    return std::tan(a);
}

/**
 * Returns the arc sine of a value; the returned angle is in the range -pi/2
 * through pi/2.
 *
 * @param a the value whose arc sine is to be returned.
 * @return the arc sine of the argument.
 */
double Math::asin(double a) {
    return std::asin(a);
}

/**
 * Returns the arc cosine of a value; the returned angle is in the range 0.0
 * through pi.
 *
 * @param a the value whose arc cosine is to be returned.
 * @return the arc cosine of the argument.
 */
double Math::acos(double a) {
    return std::acos(a);
}

/**
 * Returns the arc tangent of a value; the returned angle is in the range
 * -pi/2 through pi/2.
 *
 * @param a the value whose arc tangent is to be returned.
 * @return the arc tangent of the argument.
 */
double Math::atan(double a) {
    return std::atan(a);
}

/**
 * Returns the closest long to the argument, with ties rounding up.
 *
 * @param a a floating-point value to be rounded to a long.
 * @return the value of the argument rounded to the nearest long value.
 */
int64_t Math::round(double a) {
    if (Double::compare(a, Double::NaN) == 0) {
        return 0;
    }

    if (Double::compare(a, Double::NEGATIVE_INFINITY) == 0
        || a <= Long::MIN_VALUE) {
        return Long::MIN_VALUE;
    }

    if (Double::compare(a, Double::POSITIVE_INFINITY) == 0
        || a >= Long::MAX_VALUE) {
        return Long::MAX_VALUE;
    }

    if (a < 0 && a - std::trunc(a) <= -0.5) {
        return (int64_t)std::trunc(a);
    }

    return (int64_t) std::round(a);
}

/**
 * Returns the closest int to the argument, with ties rounding up.
 *
 * @param a a floating-point value to be rounded to an integer.
 * @return the value of the argument rounded to the nearest int value.
 */
int32_t Math::round(float a) {
    if (Float::compare(a, Float::NaN) == 0) {
        return 0;
    }

    if (Float::compare(a, Float::NEGATIVE_INFINITY) == 0
        || a <= Integer::MIN_VALUE) {
        return Integer::MIN_VALUE;
    }

    if (Float::compare(a, Float::POSITIVE_INFINITY) == 0
        || a >= Integer::MAX_VALUE) {
        return Integer::MAX_VALUE;
    }

    if (a < 0 && a - std::trunc(a) <= -0.5) {
        return (int32_t)std::trunc(a);
    }

    return (int32_t) std::round(a);
}
