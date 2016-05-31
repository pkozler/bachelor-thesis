#include "Long.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _MAX_LONG_STRLEN 20

/**
 * Constructs a newly allocated Long structure that represents the specified
 * long argument.
 *
 * @param value the value to be represented by the Long structure.
 */
Long *new_Long(int64_t value) {
    Long *l = malloc(sizeof(Long));
    l->v = value;

    return l;
}

/**
 * Returns the value of the specified Long as a long value.
 *
 * @param ptr The allocated structure
 * @return the numeric value represented by the specified structure after conversion to
 * type long.
 */
int64_t longValue(Long *ptr) {
    return ptr->v;
}

/**
 * Compares two Long structures numerically.
 *
 * @param ptr The allocated structure
 * @param anotherLong the Long to be compared.
 * @return the value 0 if the first Long is equal to the second Long; a value
 * less than 0 if the first Long is numerically less than the second Long; and
 * a value greater than 0 if the first Long is numerically greater than the
 * second Long (signed comparison).
 */
int32_t compareToL(Long *ptr, Long *anotherLong) {
    return Long_compare(ptr->v, anotherLong->v);
}

/**
 * Compares two long values numerically.
 *
 * @param x the first long to compare
 * @param y the second long to compare
 * @return the value 0 if x == y; a value less than 0 if x < y; and a value greater than 0 if x
 * > y
 */
int32_t Long_compare(int64_t x, int64_t y) {
    return (x < y) ? -1 : ((x == y) ? 0 : 1);
}

/**
 * Compares the one structure to the other.
 *
 * @param ptr The allocated structure
 * @param obj the structure to compare with.
 * @return true if the structures are the same; false otherwise.
 */
bool equalsL(Long *ptr, Long *obj) {
    if (ptr == NULL || obj == NULL) {
        return false;
    }

    if (sizeof(*ptr) != sizeof(*obj)) {
        return false;
    }

    return (ptr->v == obj->v);
}

/**
 * Returns a String structure representing the specified Long's value.
 *
 * @param ptr The allocated structure
 * @return a string representation of the value of the specified structure in base 10.
 */
String *toStringL(Long *ptr) {
    return Long_toString(ptr->v);
}

/**
 * Returns a String structure representing the specified long.
 *
 * @param l a long to be converted.
 * @return a string representation of the argument in base 10.
 */
String *Long_toString(int64_t l) {
    char *str = malloc(_MAX_LONG_STRLEN + 1);
    char buf[_MAX_LONG_STRLEN];

    str[0] = '\0';
    sprintf(buf, "%lld", l);
    strcat(str, buf);

    return new_String(str);
}

/**
 * Parses the string argument as a signed long in the radix specified by the
 * second argument.
 *
 * @param s a String containing the long representation to be parsed
 * @return the long represented by the argument in decimal.
 */
int64_t Long_parseLong(String *s) {
    return strtol(s->s, NULL, 10);
}
