#include "Float.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"

// maximum possible string length of the float value used as the string buffer size
#define _MAX_FLOAT_STRLEN 12

/**
 * Constructs a newly allocated Float structure that represents the
 * float argument.
 *
 * @param value the value to be represented by the Float.
 */
Float *new_Float(float value) {
    Float *f = malloc(sizeof (Float));
    f->v = value;

    return f;
}

/*
    returns the "binary representation" of negative zero value for comparison purposes
*/
long _getNegativeZeroFloatBits() {
    FloatInt32 bitConverter;
    bitConverter.val = -0.0;

    return bitConverter.bits;
}

/**
 * Returns the float value of the specified Float structure.
 *
 * @param ptr The allocated structure
 * @return the float value represented by the specified structure
 */
float floatValue(Float *ptr) {
    return ptr->v;
}

/**
 * Compares two Float structures numerically.
 *
 * @param ptr The allocated structure
 * @param anotherFloat the Float to be compared.
 * @return the value 0 if anotherFloat is numerically equal to the first Float; a
 * value less than 0 if the first Float is numerically less than anotherFloat;
 * and a value greater than 0 if the first Float is numerically greater than
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
    /* testing for NaN values (a NaN value is considered greated
       than any other, including positive infinity,
       and two NaN values are considered equal) */
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

    /* testing for +0.0 and -0.0 value (a positive zero
       is considered greater than a negative zero) */
    if (vBits.bits == 0
            && v2Bits.bits == negativeZeroBits) {
        return 1;
    }

    if (vBits.bits == negativeZeroBits
            && v2Bits.bits == 0) {
        return -1;
    }

    /* testing for other values and returning
       1 if first value is greater, 0 if first value 
       equals second value, -1 otherwise */
    return (f1 > f2 ? 1 : f1 < f2 ? -1 : 0);
}

/**
 * Compares the one structure against the other.
 *
 * @param ptr The allocated structure
 * @param obj the structure to be compared
 * @return true if the structures are the same; false otherwise.
 */
bool equalsF(Float *ptr, Float *obj) {
    // testing another object reference for a NULL value
    if (ptr == NULL || obj == NULL) {
        return false;
    }

    // testing object class equality
    if (sizeof(*ptr) != sizeof(*obj)) {
        return false;
    }

    float v = ptr->v;
    float v2 = obj->v;

    // testing for NaN values (two NaN values are considered equal)
    if (isnan(v) && isnan(v2)) {
        return true;
    }

    FloatInt32 vBits, v2Bits;
    vBits.val = v;
    v2Bits.val = v2;
    int32_t negativeZeroBits = _getNegativeZeroFloatBits();

    // testing for zero values (+0.0 is considered greater than -0.0)
    if (vBits.bits == negativeZeroBits) {
        return v2Bits.bits == negativeZeroBits;
    }

    if (v2Bits.bits == negativeZeroBits) {
        return vBits.bits == negativeZeroBits;
    }

    // testing other values
    return (v == v2);
}

/**
 * Returns a string representation of the specified Float structure.
 *
 * @param ptr The allocated structure
 * @return a String representation of the specified structure.
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
    // printing the string representation to the buffer
    sprintf(buf, "%G", f);
    // creating the null-terminated string from the buffer
    strcat(str, buf);
    String *s = new_String(str);
    free(str);
    
    return s;
}

/**
 * Returns a new float initialized to the value represented by the specified
 * String, as performed by the "valueOf" function for struct Float.
 *
 * @param s the string to be parsed.
 * @return the float value represented by the string argument.
 */
float Float_parseFloat(String *s) {
    String *str = trim(s);
    float value = strtof(str->s, NULL);

    // negative zero handling
    String *sign = new_String("-");
    
    if (value == 0 && startsWith(str, sign)) {
        value = -0.0f;
    }
    
    free(str);
    free(sign);

    return value;
}
