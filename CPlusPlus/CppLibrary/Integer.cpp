#include "Integer.h"

#include <string>
#include <cstdlib>

const int32_t Integer::MAX_VALUE = 2147483647;
const int32_t Integer::MIN_VALUE = -2147483648;

/**
 * Constructs a newly allocated Integer object that represents the specified
 * int value.
 *
 * @param value the value to be represented by the Integer object.
 */
Integer::Integer(int32_t value) {
    v = value;
}

/**
 * Returns the value of this Integer as an int.
 *
 * @return the numeric value represented by this object after conversion to
 * type int.
 */
int32_t Integer::intValue() {
    return v;
}

/**
 * Compares two Integer objects numerically.
 *
 * @param anotherInteger the Integer to be compared.
 * @return the value 0 if this Integer is equal to the argument Integer; a
 * value less than 0 if this Integer is numerically less than the argument
 * Integer; and a value greater than 0 if this Integer is numerically
 * greater than the argument Integer (signed comparison).
 */
int32_t Integer::compareTo(Object *anotherInteger) {
    return Integer::compare(v, ((Integer *)anotherInteger)->v);
}

/**
 * Compares two int values numerically.
 *
 * @param x the first int to compare
 * @param y the second int to compare
 * @return the value 0 if x == y; a value less than 0 if x < y; and a value greater than 0 if x
 * > y
 */
int32_t Integer::compare(int32_t x, int32_t y) {
    // 1 if x is greater, 0 if x equals y, -1 otherwise
    return (x < y) ? -1 : ((x == y) ? 0 : 1);
}

/**
 * Compares this object to the specified object.
 *
 * @param obj the object to compare with.
 * @return true if the objects are the same; false otherwise.
 */
bool Integer::equals(Object *obj) {
    // testing another object reference for a NULL value
    if (obj == nullptr) {
        return false;
    }

    // testing object class equality
    if (sizeof(this) != sizeof(*obj)) {
        return false;
    }

    // testing object fields equality
    return (v == ((Integer *)obj)->v);
}

/**
 * Returns a String object representing this Integer's value.
 * 
 * @return a string representation of the value of this object in base 10.
 */
String *Integer::toString() {
    return toString(v);
}

/**
 * Returns a String object representing the specified integer.
 *
 * @param i an integer to be converted.
 * @return a string representation of the argument in base 10.
 */
String *Integer::toString(int32_t i) {
    return new String(std::to_string(i));
}

/**
 * Parses the string argument as a signed decimal integer.
 *
 * @param s a String containing the int representation to be parsed
 * @return the integer value represented by the argument in decimal.
 */
int32_t Integer::parseInt(String *s) {
    String *str = s->trim();
    int32_t value = strtol(str->_s().c_str(), nullptr, 10);
    delete str;
    
    return value;
}
