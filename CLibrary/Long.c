#include "Long.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _MAX_LONG_STRLEN 20

Long *new_Long(int64_t value) {
    Long *l = malloc(sizeof(Long));
    l->v = value;

    return l;
}

int64_t longValue(Long *ptr) {
    return ptr->v;
}

int32_t compareToL(Long *ptr, Long *anotherLong) {
    return Long_compare(ptr->v, anotherLong->v);
}

int32_t Long_compare(int64_t x, int64_t y) {
    return (x < y) ? -1 : ((x == y) ? 0 : 1);
}

bool equalsL(Long *ptr, Long *obj) {
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

String *toStringL(Long *ptr) {
    return Long_toString(ptr->v);
}

String *Long_toString(int64_t l) {
    char *str = malloc(_MAX_LONG_STRLEN + 1);
    char buf[_MAX_LONG_STRLEN];

    str[0] = '\0';
    sprintf(buf, "%lld", l);
    strcat(str, buf);

    return new_String(str);
}

int64_t Long_parseLong(String *s) {
    return strtol(s->s, NULL, 10);
}
