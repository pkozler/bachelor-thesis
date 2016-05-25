#include "Boolean.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
 * Returns the value of this Boolean structure as a boolean primitive.
 *
 * @return the primitive boolean value of this structure.
 */
bool booleanValue(Boolean *ptr) {
    return ptr->v;
}

/**
 * Compares this Boolean instance with another.
 *
 * @param b the Boolean instance to be compared
 * @return zero if this structure represents the same boolean value as the
 * argument; a positive value if this structure represents true and the
 * argument represents false; and a negative value if this structure represents
 * false and the argument represents true
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
    return (x == y) ? 0 : (x ? 1 : -1);
}

/**
 * Returns true if and only if the argument is not null and is a Boolean
 * structure that represents the same boolean value as this structure.
 *
 * @param obj the structure to compare with.
 * @return true if the Boolean structures represent the same value; false
 * otherwise.
 */
bool equalsBool(Boolean *ptr, Boolean *obj) {
    if (ptr == NULL || obj == NULL) {
        return false;
    }
    
    if (sizeof(*ptr) != sizeof(*obj)) {
        return false;
    }

    return (ptr->v == obj->v);
}

/**
 * Returns a String structure representing this Boolean's value.
 * 
 * @return a string representation of this structure.
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
    sprintf(buf, "%s", b ? "true" : "false");
    strcat(str, buf);

    return new_String(str);
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
    bool value = false;

    if (equalsStr(toLowerCase(s), trueStr)) {
        value = true;
    }
    else if (equalsStr(toLowerCase(s), falseStr)) {
        value = false;
    }

    free(trueStr);
    free(falseStr);

    return value;
}
