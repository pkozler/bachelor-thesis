#include "StringBuilder.h"

/**
 * Constructs a string builder with no characters in it and an initial
 * capacity of 16 characters.
 */
StringBuilder::StringBuilder() {
    // really no code
}

StringBuilder::~StringBuilder() {
    // really no code
}

/**
 * Appends the specified string to this character sequence.
 *
 * @param str a string.
 * @return a pointer to this object.
 */
StringBuilder *StringBuilder::append(String *str) {
    oss << str;
    
    return this;
}

/**
 * Returns a string representing the data in this sequence.
 *
 * @return a string representation of this sequence of characters.
 */
String *StringBuilder::toString() {
    return new String(oss.str());
}
