#ifndef BYTE_INCLUDED
#define BYTE_INCLUDED

#include "String.h"
#include <stdbool.h>
#include <stdint.h>

#define Byte_MAX_VALUE 127
#define Byte_MIN_VALUE -128

typedef struct {
    int8_t v;
} Byte;

Byte *new_Byte(int8_t value);
int8_t byteValue(Byte *ptr);
int32_t compareToB(Byte *ptr, Byte *anotherByte);
bool equalsB(Byte *ptr, Byte *obj);
String *toStringB(Byte *ptr);
String *Byte_toString(int8_t b);
int8_t Byte_parseByte(String *s);

#endif /* BYTE_INCLUDED */
