#include "Byte.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _MAX_BYTE_STRLEN 4

Byte *new_Byte(int8_t value) {
    Byte *b = malloc(sizeof(Byte));
    b->v = value;

    return b;
}

int8_t byteValue(Byte *ptr) {
    return ptr->v;
}

int32_t compareToB(Byte *ptr, Byte *anotherByte) {
    return Byte_compare(ptr->v, anotherByte->v);
}

int32_t Byte_compare(int8_t x, int8_t y) {
    return x - y;
}

bool equalsB(Byte *ptr, Byte *obj) {
    if (ptr == obj) {
        return true;
    }

    if (ptr == NULL || obj == NULL) {
        return false;
    }

    if (sizeof(*ptr) != sizeof(*obj)) {
        return false;
    }

    return (ptr->v == obj->v);
}

String *toStringB(Byte *ptr) {
    return Byte_toString(ptr->v);
}

String *Byte_toString(int8_t b) {
    char *str = malloc(_MAX_BYTE_STRLEN + 1);
    char buf[_MAX_BYTE_STRLEN];

    str[0] = '\0';
    sprintf(buf, "%hd", b);
    strcat(str, buf);

    return new_String(str);
}

int8_t Byte_parseByte(String *s) {
    return strtol(s->s, NULL, 10);
}
