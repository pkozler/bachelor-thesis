#ifndef DOUBLE_INCLUDED
#define DOUBLE_INCLUDED

#include "String.h"
#include <stdbool.h>
#include <stdint.h>

/**
 * The Double struct wraps a value of the type double.
 *
 * @author Petr Kozler (A13B0359P)
 */

/**
 * A constant holding the positive infinity of type double.
 */
#define Double_POSITIVE_INFINITY 1.0 / 0.0
/**
 * A constant holding the negative infinity of type double.
 */
#define Double_NEGATIVE_INFINITY -1.0 / 0.0
/**
 * A constant holding a Not-a-Number (NaN) value of type double.
 */
#define Double_NaN 0.0 / 0.0
/**
 * A constant holding the largest positive finite value of type double, (2-2^-52)·2^1023.
 */
#define Double_MAX_VALUE 1.7976931348623157e+308
/**
 * A constant holding the smallest positive nonzero value of type double, 2^-1074.
 */
#define Double_MIN_VALUE 4.9e-324
/**
 * Maximum exponent a finite double variable may have.
 */
#define Double_MAX_EXPONENT 1023
/**
 * Minimum exponent a normalized double variable may have.
 */
#define Double_MIN_EXPONENT -1022
/**
 * A constant holding the smallest positive normal value of type double, 2^-1022.
 */
#define Double_MIN_NORMAL 2.2250738585072014e-308

/*
    DoubleInt64 union provides the ability to set the double value
    and get the int64_t value with the same binary representation.
*/
typedef union {
    double val;
    int64_t bits;
} DoubleInt64;

typedef struct {
    double v;
} Double;

Double *new_Double(double value);
double doubleValue(Double *ptr);
int32_t compareToD(Double *ptr, Double *anotherDouble);
int32_t Double_compare(double d1, double d2);
bool equalsD(Double *ptr, Double *obj);
String *toStringD(Double *ptr);
String *Double_toString(double d);
double Double_parseDouble(String *s);

#endif /* DOUBLE_INCLUDED */
