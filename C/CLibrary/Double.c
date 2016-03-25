#include "Double.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define _MAX_DOUBLE_STRLEN 13

/**
 * Constructs a newly allocated Double object that represents the primitive
 * double argument.
 *
 * @param value the value to be represented by the Double.
 */
Double *new_Double(double value) {
    Double *d = malloc(sizeof (Double));
    d->v = value;

    return d;
}

long _getNegativeZeroDoubleBits() {
    DoubleInt64 bitConverter;
    bitConverter.val = -0.0;

    return bitConverter.bits;
}

/**
 * Returns the double value of this Double object.
 *
 * @return the double value represented by this object
 */
double doubleValue(Double *ptr) {
    return ptr->v;
}

/**
 * Compares two Double objects numerically.
 *
 * @param anotherDouble the Double to be compared.
 * @return the value 0 if anotherDouble is numerically equal to this Double;
 * a value less than 0 if this Double is numerically less than
 * anotherDouble; and a value greater than 0 if this Double is numerically
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

    if (vBits.bits == 0
            && v2Bits.bits == negativeZeroBits) {
        return 1;
    }

    if (vBits.bits == negativeZeroBits
            && v2Bits.bits == 0) {
        return -1;
    }

    return (d1 > d2 ? 1 : d1 < d2 ? -1 : 0);
}

/**
 * Compares this object against the specified object.
 *
 * @param obj the object to compare with.
 * @return true if the objects are the same; false otherwise.
 */
bool equalsD(Double *ptr, Double *obj) {
    if (ptr == NULL || obj == NULL) {
        return false;
    }

    if (sizeof(*ptr) != sizeof(*obj)) {
        return false;
    }

    double v = ptr->v;
    double v2 = obj->v;

    if (isnan(v) && isnan(v2)) {
        return true;
    }

    DoubleInt64 vBits, v2Bits;
    vBits.val = v;
    v2Bits.val = v2;
    int64_t negativeZeroBits = _getNegativeZeroDoubleBits();

    if (vBits.bits == negativeZeroBits) {
        return v2Bits.bits == negativeZeroBits;
    }

    if (v2Bits.bits == negativeZeroBits) {
        return vBits.bits == negativeZeroBits;
    }

    return (v == v2);
}

/**
 * Returns a string representation of this Double object.
 *
 * @return a String representation of this object.
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
    sprintf(buf, "%lG", d);
    strcat(str, buf);

    return new_String(str);
}

/**
 * Returns a new double initialized to the value represented by the
 * specified String, as performed by the valueOf method of class Double.
 *
 * @param s the string to be parsed.
 * @return the double value represented by the string argument.
 */
double Double_parseDouble(String *s) {
    return strtod(s->s, NULL);
}
