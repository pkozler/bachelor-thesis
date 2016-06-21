#include "Integer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// maximum possible string length of the int32_t value used as the string buffer size
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
 * Returns the value of the specified Integer as an int.
 *
 * @param ptr The allocated structure
 * @return the numeric value represented by the specified structure after conversion to
 * type int.
 */
int32_t intValue(Integer *ptr) {
    return ptr->v;
}

/**
 * Compares two Integer structures numerically.
 *
 * @param ptr The allocated structure
 * @param anotherInteger the Integer to be compared.
 * @return the value 0 if the first Integer is equal to the second Integer; a
 * value less than 0 if the first Integer is numerically less than the second
 * Integer; and a value greater than 0 if the first Integer is numerically
 * greater than the second Integer (signed comparison).
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
    // 1 if x is greater, 0 if x equals y, -1 otherwise
    return (x < y) ? -1 : ((x == y) ? 0 : 1);
}

/**
 * Compares the one structure to the other.
 *
 * @param ptr The allocated structure
 * @param obj the structure to compare with.
 * @return true if the structures are the same; false otherwise.
 */
bool equalsI(Integer *ptr, Integer *obj) {
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
 * Returns a String structure representing the specified Integer's value.
 *
 * @param ptr The allocated structure
 * @return a string representation of the value of the specified structure in base 10.
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
    // printing the string representation to the buffer
    sprintf(buf, "%d", i);
    // creating the null-terminated string from the buffer
    strcat(str, buf);
    String *s = new_String(str);
    free(str);
    
    return s;
}

/**
 * Parses the string argument as a signed decimal integer.
 *
 * @param s a String containing the int representation to be parsed
 * @return the integer value represented by the argument in decimal.
 */
int32_t Integer_parseInt(String *s) {
    String *str = trim(s);
    int32_t value = strtol(str->s, NULL, 10);
    free(str);
    
    return value;
}
