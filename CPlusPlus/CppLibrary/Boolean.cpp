#include "Boolean.h"

/**
 * Allocates a Boolean object representing the value argument.
 *
 * @param value the value of the Boolean.
 */
Boolean::Boolean(bool value) {
    v = value;
}

/**
 * Returns the value of this Boolean object as a boolean primitive.
 *
 * @return the primitive boolean value of this object.
 */
bool Boolean::booleanValue() {
    return v;
}

/**
 * Compares this Boolean instance with another.
 *
 * @param b the Boolean instance to be compared
 * @return zero if this object represents the same boolean value as the
 * argument; a positive value if this object represents true and the
 * argument represents false; and a negative value if this object represents
 * false and the argument represents true
 */
int32_t Boolean::compareTo(Object *b) {
    return compare(v, ((Boolean *)b)->v);
}

/**
 * Compares two boolean values.
 *
 * @param x the first boolean to compare
 * @param y the second boolean to compare
 * @return the value 0 if x == y; a value less than 0 if !x && y; and a
 * value greater than 0 if x && !y
 */
int32_t Boolean::compare(bool x, bool y) {
    return (x == y) ? 0 : (x ? 1 : -1);
}

/**
 * Returns true if and only if the argument is not null and is a Boolean
 * object that represents the same boolean value as this object.
 *
 * @param obj the object to compare with.
 * @return true if the Boolean objects represent the same value; false
 * otherwise.
 */
bool Boolean::equals(Object *obj) {
    if (obj == nullptr) {
        return false;
    }

    if (sizeof(this) != sizeof(*obj)) {
        return false;
    }
    
    return (v == ((Boolean *)obj)->v);
}

/**
 * Returns a String object representing this Boolean's value.
 * 
 * @return a string representation of this object.
 */
String *Boolean::toString() {
    return toString(v);
}

/**
 * Returns a String object representing the specified boolean.
 *
 * @param b the boolean to be converted
 * @return the string representation of the specified boolean
 */
String *Boolean::toString(bool b) {
    return new String(b ? "true" : "false");
}

/**
 * Parses the string argument as a boolean.
 *
 * @param s the String containing the boolean representation to be parsed
 * @return the boolean represented by the string argument
 */
bool Boolean::parseBoolean(String *s) {
    String *trueStr = new String("true");
    String *falseStr = new String("false");
    String *trimmedStr = s->trim();
    String *str = trimmedStr->toLowerCase();
    bool value = false;

    if (str->equals(trueStr)) {
        value = true;
    }
    else if (str->equals(falseStr)) {
        value = false;
    }

    delete trueStr;
    delete falseStr;
    delete trimmedStr;
    delete str;

    return value;
}