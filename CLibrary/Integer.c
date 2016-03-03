#include "Integer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _MAX_INT_STRLEN 11

Integer *new_Integer(int32_t value) {
    Integer *i = malloc(sizeof(Integer));
    i->v = value;

    return i;
}

int32_t intValue(Integer *ptr) {
    return ptr->v;
}

int32_t compareToI(Integer *ptr, Integer *anotherInteger) {
    return Integer_compare(ptr->v, anotherInteger->v);
}

int32_t Integer_compare(int32_t x, int32_t y) {
    return (x < y) ? -1 : ((x == y) ? 0 : 1);
}

bool equalsI(Integer *ptr, Integer *obj) {
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

String *toStringI(Integer *ptr) {
    return Integer_toString(ptr->v);
}

String *Integer_toString(int32_t i) {
    char *str = malloc(_MAX_INT_STRLEN + 1);
    char buf[_MAX_INT_STRLEN];

    str[0] = '\0';
    sprintf(buf, "%d", i);
    strcat(str, buf);

    return new_String(str);
}

int32_t Integer_parseInt(String *s) {
    return strtol(s->s, NULL, 10);
}
