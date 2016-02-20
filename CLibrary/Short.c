#include "Short.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _MAX_SHORT_STRLEN 6

Short *new_Short(short value) {
    Short *s = malloc(sizeof(Short));
    s->v = value;

    return s;
}

short shortValue(Short *ptr) {
    return ptr->v;
}

int compareToS(Short *ptr, Short *anotherShort) {
    return (ptr->v - anotherShort->v);
}

bool equalsS(Short *ptr, Short *obj) {
    if (ptr == obj) {
        return true;
    }

    if (ptr == NULL || obj == NULL) {
        return false;
    }

    return (ptr->v == obj->v);
}

String *toStringS(Short *ptr) {
    return Short_toString(ptr->v);
}

String *Short_toString(short s) {
    char *str = malloc(_MAX_SHORT_STRLEN + 1);
    char buf[_MAX_SHORT_STRLEN];

    str[0] = '\0';
    sprintf(buf, "%hd", s);
    strcat(str, buf);

    return new_String(str);
}

short Short_parseShort(String *s) {
    return strtol(s->s, NULL, 10);
}
