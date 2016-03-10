#ifndef FLOAT_INCLUDED
#define FLOAT_INCLUDED

#include "String.h"
#include <stdbool.h>
#include <stdint.h>

#define Float_POSITIVE_INFINITY 1.0f / 0.0f
#define Float_NEGATIVE_INFINITY -1.0f / 0.0f
#define Float_NaN 0.0f / 0.0f
#define Float_MAX_VALUE 3.4028235e+38f
#define Float_MIN_VALUE 1.4e-45f
#define Float_MAX_EXPONENT 127
#define Float_MIN_EXPONENT -126
#define Float_MIN_NORMAL 1.17549435e-38f

typedef union {
    float val;
    int32_t bits;
} FloatInt32;

typedef struct {
    float v;
} Float;

Float *new_Float(float value);
float floatValue(Float *ptr);
int32_t compareToF(Float *ptr, Float *anotherFloat);
int32_t Float_compare(float f1, float f2);
bool equalsF(Float *ptr, Float *obj);
String *toStringF(Float *ptr);
String *Float_toString(float f);
float Float_parseFloat(String *s);

#endif /* FLOAT_INCLUDED */
