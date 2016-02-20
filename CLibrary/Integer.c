#include "Integer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _MAX_INT_STRLEN 11

Integer *new_Integer(int value) {
    Integer *i = malloc(sizeof(Integer));
    i->v = value;

    return i;
}

int intValue(Integer *ptr) {
    return ptr->v;
}

int compareToI(Integer *ptr, Integer *anotherInteger) {
    return (ptr->v - anotherInteger->v);
}

bool equalsI(Integer *ptr, Integer *obj) {
    if (ptr == obj) {
        return true;
    }

    if (ptr == NULL || obj == NULL) {
        return false;
    }

    return (ptr->v == obj->v);
}

String *toStringI(Integer *ptr) {
    return Integer_toString(ptr->v);
}

String *Integer_toString(int i) {
    char *str = malloc(_MAX_INT_STRLEN + 1);
    char buf[_MAX_INT_STRLEN];

    str[0] = '\0';
    sprintf(buf, "%d", i);
    strcat(str, buf);

    return new_String(str);
}

int Integer_parseInt(String *s) {
    return strtol(s->s, NULL, 10);
}
