#include "Byte.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _MAX_BYTE_STRLEN 4

Byte *new_Byte(char value) {
    Byte *b = malloc(sizeof(Byte));
    b->v = value;

    return b;
}

char byteValue(Byte *ptr) {
    return ptr->v;
}

int compareToB(Byte *ptr, Byte *anotherByte) {
    return (ptr->v - anotherByte->v);
}

bool equalsB(Byte *ptr, Byte *obj) {
    if (ptr == obj) {
        return true;
    }

    if (ptr == NULL || obj == NULL) {
        return false;
    }

    return (ptr->v == obj->v);
}

String *toStringB(Byte *ptr) {
    return Byte_toString(ptr->v);
}

String *Byte_toString(char b) {
    char *str = malloc(_MAX_BYTE_STRLEN + 1);
    char buf[_MAX_BYTE_STRLEN];

    str[0] = '\0';
    sprintf(buf, "%hd", b);
    strcat(str, buf);

    return new_String(str);
}

char Byte_parseByte(String *s) {
    return strtol(s->s, NULL, 10);
}
