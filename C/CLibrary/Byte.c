#include "Byte.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _MAX_BYTE_STRLEN 4

/**
 * Constructs a newly allocated Byte structure that represents the specified
 * byte value.
 *
 * @param value the value to be represented by the Byte.
 */
Byte *new_Byte(int8_t value) {
    Byte *b = malloc(sizeof(Byte));
    b->v = value;

    return b;
}

/**
 * Returns the value of this Byte as a byte.
 *
 * @return the numeric value represented by this structure after conversion to
 * type byte.
 */
int8_t byteValue(Byte *ptr) {
    return ptr->v;
}

/**
 * Compares two Byte structures numerically.
 *
 * @param anotherByte the Byte to be compared.
 * @return the value 0 if this Byte is equal to the argument Byte; a value
 * less than 0 if this Byte is numerically less than the argument Byte; and
 * a value greater than 0 if this Byte is numerically greater than the
 * argument Byte (signed comparison).
 */
int32_t compareToB(Byte *ptr, Byte *anotherByte) {
    return Byte_compare(ptr->v, anotherByte->v);
}

/**
 * Compares two byte values numerically.
 *
 * @param x the first byte to compare
 * @param y the second byte to compare
 * @return the value 0 if x == y; a value less than 0 if x < y; and a value greater than 0 if x
 * > y
 */
int32_t Byte_compare(int8_t x, int8_t y) {
    return x - y;
}

/**
 * Compares this structure to the specified structure.
 *
 * @param obj the structure to compare with
 * @return true if the structures are the same; false otherwise.
 */
bool equalsB(Byte *ptr, Byte *obj) {
    if (ptr == NULL || obj == NULL) {
        return false;
    }

    if (sizeof(*ptr) != sizeof(*obj)) {
        return false;
    }

    return (ptr->v == obj->v);
}

/**
 * Returns a String structure representing this Byte's value.
 * 
 * @return a string representation of the value of this structure in base 10.
 */
String *toStringB(Byte *ptr) {
    return Byte_toString(ptr->v);
}

/**
 * Returns a new String structure representing the specified byte.
 *
 * @param b the byte to be converted
 * @return the string representation of the specified byte
 */
String *Byte_toString(int8_t b) {
    char *str = malloc(_MAX_BYTE_STRLEN + 1);
    char buf[_MAX_BYTE_STRLEN];

    str[0] = '\0';
    sprintf(buf, "%hd", b);
    strcat(str, buf);

    return new_String(str);
}

/**
 * Parses the string argument as a signed decimal byte.
 *
 * @param s a String containing the byte representation to be parsed
 * @return the byte value represented by the argument in decimal
 */
int8_t Byte_parseByte(String *s) {
    return strtol(s->s, NULL, 10);
}
