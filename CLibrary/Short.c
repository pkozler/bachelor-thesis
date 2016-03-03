#include "Short.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _MAX_SHORT_STRLEN 6

Short *new_Short(int16_t value) {
    Short *s = malloc(sizeof(Short));
    s->v = value;

    return s;
}

int16_t shortValue(Short *ptr) {
    return ptr->v;
}

int32_t compareToS(Short *ptr, Short *anotherShort) {
    return Short_compare(ptr->v, anotherShort->v);
}

int32_t Short_compare(int16_t x, int16_t y) {
    return x - y;
}

bool equalsS(Short *ptr, Short *obj) {
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

String *toStringS(Short *ptr) {
    return Short_toString(ptr->v);
}

String *Short_toString(int16_t s) {
    char *str = malloc(_MAX_SHORT_STRLEN + 1);
    char buf[_MAX_SHORT_STRLEN];

    str[0] = '\0';
    sprintf(buf, "%hd", s);
    strcat(str, buf);

    return new_String(str);
}

int16_t Short_parseShort(String *s) {
    return strtol(s->s, NULL, 10);
}
