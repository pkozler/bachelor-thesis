#include "Float.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define _MAX_FLOAT_STRLEN 12

/**
 * Constructs a newly allocated Float object that represents the primitive
 * float argument.
 *
 * @param value the value to be represented by the Float.
 */
Float *new_Float(float value) {
    Float *f = malloc(sizeof (Float));
    f->v = value;

    return f;
}

long _getNegativeZeroFloatBits() {
    FloatInt32 bitConverter;
    bitConverter.val = -0.0;

    return bitConverter.bits;
}

/**
 * Returns the float value of this Float object.
 *
 * @return the float value represented by this object
 */
float floatValue(Float *ptr) {
    return ptr->v;
}

/**
 * Compares two Float objects numerically.
 *
 * @param anotherFloat the Float to be compared.
 * @return the value 0 if anotherFloat is numerically equal to this Float; a
 * value less than 0 if this Float is numerically less than anotherFloat;
 * and a value greater than 0 if this Float is numerically greater than
 * anotherFloat.
 */
int32_t compareToF(Float *ptr, Float *anotherFloat) {
    return Float_compare(ptr->v, anotherFloat->v);
}

/**
 * Compares the two specified float values.
 *
 * @param f1 the first float to compare.
 * @param f2 the second float to compare.
 * @return the value 0 if f1 is numerically equal to f2; a value less than 0
 * if f1 is numerically less than f2; and a value greater than 0 if f1 is
 * numerically greater than f2.
 */
int32_t Float_compare(float f1, float f2) {
    if (isnan(f1)) {
        if (isnan(f2)) {
            return 0;
        }

        return 1;
    }

    if (isnan(f2)) {
        return -1;
    }

    FloatInt32 vBits, v2Bits;
    vBits.val = f1;
    v2Bits.val = f2;
    int32_t negativeZeroBits = _getNegativeZeroFloatBits();

    if (vBits.bits == 0
            && v2Bits.bits == negativeZeroBits) {
        return 1;
    }

    if (vBits.bits == negativeZeroBits
            && v2Bits.bits == 0) {
        return -1;
    }

    return (f1 > f2 ? 1 : f1 < f2 ? -1 : 0);
}

/**
 * Compares this object against the specified object.
 *
 * @param obj the object to be compared
 * @return true if the objects are the same; false otherwise.
 */
bool equalsF(Float *ptr, Float *obj) {
    if (ptr == NULL || obj == NULL) {
        return false;
    }

    if (sizeof(*ptr) != sizeof(*obj)) {
        return false;
    }

    float v = ptr->v;
    float v2 = obj->v;

    if (isnan(v) && isnan(v2)) {
        return true;
    }

    FloatInt32 vBits, v2Bits;
    vBits.val = v;
    v2Bits.val = v2;
    int32_t negativeZeroBits = _getNegativeZeroFloatBits();

    if (vBits.bits == negativeZeroBits) {
        return v2Bits.bits == negativeZeroBits;
    }

    if (v2Bits.bits == negativeZeroBits) {
        return vBits.bits == negativeZeroBits;
    }

    return (v == v2);
}

/**
 * Returns a string representation of this Float object.
 *
 * @return a String representation of this object.
 */
String *toStringF(Float *ptr) {
    return Float_toString(ptr->v);
}

/**
 * Returns a string representation of the float argument.
 *
 * @param f the float to be converted.
 * @return a string representation of the argument.
 */
String *Float_toString(float f) {
    char *str = malloc(_MAX_FLOAT_STRLEN + 1);
    char buf[_MAX_FLOAT_STRLEN];

    str[0] = '\0';
    sprintf(buf, "%G", f);
    strcat(str, buf);

    return new_String(str);
}

/**
 * Returns a new float initialized to the value represented by the specified
 * String, as performed by the valueOf method of class Float.
 *
 * @param s the string to be parsed.
 * @return the float value represented by the string argument.
 */
float Float_parseFloat(String *s) {
    return strtof(s->s, NULL);
}
