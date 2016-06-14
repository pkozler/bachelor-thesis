#include "Math_.h"
#include "Double.h"
#include "Float.h"
#include "Long.h"
#include "Integer.h"

#include <stdlib.h>
#include <math.h>

/**
 * Returns the absolute value of a double value.
 *
 * @param a the argument whose absolute value is to be determined
 * @return the absolute value of the argument.
 */
double Math_absD(double a) {
    return fabs(a);
}

/**
 * Returns the absolute value of a float value.
 *
 * @param a the argument whose absolute value is to be determined
 * @return the absolute value of the argument.
 */
float Math_absF(float a) {
    return fabsf(a);
}

/**
 * Returns the absolute value of an int value.
 *
 * @param a the argument whose absolute value is to be determined
 * @return the absolute value of the argument.
 */
int32_t Math_absI(int32_t a) {
    return abs(a);
}

/**
 * Returns the absolute value of a long value.
 *
 * @param a the argument whose absolute value is to be determined
 * @return the absolute value of the argument.
 */
int64_t Math_absL(int64_t a) {
    return llabs(a);
}

/**
 * Returns the greater of two double values.
 *
 * @param a an argument.
 * @param b another argument.
 * @return the larger of a and b.
 */
double Math_maxD(double a, double b) {
    return fmax(a, b);
}

/**
 * Returns the greater of two float values.
 *
 * @param a an argument.
 * @param b another argument.
 * @return the larger of a and b.
 */
float Math_maxF(float a, float b) {
    return fmaxf(a, b);
}

/**
 * Returns the greater of two int values.
 *
 * @param a an argument.
 * @param b another argument.
 * @return the larger of a and b.
 */
int32_t Math_maxI(int32_t a, int32_t b) {
    return fmaxl(a, b);
}

/**
 * Returns the greater of two long values.
 *
 * @param a an argument.
 * @param b another argument.
 * @return the larger of a and b.
 */
int64_t Math_maxL(int64_t a, int64_t b) {
    return fmaxl(a, b);
}

/**
 * Returns the smaller of two double values.
 *
 * @param a an argument.
 * @param b another argument.
 * @return the smaller of a and b.
 */
double Math_minD(double a, double b) {
    return fmin(a, b);
}

/**
 * Returns the smaller of two float values.
 *
 * @param a an argument.
 * @param b another argument.
 * @return the smaller of a and b.
 */
float Math_minF(float a, float b) {
    return fminf(a, b);
}

/**
 * Returns the smaller of two int values.
 *
 * @param a an argument.
 * @param b another argument.
 * @return the smaller of a and b.
 */
int32_t Math_minI(int32_t a, int32_t b) {
    return fminl(a, b);
}

/**
 * Returns the smaller of two long values.
 *
 * @param a an argument.
 * @param b another argument.
 * @return the smaller of a and b.
 */
int64_t Math_minL(int64_t a, int64_t b) {
    return fminl(a, b);
}

/**
 * Returns the value of the first argument raised to the power of the second
 * argument.
 *
 * @param a the base.
 * @param b the exponent.
 * @return the value a^b.
 */
double Math_pow(double a, double b) {
    return pow(a, b);
}

/**
 * Returns the correctly rounded positive square root of a double value.
 *
 * @param a a value.
 * @return the positive square root of a. If the argument is NaN or less
 * than zero, the result is NaN.
 */
double Math_sqrt(double a) {
    return sqrt(a);
}

/**
 * Returns the natural logarithm (base e) of a double value.
 *
 * @param a a value
 * @return the value ln a, the natural logarithm of a.
 */
double Math_log(double a) {
    return log(a);
}

/**
 * Returns the base 10 logarithm of a double value.
 *
 * @param a a value
 * @return the base 10 logarithm of a.
 */
double Math_log10(double a) {
    return log10(a);
}

/**
 * Returns the trigonometric sine of an angle.
 *
 * @param a an angle, in radians.
 * @return the sine of the argument.
 */
double Math_sin(double a) {
    return sin(a);
}

/**
 * Returns the trigonometric cosine of an angle.
 *
 * @param a an angle, in radians.
 * @return the cosine of the argument.
 */
double Math_cos(double a) {
    return cos(a);
}

/**
 * Returns the trigonometric tangent of an angle.
 *
 * @param a an angle, in radians.
 * @return the tangent of the argument.
 */
double Math_tan(double a) {
    return tan(a);
}

/**
 * Returns the arc sine of a value; the returned angle is in the range -pi/2
 * through pi/2.
 *
 * @param a the value whose arc sine is to be returned.
 * @return the arc sine of the argument.
 */
double Math_asin(double a) {
    return asin(a);
}

/**
 * Returns the arc cosine of a value; the returned angle is in the range 0.0
 * through pi.
 *
 * @param a the value whose arc cosine is to be returned.
 * @return the arc cosine of the argument.
 */
double Math_acos(double a) {
    return acos(a);
}

/**
 * Returns the arc tangent of a value; the returned angle is in the range
 * -pi/2 through pi/2.
 *
 * @param a the value whose arc tangent is to be returned.
 * @return the arc tangent of the argument.
 */
double Math_atan(double a) {
    return atan(a);
}

/**
 * Returns the closest long to the argument, with ties rounding up.
 *
 * @param a a floating-point value to be rounded to a long.
 * @return the value of the argument rounded to the nearest long value.
 */
int64_t Math_roundD(double a) {
    if (Double_compare(a, Double_NaN) == 0) {
        return 0;
    }

    if (Double_compare(a, Double_NEGATIVE_INFINITY) == 0
        || a <= Long_MIN_VALUE) {
        return Long_MIN_VALUE;
    }

    if (Double_compare(a, Double_POSITIVE_INFINITY) == 0
        || a >= Long_MAX_VALUE) {
        return Long_MAX_VALUE;
    }

    if (a < 0 && a - trunc(a) <= -0.5) {
        return (int64_t)trunc(a);
    }

    return (int64_t)round(a);
}

/**
 * Returns the closest int to the argument, with ties rounding up.
 *
 * @param a a floating-point value to be rounded to an integer.
 * @return the value of the argument rounded to the nearest int value.
 */
int32_t Math_roundF(float a) {
    if (Float_compare(a, Float_NaN) == 0) {
        return 0;
    }

    if (Float_compare(a, Float_NEGATIVE_INFINITY) == 0
        || a <= Integer_MIN_VALUE) {
        return Integer_MIN_VALUE;
    }

    if (Float_compare(a, Float_POSITIVE_INFINITY) == 0
        || a >= Integer_MAX_VALUE) {
        return Integer_MAX_VALUE;
    }

    if (a < 0 && a - truncf(a) <= -0.5) {
        return (int32_t)truncf(a);
    }

    return (int32_t)roundf(a);
}
