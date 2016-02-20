#include "Math.h"

#include <stdlib.h>
#include <math.h>

double Math_absD(double a) {
    return fabs(a);
}

float Math_absF(float a) {
    return fabsf(a);
}

int Math_absI(int a) {
    return abs(a);
}

long Math_absL(long a) {
    return labs(a);
}

double Math_maxD(double a, double b) {
    return fmax(a, b);
}

float Math_maxF(float a, float b) {
    return fmaxf(a, b);
}

int Math_maxI(int a, int b) {
    return fmaxl(a, b);
}

long Math_maxL(long a, long b) {
    return fmaxl(a, b);
}

double Math_minD(double a, double b) {
    return fmin(a, b);
}

float Math_minF(float a, float b) {
    return fminf(a, b);
}

int Math_minI(int a, int b) {
    return fminl(a, b);
}

long Math_minL(long a, long b) {
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

long Math_roundD(double a) {
    return (long) round(a);
}

int Math_roundF(float a) {
    return (int) roundf(a);
}
