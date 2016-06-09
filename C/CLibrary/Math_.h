#ifndef MATH_INCLUDED
#define	MATH_INCLUDED

#include <stdint.h>

/**
 * The module Math contains functions for performing basic numeric operations such as the elementary exponential,
 * logarithm, square root, and trigonometric functions.
 *
 * @author Petr Kozler (A13B0359P)
 */

/**
 * The double value that is closer than any other to e, the base of the natural logarithms.
 */
#define Math_E 2.7182818284590452354
/**
 * The double value that is closer than any other to pi, the ratio of the circumference of a circle to its diameter.
 */
#define Math_PI 3.14159265358979323846

double Math_absD(double a);
float Math_absF(float a);
int32_t Math_absI(int32_t a);
int64_t Math_absL(int64_t a);
double Math_maxD(double a, double b);
float Math_maxF(float a, float b);
int32_t Math_maxI(int32_t a, int32_t b);
int64_t Math_maxL(int64_t a, int64_t b);
double Math_minD(double a, double b);
float Math_minF(float a, float b);
int32_t Math_minI(int32_t a, int32_t b);
int64_t Math_minL(int64_t a, int64_t b);
double Math_pow(double a, double b);
double Math_sqrt(double a);
double Math_log(double a);
double Math_log10(double a);
double Math_sin(double a);
double Math_cos(double a);
double Math_tan(double a);
double Math_asin(double a);
double Math_acos(double a);
double Math_atan(double a);
int64_t Math_roundD(double a);
int32_t Math_roundF(float a);

#endif	/* MATH_INCLUDED */
