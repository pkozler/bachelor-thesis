#include "Short.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _MAX_SHORT_STRLEN 6

/**
 * Constructs a newly allocated Short structure that represents the specified
 * short value.
 *
 * @param value the value to be represented by the Short.
 */
Short *new_Short(int16_t value) {
    Short *s = malloc(sizeof(Short));
    s->v = value;

    return s;
}

/**
 * Returns the value of the specified Short as a short.
 *
 * @param ptr The allocated structure
 * @return the numeric value represented by the specified structure after conversion to
 * type short.
 */
int16_t shortValue(Short *ptr) {
    return ptr->v;
}

/**
 * Compares two Short structures numerically.
 *
 * @param ptr The allocated structure
 * @param anotherShort the Short to be compared.
 * @return the value 0 if the first Short is equal to the second Short; a value
 * less than 0 if the first Short is numerically less than the second Short;
 * and a value greater than 0 if the first Short is numerically greater than the
 * second Short (signed comparison).
 */
int32_t compareToS(Short *ptr, Short *anotherShort) {
    return Short_compare(ptr->v, anotherShort->v);
}

/**
 * Compares two short values numerically.
 *
 * @param x the first short to compare
 * @param y the second short to compare
 * @return the value 0 if x == y; a value less than 0 if x < y; and a value greater than 0 if x
 * > y
 */
int32_t Short_compare(int16_t x, int16_t y) {
    return x - y;
}

/**
 * Compares the one structure to the other.
 *
 * @param ptr The allocated structure
 * @param obj the structure to compare with
 * @return true if the structures are the same; false otherwise.
 */
bool equalsS(Short *ptr, Short *obj) {
    if (ptr == NULL || obj == NULL) {
        return false;
    }

    if (sizeof(*ptr) != sizeof(*obj)) {
        return false;
    }

    return (ptr->v == obj->v);
}

/**
 * Returns a String structure representing the specified Short's value.
 *
 * @param ptr The allocated structure
 * @return a string representation of the value of the specified structure in base 10.
 */
String *toStringS(Short *ptr) {
    return Short_toString(ptr->v);
}

/**
 * Returns a new String structure representing the specified short.
 *
 * @param s the short to be converted
 * @return the string representation of the specified short
 */
String *Short_toString(int16_t s) {
    char *str = malloc(_MAX_SHORT_STRLEN + 1);
    char buf[_MAX_SHORT_STRLEN];

    str[0] = '\0';
    sprintf(buf, "%hd", s);
    strcat(str, buf);

    return new_String(str);
}

/**
 * Parses the string argument as a signed decimal short.
 *
 * @param s a String containing the short representation to be parsed
 * @return the short value represented by the argument in decimal.
 */
int16_t Short_parseShort(String *s) {
    return strtol(s->s, NULL, 10);
}
