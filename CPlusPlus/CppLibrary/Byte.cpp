#include "Byte.h"

#include <string>
#include <cstdlib>

const int8_t Byte::MAX_VALUE = 127;
const int8_t Byte::MIN_VALUE = -128;

/**
 * Constructs a newly allocated Byte object that represents the specified
 * byte value.
 *
 * @param value the value to be represented by the Byte.
 */
Byte::Byte(int8_t value) {
    v = value;
}

/**
 * Returns the value of this Byte as a byte.
 *
 * @return the numeric value represented by this object after conversion to
 * type byte.
 */
int8_t Byte::byteValue() {
    return v;
}

/**
 * Compares two Byte objects numerically.
 *
 * @param anotherByte the Byte to be compared.
 * @return the value 0 if this Byte is equal to the argument Byte; a value
 * less than 0 if this Byte is numerically less than the argument Byte; and
 * a value greater than 0 if this Byte is numerically greater than the
 * argument Byte (signed comparison).
 */
int32_t Byte::compareTo(Object *anotherByte) {
    return compare(v, ((Byte *)anotherByte)->v);
}

/**
 * Compares two byte values numerically.
 *
 * @param x the first byte to compare
 * @param y the second byte to compare
 * @return the value 0 if x == y; a value less than 0 if x < y; and a value greater than 0 if x
 * > y
 */
int32_t Byte::compare(int8_t x, int8_t y) {
    // positive number if x is greater, 0 if x equals y, negative number otherwise
    return x - y;
}

/**
 * Compares this object to the specified object.
 *
 * @param obj the object to compare with
 * @return true if the objects are the same; false otherwise.
 */
bool Byte::equals(Object *obj) {
    // testing another object reference for a NULL value
    if (obj == nullptr) {
        return false;
    }

    // testing object class equality
    if (sizeof(this) != sizeof(*obj)) {
        return false;
    }

    // testing object fields equality
    return (v == ((Byte *)obj)->v);
}

/**
 * Returns a String object representing this Byte's value.
 * 
 * @return a string representation of the value of this object in base 10.
 */
String *Byte::toString() {
    return toString(v);
}

/**
 * Returns a new String object representing the specified byte.
 *
 * @param b the byte to be converted
 * @return the string representation of the specified byte
 */
String *Byte::toString(int8_t b) {
    return new String(std::to_string(b));
}

/**
 * Parses the string argument as a signed decimal byte.
 *
 * @param s a String containing the byte representation to be parsed
 * @return the byte value represented by the argument in decimal
 */
int8_t Byte::parseByte(String *s) {
    String *str = s->trim();
    int8_t value = strtol(str->_s().c_str(), nullptr, 10);
    delete str;
    
    return value;
}
