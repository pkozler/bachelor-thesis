#include "Double.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"

// maximum possible string length of the double value used as the string buffer size
#define _MAX_DOUBLE_STRLEN 13

/**
 * Constructs a newly allocated Double structure that represents the
 * double argument.
 *
 * @param value the value to be represented by the Double.
 */
Double *new_Double(double value) {
    Double *d = malloc(sizeof (Double));
    d->v = value;

    return d;
}

/*
    returns the "binary representation" of negative zero value for comparison purposes
*/
long _getNegativeZeroDoubleBits() {
    DoubleInt64 bitConverter;
    bitConverter.val = -0.0;

    return bitConverter.bits;
}

/**
 * Returns the double value of the specified Double structure.
 *
 * @param ptr The allocated structure
 * @return the double value represented by the specified structure
 */
double doubleValue(Double *ptr) {
    return ptr->v;
}

/**
 * Compares two Double structures numerically.
 *
 * @param ptr The allocated structure
 * @param anotherDouble the Double to be compared.
 * @return the value 0 if anotherDouble is numerically equal to the first Double;
 * a value less than 0 if the first Double is numerically less than
 * anotherDouble; and a value greater than 0 if the first Double is numerically
 * greater than anotherDouble.
 */
int32_t compareToD(Double *ptr, Double *anotherDouble) {
    return Double_compare(ptr->v, anotherDouble->v);
}

/**
 * Compares the two specified double values.
 *
 * @param d1 the first double to compare
 * @param d2 the second double to compare
 * @return the value 0 if d1 is numerically equal to d2; a value less than 0
 * if d1 is numerically less than d2; and a value greater than 0 if d1 is
 * numerically greater than d2.
 */
int32_t Double_compare(double d1, double d2) {
    /* testing for NaN values (a NaN value is considered greated
       than any other, including positive infinity,
       and two NaN values are considered equal) */
    if (isnan(d1)) {
        if (isnan(d2)) {
            return 0;
        }

        return 1;
    }

    if (isnan(d2)) {
        return -1;
    }

    DoubleInt64 vBits, v2Bits;
    vBits.val = d1;
    v2Bits.val = d2;
    int64_t negativeZeroBits = _getNegativeZeroDoubleBits();

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
    return (d1 > d2 ? 1 : d1 < d2 ? -1 : 0);
}

/**
 * Compares the one structure against the other.
 *
 * @param ptr The allocated structure
 * @param obj the structure to compare with.
 * @return true if the structures are the same; false otherwise.
 */
bool equalsD(Double *ptr, Double *obj) {
    // testing another object reference for a NULL value
    if (ptr == NULL || obj == NULL) {
        return false;
    }

    // testing object class equality
    if (sizeof(*ptr) != sizeof(*obj)) {
        return false;
    }

    double v = ptr->v;
    double v2 = obj->v;

    // testing for NaN values (two NaN values are considered equal)
    if (isnan(v) && isnan(v2)) {
        return true;
    }

    DoubleInt64 vBits, v2Bits;
    vBits.val = v;
    v2Bits.val = v2;
    int64_t negativeZeroBits = _getNegativeZeroDoubleBits();

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
 * Returns a string representation of the specified Double structure.
 *
 * @param ptr The allocated structure
 * @return a String representation of the specified structure.
 */
String *toStringD(Double *ptr) {
    return Double_toString(ptr->v);
}

/**
 * Returns a string representation of the double argument.
 *
 * @param d the double to be converted.
 * @return a string representation of the argument.
 */
String *Double_toString(double d) {
    char *str = malloc(_MAX_DOUBLE_STRLEN + 1);
    char buf[_MAX_DOUBLE_STRLEN];

    str[0] = '\0';
    // printing the string representation to the buffer
    sprintf(buf, "%lG", d);
    // creating the null-terminated string from the buffer
    strcat(str, buf);
    String *s = new_String(str);
    free(str);
    
    return s;
}

/**
 * Returns a new double initialized to the value represented by the
 * specified String, as performed by the "valueOf" function for struct Double.
 *
 * @param s the string to be parsed.
 * @return the double value represented by the string argument.
 */
double Double_parseDouble(String *s) {
    String *str = trim(s);
    double value = strtod(str->s, NULL);
    
    // negative zero handling
    String *sign = new_String("-");
    
    if (value == 0 && startsWith(str, sign)) {
        value = -0.0;
    }
    
    free(str);
    free(sign);

    return value;
}
