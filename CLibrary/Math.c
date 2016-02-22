#include "Math.h"

#include <stdlib.h>
#include <math.h>

double Math_absD(double a) {
    return fabs(a);
}

float Math_absF(float a) {
    return fabsf(a);
}

int32_t Math_absI(int32_t a) {
    return abs(a);
}

int64_t Math_absL(int64_t a) {
    return labs(a);
}

double Math_maxD(double a, double b) {
    return fmax(a, b);
}

float Math_maxF(float a, float b) {
    return fmaxf(a, b);
}

int32_t Math_maxI(int32_t a, int32_t b) {
    return fmaxl(a, b);
}

int64_t Math_maxL(int64_t a, int64_t b) {
    return fmaxl(a, b);
}

double Math_minD(double a, double b) {
    return fmin(a, b);
}

float Math_minF(float a, float b) {
    return fminf(a, b);
}

int32_t Math_minI(int32_t a, int32_t b) {
    return fminl(a, b);
}

int64_t Math_minL(int64_t a, int64_t b) {
    return fminl(a, b);
}

double Math_sqrt(double a) {
    return sqrt(a);
}

double Math_pow(double a, double b) {
    return pow(a, b);
}

double Math_log(double a) {
    return log(a);
}

double Math_log10(double a) {
    return log10(a);
}

double Math_sin(double a) {
    return sin(a);
}

double Math_cos(double a) {
    return cos(a);
}

double Math_tan(double a) {
    return tan(a);
}

double Math_asin(double a) {
    return asin(a);
}

double Math_acos(double a) {
    return acos(a);
}

double Math_atan(double a) {
    return atan(a);
}

int64_t Math_roundD(double a) {
    return (int64_t) round(a);
}

int32_t Math_roundF(float a) {
    return (int32_t) roundf(a);
}
