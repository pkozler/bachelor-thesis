#ifndef DOUBLE_INCLUDED
#define DOUBLE_INCLUDED

#include "String.h"
#include <stdbool.h>
#include <stdint.h>

#define Double_MAX_VALUE 1.7976931348623157e+308
#define Double_MIN_VALUE 4.9e-324

typedef struct {
    double v;
} Double;

Double *new_Double(double value);
double doubleValue(Double *ptr);
int32_t compareToD(Double *ptr, Double *anotherDouble);
bool equalsD(Double *ptr, Double *obj);
String *toStringD(Double *ptr);
String *Double_toString(double d);
double Double_parseDouble(String *s);

#endif /* DOUBLE_INCLUDED */
