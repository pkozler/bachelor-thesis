#include "Float.h"

#include <string>
#include <cmath>

/**
 * A constant holding the positive infinity of type float.
 */
const float Float::POSITIVE_INFINITY = 1.0f / 0.0f;
/**
 * A constant holding the negative infinity of type float.
 */
const float Float::NEGATIVE_INFINITY = -1.0f / 0.0f;
/**
 * A constant holding a Not-a-Number (NaN) value of type float.
 */
const float Float::NaN = 0.0f / 0.0f;
/**
 * A constant holding the largest positive finite value of type float, (2-2^-23)·2^127.
 */
const float Float::MAX_VALUE = 3.4028235e+38f;
/**
 * A constant holding the smallest positive nonzero value of type float, 2-^149.
 */
const float Float::MIN_VALUE = 1.4e-45f;
/**
 * Maximum exponent a finite float variable may hav
 */
const int32_t Float::MAX_EXPONENT = 127;
/**
 * Minimum exponent a normalized float variable may have.
 */
const int32_t Float::MIN_EXPONENT = -126;
/**
 * A constant holding the smallest positive normal value of type float, 2^-126.
 */
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
int32_t Float::compareTo(Float *anotherFloat) {
    return compare(v, anotherFloat->v);
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
bool Float::equals(Float *obj) {
    if (obj == nullptr) {
        return false;
    }

    if (sizeof (*this) != sizeof (*obj)) {
        return false;
    }

    float v2 = obj->v;

    if (std::isnan(v) && std::isnan(v2)) {
        return true;
    }

    FloatInt32 vBits, v2Bits;
    vBits.val = v;
    v2Bits.val = v2;
    int32_t negativeZeroBits = getNegativeZeroBits();

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
    return std::stof(s->toString(), nullptr);
}

std::ostream &operator<<(std::ostream &s, Float &obj) {
    return s << obj.toString()->toString().c_str();
}
