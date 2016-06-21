#include "Double.h"

#include <string>
#include <cmath>
#include <cstdlib>

const double Double::POSITIVE_INFINITY = 1.0 / 0.0;
const double Double::NEGATIVE_INFINITY = -1.0 / 0.0;
const double Double::NaN = 0.0 / 0.0;
const double Double::MAX_VALUE = 1.7976931348623157e+308;
const double Double::MIN_VALUE = 4.9e-324;
const int32_t Double::MAX_EXPONENT = 1023;
const int32_t Double::MIN_EXPONENT = -1022;
const double Double::MIN_NORMAL = 2.2250738585072014e-308;

/**
 * Constructs a newly allocated Double object that represents the primitive
 * double argument.
 *
 * @param value the value to be represented by the Double.
 */
Double::Double(double value) {
    v = value;
}

/*
    returns the "binary representation" of negative zero value for comparison purposes
*/
int64_t Double::getNegativeZeroBits() {
    DoubleInt64 bitConverter;
    bitConverter.val = -0.0;

    return bitConverter.bits;
}

/**
 * Returns the double value of this Double object.
 *
 * @return the double value represented by this object
 */
double Double::doubleValue() {
    return v;
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
int32_t Double::compareTo(Object *anotherDouble) {
    return compare(v, ((Double *)anotherDouble)->v);
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
int32_t Double::compare(double d1, double d2) {
    /* testing for NaN values (a NaN value is considered greated
       than any other, including positive infinity,
       and two NaN values are considered equal) */
    if (std::isnan(d1)) {
        if (std::isnan(d2)) {
            return 0;
        }

        return 1;
    }

    if (std::isnan(d2)) {
        return -1;
    }

    DoubleInt64 vBits, v2Bits;
    vBits.val = d1;
    v2Bits.val = d2;
    int64_t negativeZeroBits = getNegativeZeroBits();

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
 * Compares this object against the specified object.
 *
 * @param obj the object to compare with.
 * @return true if the objects are the same; false otherwise.
 */
bool Double::equals(Object *obj) {
    // testing another object reference for a NULL value
    if (obj == nullptr) {
        return false;
    }

    // testing object class equality
    if (sizeof (this) != sizeof (*obj)) {
        return false;
    }

    double v2 = ((Double *)obj)->v;

    // testing for NaN values (two NaN values are considered equal)
    if (std::isnan(v) && std::isnan(v2)) {
        return true;
    }

    DoubleInt64 vBits, v2Bits;
    vBits.val = v;
    v2Bits.val = v2;
    int64_t negativeZeroBits = getNegativeZeroBits();

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
 * Returns a string representation of this Double object.
 *
 * @return a String representation of this object.
 */
String *Double::toString() {
    return toString(v);
}

/**
 * Returns a string representation of the double argument.
 *
 * @param d the double to be converted.
 * @return a string representation of the argument.
 */
String *Double::toString(double d) {
    return new String(std::to_string(d));
}

/**
 * Returns a new double initialized to the value represented by the
 * specified String, as performed by the valueOf method of class Double.
 *
 * @param s the string to be parsed.
 * @return the double value represented by the string argument.
 */
double Double::parseDouble(String *s) {
    String *str = s->trim();
    double value = strtod(str->_s().c_str(), nullptr);
    
    // negative zero handling
    String *sign = new String("-");
    
    if (value == 0 && s.startsWith(sign)) {
        value = -0.0;
    }
    
    delete str, sign;
    
    return value;
}
