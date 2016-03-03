#ifndef DOUBLE_INCLUDED
#define DOUBLE_INCLUDED

#include "String.h"
#include <stdbool.h>
#include <stdint.h>

#define Double_POSITIVE_INFINITY 1.0 / 0.0
#define Double_NEGATIVE_INFINITY -1.0 / 0.0
#define Double_NaN 0.0 / 0.0
#define Double_MAX_VALUE 1.7976931348623157e+308
#define Double_MIN_VALUE 4.9e-324
#define Double_MAX_EXPONENT 1023
#define Double_MIN_EXPONENT -1022
#define Double_MIN_NORMAL 2.2250738585072014e-308

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
int32_t Double_compare(double v, double v2);
bool equalsD(Double *ptr, Double *obj);
String *toStringD(Double *ptr);
String *Double_toString(double d);
double Double_parseDouble(String *s);

#endif /* DOUBLE_INCLUDED */
