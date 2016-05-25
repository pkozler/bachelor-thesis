#ifndef BYTE_INCLUDED
#define BYTE_INCLUDED

#include "String.h"
#include <stdbool.h>
#include <stdint.h>

/**
 * The Byte struct wraps a value of the type int8_t, representing a byte value.
 *
 * @author Petr Kozler (A13B0359P)
 */

/**
 * A constant holding the maximum value a byte can have, 2^7-1.
 */
#define Byte_MAX_VALUE 127
/**
 * A constant holding the minimum value a byte can have, -2^7.
 */
#define Byte_MIN_VALUE -128

typedef struct {
    int8_t v;
} Byte;

Byte *new_Byte(int8_t value);
int8_t byteValue(Byte *ptr);
int32_t compareToB(Byte *ptr, Byte *anotherByte);
int32_t Byte_compare(int8_t x, int8_t y);
bool equalsB(Byte *ptr, Byte *obj);
String *toStringB(Byte *ptr);
String *Byte_toString(int8_t b);
int8_t Byte_parseByte(String *s);

#endif /* BYTE_INCLUDED */
