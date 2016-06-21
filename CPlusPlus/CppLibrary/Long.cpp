#include "Long.h"

#include <string>
#include <cstdlib>

const int64_t Long::MAX_VALUE = 9223372036854775807LL;
const int64_t Long::MIN_VALUE = -9223372036854775808LL;

/**
 * Constructs a newly allocated Long object that represents the specified
 * long argument.
 *
 * @param value the value to be represented by the Long object.
 */
Long::Long(int64_t value) {
    v = value;
}

/**
 * Returns the value of this Long as a long value.
 *
 * @return the numeric value represented by this object after conversion to
 * type long.
 */
int64_t Long::longValue() {
    return v;
}

/**
 * Compares two Long objects numerically.
 *
 * @param anotherLong the Long to be compared.
 * @return the value 0 if this Long is equal to the argument Long; a value
 * less than 0 if this Long is numerically less than the argument Long; and
 * a value greater than 0 if this Long is numerically greater than the
 * argument Long (signed comparison).
 */
int32_t Long::compareTo(Object *anotherLong) {
    return Long::compare(v, ((Long *)anotherLong)->v);
}

/**
 * Compares two long values numerically.
 *
 * @param x the first long to compare
 * @param y the second long to compare
 * @return the value 0 if x == y; a value less than 0 if x < y; and a value greater than 0 if x
 * > y
 */
int32_t Long::compare(int64_t x, int64_t y) {
    // 1 if x is greater, 0 if x equals y, -1 otherwise
    return (x < y) ? -1 : ((x == y) ? 0 : 1);
}

/**
 * Compares this object to the specified object.
 *
 * @param obj the object to compare with.
 * @return true if the objects are the same; false otherwise.
 */
bool Long::equals(Object *obj) {
    // testing another object reference for a NULL value
    if (obj == nullptr) {
        return false;
    }

    // testing object class equality
    if (sizeof(this) != sizeof(*obj)) {
        return false;
    }

    // testing object fields equality
    return (v == ((Long *)obj)->v);
}

/**
 * Returns a String object representing this Long's value.
 *
 * @return a string representation of the value of this object in base 10.
 */
String *Long::toString() {
    return toString(v);
}

/**
 * Returns a String object representing the specified long.
 *
 * @param l a long to be converted.
 * @return a string representation of the argument in base 10.
 */
String *Long::toString(int64_t l) {
    return new String(std::to_string(l));
}

/**
 * Parses the string argument as a signed long in the radix specified by the
 * second argument.
 *
 * @param s a String containing the long representation to be parsed
 * @return the long represented by the argument in decimal.
 */
int64_t Long::parseLong(String *s) {
    String *str = s->trim();
    int64_t value = strtoll(str->_s().c_str(), nullptr, 10);
    delete str;
    
    return value;
}
