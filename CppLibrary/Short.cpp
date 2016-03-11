#include "Short.h"

#include <string>

/**
 * A constant holding the maximum value a short can have, 2^15-1.
 */
const int16_t Short::MAX_VALUE = 32767;
/**
 * A constant holding the minimum value a short can have, -2^15.
 */
const int16_t Short::MIN_VALUE = -32768;

/**
 * Constructs a newly allocated Short object that represents the specified
 * short value.
 *
 * @param value the value to be represented by the Short.
 */
Short::Short(int16_t value) {
    v = value;
}

/**
 * Returns the value of this Short as a short.
 *
 * @return the numeric value represented by this object after conversion to
 * type short.
 */
int16_t Short::shortValue() {
    return v;
}

/**
 * Compares two Short objects numerically.
 *
 * @param anotherShort the Short to be compared.
 * @return the value 0 if this Short is equal to the argument Short; a value
 * less than 0 if this Short is numerically less than the argument Short;
 * and a value greater than 0 if this Short is numerically greater than the
 * argument Short (signed comparison).
 */
int32_t Short::compareTo(Short *anotherShort) {
    return compare(v, anotherShort->v);
}

/**
 * Compares two short values numerically.
 *
 * @param x the first short to compare
 * @param y the second short to compare
 * @return the value 0 if x == y; a value less than 0 if x < y; and a value greater than 0 if x
 * > y
 */
int32_t Short::compare(int16_t x, int16_t y) {
    return x - y;
}

/**
 * Compares this object to the specified object.
 *
 * @param obj the object to compare with
 * @return true if the objects are the same; false otherwise.
 */
int16_t Short::equals(Short *obj) {
    if (obj == nullptr) {
        return false;
    }

    if (sizeof(*this) != sizeof(*obj)) {
        return false;
    }
    
    return (v == obj->v);
}

/**
 * Returns a String object representing this Short's value.
 *
 * @return a string representation of the value of this object in base 10.
 */
String *Short::toString() {
    return toString(v);
}

/**
 * Returns a new String object representing the specified short.
 *
 * @param s the short to be converted
 * @return the string representation of the specified short
 */
String *Short::toString(int16_t s) {
    return new String(std::to_string(s));
}

/**
 * Parses the string argument as a signed decimal short.
 *
 * @param s a String containing the short representation to be parsed
 * @return the short value represented by the argument in decimal.
 */
int16_t Short::parseShort(String *s) {
    return (int16_t) std::stoi(s->toString(), nullptr, 10);
}

std::ostream &operator<<(std::ostream &s, Short &obj) {
    return s << obj.toString()->toString().c_str();
}
