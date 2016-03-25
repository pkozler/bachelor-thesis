#ifndef MATH_INCLUDED
#define	MATH_INCLUDED

#include <cstdint>

/**
 * The class Math contains methods for performing basic numeric operations such as the elementary exponential,
 * logarithm, square root, and trigonometric functions.
 *
 * @author Petr Kozler (A13B0359P)
 */
class Math {
public:
    static const double E;
    static const double PI;
    static double abs(double a);
    static float abs(float a);
    static int32_t abs(int32_t a);
    static int64_t abs(int64_t a);
    static double max(double a, double b);
    static float max(float a, float b);
    static int32_t max(int32_t a, int32_t b);
    static int64_t max(int64_t a, int64_t b);
    static double min(double a, double b);
    static float min(float a, float b);
    static int32_t min(int32_t a, int32_t b);
    static int64_t min(int64_t a, int64_t b);
    static double pow(double a, double b);
    static double sqrt(double a);
    static double log(double a);
    static double log10(double a);
    static double sin(double a);
    static double cos(double a);
    static double tan(double a);
    static double asin(double a);
    static double acos(double a);
    static double atan(double a);
    static int64_t round(double a);
    static int32_t round(float a);
};

#endif	// MATH_INCLUDED
