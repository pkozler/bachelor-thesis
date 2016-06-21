#include "Boolean.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// maximum possible string length of the bool value used as the string buffer size
#define _MAX_BOOL_STRLEN 5

/**
 * Allocates a Boolean structure representing the value argument.
 *
 * @param value the value of the Boolean.
 */
Boolean *new_Boolean(bool value) {
    Boolean *b = malloc(sizeof(Boolean));
    b->v = value;

    return b;
}

/**
 * Returns the value of the specified Boolean structure as a boolean primitive.
 *
 * @param ptr The allocated structure
 * @return the primitive boolean value of the specified structure.
 */
bool booleanValue(Boolean *ptr) {
    return ptr->v;
}

/**
 * Compares the one specified Boolean instance with another.
 *
 * @param ptr The allocated structure
 * @param b the Boolean instance to be compared
 * @return zero if the first specified structure represents the same boolean value as the
 * second; a positive value if the first structure represents true and the
 * second represents false; and a negative value if the first structure represents
 * false and the second represents true
 */
int32_t compareToBool(Boolean *ptr, Boolean *b) {
    return Boolean_compare(ptr->v, b->v);
}

/**
 * Compares two boolean values.
 *
 * @param x the first boolean to compare
 * @param y the second boolean to compare
 * @return the value 0 if x == y; a value less than 0 if !x && y; and a
 * value greater than 0 if x && !y
 */
int32_t Boolean_compare(bool x, bool y) {
    // 0 if x equals y, 1 if x is TRUE and y is FALSE, -1 otherwise
    return (x == y) ? 0 : (x ? 1 : -1);
}

/**
 * Returns true if and only if the arguments are not null and are a Boolean
 * structures that represents the same boolean value.
 *
 * @param ptr The allocated structure
 * @param obj the structure to compare with.
 * @return true if the Boolean structures represent the same value; false
 * otherwise.
 */
bool equalsBool(Boolean *ptr, Boolean *obj) {
    // testing another object reference for a NULL value
    if (ptr == NULL || obj == NULL) {
        return false;
    }

    // testing object class equality
    if (sizeof(*ptr) != sizeof(*obj)) {
        return false;
    }

    // testing object fields equality
    return (ptr->v == obj->v);
}

/**
 * Returns a String structure representing the specified Boolean's value.
 *
 * @param ptr The allocated structure
 * @return a string representation of the specified structure.
 */
String *toStringBool(Boolean *ptr) {
    return Boolean_toString(ptr->v);
}

/**
 * Returns a String structure representing the specified boolean.
 *
 * @param b the boolean to be converted
 * @return the string representation of the specified boolean
 */
String *Boolean_toString(bool b) {
    char *str = malloc(_MAX_BOOL_STRLEN + 1);
    char buf[_MAX_BOOL_STRLEN];

    str[0] = '\0';
    // printing the string representation to the buffer
    sprintf(buf, "%s", b ? "true" : "false");
    // creating the null-terminated string from the buffer
    strcat(str, buf);
    String *s = new_String(str);
    free(str);
    
    return s;
}

/**
 * Parses the string argument as a boolean.
 *
 * @param s the String containing the boolean representation to be parsed
 * @return the boolean represented by the string argument
 */
bool Boolean_parseBoolean(String *s) {
    String *trueStr = new_String("true");
    String *falseStr = new_String("false");
    String *trimmedStr = trim(s);
    String *str = toLowerCase(trimmedStr);
    bool value = false;

    // test if the string is equal to "true"
    if (equalsStr(str, trueStr)) {
        value = true;
    }
    // test if the string is equal to "false"
    else if (equalsStr(str, falseStr)) {
        value = false;
    }

    free(trueStr);
    free(falseStr);
    free(trimmedStr);
    free(str);
    
    return value;
}
