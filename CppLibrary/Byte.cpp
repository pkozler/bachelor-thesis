#include "Byte.h"

#include <string>

/**
 * A constant holding the maximum value a byte can have, 2^7-1.
 */
const int8_t Byte::MAX_VALUE = 127;
/**
 * A constant holding the minimum value a byte can have, -2^7.
 */
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

Byte::~Byte() {
    // really no code
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
int32_t Byte::compareTo(Byte *anotherByte) {
    return compare(v, anotherByte->v);
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
    return x - y;
}

/**
 * Compares this object to the specified object.
 *
 * @param obj the object to compare with
 * @return true if the objects are the same; false otherwise.
 */
bool Byte::equals(Byte *obj) {
    if (obj == nullptr) {
        return false;
    }

    if (sizeof(*this) != sizeof(*obj)) {
        return false;
    }
    
    return (v == obj->v);
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
    return (int8_t) std::stoi(s->toString(), nullptr, 10);
}

std::ostream &operator<<(std::ostream &s, Byte &obj) {
    return s << obj.toString()->toString().c_str();
}
