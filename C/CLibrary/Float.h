#ifndef FLOAT_INCLUDED
#define FLOAT_INCLUDED

#include "String.h"
#include <stdbool.h>
#include <stdint.h>

/**
 * The Float struct wraps a value of type float.
 *
 * @author Petr Kozler (A13B0359P)
 */

/**
 * A constant holding the positive infinity of type float.
 */
#define Float_POSITIVE_INFINITY 1.0f / 0.0f
/**
 * A constant holding the negative infinity of type float.
 */
#define Float_NEGATIVE_INFINITY -1.0f / 0.0f
/**
 * A constant holding a Not-a-Number (NaN) value of type float.
 */
#define Float_NaN 0.0f / 0.0f
/**
 * A constant holding the largest positive finite value of type float, (2-2^-23)·2^127.
 */
#define Float_MAX_VALUE 3.4028235e+38f
/**
 * A constant holding the smallest positive nonzero value of type float, 2-^149.
 */
#define Float_MIN_VALUE 1.4e-45f
/**
 * Maximum exponent a finite float variable may hav
 */
#define Float_MAX_EXPONENT 127
/**
 * Minimum exponent a normalized float variable may have.
 */
#define Float_MIN_EXPONENT -126
/**
 * A constant holding the smallest positive normal value of type float, 2^-126.
 */
#define Float_MIN_NORMAL 1.17549435e-38f

/*
    FloatInt32 union provides the ability to set the float value
    and get the int32_t value with the same binary representation.
*/
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
