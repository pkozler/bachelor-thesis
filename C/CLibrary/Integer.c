#include "Integer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _MAX_INT_STRLEN 11

/**
 * Constructs a newly allocated Integer structure that represents the specified
 * int value.
 *
 * @param value the value to be represented by the Integer structure.
 */
Integer *new_Integer(int32_t value) {
    Integer *i = malloc(sizeof(Integer));
    i->v = value;

    return i;
}

/**
 * Returns the value of this Integer as an int.
 *
 * @return the numeric value represented by this structure after conversion to
 * type int.
 */
int32_t intValue(Integer *ptr) {
    return ptr->v;
}

/**
 * Compares two Integer structures numerically.
 *
 * @param anotherInteger the Integer to be compared.
 * @return the value 0 if this Integer is equal to the argument Integer; a
 * value less than 0 if this Integer is numerically less than the argument
 * Integer; and a value greater than 0 if this Integer is numerically
 * greater than the argument Integer (signed comparison).
 */
int32_t compareToI(Integer *ptr, Integer *anotherInteger) {
    return Integer_compare(ptr->v, anotherInteger->v);
}

/**
 * Compares two int values numerically.
 *
 * @param x the first int to compare
 * @param y the second int to compare
 * @return the value 0 if x == y; a value less than 0 if x < y; and a value greater than 0 if x
 * > y
 */
int32_t Integer_compare(int32_t x, int32_t y) {
    return (x < y) ? -1 : ((x == y) ? 0 : 1);
}

/**
 * Compares this structure to the specified structure.
 *
 * @param obj the structure to compare with.
 * @return true if the structures are the same; false otherwise.
 */
bool equalsI(Integer *ptr, Integer *obj) {
    if (ptr == NULL || obj == NULL) {
        return false;
    }

    if (sizeof(*ptr) != sizeof(*obj)) {
        return false;
    }

    return (ptr->v == obj->v);
}

/**
 * Returns a String structure representing this Integer's value.
 * 
 * @return a string representation of the value of this structure in base 10.
 */
String *toStringI(Integer *ptr) {
    return Integer_toString(ptr->v);
}

/**
 * Returns a String structure representing the specified integer.
 *
 * @param i an integer to be converted.
 * @return a string representation of the argument in base 10.
 */
String *Integer_toString(int32_t i) {
    char *str = malloc(_MAX_INT_STRLEN + 1);
    char buf[_MAX_INT_STRLEN];

    str[0] = '\0';
    sprintf(buf, "%d", i);
    strcat(str, buf);

    return new_String(str);
}

/**
 * Parses the string argument as a signed decimal integer.
 *
 * @param s a String containing the int representation to be parsed
 * @return the integer value represented by the argument in decimal.
 */
int32_t Integer_parseInt(String *s) {
    return strtol(s->s, NULL, 10);
}
