#ifndef BYTE_INCLUDED
#define BYTE_INCLUDED

#include "String.h"
#include <stdbool.h>

#define Byte_MAX_VALUE 127
#define Byte_MIN_VALUE -128

typedef struct {
    char v;
} Byte;

Byte *new_Byte(char value);
char byteValue(Byte *ptr);
int compareToB(Byte *ptr, Byte *anotherByte);
bool equalsB(Byte *ptr, Byte *obj);
String *toStringB(Byte *ptr);
String *Byte_toString(char b);
char Byte_parseByte(String *s);

#endif /* BYTE_INCLUDED */
