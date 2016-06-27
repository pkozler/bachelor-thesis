#include "Float.h"

#include <string>
#include <cmath>
#include <cstdlib>

const float Float::POSITIVE_INFINITY = 1.0f / 0.0f;
const float Float::NEGATIVE_INFINITY = -1.0f / 0.0f;
const float Float::NaN = 0.0f / 0.0f;
const float Float::MAX_VALUE = 3.4028235e+38f;
const float Float::MIN_VALUE = 1.4e-45f;
const int32_t Float::MAX_EXPONENT = 127;
const int32_t Float::MIN_EXPONENT = -126;
const float Float::MIN_NORMAL = 1.17549435e-38f;

/**
 * Constructs a newly allocated Float object that represents the primitive
 * float argument.
 *
 * @param value the value to be represented by the Float.
 */
Float::Float(float value) {
    v = value;
}

/*
    returns the "binary representation" of negative zero value for comparison purposes
*/
int32_t Float::getNegativeZeroBits() {
    FloatInt32 bitConverter;
    bitConverter.val = -0.0;

    return bitConverter.bits;
}

/**
 * Returns the float value of this Float object.
 *
 * @return the float value represented by this object
 */
float Float::floatValue() {
    return v;
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
int32_t Float::compareTo(Object *anotherFloat) {
    return compare(v, ((Float *)anotherFloat)->v);
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
int32_t Float::compare(float f1, float f2) {
    /* testing for NaN values (a NaN value is considered greated
       than any other, including positive infinity,
       and two NaN values are considered equal) */
    if (std::isnan(f1)) {
        if (std::isnan(f2)) {
            return 0;
        }

        return 1;
    }

    if (std::isnan(f2)) {
        return -1;
    }

    FloatInt32 vBits, v2Bits;
    vBits.val = f1;
    v2Bits.val = f2;
    int32_t negativeZeroBits = getNegativeZeroBits();

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
 * Compares this object against the specified object.
 *
 * @param obj the object to be compared
 * @return true if the objects are the same; false otherwise.
 */
bool Float::equals(Object *obj) {
    // testing another object reference for a NULL value
    if (obj == nullptr) {
        return false;
    }

    // testing object class equality
    if (sizeof (this) != sizeof (*obj)) {
        return false;
    }

    float v2 = ((Float *)obj)->v;

    // testing for NaN values (two NaN values are considered equal)
    if (std::isnan(v) && std::isnan(v2)) {
        return true;
    }

    FloatInt32 vBits, v2Bits;
    vBits.val = v;
    v2Bits.val = v2;
    int32_t negativeZeroBits = getNegativeZeroBits();

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
 * Returns a string representation of this Float object.
 *
 * @return a String representation of this object.
 */
String *Float::toString() {
    return toString(v);
}

/**
 * Returns a string representation of the float argument.
 *
 * @param f the float to be converted.
 * @return a string representation of the argument.
 */
String *Float::toString(float f) {
    return new String(std::to_string(f));
}

/**
 * Returns a new float initialized to the value represented by the specified
 * String, as performed by the valueOf method of class Float.
 *
 * @param s the string to be parsed.
 * @return the float value represented by the string argument.
 */
float Float::parseFloat(String *s) {
    String *str = s->trim();
    float value = strtof(str->_s().c_str(), nullptr);
    
    // negative zero handling
    String *sign = new String("-");
    
    if (value == 0 && s->startsWith(sign)) {
        value = -0.0f;
    }
    
    delete str, sign;
    
    return value;
}
